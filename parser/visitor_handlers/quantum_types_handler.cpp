#include "../visitor.hpp"

antlrcpp::Any visitor::visitQuantumDeclaration(qasmParser::QuantumDeclarationContext *context) {
  return {};
}

antlrcpp::Any visitor::visitQuantumGateDefinition(qasmParser::QuantumGateDefinitionContext *context) {
  return {};
}

visitor::visitor(mlir::OpBuilder b, mlir::ModuleOp m, std::string &fname)
        : builder(b), file_name(fname), m_module(m) {
  auto context = b.getContext();
  llvm::StringRef qubit_type_name("Qubit"), array_type_name("Array"),
          result_type_name("Result");
  mlir::Identifier dialect = mlir::Identifier::get("quantum", context);
  qubit_type = mlir::OpaqueType::get(context, dialect, qubit_type_name);
  array_type = mlir::OpaqueType::get(context, dialect, array_type_name);
  result_type = mlir::OpaqueType::get(context, dialect, result_type_name);
  symbol_table.set_op_builder(builder);
}
