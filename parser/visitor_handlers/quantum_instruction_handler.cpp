#include "../visitor.hpp"
#include "Quantum/QuantumOps.h"

std::any visitor::visitQuantumGateCall(qasmParser::QuantumGateCallContext *context) {
  auto qgn = context->quantumGateName();
  auto qbit_var_name = context->indexedIdentifier().front()->Identifier()->getText();
  std::vector<mlir::Value> qubits, params;
  qubits = std::vector<mlir::Value>{symbol_table.get_symbol(qbit_var_name)};
  auto inst = builder.create<mlir::quantum::ValueSemanticsInstOp>(builder.getUnknownLoc(),
                                                      llvm::makeArrayRef(std::vector<mlir::Type>{qubit_type})
                                                      , builder.getStringAttr(qgn->getText()), llvm::makeArrayRef(qubits), llvm::makeArrayRef(params));

  symbol_table.replace_symbol(qubits.front(), inst.result().front());
  return {};
}