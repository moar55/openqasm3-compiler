#include "expression_handler.h"
#include "mlir/Dialect/Arith/IR/Arith.h"
#include "mlir/Dialect/Tensor/IR/Tensor.h"

using namespace mlir;
std::any visitor::visitSingleDesignatorDeclaration(
        qasmParser::SingleDesignatorDeclarationContext* context) {
  //TODO: make sure a variable is not redeclared!
  auto type = context->singleDesignatorType()->getText();
  auto designator_expr = context->designator()->expression();
  auto width_idx = std::stoi(designator_expr->getText()); //TODO: catch non const int values

  Attribute init_attr;
  Type value_type;
  if (type == "int") {
    value_type = builder.getIntegerType(width_idx);
    init_attr = IntegerAttr::get(value_type, 0);
  } else if (type == "uint") {
    value_type = builder.getIntegerType(width_idx, false);
    init_attr = IntegerAttr::get(value_type, 0);
  } else if (type == "float") {
    if (width_idx == 16) {
      value_type = FloatType::getF16(builder.getContext());
      init_attr = FloatAttr::get(value_type, 0.0);

    } else if (width_idx == 32) {
      value_type = FloatType::getF32(builder.getContext());
      init_attr = FloatAttr::get(value_type, 0.0);

    } else if (width_idx == 64) {
      value_type = FloatType::getF64(builder.getContext());
      init_attr = FloatAttr::get(value_type, 0.0);

    } else {
      printErrorMessage("We only support 16, 32, and 64 floating point types.", context);
    }
  } else {
    printErrorMessage("We do not currently support this type: " + type, context);
  }
  Value val;
  if (context->equalsExpression()) {
    auto text = context->Identifier()->getText();
    qasm_expression_generator generator(builder, symbol_table, value_type);
    generator.visitExpression(context->equalsExpression()->expression());
     val = generator.current_value;
  } else {
     val = builder.create<arith::ConstantOp>(builder.getUnknownLoc(), init_attr); // default value
  }
  symbol_table.add_symbol(context->Identifier()->getText(), val);
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
  int size;
  if (context->designator()) {
    try {
      size = std::stoi(context->designator()->expression()->getText());
    } catch(...) {
      printErrorMessage("currently only constant integers are supported as desingator indices");
    }
  } else {
    size = 1;
  }
//  Value mlir_vector;
//  if (!context->equalsExpression()) {

    auto default_val = get_mlir_integer_val(builder, 0, builder.getI1Type()); // TODO: check if nested regions commen expressions are eleminated
    ArrayRef<int64_t> shape {size};
    auto memref = builder.create<memref::AllocOp>(builder.getUnknownLoc(), MemRefType::get(shape, builder.getI1Type()));
    auto default_val2 = get_mlir_integer_val(builder, 0, builder.getIndexType());
    auto val3 = builder.create<memref::LoadOp>(builder.getUnknownLoc(), memref, default_val2); //
    builder.create<arith::ExtUIOp>(builder.getUnknownLoc(), builder.getI32Type(), val3);
//    for (int i = 0; i < size; i++) {
//
//    }
//    auto tensor = builder.create<tensor::EmptyOp>(builder.getUnknownLoc(), shape, builder.getI1Type());
//    auto val = builder.create<linalg::FillOp>(builder.getUnknownLoc(), {default_val}, {tensor});
//  }
//  auto vector_type = VectorType::get({size}, builder.getI1Type());
//  auto vector_attr = DenseIntElementsAttr::get(vector_type, std::vector<int>(size, 0));
//  auto mlir_vector = builder.create<arith::ConstantOp>(builder.getUnknownLoc(), vector_attr, vector_type);
  //  auto mem_type = MemRefType::get(shaperef, builder.getI1Type());
//  Value allocation = builder.create<memref::AllocaOp>(builder.getUnknownLoc(), mem_type);
//  auto integer_type = builder.getI1Type();
//  auto integer_attr = IntegerAttr::get(integer_type, 0);
//  auto value = builder.create<arith::ConstantOp>(builder.getUnknownLoc(), integer_attr, integer_type);
//  builder.create<memref::StoreOp>(builder.getUnknownLoc(), value, allocation);
//  symbol_table.add_symbol(context->Identifier()->getText(), mlir_vector);
  return 0;
}


std::any visitor::visitClassicalAssignment(qasmParser::ClassicalAssignmentContext *ctx) {
  auto identifier = ctx->indexedIdentifier()->Identifier();
  auto ass_operator = ctx->assignmentOperator();
  std::string identifier_text = identifier->getText();
  if (!symbol_table.has_symbol(identifier_text)) {
    std::string err_msg = "Can't apply" + ass_operator->getText() + "to an uninitialized variable" + identifier_text;
    printErrorMessage(err_msg);
  }
  Value identifier_val = symbol_table.get_symbol(identifier_text);
  qasm_expression_generator generator(builder, symbol_table, identifier_val.getType());
  generator.visitExpression(ctx->expression());
  symbol_table.add_symbol(identifier_text, generator.current_value, true);
  return {};
}