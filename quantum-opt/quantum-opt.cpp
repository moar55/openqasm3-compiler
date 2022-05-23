#include "iostream"
#include "visitor.hpp"
#include "mlir_generator.hpp"
#include "Quantum/QuantumDialect.h"
#include "Quantum/QuantumOps.h"
#include "mlir/Dialect/MemRef/IR/MemRef.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"

mlir::OpBuilder* builder;
mlir::ModuleOp m_module;

using namespace antlr4;

int main() {
  std::string qasm_src = R"#(OPENQASM3;
    qubit q;
    h q;
    c = measure q;
  )#";
  mlir::MLIRContext* context = new mlir::MLIRContext;
  context->loadDialect<mlir::quantum::QuantumDialect, mlir::memref::MemRefDialect>();
  std::shared_ptr<MLIRGenerator> mlir_generator = std::make_shared<MLIRGenerator>(*context);
  mlir_generator->mlirgen(qasm_src);
  std::cout<<"Hello there"<<std::endl;
  return 0;
};