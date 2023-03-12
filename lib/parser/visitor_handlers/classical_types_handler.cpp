#include "expression_handler.h"
#include "mlir/Dialect/Arith/IR/Arith.h"
#include "mlir/Dialect/Tensor/IR/Tensor.h"

#include "mlir/Dialect/Vector/IR/VectorOps.h"

using namespace mlir;
std::any Visitor::visitSingleDesignatorDeclaration(
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

  auto total_size = 2;
  auto size = total_size * 2 * 2;
  ArrayRef<int64_t> shape {size};
  std::vector<double> init(size);
  std::fill(init.begin(), init.end(), 0.0);
  init[0] = 1.0;
  auto vector_type = VectorType::get(shape, builder.getF64Type());
  auto attr = DenseFPElementsAttr::get(vector_type, init);
  Value global_vector = builder.create<arith::ConstantOp>(builder.getUnknownLoc(), attr, vector_type);
  global_vector = builder.create<vector::ShapeCastOp>(builder.getUnknownLoc(), VectorType::get({total_size * 2, 2}, builder.getF64Type()), global_vector);

  return {};
}

std::any Visitor::visitBitDeclaration(
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

  auto identifier_name = context->Identifier()->getText();
  if (context->equalsExpression()) {
    printErrorMessage("declarative initalization of bits is not yet supported");
  } else {
    Value val;
    if (size == 1) {
        val = get_mlir_integer_val(builder, 0, builder.getI1Type());
      } else {
      ArrayRef<int64_t> shape {size};
      auto vector_type = VectorType::get(shape, builder.getI1Type());
      auto attr = DenseIntElementsAttr::get(vector_type, false);
      val = builder.create<arith::ConstantOp>(builder.getUnknownLoc(), attr, vector_type);
    }
    symbol_table.add_symbol(identifier_name, val);
  }
  return 0;
}

std::any Visitor::visitClassicalAssignment(qasmParser::ClassicalAssignmentContext *ctx) {
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
  if (identifier_val.getType() != generator.current_value.getType()) {
    if (!identifier_val.getType().isa<VectorType>() || !generator.current_value.getType().isa<VectorType>() ||
            (identifier_val.getType().dyn_cast<VectorType>()).getShape()[0] < generator.current_value.getType().dyn_cast<VectorType>().getShape()[0]) { //TODO: make this more accomodating
      printErrorMessage("mismatch of type/dimension between evaluated expression, and variable assigned to", ctx);
    }
  }
  symbol_table.add_symbol(identifier_text, generator.current_value, true);
  return {};
}