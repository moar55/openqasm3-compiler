#include "headers.h"

using namespace mlir;

int main(int argc, char **argv) {
  std::ifstream ifs("test.qasm");
  std::string qasm_src( (std::istreambuf_iterator<char>(ifs) ),
                        (std::istreambuf_iterator<char>() ));
  auto context = std::make_unique<MLIRContext>();
  context->loadDialect<quantum::QuantumDialect, memref::MemRefDialect, arith::ArithmeticDialect,
    scf::SCFDialect, func::FuncDialect, restquantum::RestrictedQuantumDialect>();
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