#include <mlir/Conversion/FuncToLLVM/ConvertFuncToLLVMPass.h>
#include "mlir/Conversion/ComplexToLLVM/ComplexToLLVM.h"
#include "mlir/Conversion/TensorToLinalg/TensorToLinalgPass.h"
#include "mlir/Conversion/LinalgToLLVM/LinalgToLLVM.h"
#include "headers.h"

using namespace mlir;


int llvm_dump(ModuleOp module) {
//  mlir::PassManager pm(module->getContext());
//  pm.addPass(quantum::createConvertInstPass());
//  pm.addPass(quantum::createForwardDeclareQuantumAllocsPass());
//  pm.addPass(mlir::createCSEPass());
//  pm.addPass(mlir::createConvertFuncToLLVMPass());
//  pm.addPass(mlir::createConvertVectorToLLVMPass());
//  pm.addPass(mlir::createArithToLLVMConversionPass());
//  pm.addPass(mlir::createMemRefToLLVMConversionPass());
//  pm.addPass(mlir::createReconcileUnrealizedCastsPass());

//  pm.run(module);
//  module.dump();
    llvm::InitializeNativeTarget();
    llvm::InitializeNativeTargetAsmPrinter();
    registerLLVMDialectTranslation(*module->getContext());
    llvm::LLVMContext llvmContext;
    auto llvmModule = translateModuleToLLVMIR(module, llvmContext);
    if (!llvmModule) {
        llvm::errs() << "Failed to emit LLVM IR\n";
        return -1;
    }

    ExecutionEngine::setupTargetTriple(llvmModule.get());

    //   run optimizaiton stuff
    //    ....
    //    ...

    llvmModule->dump();
    return 0;
}

int main(int argc, char **argv) {
    std::ifstream ifs("test.qasm");
    std::string qasm_src( (std::istreambuf_iterator<char>(ifs) ),
                        (std::istreambuf_iterator<char>() ));
    auto context = std::make_unique<MLIRContext>();
    context->loadDialect<quantum::QuantumDialect, memref::MemRefDialect, arith::ArithDialect,
        math::MathDialect,
        complex::ComplexDialect,
        tensor::TensorDialect, linalg::LinalgDialect, scf::SCFDialect, func::FuncDialect, vector::VectorDialect,LLVM::LLVMDialect, restquantum::RestrictedQuantumDialect>();
    MLIRGenerator mlir_generator = MLIRGenerator(*context);
    mlir_generator.initialize_mlirgen("main");
    mlir_generator.mlirgen(qasm_src);
    ModuleOp module = mlir_generator.get_module();
    module.dump();
    //  mlir::OpPrintingFlags flags;
    //  flags.printValueUsers();
    //  flags.enableDebugInfo();
    //  flags.printGenericOpForm();
    // empty while loop doesn't work
    mlir::PassManager pm(module->getContext());
    pm.addPass(mlir::createCanonicalizerPass());
    pm.addPass(mlir::createCSEPass());
    pm.addPass(mlir::createSymbolDCEPass());
    //  pm.addPass(quantum::createOptimizeQuantumPass());
    //  pm.addPass(quantum::createConvertInstPass());
    pm.run(module);
    module.dump();


    pm.clear();
    pm.addPass(quantum::createConvertToGenGatePass());
    pm.addPass(quantum::createConvertInstPass());
    pm.run(module);
    module.dump();

    pm.clear();
    pm.addPass(quantum::createQuantumSimulator());
    pm.addPass(mlir::createCSEPass());
    pm.addPass(mlir::createSymbolDCEPass());
    pm.run(module);
    module.dump();

    pm.clear();
    //convert complex to llvm
    pm.addPass(mlir::createConvertFuncToLLVMPass());
    pm.addPass(mlir::createConvertVectorToLLVMPass());
    pm.addPass(mlir::createArithToLLVMConversionPass());
    pm.addPass(mlir::createMemRefToLLVMConversionPass());
    pm.addPass(mlir::createConvertTensorToLinalgPass());
    pm.addPass(mlir::createConvertLinalgToLLVMPass());
    pm.addPass(mlir::createConvertComplexToLLVMPass());
//    createConvertComplexToLLVMPass());
//    pm.addPass(quantum::createLowerToLLVMPass());
    pm.addPass(mlir::createReconcileUnrealizedCastsPass());
    pm.run(module);

    /// JIT
    llvm::InitializeNativeTarget();
    llvm::InitializeNativeTargetAsmPrinter();
    registerLLVMDialectTranslation(*module->getContext());
    //   run optimizaiton stuff
    //    ....
    //    ...

    // Create an MLIR execution engine. The execution engine eagerly JIT-compiles
    // the module.
    mlir::ExecutionEngineOptions engineOptions;
    engineOptions.sharedLibPaths = {"/usr/local/lib/libmlir_c_runner_utils.so"};
    auto maybeEngine = mlir::ExecutionEngine::create(module, engineOptions);
    assert(maybeEngine && "failed to construct an execution engine");
    auto &engine = maybeEngine.get();

    // Invoke the JIT-compiled function.
    auto invocationResult = engine->invokePacked("main");
    if (invocationResult) {
        llvm::errs() << "JIT invocation failed\n";
        return -1;
    }
    return 0;
}