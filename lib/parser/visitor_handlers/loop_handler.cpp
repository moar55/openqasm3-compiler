#include "mlir/Dialect/SCF/IR/SCF.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "../generated/qasmLexer.h"
#include <quantum-mlir/Dialect/RestrictedQuantum/IR/RestrictedQuantumDialect.h>
#include "mlir/Dialect/Vector/IR/VectorOps.h"

using namespace mlir;


void find_symbols(qasmParser::ExpressionContext *ctx, std::set<std::string> &symbols) {
  if (ctx->expressionTerminator()) {
    if (ctx->expressionTerminator()->Identifier()) {
      symbols.insert(ctx->getText());
    }
    return ;
  }


  // get tokens and
  antlr4::CharStream *input = ctx->start->getInputStream();
  antlr4::misc::Interval intrvl = antlr4::misc::Interval();
  intrvl.a = ctx->getStart()->getStartIndex();
  intrvl.b = ctx->getStop()->getStopIndex();
  std::string condStr = input->getText(intrvl);
  antlr4::ANTLRInputStream cond(condStr);
  qasmLexer lex(&cond);
  auto tokens = lex.getAllTokens();
  for (const auto &token: tokens) {
    //TODO: add extra condition to make sure not a function name
    if (token->getType() == qasmLexer::Identifier) {
      symbols.insert(token->getText());
    }
  }
}

std::any visitor::visitLoopStatement(qasmParser::LoopStatementContext *ctx) {
  auto signature = ctx->loopSignature();
  if (signature->getStart()->getText() == "while") {
    auto cond = signature->expression();
    // get the identifier symbols needed in the condition
    std::set<std::string> symbols;
    find_symbols(cond, symbols); //TODO: find a single symbol?
    auto cond_type = symbol_table.get_symbol(*symbols.begin()).getType();
//    std::vector<Value> symbols_values;
//    std::vector<Type> symbols_types;
//
//    for (auto &symbol: symbols) {
//      if (!symbol_table.has_symbol(symbol)) {
//        printErrorMessage("unkown symbol " + symbol, cond);
//      }
//      symbols_values.push_back(symbol_table.get_symbol(symbol));
//      symbols_types.push_back(get_symbol_type(symbol));
////      auto allocation = builder.create<memref::AllocOp>(builder.getUnknownLoc(), MemRefType::get(1, get_symbol_type(symbol)));
////      builder.create<memref::LoadOp>(builder.getUnknownLoc(), symbol_table.get_symbol(symbol));
////      symbol_table.add_symbol(symbol, allocation);
//    }
    // end getting identifier symbols

    auto builder_backup = builder;
    // -------------- begin shadow visit ----------------------------//
    //TODO: refactor in a function?
    auto context = std::make_unique<MLIRContext>();
    context->loadDialect<quantum::QuantumDialect, memref::MemRefDialect, arith::ArithDialect,
            vector::VectorDialect,
            scf::SCFDialect, func::FuncDialect, restquantum::RestrictedQuantumDialect>();
    OpBuilder shadow_builder(context.get());
    std::set<std::string> yield_symbols;
    std::vector<Value> yield_values;
    std::vector<Type> yield_types;

    builder = shadow_builder;
    symbol_table.enter_new_scope();
    // visit then scope nodes
    this->visitChildren(ctx->programBlock());
    for (auto const& [symbol, val] : symbol_table.get_symbols_and_values_pair(symbol_table.get_current_scope())) { //TODO: refactor in a funciton
      if (symbol_table.has_symbol(symbol, symbol_table.get_parent_scope(), true)) { //TODO: make sure this is actually necessary in this case
        yield_symbols.insert(symbol);
      }
    }

    symbol_table.exit_scope();
    //-------------- end shadow build --------------------------//
    builder = builder_backup;

    for (auto &symbol: yield_symbols) {
      auto val = symbol_table.get_symbol(symbol);
      yield_values.push_back(val);
      yield_types.push_back(val.getType());
    }

//
//    symbols.insert(yield_symbols.begin(), yield_symbols.end());
//    symbols_values.insert(symbols_values.end(), yield_values.begin(), yield_values.end());
//    symbols_types.insert(symbols_types.end(), yield_types.begin(), yield_types.end());

    symbol_table.enter_new_scope();
    auto whileOp = builder.create<scf::WhileOp>(builder.getUnknownLoc(),
                                                yield_types, yield_values,
                                                [&](OpBuilder &beforeBuilder, Location loc, ValueRange args) {
                      // a bit hacky way to tell the generator that the symbols should be the args of this function
                        auto it = args.begin();
                        for (auto symbol: yield_symbols) {
                          symbol_table.add_symbol(symbol, *it, true);
                          it = std::next(it);
                        }

                        // fix this
                        qasm_expression_generator generator(beforeBuilder, symbol_table, cond_type);
                        generator.visitExpression(cond);
//                        auto type = beforeBuilder.getI1Type();
//                        auto intr = IntegerAttr::get(type, 1);
//                        auto val = beforeBuilder.create<arith::ConstantOp>(beforeBuilder.getUnknownLoc(), intr);
                        beforeBuilder.create<scf::ConditionOp>(beforeBuilder.getUnknownLoc(), generator.current_value, args);
                      }, [&](OpBuilder &afterBuilder, Location loc, ValueRange args2) {
                        auto it = args2.begin();
                        for (auto symbol: yield_symbols) {
                          symbol_table.add_symbol(symbol, *it, true);
                          it = std::next(it);
                      }
                      auto temp = builder;
                      builder = afterBuilder;
                      this->visitChildren(ctx->programBlock());
                      builder = temp;
                      std::vector<Value> output_values;
                      for (auto &symbol: yield_symbols) {
                        output_values.push_back(symbol_table.get_symbol(symbol));
                      }
                      afterBuilder.create<scf::YieldOp>(afterBuilder.getUnknownLoc(), output_values);
            });
    symbol_table.exit_scope();
    auto it = whileOp.getResults().begin();
    for (auto &symbol: yield_symbols) {
      symbol_table.add_symbol(symbol, *it, true);
      it = std::next(it);
    }

//    builder.create
//    builder.createBlock()
//    whileOp.getBefore().push_back()
//    auto x = builder.createBlock()
  } else {
    printErrorMessage("for loops are not yet supported");
  }
  return {};
}
