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
      Location loc = op->getLoc();
      std::vector<mlir::Value> qubits, params;
      qubits = std::vector<mlir::Value>{op->getOperand(0)};
      auto inst = rewriter.create<restquantum::RxOp>(loc, llvm::makeArrayRef(std::vector<mlir::Type>{mlir::Type{}})
              , llvm::makeArrayRef(qubits), llvm::makeArrayRef(params));
      rewriter.replaceOp(op, inst.getResult(0));
      return success();
    }
};

//void hoba() {
//  auto x = new ConvertInstBase
//}
class ConvertInst
: public quantum::ConvertInstBase<ConvertInst> {
public:
    void runOnOperation() override {
      MLIRContext *context = &getContext();
      ConversionTarget target(*context);
      target.addLegalDialect<memref::MemRefDialect,arith::ArithmeticDialect, quantum::QuantumDialect, restquantum::RestrictedQuantumDialect>();
      TypeConverter typeConverter;
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