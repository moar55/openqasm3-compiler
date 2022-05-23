#include "../visitor.hpp"

antlrcpp::Any visitor::visitSingleDesignatorDeclaration(
        qasmParser::SingleDesignatorDeclarationContext* context)  {
  return {};
}

antlrcpp::Any visitor::visitNoDesignatorDeclaration(
        qasmParser::NoDesignatorDeclarationContext* context) {
  return {}
}

antlrcpp::Any visitor::visitBitDeclaration(
        qasmParser::BitDeclarationContext* context) {
  return {};
}