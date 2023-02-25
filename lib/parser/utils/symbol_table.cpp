#include "symbol_table.hpp"

#include <iostream>

#include "exprtk.hpp"
#include "quantum-mlir/Dialect/Quantum/IR/QuantumOps.h"
#include "mlir/IR/Builders.h"
#include "mlir/IR/BuiltinTypes.h"

using symbol_table_t = exprtk::symbol_table<double>;
using expression_t = exprtk::expression<double>;
using parser_t = exprtk::parser<double>;


std::string ScopedSymbolTable::get_symbol_var_name(mlir::Value value) {
  auto iter = replacement_helper.find(value.getAsOpaquePointer());
  return iter != replacement_helper.end() ? iter->second : "";
}

std::string &replace_val(std::string &s, const std::string &from, const std::string &to) {
  if (!from.empty())
    for (size_t pos = 0; (pos = s.find(from, pos)) != std::string::npos; pos += to.size())
      s.replace(pos, from.size(), to);
  return s;
}

void ScopedSymbolTable::add_measure_bit_assignment(
        const mlir::Value &bit_var, const mlir::Value &result_var) {
  assert(result_var.getType().isa<mlir::OpaqueType>());
  bit_var_ptr_to_meas_result_var[bit_var.getAsOpaquePointer()] = result_var;
}

std::optional<mlir::Value>
ScopedSymbolTable::try_lookup_meas_result(const mlir::Value &bit_var) {
  const auto iter =
          bit_var_ptr_to_meas_result_var.find(bit_var.getAsOpaquePointer());
  if (iter != bit_var_ptr_to_meas_result_var.end()) {
    return iter->second;
  }
  return std::nullopt;
}

std::optional<mlir::Value>
ScopedSymbolTable::try_lookup_meas_result(const std::string &bit_var_name) {
  if (!has_symbol(bit_var_name)) {
    return std::nullopt;
  }
  return try_lookup_meas_result(get_symbol(bit_var_name));
}

void ScopedSymbolTable::erase_symbol(const std::string &var_name) {
  for (auto &table: scoped_symbol_tables) {
    table.erase_symbol(var_name);
  }
}

bool ScopedSymbolTable::verify_qubit_ssa_dominance_property(
        mlir::Value qubit, mlir::Block *current_block) {
  assert(qubit.getType().isa<mlir::OpaqueType>() &&
         qubit.getType().dyn_cast<mlir::OpaqueType>().getTypeData() == "Qubit");

  // Checking that the QVS Op that **produces** this qubit is in the same
  // region as this op.
  // i.e., if the Op that produces this qubit SSA is in a for or if region,
  // this qubit SSA is **not** properly dominated. Hence, requires a re-extract.
  if (auto *useOp = qubit.getDefiningOp()) {
    if (mlir::dyn_cast_or_null<mlir::quantum::GenGate>(useOp)) {
      mlir::Block *block2 = useOp->getBlock();
      mlir::Region *region1 = current_block->getParent();
      mlir::Region *region2 = block2->getParent();
      return region1 == region2;
    }
  }

  return true;
}

void ScopedSymbolTable::add_symbol(const std::string variable_name, const mlir::Value &value, const std::size_t scope,
                                   bool overwrite) {
  if (scope > current_scope) {
    printErrorMessage("Provided scope is greater than the current scope.\n");
  }

  if (has_symbol(variable_name)) {
    if (!overwrite) {
      printErrorMessage(variable_name + " is already in the symbol table.");
    } else {
      scoped_symbol_tables[scope][variable_name] = value;
      last_value_added = value;
      replacement_helper[value.getAsOpaquePointer()] = variable_name;
      return;
    }
  }

  scoped_symbol_tables[scope].insert({variable_name, value});
  last_value_added = value;

  replacement_helper.insert({value.getAsOpaquePointer(), variable_name});
}

void ScopedSymbolTable::add_symbol(const std::string variable_name, const mlir::Value &value, bool overwrite) {
  add_symbol(variable_name, value, current_scope, overwrite);
}

void ScopedSymbolTable::add_global_symbol(const std::string variable_name, const mlir::Value &value) {
  add_symbol(variable_name, value, 0, false);
}
