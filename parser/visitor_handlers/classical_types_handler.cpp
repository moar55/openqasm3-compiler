#include "../visitor.hpp"
#include "mlir/Dialect/Arithmetic/IR/Arithmetic.h"

class visitor;

std::any visitor::visitSingleDesignatorDeclaration(
        qasmParser::SingleDesignatorDeclarationContext* context) {
  auto type = context->singleDesignatorType()->getText();
  auto designator_expr = context->designator()->expression();
  auto width_idx = std::stoi(designator_expr->getText());

  mlir::Attribute init_attr;
  mlir::Type value_type;
  if (type == "int") {
    value_type = builder.getIntegerType(width_idx);
    init_attr = mlir::IntegerAttr::get(value_type, 0);
  } else if (type == "uint") {
    value_type = builder.getIntegerType(width_idx, false);
    init_attr = mlir::IntegerAttr::get(value_type, 0);
  } else if (type == "float") {
    if (width_idx == 16) {
      value_type = mlir::FloatType::getF16(builder.getContext());
      init_attr = mlir::FloatAttr::get(value_type, 0.0);

    } else if (width_idx == 32) {
      value_type = mlir::FloatType::getF32(builder.getContext());
      init_attr = mlir::FloatAttr::get(value_type, 0.0);

    } else if (width_idx == 64) {
      value_type = mlir::FloatType::getF64(builder.getContext());
      init_attr = mlir::FloatAttr::get(value_type, 0.0);

    } else {
        std::cout << "err" << "we only support 16, 32, and 64 floating point types." << context << std::endl;
    }
  } else {
    std::cout << "err" << "We do not currently support this type: " << type << context << std::endl;
  }

  llvm::ArrayRef<int64_t> shaperef{};
  auto mem_type = mlir::MemRefType::get(shaperef, value_type);
  mlir::Value allocation = builder.create<mlir::memref::AllocaOp>(builder.getUnknownLoc(), mem_type);
  symbol_table.add_symbol(context->Identifier()->getText(), allocation);
  return {};
}

std::any visitor::visitBitDeclaration(
        qasmParser::BitDeclarationContext* context) {
  // bitDeclaration
  //     : bitType (indexIdentifierList | indexEqualsAssignmentList )
  //     ;
  //     indexIdentifier
  //     : Identifier rangeDefinition
  //     | Identifier ( LBRACKET expressionList RBRACKET )?
  //     | indexIdentifier '||' indexIdentifier
  //     ;

  // indexIdentifierList
  //     : ( indexIdentifier COMMA )* indexIdentifier
  //     ;
  // indexEqualsAssignmentList
  //     : ( indexIdentifier equalsExpression COMMA)* indexIdentifier
  //     equalsExpression
  //     ;


  llvm::ArrayRef<int64_t> shaperef{};
  auto mem_type = mlir::MemRefType::get(shaperef, builder.getI1Type());
  mlir::Value allocation = builder.create<mlir::memref::AllocaOp>(builder.getUnknownLoc(), mem_type);
  auto integer_type = builder.getI1Type();
  auto integer_attr = mlir::IntegerAttr::get(integer_type, 0);
  auto value = builder.create<mlir::arith::ConstantOp>(builder.getUnknownLoc(), integer_attr, integer_type);
  builder.create<mlir::memref::StoreOp>(builder.getUnknownLoc(), value, allocation);
  symbol_table.add_symbol(context->Identifier()->getText(), allocation);
  return 0;
}