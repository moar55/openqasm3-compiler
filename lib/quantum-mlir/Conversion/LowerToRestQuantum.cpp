#include <iostream>
#include <mlir/Dialect/MemRef/IR/MemRef.h>
#include <mlir/Transforms/DialectConversion.h>
#include <mlir/Dialect/Arith/IR/Arith.h>
#include <quantum-mlir/Dialect/Quantum/IR/QuantumOps.h>
#include "quantum-mlir/Dialect/RestrictedQuantum/IR/RestrictedQuantumOps.h"
#include "quantum-mlir/Conversion/Passes.h"
#include "PassImp.h"
#include <cmath>
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/Dialect/SCF/IR/SCF.h"
#include "mlir/Dialect/Vector/IR/VectorOps.h"

using namespace mlir;

template <typename Op, typename... Args>
Value createRotationGateGeneric(ConversionPatternRewriter &rewriter, quantum::GenGate op,
                                Location loc, bool replace, Args... args) {
  if (replace) {
    return rewriter.replaceOpWithNewOp<Op>(op, args...);
  } else {
    return rewriter.create<Op>(loc, args...);
  }
}



Value createRotationGate(ConversionPatternRewriter &rewriter, Value operand, const std::pair<std::string,
                         double>& my_pair, quantum::GenGate& op, Location loc, bool replace=false) {
  double angle = my_pair.second;
  Value output;
  if (my_pair.first == "rx") {
    if (angle == 90)
      output = createRotationGateGeneric<restquantum::Rx90Op>(rewriter, op, loc, replace, operand.getType(), operand);
    else
      output = createRotationGateGeneric<restquantum::Rx180Op>(rewriter, op, loc, replace, operand.getType(), operand);
  } else if (my_pair.first == "ry") {
    if (angle == 90)
      output = createRotationGateGeneric<restquantum::Ry90Op>(rewriter, op, loc, replace, operand.getType(), operand);
    else
      output = createRotationGateGeneric<restquantum::Ry180Op>(rewriter, op, loc, replace, operand.getType(), operand);
  } else if (my_pair.first == "rz") {
    FloatType f64 = rewriter.getF64Type();
    auto radians_angle = angle * M_PI / 180;
    FloatAttr angle_attr = FloatAttr::get(f64, radians_angle);
    Value angle_op = rewriter.create<arith::ConstantOp>(rewriter.getUnknownLoc(), angle_attr, f64).getResult();
    output = createRotationGateGeneric<restquantum::RzOp>(rewriter, op, loc, replace, operand.getType(), operand, angle_op);
  }
  return output;
}

class ConvertInstRewrite : public OpConversionPattern<quantum::GenGate> {
public :
    using OpConversionPattern::OpConversionPattern;

    LogicalResult matchAndRewrite(quantum::GenGate op, OpAdaptor adaptor,
                                  ConversionPatternRewriter &rewriter) const override {
      //TODO: cleanup
      //TODO: maybe use enums for gate names
      auto const gate_name = op.getNameAttr().str();
      std::vector<std::pair<std::string, double>> rotation_gates_and_angles;
      auto params = op.getParams();

      if (gate_name == "H") {
        rotation_gates_and_angles = {std::pair{"rx", 180}, std::pair{"ry", 90}}; //Ry(90)Rx(180)
      } else if (gate_name == "X") {
        rotation_gates_and_angles = {std::pair{"rx", 180}}; // Rx(180)
      } else if (gate_name == "Z") {
        rotation_gates_and_angles = {std::pair{"rz", 180}}; // Rz(180)
      } else if (gate_name == "Y") {
        rotation_gates_and_angles = {std::pair{"ry", 180}}; // Ry(180)
      } else if (gate_name == "RX") { //RZ(pi)SX_RZ(theta + pi)SX_RZ(pi/2)
        Value operand = op.getOperand(0);
        auto loc = operand.getLoc();
        FloatType f64 = rewriter.getF64Type();

        FloatAttr pi_attr = FloatAttr::get(f64, M_PI);
        Value pi_op = rewriter.create<arith::ConstantOp>(rewriter.getUnknownLoc(), pi_attr, f64).getResult();

        FloatAttr pi2_attr = FloatAttr::get(f64, M_PI_2);
        Value pi2_op = rewriter.create<arith::ConstantOp>(rewriter.getUnknownLoc(), pi2_attr, f64).getResult();

        //Rz(pi/2)
        operand = createRotationGateGeneric<restquantum::RzOp>(rewriter, op, loc, false, operand.getType(), operand, pi2_op);
        loc = rewriter.getUnknownLoc();

        //Sqrt X
        operand = createRotationGateGeneric<restquantum::SqrtX>(rewriter, op, loc, false, operand.getType(), operand);
        loc = rewriter.getUnknownLoc();

        // Rz(theta + pi)
        Value theta = op.getOperand(1);
        Value angle_op = rewriter.create<arith::AddFOp>(loc, theta, pi_op); // theta + pi
        loc = rewriter.getUnknownLoc();
        operand = createRotationGateGeneric<restquantum::RzOp>(rewriter, op, loc, false, operand.getType(), operand, angle_op);
        loc = rewriter.getUnknownLoc();

        //Sqrt x
        operand = createRotationGateGeneric<restquantum::SqrtX>(rewriter, op, loc, false, operand.getType(), operand);
        loc = rewriter.getUnknownLoc();

        // Rz(pi)
        createRotationGateGeneric<restquantum::RzOp>(rewriter, op, loc, true, operand.getType(), operand, angle_op);
      } else if (gate_name == "RY") { //RZ(pi)RX(pi/2)RZ(theta + pi)RX(pi/2)
          Value operand = op.getOperand(0);
          auto loc = operand.getLoc();

          //RX(pi/2)
          createRotationGateGeneric<restquantum::Rx90Op>(rewriter, op, loc, false, operand.getType(), operand);
          loc = rewriter.getUnknownLoc();

          // Rz(theta + pi)
          FloatType f64 = rewriter.getF64Type();
          FloatAttr pi_attr = FloatAttr::get(f64, M_PI);
          Value pi_op = rewriter.create<arith::ConstantOp>(rewriter.getUnknownLoc(), pi_attr, f64).getResult();
          Value theta = op.getOperand(1);
          Value angle_op = rewriter.create<arith::AddFOp>(loc, theta, pi_op); // theta + pi
          loc = rewriter.getUnknownLoc();
          operand = createRotationGateGeneric<restquantum::RzOp>(rewriter, op, loc, false, operand.getType(), operand, angle_op);

          //RX(pi/2)
          operand = createRotationGateGeneric<restquantum::Rx90Op>(rewriter, op, loc, false, operand.getType(), operand);
          loc = rewriter.getUnknownLoc();

          //RZ(pi)
          createRotationGateGeneric<restquantum::RzOp>(rewriter, op, loc, true, operand.getType(), operand, pi_op);
      } else if (gate_name == "RZ") {
        if (params.size() != 1) {
          std::cout << "RZ gate takes a single angle param!" << std::endl;
          exit(1);
        }
        rewriter.replaceOpWithNewOp<restquantum::RzOp>(op, op.getOperand(0).getType(), op.getOperand(0),
                                                       params.front());
      } else if (gate_name == "CX") {
        if (op->getOperands().size() != 2) {
          std::cout << "CX requires two operands" << std::endl;
          exit(1);
        }
        rewriter.replaceOpWithNewOp<restquantum::CXOp>(op, op.getOperand(0).getType(), op.getOperand(1).getType(), op->getOperand(0),
                                                     op.getOperand(1));
      } else {
        std::cout << gate_name + " gate is not supported" << std::endl;
        exit(1);
      };

      if (!rotation_gates_and_angles.empty()) {
        Value operand = op.getOperand(0);
        auto loc = operand.getLoc();
        //apply operations in normal matrix multiplication order
        std::reverse(rotation_gates_and_angles.begin(), rotation_gates_and_angles.end());
        auto last_pair = rotation_gates_and_angles.back();
        rotation_gates_and_angles.pop_back();
        for (auto &my_pair: rotation_gates_and_angles) {
          operand = createRotationGate(rewriter, operand, my_pair, op, loc);
          loc = rewriter.getUnknownLoc();
        }
        createRotationGate(rewriter, operand, last_pair, op, loc, true);
      }
      return success();
    };
};

class ConvertGenGate: public OpConversionPattern<quantum::GenGate> {
public:
    using OpConversionPattern::OpConversionPattern;
    LogicalResult matchAndRewrite(quantum::GenGate op, OpAdaptor adaptor,
                                  ConversionPatternRewriter &rewriter) const override {

        auto gate_name = op.getNameAttr().str();
        // gate not supported for restquantum conversion yet
        std::cout << gate_name + " gate is not supported for restquantum conversion yet" << std::endl;
        exit(1);
    }
};

class ConvertXGate : public OpConversionPattern<quantum::XOp> {
public :
    using OpConversionPattern::OpConversionPattern;

    LogicalResult matchAndRewrite(quantum::XOp op, OpAdaptor adaptor,
                                  ConversionPatternRewriter &rewriter) const override {
        rewriter.replaceOpWithNewOp<restquantum::Rx180Op>(op, op->getOperand(0).getType(), op->getOperand(0));
        return success();
 }
};

class ConvertYGate : public OpConversionPattern<quantum::YOp> {
public :
    using OpConversionPattern::OpConversionPattern;

    LogicalResult matchAndRewrite(quantum::YOp op, OpAdaptor adaptor,
                                  ConversionPatternRewriter &rewriter) const override {
        rewriter.replaceOpWithNewOp<restquantum::Ry180Op>(op, op->getOperand(0).getType(), op->getOperand(0));
        return success();
    }
};

class ConvertZGate : public OpConversionPattern<quantum::ZOp> {
public :
    using OpConversionPattern::OpConversionPattern;

    LogicalResult matchAndRewrite(quantum::ZOp op, OpAdaptor adaptor,
                                  ConversionPatternRewriter &rewriter) const override {
        FloatType f64 = rewriter.getF64Type();
        FloatAttr pi_attr = FloatAttr::get(f64, M_PI);
        Value pi_op = rewriter.create<arith::ConstantOp>(rewriter.getUnknownLoc(), pi_attr, f64).getResult();
        rewriter.replaceOpWithNewOp<restquantum::RzOp>(op, op->getOperand(0).getType(), op->getOperand(0), pi_op);
        return success();
    }
};

class ConvertHGate : public OpConversionPattern<quantum::HOp> {
public :
    using OpConversionPattern::OpConversionPattern;

    LogicalResult matchAndRewrite(quantum::HOp op, OpAdaptor adaptor,
                                  ConversionPatternRewriter &rewriter) const override {
        auto val = rewriter.replaceOpWithNewOp<restquantum::Ry90Op>(op, op->getOperand(0).getType(), op->getOperand(0));
        rewriter.create<restquantum::Rx180Op>(rewriter.getUnknownLoc(), val.getType(), val.getResult());
        return success();
    }
};

class ConvertCXGate : public OpConversionPattern<quantum::CXOp> {
public :
    using OpConversionPattern::OpConversionPattern;

    LogicalResult matchAndRewrite(quantum::CXOp op, OpAdaptor adaptor,
                                  ConversionPatternRewriter &rewriter) const override {
        // refactor later, now just use restquantum::CX
        rewriter.replaceOpWithNewOp<restquantum::CXOp>(op, op->getOperand(0).getType(), op->getOperand(1).getType(), op->getOperand(0), op->getOperand(1));
        return success();
    }
};

class ConvertRXGate: public OpConversionPattern<quantum::RxOp> {
public :
    using OpConversionPattern::OpConversionPattern;

    LogicalResult matchAndRewrite(quantum::RxOp op, OpAdaptor adaptor,
                                  ConversionPatternRewriter &rewriter) const override {
        // use RX = RZ(pi)SX_RZ(theta + pi)SX_RZ(pi/2)
        Value operand = op.getOperand(0);
        auto loc = operand.getLoc();
        FloatType f64 = rewriter.getF64Type();

        FloatAttr pi_attr = FloatAttr::get(f64, M_PI);
        Value pi_op = rewriter.create<arith::ConstantOp>(rewriter.getUnknownLoc(), pi_attr, f64).getResult();

        FloatAttr pi2_attr = FloatAttr::get(f64, M_PI_2);
        Value pi2_op = rewriter.create<arith::ConstantOp>(rewriter.getUnknownLoc(), pi2_attr, f64).getResult();

        //Rz(pi/2)
        operand = rewriter.create<restquantum::RzOp>( loc, operand.getType(), operand, pi2_op);
        loc = rewriter.getUnknownLoc();

        //Sqrt X
        operand = rewriter.create<restquantum::SqrtX>(loc, operand.getType(), operand);
        loc = rewriter.getUnknownLoc();

        // Rz(theta + pi)
        Value theta = op.getOperand(1);
        Value angle_op = rewriter.create<arith::AddFOp>(loc, theta, pi_op); // theta + pi
        loc = rewriter.getUnknownLoc();
        operand = rewriter.create<restquantum::RzOp>(loc, operand.getType(), operand, angle_op);
        loc = rewriter.getUnknownLoc();

        //Sqrt x
        operand = rewriter.create<restquantum::SqrtX>(loc, operand.getType(), operand);
        loc = rewriter.getUnknownLoc();

        // Rz(pi)
        rewriter.replaceOpWithNewOp<restquantum::RzOp>(op, operand.getType(), operand, angle_op);
        return success();
    }
};


class ConvertRYGate: public OpConversionPattern<quantum::RyOp> {
public :
    using OpConversionPattern::OpConversionPattern;

    LogicalResult matchAndRewrite(quantum::RyOp op, OpAdaptor adaptor,
                                  ConversionPatternRewriter &rewriter) const override {
        Value operand = op.getOperand(0);
        auto loc = operand.getLoc();

        //RX(pi/2)
        rewriter.create<restquantum::Rx90Op>(loc, operand.getType(), operand);
        loc = rewriter.getUnknownLoc();

        // Rz(theta + pi)
        FloatType f64 = rewriter.getF64Type();
        FloatAttr pi_attr = FloatAttr::get(f64, M_PI);
        Value pi_op = rewriter.create<arith::ConstantOp>(rewriter.getUnknownLoc(), pi_attr, f64).getResult();
        Value theta = op.getOperand(1);
        Value angle_op = rewriter.create<arith::AddFOp>(loc, theta, pi_op); // theta + pi
        loc = rewriter.getUnknownLoc();
        operand = rewriter.create<restquantum::RzOp>(loc,  operand.getType(), operand, angle_op);

        //RX(pi/2)
        operand = rewriter.create<restquantum::Rx90Op>(loc,  operand.getType(), operand);
        loc = rewriter.getUnknownLoc();

        //RZ(pi)
        rewriter.replaceOpWithNewOp<restquantum::RzOp>(op, operand.getType(), operand, pi_op);
        return success();
    }
};


class ConvertRZGate: public OpConversionPattern<quantum::RzOp> {
public :
    using OpConversionPattern::OpConversionPattern;

    LogicalResult matchAndRewrite(quantum::RzOp op, OpAdaptor adaptor,
                                  ConversionPatternRewriter &rewriter) const override {
    rewriter.replaceOpWithNewOp<restquantum::RzOp>(op, op.getOperand(0).getType(), op.getOperand(0), op.getAngle());
        return success();
    }
};


class LowerToRestQuantum
        : public quantum::LowerToRestQuantumBase<LowerToRestQuantum> {
public:
    void runOnOperation() override {
      MLIRContext *context = &getContext();
      ConversionTarget target(*context);
      target.addLegalDialect<
              memref::MemRefDialect,arith::ArithDialect,
              restquantum::RestrictedQuantumDialect, vector::VectorDialect, func::FuncDialect, scf::SCFDialect>();

      target.addIllegalDialect<quantum::QuantumDialect>();
      target.addLegalOp<ModuleOp, quantum::MzOp, quantum::ExtractQubitOp, quantum::QallocOp, quantum::PrintGlobalVectorOp>();
//      target.addIllegalOp<quantum::GenGate, quantum::HOp, quantum::XOp>();
      TypeConverter typeConverter;
      typeConverter.addConversion([](Type type) {return type;});
      RewritePatternSet patterns(context);
      patterns.add<ConvertXGate, ConvertYGate, ConvertZGate, ConvertHGate, ConvertCXGate,
      ConvertRXGate, ConvertRYGate, ConvertRZGate, ConvertGenGate>(typeConverter, context);
//      patterns.add<ConvertInstRewrite>(typeConverter, context);
      if (failed(applyFullConversion(getOperation(), target,
                                        std::move(patterns)))) {
        return signalPassFailure();
      }
    };
};

std::unique_ptr<OperationPass<ModuleOp>>
mlir::quantum::createLowerToRestQuantumPass() {
  return std::make_unique<LowerToRestQuantum>();
}