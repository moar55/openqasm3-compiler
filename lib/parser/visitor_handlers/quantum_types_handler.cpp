#include "../visitor.hpp"
#include "quantum-mlir/Dialect/Quantum/IR/QuantumOps.h"
#include "mlir/Dialect/Arith/IR/Arith.h"
#include "expression_handler.h"


using namespace mlir;

std::any visitor::visitQuantumDeclaration(qasmParser::QuantumDeclarationContext *context) {
  //TODO: disallow non const expressions for designator
  std::string var_name = context->Identifier()->getText();
  StringAttr str_attr = builder.getStringAttr(var_name);
  int64_t size = 1;
  if (context->designator()) {
//    IntegerType  type = builder.getIntegerType(64);
//    auto generator = qasm_expression_generator(builder, symbol_table, type);
//    generator.visitExpression(context->designator()->expression());
//    auto defining_op = generator.current_value.getDefiningOp<arith::ConstantOp>();
    size = std::stoi(context->designator()->expression()->getText());
  }
  IntegerType integer_type = builder.getI64Type();
  IntegerAttr integer_attr = IntegerAttr::get(integer_type, size);

  mlir::Value allocation = builder.create<mlir::quantum::QallocOp>(
          builder.getUnknownLoc(), array_type, integer_attr, str_attr);

  if (size == 1) {
    auto pos = get_mlir_integer_val(builder, 0, builder.getI64Type());
    allocation = builder.create<quantum::ExtractQubitOp>(
          builder.getUnknownLoc(), qubit_type, allocation, pos);
  }
  symbol_table.add_symbol(var_name, allocation);
  return {};
}


//  auto line = context->getStart()->getLine();
//  auto col = context->getStart()->getCharPositionInLine();
//  auto loc =  builder.get(builder.getIdentifier(file_name), line, col);
//
//
//  auto location = context->
//builder.create<>()
//  builder.getUnknownLoc()
//  std::size_t size = 1;
//  auto compatibility_identifier_list = context->compatibilityIdentifierList();
//
//  bool pre_designator, assigned= false;
//
//  if (compatibility_identifier_list->compatibilityIdentifier().front()->designator()) {
//    pre_designator = compatibility_identifier_list->compatibilityIdentifier().front()->start->getText() == "[";
//    assigned = true;
//  }

//  for (auto compatibility_identifier : compatibility_identifier_list->compatibilityIdentifier()) {
//    auto var_name = compatibility_identifier->Identifier()->getText();
//    auto designator = compatibility_identifier->designator();
//    if (designator) {
//      if (assigned) {
//        bool val = compatibility_identifier->start->getText() == "[";
//        if (val != pre_designator)
//          printErrorMessage("Inconsistent designator placement in quantum identifier list");
//      } else {
//        if (compatibility_identifier->designator()) {
//          pre_designator = compatibility_identifier->start->getText() == "[";
//          assigned = true;
//        }
//      }
//      auto opt_size = symbol_table.try_evaluate_constant_integer_expression(
//              designator->expression()->getText());
//      if (opt_size.has_value()) {
//        size = opt_size.value();
//      } else {
//         check if this is a constant expression
//        qasm3_expression_generator exp_generator(builder, symbol_table,
//                                                 file_name);
//        exp_generator.visit(designator->expression());
//        auto arg = exp_generator.current_value;
//
//        if (auto constantOp = arg.getDefiningOp<mlir::ConstantOp>()) {
//          if (constantOp.getValue().isa<mlir::IntegerAttr>()) {
//            size = constantOp.getValue().cast<mlir::IntegerAttr>().getInt();
//          } else {
//            printErrorMessage(
//                    "This variable qubit size must be a constant integer.");
//          }
//        } else {
//          size = symbol_table.get_global_constant<int64_t>(
//                  designator->expression()->getText());
//        }
//      }
//    }
//


//    if (context->quantumType()->getText() == "qubit" && size == 1) {
      // we have a single qubit, dont set it as an array in teh
      // symbol table, extract it and set it
//      mlir::Value pos = get_or_create_constant_integer_value(
//              0, location, builder.getIntegerType(64), symbol_table, builder);

      // Need to also store the qubit array for this single qubit
      // so that we can deallocate later.
//      symbol_table.add_symbol("__qcor__mlir__single_qubit_register_" + var_name,
//                              allocation);
//
//      allocation = builder.create<mlir::quantum::ExtractQubitOp>(
//              location, qubit_type, allocation, pos);
//    }
//
//    symbol_table.add_symbol(var_name, allocation);
//    size = 1;
//  }
//  return {};
//}

std::any visitor::visitQuantumGateDefinition(qasmParser::QuantumGateDefinitionContext *context) {
  std::cout<< "In there boooi"<<std::endl;
  return {};
}