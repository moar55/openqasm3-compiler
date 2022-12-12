#include "../visitor.hpp"
#include "expression_handler.h"
#include "Quantum/IR/QuantumOps.h"
#include "Quantum/IR/QuantumTypes.h"

using namespace mlir;

std::any visitor::visitQuantumGateCall(qasmParser::QuantumGateCallContext *context) {
  //TODO: disallow non const expressions for indexing
  //TODO: make sure a variable is not redeclared!
  auto qgn = context->quantumGateName();
  std::vector<Value> qubits, params;

  for (auto index: context->indexedIdentifier()) {
    auto qubit_var_name = index->Identifier()->getText();
    if (!symbol_table.has_symbol(qubit_var_name)) {
      printErrorMessage("Identifier " + qubit_var_name + " isn't declared!");
    }

    auto qubit_ident = symbol_table.get_symbol(qubit_var_name);

    if(!qubit_ident.getType().isa<OpaqueType>())
      printErrorMessage("Identifier " + qubit_var_name + " isn't a qubit or qubit array");

    if (!index->indexOperator().empty()) {
      if (qubit_ident.getType().cast<OpaqueType>().getTypeData().str() != "Array")
        printErrorMessage("can't index a non qubit array type");

      if (!index->indexOperator().front()->expression(0))
        printErrorMessage("an expression and only supported as an operation for quantum gates");

      auto generator = qasm_expression_generator(builder, symbol_table, builder.getF64Type());
      generator.visitExpression(index->indexOperator().front()->expression(0));
      Value pos = generator.current_value;
      auto pos_int = pos.getDefiningOp<arith::ConstantOp>().getValue().cast<IntegerAttr>().getInt();
      auto allocation_size = qubit_ident.getDefiningOp<quantum::QallocOp>().sizeAttr().getInt();
      if ( pos_int < 0 || pos_int > allocation_size - 1)
        printErrorMessage("index out of bound for indexing variable " + qubit_var_name);

      auto qubit = builder.create<quantum::ExtractQubitOp>(builder.getUnknownLoc(), qubit_type, qubit_ident, pos);
      qubits.push_back(qubit);
    } else {
      if (qubit_ident.getType().cast<OpaqueType>().getTypeData().str() != "Qubit")
        printErrorMessage("Identifier " + qubit_var_name + " isn't a single qubit!");
      qubits.push_back(qubit_ident);
    }
  }

  if (context->expressionList()) {
    for (auto expression: context->expressionList()->expression()) {
      auto generator = qasm_expression_generator(builder, symbol_table, builder.getF64Type());
      generator.visitExpression(expression);
      params.push_back(generator.current_value);
    }
  }

  auto inst = builder.create<quantum::ValueSemanticsInstOp>(builder.getUnknownLoc(),
                                                            std::vector<Type>{qubit_type},
                                                            builder.getStringAttr(qgn->getText()),
                                                            qubits, params);


  //TODO (BUG): Only works if applied to different variables
  auto it = inst.result().begin();
  for (auto index: context->indexedIdentifier()) {
    auto qubit_var_name = index->Identifier()->getText();
    symbol_table.add_symbol(qubit_var_name, *it, {}, true);
    it = std::next(it);
  }
//  symbol_table.replace_symbol(qubits.front(), inst.result().front());
  return {};
}