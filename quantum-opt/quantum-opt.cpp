#include "iostream"
#include "visitor.hpp"
#include "mlir_generator.hpp"

#include "Quantum/QuantumDialect.h"
#include "Quantum/QuantumOps.h"

#include "mlir/Dialect/MemRef/IR/MemRef.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/Dialect/Arithmetic/IR/Arithmetic.h"
#include "mlir/Tools/mlir-opt/MlirOptMain.h"

int main(int argc, char **argv) {
  std::string qasm_src = R"#(OPENQASM3;
    qubit q;
    bit c;
    h q;
    c = measure q;
  )#";
  auto context = std::make_unique<mlir::MLIRContext>();
  context->loadDialect<mlir::quantum::QuantumDialect, mlir::memref::MemRefDialect, mlir::arith::ArithmeticDialect, mlir::func::FuncDialect>();
  std::shared_ptr<MLIRGenerator> mlir_generator = std::make_shared<MLIRGenerator>(*context);
  mlir_generator->initialize_mlirgen("main");
  mlir_generator->mlirgen(qasm_src);
  std::string s;
  llvm::raw_string_ostream os(s);
  mlir_generator->get_module()->print(os);
  os.flush();
  std::cout << "MLIR:\n" << s << "\n";
  return 0;
};