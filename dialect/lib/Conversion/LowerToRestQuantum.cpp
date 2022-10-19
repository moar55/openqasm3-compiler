#include <c++/9/iostream>
#include <mlir/Dialect/MemRef/IR/MemRef.h>
#include <mlir/Transforms/DialectConversion.h>
#include <mlir/Dialect/Arithmetic/IR/Arithmetic.h>
#include <Quantum/IR/QuantumOps.h>
#include "RestrictedQuantum/RestrictedQuantumOps.h"
//#include "mlir/Pass/Pass.h"
#include "Quantum/Transforms/Passes.h"
#include "../PassImp.h"

using namespace mlir;

class ConvertInstRewrite : public OpConversionPattern<quantum::ValueSemanticsInstOp> {
public :
    using OpConversionPattern::OpConversionPattern;

    LogicalResult matchAndRewrite(quantum::ValueSemanticsInstOp op, OpAdaptor adaptor,
                                  ConversionPatternRewriter &rewriter) const override{
      std::cout<<"hello"<<std::endl;
      const Attribute attr = op->getAttr(llvm::StringRef("name"));
      const std::string gate_name = attr.dyn_cast_or_null<StringAttr>().str();
      std::vector<std::pair<std::string, double>> rotation_gates_and_angles;
      if (gate_name == "H") {
        rotation_gates_and_angles = {std::pair{"ry", 90}, std::pair{"rx", 180}};
      } else if (gate_name == "X") {
        rotation_gates_and_angles = {std::pair{"rx", 180}};
      } else if (gate_name == "Z") {
        rotation_gates_and_angles = {std::pair{"rz", 180}};
      } else if (gate_name == "Y") {
        rotation_gates_and_angles = {std::pair{"ry", 180}};
      }

      // X, sqrtx, Rz(-infinite,infinite)
      mlir::Value operand = op.getOperand(0);
      Location loc = op.getLoc();
      if (rotation_gates_and_angles.empty()) {
        rewriter.replaceOpWithNewOp<restquantum::RxOp>(op, llvm::makeArrayRef(operand.getType()),
                                                       llvm::makeArrayRef(operand), llvm::makeArrayRef(std::vector<mlir::Value>{}));
      } else {
        rewriter.eraseOp(op);
        std::reverse(rotation_gates_and_angles.begin(), rotation_gates_and_angles.end());
        for (const auto& my_pair : rotation_gates_and_angles){
          FloatType f64 = rewriter.getF64Type();
          FloatAttr angle = FloatAttr::get(f64, my_pair.second);
          Value angle_op = rewriter.create<arith::ConstantOp>(rewriter.getUnknownLoc(), angle, f64);
          if (my_pair.first == "rx")
            operand = rewriter.create<restquantum::RxOp>(loc, llvm::makeArrayRef(operand.getType()),
                                               llvm::makeArrayRef(operand), llvm::makeArrayRef(angle_op)).getResult(0);
          else if (my_pair.first == "ry")
            operand = rewriter.create<restquantum::RyOp>(loc, llvm::makeArrayRef(operand.getType()),
                                             llvm::makeArrayRef(operand), llvm::makeArrayRef(angle_op)).getResult(0);

          loc = rewriter.getUnknownLoc();
        }
      }

      return success();
    }
};

class ConvertInst
        : public quantum::ConvertInstBase<ConvertInst> {
public:
    void runOnOperation() override {
      MLIRContext *context = &getContext();
      ConversionTarget target(*context);
      target.addLegalDialect<memref::MemRefDialect,arith::ArithmeticDialect, quantum::QuantumDialect, restquantum::RestrictedQuantumDialect>();
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