#include "expression_handler.h"
#include "quantum-mlir/Dialect/Quantum/IR/QuantumOps.h"

using namespace mlir;

std::any visitor::visitQuantumGateCall(qasmParser::QuantumGateCallContext *context) {
  //TODO: disallow non const expressions for indexing
  //TODO: make sure a variable is not redeclared!
  auto qgn = context->quantumGateName();
  std::vector<Value> qubits, params;
  std::vector<Type> types;
  std::vector<std::string> symbols;

  for (auto index: context->indexedIdentifier()) {
    auto qubit_var_name = index->Identifier()->getText();

    if (!symbol_table.has_symbol(qubit_var_name)) {
      printErrorMessage("Identifier " + qubit_var_name + " isn't declared!");
    }

    auto qubit_ident = symbol_table.get_symbol(qubit_var_name);
    if(!qubit_ident.getType().isa<OpaqueType>())
      printErrorMessage("Identifier " + qubit_var_name + " isn't a qubit or qubit array");

    if (!index->indexOperator().empty()) {
      if (get_quantum_type(qubit_ident) != "Array")
        printErrorMessage("can't index a non qubit array type");

      auto index_expression = index->indexOperator().front()->expression(0);

      if (!index_expression)
        printErrorMessage("expected an expression as an index for the qubit array");

      try {
        auto idx = std::stoi(index_expression->getText());
        auto allocation_size = get_qubit_arr_size(qubit_ident);
        if ( idx < 0 || idx > allocation_size - 1) { //check that indexing is not out of bounds
          printErrorMessage("index out of bound for indexing variable " + qubit_var_name);
        }
        auto qubit = get_or_extrct_qubit(symbol_table, qubit_var_name, idx, &builder, &qubit_type);
        qubits.push_back(qubit);
        auto indexed_name = get_indexed_name(qubit_var_name, idx);
        symbols.push_back(indexed_name);
      } catch(...) {
          printErrorMessage("currently only constant integer indices are supported", context);
        }
    } else {
      if (get_quantum_type(qubit_ident) != "Qubit")
        printErrorMessage("Identifier " + qubit_var_name + " isn't a single qubit!");
      qubits.push_back(qubit_ident);
      symbols.push_back(qubit_var_name);
    }
    types.push_back(qubit_type);
  }

  if (context->expressionList()) {
    for (auto expression: context->expressionList()->expression()) {
      auto generator = qasm_expression_generator(builder, symbol_table, builder.getF64Type());
      generator.visitExpression(expression);
      params.push_back(generator.current_value);
    }
  }

  auto inst = builder.create<quantum::ValueSemanticsInstOp>(builder.getUnknownLoc(),
                                                            types,
                                                            builder.getStringAttr(qgn->getText()),
                                                            qubits, params);

  auto it = inst.getResult().begin();
  for (auto symbol: symbols) {
    symbol_table.add_symbol(symbol, *it, true);
    it = std::next(it);
  }

//  builder.createca
  return {};
}