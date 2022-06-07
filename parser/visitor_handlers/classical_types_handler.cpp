#include "../visitor.hpp"

std::any visitor::visitSingleDesignatorDeclaration(
        qasmParser::SingleDesignatorDeclarationContext* context)  {
  return {};
}

std::any visitor::visitNoDesignatorDeclaration(
        qasmParser::NoDesignatorDeclarationContext* context) {
  return {};
}

std::any visitor::visitBitDeclaration(
        qasmParser::BitDeclarationContext* context) {
  return {};
}