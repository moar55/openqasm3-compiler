#include <RestrictedQuantum/RestrictedQuantumDialect.h>
#include <RestrictedQuantum/RestrictedQuantumOps.h>
#include <mlir/Pass/Pass.h>
#include "mlir/Pass/PassManager.h"
#include <mlir/Rewrite/PatternApplicator.h>
//#include "mlir/Rewrite/PatternApplicator.h"
#include "iostream"
#include "visitor.hpp"
#include "mlir_generator.hpp"

#include "Quantum/IR/QuantumDialect.h"
#include "Quantum/IR/QuantumOps.h"

#include "mlir/Dialect/MemRef/IR/MemRef.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/Dialect/Arithmetic/IR/Arithmetic.h"
#include "mlir/Tools/mlir-opt/MlirOptMain.h"
#include "Quantum/Transforms/Passes.h"
#include "mlir/Transforms/DialectConversion.h"

using namespace mlir;
//
///// Single-step rewrite with "matchAndRewrite". This allows for performing the
///// rewrite immediately upon a successful match.
//class ConvertInstRewrite : public OpRewritePattern<quantum::ValueSemanticsInstOp> {
//public :
//    using OpRewritePattern::OpRewritePattern;
//
//    LogicalResult matchAndRewrite(quantum::ValueSemanticsInstOp op,
//                                       PatternRewriter &rewriter) const override{
//      std::cout<<"hello"<<std::endl;
//      Location loc = op->getLoc();
//      std::vector<mlir::Value> qubits, params;
//      qubits = std::vector<mlir::Value>{op->getOperand(0)};
//      auto inst = rewriter.create<restquantum::RxOp>(loc, llvm::makeArrayRef(std::vector<mlir::Type>{mlir::Type{}})
//              , llvm::makeArrayRef(qubits), llvm::makeArrayRef(params));
//      rewriter.replaceOp(op, inst.getResult(0));
//      return success();
//    }
//};
//
//struct ConvertInstTarget : public ConversionTarget {
//    ConvertInstTarget(MLIRContext &ctx) : ConversionTarget(ctx) {
//      addLegalDialect<restquantum::RestrictedQuantumDialect, arith::ArithmeticDialect, func::FuncDialect, memref::MemRefDialect>();
//    }
//};


//class ConvertInstPass: public ConvertInstPassBase<ConvertInstPass> {
//    public
//};
/// Define a custom PatternRewriter for use by the driver.
//class MyPatternRewriter : public PatternRewriter {
//public:
//    MyPatternRewriter(MLIRContext *ctx) : PatternRewriter(ctx) {}
//
//    /// Override the necessary PatternRewriter hooks here.
//};

int main(int argc, char **argv) {
  std::string qasm_src = R"#(
    OPENQASM3;
    qubit q;
    bit c;
    Z q;
    )#";
  auto context = std::make_unique<MLIRContext>();
  context->loadDialect<quantum::QuantumDialect, memref::MemRefDialect, arith::ArithmeticDialect, func::FuncDialect, restquantum::RestrictedQuantumDialect>();
  std::shared_ptr<MLIRGenerator> mlir_generator = std::make_shared<MLIRGenerator>(*context);
  mlir_generator->initialize_mlirgen("main");
  mlir_generator->mlirgen(qasm_src);
  OwningOpRef<ModuleOp> module = mlir_generator->get_module();

  std::string s;
  llvm::raw_string_ostream os(s);
  module->print(os);
  os.flush();
  std::cout << s << std::endl;

  mlir::PassManager pm(module->getContext());
  pm.addPass(quantum::createConvertInstPass());
  auto module_op = module->getOperation();
  pm.run(module_op);

  std::string s2;
  llvm::raw_string_ostream os2(s2);
  module->print(os2);
  os2.flush();
  std::cout << s2 << std::endl;
};