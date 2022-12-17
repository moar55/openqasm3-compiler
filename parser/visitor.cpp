#include "visitor.hpp"
#include "mlir/Dialect/SCF/SCF.h"
#include "Quantum/IR/QuantumOps.h"

// The constructor, instantiates commonly used opaque types
visitor::visitor(mlir::OpBuilder b, mlir::ModuleOp m, std::string &fname) : builder(b), m_module(m), file_name(fname) {
  auto context = b.getContext();
  llvm::StringRef name("quantum"), qubit_type_name("Qubit"), array_type_name("Array"), result_type_name("Result");
  StringAttr n = StringAttr::get(context, name); // namespace
  qubit_type = mlir::OpaqueType::get(n, qubit_type_name);
  array_type = mlir::OpaqueType::get(n, array_type_name);
  result_type = mlir::OpaqueType::get(n, result_type_name);
  symbol_table.set_op_builder(builder);
}

void visitor::gen_yield_of_symbols(const std::set<std::string> yield_symbols) {
  for (auto const& symbol: yield_symbols) {
    if (symbol_table.has_symbol(symbol)) {
      builder.create<scf::YieldOp>(builder.getUnknownLoc(), symbol_table.get_symbol(symbol));
    } else { // symbol is an indexed identifier that wasn't extracted till this point
      auto idx = get_index_from_indexed_name(symbol);
      auto idx_val = get_mlir_integer_val(builder, idx);
      auto indexless_symbol = get_name_from_indexed_name(symbol);
      auto qubit_arr = symbol_table.get_symbol(indexless_symbol);
      mlir::Value qubit = builder.create<quantum::ExtractQubitOp>(builder.getUnknownLoc(), qubit_type, qubit_arr, *idx_val);
      symbol_table.add_symbol(symbol, qubit); // TODO: check if  this line is unnecessary
      builder.create<scf::YieldOp>(builder.getUnknownLoc(), qubit);
    }
  }
}


mlir::Type visitor::get_symbol_type(const std::string &var_name) {
  if (symbol_table.has_symbol(var_name)) {
    return symbol_table.get_symbol(var_name).getType();
  }
  if (symbol_table.has_symbol(var_name, true)) {
    return qubit_type;
  }

  printErrorMessage(("var " + var_name + " doesn't exist!"));
}

visitor::~visitor() {}

