#include "expression_handler.h"
#include "quantum-mlir/Dialect/Quantum/IR/QuantumOps.h"
#include <map>
#include <string>
#include <functional>
#include <algorithm>

using namespace mlir;


std::map<std::string, std::function<Value(OpBuilder &, Location &, Type &, Value &, Value *)>> build_map = {
        {"X",  [](OpBuilder &builder, Location &loc, Type &type, Value &value, Value *value2) {
            return builder.create<quantum::XOp>(loc, type, value);
        }},
        {"Y",  [](OpBuilder &builder, Location &loc, Type &type, Value &value, Value *value2) {
            return builder.create<quantum::YOp>(loc, type, value);
        }},
        {"Z",  [](OpBuilder &builder, Location &loc, Type &type, Value &value, Value *value2) {
            return builder.create<quantum::ZOp>(loc, type, value);
        }},
        {"I",  [](OpBuilder &builder, Location &loc, Type &type, Value &value, Value *value2) {
            return builder.create<quantum::IOp>(loc, type, value);
        }},
        {"H",  [](OpBuilder &builder, Location &loc, Type &type, Value &value, Value *value2) {
            return builder.create<quantum::HOp>(loc, type, value);
        }},
        {"S",  [](OpBuilder &builder, Location &loc, Type &type, Value &value, Value *value2) {
            return builder.create<quantum::SOp>(loc, type, value);
        }},
        {"T",  [](OpBuilder &builder, Location &loc, Type &type, Value &value, Value *value2) {
            return builder.create<quantum::TOp>(loc, type, value);
        }},
        {"RX", [](OpBuilder &builder, Location &loc, Type &type, Value &value, Value *value2) {
            return builder.create<quantum::RxOp>(loc, type, value, *value2);
        }},
        {"RY", [](OpBuilder &builder, Location &loc, Type &type, Value &value, Value *value2) {
            return builder.create<quantum::RyOp>(loc, type, value, *value2);
        }},
        {"RZ", [](OpBuilder &builder, Location &loc, Type &type, Value &value, Value *value2) {
            return builder.create<quantum::RzOp>(loc, type, value, *value2);
        }}
};


const std::vector<std::string> single_qubit_ops = {"X", "Y", "Z", "I", "H", "S", "T"};
const std::vector<std::string> rotation_gates = {"RX", "RY", "RZ"};


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
    if (!qubit_ident.getType().isa<OpaqueType>())
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
        if (idx < 0 || idx > allocation_size - 1) { //check that indexing is not out of bounds
          printErrorMessage("index out of bound for indexing variable " + qubit_var_name);
        }
        auto qubit = get_or_extrct_qubit(symbol_table, qubit_var_name, idx, &builder, &qubit_type);
        qubits.push_back(qubit);
        auto indexed_name = get_indexed_name(qubit_var_name, idx);
        symbols.push_back(indexed_name);
      } catch (...) {
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

  std::unique_ptr<ResultRange> results;

  //TODO: refactor
  auto loc = builder.getUnknownLoc();
  const auto qgn_text = qgn->getText();
  if (std::find(single_qubit_ops.begin(), single_qubit_ops.end(), qgn_text) != single_qubit_ops.end()) {
    if (qubits.size() != 1 || params.size() > 0) {
      printErrorMessage("simple single qubit gates require exactly 1 qubit and 0 params!");
    }
    auto func = build_map.at(qgn_text);
    auto res = func(builder, loc, types[0], qubits[0], nullptr).getDefiningOp()->getResults();
    results = std::make_unique<ResultRange>(res);
  } else if (std::find(rotation_gates.begin(), rotation_gates.end(), qgn_text) != rotation_gates.end()) {
    if (qubits.size() != 1 || params.size() != 1) { //TODO: check second argument is F64
      printErrorMessage("simple single qubit gates requires a qubit and a rotation angle param");
    }
    auto func = build_map.at(qgn_text);
    auto res = func(builder, loc, types[0], qubits[0], &params[0]).getDefiningOp()->getResults();
    results = std::make_unique<ResultRange>(res);
  } else if (qgn_text == "CX") {
    if (qubits.size() != 2 || params.size() > 0) {
      printErrorMessage("CNOT gate require exactly 2 qubit and 0 params!");
    }
    auto res = builder.create<quantum::CXOp>(builder.getUnknownLoc(), types[0], types[1], qubits[0],
                                             qubits[1])->getResults();
    results = std::make_unique<ResultRange>(res);
  } else {
    auto res = builder.create<quantum::GenGate>(builder.getUnknownLoc(),
                                                types,
                                                builder.getStringAttr(qgn->getText()),
                                                qubits, params)->getResults();
    results = std::make_unique<ResultRange>(res);
  }

  auto it = results->begin();
  for (auto symbol: symbols) {
    symbol_table.add_symbol(symbol, *it, true);
    it = std::next(it);
  }

  return {};
}