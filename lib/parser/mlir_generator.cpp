/*******************************************************************************
 * Copyright (c) 2018-, UT-Battelle, LLC.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the BSD 3-Clause License
 * which accompanies this distribution.
 *
 * Contributors:
 *   Alexander J. McCaskey - initial API and implementation
 *   Thien Nguyen - implementation
 *******************************************************************************/
#include "mlir_generator.hpp"

#include "Visitor.hpp"
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/Dialect/Arith/IR/Arith.h"
#include "generated/qasmLexer.h"
#include "generated/qasmParser.h"

using namespace mlir;

void MLIRGenerator::initialize(
        const std::string entry_function_name) {

  auto int_type = builder.getI64Type();
  auto func_type =
          builder.getFunctionType({}, int_type);
  auto proto =
          func::FuncOp::create(builder.getUnknownLoc(), entry_function_name, func_type);
  func::FuncOp function(proto);
  auto &entryBlock = *function.addEntryBlock();
  builder.setInsertionPointToStart(&entryBlock);
  m_module.push_back(function);
}


void MLIRGenerator::generate(const std::string &src) {
  using namespace antlr4;

  if (!my_visitor) {
    my_visitor = std::make_shared<Visitor>(builder, m_module, file_name
            /*,enable_qir_apply_ifelse*/);
  }
//  auto symbol_table = Visitor->getScopedSymbolTable();

  ANTLRInputStream input(src);
  qasmLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  qasmParser parser(&tokens);

  class Qasm3ParserErrorListener : public BaseErrorListener {
  private:
      std::string file_name;

  public:
      Qasm3ParserErrorListener(const std::string &s) : file_name(s) {}

      void syntaxError(Recognizer *recognizer, Token *offendingSymbol,
                       size_t line, size_t charPositionInLine,
                       const std::string &msg, std::exception_ptr e) override {
        std::stringstream ss;
        ss << "\n\n[OPENQASM3 MLIRGen] cannot parse the source.\nerror: " << msg
           << "\n";
        ss << "occurred at " << file_name << ":" << line << ":"
           << charPositionInLine
           << ", offending symbol = " << offendingSymbol->getText() << "\n\n";
        std::cout << ss.str();
        exit(1);
      }
  };

  // Setup our custom error listeners
  lexer.removeErrorListeners();
  parser.removeErrorListeners();
  Qasm3ParserErrorListener el(file_name);
  parser.addErrorListener(&el);

  // Get the parse tree and visit
  tree::ParseTree *tree = parser.program();
  my_visitor->visitChildren(tree);
  auto return_op = get_mlir_integer_val(builder, 0, builder.getI64Type());
  builder.create<func::ReturnOp>(builder.getUnknownLoc(), return_op);
}
