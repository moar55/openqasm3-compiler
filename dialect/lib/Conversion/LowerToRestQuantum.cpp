#include <iostream>
#include <mlir/Dialect/MemRef/IR/MemRef.h>
#include <mlir/Transforms/DialectConversion.h>
#include <mlir/Dialect/Arithmetic/IR/Arithmetic.h>
#include <Quantum/IR/QuantumOps.h>
#include "RestrictedQuantum/RestrictedQuantumOps.h"
//#include "mlir/Pass/Pass.h"
#include "Quantum/Transforms/Passes.h"
#include "../PassImp.h"
#include <cmath>

using namespace mlir;

template <typename Op, typename... Args>
Value createRotationGateGeneric(ConversionPatternRewriter &rewriter, quantum::ValueSemanticsInstOp op,
                                Location loc, bool replace, Args... args) {
  if (replace) {
    return rewriter.replaceOpWithNewOp<Op>(op, args...);
  } else {
    return rewriter.create<Op>(loc, args...);
  }
}

Value createRotationGate(ConversionPatternRewriter &rewriter, Value operand, const std::pair<std::string,
                         double>& my_pair, quantum::ValueSemanticsInstOp& op, Location loc, bool replace=false) {
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
    FloatAttr angle_attr = FloatAttr::get(f64, angle);
    Value angle_op = rewriter.create<arith::ConstantOp>(rewriter.getUnknownLoc(), angle_attr, f64).getResult();
    output = createRotationGateGeneric<restquantum::RzOp>(rewriter, op, loc, replace, operand.getType(), operand, angle_op);
  }
  return output;
}

class ConvertInstRewrite : public OpConversionPattern<quantum::ValueSemanticsInstOp> {
public :
    using OpConversionPattern::OpConversionPattern;

    LogicalResult matchAndRewrite(quantum::ValueSemanticsInstOp op, OpAdaptor adaptor,
                                  ConversionPatternRewriter &rewriter) const override {
      //TODO: cleanup
      //TODO: maybe use enums for gate names
      auto const gate_name = op.nameAttr().str();
      std::vector<std::pair<std::string, double>> rotation_gates_and_angles;
      auto params = op.params();

      if (gate_name == "H") {
        rotation_gates_and_angles = {std::pair{"ry", 90}, std::pair{"rx", 180}}; //Ry(90)Rx(180)
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
        rewriter.replaceOpWithNewOp<restquantum::CX>(op, op.getOperand(0).getType(), op.getOperand(1).getType(), op->getOperand(0),
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

class ConvertInst
        : public quantum::ConvertInstBase<ConvertInst> {
public:
    void runOnOperation() override {
      MLIRContext *context = &getContext();
      ConversionTarget target(*context);
      target.addLegalDialect<
              memref::MemRefDialect,arith::ArithmeticDialect,
              quantum::QuantumDialect, restquantum::RestrictedQuantumDialect>();
      TypeConverter typeConverter;
      typeConverter.addConversion([](Type type) {return type;});
      RewritePatternSet patterns(context);
      target.addIllegalOp<quantum::ValueSemanticsInstOp>();
      patterns.add<ConvertInstRewrite>(typeConverter, context);
      if (failed(applyPartialConversion(getOperation(), target,
                                        std::move(patterns))))
        return signalPassFailure();
    };
};

std::unique_ptr<OperationPass<ModuleOp>>
mlir::quantum::createConvertInstPass() {
  return std::make_unique<ConvertInst>();
}