#include "visitor.hpp"

// The constructor, instantiates commonly used opaque types
visitor::visitor(mlir::OpBuilder b, mlir::ModuleOp m, std::string &fname) : builder(b), m_module(m), file_name(fname) {
  auto context = b.getContext();
  llvm::StringRef name("quantum"), qubit_type_name("Qubit"), array_type_name("Array"), result_type_name("Result");
  StringAttr n = StringAttr::get(context, name); // namespace
  qubit_type = mlir::OpaqueType::get(n, qubit_type_name);
  array_type = mlir::OpaqueType::get(n, array_type_name);
  result_type = mlir::OpaqueType::get(n, result_type_name);
//  symbol_table.set_op_builder(builder);
}

visitor::~visitor() {}

