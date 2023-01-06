#include "headers.h"

using namespace mlir;

int main(int argc, char **argv) {
  std::ifstream ifs("test.qasm");
  std::string qasm_src( (std::istreambuf_iterator<char>(ifs) ),
                        (std::istreambuf_iterator<char>() ));
  auto context = std::make_unique<MLIRContext>();
  context->loadDialect<quantum::QuantumDialect, memref::MemRefDialect, arith::ArithDialect,
    scf::SCFDialect, func::FuncDialect, vector::VectorDialect,LLVM::LLVMDialect, restquantum::RestrictedQuantumDialect>();
  MLIRGenerator mlir_generator = MLIRGenerator(*context);
  mlir_generator.initialize_mlirgen("main");
  mlir_generator.mlirgen(qasm_src);
  ModuleOp module = mlir_generator.get_module();
//


  mlir::OpPrintingFlags flags;
  flags.printValueUsers();
//  flags.enableDebugInfo();
//  flags.printGenericOpForm();
// empty while loop doesn't work
//  mlir::PassManager pm(module->getContext());
//  pm.addPass(quantum::createConvertInstPass());
//  pm.addPass(mlir::createCSEPass());
//  pm.run(module);

  std::string s;
  llvm::raw_string_ostream os(s);
  module->print(os);
  os.flush();
  std::cout << s << std::endl;

  //
//
  mlir::PassManager pm(module->getContext());
  pm.addPass(quantum::createConvertInstPass());
  pm.addPass(quantum::createForwardDeclareQuantumAllocsPass());
  pm.addPass(mlir::createCSEPass());
//  pm.addPass(createConvertFuncToLLVMPass());
//  pm.addPass(createConvertVectorToLLVMPass());
//  pm.addPass(createArithToLLVMConversionPass());

//  pm.addPass(quantum::createLowerToLLVMPass());
  pm.run(module);

//  LogicalResult::ver

//
//  std::string s2;
//  llvm::raw_string_ostream os2(s2);

  module.dump();
//  module->print(os2, flags);
//  os2.flush();
//  std::cout << s2 << std::endl;



//
//  llvm::InitializeNativeTarget();
//  llvm::InitializeNativeTargetAsmPrinter();
//  registerLLVMDialectTranslation(*module->getContext());


//  registerLLVMDialectTranslation(*module->getContext());
//  llvm::LLVMContext llvmContext;
//  auto llvmModule = translateModuleToLLVMIR(module, llvmContext);
//  if (!llvmModule) {
//    llvm::errs() << "Failed to emit LLVM IR\n";
//    return -1;
//  }
//  llvmModule->dump();
//
//
//  ExecutionEngine::setupTargetTriple(llvmModule.get());

//   run optimizaiton stuff
//    ....
//    ...

  // Create an MLIR execution engine. The execution engine eagerly JIT-compiles
  // the module.
//  mlir::ExecutionEngineOptions engineOptions;
//  engineOptions.sharedLibPaths = {"/usr/local/lib/libmlir_c_runner_utils.so"};
//  auto maybeEngine = mlir::ExecutionEngine::create(module, engineOptions);
//  assert(maybeEngine && "failed to construct an execution engine");
//  auto &engine = maybeEngine.get();
//
//  // Invoke the JIT-compiled function.
//  auto invocationResult = engine->invokePacked("main");
//  if (invocationResult) {
//    llvm::errs() << "JIT invocation failed\n";
//    return -1;
//  }

};