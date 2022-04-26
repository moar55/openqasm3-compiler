
// Generated from qasm.g4 by ANTLR 4.9.2


#include "qasmListener.h"
#include "qasmVisitor.h"

#include "qasmParser.h"


using namespace antlrcpp;
using namespace antlr4;

qasmParser::qasmParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

qasmParser::~qasmParser() {
  delete _interpreter;
}

std::string qasmParser::getGrammarFileName() const {
  return "qasm.g4";
}

const std::vector<std::string>& qasmParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& qasmParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

qasmParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::HeaderContext* qasmParser::ProgramContext::header() {
  return getRuleContext<qasmParser::HeaderContext>(0);
}

std::vector<qasmParser::GlobalStatementContext *> qasmParser::ProgramContext::globalStatement() {
  return getRuleContexts<qasmParser::GlobalStatementContext>();
}

qasmParser::GlobalStatementContext* qasmParser::ProgramContext::globalStatement(size_t i) {
  return getRuleContext<qasmParser::GlobalStatementContext>(i);
}

std::vector<qasmParser::StatementContext *> qasmParser::ProgramContext::statement() {
  return getRuleContexts<qasmParser::StatementContext>();
}

qasmParser::StatementContext* qasmParser::ProgramContext::statement(size_t i) {
  return getRuleContext<qasmParser::StatementContext>(i);
}


size_t qasmParser::ProgramContext::getRuleIndex() const {
  return qasmParser::RuleProgram;
}

void qasmParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void qasmParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


antlrcpp::Any qasmParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::ProgramContext* qasmParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, qasmParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(226);
    header();
    setState(231);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasmParser::T__4)
      | (1ULL << qasmParser::T__5)
      | (1ULL << qasmParser::T__6)
      | (1ULL << qasmParser::T__7)
      | (1ULL << qasmParser::T__8)
      | (1ULL << qasmParser::T__9)
      | (1ULL << qasmParser::T__10)
      | (1ULL << qasmParser::T__11)
      | (1ULL << qasmParser::T__12)
      | (1ULL << qasmParser::T__13)
      | (1ULL << qasmParser::T__15)
      | (1ULL << qasmParser::T__16)
      | (1ULL << qasmParser::T__17)
      | (1ULL << qasmParser::T__18)
      | (1ULL << qasmParser::T__19)
      | (1ULL << qasmParser::T__20)
      | (1ULL << qasmParser::T__21)
      | (1ULL << qasmParser::T__22)
      | (1ULL << qasmParser::T__24)
      | (1ULL << qasmParser::T__25)
      | (1ULL << qasmParser::T__26)
      | (1ULL << qasmParser::T__27)
      | (1ULL << qasmParser::T__28)
      | (1ULL << qasmParser::T__43)
      | (1ULL << qasmParser::T__44)
      | (1ULL << qasmParser::T__45)
      | (1ULL << qasmParser::T__46)
      | (1ULL << qasmParser::T__47)
      | (1ULL << qasmParser::T__48)
      | (1ULL << qasmParser::T__49)
      | (1ULL << qasmParser::T__50)
      | (1ULL << qasmParser::T__51)
      | (1ULL << qasmParser::T__52)
      | (1ULL << qasmParser::T__53)
      | (1ULL << qasmParser::T__54)
      | (1ULL << qasmParser::T__55)
      | (1ULL << qasmParser::T__56))) != 0) || ((((_la - 70) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 70)) & ((1ULL << (qasmParser::T__69 - 70))
      | (1ULL << (qasmParser::T__71 - 70))
      | (1ULL << (qasmParser::T__73 - 70))
      | (1ULL << (qasmParser::T__74 - 70))
      | (1ULL << (qasmParser::T__78 - 70))
      | (1ULL << (qasmParser::T__79 - 70))
      | (1ULL << (qasmParser::T__80 - 70))
      | (1ULL << (qasmParser::T__81 - 70))
      | (1ULL << (qasmParser::T__82 - 70))
      | (1ULL << (qasmParser::T__83 - 70))
      | (1ULL << (qasmParser::T__84 - 70))
      | (1ULL << (qasmParser::T__85 - 70))
      | (1ULL << (qasmParser::T__86 - 70))
      | (1ULL << (qasmParser::T__87 - 70))
      | (1ULL << (qasmParser::T__88 - 70))
      | (1ULL << (qasmParser::LPAREN - 70))
      | (1ULL << (qasmParser::MINUS - 70))
      | (1ULL << (qasmParser::ImagNumber - 70))
      | (1ULL << (qasmParser::COMPLEX - 70))
      | (1ULL << (qasmParser::CONST - 70))
      | (1ULL << (qasmParser::ARRAY - 70))
      | (1ULL << (qasmParser::SIZEOF - 70))
      | (1ULL << (qasmParser::Constant - 70))
      | (1ULL << (qasmParser::Integer - 70))
      | (1ULL << (qasmParser::Identifier - 70))
      | (1ULL << (qasmParser::RealNumber - 70))
      | (1ULL << (qasmParser::TimingLiteral - 70))
      | (1ULL << (qasmParser::StringLiteral - 70)))) != 0)) {
      setState(229);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case qasmParser::T__4:
        case qasmParser::T__5:
        case qasmParser::T__15:
        case qasmParser::T__78:
        case qasmParser::T__79:
        case qasmParser::T__80:
        case qasmParser::T__87:
        case qasmParser::T__88: {
          setState(227);
          globalStatement();
          break;
        }

        case qasmParser::T__6:
        case qasmParser::T__7:
        case qasmParser::T__8:
        case qasmParser::T__9:
        case qasmParser::T__10:
        case qasmParser::T__11:
        case qasmParser::T__12:
        case qasmParser::T__13:
        case qasmParser::T__16:
        case qasmParser::T__17:
        case qasmParser::T__18:
        case qasmParser::T__19:
        case qasmParser::T__20:
        case qasmParser::T__21:
        case qasmParser::T__22:
        case qasmParser::T__24:
        case qasmParser::T__25:
        case qasmParser::T__26:
        case qasmParser::T__27:
        case qasmParser::T__28:
        case qasmParser::T__43:
        case qasmParser::T__44:
        case qasmParser::T__45:
        case qasmParser::T__46:
        case qasmParser::T__47:
        case qasmParser::T__48:
        case qasmParser::T__49:
        case qasmParser::T__50:
        case qasmParser::T__51:
        case qasmParser::T__52:
        case qasmParser::T__53:
        case qasmParser::T__54:
        case qasmParser::T__55:
        case qasmParser::T__56:
        case qasmParser::T__69:
        case qasmParser::T__71:
        case qasmParser::T__73:
        case qasmParser::T__74:
        case qasmParser::T__81:
        case qasmParser::T__82:
        case qasmParser::T__83:
        case qasmParser::T__84:
        case qasmParser::T__85:
        case qasmParser::T__86:
        case qasmParser::LPAREN:
        case qasmParser::MINUS:
        case qasmParser::ImagNumber:
        case qasmParser::COMPLEX:
        case qasmParser::CONST:
        case qasmParser::ARRAY:
        case qasmParser::SIZEOF:
        case qasmParser::Constant:
        case qasmParser::Integer:
        case qasmParser::Identifier:
        case qasmParser::RealNumber:
        case qasmParser::TimingLiteral:
        case qasmParser::StringLiteral: {
          setState(228);
          statement();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(233);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- HeaderContext ------------------------------------------------------------------

qasmParser::HeaderContext::HeaderContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::VersionContext* qasmParser::HeaderContext::version() {
  return getRuleContext<qasmParser::VersionContext>(0);
}

std::vector<qasmParser::IncludeContext *> qasmParser::HeaderContext::include() {
  return getRuleContexts<qasmParser::IncludeContext>();
}

qasmParser::IncludeContext* qasmParser::HeaderContext::include(size_t i) {
  return getRuleContext<qasmParser::IncludeContext>(i);
}

std::vector<qasmParser::IoContext *> qasmParser::HeaderContext::io() {
  return getRuleContexts<qasmParser::IoContext>();
}

qasmParser::IoContext* qasmParser::HeaderContext::io(size_t i) {
  return getRuleContext<qasmParser::IoContext>(i);
}


size_t qasmParser::HeaderContext::getRuleIndex() const {
  return qasmParser::RuleHeader;
}

void qasmParser::HeaderContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterHeader(this);
}

void qasmParser::HeaderContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitHeader(this);
}


antlrcpp::Any qasmParser::HeaderContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitHeader(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::HeaderContext* qasmParser::header() {
  HeaderContext *_localctx = _tracker.createInstance<HeaderContext>(_ctx, getState());
  enterRule(_localctx, 2, qasmParser::RuleHeader);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(235);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasmParser::T__0) {
      setState(234);
      version();
    }
    setState(240);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == qasmParser::T__1) {
      setState(237);
      include();
      setState(242);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(246);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == qasmParser::T__2

    || _la == qasmParser::T__3) {
      setState(243);
      io();
      setState(248);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VersionContext ------------------------------------------------------------------

qasmParser::VersionContext::VersionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasmParser::VersionContext::SEMICOLON() {
  return getToken(qasmParser::SEMICOLON, 0);
}

tree::TerminalNode* qasmParser::VersionContext::Integer() {
  return getToken(qasmParser::Integer, 0);
}

tree::TerminalNode* qasmParser::VersionContext::RealNumber() {
  return getToken(qasmParser::RealNumber, 0);
}


size_t qasmParser::VersionContext::getRuleIndex() const {
  return qasmParser::RuleVersion;
}

void qasmParser::VersionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVersion(this);
}

void qasmParser::VersionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVersion(this);
}


antlrcpp::Any qasmParser::VersionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitVersion(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::VersionContext* qasmParser::version() {
  VersionContext *_localctx = _tracker.createInstance<VersionContext>(_ctx, getState());
  enterRule(_localctx, 4, qasmParser::RuleVersion);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(249);
    match(qasmParser::T__0);
    setState(250);
    _la = _input->LA(1);
    if (!(_la == qasmParser::Integer

    || _la == qasmParser::RealNumber)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(251);
    match(qasmParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IncludeContext ------------------------------------------------------------------

qasmParser::IncludeContext::IncludeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasmParser::IncludeContext::StringLiteral() {
  return getToken(qasmParser::StringLiteral, 0);
}

tree::TerminalNode* qasmParser::IncludeContext::SEMICOLON() {
  return getToken(qasmParser::SEMICOLON, 0);
}


size_t qasmParser::IncludeContext::getRuleIndex() const {
  return qasmParser::RuleInclude;
}

void qasmParser::IncludeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInclude(this);
}

void qasmParser::IncludeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInclude(this);
}


antlrcpp::Any qasmParser::IncludeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitInclude(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::IncludeContext* qasmParser::include() {
  IncludeContext *_localctx = _tracker.createInstance<IncludeContext>(_ctx, getState());
  enterRule(_localctx, 6, qasmParser::RuleInclude);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(253);
    match(qasmParser::T__1);
    setState(254);
    match(qasmParser::StringLiteral);
    setState(255);
    match(qasmParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IoIdentifierContext ------------------------------------------------------------------

qasmParser::IoIdentifierContext::IoIdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t qasmParser::IoIdentifierContext::getRuleIndex() const {
  return qasmParser::RuleIoIdentifier;
}

void qasmParser::IoIdentifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIoIdentifier(this);
}

void qasmParser::IoIdentifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIoIdentifier(this);
}


antlrcpp::Any qasmParser::IoIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitIoIdentifier(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::IoIdentifierContext* qasmParser::ioIdentifier() {
  IoIdentifierContext *_localctx = _tracker.createInstance<IoIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 8, qasmParser::RuleIoIdentifier);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(257);
    _la = _input->LA(1);
    if (!(_la == qasmParser::T__2

    || _la == qasmParser::T__3)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IoContext ------------------------------------------------------------------

qasmParser::IoContext::IoContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::IoIdentifierContext* qasmParser::IoContext::ioIdentifier() {
  return getRuleContext<qasmParser::IoIdentifierContext>(0);
}

qasmParser::ClassicalTypeContext* qasmParser::IoContext::classicalType() {
  return getRuleContext<qasmParser::ClassicalTypeContext>(0);
}

tree::TerminalNode* qasmParser::IoContext::Identifier() {
  return getToken(qasmParser::Identifier, 0);
}

tree::TerminalNode* qasmParser::IoContext::SEMICOLON() {
  return getToken(qasmParser::SEMICOLON, 0);
}


size_t qasmParser::IoContext::getRuleIndex() const {
  return qasmParser::RuleIo;
}

void qasmParser::IoContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIo(this);
}

void qasmParser::IoContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIo(this);
}


antlrcpp::Any qasmParser::IoContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitIo(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::IoContext* qasmParser::io() {
  IoContext *_localctx = _tracker.createInstance<IoContext>(_ctx, getState());
  enterRule(_localctx, 10, qasmParser::RuleIo);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(259);
    ioIdentifier();
    setState(260);
    classicalType();
    setState(261);
    match(qasmParser::Identifier);
    setState(262);
    match(qasmParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GlobalStatementContext ------------------------------------------------------------------

qasmParser::GlobalStatementContext::GlobalStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::SubroutineDefinitionContext* qasmParser::GlobalStatementContext::subroutineDefinition() {
  return getRuleContext<qasmParser::SubroutineDefinitionContext>(0);
}

qasmParser::ExternDeclarationContext* qasmParser::GlobalStatementContext::externDeclaration() {
  return getRuleContext<qasmParser::ExternDeclarationContext>(0);
}

qasmParser::QuantumGateDefinitionContext* qasmParser::GlobalStatementContext::quantumGateDefinition() {
  return getRuleContext<qasmParser::QuantumGateDefinitionContext>(0);
}

qasmParser::CalibrationContext* qasmParser::GlobalStatementContext::calibration() {
  return getRuleContext<qasmParser::CalibrationContext>(0);
}

qasmParser::QuantumDeclarationStatementContext* qasmParser::GlobalStatementContext::quantumDeclarationStatement() {
  return getRuleContext<qasmParser::QuantumDeclarationStatementContext>(0);
}

qasmParser::PragmaContext* qasmParser::GlobalStatementContext::pragma() {
  return getRuleContext<qasmParser::PragmaContext>(0);
}


size_t qasmParser::GlobalStatementContext::getRuleIndex() const {
  return qasmParser::RuleGlobalStatement;
}

void qasmParser::GlobalStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGlobalStatement(this);
}

void qasmParser::GlobalStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGlobalStatement(this);
}


antlrcpp::Any qasmParser::GlobalStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitGlobalStatement(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::GlobalStatementContext* qasmParser::globalStatement() {
  GlobalStatementContext *_localctx = _tracker.createInstance<GlobalStatementContext>(_ctx, getState());
  enterRule(_localctx, 12, qasmParser::RuleGlobalStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(270);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasmParser::T__79: {
        enterOuterAlt(_localctx, 1);
        setState(264);
        subroutineDefinition();
        break;
      }

      case qasmParser::T__78: {
        enterOuterAlt(_localctx, 2);
        setState(265);
        externDeclaration();
        break;
      }

      case qasmParser::T__15: {
        enterOuterAlt(_localctx, 3);
        setState(266);
        quantumGateDefinition();
        break;
      }

      case qasmParser::T__87:
      case qasmParser::T__88: {
        enterOuterAlt(_localctx, 4);
        setState(267);
        calibration();
        break;
      }

      case qasmParser::T__4:
      case qasmParser::T__5: {
        enterOuterAlt(_localctx, 5);
        setState(268);
        quantumDeclarationStatement();
        break;
      }

      case qasmParser::T__80: {
        enterOuterAlt(_localctx, 6);
        setState(269);
        pragma();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

qasmParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::ExpressionStatementContext* qasmParser::StatementContext::expressionStatement() {
  return getRuleContext<qasmParser::ExpressionStatementContext>(0);
}

qasmParser::AssignmentStatementContext* qasmParser::StatementContext::assignmentStatement() {
  return getRuleContext<qasmParser::AssignmentStatementContext>(0);
}

qasmParser::ClassicalDeclarationStatementContext* qasmParser::StatementContext::classicalDeclarationStatement() {
  return getRuleContext<qasmParser::ClassicalDeclarationStatementContext>(0);
}

qasmParser::BranchingStatementContext* qasmParser::StatementContext::branchingStatement() {
  return getRuleContext<qasmParser::BranchingStatementContext>(0);
}

qasmParser::LoopStatementContext* qasmParser::StatementContext::loopStatement() {
  return getRuleContext<qasmParser::LoopStatementContext>(0);
}

qasmParser::EndStatementContext* qasmParser::StatementContext::endStatement() {
  return getRuleContext<qasmParser::EndStatementContext>(0);
}

qasmParser::AliasStatementContext* qasmParser::StatementContext::aliasStatement() {
  return getRuleContext<qasmParser::AliasStatementContext>(0);
}

qasmParser::QuantumStatementContext* qasmParser::StatementContext::quantumStatement() {
  return getRuleContext<qasmParser::QuantumStatementContext>(0);
}


size_t qasmParser::StatementContext::getRuleIndex() const {
  return qasmParser::RuleStatement;
}

void qasmParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void qasmParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


antlrcpp::Any qasmParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::StatementContext* qasmParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 14, qasmParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(280);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(272);
      expressionStatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(273);
      assignmentStatement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(274);
      classicalDeclarationStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(275);
      branchingStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(276);
      loopStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(277);
      endStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(278);
      aliasStatement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(279);
      quantumStatement();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuantumDeclarationStatementContext ------------------------------------------------------------------

qasmParser::QuantumDeclarationStatementContext::QuantumDeclarationStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::QuantumDeclarationContext* qasmParser::QuantumDeclarationStatementContext::quantumDeclaration() {
  return getRuleContext<qasmParser::QuantumDeclarationContext>(0);
}

tree::TerminalNode* qasmParser::QuantumDeclarationStatementContext::SEMICOLON() {
  return getToken(qasmParser::SEMICOLON, 0);
}


size_t qasmParser::QuantumDeclarationStatementContext::getRuleIndex() const {
  return qasmParser::RuleQuantumDeclarationStatement;
}

void qasmParser::QuantumDeclarationStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQuantumDeclarationStatement(this);
}

void qasmParser::QuantumDeclarationStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQuantumDeclarationStatement(this);
}


antlrcpp::Any qasmParser::QuantumDeclarationStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitQuantumDeclarationStatement(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::QuantumDeclarationStatementContext* qasmParser::quantumDeclarationStatement() {
  QuantumDeclarationStatementContext *_localctx = _tracker.createInstance<QuantumDeclarationStatementContext>(_ctx, getState());
  enterRule(_localctx, 16, qasmParser::RuleQuantumDeclarationStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(282);
    quantumDeclaration();
    setState(283);
    match(qasmParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassicalDeclarationStatementContext ------------------------------------------------------------------

qasmParser::ClassicalDeclarationStatementContext::ClassicalDeclarationStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasmParser::ClassicalDeclarationStatementContext::SEMICOLON() {
  return getToken(qasmParser::SEMICOLON, 0);
}

qasmParser::ClassicalDeclarationContext* qasmParser::ClassicalDeclarationStatementContext::classicalDeclaration() {
  return getRuleContext<qasmParser::ClassicalDeclarationContext>(0);
}

qasmParser::ConstantDeclarationContext* qasmParser::ClassicalDeclarationStatementContext::constantDeclaration() {
  return getRuleContext<qasmParser::ConstantDeclarationContext>(0);
}


size_t qasmParser::ClassicalDeclarationStatementContext::getRuleIndex() const {
  return qasmParser::RuleClassicalDeclarationStatement;
}

void qasmParser::ClassicalDeclarationStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassicalDeclarationStatement(this);
}

void qasmParser::ClassicalDeclarationStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassicalDeclarationStatement(this);
}


antlrcpp::Any qasmParser::ClassicalDeclarationStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitClassicalDeclarationStatement(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::ClassicalDeclarationStatementContext* qasmParser::classicalDeclarationStatement() {
  ClassicalDeclarationStatementContext *_localctx = _tracker.createInstance<ClassicalDeclarationStatementContext>(_ctx, getState());
  enterRule(_localctx, 18, qasmParser::RuleClassicalDeclarationStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(287);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasmParser::T__6:
      case qasmParser::T__7:
      case qasmParser::T__8:
      case qasmParser::T__9:
      case qasmParser::T__10:
      case qasmParser::T__11:
      case qasmParser::T__12:
      case qasmParser::T__81:
      case qasmParser::T__82:
      case qasmParser::COMPLEX:
      case qasmParser::ARRAY: {
        setState(285);
        classicalDeclaration();
        break;
      }

      case qasmParser::CONST: {
        setState(286);
        constantDeclaration();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(289);
    match(qasmParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassicalAssignmentContext ------------------------------------------------------------------

qasmParser::ClassicalAssignmentContext::ClassicalAssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::IndexedIdentifierContext* qasmParser::ClassicalAssignmentContext::indexedIdentifier() {
  return getRuleContext<qasmParser::IndexedIdentifierContext>(0);
}

qasmParser::AssignmentOperatorContext* qasmParser::ClassicalAssignmentContext::assignmentOperator() {
  return getRuleContext<qasmParser::AssignmentOperatorContext>(0);
}

qasmParser::ExpressionContext* qasmParser::ClassicalAssignmentContext::expression() {
  return getRuleContext<qasmParser::ExpressionContext>(0);
}


size_t qasmParser::ClassicalAssignmentContext::getRuleIndex() const {
  return qasmParser::RuleClassicalAssignment;
}

void qasmParser::ClassicalAssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassicalAssignment(this);
}

void qasmParser::ClassicalAssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassicalAssignment(this);
}


antlrcpp::Any qasmParser::ClassicalAssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitClassicalAssignment(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::ClassicalAssignmentContext* qasmParser::classicalAssignment() {
  ClassicalAssignmentContext *_localctx = _tracker.createInstance<ClassicalAssignmentContext>(_ctx, getState());
  enterRule(_localctx, 20, qasmParser::RuleClassicalAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(291);
    indexedIdentifier();
    setState(292);
    assignmentOperator();
    setState(293);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentStatementContext ------------------------------------------------------------------

qasmParser::AssignmentStatementContext::AssignmentStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasmParser::AssignmentStatementContext::SEMICOLON() {
  return getToken(qasmParser::SEMICOLON, 0);
}

qasmParser::ClassicalAssignmentContext* qasmParser::AssignmentStatementContext::classicalAssignment() {
  return getRuleContext<qasmParser::ClassicalAssignmentContext>(0);
}

qasmParser::QuantumMeasurementAssignmentContext* qasmParser::AssignmentStatementContext::quantumMeasurementAssignment() {
  return getRuleContext<qasmParser::QuantumMeasurementAssignmentContext>(0);
}


size_t qasmParser::AssignmentStatementContext::getRuleIndex() const {
  return qasmParser::RuleAssignmentStatement;
}

void qasmParser::AssignmentStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignmentStatement(this);
}

void qasmParser::AssignmentStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignmentStatement(this);
}


antlrcpp::Any qasmParser::AssignmentStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitAssignmentStatement(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::AssignmentStatementContext* qasmParser::assignmentStatement() {
  AssignmentStatementContext *_localctx = _tracker.createInstance<AssignmentStatementContext>(_ctx, getState());
  enterRule(_localctx, 22, qasmParser::RuleAssignmentStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(297);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      setState(295);
      classicalAssignment();
      break;
    }

    case 2: {
      setState(296);
      quantumMeasurementAssignment();
      break;
    }

    default:
      break;
    }
    setState(299);
    match(qasmParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnSignatureContext ------------------------------------------------------------------

qasmParser::ReturnSignatureContext::ReturnSignatureContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasmParser::ReturnSignatureContext::ARROW() {
  return getToken(qasmParser::ARROW, 0);
}

qasmParser::ClassicalTypeContext* qasmParser::ReturnSignatureContext::classicalType() {
  return getRuleContext<qasmParser::ClassicalTypeContext>(0);
}


size_t qasmParser::ReturnSignatureContext::getRuleIndex() const {
  return qasmParser::RuleReturnSignature;
}

void qasmParser::ReturnSignatureContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnSignature(this);
}

void qasmParser::ReturnSignatureContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnSignature(this);
}


antlrcpp::Any qasmParser::ReturnSignatureContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitReturnSignature(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::ReturnSignatureContext* qasmParser::returnSignature() {
  ReturnSignatureContext *_localctx = _tracker.createInstance<ReturnSignatureContext>(_ctx, getState());
  enterRule(_localctx, 24, qasmParser::RuleReturnSignature);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(301);
    match(qasmParser::ARROW);
    setState(302);
    classicalType();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DesignatorContext ------------------------------------------------------------------

qasmParser::DesignatorContext::DesignatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasmParser::DesignatorContext::LBRACKET() {
  return getToken(qasmParser::LBRACKET, 0);
}

qasmParser::ExpressionContext* qasmParser::DesignatorContext::expression() {
  return getRuleContext<qasmParser::ExpressionContext>(0);
}

tree::TerminalNode* qasmParser::DesignatorContext::RBRACKET() {
  return getToken(qasmParser::RBRACKET, 0);
}


size_t qasmParser::DesignatorContext::getRuleIndex() const {
  return qasmParser::RuleDesignator;
}

void qasmParser::DesignatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDesignator(this);
}

void qasmParser::DesignatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDesignator(this);
}


antlrcpp::Any qasmParser::DesignatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitDesignator(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::DesignatorContext* qasmParser::designator() {
  DesignatorContext *_localctx = _tracker.createInstance<DesignatorContext>(_ctx, getState());
  enterRule(_localctx, 26, qasmParser::RuleDesignator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(304);
    match(qasmParser::LBRACKET);
    setState(305);
    expression(0);
    setState(306);
    match(qasmParser::RBRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierListContext ------------------------------------------------------------------

qasmParser::IdentifierListContext::IdentifierListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> qasmParser::IdentifierListContext::Identifier() {
  return getTokens(qasmParser::Identifier);
}

tree::TerminalNode* qasmParser::IdentifierListContext::Identifier(size_t i) {
  return getToken(qasmParser::Identifier, i);
}

std::vector<tree::TerminalNode *> qasmParser::IdentifierListContext::COMMA() {
  return getTokens(qasmParser::COMMA);
}

tree::TerminalNode* qasmParser::IdentifierListContext::COMMA(size_t i) {
  return getToken(qasmParser::COMMA, i);
}


size_t qasmParser::IdentifierListContext::getRuleIndex() const {
  return qasmParser::RuleIdentifierList;
}

void qasmParser::IdentifierListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifierList(this);
}

void qasmParser::IdentifierListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifierList(this);
}


antlrcpp::Any qasmParser::IdentifierListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitIdentifierList(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::IdentifierListContext* qasmParser::identifierList() {
  IdentifierListContext *_localctx = _tracker.createInstance<IdentifierListContext>(_ctx, getState());
  enterRule(_localctx, 28, qasmParser::RuleIdentifierList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(312);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(308);
        match(qasmParser::Identifier);
        setState(309);
        match(qasmParser::COMMA); 
      }
      setState(314);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    }
    setState(315);
    match(qasmParser::Identifier);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuantumDeclarationContext ------------------------------------------------------------------

qasmParser::QuantumDeclarationContext::QuantumDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasmParser::QuantumDeclarationContext::Identifier() {
  return getToken(qasmParser::Identifier, 0);
}

qasmParser::DesignatorContext* qasmParser::QuantumDeclarationContext::designator() {
  return getRuleContext<qasmParser::DesignatorContext>(0);
}


size_t qasmParser::QuantumDeclarationContext::getRuleIndex() const {
  return qasmParser::RuleQuantumDeclaration;
}

void qasmParser::QuantumDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQuantumDeclaration(this);
}

void qasmParser::QuantumDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQuantumDeclaration(this);
}


antlrcpp::Any qasmParser::QuantumDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitQuantumDeclaration(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::QuantumDeclarationContext* qasmParser::quantumDeclaration() {
  QuantumDeclarationContext *_localctx = _tracker.createInstance<QuantumDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 30, qasmParser::RuleQuantumDeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(327);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasmParser::T__4: {
        enterOuterAlt(_localctx, 1);
        setState(317);
        match(qasmParser::T__4);
        setState(318);
        match(qasmParser::Identifier);
        setState(320);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasmParser::LBRACKET) {
          setState(319);
          designator();
        }
        break;
      }

      case qasmParser::T__5: {
        enterOuterAlt(_localctx, 2);
        setState(322);
        match(qasmParser::T__5);
        setState(324);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasmParser::LBRACKET) {
          setState(323);
          designator();
        }
        setState(326);
        match(qasmParser::Identifier);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuantumArgumentContext ------------------------------------------------------------------

qasmParser::QuantumArgumentContext::QuantumArgumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasmParser::QuantumArgumentContext::Identifier() {
  return getToken(qasmParser::Identifier, 0);
}

qasmParser::DesignatorContext* qasmParser::QuantumArgumentContext::designator() {
  return getRuleContext<qasmParser::DesignatorContext>(0);
}


size_t qasmParser::QuantumArgumentContext::getRuleIndex() const {
  return qasmParser::RuleQuantumArgument;
}

void qasmParser::QuantumArgumentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQuantumArgument(this);
}

void qasmParser::QuantumArgumentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQuantumArgument(this);
}


antlrcpp::Any qasmParser::QuantumArgumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitQuantumArgument(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::QuantumArgumentContext* qasmParser::quantumArgument() {
  QuantumArgumentContext *_localctx = _tracker.createInstance<QuantumArgumentContext>(_ctx, getState());
  enterRule(_localctx, 32, qasmParser::RuleQuantumArgument);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(339);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasmParser::T__4: {
        enterOuterAlt(_localctx, 1);
        setState(329);
        match(qasmParser::T__4);
        setState(330);
        match(qasmParser::Identifier);
        setState(332);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasmParser::LBRACKET) {
          setState(331);
          designator();
        }
        break;
      }

      case qasmParser::T__5: {
        enterOuterAlt(_localctx, 2);
        setState(334);
        match(qasmParser::T__5);
        setState(336);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasmParser::LBRACKET) {
          setState(335);
          designator();
        }
        setState(338);
        match(qasmParser::Identifier);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuantumArgumentListContext ------------------------------------------------------------------

qasmParser::QuantumArgumentListContext::QuantumArgumentListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<qasmParser::QuantumArgumentContext *> qasmParser::QuantumArgumentListContext::quantumArgument() {
  return getRuleContexts<qasmParser::QuantumArgumentContext>();
}

qasmParser::QuantumArgumentContext* qasmParser::QuantumArgumentListContext::quantumArgument(size_t i) {
  return getRuleContext<qasmParser::QuantumArgumentContext>(i);
}

std::vector<tree::TerminalNode *> qasmParser::QuantumArgumentListContext::COMMA() {
  return getTokens(qasmParser::COMMA);
}

tree::TerminalNode* qasmParser::QuantumArgumentListContext::COMMA(size_t i) {
  return getToken(qasmParser::COMMA, i);
}


size_t qasmParser::QuantumArgumentListContext::getRuleIndex() const {
  return qasmParser::RuleQuantumArgumentList;
}

void qasmParser::QuantumArgumentListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQuantumArgumentList(this);
}

void qasmParser::QuantumArgumentListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQuantumArgumentList(this);
}


antlrcpp::Any qasmParser::QuantumArgumentListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitQuantumArgumentList(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::QuantumArgumentListContext* qasmParser::quantumArgumentList() {
  QuantumArgumentListContext *_localctx = _tracker.createInstance<QuantumArgumentListContext>(_ctx, getState());
  enterRule(_localctx, 34, qasmParser::RuleQuantumArgumentList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(341);
    quantumArgument();
    setState(346);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == qasmParser::COMMA) {
      setState(342);
      match(qasmParser::COMMA);
      setState(343);
      quantumArgument();
      setState(348);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BitTypeContext ------------------------------------------------------------------

qasmParser::BitTypeContext::BitTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t qasmParser::BitTypeContext::getRuleIndex() const {
  return qasmParser::RuleBitType;
}

void qasmParser::BitTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBitType(this);
}

void qasmParser::BitTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBitType(this);
}


antlrcpp::Any qasmParser::BitTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitBitType(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::BitTypeContext* qasmParser::bitType() {
  BitTypeContext *_localctx = _tracker.createInstance<BitTypeContext>(_ctx, getState());
  enterRule(_localctx, 36, qasmParser::RuleBitType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(349);
    _la = _input->LA(1);
    if (!(_la == qasmParser::T__6

    || _la == qasmParser::T__7)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SingleDesignatorTypeContext ------------------------------------------------------------------

qasmParser::SingleDesignatorTypeContext::SingleDesignatorTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t qasmParser::SingleDesignatorTypeContext::getRuleIndex() const {
  return qasmParser::RuleSingleDesignatorType;
}

void qasmParser::SingleDesignatorTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSingleDesignatorType(this);
}

void qasmParser::SingleDesignatorTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSingleDesignatorType(this);
}


antlrcpp::Any qasmParser::SingleDesignatorTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitSingleDesignatorType(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::SingleDesignatorTypeContext* qasmParser::singleDesignatorType() {
  SingleDesignatorTypeContext *_localctx = _tracker.createInstance<SingleDesignatorTypeContext>(_ctx, getState());
  enterRule(_localctx, 38, qasmParser::RuleSingleDesignatorType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(351);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasmParser::T__8)
      | (1ULL << qasmParser::T__9)
      | (1ULL << qasmParser::T__10)
      | (1ULL << qasmParser::T__11))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NoDesignatorTypeContext ------------------------------------------------------------------

qasmParser::NoDesignatorTypeContext::NoDesignatorTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::TimingTypeContext* qasmParser::NoDesignatorTypeContext::timingType() {
  return getRuleContext<qasmParser::TimingTypeContext>(0);
}


size_t qasmParser::NoDesignatorTypeContext::getRuleIndex() const {
  return qasmParser::RuleNoDesignatorType;
}

void qasmParser::NoDesignatorTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNoDesignatorType(this);
}

void qasmParser::NoDesignatorTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNoDesignatorType(this);
}


antlrcpp::Any qasmParser::NoDesignatorTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitNoDesignatorType(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::NoDesignatorTypeContext* qasmParser::noDesignatorType() {
  NoDesignatorTypeContext *_localctx = _tracker.createInstance<NoDesignatorTypeContext>(_ctx, getState());
  enterRule(_localctx, 40, qasmParser::RuleNoDesignatorType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(355);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasmParser::T__12: {
        enterOuterAlt(_localctx, 1);
        setState(353);
        match(qasmParser::T__12);
        break;
      }

      case qasmParser::T__81:
      case qasmParser::T__82: {
        enterOuterAlt(_localctx, 2);
        setState(354);
        timingType();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NonArrayTypeContext ------------------------------------------------------------------

qasmParser::NonArrayTypeContext::NonArrayTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::SingleDesignatorTypeContext* qasmParser::NonArrayTypeContext::singleDesignatorType() {
  return getRuleContext<qasmParser::SingleDesignatorTypeContext>(0);
}

qasmParser::DesignatorContext* qasmParser::NonArrayTypeContext::designator() {
  return getRuleContext<qasmParser::DesignatorContext>(0);
}

qasmParser::NoDesignatorTypeContext* qasmParser::NonArrayTypeContext::noDesignatorType() {
  return getRuleContext<qasmParser::NoDesignatorTypeContext>(0);
}

qasmParser::BitTypeContext* qasmParser::NonArrayTypeContext::bitType() {
  return getRuleContext<qasmParser::BitTypeContext>(0);
}

tree::TerminalNode* qasmParser::NonArrayTypeContext::COMPLEX() {
  return getToken(qasmParser::COMPLEX, 0);
}

tree::TerminalNode* qasmParser::NonArrayTypeContext::LBRACKET() {
  return getToken(qasmParser::LBRACKET, 0);
}

qasmParser::NumericTypeContext* qasmParser::NonArrayTypeContext::numericType() {
  return getRuleContext<qasmParser::NumericTypeContext>(0);
}

tree::TerminalNode* qasmParser::NonArrayTypeContext::RBRACKET() {
  return getToken(qasmParser::RBRACKET, 0);
}


size_t qasmParser::NonArrayTypeContext::getRuleIndex() const {
  return qasmParser::RuleNonArrayType;
}

void qasmParser::NonArrayTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNonArrayType(this);
}

void qasmParser::NonArrayTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNonArrayType(this);
}


antlrcpp::Any qasmParser::NonArrayTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitNonArrayType(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::NonArrayTypeContext* qasmParser::nonArrayType() {
  NonArrayTypeContext *_localctx = _tracker.createInstance<NonArrayTypeContext>(_ctx, getState());
  enterRule(_localctx, 42, qasmParser::RuleNonArrayType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(370);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasmParser::T__8:
      case qasmParser::T__9:
      case qasmParser::T__10:
      case qasmParser::T__11: {
        enterOuterAlt(_localctx, 1);
        setState(357);
        singleDesignatorType();
        setState(358);
        designator();
        break;
      }

      case qasmParser::T__12:
      case qasmParser::T__81:
      case qasmParser::T__82: {
        enterOuterAlt(_localctx, 2);
        setState(360);
        noDesignatorType();
        break;
      }

      case qasmParser::T__6:
      case qasmParser::T__7: {
        enterOuterAlt(_localctx, 3);
        setState(361);
        bitType();
        setState(363);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasmParser::LBRACKET) {
          setState(362);
          designator();
        }
        break;
      }

      case qasmParser::COMPLEX: {
        enterOuterAlt(_localctx, 4);
        setState(365);
        match(qasmParser::COMPLEX);
        setState(366);
        match(qasmParser::LBRACKET);
        setState(367);
        numericType();
        setState(368);
        match(qasmParser::RBRACKET);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayTypeContext ------------------------------------------------------------------

qasmParser::ArrayTypeContext::ArrayTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasmParser::ArrayTypeContext::ARRAY() {
  return getToken(qasmParser::ARRAY, 0);
}

tree::TerminalNode* qasmParser::ArrayTypeContext::LBRACKET() {
  return getToken(qasmParser::LBRACKET, 0);
}

qasmParser::NonArrayTypeContext* qasmParser::ArrayTypeContext::nonArrayType() {
  return getRuleContext<qasmParser::NonArrayTypeContext>(0);
}

tree::TerminalNode* qasmParser::ArrayTypeContext::COMMA() {
  return getToken(qasmParser::COMMA, 0);
}

qasmParser::ExpressionListContext* qasmParser::ArrayTypeContext::expressionList() {
  return getRuleContext<qasmParser::ExpressionListContext>(0);
}

tree::TerminalNode* qasmParser::ArrayTypeContext::RBRACKET() {
  return getToken(qasmParser::RBRACKET, 0);
}


size_t qasmParser::ArrayTypeContext::getRuleIndex() const {
  return qasmParser::RuleArrayType;
}

void qasmParser::ArrayTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayType(this);
}

void qasmParser::ArrayTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayType(this);
}


antlrcpp::Any qasmParser::ArrayTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitArrayType(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::ArrayTypeContext* qasmParser::arrayType() {
  ArrayTypeContext *_localctx = _tracker.createInstance<ArrayTypeContext>(_ctx, getState());
  enterRule(_localctx, 44, qasmParser::RuleArrayType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(372);
    match(qasmParser::ARRAY);
    setState(373);
    match(qasmParser::LBRACKET);
    setState(374);
    nonArrayType();
    setState(375);
    match(qasmParser::COMMA);
    setState(376);
    expressionList();
    setState(377);
    match(qasmParser::RBRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayReferenceTypeDimensionSpecifierContext ------------------------------------------------------------------

qasmParser::ArrayReferenceTypeDimensionSpecifierContext::ArrayReferenceTypeDimensionSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::ExpressionListContext* qasmParser::ArrayReferenceTypeDimensionSpecifierContext::expressionList() {
  return getRuleContext<qasmParser::ExpressionListContext>(0);
}

tree::TerminalNode* qasmParser::ArrayReferenceTypeDimensionSpecifierContext::DIM() {
  return getToken(qasmParser::DIM, 0);
}

tree::TerminalNode* qasmParser::ArrayReferenceTypeDimensionSpecifierContext::EQUALS() {
  return getToken(qasmParser::EQUALS, 0);
}

qasmParser::ExpressionContext* qasmParser::ArrayReferenceTypeDimensionSpecifierContext::expression() {
  return getRuleContext<qasmParser::ExpressionContext>(0);
}


size_t qasmParser::ArrayReferenceTypeDimensionSpecifierContext::getRuleIndex() const {
  return qasmParser::RuleArrayReferenceTypeDimensionSpecifier;
}

void qasmParser::ArrayReferenceTypeDimensionSpecifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayReferenceTypeDimensionSpecifier(this);
}

void qasmParser::ArrayReferenceTypeDimensionSpecifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayReferenceTypeDimensionSpecifier(this);
}


antlrcpp::Any qasmParser::ArrayReferenceTypeDimensionSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitArrayReferenceTypeDimensionSpecifier(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::ArrayReferenceTypeDimensionSpecifierContext* qasmParser::arrayReferenceTypeDimensionSpecifier() {
  ArrayReferenceTypeDimensionSpecifierContext *_localctx = _tracker.createInstance<ArrayReferenceTypeDimensionSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 46, qasmParser::RuleArrayReferenceTypeDimensionSpecifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(383);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasmParser::T__6:
      case qasmParser::T__7:
      case qasmParser::T__8:
      case qasmParser::T__9:
      case qasmParser::T__10:
      case qasmParser::T__11:
      case qasmParser::T__12:
      case qasmParser::T__27:
      case qasmParser::T__28:
      case qasmParser::T__43:
      case qasmParser::T__44:
      case qasmParser::T__45:
      case qasmParser::T__46:
      case qasmParser::T__47:
      case qasmParser::T__48:
      case qasmParser::T__49:
      case qasmParser::T__50:
      case qasmParser::T__51:
      case qasmParser::T__52:
      case qasmParser::T__53:
      case qasmParser::T__54:
      case qasmParser::T__55:
      case qasmParser::T__56:
      case qasmParser::T__81:
      case qasmParser::T__82:
      case qasmParser::T__84:
      case qasmParser::LPAREN:
      case qasmParser::MINUS:
      case qasmParser::ImagNumber:
      case qasmParser::COMPLEX:
      case qasmParser::ARRAY:
      case qasmParser::SIZEOF:
      case qasmParser::Constant:
      case qasmParser::Integer:
      case qasmParser::Identifier:
      case qasmParser::RealNumber:
      case qasmParser::TimingLiteral:
      case qasmParser::StringLiteral: {
        setState(379);
        expressionList();
        break;
      }

      case qasmParser::DIM: {
        setState(380);
        match(qasmParser::DIM);
        setState(381);
        match(qasmParser::EQUALS);
        setState(382);
        expression(0);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayReferenceTypeContext ------------------------------------------------------------------

qasmParser::ArrayReferenceTypeContext::ArrayReferenceTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasmParser::ArrayReferenceTypeContext::ARRAY() {
  return getToken(qasmParser::ARRAY, 0);
}

tree::TerminalNode* qasmParser::ArrayReferenceTypeContext::LBRACKET() {
  return getToken(qasmParser::LBRACKET, 0);
}

qasmParser::NonArrayTypeContext* qasmParser::ArrayReferenceTypeContext::nonArrayType() {
  return getRuleContext<qasmParser::NonArrayTypeContext>(0);
}

tree::TerminalNode* qasmParser::ArrayReferenceTypeContext::COMMA() {
  return getToken(qasmParser::COMMA, 0);
}

qasmParser::ArrayReferenceTypeDimensionSpecifierContext* qasmParser::ArrayReferenceTypeContext::arrayReferenceTypeDimensionSpecifier() {
  return getRuleContext<qasmParser::ArrayReferenceTypeDimensionSpecifierContext>(0);
}

tree::TerminalNode* qasmParser::ArrayReferenceTypeContext::RBRACKET() {
  return getToken(qasmParser::RBRACKET, 0);
}


size_t qasmParser::ArrayReferenceTypeContext::getRuleIndex() const {
  return qasmParser::RuleArrayReferenceType;
}

void qasmParser::ArrayReferenceTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayReferenceType(this);
}

void qasmParser::ArrayReferenceTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayReferenceType(this);
}


antlrcpp::Any qasmParser::ArrayReferenceTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitArrayReferenceType(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::ArrayReferenceTypeContext* qasmParser::arrayReferenceType() {
  ArrayReferenceTypeContext *_localctx = _tracker.createInstance<ArrayReferenceTypeContext>(_ctx, getState());
  enterRule(_localctx, 48, qasmParser::RuleArrayReferenceType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(385);
    match(qasmParser::ARRAY);
    setState(386);
    match(qasmParser::LBRACKET);
    setState(387);
    nonArrayType();
    setState(388);
    match(qasmParser::COMMA);
    setState(389);
    arrayReferenceTypeDimensionSpecifier();
    setState(390);
    match(qasmParser::RBRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassicalTypeContext ------------------------------------------------------------------

qasmParser::ClassicalTypeContext::ClassicalTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::NonArrayTypeContext* qasmParser::ClassicalTypeContext::nonArrayType() {
  return getRuleContext<qasmParser::NonArrayTypeContext>(0);
}

qasmParser::ArrayTypeContext* qasmParser::ClassicalTypeContext::arrayType() {
  return getRuleContext<qasmParser::ArrayTypeContext>(0);
}


size_t qasmParser::ClassicalTypeContext::getRuleIndex() const {
  return qasmParser::RuleClassicalType;
}

void qasmParser::ClassicalTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassicalType(this);
}

void qasmParser::ClassicalTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassicalType(this);
}


antlrcpp::Any qasmParser::ClassicalTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitClassicalType(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::ClassicalTypeContext* qasmParser::classicalType() {
  ClassicalTypeContext *_localctx = _tracker.createInstance<ClassicalTypeContext>(_ctx, getState());
  enterRule(_localctx, 50, qasmParser::RuleClassicalType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(394);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasmParser::T__6:
      case qasmParser::T__7:
      case qasmParser::T__8:
      case qasmParser::T__9:
      case qasmParser::T__10:
      case qasmParser::T__11:
      case qasmParser::T__12:
      case qasmParser::T__81:
      case qasmParser::T__82:
      case qasmParser::COMPLEX: {
        enterOuterAlt(_localctx, 1);
        setState(392);
        nonArrayType();
        break;
      }

      case qasmParser::ARRAY: {
        enterOuterAlt(_localctx, 2);
        setState(393);
        arrayType();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumericTypeContext ------------------------------------------------------------------

qasmParser::NumericTypeContext::NumericTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::SingleDesignatorTypeContext* qasmParser::NumericTypeContext::singleDesignatorType() {
  return getRuleContext<qasmParser::SingleDesignatorTypeContext>(0);
}

qasmParser::DesignatorContext* qasmParser::NumericTypeContext::designator() {
  return getRuleContext<qasmParser::DesignatorContext>(0);
}


size_t qasmParser::NumericTypeContext::getRuleIndex() const {
  return qasmParser::RuleNumericType;
}

void qasmParser::NumericTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumericType(this);
}

void qasmParser::NumericTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumericType(this);
}


antlrcpp::Any qasmParser::NumericTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitNumericType(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::NumericTypeContext* qasmParser::numericType() {
  NumericTypeContext *_localctx = _tracker.createInstance<NumericTypeContext>(_ctx, getState());
  enterRule(_localctx, 52, qasmParser::RuleNumericType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(396);
    singleDesignatorType();
    setState(397);
    designator();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantDeclarationContext ------------------------------------------------------------------

qasmParser::ConstantDeclarationContext::ConstantDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasmParser::ConstantDeclarationContext::CONST() {
  return getToken(qasmParser::CONST, 0);
}

qasmParser::ClassicalTypeContext* qasmParser::ConstantDeclarationContext::classicalType() {
  return getRuleContext<qasmParser::ClassicalTypeContext>(0);
}

tree::TerminalNode* qasmParser::ConstantDeclarationContext::Identifier() {
  return getToken(qasmParser::Identifier, 0);
}

qasmParser::EqualsExpressionContext* qasmParser::ConstantDeclarationContext::equalsExpression() {
  return getRuleContext<qasmParser::EqualsExpressionContext>(0);
}


size_t qasmParser::ConstantDeclarationContext::getRuleIndex() const {
  return qasmParser::RuleConstantDeclaration;
}

void qasmParser::ConstantDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstantDeclaration(this);
}

void qasmParser::ConstantDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstantDeclaration(this);
}


antlrcpp::Any qasmParser::ConstantDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitConstantDeclaration(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::ConstantDeclarationContext* qasmParser::constantDeclaration() {
  ConstantDeclarationContext *_localctx = _tracker.createInstance<ConstantDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 54, qasmParser::RuleConstantDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(399);
    match(qasmParser::CONST);
    setState(400);
    classicalType();
    setState(401);
    match(qasmParser::Identifier);
    setState(402);
    equalsExpression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SingleDesignatorDeclarationContext ------------------------------------------------------------------

qasmParser::SingleDesignatorDeclarationContext::SingleDesignatorDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::SingleDesignatorTypeContext* qasmParser::SingleDesignatorDeclarationContext::singleDesignatorType() {
  return getRuleContext<qasmParser::SingleDesignatorTypeContext>(0);
}

qasmParser::DesignatorContext* qasmParser::SingleDesignatorDeclarationContext::designator() {
  return getRuleContext<qasmParser::DesignatorContext>(0);
}

tree::TerminalNode* qasmParser::SingleDesignatorDeclarationContext::Identifier() {
  return getToken(qasmParser::Identifier, 0);
}

qasmParser::EqualsExpressionContext* qasmParser::SingleDesignatorDeclarationContext::equalsExpression() {
  return getRuleContext<qasmParser::EqualsExpressionContext>(0);
}


size_t qasmParser::SingleDesignatorDeclarationContext::getRuleIndex() const {
  return qasmParser::RuleSingleDesignatorDeclaration;
}

void qasmParser::SingleDesignatorDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSingleDesignatorDeclaration(this);
}

void qasmParser::SingleDesignatorDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSingleDesignatorDeclaration(this);
}


antlrcpp::Any qasmParser::SingleDesignatorDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitSingleDesignatorDeclaration(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::SingleDesignatorDeclarationContext* qasmParser::singleDesignatorDeclaration() {
  SingleDesignatorDeclarationContext *_localctx = _tracker.createInstance<SingleDesignatorDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 56, qasmParser::RuleSingleDesignatorDeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(404);
    singleDesignatorType();
    setState(405);
    designator();
    setState(406);
    match(qasmParser::Identifier);
    setState(408);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasmParser::EQUALS) {
      setState(407);
      equalsExpression();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NoDesignatorDeclarationContext ------------------------------------------------------------------

qasmParser::NoDesignatorDeclarationContext::NoDesignatorDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::NoDesignatorTypeContext* qasmParser::NoDesignatorDeclarationContext::noDesignatorType() {
  return getRuleContext<qasmParser::NoDesignatorTypeContext>(0);
}

tree::TerminalNode* qasmParser::NoDesignatorDeclarationContext::Identifier() {
  return getToken(qasmParser::Identifier, 0);
}

qasmParser::EqualsExpressionContext* qasmParser::NoDesignatorDeclarationContext::equalsExpression() {
  return getRuleContext<qasmParser::EqualsExpressionContext>(0);
}


size_t qasmParser::NoDesignatorDeclarationContext::getRuleIndex() const {
  return qasmParser::RuleNoDesignatorDeclaration;
}

void qasmParser::NoDesignatorDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNoDesignatorDeclaration(this);
}

void qasmParser::NoDesignatorDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNoDesignatorDeclaration(this);
}


antlrcpp::Any qasmParser::NoDesignatorDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitNoDesignatorDeclaration(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::NoDesignatorDeclarationContext* qasmParser::noDesignatorDeclaration() {
  NoDesignatorDeclarationContext *_localctx = _tracker.createInstance<NoDesignatorDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 58, qasmParser::RuleNoDesignatorDeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(410);
    noDesignatorType();
    setState(411);
    match(qasmParser::Identifier);
    setState(413);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasmParser::EQUALS) {
      setState(412);
      equalsExpression();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BitDeclarationContext ------------------------------------------------------------------

qasmParser::BitDeclarationContext::BitDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasmParser::BitDeclarationContext::Identifier() {
  return getToken(qasmParser::Identifier, 0);
}

qasmParser::EqualsExpressionContext* qasmParser::BitDeclarationContext::equalsExpression() {
  return getRuleContext<qasmParser::EqualsExpressionContext>(0);
}

qasmParser::DesignatorContext* qasmParser::BitDeclarationContext::designator() {
  return getRuleContext<qasmParser::DesignatorContext>(0);
}


size_t qasmParser::BitDeclarationContext::getRuleIndex() const {
  return qasmParser::RuleBitDeclaration;
}

void qasmParser::BitDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBitDeclaration(this);
}

void qasmParser::BitDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBitDeclaration(this);
}


antlrcpp::Any qasmParser::BitDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitBitDeclaration(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::BitDeclarationContext* qasmParser::bitDeclaration() {
  BitDeclarationContext *_localctx = _tracker.createInstance<BitDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 60, qasmParser::RuleBitDeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(425);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasmParser::T__7: {
        setState(415);
        match(qasmParser::T__7);
        setState(416);
        match(qasmParser::Identifier);
        setState(418);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasmParser::LBRACKET) {
          setState(417);
          designator();
        }
        break;
      }

      case qasmParser::T__6: {
        setState(420);
        match(qasmParser::T__6);
        setState(422);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasmParser::LBRACKET) {
          setState(421);
          designator();
        }
        setState(424);
        match(qasmParser::Identifier);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(428);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasmParser::EQUALS) {
      setState(427);
      equalsExpression();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ComplexDeclarationContext ------------------------------------------------------------------

qasmParser::ComplexDeclarationContext::ComplexDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasmParser::ComplexDeclarationContext::COMPLEX() {
  return getToken(qasmParser::COMPLEX, 0);
}

tree::TerminalNode* qasmParser::ComplexDeclarationContext::LBRACKET() {
  return getToken(qasmParser::LBRACKET, 0);
}

qasmParser::NumericTypeContext* qasmParser::ComplexDeclarationContext::numericType() {
  return getRuleContext<qasmParser::NumericTypeContext>(0);
}

tree::TerminalNode* qasmParser::ComplexDeclarationContext::RBRACKET() {
  return getToken(qasmParser::RBRACKET, 0);
}

tree::TerminalNode* qasmParser::ComplexDeclarationContext::Identifier() {
  return getToken(qasmParser::Identifier, 0);
}

qasmParser::EqualsExpressionContext* qasmParser::ComplexDeclarationContext::equalsExpression() {
  return getRuleContext<qasmParser::EqualsExpressionContext>(0);
}


size_t qasmParser::ComplexDeclarationContext::getRuleIndex() const {
  return qasmParser::RuleComplexDeclaration;
}

void qasmParser::ComplexDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComplexDeclaration(this);
}

void qasmParser::ComplexDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComplexDeclaration(this);
}


antlrcpp::Any qasmParser::ComplexDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitComplexDeclaration(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::ComplexDeclarationContext* qasmParser::complexDeclaration() {
  ComplexDeclarationContext *_localctx = _tracker.createInstance<ComplexDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 62, qasmParser::RuleComplexDeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(430);
    match(qasmParser::COMPLEX);
    setState(431);
    match(qasmParser::LBRACKET);
    setState(432);
    numericType();
    setState(433);
    match(qasmParser::RBRACKET);
    setState(434);
    match(qasmParser::Identifier);
    setState(436);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasmParser::EQUALS) {
      setState(435);
      equalsExpression();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayInitializerContext ------------------------------------------------------------------

qasmParser::ArrayInitializerContext::ArrayInitializerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasmParser::ArrayInitializerContext::LBRACE() {
  return getToken(qasmParser::LBRACE, 0);
}

tree::TerminalNode* qasmParser::ArrayInitializerContext::RBRACE() {
  return getToken(qasmParser::RBRACE, 0);
}

std::vector<qasmParser::ExpressionContext *> qasmParser::ArrayInitializerContext::expression() {
  return getRuleContexts<qasmParser::ExpressionContext>();
}

qasmParser::ExpressionContext* qasmParser::ArrayInitializerContext::expression(size_t i) {
  return getRuleContext<qasmParser::ExpressionContext>(i);
}

std::vector<qasmParser::ArrayInitializerContext *> qasmParser::ArrayInitializerContext::arrayInitializer() {
  return getRuleContexts<qasmParser::ArrayInitializerContext>();
}

qasmParser::ArrayInitializerContext* qasmParser::ArrayInitializerContext::arrayInitializer(size_t i) {
  return getRuleContext<qasmParser::ArrayInitializerContext>(i);
}

std::vector<tree::TerminalNode *> qasmParser::ArrayInitializerContext::COMMA() {
  return getTokens(qasmParser::COMMA);
}

tree::TerminalNode* qasmParser::ArrayInitializerContext::COMMA(size_t i) {
  return getToken(qasmParser::COMMA, i);
}


size_t qasmParser::ArrayInitializerContext::getRuleIndex() const {
  return qasmParser::RuleArrayInitializer;
}

void qasmParser::ArrayInitializerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayInitializer(this);
}

void qasmParser::ArrayInitializerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayInitializer(this);
}


antlrcpp::Any qasmParser::ArrayInitializerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitArrayInitializer(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::ArrayInitializerContext* qasmParser::arrayInitializer() {
  ArrayInitializerContext *_localctx = _tracker.createInstance<ArrayInitializerContext>(_ctx, getState());
  enterRule(_localctx, 64, qasmParser::RuleArrayInitializer);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(438);
    match(qasmParser::LBRACE);

    setState(441);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasmParser::T__6:
      case qasmParser::T__7:
      case qasmParser::T__8:
      case qasmParser::T__9:
      case qasmParser::T__10:
      case qasmParser::T__11:
      case qasmParser::T__12:
      case qasmParser::T__27:
      case qasmParser::T__28:
      case qasmParser::T__43:
      case qasmParser::T__44:
      case qasmParser::T__45:
      case qasmParser::T__46:
      case qasmParser::T__47:
      case qasmParser::T__48:
      case qasmParser::T__49:
      case qasmParser::T__50:
      case qasmParser::T__51:
      case qasmParser::T__52:
      case qasmParser::T__53:
      case qasmParser::T__54:
      case qasmParser::T__55:
      case qasmParser::T__56:
      case qasmParser::T__81:
      case qasmParser::T__82:
      case qasmParser::T__84:
      case qasmParser::LPAREN:
      case qasmParser::MINUS:
      case qasmParser::ImagNumber:
      case qasmParser::COMPLEX:
      case qasmParser::ARRAY:
      case qasmParser::SIZEOF:
      case qasmParser::Constant:
      case qasmParser::Integer:
      case qasmParser::Identifier:
      case qasmParser::RealNumber:
      case qasmParser::TimingLiteral:
      case qasmParser::StringLiteral: {
        setState(439);
        expression(0);
        break;
      }

      case qasmParser::LBRACE: {
        setState(440);
        arrayInitializer();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(450);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == qasmParser::COMMA) {
      setState(443);
      match(qasmParser::COMMA);
      setState(446);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case qasmParser::T__6:
        case qasmParser::T__7:
        case qasmParser::T__8:
        case qasmParser::T__9:
        case qasmParser::T__10:
        case qasmParser::T__11:
        case qasmParser::T__12:
        case qasmParser::T__27:
        case qasmParser::T__28:
        case qasmParser::T__43:
        case qasmParser::T__44:
        case qasmParser::T__45:
        case qasmParser::T__46:
        case qasmParser::T__47:
        case qasmParser::T__48:
        case qasmParser::T__49:
        case qasmParser::T__50:
        case qasmParser::T__51:
        case qasmParser::T__52:
        case qasmParser::T__53:
        case qasmParser::T__54:
        case qasmParser::T__55:
        case qasmParser::T__56:
        case qasmParser::T__81:
        case qasmParser::T__82:
        case qasmParser::T__84:
        case qasmParser::LPAREN:
        case qasmParser::MINUS:
        case qasmParser::ImagNumber:
        case qasmParser::COMPLEX:
        case qasmParser::ARRAY:
        case qasmParser::SIZEOF:
        case qasmParser::Constant:
        case qasmParser::Integer:
        case qasmParser::Identifier:
        case qasmParser::RealNumber:
        case qasmParser::TimingLiteral:
        case qasmParser::StringLiteral: {
          setState(444);
          expression(0);
          break;
        }

        case qasmParser::LBRACE: {
          setState(445);
          arrayInitializer();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(452);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(453);
    match(qasmParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayDeclarationContext ------------------------------------------------------------------

qasmParser::ArrayDeclarationContext::ArrayDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::ArrayTypeContext* qasmParser::ArrayDeclarationContext::arrayType() {
  return getRuleContext<qasmParser::ArrayTypeContext>(0);
}

tree::TerminalNode* qasmParser::ArrayDeclarationContext::Identifier() {
  return getToken(qasmParser::Identifier, 0);
}

tree::TerminalNode* qasmParser::ArrayDeclarationContext::EQUALS() {
  return getToken(qasmParser::EQUALS, 0);
}

qasmParser::ArrayInitializerContext* qasmParser::ArrayDeclarationContext::arrayInitializer() {
  return getRuleContext<qasmParser::ArrayInitializerContext>(0);
}

qasmParser::ExpressionContext* qasmParser::ArrayDeclarationContext::expression() {
  return getRuleContext<qasmParser::ExpressionContext>(0);
}


size_t qasmParser::ArrayDeclarationContext::getRuleIndex() const {
  return qasmParser::RuleArrayDeclaration;
}

void qasmParser::ArrayDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayDeclaration(this);
}

void qasmParser::ArrayDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayDeclaration(this);
}


antlrcpp::Any qasmParser::ArrayDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitArrayDeclaration(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::ArrayDeclarationContext* qasmParser::arrayDeclaration() {
  ArrayDeclarationContext *_localctx = _tracker.createInstance<ArrayDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 66, qasmParser::RuleArrayDeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(455);
    arrayType();
    setState(456);
    match(qasmParser::Identifier);
    setState(462);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasmParser::EQUALS) {
      setState(457);
      match(qasmParser::EQUALS);
      setState(460);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case qasmParser::LBRACE: {
          setState(458);
          arrayInitializer();
          break;
        }

        case qasmParser::T__6:
        case qasmParser::T__7:
        case qasmParser::T__8:
        case qasmParser::T__9:
        case qasmParser::T__10:
        case qasmParser::T__11:
        case qasmParser::T__12:
        case qasmParser::T__27:
        case qasmParser::T__28:
        case qasmParser::T__43:
        case qasmParser::T__44:
        case qasmParser::T__45:
        case qasmParser::T__46:
        case qasmParser::T__47:
        case qasmParser::T__48:
        case qasmParser::T__49:
        case qasmParser::T__50:
        case qasmParser::T__51:
        case qasmParser::T__52:
        case qasmParser::T__53:
        case qasmParser::T__54:
        case qasmParser::T__55:
        case qasmParser::T__56:
        case qasmParser::T__81:
        case qasmParser::T__82:
        case qasmParser::T__84:
        case qasmParser::LPAREN:
        case qasmParser::MINUS:
        case qasmParser::ImagNumber:
        case qasmParser::COMPLEX:
        case qasmParser::ARRAY:
        case qasmParser::SIZEOF:
        case qasmParser::Constant:
        case qasmParser::Integer:
        case qasmParser::Identifier:
        case qasmParser::RealNumber:
        case qasmParser::TimingLiteral:
        case qasmParser::StringLiteral: {
          setState(459);
          expression(0);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassicalDeclarationContext ------------------------------------------------------------------

qasmParser::ClassicalDeclarationContext::ClassicalDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::SingleDesignatorDeclarationContext* qasmParser::ClassicalDeclarationContext::singleDesignatorDeclaration() {
  return getRuleContext<qasmParser::SingleDesignatorDeclarationContext>(0);
}

qasmParser::NoDesignatorDeclarationContext* qasmParser::ClassicalDeclarationContext::noDesignatorDeclaration() {
  return getRuleContext<qasmParser::NoDesignatorDeclarationContext>(0);
}

qasmParser::BitDeclarationContext* qasmParser::ClassicalDeclarationContext::bitDeclaration() {
  return getRuleContext<qasmParser::BitDeclarationContext>(0);
}

qasmParser::ComplexDeclarationContext* qasmParser::ClassicalDeclarationContext::complexDeclaration() {
  return getRuleContext<qasmParser::ComplexDeclarationContext>(0);
}

qasmParser::ArrayDeclarationContext* qasmParser::ClassicalDeclarationContext::arrayDeclaration() {
  return getRuleContext<qasmParser::ArrayDeclarationContext>(0);
}


size_t qasmParser::ClassicalDeclarationContext::getRuleIndex() const {
  return qasmParser::RuleClassicalDeclaration;
}

void qasmParser::ClassicalDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassicalDeclaration(this);
}

void qasmParser::ClassicalDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassicalDeclaration(this);
}


antlrcpp::Any qasmParser::ClassicalDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitClassicalDeclaration(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::ClassicalDeclarationContext* qasmParser::classicalDeclaration() {
  ClassicalDeclarationContext *_localctx = _tracker.createInstance<ClassicalDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 68, qasmParser::RuleClassicalDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(469);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasmParser::T__8:
      case qasmParser::T__9:
      case qasmParser::T__10:
      case qasmParser::T__11: {
        enterOuterAlt(_localctx, 1);
        setState(464);
        singleDesignatorDeclaration();
        break;
      }

      case qasmParser::T__12:
      case qasmParser::T__81:
      case qasmParser::T__82: {
        enterOuterAlt(_localctx, 2);
        setState(465);
        noDesignatorDeclaration();
        break;
      }

      case qasmParser::T__6:
      case qasmParser::T__7: {
        enterOuterAlt(_localctx, 3);
        setState(466);
        bitDeclaration();
        break;
      }

      case qasmParser::COMPLEX: {
        enterOuterAlt(_localctx, 4);
        setState(467);
        complexDeclaration();
        break;
      }

      case qasmParser::ARRAY: {
        enterOuterAlt(_localctx, 5);
        setState(468);
        arrayDeclaration();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassicalTypeListContext ------------------------------------------------------------------

qasmParser::ClassicalTypeListContext::ClassicalTypeListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<qasmParser::ClassicalTypeContext *> qasmParser::ClassicalTypeListContext::classicalType() {
  return getRuleContexts<qasmParser::ClassicalTypeContext>();
}

qasmParser::ClassicalTypeContext* qasmParser::ClassicalTypeListContext::classicalType(size_t i) {
  return getRuleContext<qasmParser::ClassicalTypeContext>(i);
}

std::vector<tree::TerminalNode *> qasmParser::ClassicalTypeListContext::COMMA() {
  return getTokens(qasmParser::COMMA);
}

tree::TerminalNode* qasmParser::ClassicalTypeListContext::COMMA(size_t i) {
  return getToken(qasmParser::COMMA, i);
}


size_t qasmParser::ClassicalTypeListContext::getRuleIndex() const {
  return qasmParser::RuleClassicalTypeList;
}

void qasmParser::ClassicalTypeListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassicalTypeList(this);
}

void qasmParser::ClassicalTypeListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassicalTypeList(this);
}


antlrcpp::Any qasmParser::ClassicalTypeListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitClassicalTypeList(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::ClassicalTypeListContext* qasmParser::classicalTypeList() {
  ClassicalTypeListContext *_localctx = _tracker.createInstance<ClassicalTypeListContext>(_ctx, getState());
  enterRule(_localctx, 70, qasmParser::RuleClassicalTypeList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(476);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(471);
        classicalType();
        setState(472);
        match(qasmParser::COMMA); 
      }
      setState(478);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
    }
    setState(479);
    classicalType();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassicalArgumentContext ------------------------------------------------------------------

qasmParser::ClassicalArgumentContext::ClassicalArgumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasmParser::ClassicalArgumentContext::Identifier() {
  return getToken(qasmParser::Identifier, 0);
}

qasmParser::SingleDesignatorTypeContext* qasmParser::ClassicalArgumentContext::singleDesignatorType() {
  return getRuleContext<qasmParser::SingleDesignatorTypeContext>(0);
}

qasmParser::DesignatorContext* qasmParser::ClassicalArgumentContext::designator() {
  return getRuleContext<qasmParser::DesignatorContext>(0);
}

qasmParser::NoDesignatorTypeContext* qasmParser::ClassicalArgumentContext::noDesignatorType() {
  return getRuleContext<qasmParser::NoDesignatorTypeContext>(0);
}

tree::TerminalNode* qasmParser::ClassicalArgumentContext::COMPLEX() {
  return getToken(qasmParser::COMPLEX, 0);
}

tree::TerminalNode* qasmParser::ClassicalArgumentContext::LBRACKET() {
  return getToken(qasmParser::LBRACKET, 0);
}

qasmParser::NumericTypeContext* qasmParser::ClassicalArgumentContext::numericType() {
  return getRuleContext<qasmParser::NumericTypeContext>(0);
}

tree::TerminalNode* qasmParser::ClassicalArgumentContext::RBRACKET() {
  return getToken(qasmParser::RBRACKET, 0);
}

qasmParser::ArrayReferenceTypeContext* qasmParser::ClassicalArgumentContext::arrayReferenceType() {
  return getRuleContext<qasmParser::ArrayReferenceTypeContext>(0);
}

tree::TerminalNode* qasmParser::ClassicalArgumentContext::CONST() {
  return getToken(qasmParser::CONST, 0);
}

tree::TerminalNode* qasmParser::ClassicalArgumentContext::MUTABLE() {
  return getToken(qasmParser::MUTABLE, 0);
}


size_t qasmParser::ClassicalArgumentContext::getRuleIndex() const {
  return qasmParser::RuleClassicalArgument;
}

void qasmParser::ClassicalArgumentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassicalArgument(this);
}

void qasmParser::ClassicalArgumentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassicalArgument(this);
}


antlrcpp::Any qasmParser::ClassicalArgumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitClassicalArgument(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::ClassicalArgumentContext* qasmParser::classicalArgument() {
  ClassicalArgumentContext *_localctx = _tracker.createInstance<ClassicalArgumentContext>(_ctx, getState());
  enterRule(_localctx, 72, qasmParser::RuleClassicalArgument);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(509);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasmParser::T__8:
      case qasmParser::T__9:
      case qasmParser::T__10:
      case qasmParser::T__11:
      case qasmParser::T__12:
      case qasmParser::T__81:
      case qasmParser::T__82: {
        enterOuterAlt(_localctx, 1);
        setState(485);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case qasmParser::T__8:
          case qasmParser::T__9:
          case qasmParser::T__10:
          case qasmParser::T__11: {
            setState(481);
            singleDesignatorType();
            setState(482);
            designator();
            break;
          }

          case qasmParser::T__12:
          case qasmParser::T__81:
          case qasmParser::T__82: {
            setState(484);
            noDesignatorType();
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(487);
        match(qasmParser::Identifier);
        break;
      }

      case qasmParser::T__7: {
        enterOuterAlt(_localctx, 2);
        setState(489);
        match(qasmParser::T__7);
        setState(490);
        match(qasmParser::Identifier);
        setState(492);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasmParser::LBRACKET) {
          setState(491);
          designator();
        }
        break;
      }

      case qasmParser::T__6: {
        enterOuterAlt(_localctx, 3);
        setState(494);
        match(qasmParser::T__6);
        setState(496);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasmParser::LBRACKET) {
          setState(495);
          designator();
        }
        setState(498);
        match(qasmParser::Identifier);
        break;
      }

      case qasmParser::COMPLEX: {
        enterOuterAlt(_localctx, 4);
        setState(499);
        match(qasmParser::COMPLEX);
        setState(500);
        match(qasmParser::LBRACKET);
        setState(501);
        numericType();
        setState(502);
        match(qasmParser::RBRACKET);
        setState(503);
        match(qasmParser::Identifier);
        break;
      }

      case qasmParser::CONST:
      case qasmParser::MUTABLE: {
        enterOuterAlt(_localctx, 5);
        setState(505);
        _la = _input->LA(1);
        if (!(_la == qasmParser::CONST

        || _la == qasmParser::MUTABLE)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(506);
        arrayReferenceType();
        setState(507);
        match(qasmParser::Identifier);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassicalArgumentListContext ------------------------------------------------------------------

qasmParser::ClassicalArgumentListContext::ClassicalArgumentListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<qasmParser::ClassicalArgumentContext *> qasmParser::ClassicalArgumentListContext::classicalArgument() {
  return getRuleContexts<qasmParser::ClassicalArgumentContext>();
}

qasmParser::ClassicalArgumentContext* qasmParser::ClassicalArgumentListContext::classicalArgument(size_t i) {
  return getRuleContext<qasmParser::ClassicalArgumentContext>(i);
}

std::vector<tree::TerminalNode *> qasmParser::ClassicalArgumentListContext::COMMA() {
  return getTokens(qasmParser::COMMA);
}

tree::TerminalNode* qasmParser::ClassicalArgumentListContext::COMMA(size_t i) {
  return getToken(qasmParser::COMMA, i);
}


size_t qasmParser::ClassicalArgumentListContext::getRuleIndex() const {
  return qasmParser::RuleClassicalArgumentList;
}

void qasmParser::ClassicalArgumentListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassicalArgumentList(this);
}

void qasmParser::ClassicalArgumentListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassicalArgumentList(this);
}


antlrcpp::Any qasmParser::ClassicalArgumentListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitClassicalArgumentList(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::ClassicalArgumentListContext* qasmParser::classicalArgumentList() {
  ClassicalArgumentListContext *_localctx = _tracker.createInstance<ClassicalArgumentListContext>(_ctx, getState());
  enterRule(_localctx, 74, qasmParser::RuleClassicalArgumentList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(511);
    classicalArgument();
    setState(516);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == qasmParser::COMMA) {
      setState(512);
      match(qasmParser::COMMA);
      setState(513);
      classicalArgument();
      setState(518);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AnyTypeArgumentContext ------------------------------------------------------------------

qasmParser::AnyTypeArgumentContext::AnyTypeArgumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::ClassicalArgumentContext* qasmParser::AnyTypeArgumentContext::classicalArgument() {
  return getRuleContext<qasmParser::ClassicalArgumentContext>(0);
}

qasmParser::QuantumArgumentContext* qasmParser::AnyTypeArgumentContext::quantumArgument() {
  return getRuleContext<qasmParser::QuantumArgumentContext>(0);
}


size_t qasmParser::AnyTypeArgumentContext::getRuleIndex() const {
  return qasmParser::RuleAnyTypeArgument;
}

void qasmParser::AnyTypeArgumentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAnyTypeArgument(this);
}

void qasmParser::AnyTypeArgumentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAnyTypeArgument(this);
}


antlrcpp::Any qasmParser::AnyTypeArgumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitAnyTypeArgument(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::AnyTypeArgumentContext* qasmParser::anyTypeArgument() {
  AnyTypeArgumentContext *_localctx = _tracker.createInstance<AnyTypeArgumentContext>(_ctx, getState());
  enterRule(_localctx, 76, qasmParser::RuleAnyTypeArgument);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(521);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasmParser::T__6:
      case qasmParser::T__7:
      case qasmParser::T__8:
      case qasmParser::T__9:
      case qasmParser::T__10:
      case qasmParser::T__11:
      case qasmParser::T__12:
      case qasmParser::T__81:
      case qasmParser::T__82:
      case qasmParser::COMPLEX:
      case qasmParser::CONST:
      case qasmParser::MUTABLE: {
        enterOuterAlt(_localctx, 1);
        setState(519);
        classicalArgument();
        break;
      }

      case qasmParser::T__4:
      case qasmParser::T__5: {
        enterOuterAlt(_localctx, 2);
        setState(520);
        quantumArgument();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AnyTypeArgumentListContext ------------------------------------------------------------------

qasmParser::AnyTypeArgumentListContext::AnyTypeArgumentListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<qasmParser::AnyTypeArgumentContext *> qasmParser::AnyTypeArgumentListContext::anyTypeArgument() {
  return getRuleContexts<qasmParser::AnyTypeArgumentContext>();
}

qasmParser::AnyTypeArgumentContext* qasmParser::AnyTypeArgumentListContext::anyTypeArgument(size_t i) {
  return getRuleContext<qasmParser::AnyTypeArgumentContext>(i);
}

std::vector<tree::TerminalNode *> qasmParser::AnyTypeArgumentListContext::COMMA() {
  return getTokens(qasmParser::COMMA);
}

tree::TerminalNode* qasmParser::AnyTypeArgumentListContext::COMMA(size_t i) {
  return getToken(qasmParser::COMMA, i);
}


size_t qasmParser::AnyTypeArgumentListContext::getRuleIndex() const {
  return qasmParser::RuleAnyTypeArgumentList;
}

void qasmParser::AnyTypeArgumentListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAnyTypeArgumentList(this);
}

void qasmParser::AnyTypeArgumentListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAnyTypeArgumentList(this);
}


antlrcpp::Any qasmParser::AnyTypeArgumentListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitAnyTypeArgumentList(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::AnyTypeArgumentListContext* qasmParser::anyTypeArgumentList() {
  AnyTypeArgumentListContext *_localctx = _tracker.createInstance<AnyTypeArgumentListContext>(_ctx, getState());
  enterRule(_localctx, 78, qasmParser::RuleAnyTypeArgumentList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(528);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(523);
        anyTypeArgument();
        setState(524);
        match(qasmParser::COMMA); 
      }
      setState(530);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx);
    }
    setState(531);
    anyTypeArgument();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AliasStatementContext ------------------------------------------------------------------

qasmParser::AliasStatementContext::AliasStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasmParser::AliasStatementContext::Identifier() {
  return getToken(qasmParser::Identifier, 0);
}

tree::TerminalNode* qasmParser::AliasStatementContext::EQUALS() {
  return getToken(qasmParser::EQUALS, 0);
}

qasmParser::AliasInitializerContext* qasmParser::AliasStatementContext::aliasInitializer() {
  return getRuleContext<qasmParser::AliasInitializerContext>(0);
}

tree::TerminalNode* qasmParser::AliasStatementContext::SEMICOLON() {
  return getToken(qasmParser::SEMICOLON, 0);
}


size_t qasmParser::AliasStatementContext::getRuleIndex() const {
  return qasmParser::RuleAliasStatement;
}

void qasmParser::AliasStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAliasStatement(this);
}

void qasmParser::AliasStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAliasStatement(this);
}


antlrcpp::Any qasmParser::AliasStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitAliasStatement(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::AliasStatementContext* qasmParser::aliasStatement() {
  AliasStatementContext *_localctx = _tracker.createInstance<AliasStatementContext>(_ctx, getState());
  enterRule(_localctx, 80, qasmParser::RuleAliasStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(533);
    match(qasmParser::T__13);
    setState(534);
    match(qasmParser::Identifier);
    setState(535);
    match(qasmParser::EQUALS);
    setState(536);
    aliasInitializer(0);
    setState(537);
    match(qasmParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AliasInitializerContext ------------------------------------------------------------------

qasmParser::AliasInitializerContext::AliasInitializerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::ExpressionContext* qasmParser::AliasInitializerContext::expression() {
  return getRuleContext<qasmParser::ExpressionContext>(0);
}

std::vector<qasmParser::AliasInitializerContext *> qasmParser::AliasInitializerContext::aliasInitializer() {
  return getRuleContexts<qasmParser::AliasInitializerContext>();
}

qasmParser::AliasInitializerContext* qasmParser::AliasInitializerContext::aliasInitializer(size_t i) {
  return getRuleContext<qasmParser::AliasInitializerContext>(i);
}


size_t qasmParser::AliasInitializerContext::getRuleIndex() const {
  return qasmParser::RuleAliasInitializer;
}

void qasmParser::AliasInitializerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAliasInitializer(this);
}

void qasmParser::AliasInitializerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAliasInitializer(this);
}


antlrcpp::Any qasmParser::AliasInitializerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitAliasInitializer(this);
  else
    return visitor->visitChildren(this);
}


qasmParser::AliasInitializerContext* qasmParser::aliasInitializer() {
   return aliasInitializer(0);
}

qasmParser::AliasInitializerContext* qasmParser::aliasInitializer(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  qasmParser::AliasInitializerContext *_localctx = _tracker.createInstance<AliasInitializerContext>(_ctx, parentState);
  qasmParser::AliasInitializerContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 82;
  enterRecursionRule(_localctx, 82, qasmParser::RuleAliasInitializer, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(540);
    expression(0);
    _ctx->stop = _input->LT(-1);
    setState(547);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<AliasInitializerContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleAliasInitializer);
        setState(542);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(543);
        match(qasmParser::T__14);
        setState(544);
        aliasInitializer(2); 
      }
      setState(549);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- RangeDefinitionContext ------------------------------------------------------------------

qasmParser::RangeDefinitionContext::RangeDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> qasmParser::RangeDefinitionContext::COLON() {
  return getTokens(qasmParser::COLON);
}

tree::TerminalNode* qasmParser::RangeDefinitionContext::COLON(size_t i) {
  return getToken(qasmParser::COLON, i);
}

std::vector<qasmParser::ExpressionContext *> qasmParser::RangeDefinitionContext::expression() {
  return getRuleContexts<qasmParser::ExpressionContext>();
}

qasmParser::ExpressionContext* qasmParser::RangeDefinitionContext::expression(size_t i) {
  return getRuleContext<qasmParser::ExpressionContext>(i);
}


size_t qasmParser::RangeDefinitionContext::getRuleIndex() const {
  return qasmParser::RuleRangeDefinition;
}

void qasmParser::RangeDefinitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRangeDefinition(this);
}

void qasmParser::RangeDefinitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRangeDefinition(this);
}


antlrcpp::Any qasmParser::RangeDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitRangeDefinition(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::RangeDefinitionContext* qasmParser::rangeDefinition() {
  RangeDefinitionContext *_localctx = _tracker.createInstance<RangeDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 84, qasmParser::RuleRangeDefinition);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(551);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasmParser::T__6)
      | (1ULL << qasmParser::T__7)
      | (1ULL << qasmParser::T__8)
      | (1ULL << qasmParser::T__9)
      | (1ULL << qasmParser::T__10)
      | (1ULL << qasmParser::T__11)
      | (1ULL << qasmParser::T__12)
      | (1ULL << qasmParser::T__27)
      | (1ULL << qasmParser::T__28)
      | (1ULL << qasmParser::T__43)
      | (1ULL << qasmParser::T__44)
      | (1ULL << qasmParser::T__45)
      | (1ULL << qasmParser::T__46)
      | (1ULL << qasmParser::T__47)
      | (1ULL << qasmParser::T__48)
      | (1ULL << qasmParser::T__49)
      | (1ULL << qasmParser::T__50)
      | (1ULL << qasmParser::T__51)
      | (1ULL << qasmParser::T__52)
      | (1ULL << qasmParser::T__53)
      | (1ULL << qasmParser::T__54)
      | (1ULL << qasmParser::T__55)
      | (1ULL << qasmParser::T__56))) != 0) || ((((_la - 82) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 82)) & ((1ULL << (qasmParser::T__81 - 82))
      | (1ULL << (qasmParser::T__82 - 82))
      | (1ULL << (qasmParser::T__84 - 82))
      | (1ULL << (qasmParser::LPAREN - 82))
      | (1ULL << (qasmParser::MINUS - 82))
      | (1ULL << (qasmParser::ImagNumber - 82))
      | (1ULL << (qasmParser::COMPLEX - 82))
      | (1ULL << (qasmParser::ARRAY - 82))
      | (1ULL << (qasmParser::SIZEOF - 82))
      | (1ULL << (qasmParser::Constant - 82))
      | (1ULL << (qasmParser::Integer - 82))
      | (1ULL << (qasmParser::Identifier - 82))
      | (1ULL << (qasmParser::RealNumber - 82))
      | (1ULL << (qasmParser::TimingLiteral - 82))
      | (1ULL << (qasmParser::StringLiteral - 82)))) != 0)) {
      setState(550);
      expression(0);
    }
    setState(553);
    match(qasmParser::COLON);
    setState(555);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasmParser::T__6)
      | (1ULL << qasmParser::T__7)
      | (1ULL << qasmParser::T__8)
      | (1ULL << qasmParser::T__9)
      | (1ULL << qasmParser::T__10)
      | (1ULL << qasmParser::T__11)
      | (1ULL << qasmParser::T__12)
      | (1ULL << qasmParser::T__27)
      | (1ULL << qasmParser::T__28)
      | (1ULL << qasmParser::T__43)
      | (1ULL << qasmParser::T__44)
      | (1ULL << qasmParser::T__45)
      | (1ULL << qasmParser::T__46)
      | (1ULL << qasmParser::T__47)
      | (1ULL << qasmParser::T__48)
      | (1ULL << qasmParser::T__49)
      | (1ULL << qasmParser::T__50)
      | (1ULL << qasmParser::T__51)
      | (1ULL << qasmParser::T__52)
      | (1ULL << qasmParser::T__53)
      | (1ULL << qasmParser::T__54)
      | (1ULL << qasmParser::T__55)
      | (1ULL << qasmParser::T__56))) != 0) || ((((_la - 82) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 82)) & ((1ULL << (qasmParser::T__81 - 82))
      | (1ULL << (qasmParser::T__82 - 82))
      | (1ULL << (qasmParser::T__84 - 82))
      | (1ULL << (qasmParser::LPAREN - 82))
      | (1ULL << (qasmParser::MINUS - 82))
      | (1ULL << (qasmParser::ImagNumber - 82))
      | (1ULL << (qasmParser::COMPLEX - 82))
      | (1ULL << (qasmParser::ARRAY - 82))
      | (1ULL << (qasmParser::SIZEOF - 82))
      | (1ULL << (qasmParser::Constant - 82))
      | (1ULL << (qasmParser::Integer - 82))
      | (1ULL << (qasmParser::Identifier - 82))
      | (1ULL << (qasmParser::RealNumber - 82))
      | (1ULL << (qasmParser::TimingLiteral - 82))
      | (1ULL << (qasmParser::StringLiteral - 82)))) != 0)) {
      setState(554);
      expression(0);
    }
    setState(559);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasmParser::COLON) {
      setState(557);
      match(qasmParser::COLON);
      setState(558);
      expression(0);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuantumGateDefinitionContext ------------------------------------------------------------------

qasmParser::QuantumGateDefinitionContext::QuantumGateDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::QuantumGateSignatureContext* qasmParser::QuantumGateDefinitionContext::quantumGateSignature() {
  return getRuleContext<qasmParser::QuantumGateSignatureContext>(0);
}

qasmParser::QuantumBlockContext* qasmParser::QuantumGateDefinitionContext::quantumBlock() {
  return getRuleContext<qasmParser::QuantumBlockContext>(0);
}


size_t qasmParser::QuantumGateDefinitionContext::getRuleIndex() const {
  return qasmParser::RuleQuantumGateDefinition;
}

void qasmParser::QuantumGateDefinitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQuantumGateDefinition(this);
}

void qasmParser::QuantumGateDefinitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQuantumGateDefinition(this);
}


antlrcpp::Any qasmParser::QuantumGateDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitQuantumGateDefinition(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::QuantumGateDefinitionContext* qasmParser::quantumGateDefinition() {
  QuantumGateDefinitionContext *_localctx = _tracker.createInstance<QuantumGateDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 86, qasmParser::RuleQuantumGateDefinition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(561);
    match(qasmParser::T__15);
    setState(562);
    quantumGateSignature();
    setState(563);
    quantumBlock();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuantumGateSignatureContext ------------------------------------------------------------------

qasmParser::QuantumGateSignatureContext::QuantumGateSignatureContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::QuantumGateNameContext* qasmParser::QuantumGateSignatureContext::quantumGateName() {
  return getRuleContext<qasmParser::QuantumGateNameContext>(0);
}

std::vector<qasmParser::IdentifierListContext *> qasmParser::QuantumGateSignatureContext::identifierList() {
  return getRuleContexts<qasmParser::IdentifierListContext>();
}

qasmParser::IdentifierListContext* qasmParser::QuantumGateSignatureContext::identifierList(size_t i) {
  return getRuleContext<qasmParser::IdentifierListContext>(i);
}

tree::TerminalNode* qasmParser::QuantumGateSignatureContext::LPAREN() {
  return getToken(qasmParser::LPAREN, 0);
}

tree::TerminalNode* qasmParser::QuantumGateSignatureContext::RPAREN() {
  return getToken(qasmParser::RPAREN, 0);
}


size_t qasmParser::QuantumGateSignatureContext::getRuleIndex() const {
  return qasmParser::RuleQuantumGateSignature;
}

void qasmParser::QuantumGateSignatureContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQuantumGateSignature(this);
}

void qasmParser::QuantumGateSignatureContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQuantumGateSignature(this);
}


antlrcpp::Any qasmParser::QuantumGateSignatureContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitQuantumGateSignature(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::QuantumGateSignatureContext* qasmParser::quantumGateSignature() {
  QuantumGateSignatureContext *_localctx = _tracker.createInstance<QuantumGateSignatureContext>(_ctx, getState());
  enterRule(_localctx, 88, qasmParser::RuleQuantumGateSignature);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(565);
    quantumGateName();
    setState(571);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasmParser::LPAREN) {
      setState(566);
      match(qasmParser::LPAREN);
      setState(568);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == qasmParser::Identifier) {
        setState(567);
        identifierList();
      }
      setState(570);
      match(qasmParser::RPAREN);
    }
    setState(573);
    identifierList();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuantumGateNameContext ------------------------------------------------------------------

qasmParser::QuantumGateNameContext::QuantumGateNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasmParser::QuantumGateNameContext::Identifier() {
  return getToken(qasmParser::Identifier, 0);
}


size_t qasmParser::QuantumGateNameContext::getRuleIndex() const {
  return qasmParser::RuleQuantumGateName;
}

void qasmParser::QuantumGateNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQuantumGateName(this);
}

void qasmParser::QuantumGateNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQuantumGateName(this);
}


antlrcpp::Any qasmParser::QuantumGateNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitQuantumGateName(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::QuantumGateNameContext* qasmParser::quantumGateName() {
  QuantumGateNameContext *_localctx = _tracker.createInstance<QuantumGateNameContext>(_ctx, getState());
  enterRule(_localctx, 90, qasmParser::RuleQuantumGateName);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(575);
    _la = _input->LA(1);
    if (!(_la == qasmParser::T__16

    || _la == qasmParser::T__17 || _la == qasmParser::Identifier)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuantumBlockContext ------------------------------------------------------------------

qasmParser::QuantumBlockContext::QuantumBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasmParser::QuantumBlockContext::LBRACE() {
  return getToken(qasmParser::LBRACE, 0);
}

tree::TerminalNode* qasmParser::QuantumBlockContext::RBRACE() {
  return getToken(qasmParser::RBRACE, 0);
}

std::vector<qasmParser::QuantumStatementContext *> qasmParser::QuantumBlockContext::quantumStatement() {
  return getRuleContexts<qasmParser::QuantumStatementContext>();
}

qasmParser::QuantumStatementContext* qasmParser::QuantumBlockContext::quantumStatement(size_t i) {
  return getRuleContext<qasmParser::QuantumStatementContext>(i);
}

std::vector<qasmParser::QuantumLoopContext *> qasmParser::QuantumBlockContext::quantumLoop() {
  return getRuleContexts<qasmParser::QuantumLoopContext>();
}

qasmParser::QuantumLoopContext* qasmParser::QuantumBlockContext::quantumLoop(size_t i) {
  return getRuleContext<qasmParser::QuantumLoopContext>(i);
}


size_t qasmParser::QuantumBlockContext::getRuleIndex() const {
  return qasmParser::RuleQuantumBlock;
}

void qasmParser::QuantumBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQuantumBlock(this);
}

void qasmParser::QuantumBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQuantumBlock(this);
}


antlrcpp::Any qasmParser::QuantumBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitQuantumBlock(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::QuantumBlockContext* qasmParser::quantumBlock() {
  QuantumBlockContext *_localctx = _tracker.createInstance<QuantumBlockContext>(_ctx, getState());
  enterRule(_localctx, 92, qasmParser::RuleQuantumBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(577);
    match(qasmParser::LBRACE);
    setState(582);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasmParser::T__16)
      | (1ULL << qasmParser::T__17)
      | (1ULL << qasmParser::T__18)
      | (1ULL << qasmParser::T__19)
      | (1ULL << qasmParser::T__20)
      | (1ULL << qasmParser::T__21)
      | (1ULL << qasmParser::T__22)
      | (1ULL << qasmParser::T__24)
      | (1ULL << qasmParser::T__25)
      | (1ULL << qasmParser::T__26))) != 0) || ((((_la - 72) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 72)) & ((1ULL << (qasmParser::T__71 - 72))
      | (1ULL << (qasmParser::T__73 - 72))
      | (1ULL << (qasmParser::T__83 - 72))
      | (1ULL << (qasmParser::T__85 - 72))
      | (1ULL << (qasmParser::T__86 - 72))
      | (1ULL << (qasmParser::Identifier - 72)))) != 0)) {
      setState(580);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case qasmParser::T__16:
        case qasmParser::T__17:
        case qasmParser::T__18:
        case qasmParser::T__19:
        case qasmParser::T__20:
        case qasmParser::T__21:
        case qasmParser::T__22:
        case qasmParser::T__24:
        case qasmParser::T__25:
        case qasmParser::T__26:
        case qasmParser::T__83:
        case qasmParser::T__85:
        case qasmParser::T__86:
        case qasmParser::Identifier: {
          setState(578);
          quantumStatement();
          break;
        }

        case qasmParser::T__71:
        case qasmParser::T__73: {
          setState(579);
          quantumLoop();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(584);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(585);
    match(qasmParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuantumLoopContext ------------------------------------------------------------------

qasmParser::QuantumLoopContext::QuantumLoopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::LoopSignatureContext* qasmParser::QuantumLoopContext::loopSignature() {
  return getRuleContext<qasmParser::LoopSignatureContext>(0);
}

qasmParser::QuantumLoopBlockContext* qasmParser::QuantumLoopContext::quantumLoopBlock() {
  return getRuleContext<qasmParser::QuantumLoopBlockContext>(0);
}


size_t qasmParser::QuantumLoopContext::getRuleIndex() const {
  return qasmParser::RuleQuantumLoop;
}

void qasmParser::QuantumLoopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQuantumLoop(this);
}

void qasmParser::QuantumLoopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQuantumLoop(this);
}


antlrcpp::Any qasmParser::QuantumLoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitQuantumLoop(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::QuantumLoopContext* qasmParser::quantumLoop() {
  QuantumLoopContext *_localctx = _tracker.createInstance<QuantumLoopContext>(_ctx, getState());
  enterRule(_localctx, 94, qasmParser::RuleQuantumLoop);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(587);
    loopSignature();
    setState(588);
    quantumLoopBlock();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuantumLoopBlockContext ------------------------------------------------------------------

qasmParser::QuantumLoopBlockContext::QuantumLoopBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<qasmParser::QuantumStatementContext *> qasmParser::QuantumLoopBlockContext::quantumStatement() {
  return getRuleContexts<qasmParser::QuantumStatementContext>();
}

qasmParser::QuantumStatementContext* qasmParser::QuantumLoopBlockContext::quantumStatement(size_t i) {
  return getRuleContext<qasmParser::QuantumStatementContext>(i);
}

tree::TerminalNode* qasmParser::QuantumLoopBlockContext::LBRACE() {
  return getToken(qasmParser::LBRACE, 0);
}

tree::TerminalNode* qasmParser::QuantumLoopBlockContext::RBRACE() {
  return getToken(qasmParser::RBRACE, 0);
}


size_t qasmParser::QuantumLoopBlockContext::getRuleIndex() const {
  return qasmParser::RuleQuantumLoopBlock;
}

void qasmParser::QuantumLoopBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQuantumLoopBlock(this);
}

void qasmParser::QuantumLoopBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQuantumLoopBlock(this);
}


antlrcpp::Any qasmParser::QuantumLoopBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitQuantumLoopBlock(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::QuantumLoopBlockContext* qasmParser::quantumLoopBlock() {
  QuantumLoopBlockContext *_localctx = _tracker.createInstance<QuantumLoopBlockContext>(_ctx, getState());
  enterRule(_localctx, 96, qasmParser::RuleQuantumLoopBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(599);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasmParser::T__16:
      case qasmParser::T__17:
      case qasmParser::T__18:
      case qasmParser::T__19:
      case qasmParser::T__20:
      case qasmParser::T__21:
      case qasmParser::T__22:
      case qasmParser::T__24:
      case qasmParser::T__25:
      case qasmParser::T__26:
      case qasmParser::T__83:
      case qasmParser::T__85:
      case qasmParser::T__86:
      case qasmParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(590);
        quantumStatement();
        break;
      }

      case qasmParser::LBRACE: {
        enterOuterAlt(_localctx, 2);
        setState(591);
        match(qasmParser::LBRACE);
        setState(595);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << qasmParser::T__16)
          | (1ULL << qasmParser::T__17)
          | (1ULL << qasmParser::T__18)
          | (1ULL << qasmParser::T__19)
          | (1ULL << qasmParser::T__20)
          | (1ULL << qasmParser::T__21)
          | (1ULL << qasmParser::T__22)
          | (1ULL << qasmParser::T__24)
          | (1ULL << qasmParser::T__25)
          | (1ULL << qasmParser::T__26))) != 0) || ((((_la - 84) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 84)) & ((1ULL << (qasmParser::T__83 - 84))
          | (1ULL << (qasmParser::T__85 - 84))
          | (1ULL << (qasmParser::T__86 - 84))
          | (1ULL << (qasmParser::Identifier - 84)))) != 0)) {
          setState(592);
          quantumStatement();
          setState(597);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(598);
        match(qasmParser::RBRACE);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuantumStatementContext ------------------------------------------------------------------

qasmParser::QuantumStatementContext::QuantumStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::QuantumInstructionContext* qasmParser::QuantumStatementContext::quantumInstruction() {
  return getRuleContext<qasmParser::QuantumInstructionContext>(0);
}

tree::TerminalNode* qasmParser::QuantumStatementContext::SEMICOLON() {
  return getToken(qasmParser::SEMICOLON, 0);
}

qasmParser::TimingStatementContext* qasmParser::QuantumStatementContext::timingStatement() {
  return getRuleContext<qasmParser::TimingStatementContext>(0);
}


size_t qasmParser::QuantumStatementContext::getRuleIndex() const {
  return qasmParser::RuleQuantumStatement;
}

void qasmParser::QuantumStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQuantumStatement(this);
}

void qasmParser::QuantumStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQuantumStatement(this);
}


antlrcpp::Any qasmParser::QuantumStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitQuantumStatement(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::QuantumStatementContext* qasmParser::quantumStatement() {
  QuantumStatementContext *_localctx = _tracker.createInstance<QuantumStatementContext>(_ctx, getState());
  enterRule(_localctx, 98, qasmParser::RuleQuantumStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(605);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasmParser::T__16:
      case qasmParser::T__17:
      case qasmParser::T__18:
      case qasmParser::T__19:
      case qasmParser::T__20:
      case qasmParser::T__21:
      case qasmParser::T__22:
      case qasmParser::T__24:
      case qasmParser::T__25:
      case qasmParser::T__26:
      case qasmParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(601);
        quantumInstruction();
        setState(602);
        match(qasmParser::SEMICOLON);
        break;
      }

      case qasmParser::T__83:
      case qasmParser::T__85:
      case qasmParser::T__86: {
        enterOuterAlt(_localctx, 2);
        setState(604);
        timingStatement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuantumInstructionContext ------------------------------------------------------------------

qasmParser::QuantumInstructionContext::QuantumInstructionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::QuantumGateCallContext* qasmParser::QuantumInstructionContext::quantumGateCall() {
  return getRuleContext<qasmParser::QuantumGateCallContext>(0);
}

qasmParser::QuantumPhaseContext* qasmParser::QuantumInstructionContext::quantumPhase() {
  return getRuleContext<qasmParser::QuantumPhaseContext>(0);
}

qasmParser::QuantumMeasurementContext* qasmParser::QuantumInstructionContext::quantumMeasurement() {
  return getRuleContext<qasmParser::QuantumMeasurementContext>(0);
}

qasmParser::QuantumResetContext* qasmParser::QuantumInstructionContext::quantumReset() {
  return getRuleContext<qasmParser::QuantumResetContext>(0);
}

qasmParser::QuantumBarrierContext* qasmParser::QuantumInstructionContext::quantumBarrier() {
  return getRuleContext<qasmParser::QuantumBarrierContext>(0);
}


size_t qasmParser::QuantumInstructionContext::getRuleIndex() const {
  return qasmParser::RuleQuantumInstruction;
}

void qasmParser::QuantumInstructionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQuantumInstruction(this);
}

void qasmParser::QuantumInstructionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQuantumInstruction(this);
}


antlrcpp::Any qasmParser::QuantumInstructionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitQuantumInstruction(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::QuantumInstructionContext* qasmParser::quantumInstruction() {
  QuantumInstructionContext *_localctx = _tracker.createInstance<QuantumInstructionContext>(_ctx, getState());
  enterRule(_localctx, 100, qasmParser::RuleQuantumInstruction);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(612);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(607);
      quantumGateCall();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(608);
      quantumPhase();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(609);
      quantumMeasurement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(610);
      quantumReset();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(611);
      quantumBarrier();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuantumPhaseContext ------------------------------------------------------------------

qasmParser::QuantumPhaseContext::QuantumPhaseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasmParser::QuantumPhaseContext::LPAREN() {
  return getToken(qasmParser::LPAREN, 0);
}

qasmParser::ExpressionContext* qasmParser::QuantumPhaseContext::expression() {
  return getRuleContext<qasmParser::ExpressionContext>(0);
}

tree::TerminalNode* qasmParser::QuantumPhaseContext::RPAREN() {
  return getToken(qasmParser::RPAREN, 0);
}

std::vector<qasmParser::QuantumGateModifierContext *> qasmParser::QuantumPhaseContext::quantumGateModifier() {
  return getRuleContexts<qasmParser::QuantumGateModifierContext>();
}

qasmParser::QuantumGateModifierContext* qasmParser::QuantumPhaseContext::quantumGateModifier(size_t i) {
  return getRuleContext<qasmParser::QuantumGateModifierContext>(i);
}

std::vector<qasmParser::IndexedIdentifierContext *> qasmParser::QuantumPhaseContext::indexedIdentifier() {
  return getRuleContexts<qasmParser::IndexedIdentifierContext>();
}

qasmParser::IndexedIdentifierContext* qasmParser::QuantumPhaseContext::indexedIdentifier(size_t i) {
  return getRuleContext<qasmParser::IndexedIdentifierContext>(i);
}

std::vector<tree::TerminalNode *> qasmParser::QuantumPhaseContext::COMMA() {
  return getTokens(qasmParser::COMMA);
}

tree::TerminalNode* qasmParser::QuantumPhaseContext::COMMA(size_t i) {
  return getToken(qasmParser::COMMA, i);
}


size_t qasmParser::QuantumPhaseContext::getRuleIndex() const {
  return qasmParser::RuleQuantumPhase;
}

void qasmParser::QuantumPhaseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQuantumPhase(this);
}

void qasmParser::QuantumPhaseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQuantumPhase(this);
}


antlrcpp::Any qasmParser::QuantumPhaseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitQuantumPhase(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::QuantumPhaseContext* qasmParser::quantumPhase() {
  QuantumPhaseContext *_localctx = _tracker.createInstance<QuantumPhaseContext>(_ctx, getState());
  enterRule(_localctx, 102, qasmParser::RuleQuantumPhase);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(617);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasmParser::T__22)
      | (1ULL << qasmParser::T__24)
      | (1ULL << qasmParser::T__25)
      | (1ULL << qasmParser::T__26))) != 0)) {
      setState(614);
      quantumGateModifier();
      setState(619);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(620);
    match(qasmParser::T__18);
    setState(621);
    match(qasmParser::LPAREN);
    setState(622);
    expression(0);
    setState(623);
    match(qasmParser::RPAREN);
    setState(632);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasmParser::Identifier) {
      setState(624);
      indexedIdentifier();
      setState(629);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == qasmParser::COMMA) {
        setState(625);
        match(qasmParser::COMMA);
        setState(626);
        indexedIdentifier();
        setState(631);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuantumResetContext ------------------------------------------------------------------

qasmParser::QuantumResetContext::QuantumResetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::IndexedIdentifierContext* qasmParser::QuantumResetContext::indexedIdentifier() {
  return getRuleContext<qasmParser::IndexedIdentifierContext>(0);
}


size_t qasmParser::QuantumResetContext::getRuleIndex() const {
  return qasmParser::RuleQuantumReset;
}

void qasmParser::QuantumResetContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQuantumReset(this);
}

void qasmParser::QuantumResetContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQuantumReset(this);
}


antlrcpp::Any qasmParser::QuantumResetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitQuantumReset(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::QuantumResetContext* qasmParser::quantumReset() {
  QuantumResetContext *_localctx = _tracker.createInstance<QuantumResetContext>(_ctx, getState());
  enterRule(_localctx, 104, qasmParser::RuleQuantumReset);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(634);
    match(qasmParser::T__19);
    setState(635);
    indexedIdentifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuantumMeasurementContext ------------------------------------------------------------------

qasmParser::QuantumMeasurementContext::QuantumMeasurementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::IndexedIdentifierContext* qasmParser::QuantumMeasurementContext::indexedIdentifier() {
  return getRuleContext<qasmParser::IndexedIdentifierContext>(0);
}


size_t qasmParser::QuantumMeasurementContext::getRuleIndex() const {
  return qasmParser::RuleQuantumMeasurement;
}

void qasmParser::QuantumMeasurementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQuantumMeasurement(this);
}

void qasmParser::QuantumMeasurementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQuantumMeasurement(this);
}


antlrcpp::Any qasmParser::QuantumMeasurementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitQuantumMeasurement(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::QuantumMeasurementContext* qasmParser::quantumMeasurement() {
  QuantumMeasurementContext *_localctx = _tracker.createInstance<QuantumMeasurementContext>(_ctx, getState());
  enterRule(_localctx, 106, qasmParser::RuleQuantumMeasurement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(637);
    match(qasmParser::T__20);
    setState(638);
    indexedIdentifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuantumMeasurementAssignmentContext ------------------------------------------------------------------

qasmParser::QuantumMeasurementAssignmentContext::QuantumMeasurementAssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::QuantumMeasurementContext* qasmParser::QuantumMeasurementAssignmentContext::quantumMeasurement() {
  return getRuleContext<qasmParser::QuantumMeasurementContext>(0);
}

tree::TerminalNode* qasmParser::QuantumMeasurementAssignmentContext::ARROW() {
  return getToken(qasmParser::ARROW, 0);
}

qasmParser::IndexedIdentifierContext* qasmParser::QuantumMeasurementAssignmentContext::indexedIdentifier() {
  return getRuleContext<qasmParser::IndexedIdentifierContext>(0);
}

tree::TerminalNode* qasmParser::QuantumMeasurementAssignmentContext::EQUALS() {
  return getToken(qasmParser::EQUALS, 0);
}


size_t qasmParser::QuantumMeasurementAssignmentContext::getRuleIndex() const {
  return qasmParser::RuleQuantumMeasurementAssignment;
}

void qasmParser::QuantumMeasurementAssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQuantumMeasurementAssignment(this);
}

void qasmParser::QuantumMeasurementAssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQuantumMeasurementAssignment(this);
}


antlrcpp::Any qasmParser::QuantumMeasurementAssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitQuantumMeasurementAssignment(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::QuantumMeasurementAssignmentContext* qasmParser::quantumMeasurementAssignment() {
  QuantumMeasurementAssignmentContext *_localctx = _tracker.createInstance<QuantumMeasurementAssignmentContext>(_ctx, getState());
  enterRule(_localctx, 108, qasmParser::RuleQuantumMeasurementAssignment);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(649);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasmParser::T__20: {
        enterOuterAlt(_localctx, 1);
        setState(640);
        quantumMeasurement();
        setState(643);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasmParser::ARROW) {
          setState(641);
          match(qasmParser::ARROW);
          setState(642);
          indexedIdentifier();
        }
        break;
      }

      case qasmParser::Identifier: {
        enterOuterAlt(_localctx, 2);
        setState(645);
        indexedIdentifier();
        setState(646);
        match(qasmParser::EQUALS);
        setState(647);
        quantumMeasurement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuantumBarrierContext ------------------------------------------------------------------

qasmParser::QuantumBarrierContext::QuantumBarrierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<qasmParser::IndexedIdentifierContext *> qasmParser::QuantumBarrierContext::indexedIdentifier() {
  return getRuleContexts<qasmParser::IndexedIdentifierContext>();
}

qasmParser::IndexedIdentifierContext* qasmParser::QuantumBarrierContext::indexedIdentifier(size_t i) {
  return getRuleContext<qasmParser::IndexedIdentifierContext>(i);
}

std::vector<tree::TerminalNode *> qasmParser::QuantumBarrierContext::COMMA() {
  return getTokens(qasmParser::COMMA);
}

tree::TerminalNode* qasmParser::QuantumBarrierContext::COMMA(size_t i) {
  return getToken(qasmParser::COMMA, i);
}


size_t qasmParser::QuantumBarrierContext::getRuleIndex() const {
  return qasmParser::RuleQuantumBarrier;
}

void qasmParser::QuantumBarrierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQuantumBarrier(this);
}

void qasmParser::QuantumBarrierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQuantumBarrier(this);
}


antlrcpp::Any qasmParser::QuantumBarrierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitQuantumBarrier(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::QuantumBarrierContext* qasmParser::quantumBarrier() {
  QuantumBarrierContext *_localctx = _tracker.createInstance<QuantumBarrierContext>(_ctx, getState());
  enterRule(_localctx, 110, qasmParser::RuleQuantumBarrier);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(651);
    match(qasmParser::T__21);
    setState(660);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasmParser::Identifier) {
      setState(652);
      indexedIdentifier();
      setState(657);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == qasmParser::COMMA) {
        setState(653);
        match(qasmParser::COMMA);
        setState(654);
        indexedIdentifier();
        setState(659);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuantumGateModifierContext ------------------------------------------------------------------

qasmParser::QuantumGateModifierContext::QuantumGateModifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::PowModifierContext* qasmParser::QuantumGateModifierContext::powModifier() {
  return getRuleContext<qasmParser::PowModifierContext>(0);
}

qasmParser::CtrlModifierContext* qasmParser::QuantumGateModifierContext::ctrlModifier() {
  return getRuleContext<qasmParser::CtrlModifierContext>(0);
}


size_t qasmParser::QuantumGateModifierContext::getRuleIndex() const {
  return qasmParser::RuleQuantumGateModifier;
}

void qasmParser::QuantumGateModifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQuantumGateModifier(this);
}

void qasmParser::QuantumGateModifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQuantumGateModifier(this);
}


antlrcpp::Any qasmParser::QuantumGateModifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitQuantumGateModifier(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::QuantumGateModifierContext* qasmParser::quantumGateModifier() {
  QuantumGateModifierContext *_localctx = _tracker.createInstance<QuantumGateModifierContext>(_ctx, getState());
  enterRule(_localctx, 112, qasmParser::RuleQuantumGateModifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(665);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasmParser::T__22: {
        setState(662);
        match(qasmParser::T__22);
        break;
      }

      case qasmParser::T__24: {
        setState(663);
        powModifier();
        break;
      }

      case qasmParser::T__25:
      case qasmParser::T__26: {
        setState(664);
        ctrlModifier();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(667);
    match(qasmParser::T__23);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PowModifierContext ------------------------------------------------------------------

qasmParser::PowModifierContext::PowModifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasmParser::PowModifierContext::LPAREN() {
  return getToken(qasmParser::LPAREN, 0);
}

qasmParser::ExpressionContext* qasmParser::PowModifierContext::expression() {
  return getRuleContext<qasmParser::ExpressionContext>(0);
}

tree::TerminalNode* qasmParser::PowModifierContext::RPAREN() {
  return getToken(qasmParser::RPAREN, 0);
}


size_t qasmParser::PowModifierContext::getRuleIndex() const {
  return qasmParser::RulePowModifier;
}

void qasmParser::PowModifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPowModifier(this);
}

void qasmParser::PowModifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPowModifier(this);
}


antlrcpp::Any qasmParser::PowModifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitPowModifier(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::PowModifierContext* qasmParser::powModifier() {
  PowModifierContext *_localctx = _tracker.createInstance<PowModifierContext>(_ctx, getState());
  enterRule(_localctx, 114, qasmParser::RulePowModifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(669);
    match(qasmParser::T__24);
    setState(670);
    match(qasmParser::LPAREN);
    setState(671);
    expression(0);
    setState(672);
    match(qasmParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CtrlModifierContext ------------------------------------------------------------------

qasmParser::CtrlModifierContext::CtrlModifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasmParser::CtrlModifierContext::LPAREN() {
  return getToken(qasmParser::LPAREN, 0);
}

qasmParser::ExpressionContext* qasmParser::CtrlModifierContext::expression() {
  return getRuleContext<qasmParser::ExpressionContext>(0);
}

tree::TerminalNode* qasmParser::CtrlModifierContext::RPAREN() {
  return getToken(qasmParser::RPAREN, 0);
}


size_t qasmParser::CtrlModifierContext::getRuleIndex() const {
  return qasmParser::RuleCtrlModifier;
}

void qasmParser::CtrlModifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCtrlModifier(this);
}

void qasmParser::CtrlModifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCtrlModifier(this);
}


antlrcpp::Any qasmParser::CtrlModifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitCtrlModifier(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::CtrlModifierContext* qasmParser::ctrlModifier() {
  CtrlModifierContext *_localctx = _tracker.createInstance<CtrlModifierContext>(_ctx, getState());
  enterRule(_localctx, 116, qasmParser::RuleCtrlModifier);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(674);
    _la = _input->LA(1);
    if (!(_la == qasmParser::T__25

    || _la == qasmParser::T__26)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(679);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasmParser::LPAREN) {
      setState(675);
      match(qasmParser::LPAREN);
      setState(676);
      expression(0);
      setState(677);
      match(qasmParser::RPAREN);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuantumGateCallContext ------------------------------------------------------------------

qasmParser::QuantumGateCallContext::QuantumGateCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::QuantumGateNameContext* qasmParser::QuantumGateCallContext::quantumGateName() {
  return getRuleContext<qasmParser::QuantumGateNameContext>(0);
}

std::vector<qasmParser::IndexedIdentifierContext *> qasmParser::QuantumGateCallContext::indexedIdentifier() {
  return getRuleContexts<qasmParser::IndexedIdentifierContext>();
}

qasmParser::IndexedIdentifierContext* qasmParser::QuantumGateCallContext::indexedIdentifier(size_t i) {
  return getRuleContext<qasmParser::IndexedIdentifierContext>(i);
}

std::vector<qasmParser::QuantumGateModifierContext *> qasmParser::QuantumGateCallContext::quantumGateModifier() {
  return getRuleContexts<qasmParser::QuantumGateModifierContext>();
}

qasmParser::QuantumGateModifierContext* qasmParser::QuantumGateCallContext::quantumGateModifier(size_t i) {
  return getRuleContext<qasmParser::QuantumGateModifierContext>(i);
}

tree::TerminalNode* qasmParser::QuantumGateCallContext::LPAREN() {
  return getToken(qasmParser::LPAREN, 0);
}

qasmParser::ExpressionListContext* qasmParser::QuantumGateCallContext::expressionList() {
  return getRuleContext<qasmParser::ExpressionListContext>(0);
}

tree::TerminalNode* qasmParser::QuantumGateCallContext::RPAREN() {
  return getToken(qasmParser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> qasmParser::QuantumGateCallContext::COMMA() {
  return getTokens(qasmParser::COMMA);
}

tree::TerminalNode* qasmParser::QuantumGateCallContext::COMMA(size_t i) {
  return getToken(qasmParser::COMMA, i);
}


size_t qasmParser::QuantumGateCallContext::getRuleIndex() const {
  return qasmParser::RuleQuantumGateCall;
}

void qasmParser::QuantumGateCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQuantumGateCall(this);
}

void qasmParser::QuantumGateCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQuantumGateCall(this);
}


antlrcpp::Any qasmParser::QuantumGateCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitQuantumGateCall(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::QuantumGateCallContext* qasmParser::quantumGateCall() {
  QuantumGateCallContext *_localctx = _tracker.createInstance<QuantumGateCallContext>(_ctx, getState());
  enterRule(_localctx, 118, qasmParser::RuleQuantumGateCall);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(684);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasmParser::T__22)
      | (1ULL << qasmParser::T__24)
      | (1ULL << qasmParser::T__25)
      | (1ULL << qasmParser::T__26))) != 0)) {
      setState(681);
      quantumGateModifier();
      setState(686);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(687);
    quantumGateName();
    setState(692);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasmParser::LPAREN) {
      setState(688);
      match(qasmParser::LPAREN);
      setState(689);
      expressionList();
      setState(690);
      match(qasmParser::RPAREN);
    }
    setState(694);
    indexedIdentifier();
    setState(699);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == qasmParser::COMMA) {
      setState(695);
      match(qasmParser::COMMA);
      setState(696);
      indexedIdentifier();
      setState(701);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryOperatorContext ------------------------------------------------------------------

qasmParser::UnaryOperatorContext::UnaryOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasmParser::UnaryOperatorContext::MINUS() {
  return getToken(qasmParser::MINUS, 0);
}


size_t qasmParser::UnaryOperatorContext::getRuleIndex() const {
  return qasmParser::RuleUnaryOperator;
}

void qasmParser::UnaryOperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryOperator(this);
}

void qasmParser::UnaryOperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryOperator(this);
}


antlrcpp::Any qasmParser::UnaryOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitUnaryOperator(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::UnaryOperatorContext* qasmParser::unaryOperator() {
  UnaryOperatorContext *_localctx = _tracker.createInstance<UnaryOperatorContext>(_ctx, getState());
  enterRule(_localctx, 120, qasmParser::RuleUnaryOperator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(702);
    _la = _input->LA(1);
    if (!(_la == qasmParser::T__27

    || _la == qasmParser::T__28 || _la == qasmParser::MINUS)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ComparisonOperatorContext ------------------------------------------------------------------

qasmParser::ComparisonOperatorContext::ComparisonOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t qasmParser::ComparisonOperatorContext::getRuleIndex() const {
  return qasmParser::RuleComparisonOperator;
}

void qasmParser::ComparisonOperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComparisonOperator(this);
}

void qasmParser::ComparisonOperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComparisonOperator(this);
}


antlrcpp::Any qasmParser::ComparisonOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitComparisonOperator(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::ComparisonOperatorContext* qasmParser::comparisonOperator() {
  ComparisonOperatorContext *_localctx = _tracker.createInstance<ComparisonOperatorContext>(_ctx, getState());
  enterRule(_localctx, 122, qasmParser::RuleComparisonOperator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(704);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasmParser::T__29)
      | (1ULL << qasmParser::T__30)
      | (1ULL << qasmParser::T__31)
      | (1ULL << qasmParser::T__32))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EqualityOperatorContext ------------------------------------------------------------------

qasmParser::EqualityOperatorContext::EqualityOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t qasmParser::EqualityOperatorContext::getRuleIndex() const {
  return qasmParser::RuleEqualityOperator;
}

void qasmParser::EqualityOperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEqualityOperator(this);
}

void qasmParser::EqualityOperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEqualityOperator(this);
}


antlrcpp::Any qasmParser::EqualityOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitEqualityOperator(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::EqualityOperatorContext* qasmParser::equalityOperator() {
  EqualityOperatorContext *_localctx = _tracker.createInstance<EqualityOperatorContext>(_ctx, getState());
  enterRule(_localctx, 124, qasmParser::RuleEqualityOperator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(706);
    _la = _input->LA(1);
    if (!(_la == qasmParser::T__33

    || _la == qasmParser::T__34)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LogicalOperatorContext ------------------------------------------------------------------

qasmParser::LogicalOperatorContext::LogicalOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t qasmParser::LogicalOperatorContext::getRuleIndex() const {
  return qasmParser::RuleLogicalOperator;
}

void qasmParser::LogicalOperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicalOperator(this);
}

void qasmParser::LogicalOperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicalOperator(this);
}


antlrcpp::Any qasmParser::LogicalOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitLogicalOperator(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::LogicalOperatorContext* qasmParser::logicalOperator() {
  LogicalOperatorContext *_localctx = _tracker.createInstance<LogicalOperatorContext>(_ctx, getState());
  enterRule(_localctx, 126, qasmParser::RuleLogicalOperator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(708);
    _la = _input->LA(1);
    if (!(_la == qasmParser::T__35

    || _la == qasmParser::T__36)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionStatementContext ------------------------------------------------------------------

qasmParser::ExpressionStatementContext::ExpressionStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::ExpressionContext* qasmParser::ExpressionStatementContext::expression() {
  return getRuleContext<qasmParser::ExpressionContext>(0);
}

tree::TerminalNode* qasmParser::ExpressionStatementContext::SEMICOLON() {
  return getToken(qasmParser::SEMICOLON, 0);
}


size_t qasmParser::ExpressionStatementContext::getRuleIndex() const {
  return qasmParser::RuleExpressionStatement;
}

void qasmParser::ExpressionStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionStatement(this);
}

void qasmParser::ExpressionStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionStatement(this);
}


antlrcpp::Any qasmParser::ExpressionStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitExpressionStatement(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::ExpressionStatementContext* qasmParser::expressionStatement() {
  ExpressionStatementContext *_localctx = _tracker.createInstance<ExpressionStatementContext>(_ctx, getState());
  enterRule(_localctx, 128, qasmParser::RuleExpressionStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(710);
    expression(0);
    setState(711);
    match(qasmParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

qasmParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::ExpressionTerminatorContext* qasmParser::ExpressionContext::expressionTerminator() {
  return getRuleContext<qasmParser::ExpressionTerminatorContext>(0);
}

qasmParser::UnaryExpressionContext* qasmParser::ExpressionContext::unaryExpression() {
  return getRuleContext<qasmParser::UnaryExpressionContext>(0);
}

qasmParser::LogicalAndExpressionContext* qasmParser::ExpressionContext::logicalAndExpression() {
  return getRuleContext<qasmParser::LogicalAndExpressionContext>(0);
}

qasmParser::ExpressionContext* qasmParser::ExpressionContext::expression() {
  return getRuleContext<qasmParser::ExpressionContext>(0);
}


size_t qasmParser::ExpressionContext::getRuleIndex() const {
  return qasmParser::RuleExpression;
}

void qasmParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void qasmParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}


antlrcpp::Any qasmParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}


qasmParser::ExpressionContext* qasmParser::expression() {
   return expression(0);
}

qasmParser::ExpressionContext* qasmParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  qasmParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  qasmParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 130;
  enterRecursionRule(_localctx, 130, qasmParser::RuleExpression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(717);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 67, _ctx)) {
    case 1: {
      setState(714);
      expressionTerminator();
      break;
    }

    case 2: {
      setState(715);
      unaryExpression();
      break;
    }

    case 3: {
      setState(716);
      logicalAndExpression(0);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(724);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 68, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExpression);
        setState(719);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(720);
        match(qasmParser::T__36);
        setState(721);
        logicalAndExpression(0); 
      }
      setState(726);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 68, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- LogicalAndExpressionContext ------------------------------------------------------------------

qasmParser::LogicalAndExpressionContext::LogicalAndExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::BitOrExpressionContext* qasmParser::LogicalAndExpressionContext::bitOrExpression() {
  return getRuleContext<qasmParser::BitOrExpressionContext>(0);
}

qasmParser::LogicalAndExpressionContext* qasmParser::LogicalAndExpressionContext::logicalAndExpression() {
  return getRuleContext<qasmParser::LogicalAndExpressionContext>(0);
}


size_t qasmParser::LogicalAndExpressionContext::getRuleIndex() const {
  return qasmParser::RuleLogicalAndExpression;
}

void qasmParser::LogicalAndExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicalAndExpression(this);
}

void qasmParser::LogicalAndExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicalAndExpression(this);
}


antlrcpp::Any qasmParser::LogicalAndExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitLogicalAndExpression(this);
  else
    return visitor->visitChildren(this);
}


qasmParser::LogicalAndExpressionContext* qasmParser::logicalAndExpression() {
   return logicalAndExpression(0);
}

qasmParser::LogicalAndExpressionContext* qasmParser::logicalAndExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  qasmParser::LogicalAndExpressionContext *_localctx = _tracker.createInstance<LogicalAndExpressionContext>(_ctx, parentState);
  qasmParser::LogicalAndExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 132;
  enterRecursionRule(_localctx, 132, qasmParser::RuleLogicalAndExpression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(728);
    bitOrExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(735);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 69, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<LogicalAndExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLogicalAndExpression);
        setState(730);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(731);
        match(qasmParser::T__35);
        setState(732);
        bitOrExpression(0); 
      }
      setState(737);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 69, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- BitOrExpressionContext ------------------------------------------------------------------

qasmParser::BitOrExpressionContext::BitOrExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::XOrExpressionContext* qasmParser::BitOrExpressionContext::xOrExpression() {
  return getRuleContext<qasmParser::XOrExpressionContext>(0);
}

qasmParser::BitOrExpressionContext* qasmParser::BitOrExpressionContext::bitOrExpression() {
  return getRuleContext<qasmParser::BitOrExpressionContext>(0);
}


size_t qasmParser::BitOrExpressionContext::getRuleIndex() const {
  return qasmParser::RuleBitOrExpression;
}

void qasmParser::BitOrExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBitOrExpression(this);
}

void qasmParser::BitOrExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBitOrExpression(this);
}


antlrcpp::Any qasmParser::BitOrExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitBitOrExpression(this);
  else
    return visitor->visitChildren(this);
}


qasmParser::BitOrExpressionContext* qasmParser::bitOrExpression() {
   return bitOrExpression(0);
}

qasmParser::BitOrExpressionContext* qasmParser::bitOrExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  qasmParser::BitOrExpressionContext *_localctx = _tracker.createInstance<BitOrExpressionContext>(_ctx, parentState);
  qasmParser::BitOrExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 134;
  enterRecursionRule(_localctx, 134, qasmParser::RuleBitOrExpression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(739);
    xOrExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(746);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 70, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<BitOrExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleBitOrExpression);
        setState(741);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(742);
        match(qasmParser::T__37);
        setState(743);
        xOrExpression(0); 
      }
      setState(748);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 70, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- XOrExpressionContext ------------------------------------------------------------------

qasmParser::XOrExpressionContext::XOrExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::BitAndExpressionContext* qasmParser::XOrExpressionContext::bitAndExpression() {
  return getRuleContext<qasmParser::BitAndExpressionContext>(0);
}

qasmParser::XOrExpressionContext* qasmParser::XOrExpressionContext::xOrExpression() {
  return getRuleContext<qasmParser::XOrExpressionContext>(0);
}


size_t qasmParser::XOrExpressionContext::getRuleIndex() const {
  return qasmParser::RuleXOrExpression;
}

void qasmParser::XOrExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterXOrExpression(this);
}

void qasmParser::XOrExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitXOrExpression(this);
}


antlrcpp::Any qasmParser::XOrExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitXOrExpression(this);
  else
    return visitor->visitChildren(this);
}


qasmParser::XOrExpressionContext* qasmParser::xOrExpression() {
   return xOrExpression(0);
}

qasmParser::XOrExpressionContext* qasmParser::xOrExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  qasmParser::XOrExpressionContext *_localctx = _tracker.createInstance<XOrExpressionContext>(_ctx, parentState);
  qasmParser::XOrExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 136;
  enterRecursionRule(_localctx, 136, qasmParser::RuleXOrExpression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(750);
    bitAndExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(757);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 71, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<XOrExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleXOrExpression);
        setState(752);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(753);
        match(qasmParser::T__38);
        setState(754);
        bitAndExpression(0); 
      }
      setState(759);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 71, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- BitAndExpressionContext ------------------------------------------------------------------

qasmParser::BitAndExpressionContext::BitAndExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::EqualityExpressionContext* qasmParser::BitAndExpressionContext::equalityExpression() {
  return getRuleContext<qasmParser::EqualityExpressionContext>(0);
}

qasmParser::BitAndExpressionContext* qasmParser::BitAndExpressionContext::bitAndExpression() {
  return getRuleContext<qasmParser::BitAndExpressionContext>(0);
}


size_t qasmParser::BitAndExpressionContext::getRuleIndex() const {
  return qasmParser::RuleBitAndExpression;
}

void qasmParser::BitAndExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBitAndExpression(this);
}

void qasmParser::BitAndExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBitAndExpression(this);
}


antlrcpp::Any qasmParser::BitAndExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitBitAndExpression(this);
  else
    return visitor->visitChildren(this);
}


qasmParser::BitAndExpressionContext* qasmParser::bitAndExpression() {
   return bitAndExpression(0);
}

qasmParser::BitAndExpressionContext* qasmParser::bitAndExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  qasmParser::BitAndExpressionContext *_localctx = _tracker.createInstance<BitAndExpressionContext>(_ctx, parentState);
  qasmParser::BitAndExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 138;
  enterRecursionRule(_localctx, 138, qasmParser::RuleBitAndExpression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(761);
    equalityExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(768);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 72, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<BitAndExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleBitAndExpression);
        setState(763);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(764);
        match(qasmParser::T__39);
        setState(765);
        equalityExpression(0); 
      }
      setState(770);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 72, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- EqualityExpressionContext ------------------------------------------------------------------

qasmParser::EqualityExpressionContext::EqualityExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::ComparisonExpressionContext* qasmParser::EqualityExpressionContext::comparisonExpression() {
  return getRuleContext<qasmParser::ComparisonExpressionContext>(0);
}

qasmParser::EqualityExpressionContext* qasmParser::EqualityExpressionContext::equalityExpression() {
  return getRuleContext<qasmParser::EqualityExpressionContext>(0);
}

qasmParser::EqualityOperatorContext* qasmParser::EqualityExpressionContext::equalityOperator() {
  return getRuleContext<qasmParser::EqualityOperatorContext>(0);
}


size_t qasmParser::EqualityExpressionContext::getRuleIndex() const {
  return qasmParser::RuleEqualityExpression;
}

void qasmParser::EqualityExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEqualityExpression(this);
}

void qasmParser::EqualityExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEqualityExpression(this);
}


antlrcpp::Any qasmParser::EqualityExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitEqualityExpression(this);
  else
    return visitor->visitChildren(this);
}


qasmParser::EqualityExpressionContext* qasmParser::equalityExpression() {
   return equalityExpression(0);
}

qasmParser::EqualityExpressionContext* qasmParser::equalityExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  qasmParser::EqualityExpressionContext *_localctx = _tracker.createInstance<EqualityExpressionContext>(_ctx, parentState);
  qasmParser::EqualityExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 140;
  enterRecursionRule(_localctx, 140, qasmParser::RuleEqualityExpression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(772);
    comparisonExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(780);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 73, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<EqualityExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleEqualityExpression);
        setState(774);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(775);
        equalityOperator();
        setState(776);
        comparisonExpression(0); 
      }
      setState(782);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 73, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ComparisonExpressionContext ------------------------------------------------------------------

qasmParser::ComparisonExpressionContext::ComparisonExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::BitShiftExpressionContext* qasmParser::ComparisonExpressionContext::bitShiftExpression() {
  return getRuleContext<qasmParser::BitShiftExpressionContext>(0);
}

qasmParser::ComparisonExpressionContext* qasmParser::ComparisonExpressionContext::comparisonExpression() {
  return getRuleContext<qasmParser::ComparisonExpressionContext>(0);
}

qasmParser::ComparisonOperatorContext* qasmParser::ComparisonExpressionContext::comparisonOperator() {
  return getRuleContext<qasmParser::ComparisonOperatorContext>(0);
}


size_t qasmParser::ComparisonExpressionContext::getRuleIndex() const {
  return qasmParser::RuleComparisonExpression;
}

void qasmParser::ComparisonExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComparisonExpression(this);
}

void qasmParser::ComparisonExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComparisonExpression(this);
}


antlrcpp::Any qasmParser::ComparisonExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitComparisonExpression(this);
  else
    return visitor->visitChildren(this);
}


qasmParser::ComparisonExpressionContext* qasmParser::comparisonExpression() {
   return comparisonExpression(0);
}

qasmParser::ComparisonExpressionContext* qasmParser::comparisonExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  qasmParser::ComparisonExpressionContext *_localctx = _tracker.createInstance<ComparisonExpressionContext>(_ctx, parentState);
  qasmParser::ComparisonExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 142;
  enterRecursionRule(_localctx, 142, qasmParser::RuleComparisonExpression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(784);
    bitShiftExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(792);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 74, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ComparisonExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleComparisonExpression);
        setState(786);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(787);
        comparisonOperator();
        setState(788);
        bitShiftExpression(0); 
      }
      setState(794);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 74, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- BitShiftExpressionContext ------------------------------------------------------------------

qasmParser::BitShiftExpressionContext::BitShiftExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::AdditiveExpressionContext* qasmParser::BitShiftExpressionContext::additiveExpression() {
  return getRuleContext<qasmParser::AdditiveExpressionContext>(0);
}

qasmParser::BitShiftExpressionContext* qasmParser::BitShiftExpressionContext::bitShiftExpression() {
  return getRuleContext<qasmParser::BitShiftExpressionContext>(0);
}


size_t qasmParser::BitShiftExpressionContext::getRuleIndex() const {
  return qasmParser::RuleBitShiftExpression;
}

void qasmParser::BitShiftExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBitShiftExpression(this);
}

void qasmParser::BitShiftExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBitShiftExpression(this);
}


antlrcpp::Any qasmParser::BitShiftExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitBitShiftExpression(this);
  else
    return visitor->visitChildren(this);
}


qasmParser::BitShiftExpressionContext* qasmParser::bitShiftExpression() {
   return bitShiftExpression(0);
}

qasmParser::BitShiftExpressionContext* qasmParser::bitShiftExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  qasmParser::BitShiftExpressionContext *_localctx = _tracker.createInstance<BitShiftExpressionContext>(_ctx, parentState);
  qasmParser::BitShiftExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 144;
  enterRecursionRule(_localctx, 144, qasmParser::RuleBitShiftExpression, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(796);
    additiveExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(803);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 75, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<BitShiftExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleBitShiftExpression);
        setState(798);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(799);
        _la = _input->LA(1);
        if (!(_la == qasmParser::T__40

        || _la == qasmParser::T__41)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(800);
        additiveExpression(0); 
      }
      setState(805);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 75, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- AdditiveExpressionContext ------------------------------------------------------------------

qasmParser::AdditiveExpressionContext::AdditiveExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::MultiplicativeExpressionContext* qasmParser::AdditiveExpressionContext::multiplicativeExpression() {
  return getRuleContext<qasmParser::MultiplicativeExpressionContext>(0);
}

qasmParser::AdditiveExpressionContext* qasmParser::AdditiveExpressionContext::additiveExpression() {
  return getRuleContext<qasmParser::AdditiveExpressionContext>(0);
}

tree::TerminalNode* qasmParser::AdditiveExpressionContext::PLUS() {
  return getToken(qasmParser::PLUS, 0);
}

tree::TerminalNode* qasmParser::AdditiveExpressionContext::MINUS() {
  return getToken(qasmParser::MINUS, 0);
}


size_t qasmParser::AdditiveExpressionContext::getRuleIndex() const {
  return qasmParser::RuleAdditiveExpression;
}

void qasmParser::AdditiveExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAdditiveExpression(this);
}

void qasmParser::AdditiveExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAdditiveExpression(this);
}


antlrcpp::Any qasmParser::AdditiveExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitAdditiveExpression(this);
  else
    return visitor->visitChildren(this);
}


qasmParser::AdditiveExpressionContext* qasmParser::additiveExpression() {
   return additiveExpression(0);
}

qasmParser::AdditiveExpressionContext* qasmParser::additiveExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  qasmParser::AdditiveExpressionContext *_localctx = _tracker.createInstance<AdditiveExpressionContext>(_ctx, parentState);
  qasmParser::AdditiveExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 146;
  enterRecursionRule(_localctx, 146, qasmParser::RuleAdditiveExpression, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(807);
    multiplicativeExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(814);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 76, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<AdditiveExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleAdditiveExpression);
        setState(809);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(810);
        _la = _input->LA(1);
        if (!(_la == qasmParser::PLUS

        || _la == qasmParser::MINUS)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(811);
        multiplicativeExpression(0); 
      }
      setState(816);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 76, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- MultiplicativeExpressionContext ------------------------------------------------------------------

qasmParser::MultiplicativeExpressionContext::MultiplicativeExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::UnaryExpressionContext* qasmParser::MultiplicativeExpressionContext::unaryExpression() {
  return getRuleContext<qasmParser::UnaryExpressionContext>(0);
}

qasmParser::MultiplicativeExpressionContext* qasmParser::MultiplicativeExpressionContext::multiplicativeExpression() {
  return getRuleContext<qasmParser::MultiplicativeExpressionContext>(0);
}

tree::TerminalNode* qasmParser::MultiplicativeExpressionContext::MUL() {
  return getToken(qasmParser::MUL, 0);
}

tree::TerminalNode* qasmParser::MultiplicativeExpressionContext::DIV() {
  return getToken(qasmParser::DIV, 0);
}

tree::TerminalNode* qasmParser::MultiplicativeExpressionContext::MOD() {
  return getToken(qasmParser::MOD, 0);
}


size_t qasmParser::MultiplicativeExpressionContext::getRuleIndex() const {
  return qasmParser::RuleMultiplicativeExpression;
}

void qasmParser::MultiplicativeExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiplicativeExpression(this);
}

void qasmParser::MultiplicativeExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiplicativeExpression(this);
}


antlrcpp::Any qasmParser::MultiplicativeExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitMultiplicativeExpression(this);
  else
    return visitor->visitChildren(this);
}


qasmParser::MultiplicativeExpressionContext* qasmParser::multiplicativeExpression() {
   return multiplicativeExpression(0);
}

qasmParser::MultiplicativeExpressionContext* qasmParser::multiplicativeExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  qasmParser::MultiplicativeExpressionContext *_localctx = _tracker.createInstance<MultiplicativeExpressionContext>(_ctx, parentState);
  qasmParser::MultiplicativeExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 148;
  enterRecursionRule(_localctx, 148, qasmParser::RuleMultiplicativeExpression, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(818);
    unaryExpression();
    _ctx->stop = _input->LT(-1);
    setState(825);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 77, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<MultiplicativeExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleMultiplicativeExpression);
        setState(820);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(821);
        _la = _input->LA(1);
        if (!(((((_la - 105) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 105)) & ((1ULL << (qasmParser::MUL - 105))
          | (1ULL << (qasmParser::DIV - 105))
          | (1ULL << (qasmParser::MOD - 105)))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(822);
        unaryExpression(); 
      }
      setState(827);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 77, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- UnaryExpressionContext ------------------------------------------------------------------

qasmParser::UnaryExpressionContext::UnaryExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::PowerExpressionContext* qasmParser::UnaryExpressionContext::powerExpression() {
  return getRuleContext<qasmParser::PowerExpressionContext>(0);
}

qasmParser::UnaryOperatorContext* qasmParser::UnaryExpressionContext::unaryOperator() {
  return getRuleContext<qasmParser::UnaryOperatorContext>(0);
}


size_t qasmParser::UnaryExpressionContext::getRuleIndex() const {
  return qasmParser::RuleUnaryExpression;
}

void qasmParser::UnaryExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryExpression(this);
}

void qasmParser::UnaryExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryExpression(this);
}


antlrcpp::Any qasmParser::UnaryExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitUnaryExpression(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::UnaryExpressionContext* qasmParser::unaryExpression() {
  UnaryExpressionContext *_localctx = _tracker.createInstance<UnaryExpressionContext>(_ctx, getState());
  enterRule(_localctx, 150, qasmParser::RuleUnaryExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(829);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasmParser::T__27

    || _la == qasmParser::T__28 || _la == qasmParser::MINUS) {
      setState(828);
      unaryOperator();
    }
    setState(831);
    powerExpression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PowerExpressionContext ------------------------------------------------------------------

qasmParser::PowerExpressionContext::PowerExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::IndexExpressionContext* qasmParser::PowerExpressionContext::indexExpression() {
  return getRuleContext<qasmParser::IndexExpressionContext>(0);
}

qasmParser::PowerExpressionContext* qasmParser::PowerExpressionContext::powerExpression() {
  return getRuleContext<qasmParser::PowerExpressionContext>(0);
}


size_t qasmParser::PowerExpressionContext::getRuleIndex() const {
  return qasmParser::RulePowerExpression;
}

void qasmParser::PowerExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPowerExpression(this);
}

void qasmParser::PowerExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPowerExpression(this);
}


antlrcpp::Any qasmParser::PowerExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitPowerExpression(this);
  else
    return visitor->visitChildren(this);
}


qasmParser::PowerExpressionContext* qasmParser::powerExpression() {
   return powerExpression(0);
}

qasmParser::PowerExpressionContext* qasmParser::powerExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  qasmParser::PowerExpressionContext *_localctx = _tracker.createInstance<PowerExpressionContext>(_ctx, parentState);
  qasmParser::PowerExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 152;
  enterRecursionRule(_localctx, 152, qasmParser::RulePowerExpression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(834);
    indexExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(841);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 79, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<PowerExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RulePowerExpression);
        setState(836);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(837);
        match(qasmParser::T__42);
        setState(838);
        indexExpression(0); 
      }
      setState(843);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 79, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- IndexOperatorContext ------------------------------------------------------------------

qasmParser::IndexOperatorContext::IndexOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasmParser::IndexOperatorContext::LBRACKET() {
  return getToken(qasmParser::LBRACKET, 0);
}

tree::TerminalNode* qasmParser::IndexOperatorContext::RBRACKET() {
  return getToken(qasmParser::RBRACKET, 0);
}

qasmParser::DiscreteSetContext* qasmParser::IndexOperatorContext::discreteSet() {
  return getRuleContext<qasmParser::DiscreteSetContext>(0);
}

std::vector<qasmParser::ExpressionContext *> qasmParser::IndexOperatorContext::expression() {
  return getRuleContexts<qasmParser::ExpressionContext>();
}

qasmParser::ExpressionContext* qasmParser::IndexOperatorContext::expression(size_t i) {
  return getRuleContext<qasmParser::ExpressionContext>(i);
}

std::vector<qasmParser::RangeDefinitionContext *> qasmParser::IndexOperatorContext::rangeDefinition() {
  return getRuleContexts<qasmParser::RangeDefinitionContext>();
}

qasmParser::RangeDefinitionContext* qasmParser::IndexOperatorContext::rangeDefinition(size_t i) {
  return getRuleContext<qasmParser::RangeDefinitionContext>(i);
}

std::vector<tree::TerminalNode *> qasmParser::IndexOperatorContext::COMMA() {
  return getTokens(qasmParser::COMMA);
}

tree::TerminalNode* qasmParser::IndexOperatorContext::COMMA(size_t i) {
  return getToken(qasmParser::COMMA, i);
}


size_t qasmParser::IndexOperatorContext::getRuleIndex() const {
  return qasmParser::RuleIndexOperator;
}

void qasmParser::IndexOperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIndexOperator(this);
}

void qasmParser::IndexOperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIndexOperator(this);
}


antlrcpp::Any qasmParser::IndexOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitIndexOperator(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::IndexOperatorContext* qasmParser::indexOperator() {
  IndexOperatorContext *_localctx = _tracker.createInstance<IndexOperatorContext>(_ctx, getState());
  enterRule(_localctx, 154, qasmParser::RuleIndexOperator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(844);
    match(qasmParser::LBRACKET);
    setState(860);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasmParser::LBRACE: {
        setState(845);
        discreteSet();
        break;
      }

      case qasmParser::T__6:
      case qasmParser::T__7:
      case qasmParser::T__8:
      case qasmParser::T__9:
      case qasmParser::T__10:
      case qasmParser::T__11:
      case qasmParser::T__12:
      case qasmParser::T__27:
      case qasmParser::T__28:
      case qasmParser::T__43:
      case qasmParser::T__44:
      case qasmParser::T__45:
      case qasmParser::T__46:
      case qasmParser::T__47:
      case qasmParser::T__48:
      case qasmParser::T__49:
      case qasmParser::T__50:
      case qasmParser::T__51:
      case qasmParser::T__52:
      case qasmParser::T__53:
      case qasmParser::T__54:
      case qasmParser::T__55:
      case qasmParser::T__56:
      case qasmParser::T__81:
      case qasmParser::T__82:
      case qasmParser::T__84:
      case qasmParser::LPAREN:
      case qasmParser::COLON:
      case qasmParser::MINUS:
      case qasmParser::ImagNumber:
      case qasmParser::COMPLEX:
      case qasmParser::ARRAY:
      case qasmParser::SIZEOF:
      case qasmParser::Constant:
      case qasmParser::Integer:
      case qasmParser::Identifier:
      case qasmParser::RealNumber:
      case qasmParser::TimingLiteral:
      case qasmParser::StringLiteral: {
        setState(848);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 80, _ctx)) {
        case 1: {
          setState(846);
          expression(0);
          break;
        }

        case 2: {
          setState(847);
          rangeDefinition();
          break;
        }

        default:
          break;
        }
        setState(857);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == qasmParser::COMMA) {
          setState(850);
          match(qasmParser::COMMA);
          setState(853);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 81, _ctx)) {
          case 1: {
            setState(851);
            expression(0);
            break;
          }

          case 2: {
            setState(852);
            rangeDefinition();
            break;
          }

          default:
            break;
          }
          setState(859);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(862);
    match(qasmParser::RBRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IndexExpressionContext ------------------------------------------------------------------

qasmParser::IndexExpressionContext::IndexExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::ExpressionTerminatorContext* qasmParser::IndexExpressionContext::expressionTerminator() {
  return getRuleContext<qasmParser::ExpressionTerminatorContext>(0);
}

qasmParser::IndexExpressionContext* qasmParser::IndexExpressionContext::indexExpression() {
  return getRuleContext<qasmParser::IndexExpressionContext>(0);
}

qasmParser::IndexOperatorContext* qasmParser::IndexExpressionContext::indexOperator() {
  return getRuleContext<qasmParser::IndexOperatorContext>(0);
}


size_t qasmParser::IndexExpressionContext::getRuleIndex() const {
  return qasmParser::RuleIndexExpression;
}

void qasmParser::IndexExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIndexExpression(this);
}

void qasmParser::IndexExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIndexExpression(this);
}


antlrcpp::Any qasmParser::IndexExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitIndexExpression(this);
  else
    return visitor->visitChildren(this);
}


qasmParser::IndexExpressionContext* qasmParser::indexExpression() {
   return indexExpression(0);
}

qasmParser::IndexExpressionContext* qasmParser::indexExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  qasmParser::IndexExpressionContext *_localctx = _tracker.createInstance<IndexExpressionContext>(_ctx, parentState);
  qasmParser::IndexExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 156;
  enterRecursionRule(_localctx, 156, qasmParser::RuleIndexExpression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(865);
    expressionTerminator();
    _ctx->stop = _input->LT(-1);
    setState(871);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 84, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<IndexExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleIndexExpression);
        setState(867);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(868);
        indexOperator(); 
      }
      setState(873);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 84, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- IndexedIdentifierContext ------------------------------------------------------------------

qasmParser::IndexedIdentifierContext::IndexedIdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasmParser::IndexedIdentifierContext::Identifier() {
  return getToken(qasmParser::Identifier, 0);
}

std::vector<qasmParser::IndexOperatorContext *> qasmParser::IndexedIdentifierContext::indexOperator() {
  return getRuleContexts<qasmParser::IndexOperatorContext>();
}

qasmParser::IndexOperatorContext* qasmParser::IndexedIdentifierContext::indexOperator(size_t i) {
  return getRuleContext<qasmParser::IndexOperatorContext>(i);
}


size_t qasmParser::IndexedIdentifierContext::getRuleIndex() const {
  return qasmParser::RuleIndexedIdentifier;
}

void qasmParser::IndexedIdentifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIndexedIdentifier(this);
}

void qasmParser::IndexedIdentifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIndexedIdentifier(this);
}


antlrcpp::Any qasmParser::IndexedIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitIndexedIdentifier(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::IndexedIdentifierContext* qasmParser::indexedIdentifier() {
  IndexedIdentifierContext *_localctx = _tracker.createInstance<IndexedIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 158, qasmParser::RuleIndexedIdentifier);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(874);
    match(qasmParser::Identifier);
    setState(878);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == qasmParser::LBRACKET) {
      setState(875);
      indexOperator();
      setState(880);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionTerminatorContext ------------------------------------------------------------------

qasmParser::ExpressionTerminatorContext::ExpressionTerminatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasmParser::ExpressionTerminatorContext::Constant() {
  return getToken(qasmParser::Constant, 0);
}

tree::TerminalNode* qasmParser::ExpressionTerminatorContext::Integer() {
  return getToken(qasmParser::Integer, 0);
}

tree::TerminalNode* qasmParser::ExpressionTerminatorContext::RealNumber() {
  return getToken(qasmParser::RealNumber, 0);
}

tree::TerminalNode* qasmParser::ExpressionTerminatorContext::ImagNumber() {
  return getToken(qasmParser::ImagNumber, 0);
}

qasmParser::BooleanLiteralContext* qasmParser::ExpressionTerminatorContext::booleanLiteral() {
  return getRuleContext<qasmParser::BooleanLiteralContext>(0);
}

tree::TerminalNode* qasmParser::ExpressionTerminatorContext::Identifier() {
  return getToken(qasmParser::Identifier, 0);
}

tree::TerminalNode* qasmParser::ExpressionTerminatorContext::StringLiteral() {
  return getToken(qasmParser::StringLiteral, 0);
}

qasmParser::BuiltInCallContext* qasmParser::ExpressionTerminatorContext::builtInCall() {
  return getRuleContext<qasmParser::BuiltInCallContext>(0);
}

qasmParser::ExternOrSubroutineCallContext* qasmParser::ExpressionTerminatorContext::externOrSubroutineCall() {
  return getRuleContext<qasmParser::ExternOrSubroutineCallContext>(0);
}

qasmParser::TimingIdentifierContext* qasmParser::ExpressionTerminatorContext::timingIdentifier() {
  return getRuleContext<qasmParser::TimingIdentifierContext>(0);
}

tree::TerminalNode* qasmParser::ExpressionTerminatorContext::LPAREN() {
  return getToken(qasmParser::LPAREN, 0);
}

qasmParser::ExpressionContext* qasmParser::ExpressionTerminatorContext::expression() {
  return getRuleContext<qasmParser::ExpressionContext>(0);
}

tree::TerminalNode* qasmParser::ExpressionTerminatorContext::RPAREN() {
  return getToken(qasmParser::RPAREN, 0);
}


size_t qasmParser::ExpressionTerminatorContext::getRuleIndex() const {
  return qasmParser::RuleExpressionTerminator;
}

void qasmParser::ExpressionTerminatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionTerminator(this);
}

void qasmParser::ExpressionTerminatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionTerminator(this);
}


antlrcpp::Any qasmParser::ExpressionTerminatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitExpressionTerminator(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::ExpressionTerminatorContext* qasmParser::expressionTerminator() {
  ExpressionTerminatorContext *_localctx = _tracker.createInstance<ExpressionTerminatorContext>(_ctx, getState());
  enterRule(_localctx, 160, qasmParser::RuleExpressionTerminator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(895);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 86, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(881);
      match(qasmParser::Constant);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(882);
      match(qasmParser::Integer);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(883);
      match(qasmParser::RealNumber);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(884);
      match(qasmParser::ImagNumber);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(885);
      booleanLiteral();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(886);
      match(qasmParser::Identifier);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(887);
      match(qasmParser::StringLiteral);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(888);
      builtInCall();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(889);
      externOrSubroutineCall();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(890);
      timingIdentifier();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(891);
      match(qasmParser::LPAREN);
      setState(892);
      expression(0);
      setState(893);
      match(qasmParser::RPAREN);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BooleanLiteralContext ------------------------------------------------------------------

qasmParser::BooleanLiteralContext::BooleanLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t qasmParser::BooleanLiteralContext::getRuleIndex() const {
  return qasmParser::RuleBooleanLiteral;
}

void qasmParser::BooleanLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBooleanLiteral(this);
}

void qasmParser::BooleanLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBooleanLiteral(this);
}


antlrcpp::Any qasmParser::BooleanLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitBooleanLiteral(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::BooleanLiteralContext* qasmParser::booleanLiteral() {
  BooleanLiteralContext *_localctx = _tracker.createInstance<BooleanLiteralContext>(_ctx, getState());
  enterRule(_localctx, 162, qasmParser::RuleBooleanLiteral);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(897);
    _la = _input->LA(1);
    if (!(_la == qasmParser::T__43

    || _la == qasmParser::T__44)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BuiltInCallContext ------------------------------------------------------------------

qasmParser::BuiltInCallContext::BuiltInCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasmParser::BuiltInCallContext::LPAREN() {
  return getToken(qasmParser::LPAREN, 0);
}

qasmParser::ExpressionListContext* qasmParser::BuiltInCallContext::expressionList() {
  return getRuleContext<qasmParser::ExpressionListContext>(0);
}

tree::TerminalNode* qasmParser::BuiltInCallContext::RPAREN() {
  return getToken(qasmParser::RPAREN, 0);
}

qasmParser::BuiltInMathContext* qasmParser::BuiltInCallContext::builtInMath() {
  return getRuleContext<qasmParser::BuiltInMathContext>(0);
}

qasmParser::CastOperatorContext* qasmParser::BuiltInCallContext::castOperator() {
  return getRuleContext<qasmParser::CastOperatorContext>(0);
}

tree::TerminalNode* qasmParser::BuiltInCallContext::SIZEOF() {
  return getToken(qasmParser::SIZEOF, 0);
}


size_t qasmParser::BuiltInCallContext::getRuleIndex() const {
  return qasmParser::RuleBuiltInCall;
}

void qasmParser::BuiltInCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBuiltInCall(this);
}

void qasmParser::BuiltInCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBuiltInCall(this);
}


antlrcpp::Any qasmParser::BuiltInCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitBuiltInCall(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::BuiltInCallContext* qasmParser::builtInCall() {
  BuiltInCallContext *_localctx = _tracker.createInstance<BuiltInCallContext>(_ctx, getState());
  enterRule(_localctx, 164, qasmParser::RuleBuiltInCall);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(902);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasmParser::T__45:
      case qasmParser::T__46:
      case qasmParser::T__47:
      case qasmParser::T__48:
      case qasmParser::T__49:
      case qasmParser::T__50:
      case qasmParser::T__51:
      case qasmParser::T__52:
      case qasmParser::T__53:
      case qasmParser::T__54:
      case qasmParser::T__55:
      case qasmParser::T__56: {
        setState(899);
        builtInMath();
        break;
      }

      case qasmParser::T__6:
      case qasmParser::T__7:
      case qasmParser::T__8:
      case qasmParser::T__9:
      case qasmParser::T__10:
      case qasmParser::T__11:
      case qasmParser::T__12:
      case qasmParser::T__81:
      case qasmParser::T__82:
      case qasmParser::COMPLEX:
      case qasmParser::ARRAY: {
        setState(900);
        castOperator();
        break;
      }

      case qasmParser::SIZEOF: {
        setState(901);
        match(qasmParser::SIZEOF);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(904);
    match(qasmParser::LPAREN);
    setState(905);
    expressionList();
    setState(906);
    match(qasmParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BuiltInMathContext ------------------------------------------------------------------

qasmParser::BuiltInMathContext::BuiltInMathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t qasmParser::BuiltInMathContext::getRuleIndex() const {
  return qasmParser::RuleBuiltInMath;
}

void qasmParser::BuiltInMathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBuiltInMath(this);
}

void qasmParser::BuiltInMathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBuiltInMath(this);
}


antlrcpp::Any qasmParser::BuiltInMathContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitBuiltInMath(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::BuiltInMathContext* qasmParser::builtInMath() {
  BuiltInMathContext *_localctx = _tracker.createInstance<BuiltInMathContext>(_ctx, getState());
  enterRule(_localctx, 166, qasmParser::RuleBuiltInMath);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(908);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasmParser::T__45)
      | (1ULL << qasmParser::T__46)
      | (1ULL << qasmParser::T__47)
      | (1ULL << qasmParser::T__48)
      | (1ULL << qasmParser::T__49)
      | (1ULL << qasmParser::T__50)
      | (1ULL << qasmParser::T__51)
      | (1ULL << qasmParser::T__52)
      | (1ULL << qasmParser::T__53)
      | (1ULL << qasmParser::T__54)
      | (1ULL << qasmParser::T__55)
      | (1ULL << qasmParser::T__56))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CastOperatorContext ------------------------------------------------------------------

qasmParser::CastOperatorContext::CastOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::ClassicalTypeContext* qasmParser::CastOperatorContext::classicalType() {
  return getRuleContext<qasmParser::ClassicalTypeContext>(0);
}


size_t qasmParser::CastOperatorContext::getRuleIndex() const {
  return qasmParser::RuleCastOperator;
}

void qasmParser::CastOperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCastOperator(this);
}

void qasmParser::CastOperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCastOperator(this);
}


antlrcpp::Any qasmParser::CastOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitCastOperator(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::CastOperatorContext* qasmParser::castOperator() {
  CastOperatorContext *_localctx = _tracker.createInstance<CastOperatorContext>(_ctx, getState());
  enterRule(_localctx, 168, qasmParser::RuleCastOperator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(910);
    classicalType();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionListContext ------------------------------------------------------------------

qasmParser::ExpressionListContext::ExpressionListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<qasmParser::ExpressionContext *> qasmParser::ExpressionListContext::expression() {
  return getRuleContexts<qasmParser::ExpressionContext>();
}

qasmParser::ExpressionContext* qasmParser::ExpressionListContext::expression(size_t i) {
  return getRuleContext<qasmParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> qasmParser::ExpressionListContext::COMMA() {
  return getTokens(qasmParser::COMMA);
}

tree::TerminalNode* qasmParser::ExpressionListContext::COMMA(size_t i) {
  return getToken(qasmParser::COMMA, i);
}


size_t qasmParser::ExpressionListContext::getRuleIndex() const {
  return qasmParser::RuleExpressionList;
}

void qasmParser::ExpressionListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionList(this);
}

void qasmParser::ExpressionListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionList(this);
}


antlrcpp::Any qasmParser::ExpressionListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitExpressionList(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::ExpressionListContext* qasmParser::expressionList() {
  ExpressionListContext *_localctx = _tracker.createInstance<ExpressionListContext>(_ctx, getState());
  enterRule(_localctx, 170, qasmParser::RuleExpressionList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(912);
    expression(0);
    setState(917);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == qasmParser::COMMA) {
      setState(913);
      match(qasmParser::COMMA);
      setState(914);
      expression(0);
      setState(919);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EqualsExpressionContext ------------------------------------------------------------------

qasmParser::EqualsExpressionContext::EqualsExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasmParser::EqualsExpressionContext::EQUALS() {
  return getToken(qasmParser::EQUALS, 0);
}

qasmParser::ExpressionContext* qasmParser::EqualsExpressionContext::expression() {
  return getRuleContext<qasmParser::ExpressionContext>(0);
}


size_t qasmParser::EqualsExpressionContext::getRuleIndex() const {
  return qasmParser::RuleEqualsExpression;
}

void qasmParser::EqualsExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEqualsExpression(this);
}

void qasmParser::EqualsExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEqualsExpression(this);
}


antlrcpp::Any qasmParser::EqualsExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitEqualsExpression(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::EqualsExpressionContext* qasmParser::equalsExpression() {
  EqualsExpressionContext *_localctx = _tracker.createInstance<EqualsExpressionContext>(_ctx, getState());
  enterRule(_localctx, 172, qasmParser::RuleEqualsExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(920);
    match(qasmParser::EQUALS);
    setState(921);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentOperatorContext ------------------------------------------------------------------

qasmParser::AssignmentOperatorContext::AssignmentOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasmParser::AssignmentOperatorContext::EQUALS() {
  return getToken(qasmParser::EQUALS, 0);
}


size_t qasmParser::AssignmentOperatorContext::getRuleIndex() const {
  return qasmParser::RuleAssignmentOperator;
}

void qasmParser::AssignmentOperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignmentOperator(this);
}

void qasmParser::AssignmentOperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignmentOperator(this);
}


antlrcpp::Any qasmParser::AssignmentOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitAssignmentOperator(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::AssignmentOperatorContext* qasmParser::assignmentOperator() {
  AssignmentOperatorContext *_localctx = _tracker.createInstance<AssignmentOperatorContext>(_ctx, getState());
  enterRule(_localctx, 174, qasmParser::RuleAssignmentOperator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(923);
    _la = _input->LA(1);
    if (!(((((_la - 58) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 58)) & ((1ULL << (qasmParser::T__57 - 58))
      | (1ULL << (qasmParser::T__58 - 58))
      | (1ULL << (qasmParser::T__59 - 58))
      | (1ULL << (qasmParser::T__60 - 58))
      | (1ULL << (qasmParser::T__61 - 58))
      | (1ULL << (qasmParser::T__62 - 58))
      | (1ULL << (qasmParser::T__63 - 58))
      | (1ULL << (qasmParser::T__64 - 58))
      | (1ULL << (qasmParser::T__65 - 58))
      | (1ULL << (qasmParser::T__66 - 58))
      | (1ULL << (qasmParser::T__67 - 58))
      | (1ULL << (qasmParser::T__68 - 58))
      | (1ULL << (qasmParser::EQUALS - 58)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DiscreteSetContext ------------------------------------------------------------------

qasmParser::DiscreteSetContext::DiscreteSetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasmParser::DiscreteSetContext::LBRACE() {
  return getToken(qasmParser::LBRACE, 0);
}

std::vector<qasmParser::ExpressionContext *> qasmParser::DiscreteSetContext::expression() {
  return getRuleContexts<qasmParser::ExpressionContext>();
}

qasmParser::ExpressionContext* qasmParser::DiscreteSetContext::expression(size_t i) {
  return getRuleContext<qasmParser::ExpressionContext>(i);
}

tree::TerminalNode* qasmParser::DiscreteSetContext::RBRACE() {
  return getToken(qasmParser::RBRACE, 0);
}

std::vector<tree::TerminalNode *> qasmParser::DiscreteSetContext::COMMA() {
  return getTokens(qasmParser::COMMA);
}

tree::TerminalNode* qasmParser::DiscreteSetContext::COMMA(size_t i) {
  return getToken(qasmParser::COMMA, i);
}


size_t qasmParser::DiscreteSetContext::getRuleIndex() const {
  return qasmParser::RuleDiscreteSet;
}

void qasmParser::DiscreteSetContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDiscreteSet(this);
}

void qasmParser::DiscreteSetContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDiscreteSet(this);
}


antlrcpp::Any qasmParser::DiscreteSetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitDiscreteSet(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::DiscreteSetContext* qasmParser::discreteSet() {
  DiscreteSetContext *_localctx = _tracker.createInstance<DiscreteSetContext>(_ctx, getState());
  enterRule(_localctx, 176, qasmParser::RuleDiscreteSet);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(925);
    match(qasmParser::LBRACE);
    setState(926);
    expression(0);
    setState(931);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == qasmParser::COMMA) {
      setState(927);
      match(qasmParser::COMMA);
      setState(928);
      expression(0);
      setState(933);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(934);
    match(qasmParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SetDeclarationContext ------------------------------------------------------------------

qasmParser::SetDeclarationContext::SetDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::DiscreteSetContext* qasmParser::SetDeclarationContext::discreteSet() {
  return getRuleContext<qasmParser::DiscreteSetContext>(0);
}

tree::TerminalNode* qasmParser::SetDeclarationContext::LBRACKET() {
  return getToken(qasmParser::LBRACKET, 0);
}

qasmParser::RangeDefinitionContext* qasmParser::SetDeclarationContext::rangeDefinition() {
  return getRuleContext<qasmParser::RangeDefinitionContext>(0);
}

tree::TerminalNode* qasmParser::SetDeclarationContext::RBRACKET() {
  return getToken(qasmParser::RBRACKET, 0);
}

tree::TerminalNode* qasmParser::SetDeclarationContext::Identifier() {
  return getToken(qasmParser::Identifier, 0);
}


size_t qasmParser::SetDeclarationContext::getRuleIndex() const {
  return qasmParser::RuleSetDeclaration;
}

void qasmParser::SetDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSetDeclaration(this);
}

void qasmParser::SetDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSetDeclaration(this);
}


antlrcpp::Any qasmParser::SetDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitSetDeclaration(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::SetDeclarationContext* qasmParser::setDeclaration() {
  SetDeclarationContext *_localctx = _tracker.createInstance<SetDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 178, qasmParser::RuleSetDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(942);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasmParser::LBRACE: {
        enterOuterAlt(_localctx, 1);
        setState(936);
        discreteSet();
        break;
      }

      case qasmParser::LBRACKET: {
        enterOuterAlt(_localctx, 2);
        setState(937);
        match(qasmParser::LBRACKET);
        setState(938);
        rangeDefinition();
        setState(939);
        match(qasmParser::RBRACKET);
        break;
      }

      case qasmParser::Identifier: {
        enterOuterAlt(_localctx, 3);
        setState(941);
        match(qasmParser::Identifier);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramBlockContext ------------------------------------------------------------------

qasmParser::ProgramBlockContext::ProgramBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<qasmParser::StatementContext *> qasmParser::ProgramBlockContext::statement() {
  return getRuleContexts<qasmParser::StatementContext>();
}

qasmParser::StatementContext* qasmParser::ProgramBlockContext::statement(size_t i) {
  return getRuleContext<qasmParser::StatementContext>(i);
}

std::vector<qasmParser::ControlDirectiveContext *> qasmParser::ProgramBlockContext::controlDirective() {
  return getRuleContexts<qasmParser::ControlDirectiveContext>();
}

qasmParser::ControlDirectiveContext* qasmParser::ProgramBlockContext::controlDirective(size_t i) {
  return getRuleContext<qasmParser::ControlDirectiveContext>(i);
}

tree::TerminalNode* qasmParser::ProgramBlockContext::LBRACE() {
  return getToken(qasmParser::LBRACE, 0);
}

tree::TerminalNode* qasmParser::ProgramBlockContext::RBRACE() {
  return getToken(qasmParser::RBRACE, 0);
}


size_t qasmParser::ProgramBlockContext::getRuleIndex() const {
  return qasmParser::RuleProgramBlock;
}

void qasmParser::ProgramBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgramBlock(this);
}

void qasmParser::ProgramBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgramBlock(this);
}


antlrcpp::Any qasmParser::ProgramBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitProgramBlock(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::ProgramBlockContext* qasmParser::programBlock() {
  ProgramBlockContext *_localctx = _tracker.createInstance<ProgramBlockContext>(_ctx, getState());
  enterRule(_localctx, 180, qasmParser::RuleProgramBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(955);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 93, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(944);
      statement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(945);
      controlDirective();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(946);
      match(qasmParser::LBRACE);
      setState(951);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << qasmParser::T__6)
        | (1ULL << qasmParser::T__7)
        | (1ULL << qasmParser::T__8)
        | (1ULL << qasmParser::T__9)
        | (1ULL << qasmParser::T__10)
        | (1ULL << qasmParser::T__11)
        | (1ULL << qasmParser::T__12)
        | (1ULL << qasmParser::T__13)
        | (1ULL << qasmParser::T__16)
        | (1ULL << qasmParser::T__17)
        | (1ULL << qasmParser::T__18)
        | (1ULL << qasmParser::T__19)
        | (1ULL << qasmParser::T__20)
        | (1ULL << qasmParser::T__21)
        | (1ULL << qasmParser::T__22)
        | (1ULL << qasmParser::T__24)
        | (1ULL << qasmParser::T__25)
        | (1ULL << qasmParser::T__26)
        | (1ULL << qasmParser::T__27)
        | (1ULL << qasmParser::T__28)
        | (1ULL << qasmParser::T__43)
        | (1ULL << qasmParser::T__44)
        | (1ULL << qasmParser::T__45)
        | (1ULL << qasmParser::T__46)
        | (1ULL << qasmParser::T__47)
        | (1ULL << qasmParser::T__48)
        | (1ULL << qasmParser::T__49)
        | (1ULL << qasmParser::T__50)
        | (1ULL << qasmParser::T__51)
        | (1ULL << qasmParser::T__52)
        | (1ULL << qasmParser::T__53)
        | (1ULL << qasmParser::T__54)
        | (1ULL << qasmParser::T__55)
        | (1ULL << qasmParser::T__56))) != 0) || ((((_la - 70) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 70)) & ((1ULL << (qasmParser::T__69 - 70))
        | (1ULL << (qasmParser::T__71 - 70))
        | (1ULL << (qasmParser::T__73 - 70))
        | (1ULL << (qasmParser::T__74 - 70))
        | (1ULL << (qasmParser::T__75 - 70))
        | (1ULL << (qasmParser::T__76 - 70))
        | (1ULL << (qasmParser::T__77 - 70))
        | (1ULL << (qasmParser::T__81 - 70))
        | (1ULL << (qasmParser::T__82 - 70))
        | (1ULL << (qasmParser::T__83 - 70))
        | (1ULL << (qasmParser::T__84 - 70))
        | (1ULL << (qasmParser::T__85 - 70))
        | (1ULL << (qasmParser::T__86 - 70))
        | (1ULL << (qasmParser::LPAREN - 70))
        | (1ULL << (qasmParser::MINUS - 70))
        | (1ULL << (qasmParser::ImagNumber - 70))
        | (1ULL << (qasmParser::COMPLEX - 70))
        | (1ULL << (qasmParser::CONST - 70))
        | (1ULL << (qasmParser::ARRAY - 70))
        | (1ULL << (qasmParser::SIZEOF - 70))
        | (1ULL << (qasmParser::Constant - 70))
        | (1ULL << (qasmParser::Integer - 70))
        | (1ULL << (qasmParser::Identifier - 70))
        | (1ULL << (qasmParser::RealNumber - 70))
        | (1ULL << (qasmParser::TimingLiteral - 70))
        | (1ULL << (qasmParser::StringLiteral - 70)))) != 0)) {
        setState(949);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 91, _ctx)) {
        case 1: {
          setState(947);
          statement();
          break;
        }

        case 2: {
          setState(948);
          controlDirective();
          break;
        }

        default:
          break;
        }
        setState(953);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(954);
      match(qasmParser::RBRACE);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BranchingStatementContext ------------------------------------------------------------------

qasmParser::BranchingStatementContext::BranchingStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasmParser::BranchingStatementContext::LPAREN() {
  return getToken(qasmParser::LPAREN, 0);
}

qasmParser::ExpressionContext* qasmParser::BranchingStatementContext::expression() {
  return getRuleContext<qasmParser::ExpressionContext>(0);
}

tree::TerminalNode* qasmParser::BranchingStatementContext::RPAREN() {
  return getToken(qasmParser::RPAREN, 0);
}

std::vector<qasmParser::ProgramBlockContext *> qasmParser::BranchingStatementContext::programBlock() {
  return getRuleContexts<qasmParser::ProgramBlockContext>();
}

qasmParser::ProgramBlockContext* qasmParser::BranchingStatementContext::programBlock(size_t i) {
  return getRuleContext<qasmParser::ProgramBlockContext>(i);
}


size_t qasmParser::BranchingStatementContext::getRuleIndex() const {
  return qasmParser::RuleBranchingStatement;
}

void qasmParser::BranchingStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBranchingStatement(this);
}

void qasmParser::BranchingStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBranchingStatement(this);
}


antlrcpp::Any qasmParser::BranchingStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitBranchingStatement(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::BranchingStatementContext* qasmParser::branchingStatement() {
  BranchingStatementContext *_localctx = _tracker.createInstance<BranchingStatementContext>(_ctx, getState());
  enterRule(_localctx, 182, qasmParser::RuleBranchingStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(957);
    match(qasmParser::T__69);
    setState(958);
    match(qasmParser::LPAREN);
    setState(959);
    expression(0);
    setState(960);
    match(qasmParser::RPAREN);
    setState(961);
    programBlock();
    setState(964);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 94, _ctx)) {
    case 1: {
      setState(962);
      match(qasmParser::T__70);
      setState(963);
      programBlock();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LoopSignatureContext ------------------------------------------------------------------

qasmParser::LoopSignatureContext::LoopSignatureContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasmParser::LoopSignatureContext::Identifier() {
  return getToken(qasmParser::Identifier, 0);
}

qasmParser::SetDeclarationContext* qasmParser::LoopSignatureContext::setDeclaration() {
  return getRuleContext<qasmParser::SetDeclarationContext>(0);
}

tree::TerminalNode* qasmParser::LoopSignatureContext::LPAREN() {
  return getToken(qasmParser::LPAREN, 0);
}

qasmParser::ExpressionContext* qasmParser::LoopSignatureContext::expression() {
  return getRuleContext<qasmParser::ExpressionContext>(0);
}

tree::TerminalNode* qasmParser::LoopSignatureContext::RPAREN() {
  return getToken(qasmParser::RPAREN, 0);
}


size_t qasmParser::LoopSignatureContext::getRuleIndex() const {
  return qasmParser::RuleLoopSignature;
}

void qasmParser::LoopSignatureContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLoopSignature(this);
}

void qasmParser::LoopSignatureContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLoopSignature(this);
}


antlrcpp::Any qasmParser::LoopSignatureContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitLoopSignature(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::LoopSignatureContext* qasmParser::loopSignature() {
  LoopSignatureContext *_localctx = _tracker.createInstance<LoopSignatureContext>(_ctx, getState());
  enterRule(_localctx, 184, qasmParser::RuleLoopSignature);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(975);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasmParser::T__71: {
        enterOuterAlt(_localctx, 1);
        setState(966);
        match(qasmParser::T__71);
        setState(967);
        match(qasmParser::Identifier);
        setState(968);
        match(qasmParser::T__72);
        setState(969);
        setDeclaration();
        break;
      }

      case qasmParser::T__73: {
        enterOuterAlt(_localctx, 2);
        setState(970);
        match(qasmParser::T__73);
        setState(971);
        match(qasmParser::LPAREN);
        setState(972);
        expression(0);
        setState(973);
        match(qasmParser::RPAREN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LoopStatementContext ------------------------------------------------------------------

qasmParser::LoopStatementContext::LoopStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::LoopSignatureContext* qasmParser::LoopStatementContext::loopSignature() {
  return getRuleContext<qasmParser::LoopSignatureContext>(0);
}

qasmParser::ProgramBlockContext* qasmParser::LoopStatementContext::programBlock() {
  return getRuleContext<qasmParser::ProgramBlockContext>(0);
}


size_t qasmParser::LoopStatementContext::getRuleIndex() const {
  return qasmParser::RuleLoopStatement;
}

void qasmParser::LoopStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLoopStatement(this);
}

void qasmParser::LoopStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLoopStatement(this);
}


antlrcpp::Any qasmParser::LoopStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitLoopStatement(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::LoopStatementContext* qasmParser::loopStatement() {
  LoopStatementContext *_localctx = _tracker.createInstance<LoopStatementContext>(_ctx, getState());
  enterRule(_localctx, 186, qasmParser::RuleLoopStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(977);
    loopSignature();
    setState(978);
    programBlock();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EndStatementContext ------------------------------------------------------------------

qasmParser::EndStatementContext::EndStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasmParser::EndStatementContext::SEMICOLON() {
  return getToken(qasmParser::SEMICOLON, 0);
}


size_t qasmParser::EndStatementContext::getRuleIndex() const {
  return qasmParser::RuleEndStatement;
}

void qasmParser::EndStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEndStatement(this);
}

void qasmParser::EndStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEndStatement(this);
}


antlrcpp::Any qasmParser::EndStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitEndStatement(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::EndStatementContext* qasmParser::endStatement() {
  EndStatementContext *_localctx = _tracker.createInstance<EndStatementContext>(_ctx, getState());
  enterRule(_localctx, 188, qasmParser::RuleEndStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(980);
    match(qasmParser::T__74);
    setState(981);
    match(qasmParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStatementContext ------------------------------------------------------------------

qasmParser::ReturnStatementContext::ReturnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasmParser::ReturnStatementContext::SEMICOLON() {
  return getToken(qasmParser::SEMICOLON, 0);
}

qasmParser::ExpressionContext* qasmParser::ReturnStatementContext::expression() {
  return getRuleContext<qasmParser::ExpressionContext>(0);
}

qasmParser::QuantumMeasurementContext* qasmParser::ReturnStatementContext::quantumMeasurement() {
  return getRuleContext<qasmParser::QuantumMeasurementContext>(0);
}


size_t qasmParser::ReturnStatementContext::getRuleIndex() const {
  return qasmParser::RuleReturnStatement;
}

void qasmParser::ReturnStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStatement(this);
}

void qasmParser::ReturnStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStatement(this);
}


antlrcpp::Any qasmParser::ReturnStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitReturnStatement(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::ReturnStatementContext* qasmParser::returnStatement() {
  ReturnStatementContext *_localctx = _tracker.createInstance<ReturnStatementContext>(_ctx, getState());
  enterRule(_localctx, 190, qasmParser::RuleReturnStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(983);
    match(qasmParser::T__75);
    setState(986);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasmParser::T__6:
      case qasmParser::T__7:
      case qasmParser::T__8:
      case qasmParser::T__9:
      case qasmParser::T__10:
      case qasmParser::T__11:
      case qasmParser::T__12:
      case qasmParser::T__27:
      case qasmParser::T__28:
      case qasmParser::T__43:
      case qasmParser::T__44:
      case qasmParser::T__45:
      case qasmParser::T__46:
      case qasmParser::T__47:
      case qasmParser::T__48:
      case qasmParser::T__49:
      case qasmParser::T__50:
      case qasmParser::T__51:
      case qasmParser::T__52:
      case qasmParser::T__53:
      case qasmParser::T__54:
      case qasmParser::T__55:
      case qasmParser::T__56:
      case qasmParser::T__81:
      case qasmParser::T__82:
      case qasmParser::T__84:
      case qasmParser::LPAREN:
      case qasmParser::MINUS:
      case qasmParser::ImagNumber:
      case qasmParser::COMPLEX:
      case qasmParser::ARRAY:
      case qasmParser::SIZEOF:
      case qasmParser::Constant:
      case qasmParser::Integer:
      case qasmParser::Identifier:
      case qasmParser::RealNumber:
      case qasmParser::TimingLiteral:
      case qasmParser::StringLiteral: {
        setState(984);
        expression(0);
        break;
      }

      case qasmParser::T__20: {
        setState(985);
        quantumMeasurement();
        break;
      }

      case qasmParser::SEMICOLON: {
        break;
      }

    default:
      break;
    }
    setState(988);
    match(qasmParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ControlDirectiveContext ------------------------------------------------------------------

qasmParser::ControlDirectiveContext::ControlDirectiveContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasmParser::ControlDirectiveContext::SEMICOLON() {
  return getToken(qasmParser::SEMICOLON, 0);
}

qasmParser::EndStatementContext* qasmParser::ControlDirectiveContext::endStatement() {
  return getRuleContext<qasmParser::EndStatementContext>(0);
}

qasmParser::ReturnStatementContext* qasmParser::ControlDirectiveContext::returnStatement() {
  return getRuleContext<qasmParser::ReturnStatementContext>(0);
}


size_t qasmParser::ControlDirectiveContext::getRuleIndex() const {
  return qasmParser::RuleControlDirective;
}

void qasmParser::ControlDirectiveContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterControlDirective(this);
}

void qasmParser::ControlDirectiveContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitControlDirective(this);
}


antlrcpp::Any qasmParser::ControlDirectiveContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitControlDirective(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::ControlDirectiveContext* qasmParser::controlDirective() {
  ControlDirectiveContext *_localctx = _tracker.createInstance<ControlDirectiveContext>(_ctx, getState());
  enterRule(_localctx, 192, qasmParser::RuleControlDirective);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(994);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasmParser::T__76:
      case qasmParser::T__77: {
        enterOuterAlt(_localctx, 1);
        setState(990);
        _la = _input->LA(1);
        if (!(_la == qasmParser::T__76

        || _la == qasmParser::T__77)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(991);
        match(qasmParser::SEMICOLON);
        break;
      }

      case qasmParser::T__74: {
        enterOuterAlt(_localctx, 2);
        setState(992);
        endStatement();
        break;
      }

      case qasmParser::T__75: {
        enterOuterAlt(_localctx, 3);
        setState(993);
        returnStatement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExternDeclarationContext ------------------------------------------------------------------

qasmParser::ExternDeclarationContext::ExternDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasmParser::ExternDeclarationContext::Identifier() {
  return getToken(qasmParser::Identifier, 0);
}

tree::TerminalNode* qasmParser::ExternDeclarationContext::LPAREN() {
  return getToken(qasmParser::LPAREN, 0);
}

tree::TerminalNode* qasmParser::ExternDeclarationContext::RPAREN() {
  return getToken(qasmParser::RPAREN, 0);
}

tree::TerminalNode* qasmParser::ExternDeclarationContext::SEMICOLON() {
  return getToken(qasmParser::SEMICOLON, 0);
}

qasmParser::ClassicalTypeListContext* qasmParser::ExternDeclarationContext::classicalTypeList() {
  return getRuleContext<qasmParser::ClassicalTypeListContext>(0);
}

qasmParser::ReturnSignatureContext* qasmParser::ExternDeclarationContext::returnSignature() {
  return getRuleContext<qasmParser::ReturnSignatureContext>(0);
}


size_t qasmParser::ExternDeclarationContext::getRuleIndex() const {
  return qasmParser::RuleExternDeclaration;
}

void qasmParser::ExternDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExternDeclaration(this);
}

void qasmParser::ExternDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExternDeclaration(this);
}


antlrcpp::Any qasmParser::ExternDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitExternDeclaration(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::ExternDeclarationContext* qasmParser::externDeclaration() {
  ExternDeclarationContext *_localctx = _tracker.createInstance<ExternDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 194, qasmParser::RuleExternDeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(996);
    match(qasmParser::T__78);
    setState(997);
    match(qasmParser::Identifier);
    setState(998);
    match(qasmParser::LPAREN);
    setState(1000);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasmParser::T__6)
      | (1ULL << qasmParser::T__7)
      | (1ULL << qasmParser::T__8)
      | (1ULL << qasmParser::T__9)
      | (1ULL << qasmParser::T__10)
      | (1ULL << qasmParser::T__11)
      | (1ULL << qasmParser::T__12))) != 0) || ((((_la - 82) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 82)) & ((1ULL << (qasmParser::T__81 - 82))
      | (1ULL << (qasmParser::T__82 - 82))
      | (1ULL << (qasmParser::COMPLEX - 82))
      | (1ULL << (qasmParser::ARRAY - 82)))) != 0)) {
      setState(999);
      classicalTypeList();
    }
    setState(1002);
    match(qasmParser::RPAREN);
    setState(1004);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasmParser::ARROW) {
      setState(1003);
      returnSignature();
    }
    setState(1006);
    match(qasmParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExternOrSubroutineCallContext ------------------------------------------------------------------

qasmParser::ExternOrSubroutineCallContext::ExternOrSubroutineCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasmParser::ExternOrSubroutineCallContext::Identifier() {
  return getToken(qasmParser::Identifier, 0);
}

tree::TerminalNode* qasmParser::ExternOrSubroutineCallContext::LPAREN() {
  return getToken(qasmParser::LPAREN, 0);
}

tree::TerminalNode* qasmParser::ExternOrSubroutineCallContext::RPAREN() {
  return getToken(qasmParser::RPAREN, 0);
}

qasmParser::ExpressionListContext* qasmParser::ExternOrSubroutineCallContext::expressionList() {
  return getRuleContext<qasmParser::ExpressionListContext>(0);
}


size_t qasmParser::ExternOrSubroutineCallContext::getRuleIndex() const {
  return qasmParser::RuleExternOrSubroutineCall;
}

void qasmParser::ExternOrSubroutineCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExternOrSubroutineCall(this);
}

void qasmParser::ExternOrSubroutineCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExternOrSubroutineCall(this);
}


antlrcpp::Any qasmParser::ExternOrSubroutineCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitExternOrSubroutineCall(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::ExternOrSubroutineCallContext* qasmParser::externOrSubroutineCall() {
  ExternOrSubroutineCallContext *_localctx = _tracker.createInstance<ExternOrSubroutineCallContext>(_ctx, getState());
  enterRule(_localctx, 196, qasmParser::RuleExternOrSubroutineCall);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1008);
    match(qasmParser::Identifier);
    setState(1009);
    match(qasmParser::LPAREN);
    setState(1011);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasmParser::T__6)
      | (1ULL << qasmParser::T__7)
      | (1ULL << qasmParser::T__8)
      | (1ULL << qasmParser::T__9)
      | (1ULL << qasmParser::T__10)
      | (1ULL << qasmParser::T__11)
      | (1ULL << qasmParser::T__12)
      | (1ULL << qasmParser::T__27)
      | (1ULL << qasmParser::T__28)
      | (1ULL << qasmParser::T__43)
      | (1ULL << qasmParser::T__44)
      | (1ULL << qasmParser::T__45)
      | (1ULL << qasmParser::T__46)
      | (1ULL << qasmParser::T__47)
      | (1ULL << qasmParser::T__48)
      | (1ULL << qasmParser::T__49)
      | (1ULL << qasmParser::T__50)
      | (1ULL << qasmParser::T__51)
      | (1ULL << qasmParser::T__52)
      | (1ULL << qasmParser::T__53)
      | (1ULL << qasmParser::T__54)
      | (1ULL << qasmParser::T__55)
      | (1ULL << qasmParser::T__56))) != 0) || ((((_la - 82) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 82)) & ((1ULL << (qasmParser::T__81 - 82))
      | (1ULL << (qasmParser::T__82 - 82))
      | (1ULL << (qasmParser::T__84 - 82))
      | (1ULL << (qasmParser::LPAREN - 82))
      | (1ULL << (qasmParser::MINUS - 82))
      | (1ULL << (qasmParser::ImagNumber - 82))
      | (1ULL << (qasmParser::COMPLEX - 82))
      | (1ULL << (qasmParser::ARRAY - 82))
      | (1ULL << (qasmParser::SIZEOF - 82))
      | (1ULL << (qasmParser::Constant - 82))
      | (1ULL << (qasmParser::Integer - 82))
      | (1ULL << (qasmParser::Identifier - 82))
      | (1ULL << (qasmParser::RealNumber - 82))
      | (1ULL << (qasmParser::TimingLiteral - 82))
      | (1ULL << (qasmParser::StringLiteral - 82)))) != 0)) {
      setState(1010);
      expressionList();
    }
    setState(1013);
    match(qasmParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SubroutineDefinitionContext ------------------------------------------------------------------

qasmParser::SubroutineDefinitionContext::SubroutineDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasmParser::SubroutineDefinitionContext::Identifier() {
  return getToken(qasmParser::Identifier, 0);
}

tree::TerminalNode* qasmParser::SubroutineDefinitionContext::LPAREN() {
  return getToken(qasmParser::LPAREN, 0);
}

tree::TerminalNode* qasmParser::SubroutineDefinitionContext::RPAREN() {
  return getToken(qasmParser::RPAREN, 0);
}

qasmParser::SubroutineBlockContext* qasmParser::SubroutineDefinitionContext::subroutineBlock() {
  return getRuleContext<qasmParser::SubroutineBlockContext>(0);
}

qasmParser::AnyTypeArgumentListContext* qasmParser::SubroutineDefinitionContext::anyTypeArgumentList() {
  return getRuleContext<qasmParser::AnyTypeArgumentListContext>(0);
}

qasmParser::ReturnSignatureContext* qasmParser::SubroutineDefinitionContext::returnSignature() {
  return getRuleContext<qasmParser::ReturnSignatureContext>(0);
}


size_t qasmParser::SubroutineDefinitionContext::getRuleIndex() const {
  return qasmParser::RuleSubroutineDefinition;
}

void qasmParser::SubroutineDefinitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubroutineDefinition(this);
}

void qasmParser::SubroutineDefinitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubroutineDefinition(this);
}


antlrcpp::Any qasmParser::SubroutineDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitSubroutineDefinition(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::SubroutineDefinitionContext* qasmParser::subroutineDefinition() {
  SubroutineDefinitionContext *_localctx = _tracker.createInstance<SubroutineDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 198, qasmParser::RuleSubroutineDefinition);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1015);
    match(qasmParser::T__79);
    setState(1016);
    match(qasmParser::Identifier);
    setState(1017);
    match(qasmParser::LPAREN);
    setState(1019);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasmParser::T__4)
      | (1ULL << qasmParser::T__5)
      | (1ULL << qasmParser::T__6)
      | (1ULL << qasmParser::T__7)
      | (1ULL << qasmParser::T__8)
      | (1ULL << qasmParser::T__9)
      | (1ULL << qasmParser::T__10)
      | (1ULL << qasmParser::T__11)
      | (1ULL << qasmParser::T__12))) != 0) || ((((_la - 82) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 82)) & ((1ULL << (qasmParser::T__81 - 82))
      | (1ULL << (qasmParser::T__82 - 82))
      | (1ULL << (qasmParser::COMPLEX - 82))
      | (1ULL << (qasmParser::CONST - 82))
      | (1ULL << (qasmParser::MUTABLE - 82)))) != 0)) {
      setState(1018);
      anyTypeArgumentList();
    }
    setState(1021);
    match(qasmParser::RPAREN);
    setState(1023);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasmParser::ARROW) {
      setState(1022);
      returnSignature();
    }
    setState(1025);
    subroutineBlock();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SubroutineBlockContext ------------------------------------------------------------------

qasmParser::SubroutineBlockContext::SubroutineBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasmParser::SubroutineBlockContext::LBRACE() {
  return getToken(qasmParser::LBRACE, 0);
}

tree::TerminalNode* qasmParser::SubroutineBlockContext::RBRACE() {
  return getToken(qasmParser::RBRACE, 0);
}

std::vector<qasmParser::StatementContext *> qasmParser::SubroutineBlockContext::statement() {
  return getRuleContexts<qasmParser::StatementContext>();
}

qasmParser::StatementContext* qasmParser::SubroutineBlockContext::statement(size_t i) {
  return getRuleContext<qasmParser::StatementContext>(i);
}

qasmParser::ReturnStatementContext* qasmParser::SubroutineBlockContext::returnStatement() {
  return getRuleContext<qasmParser::ReturnStatementContext>(0);
}


size_t qasmParser::SubroutineBlockContext::getRuleIndex() const {
  return qasmParser::RuleSubroutineBlock;
}

void qasmParser::SubroutineBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubroutineBlock(this);
}

void qasmParser::SubroutineBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubroutineBlock(this);
}


antlrcpp::Any qasmParser::SubroutineBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitSubroutineBlock(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::SubroutineBlockContext* qasmParser::subroutineBlock() {
  SubroutineBlockContext *_localctx = _tracker.createInstance<SubroutineBlockContext>(_ctx, getState());
  enterRule(_localctx, 200, qasmParser::RuleSubroutineBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1027);
    match(qasmParser::LBRACE);
    setState(1031);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasmParser::T__6)
      | (1ULL << qasmParser::T__7)
      | (1ULL << qasmParser::T__8)
      | (1ULL << qasmParser::T__9)
      | (1ULL << qasmParser::T__10)
      | (1ULL << qasmParser::T__11)
      | (1ULL << qasmParser::T__12)
      | (1ULL << qasmParser::T__13)
      | (1ULL << qasmParser::T__16)
      | (1ULL << qasmParser::T__17)
      | (1ULL << qasmParser::T__18)
      | (1ULL << qasmParser::T__19)
      | (1ULL << qasmParser::T__20)
      | (1ULL << qasmParser::T__21)
      | (1ULL << qasmParser::T__22)
      | (1ULL << qasmParser::T__24)
      | (1ULL << qasmParser::T__25)
      | (1ULL << qasmParser::T__26)
      | (1ULL << qasmParser::T__27)
      | (1ULL << qasmParser::T__28)
      | (1ULL << qasmParser::T__43)
      | (1ULL << qasmParser::T__44)
      | (1ULL << qasmParser::T__45)
      | (1ULL << qasmParser::T__46)
      | (1ULL << qasmParser::T__47)
      | (1ULL << qasmParser::T__48)
      | (1ULL << qasmParser::T__49)
      | (1ULL << qasmParser::T__50)
      | (1ULL << qasmParser::T__51)
      | (1ULL << qasmParser::T__52)
      | (1ULL << qasmParser::T__53)
      | (1ULL << qasmParser::T__54)
      | (1ULL << qasmParser::T__55)
      | (1ULL << qasmParser::T__56))) != 0) || ((((_la - 70) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 70)) & ((1ULL << (qasmParser::T__69 - 70))
      | (1ULL << (qasmParser::T__71 - 70))
      | (1ULL << (qasmParser::T__73 - 70))
      | (1ULL << (qasmParser::T__74 - 70))
      | (1ULL << (qasmParser::T__81 - 70))
      | (1ULL << (qasmParser::T__82 - 70))
      | (1ULL << (qasmParser::T__83 - 70))
      | (1ULL << (qasmParser::T__84 - 70))
      | (1ULL << (qasmParser::T__85 - 70))
      | (1ULL << (qasmParser::T__86 - 70))
      | (1ULL << (qasmParser::LPAREN - 70))
      | (1ULL << (qasmParser::MINUS - 70))
      | (1ULL << (qasmParser::ImagNumber - 70))
      | (1ULL << (qasmParser::COMPLEX - 70))
      | (1ULL << (qasmParser::CONST - 70))
      | (1ULL << (qasmParser::ARRAY - 70))
      | (1ULL << (qasmParser::SIZEOF - 70))
      | (1ULL << (qasmParser::Constant - 70))
      | (1ULL << (qasmParser::Integer - 70))
      | (1ULL << (qasmParser::Identifier - 70))
      | (1ULL << (qasmParser::RealNumber - 70))
      | (1ULL << (qasmParser::TimingLiteral - 70))
      | (1ULL << (qasmParser::StringLiteral - 70)))) != 0)) {
      setState(1028);
      statement();
      setState(1033);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1035);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasmParser::T__75) {
      setState(1034);
      returnStatement();
    }
    setState(1037);
    match(qasmParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PragmaContext ------------------------------------------------------------------

qasmParser::PragmaContext::PragmaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasmParser::PragmaContext::LBRACE() {
  return getToken(qasmParser::LBRACE, 0);
}

tree::TerminalNode* qasmParser::PragmaContext::RBRACE() {
  return getToken(qasmParser::RBRACE, 0);
}

std::vector<qasmParser::StatementContext *> qasmParser::PragmaContext::statement() {
  return getRuleContexts<qasmParser::StatementContext>();
}

qasmParser::StatementContext* qasmParser::PragmaContext::statement(size_t i) {
  return getRuleContext<qasmParser::StatementContext>(i);
}


size_t qasmParser::PragmaContext::getRuleIndex() const {
  return qasmParser::RulePragma;
}

void qasmParser::PragmaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPragma(this);
}

void qasmParser::PragmaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPragma(this);
}


antlrcpp::Any qasmParser::PragmaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitPragma(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::PragmaContext* qasmParser::pragma() {
  PragmaContext *_localctx = _tracker.createInstance<PragmaContext>(_ctx, getState());
  enterRule(_localctx, 202, qasmParser::RulePragma);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1039);
    match(qasmParser::T__80);
    setState(1040);
    match(qasmParser::LBRACE);
    setState(1044);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasmParser::T__6)
      | (1ULL << qasmParser::T__7)
      | (1ULL << qasmParser::T__8)
      | (1ULL << qasmParser::T__9)
      | (1ULL << qasmParser::T__10)
      | (1ULL << qasmParser::T__11)
      | (1ULL << qasmParser::T__12)
      | (1ULL << qasmParser::T__13)
      | (1ULL << qasmParser::T__16)
      | (1ULL << qasmParser::T__17)
      | (1ULL << qasmParser::T__18)
      | (1ULL << qasmParser::T__19)
      | (1ULL << qasmParser::T__20)
      | (1ULL << qasmParser::T__21)
      | (1ULL << qasmParser::T__22)
      | (1ULL << qasmParser::T__24)
      | (1ULL << qasmParser::T__25)
      | (1ULL << qasmParser::T__26)
      | (1ULL << qasmParser::T__27)
      | (1ULL << qasmParser::T__28)
      | (1ULL << qasmParser::T__43)
      | (1ULL << qasmParser::T__44)
      | (1ULL << qasmParser::T__45)
      | (1ULL << qasmParser::T__46)
      | (1ULL << qasmParser::T__47)
      | (1ULL << qasmParser::T__48)
      | (1ULL << qasmParser::T__49)
      | (1ULL << qasmParser::T__50)
      | (1ULL << qasmParser::T__51)
      | (1ULL << qasmParser::T__52)
      | (1ULL << qasmParser::T__53)
      | (1ULL << qasmParser::T__54)
      | (1ULL << qasmParser::T__55)
      | (1ULL << qasmParser::T__56))) != 0) || ((((_la - 70) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 70)) & ((1ULL << (qasmParser::T__69 - 70))
      | (1ULL << (qasmParser::T__71 - 70))
      | (1ULL << (qasmParser::T__73 - 70))
      | (1ULL << (qasmParser::T__74 - 70))
      | (1ULL << (qasmParser::T__81 - 70))
      | (1ULL << (qasmParser::T__82 - 70))
      | (1ULL << (qasmParser::T__83 - 70))
      | (1ULL << (qasmParser::T__84 - 70))
      | (1ULL << (qasmParser::T__85 - 70))
      | (1ULL << (qasmParser::T__86 - 70))
      | (1ULL << (qasmParser::LPAREN - 70))
      | (1ULL << (qasmParser::MINUS - 70))
      | (1ULL << (qasmParser::ImagNumber - 70))
      | (1ULL << (qasmParser::COMPLEX - 70))
      | (1ULL << (qasmParser::CONST - 70))
      | (1ULL << (qasmParser::ARRAY - 70))
      | (1ULL << (qasmParser::SIZEOF - 70))
      | (1ULL << (qasmParser::Constant - 70))
      | (1ULL << (qasmParser::Integer - 70))
      | (1ULL << (qasmParser::Identifier - 70))
      | (1ULL << (qasmParser::RealNumber - 70))
      | (1ULL << (qasmParser::TimingLiteral - 70))
      | (1ULL << (qasmParser::StringLiteral - 70)))) != 0)) {
      setState(1041);
      statement();
      setState(1046);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1047);
    match(qasmParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TimingTypeContext ------------------------------------------------------------------

qasmParser::TimingTypeContext::TimingTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t qasmParser::TimingTypeContext::getRuleIndex() const {
  return qasmParser::RuleTimingType;
}

void qasmParser::TimingTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTimingType(this);
}

void qasmParser::TimingTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTimingType(this);
}


antlrcpp::Any qasmParser::TimingTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitTimingType(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::TimingTypeContext* qasmParser::timingType() {
  TimingTypeContext *_localctx = _tracker.createInstance<TimingTypeContext>(_ctx, getState());
  enterRule(_localctx, 204, qasmParser::RuleTimingType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1049);
    _la = _input->LA(1);
    if (!(_la == qasmParser::T__81

    || _la == qasmParser::T__82)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TimingBoxContext ------------------------------------------------------------------

qasmParser::TimingBoxContext::TimingBoxContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::QuantumBlockContext* qasmParser::TimingBoxContext::quantumBlock() {
  return getRuleContext<qasmParser::QuantumBlockContext>(0);
}

qasmParser::DesignatorContext* qasmParser::TimingBoxContext::designator() {
  return getRuleContext<qasmParser::DesignatorContext>(0);
}


size_t qasmParser::TimingBoxContext::getRuleIndex() const {
  return qasmParser::RuleTimingBox;
}

void qasmParser::TimingBoxContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTimingBox(this);
}

void qasmParser::TimingBoxContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTimingBox(this);
}


antlrcpp::Any qasmParser::TimingBoxContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitTimingBox(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::TimingBoxContext* qasmParser::timingBox() {
  TimingBoxContext *_localctx = _tracker.createInstance<TimingBoxContext>(_ctx, getState());
  enterRule(_localctx, 206, qasmParser::RuleTimingBox);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1051);
    match(qasmParser::T__83);
    setState(1053);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasmParser::LBRACKET) {
      setState(1052);
      designator();
    }
    setState(1055);
    quantumBlock();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TimingIdentifierContext ------------------------------------------------------------------

qasmParser::TimingIdentifierContext::TimingIdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasmParser::TimingIdentifierContext::TimingLiteral() {
  return getToken(qasmParser::TimingLiteral, 0);
}

tree::TerminalNode* qasmParser::TimingIdentifierContext::LPAREN() {
  return getToken(qasmParser::LPAREN, 0);
}

tree::TerminalNode* qasmParser::TimingIdentifierContext::RPAREN() {
  return getToken(qasmParser::RPAREN, 0);
}

tree::TerminalNode* qasmParser::TimingIdentifierContext::Identifier() {
  return getToken(qasmParser::Identifier, 0);
}

qasmParser::QuantumBlockContext* qasmParser::TimingIdentifierContext::quantumBlock() {
  return getRuleContext<qasmParser::QuantumBlockContext>(0);
}


size_t qasmParser::TimingIdentifierContext::getRuleIndex() const {
  return qasmParser::RuleTimingIdentifier;
}

void qasmParser::TimingIdentifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTimingIdentifier(this);
}

void qasmParser::TimingIdentifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTimingIdentifier(this);
}


antlrcpp::Any qasmParser::TimingIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitTimingIdentifier(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::TimingIdentifierContext* qasmParser::timingIdentifier() {
  TimingIdentifierContext *_localctx = _tracker.createInstance<TimingIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 208, qasmParser::RuleTimingIdentifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1065);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasmParser::TimingLiteral: {
        enterOuterAlt(_localctx, 1);
        setState(1057);
        match(qasmParser::TimingLiteral);
        break;
      }

      case qasmParser::T__84: {
        enterOuterAlt(_localctx, 2);
        setState(1058);
        match(qasmParser::T__84);
        setState(1059);
        match(qasmParser::LPAREN);
        setState(1062);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case qasmParser::Identifier: {
            setState(1060);
            match(qasmParser::Identifier);
            break;
          }

          case qasmParser::LBRACE: {
            setState(1061);
            quantumBlock();
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(1064);
        match(qasmParser::RPAREN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TimingInstructionNameContext ------------------------------------------------------------------

qasmParser::TimingInstructionNameContext::TimingInstructionNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t qasmParser::TimingInstructionNameContext::getRuleIndex() const {
  return qasmParser::RuleTimingInstructionName;
}

void qasmParser::TimingInstructionNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTimingInstructionName(this);
}

void qasmParser::TimingInstructionNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTimingInstructionName(this);
}


antlrcpp::Any qasmParser::TimingInstructionNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitTimingInstructionName(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::TimingInstructionNameContext* qasmParser::timingInstructionName() {
  TimingInstructionNameContext *_localctx = _tracker.createInstance<TimingInstructionNameContext>(_ctx, getState());
  enterRule(_localctx, 210, qasmParser::RuleTimingInstructionName);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1067);
    _la = _input->LA(1);
    if (!(_la == qasmParser::T__85

    || _la == qasmParser::T__86)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TimingInstructionContext ------------------------------------------------------------------

qasmParser::TimingInstructionContext::TimingInstructionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::TimingInstructionNameContext* qasmParser::TimingInstructionContext::timingInstructionName() {
  return getRuleContext<qasmParser::TimingInstructionNameContext>(0);
}

qasmParser::DesignatorContext* qasmParser::TimingInstructionContext::designator() {
  return getRuleContext<qasmParser::DesignatorContext>(0);
}

std::vector<qasmParser::IndexedIdentifierContext *> qasmParser::TimingInstructionContext::indexedIdentifier() {
  return getRuleContexts<qasmParser::IndexedIdentifierContext>();
}

qasmParser::IndexedIdentifierContext* qasmParser::TimingInstructionContext::indexedIdentifier(size_t i) {
  return getRuleContext<qasmParser::IndexedIdentifierContext>(i);
}

tree::TerminalNode* qasmParser::TimingInstructionContext::LPAREN() {
  return getToken(qasmParser::LPAREN, 0);
}

tree::TerminalNode* qasmParser::TimingInstructionContext::RPAREN() {
  return getToken(qasmParser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> qasmParser::TimingInstructionContext::COMMA() {
  return getTokens(qasmParser::COMMA);
}

tree::TerminalNode* qasmParser::TimingInstructionContext::COMMA(size_t i) {
  return getToken(qasmParser::COMMA, i);
}

qasmParser::ExpressionListContext* qasmParser::TimingInstructionContext::expressionList() {
  return getRuleContext<qasmParser::ExpressionListContext>(0);
}


size_t qasmParser::TimingInstructionContext::getRuleIndex() const {
  return qasmParser::RuleTimingInstruction;
}

void qasmParser::TimingInstructionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTimingInstruction(this);
}

void qasmParser::TimingInstructionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTimingInstruction(this);
}


antlrcpp::Any qasmParser::TimingInstructionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitTimingInstruction(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::TimingInstructionContext* qasmParser::timingInstruction() {
  TimingInstructionContext *_localctx = _tracker.createInstance<TimingInstructionContext>(_ctx, getState());
  enterRule(_localctx, 212, qasmParser::RuleTimingInstruction);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1069);
    timingInstructionName();
    setState(1075);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasmParser::LPAREN) {
      setState(1070);
      match(qasmParser::LPAREN);
      setState(1072);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << qasmParser::T__6)
        | (1ULL << qasmParser::T__7)
        | (1ULL << qasmParser::T__8)
        | (1ULL << qasmParser::T__9)
        | (1ULL << qasmParser::T__10)
        | (1ULL << qasmParser::T__11)
        | (1ULL << qasmParser::T__12)
        | (1ULL << qasmParser::T__27)
        | (1ULL << qasmParser::T__28)
        | (1ULL << qasmParser::T__43)
        | (1ULL << qasmParser::T__44)
        | (1ULL << qasmParser::T__45)
        | (1ULL << qasmParser::T__46)
        | (1ULL << qasmParser::T__47)
        | (1ULL << qasmParser::T__48)
        | (1ULL << qasmParser::T__49)
        | (1ULL << qasmParser::T__50)
        | (1ULL << qasmParser::T__51)
        | (1ULL << qasmParser::T__52)
        | (1ULL << qasmParser::T__53)
        | (1ULL << qasmParser::T__54)
        | (1ULL << qasmParser::T__55)
        | (1ULL << qasmParser::T__56))) != 0) || ((((_la - 82) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 82)) & ((1ULL << (qasmParser::T__81 - 82))
        | (1ULL << (qasmParser::T__82 - 82))
        | (1ULL << (qasmParser::T__84 - 82))
        | (1ULL << (qasmParser::LPAREN - 82))
        | (1ULL << (qasmParser::MINUS - 82))
        | (1ULL << (qasmParser::ImagNumber - 82))
        | (1ULL << (qasmParser::COMPLEX - 82))
        | (1ULL << (qasmParser::ARRAY - 82))
        | (1ULL << (qasmParser::SIZEOF - 82))
        | (1ULL << (qasmParser::Constant - 82))
        | (1ULL << (qasmParser::Integer - 82))
        | (1ULL << (qasmParser::Identifier - 82))
        | (1ULL << (qasmParser::RealNumber - 82))
        | (1ULL << (qasmParser::TimingLiteral - 82))
        | (1ULL << (qasmParser::StringLiteral - 82)))) != 0)) {
        setState(1071);
        expressionList();
      }
      setState(1074);
      match(qasmParser::RPAREN);
    }
    setState(1077);
    designator();
    setState(1078);
    indexedIdentifier();
    setState(1083);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == qasmParser::COMMA) {
      setState(1079);
      match(qasmParser::COMMA);
      setState(1080);
      indexedIdentifier();
      setState(1085);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TimingStatementContext ------------------------------------------------------------------

qasmParser::TimingStatementContext::TimingStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::TimingInstructionContext* qasmParser::TimingStatementContext::timingInstruction() {
  return getRuleContext<qasmParser::TimingInstructionContext>(0);
}

tree::TerminalNode* qasmParser::TimingStatementContext::SEMICOLON() {
  return getToken(qasmParser::SEMICOLON, 0);
}

qasmParser::TimingBoxContext* qasmParser::TimingStatementContext::timingBox() {
  return getRuleContext<qasmParser::TimingBoxContext>(0);
}


size_t qasmParser::TimingStatementContext::getRuleIndex() const {
  return qasmParser::RuleTimingStatement;
}

void qasmParser::TimingStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTimingStatement(this);
}

void qasmParser::TimingStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTimingStatement(this);
}


antlrcpp::Any qasmParser::TimingStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitTimingStatement(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::TimingStatementContext* qasmParser::timingStatement() {
  TimingStatementContext *_localctx = _tracker.createInstance<TimingStatementContext>(_ctx, getState());
  enterRule(_localctx, 214, qasmParser::RuleTimingStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1090);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasmParser::T__85:
      case qasmParser::T__86: {
        enterOuterAlt(_localctx, 1);
        setState(1086);
        timingInstruction();
        setState(1087);
        match(qasmParser::SEMICOLON);
        break;
      }

      case qasmParser::T__83: {
        enterOuterAlt(_localctx, 2);
        setState(1089);
        timingBox();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CalibrationContext ------------------------------------------------------------------

qasmParser::CalibrationContext::CalibrationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::CalibrationGrammarDeclarationContext* qasmParser::CalibrationContext::calibrationGrammarDeclaration() {
  return getRuleContext<qasmParser::CalibrationGrammarDeclarationContext>(0);
}

qasmParser::CalibrationDefinitionContext* qasmParser::CalibrationContext::calibrationDefinition() {
  return getRuleContext<qasmParser::CalibrationDefinitionContext>(0);
}


size_t qasmParser::CalibrationContext::getRuleIndex() const {
  return qasmParser::RuleCalibration;
}

void qasmParser::CalibrationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCalibration(this);
}

void qasmParser::CalibrationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCalibration(this);
}


antlrcpp::Any qasmParser::CalibrationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitCalibration(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::CalibrationContext* qasmParser::calibration() {
  CalibrationContext *_localctx = _tracker.createInstance<CalibrationContext>(_ctx, getState());
  enterRule(_localctx, 216, qasmParser::RuleCalibration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1094);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasmParser::T__87: {
        enterOuterAlt(_localctx, 1);
        setState(1092);
        calibrationGrammarDeclaration();
        break;
      }

      case qasmParser::T__88: {
        enterOuterAlt(_localctx, 2);
        setState(1093);
        calibrationDefinition();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CalibrationGrammarDeclarationContext ------------------------------------------------------------------

qasmParser::CalibrationGrammarDeclarationContext::CalibrationGrammarDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::CalibrationGrammarContext* qasmParser::CalibrationGrammarDeclarationContext::calibrationGrammar() {
  return getRuleContext<qasmParser::CalibrationGrammarContext>(0);
}

tree::TerminalNode* qasmParser::CalibrationGrammarDeclarationContext::SEMICOLON() {
  return getToken(qasmParser::SEMICOLON, 0);
}


size_t qasmParser::CalibrationGrammarDeclarationContext::getRuleIndex() const {
  return qasmParser::RuleCalibrationGrammarDeclaration;
}

void qasmParser::CalibrationGrammarDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCalibrationGrammarDeclaration(this);
}

void qasmParser::CalibrationGrammarDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCalibrationGrammarDeclaration(this);
}


antlrcpp::Any qasmParser::CalibrationGrammarDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitCalibrationGrammarDeclaration(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::CalibrationGrammarDeclarationContext* qasmParser::calibrationGrammarDeclaration() {
  CalibrationGrammarDeclarationContext *_localctx = _tracker.createInstance<CalibrationGrammarDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 218, qasmParser::RuleCalibrationGrammarDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1096);
    match(qasmParser::T__87);
    setState(1097);
    calibrationGrammar();
    setState(1098);
    match(qasmParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CalibrationDefinitionContext ------------------------------------------------------------------

qasmParser::CalibrationDefinitionContext::CalibrationDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasmParser::CalibrationDefinitionContext::Identifier() {
  return getToken(qasmParser::Identifier, 0);
}

qasmParser::IdentifierListContext* qasmParser::CalibrationDefinitionContext::identifierList() {
  return getRuleContext<qasmParser::IdentifierListContext>(0);
}

tree::TerminalNode* qasmParser::CalibrationDefinitionContext::LBRACE() {
  return getToken(qasmParser::LBRACE, 0);
}

tree::TerminalNode* qasmParser::CalibrationDefinitionContext::RBRACE() {
  return getToken(qasmParser::RBRACE, 0);
}

tree::TerminalNode* qasmParser::CalibrationDefinitionContext::LPAREN() {
  return getToken(qasmParser::LPAREN, 0);
}

tree::TerminalNode* qasmParser::CalibrationDefinitionContext::RPAREN() {
  return getToken(qasmParser::RPAREN, 0);
}

qasmParser::ReturnSignatureContext* qasmParser::CalibrationDefinitionContext::returnSignature() {
  return getRuleContext<qasmParser::ReturnSignatureContext>(0);
}

qasmParser::CalibrationArgumentListContext* qasmParser::CalibrationDefinitionContext::calibrationArgumentList() {
  return getRuleContext<qasmParser::CalibrationArgumentListContext>(0);
}


size_t qasmParser::CalibrationDefinitionContext::getRuleIndex() const {
  return qasmParser::RuleCalibrationDefinition;
}

void qasmParser::CalibrationDefinitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCalibrationDefinition(this);
}

void qasmParser::CalibrationDefinitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCalibrationDefinition(this);
}


antlrcpp::Any qasmParser::CalibrationDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitCalibrationDefinition(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::CalibrationDefinitionContext* qasmParser::calibrationDefinition() {
  CalibrationDefinitionContext *_localctx = _tracker.createInstance<CalibrationDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 220, qasmParser::RuleCalibrationDefinition);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1100);
    match(qasmParser::T__88);
    setState(1101);
    match(qasmParser::Identifier);
    setState(1107);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasmParser::LPAREN) {
      setState(1102);
      match(qasmParser::LPAREN);
      setState(1104);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << qasmParser::T__6)
        | (1ULL << qasmParser::T__7)
        | (1ULL << qasmParser::T__8)
        | (1ULL << qasmParser::T__9)
        | (1ULL << qasmParser::T__10)
        | (1ULL << qasmParser::T__11)
        | (1ULL << qasmParser::T__12)
        | (1ULL << qasmParser::T__27)
        | (1ULL << qasmParser::T__28)
        | (1ULL << qasmParser::T__43)
        | (1ULL << qasmParser::T__44)
        | (1ULL << qasmParser::T__45)
        | (1ULL << qasmParser::T__46)
        | (1ULL << qasmParser::T__47)
        | (1ULL << qasmParser::T__48)
        | (1ULL << qasmParser::T__49)
        | (1ULL << qasmParser::T__50)
        | (1ULL << qasmParser::T__51)
        | (1ULL << qasmParser::T__52)
        | (1ULL << qasmParser::T__53)
        | (1ULL << qasmParser::T__54)
        | (1ULL << qasmParser::T__55)
        | (1ULL << qasmParser::T__56))) != 0) || ((((_la - 82) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 82)) & ((1ULL << (qasmParser::T__81 - 82))
        | (1ULL << (qasmParser::T__82 - 82))
        | (1ULL << (qasmParser::T__84 - 82))
        | (1ULL << (qasmParser::LPAREN - 82))
        | (1ULL << (qasmParser::MINUS - 82))
        | (1ULL << (qasmParser::ImagNumber - 82))
        | (1ULL << (qasmParser::COMPLEX - 82))
        | (1ULL << (qasmParser::CONST - 82))
        | (1ULL << (qasmParser::MUTABLE - 82))
        | (1ULL << (qasmParser::ARRAY - 82))
        | (1ULL << (qasmParser::SIZEOF - 82))
        | (1ULL << (qasmParser::Constant - 82))
        | (1ULL << (qasmParser::Integer - 82))
        | (1ULL << (qasmParser::Identifier - 82))
        | (1ULL << (qasmParser::RealNumber - 82))
        | (1ULL << (qasmParser::TimingLiteral - 82))
        | (1ULL << (qasmParser::StringLiteral - 82)))) != 0)) {
        setState(1103);
        calibrationArgumentList();
      }
      setState(1106);
      match(qasmParser::RPAREN);
    }
    setState(1109);
    identifierList();
    setState(1111);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasmParser::ARROW) {
      setState(1110);
      returnSignature();
    }
    setState(1113);
    match(qasmParser::LBRACE);
    setState(1117);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 117, _ctx);
    while (alt != 1 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1 + 1) {
        setState(1114);
        matchWildcard(); 
      }
      setState(1119);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 117, _ctx);
    }
    setState(1120);
    match(qasmParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CalibrationGrammarContext ------------------------------------------------------------------

qasmParser::CalibrationGrammarContext::CalibrationGrammarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasmParser::CalibrationGrammarContext::StringLiteral() {
  return getToken(qasmParser::StringLiteral, 0);
}


size_t qasmParser::CalibrationGrammarContext::getRuleIndex() const {
  return qasmParser::RuleCalibrationGrammar;
}

void qasmParser::CalibrationGrammarContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCalibrationGrammar(this);
}

void qasmParser::CalibrationGrammarContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCalibrationGrammar(this);
}


antlrcpp::Any qasmParser::CalibrationGrammarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitCalibrationGrammar(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::CalibrationGrammarContext* qasmParser::calibrationGrammar() {
  CalibrationGrammarContext *_localctx = _tracker.createInstance<CalibrationGrammarContext>(_ctx, getState());
  enterRule(_localctx, 222, qasmParser::RuleCalibrationGrammar);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1122);
    _la = _input->LA(1);
    if (!(_la == qasmParser::T__89

    || _la == qasmParser::StringLiteral)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CalibrationArgumentListContext ------------------------------------------------------------------

qasmParser::CalibrationArgumentListContext::CalibrationArgumentListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasmParser::ClassicalArgumentListContext* qasmParser::CalibrationArgumentListContext::classicalArgumentList() {
  return getRuleContext<qasmParser::ClassicalArgumentListContext>(0);
}

qasmParser::ExpressionListContext* qasmParser::CalibrationArgumentListContext::expressionList() {
  return getRuleContext<qasmParser::ExpressionListContext>(0);
}


size_t qasmParser::CalibrationArgumentListContext::getRuleIndex() const {
  return qasmParser::RuleCalibrationArgumentList;
}

void qasmParser::CalibrationArgumentListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCalibrationArgumentList(this);
}

void qasmParser::CalibrationArgumentListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<qasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCalibrationArgumentList(this);
}


antlrcpp::Any qasmParser::CalibrationArgumentListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasmVisitor*>(visitor))
    return parserVisitor->visitCalibrationArgumentList(this);
  else
    return visitor->visitChildren(this);
}

qasmParser::CalibrationArgumentListContext* qasmParser::calibrationArgumentList() {
  CalibrationArgumentListContext *_localctx = _tracker.createInstance<CalibrationArgumentListContext>(_ctx, getState());
  enterRule(_localctx, 224, qasmParser::RuleCalibrationArgumentList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1126);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 118, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1124);
      classicalArgumentList();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1125);
      expressionList();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool qasmParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 41: return aliasInitializerSempred(dynamic_cast<AliasInitializerContext *>(context), predicateIndex);
    case 65: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);
    case 66: return logicalAndExpressionSempred(dynamic_cast<LogicalAndExpressionContext *>(context), predicateIndex);
    case 67: return bitOrExpressionSempred(dynamic_cast<BitOrExpressionContext *>(context), predicateIndex);
    case 68: return xOrExpressionSempred(dynamic_cast<XOrExpressionContext *>(context), predicateIndex);
    case 69: return bitAndExpressionSempred(dynamic_cast<BitAndExpressionContext *>(context), predicateIndex);
    case 70: return equalityExpressionSempred(dynamic_cast<EqualityExpressionContext *>(context), predicateIndex);
    case 71: return comparisonExpressionSempred(dynamic_cast<ComparisonExpressionContext *>(context), predicateIndex);
    case 72: return bitShiftExpressionSempred(dynamic_cast<BitShiftExpressionContext *>(context), predicateIndex);
    case 73: return additiveExpressionSempred(dynamic_cast<AdditiveExpressionContext *>(context), predicateIndex);
    case 74: return multiplicativeExpressionSempred(dynamic_cast<MultiplicativeExpressionContext *>(context), predicateIndex);
    case 76: return powerExpressionSempred(dynamic_cast<PowerExpressionContext *>(context), predicateIndex);
    case 78: return indexExpressionSempred(dynamic_cast<IndexExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool qasmParser::aliasInitializerSempred(AliasInitializerContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool qasmParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool qasmParser::logicalAndExpressionSempred(LogicalAndExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool qasmParser::bitOrExpressionSempred(BitOrExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool qasmParser::xOrExpressionSempred(XOrExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool qasmParser::bitAndExpressionSempred(BitAndExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 5: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool qasmParser::equalityExpressionSempred(EqualityExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 6: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool qasmParser::comparisonExpressionSempred(ComparisonExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 7: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool qasmParser::bitShiftExpressionSempred(BitShiftExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 8: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool qasmParser::additiveExpressionSempred(AdditiveExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 9: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool qasmParser::multiplicativeExpressionSempred(MultiplicativeExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 10: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool qasmParser::powerExpressionSempred(PowerExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 11: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool qasmParser::indexExpressionSempred(IndexExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 12: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> qasmParser::_decisionToDFA;
atn::PredictionContextCache qasmParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN qasmParser::_atn;
std::vector<uint16_t> qasmParser::_serializedATN;

std::vector<std::string> qasmParser::_ruleNames = {
  "program", "header", "version", "include", "ioIdentifier", "io", "globalStatement", 
  "statement", "quantumDeclarationStatement", "classicalDeclarationStatement", 
  "classicalAssignment", "assignmentStatement", "returnSignature", "designator", 
  "identifierList", "quantumDeclaration", "quantumArgument", "quantumArgumentList", 
  "bitType", "singleDesignatorType", "noDesignatorType", "nonArrayType", 
  "arrayType", "arrayReferenceTypeDimensionSpecifier", "arrayReferenceType", 
  "classicalType", "numericType", "constantDeclaration", "singleDesignatorDeclaration", 
  "noDesignatorDeclaration", "bitDeclaration", "complexDeclaration", "arrayInitializer", 
  "arrayDeclaration", "classicalDeclaration", "classicalTypeList", "classicalArgument", 
  "classicalArgumentList", "anyTypeArgument", "anyTypeArgumentList", "aliasStatement", 
  "aliasInitializer", "rangeDefinition", "quantumGateDefinition", "quantumGateSignature", 
  "quantumGateName", "quantumBlock", "quantumLoop", "quantumLoopBlock", 
  "quantumStatement", "quantumInstruction", "quantumPhase", "quantumReset", 
  "quantumMeasurement", "quantumMeasurementAssignment", "quantumBarrier", 
  "quantumGateModifier", "powModifier", "ctrlModifier", "quantumGateCall", 
  "unaryOperator", "comparisonOperator", "equalityOperator", "logicalOperator", 
  "expressionStatement", "expression", "logicalAndExpression", "bitOrExpression", 
  "xOrExpression", "bitAndExpression", "equalityExpression", "comparisonExpression", 
  "bitShiftExpression", "additiveExpression", "multiplicativeExpression", 
  "unaryExpression", "powerExpression", "indexOperator", "indexExpression", 
  "indexedIdentifier", "expressionTerminator", "booleanLiteral", "builtInCall", 
  "builtInMath", "castOperator", "expressionList", "equalsExpression", "assignmentOperator", 
  "discreteSet", "setDeclaration", "programBlock", "branchingStatement", 
  "loopSignature", "loopStatement", "endStatement", "returnStatement", "controlDirective", 
  "externDeclaration", "externOrSubroutineCall", "subroutineDefinition", 
  "subroutineBlock", "pragma", "timingType", "timingBox", "timingIdentifier", 
  "timingInstructionName", "timingInstruction", "timingStatement", "calibration", 
  "calibrationGrammarDeclaration", "calibrationDefinition", "calibrationGrammar", 
  "calibrationArgumentList"
};

std::vector<std::string> qasmParser::_literalNames = {
  "", "'OPENQASM'", "'include'", "'input'", "'output'", "'qreg'", "'qubit'", 
  "'bit'", "'creg'", "'int'", "'uint'", "'float'", "'angle'", "'bool'", 
  "'let'", "'++'", "'gate'", "'U'", "'CX'", "'gphase'", "'reset'", "'measure'", 
  "'barrier'", "'inv'", "'@'", "'pow'", "'ctrl'", "'negctrl'", "'~'", "'!'", 
  "'>'", "'<'", "'>='", "'<='", "'=='", "'!='", "'&&'", "'||'", "'|'", "'^'", 
  "'&'", "'<<'", "'>>'", "'**'", "'true'", "'false'", "'arcsin'", "'sin'", 
  "'arccos'", "'cos'", "'arctan'", "'tan'", "'exp'", "'ln'", "'sqrt'", "'rotl'", 
  "'rotr'", "'popcount'", "'+='", "'-='", "'*='", "'/='", "'&='", "'|='", 
  "'~='", "'^='", "'<<='", "'>>='", "'%='", "'**='", "'if'", "'else'", "'for'", 
  "'in'", "'while'", "'end'", "'return'", "'break'", "'continue'", "'extern'", 
  "'def'", "'#pragma'", "'duration'", "'stretch'", "'box'", "'durationof'", 
  "'delay'", "'rotary'", "'defcalgrammar'", "'defcal'", "'\"openpulse\"'", 
  "'['", "']'", "'{'", "'}'", "'('", "')'", "':'", "';'", "'.'", "','", 
  "'='", "'->'", "'+'", "'-'", "'*'", "'/'", "'%'", "'im'", "", "'complex'", 
  "'#'", "'const'", "'mutable'", "'array'", "'sizeof'", "'#dim'"
};

std::vector<std::string> qasmParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "LBRACKET", "RBRACKET", "LBRACE", "RBRACE", "LPAREN", "RPAREN", "COLON", 
  "SEMICOLON", "DOT", "COMMA", "EQUALS", "ARROW", "PLUS", "MINUS", "MUL", 
  "DIV", "MOD", "IMAG", "ImagNumber", "COMPLEX", "HASH", "CONST", "MUTABLE", 
  "ARRAY", "SIZEOF", "DIM", "Constant", "Whitespace", "Newline", "Integer", 
  "Identifier", "RealNumber", "TimingLiteral", "StringLiteral", "LineComment", 
  "BlockComment"
};

dfa::Vocabulary qasmParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> qasmParser::_tokenNames;

qasmParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  static const uint16_t serializedATNSegment0[] = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
       0x3, 0x80, 0x46b, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 
       0xe, 0x9, 0xe, 0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 
       0x9, 0x11, 0x4, 0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 
       0x9, 0x14, 0x4, 0x15, 0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 
       0x9, 0x17, 0x4, 0x18, 0x9, 0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 
       0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 
       0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 0x1f, 0x9, 0x1f, 0x4, 0x20, 
       0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 0x9, 0x22, 0x4, 0x23, 
       0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 0x25, 0x4, 0x26, 
       0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 0x4, 0x29, 
       0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 0x2c, 
       0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
       0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 
       0x9, 0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 
       0x9, 0x35, 0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x4, 0x38, 
       0x9, 0x38, 0x4, 0x39, 0x9, 0x39, 0x4, 0x3a, 0x9, 0x3a, 0x4, 0x3b, 
       0x9, 0x3b, 0x4, 0x3c, 0x9, 0x3c, 0x4, 0x3d, 0x9, 0x3d, 0x4, 0x3e, 
       0x9, 0x3e, 0x4, 0x3f, 0x9, 0x3f, 0x4, 0x40, 0x9, 0x40, 0x4, 0x41, 
       0x9, 0x41, 0x4, 0x42, 0x9, 0x42, 0x4, 0x43, 0x9, 0x43, 0x4, 0x44, 
       0x9, 0x44, 0x4, 0x45, 0x9, 0x45, 0x4, 0x46, 0x9, 0x46, 0x4, 0x47, 
       0x9, 0x47, 0x4, 0x48, 0x9, 0x48, 0x4, 0x49, 0x9, 0x49, 0x4, 0x4a, 
       0x9, 0x4a, 0x4, 0x4b, 0x9, 0x4b, 0x4, 0x4c, 0x9, 0x4c, 0x4, 0x4d, 
       0x9, 0x4d, 0x4, 0x4e, 0x9, 0x4e, 0x4, 0x4f, 0x9, 0x4f, 0x4, 0x50, 
       0x9, 0x50, 0x4, 0x51, 0x9, 0x51, 0x4, 0x52, 0x9, 0x52, 0x4, 0x53, 
       0x9, 0x53, 0x4, 0x54, 0x9, 0x54, 0x4, 0x55, 0x9, 0x55, 0x4, 0x56, 
       0x9, 0x56, 0x4, 0x57, 0x9, 0x57, 0x4, 0x58, 0x9, 0x58, 0x4, 0x59, 
       0x9, 0x59, 0x4, 0x5a, 0x9, 0x5a, 0x4, 0x5b, 0x9, 0x5b, 0x4, 0x5c, 
       0x9, 0x5c, 0x4, 0x5d, 0x9, 0x5d, 0x4, 0x5e, 0x9, 0x5e, 0x4, 0x5f, 
       0x9, 0x5f, 0x4, 0x60, 0x9, 0x60, 0x4, 0x61, 0x9, 0x61, 0x4, 0x62, 
       0x9, 0x62, 0x4, 0x63, 0x9, 0x63, 0x4, 0x64, 0x9, 0x64, 0x4, 0x65, 
       0x9, 0x65, 0x4, 0x66, 0x9, 0x66, 0x4, 0x67, 0x9, 0x67, 0x4, 0x68, 
       0x9, 0x68, 0x4, 0x69, 0x9, 0x69, 0x4, 0x6a, 0x9, 0x6a, 0x4, 0x6b, 
       0x9, 0x6b, 0x4, 0x6c, 0x9, 0x6c, 0x4, 0x6d, 0x9, 0x6d, 0x4, 0x6e, 
       0x9, 0x6e, 0x4, 0x6f, 0x9, 0x6f, 0x4, 0x70, 0x9, 0x70, 0x4, 0x71, 
       0x9, 0x71, 0x4, 0x72, 0x9, 0x72, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 
       0x2, 0xe8, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0xeb, 0xb, 0x2, 0x3, 0x3, 
       0x5, 0x3, 0xee, 0xa, 0x3, 0x3, 0x3, 0x7, 0x3, 0xf1, 0xa, 0x3, 0xc, 
       0x3, 0xe, 0x3, 0xf4, 0xb, 0x3, 0x3, 0x3, 0x7, 0x3, 0xf7, 0xa, 0x3, 
       0xc, 0x3, 0xe, 0x3, 0xfa, 0xb, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
       0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 
       0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 
       0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x111, 
       0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
       0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x11b, 0xa, 0x9, 0x3, 0xa, 0x3, 
       0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x122, 0xa, 0xb, 0x3, 
       0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 
       0x3, 0xd, 0x5, 0xd, 0x12c, 0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 
       0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
       0x10, 0x3, 0x10, 0x7, 0x10, 0x139, 0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 
       0x13c, 0xb, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 
       0x11, 0x5, 0x11, 0x143, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 
       0x147, 0xa, 0x11, 0x3, 0x11, 0x5, 0x11, 0x14a, 0xa, 0x11, 0x3, 0x12, 
       0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0x14f, 0xa, 0x12, 0x3, 0x12, 0x3, 
       0x12, 0x5, 0x12, 0x153, 0xa, 0x12, 0x3, 0x12, 0x5, 0x12, 0x156, 0xa, 
       0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x7, 0x13, 0x15b, 0xa, 0x13, 
       0xc, 0x13, 0xe, 0x13, 0x15e, 0xb, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 
       0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0x166, 0xa, 0x16, 
       0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
       0x5, 0x17, 0x16e, 0xa, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 
       0x17, 0x3, 0x17, 0x5, 0x17, 0x175, 0xa, 0x17, 0x3, 0x18, 0x3, 0x18, 
       0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 
       0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 0x182, 0xa, 0x19, 0x3, 
       0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 
       0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 0x18d, 0xa, 0x1b, 0x3, 0x1c, 
       0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 
       0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 
       0x19b, 0xa, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 0x1a0, 
       0xa, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x1a5, 0xa, 
       0x20, 0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x1a9, 0xa, 0x20, 0x3, 0x20, 
       0x5, 0x20, 0x1ac, 0xa, 0x20, 0x3, 0x20, 0x5, 0x20, 0x1af, 0xa, 0x20, 
       0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 
       0x5, 0x21, 0x1b7, 0xa, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x5, 
       0x22, 0x1bc, 0xa, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 
       0x1c1, 0xa, 0x22, 0x7, 0x22, 0x1c3, 0xa, 0x22, 0xc, 0x22, 0xe, 0x22, 
       0x1c6, 0xb, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 
       0x23, 0x3, 0x23, 0x3, 0x23, 0x5, 0x23, 0x1cf, 0xa, 0x23, 0x5, 0x23, 
       0x1d1, 0xa, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 
       0x24, 0x5, 0x24, 0x1d8, 0xa, 0x24, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 
       0x7, 0x25, 0x1dd, 0xa, 0x25, 0xc, 0x25, 0xe, 0x25, 0x1e0, 0xb, 0x25, 
       0x3, 0x25, 0x3, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 
       0x5, 0x26, 0x1e8, 0xa, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 
       0x26, 0x3, 0x26, 0x5, 0x26, 0x1ef, 0xa, 0x26, 0x3, 0x26, 0x3, 0x26, 
       0x5, 0x26, 0x1f3, 0xa, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 
       0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 
       0x26, 0x3, 0x26, 0x5, 0x26, 0x200, 0xa, 0x26, 0x3, 0x27, 0x3, 0x27, 
       0x3, 0x27, 0x7, 0x27, 0x205, 0xa, 0x27, 0xc, 0x27, 0xe, 0x27, 0x208, 
       0xb, 0x27, 0x3, 0x28, 0x3, 0x28, 0x5, 0x28, 0x20c, 0xa, 0x28, 0x3, 
       0x29, 0x3, 0x29, 0x3, 0x29, 0x7, 0x29, 0x211, 0xa, 0x29, 0xc, 0x29, 
       0xe, 0x29, 0x214, 0xb, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x2a, 0x3, 
       0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2b, 0x3, 
       0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x7, 0x2b, 0x224, 
       0xa, 0x2b, 0xc, 0x2b, 0xe, 0x2b, 0x227, 0xb, 0x2b, 0x3, 0x2c, 0x5, 
       0x2c, 0x22a, 0xa, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 0x22e, 0xa, 
       0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 0x232, 0xa, 0x2c, 0x3, 0x2d, 
       0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 
       0x5, 0x2e, 0x23b, 0xa, 0x2e, 0x3, 0x2e, 0x5, 0x2e, 0x23e, 0xa, 0x2e, 
       0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x30, 0x3, 0x30, 
       0x3, 0x30, 0x7, 0x30, 0x247, 0xa, 0x30, 0xc, 0x30, 0xe, 0x30, 0x24a, 
       0xb, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 
       0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x7, 0x32, 0x254, 0xa, 0x32, 0xc, 
       0x32, 0xe, 0x32, 0x257, 0xb, 0x32, 0x3, 0x32, 0x5, 0x32, 0x25a, 0xa, 
       0x32, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x5, 0x33, 0x260, 
       0xa, 0x33, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 
       0x5, 0x34, 0x267, 0xa, 0x34, 0x3, 0x35, 0x7, 0x35, 0x26a, 0xa, 0x35, 
       0xc, 0x35, 0xe, 0x35, 0x26d, 0xb, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 
       0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x7, 0x35, 0x276, 
       0xa, 0x35, 0xc, 0x35, 0xe, 0x35, 0x279, 0xb, 0x35, 0x5, 0x35, 0x27b, 
       0xa, 0x35, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x37, 0x3, 0x37, 
       0x3, 0x37, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x5, 0x38, 0x286, 0xa, 
       0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x5, 0x38, 0x28c, 
       0xa, 0x38, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x7, 0x39, 
       0x292, 0xa, 0x39, 0xc, 0x39, 0xe, 0x39, 0x295, 0xb, 0x39, 0x5, 0x39, 
       0x297, 0xa, 0x39, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x5, 0x3a, 0x29c, 
       0xa, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 
       0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 
       0x3, 0x3c, 0x5, 0x3c, 0x2aa, 0xa, 0x3c, 0x3, 0x3d, 0x7, 0x3d, 0x2ad, 
       0xa, 0x3d, 0xc, 0x3d, 0xe, 0x3d, 0x2b0, 0xb, 0x3d, 0x3, 0x3d, 0x3, 
       0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x5, 0x3d, 0x2b7, 0xa, 0x3d, 
       0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x7, 0x3d, 0x2bc, 0xa, 0x3d, 0xc, 
       0x3d, 0xe, 0x3d, 0x2bf, 0xb, 0x3d, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3f, 
       0x3, 0x3f, 0x3, 0x40, 0x3, 0x40, 0x3, 0x41, 0x3, 0x41, 0x3, 0x42, 
       0x3, 0x42, 0x3, 0x42, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 
       0x5, 0x43, 0x2d0, 0xa, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x7, 
       0x43, 0x2d5, 0xa, 0x43, 0xc, 0x43, 0xe, 0x43, 0x2d8, 0xb, 0x43, 0x3, 
       0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x7, 
       0x44, 0x2e0, 0xa, 0x44, 0xc, 0x44, 0xe, 0x44, 0x2e3, 0xb, 0x44, 0x3, 
       0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x7, 
       0x45, 0x2eb, 0xa, 0x45, 0xc, 0x45, 0xe, 0x45, 0x2ee, 0xb, 0x45, 0x3, 
       0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x7, 
       0x46, 0x2f6, 0xa, 0x46, 0xc, 0x46, 0xe, 0x46, 0x2f9, 0xb, 0x46, 0x3, 
       0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x7, 
       0x47, 0x301, 0xa, 0x47, 0xc, 0x47, 0xe, 0x47, 0x304, 0xb, 0x47, 0x3, 
       0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 
       0x48, 0x7, 0x48, 0x30d, 0xa, 0x48, 0xc, 0x48, 0xe, 0x48, 0x310, 0xb, 
       0x48, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 
       0x49, 0x3, 0x49, 0x7, 0x49, 0x319, 0xa, 0x49, 0xc, 0x49, 0xe, 0x49, 
       0x31c, 0xb, 0x49, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 
       0x4a, 0x3, 0x4a, 0x7, 0x4a, 0x324, 0xa, 0x4a, 0xc, 0x4a, 0xe, 0x4a, 
       0x327, 0xb, 0x4a, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x3, 
       0x4b, 0x3, 0x4b, 0x7, 0x4b, 0x32f, 0xa, 0x4b, 0xc, 0x4b, 0xe, 0x4b, 
       0x332, 0xb, 0x4b, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 
       0x4c, 0x3, 0x4c, 0x7, 0x4c, 0x33a, 0xa, 0x4c, 0xc, 0x4c, 0xe, 0x4c, 
       0x33d, 0xb, 0x4c, 0x3, 0x4d, 0x5, 0x4d, 0x340, 0xa, 0x4d, 0x3, 0x4d, 
       0x3, 0x4d, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 
       0x3, 0x4e, 0x7, 0x4e, 0x34a, 0xa, 0x4e, 0xc, 0x4e, 0xe, 0x4e, 0x34d, 
       0xb, 0x4e, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x5, 0x4f, 
       0x353, 0xa, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x5, 0x4f, 0x358, 
       0xa, 0x4f, 0x7, 0x4f, 0x35a, 0xa, 0x4f, 0xc, 0x4f, 0xe, 0x4f, 0x35d, 
       0xb, 0x4f, 0x5, 0x4f, 0x35f, 0xa, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 
       0x50, 0x3, 0x50, 0x3, 0x50, 0x3, 0x50, 0x3, 0x50, 0x7, 0x50, 0x368, 
       0xa, 0x50, 0xc, 0x50, 0xe, 0x50, 0x36b, 0xb, 0x50, 0x3, 0x51, 0x3, 
       0x51, 0x7, 0x51, 0x36f, 0xa, 0x51, 0xc, 0x51, 0xe, 0x51, 0x372, 0xb, 
       0x51, 0x3, 0x52, 0x3, 0x52, 0x3, 0x52, 0x3, 0x52, 0x3, 0x52, 0x3, 
       0x52, 0x3, 0x52, 0x3, 0x52, 0x3, 0x52, 0x3, 0x52, 0x3, 0x52, 0x3, 
       0x52, 0x3, 0x52, 0x3, 0x52, 0x5, 0x52, 0x382, 0xa, 0x52, 0x3, 0x53, 
       0x3, 0x53, 0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x5, 0x54, 0x389, 0xa, 
       0x54, 0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x3, 0x55, 0x3, 
       0x55, 0x3, 0x56, 0x3, 0x56, 0x3, 0x57, 0x3, 0x57, 0x3, 0x57, 0x7, 
       0x57, 0x396, 0xa, 0x57, 0xc, 0x57, 0xe, 0x57, 0x399, 0xb, 0x57, 0x3, 
       0x58, 0x3, 0x58, 0x3, 0x58, 0x3, 0x59, 0x3, 0x59, 0x3, 0x5a, 0x3, 
       0x5a, 0x3, 0x5a, 0x3, 0x5a, 0x7, 0x5a, 0x3a4, 0xa, 0x5a, 0xc, 0x5a, 
       0xe, 0x5a, 0x3a7, 0xb, 0x5a, 0x3, 0x5a, 0x3, 0x5a, 0x3, 0x5b, 0x3, 
       0x5b, 0x3, 0x5b, 0x3, 0x5b, 0x3, 0x5b, 0x3, 0x5b, 0x5, 0x5b, 0x3b1, 
       0xa, 0x5b, 0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 
       0x7, 0x5c, 0x3b8, 0xa, 0x5c, 0xc, 0x5c, 0xe, 0x5c, 0x3bb, 0xb, 0x5c, 
       0x3, 0x5c, 0x5, 0x5c, 0x3be, 0xa, 0x5c, 0x3, 0x5d, 0x3, 0x5d, 0x3, 
       0x5d, 0x3, 0x5d, 0x3, 0x5d, 0x3, 0x5d, 0x3, 0x5d, 0x5, 0x5d, 0x3c7, 
       0xa, 0x5d, 0x3, 0x5e, 0x3, 0x5e, 0x3, 0x5e, 0x3, 0x5e, 0x3, 0x5e, 
       0x3, 0x5e, 0x3, 0x5e, 0x3, 0x5e, 0x3, 0x5e, 0x5, 0x5e, 0x3d2, 0xa, 
       0x5e, 0x3, 0x5f, 0x3, 0x5f, 0x3, 0x5f, 0x3, 0x60, 0x3, 0x60, 0x3, 
       0x60, 0x3, 0x61, 0x3, 0x61, 0x3, 0x61, 0x5, 0x61, 0x3dd, 0xa, 0x61, 
       0x3, 0x61, 0x3, 0x61, 0x3, 0x62, 0x3, 0x62, 0x3, 0x62, 0x3, 0x62, 
       0x5, 0x62, 0x3e5, 0xa, 0x62, 0x3, 0x63, 0x3, 0x63, 0x3, 0x63, 0x3, 
       0x63, 0x5, 0x63, 0x3eb, 0xa, 0x63, 0x3, 0x63, 0x3, 0x63, 0x5, 0x63, 
       0x3ef, 0xa, 0x63, 0x3, 0x63, 0x3, 0x63, 0x3, 0x64, 0x3, 0x64, 0x3, 
       0x64, 0x5, 0x64, 0x3f6, 0xa, 0x64, 0x3, 0x64, 0x3, 0x64, 0x3, 0x65, 
       0x3, 0x65, 0x3, 0x65, 0x3, 0x65, 0x5, 0x65, 0x3fe, 0xa, 0x65, 0x3, 
       0x65, 0x3, 0x65, 0x5, 0x65, 0x402, 0xa, 0x65, 0x3, 0x65, 0x3, 0x65, 
       0x3, 0x66, 0x3, 0x66, 0x7, 0x66, 0x408, 0xa, 0x66, 0xc, 0x66, 0xe, 
       0x66, 0x40b, 0xb, 0x66, 0x3, 0x66, 0x5, 0x66, 0x40e, 0xa, 0x66, 0x3, 
       0x66, 0x3, 0x66, 0x3, 0x67, 0x3, 0x67, 0x3, 0x67, 0x7, 0x67, 0x415, 
       0xa, 0x67, 0xc, 0x67, 0xe, 0x67, 0x418, 0xb, 0x67, 0x3, 0x67, 0x3, 
       0x67, 0x3, 0x68, 0x3, 0x68, 0x3, 0x69, 0x3, 0x69, 0x5, 0x69, 0x420, 
       0xa, 0x69, 0x3, 0x69, 0x3, 0x69, 0x3, 0x6a, 0x3, 0x6a, 0x3, 0x6a, 
       0x3, 0x6a, 0x3, 0x6a, 0x5, 0x6a, 0x429, 0xa, 0x6a, 0x3, 0x6a, 0x5, 
       0x6a, 0x42c, 0xa, 0x6a, 0x3, 0x6b, 0x3, 0x6b, 0x3, 0x6c, 0x3, 0x6c, 
       0x3, 0x6c, 0x5, 0x6c, 0x433, 0xa, 0x6c, 0x3, 0x6c, 0x5, 0x6c, 0x436, 
       0xa, 0x6c, 0x3, 0x6c, 0x3, 0x6c, 0x3, 0x6c, 0x3, 0x6c, 0x7, 0x6c, 
       0x43c, 0xa, 0x6c, 0xc, 0x6c, 0xe, 0x6c, 0x43f, 0xb, 0x6c, 0x3, 0x6d, 
       0x3, 0x6d, 0x3, 0x6d, 0x3, 0x6d, 0x5, 0x6d, 0x445, 0xa, 0x6d, 0x3, 
       0x6e, 0x3, 0x6e, 0x5, 0x6e, 0x449, 0xa, 0x6e, 0x3, 0x6f, 0x3, 0x6f, 
       0x3, 0x6f, 0x3, 0x6f, 0x3, 0x70, 0x3, 0x70, 0x3, 0x70, 0x3, 0x70, 
       0x5, 0x70, 0x453, 0xa, 0x70, 0x3, 0x70, 0x5, 0x70, 0x456, 0xa, 0x70, 
       0x3, 0x70, 0x3, 0x70, 0x5, 0x70, 0x45a, 0xa, 0x70, 0x3, 0x70, 0x3, 
       0x70, 0x7, 0x70, 0x45e, 0xa, 0x70, 0xc, 0x70, 0xe, 0x70, 0x461, 0xb, 
       0x70, 0x3, 0x70, 0x3, 0x70, 0x3, 0x71, 0x3, 0x71, 0x3, 0x72, 0x3, 
       0x72, 0x5, 0x72, 0x469, 0xa, 0x72, 0x3, 0x72, 0x3, 0x45f, 0xf, 0x54, 
       0x84, 0x86, 0x88, 0x8a, 0x8c, 0x8e, 0x90, 0x92, 0x94, 0x96, 0x9a, 
       0x9e, 0x73, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 
       0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 
       0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 
       0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 
       0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 
       0x6e, 0x70, 0x72, 0x74, 0x76, 0x78, 0x7a, 0x7c, 0x7e, 0x80, 0x82, 
       0x84, 0x86, 0x88, 0x8a, 0x8c, 0x8e, 0x90, 0x92, 0x94, 0x96, 0x98, 
       0x9a, 0x9c, 0x9e, 0xa0, 0xa2, 0xa4, 0xa6, 0xa8, 0xaa, 0xac, 0xae, 
       0xb0, 0xb2, 0xb4, 0xb6, 0xb8, 0xba, 0xbc, 0xbe, 0xc0, 0xc2, 0xc4, 
       0xc6, 0xc8, 0xca, 0xcc, 0xce, 0xd0, 0xd2, 0xd4, 0xd6, 0xd8, 0xda, 
       0xdc, 0xde, 0xe0, 0xe2, 0x2, 0x17, 0x4, 0x2, 0x7a, 0x7a, 0x7c, 0x7c, 
       0x3, 0x2, 0x5, 0x6, 0x3, 0x2, 0x9, 0xa, 0x3, 0x2, 0xb, 0xe, 0x3, 
       0x2, 0x72, 0x73, 0x4, 0x2, 0x13, 0x14, 0x7b, 0x7b, 0x3, 0x2, 0x1c, 
       0x1d, 0x4, 0x2, 0x1e, 0x1f, 0x6a, 0x6a, 0x3, 0x2, 0x20, 0x23, 0x3, 
       0x2, 0x24, 0x25, 0x3, 0x2, 0x26, 0x27, 0x3, 0x2, 0x2b, 0x2c, 0x3, 
       0x2, 0x69, 0x6a, 0x3, 0x2, 0x6b, 0x6d, 0x3, 0x2, 0x2e, 0x2f, 0x3, 
       0x2, 0x30, 0x3b, 0x4, 0x2, 0x3c, 0x47, 0x67, 0x67, 0x3, 0x2, 0x4f, 
       0x50, 0x3, 0x2, 0x54, 0x55, 0x3, 0x2, 0x58, 0x59, 0x4, 0x2, 0x5c, 
       0x5c, 0x7e, 0x7e, 0x2, 0x495, 0x2, 0xe4, 0x3, 0x2, 0x2, 0x2, 0x4, 
       0xed, 0x3, 0x2, 0x2, 0x2, 0x6, 0xfb, 0x3, 0x2, 0x2, 0x2, 0x8, 0xff, 
       0x3, 0x2, 0x2, 0x2, 0xa, 0x103, 0x3, 0x2, 0x2, 0x2, 0xc, 0x105, 0x3, 
       0x2, 0x2, 0x2, 0xe, 0x110, 0x3, 0x2, 0x2, 0x2, 0x10, 0x11a, 0x3, 
       0x2, 0x2, 0x2, 0x12, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x14, 0x121, 0x3, 
       0x2, 0x2, 0x2, 0x16, 0x125, 0x3, 0x2, 0x2, 0x2, 0x18, 0x12b, 0x3, 
       0x2, 0x2, 0x2, 0x1a, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x132, 0x3, 
       0x2, 0x2, 0x2, 0x1e, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x20, 0x149, 0x3, 
       0x2, 0x2, 0x2, 0x22, 0x155, 0x3, 0x2, 0x2, 0x2, 0x24, 0x157, 0x3, 
       0x2, 0x2, 0x2, 0x26, 0x15f, 0x3, 0x2, 0x2, 0x2, 0x28, 0x161, 0x3, 
       0x2, 0x2, 0x2, 0x2a, 0x165, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x174, 0x3, 
       0x2, 0x2, 0x2, 0x2e, 0x176, 0x3, 0x2, 0x2, 0x2, 0x30, 0x181, 0x3, 
       0x2, 0x2, 0x2, 0x32, 0x183, 0x3, 0x2, 0x2, 0x2, 0x34, 0x18c, 0x3, 
       0x2, 0x2, 0x2, 0x36, 0x18e, 0x3, 0x2, 0x2, 0x2, 0x38, 0x191, 0x3, 
       0x2, 0x2, 0x2, 0x3a, 0x196, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x19c, 0x3, 
       0x2, 0x2, 0x2, 0x3e, 0x1ab, 0x3, 0x2, 0x2, 0x2, 0x40, 0x1b0, 0x3, 
       0x2, 0x2, 0x2, 0x42, 0x1b8, 0x3, 0x2, 0x2, 0x2, 0x44, 0x1c9, 0x3, 
       0x2, 0x2, 0x2, 0x46, 0x1d7, 0x3, 0x2, 0x2, 0x2, 0x48, 0x1de, 0x3, 
       0x2, 0x2, 0x2, 0x4a, 0x1ff, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x201, 0x3, 
       0x2, 0x2, 0x2, 0x4e, 0x20b, 0x3, 0x2, 0x2, 0x2, 0x50, 0x212, 0x3, 
       0x2, 0x2, 0x2, 0x52, 0x217, 0x3, 0x2, 0x2, 0x2, 0x54, 0x21d, 0x3, 
       0x2, 0x2, 0x2, 0x56, 0x229, 0x3, 0x2, 0x2, 0x2, 0x58, 0x233, 0x3, 
       0x2, 0x2, 0x2, 0x5a, 0x237, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x241, 0x3, 
       0x2, 0x2, 0x2, 0x5e, 0x243, 0x3, 0x2, 0x2, 0x2, 0x60, 0x24d, 0x3, 
       0x2, 0x2, 0x2, 0x62, 0x259, 0x3, 0x2, 0x2, 0x2, 0x64, 0x25f, 0x3, 
       0x2, 0x2, 0x2, 0x66, 0x266, 0x3, 0x2, 0x2, 0x2, 0x68, 0x26b, 0x3, 
       0x2, 0x2, 0x2, 0x6a, 0x27c, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x27f, 0x3, 
       0x2, 0x2, 0x2, 0x6e, 0x28b, 0x3, 0x2, 0x2, 0x2, 0x70, 0x28d, 0x3, 
       0x2, 0x2, 0x2, 0x72, 0x29b, 0x3, 0x2, 0x2, 0x2, 0x74, 0x29f, 0x3, 
       0x2, 0x2, 0x2, 0x76, 0x2a4, 0x3, 0x2, 0x2, 0x2, 0x78, 0x2ae, 0x3, 
       0x2, 0x2, 0x2, 0x7a, 0x2c0, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x2c2, 0x3, 
       0x2, 0x2, 0x2, 0x7e, 0x2c4, 0x3, 0x2, 0x2, 0x2, 0x80, 0x2c6, 0x3, 
       0x2, 0x2, 0x2, 0x82, 0x2c8, 0x3, 0x2, 0x2, 0x2, 0x84, 0x2cf, 0x3, 
       0x2, 0x2, 0x2, 0x86, 0x2d9, 0x3, 0x2, 0x2, 0x2, 0x88, 0x2e4, 0x3, 
       0x2, 0x2, 0x2, 0x8a, 0x2ef, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x2fa, 0x3, 
       0x2, 0x2, 0x2, 0x8e, 0x305, 0x3, 0x2, 0x2, 0x2, 0x90, 0x311, 0x3, 
       0x2, 0x2, 0x2, 0x92, 0x31d, 0x3, 0x2, 0x2, 0x2, 0x94, 0x328, 0x3, 
       0x2, 0x2, 0x2, 0x96, 0x333, 0x3, 0x2, 0x2, 0x2, 0x98, 0x33f, 0x3, 
       0x2, 0x2, 0x2, 0x9a, 0x343, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x34e, 0x3, 
       0x2, 0x2, 0x2, 0x9e, 0x362, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x36c, 0x3, 
       0x2, 0x2, 0x2, 0xa2, 0x381, 0x3, 0x2, 0x2, 0x2, 0xa4, 0x383, 0x3, 
       0x2, 0x2, 0x2, 0xa6, 0x388, 0x3, 0x2, 0x2, 0x2, 0xa8, 0x38e, 0x3, 
       0x2, 0x2, 0x2, 0xaa, 0x390, 0x3, 0x2, 0x2, 0x2, 0xac, 0x392, 0x3, 
       0x2, 0x2, 0x2, 0xae, 0x39a, 0x3, 0x2, 0x2, 0x2, 0xb0, 0x39d, 0x3, 
       0x2, 0x2, 0x2, 0xb2, 0x39f, 0x3, 0x2, 0x2, 0x2, 0xb4, 0x3b0, 0x3, 
       0x2, 0x2, 0x2, 0xb6, 0x3bd, 0x3, 0x2, 0x2, 0x2, 0xb8, 0x3bf, 0x3, 
       0x2, 0x2, 0x2, 0xba, 0x3d1, 0x3, 0x2, 0x2, 0x2, 0xbc, 0x3d3, 0x3, 
       0x2, 0x2, 0x2, 0xbe, 0x3d6, 0x3, 0x2, 0x2, 0x2, 0xc0, 0x3d9, 0x3, 
       0x2, 0x2, 0x2, 0xc2, 0x3e4, 0x3, 0x2, 0x2, 0x2, 0xc4, 0x3e6, 0x3, 
       0x2, 0x2, 0x2, 0xc6, 0x3f2, 0x3, 0x2, 0x2, 0x2, 0xc8, 0x3f9, 0x3, 
       0x2, 0x2, 0x2, 0xca, 0x405, 0x3, 0x2, 0x2, 0x2, 0xcc, 0x411, 0x3, 
       0x2, 0x2, 0x2, 0xce, 0x41b, 0x3, 0x2, 0x2, 0x2, 0xd0, 0x41d, 0x3, 
       0x2, 0x2, 0x2, 0xd2, 0x42b, 0x3, 0x2, 0x2, 0x2, 0xd4, 0x42d, 0x3, 
       0x2, 0x2, 0x2, 0xd6, 0x42f, 0x3, 0x2, 0x2, 0x2, 0xd8, 0x444, 0x3, 
       0x2, 0x2, 0x2, 0xda, 0x448, 0x3, 0x2, 0x2, 0x2, 0xdc, 0x44a, 0x3, 
       0x2, 0x2, 0x2, 0xde, 0x44e, 0x3, 0x2, 0x2, 0x2, 0xe0, 0x464, 0x3, 
       0x2, 0x2, 0x2, 0xe2, 0x468, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe9, 0x5, 
       0x4, 0x3, 0x2, 0xe5, 0xe8, 0x5, 0xe, 0x8, 0x2, 0xe6, 0xe8, 0x5, 0x10, 
       0x9, 0x2, 0xe7, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xe6, 0x3, 0x2, 0x2, 
       0x2, 0xe8, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xe7, 0x3, 0x2, 0x2, 0x2, 
       0xe9, 0xea, 0x3, 0x2, 0x2, 0x2, 0xea, 0x3, 0x3, 0x2, 0x2, 0x2, 0xeb, 
       0xe9, 0x3, 0x2, 0x2, 0x2, 0xec, 0xee, 0x5, 0x6, 0x4, 0x2, 0xed, 0xec, 
       0x3, 0x2, 0x2, 0x2, 0xed, 0xee, 0x3, 0x2, 0x2, 0x2, 0xee, 0xf2, 0x3, 
       0x2, 0x2, 0x2, 0xef, 0xf1, 0x5, 0x8, 0x5, 0x2, 0xf0, 0xef, 0x3, 0x2, 
       0x2, 0x2, 0xf1, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf0, 0x3, 0x2, 0x2, 
       0x2, 0xf2, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf8, 0x3, 0x2, 0x2, 0x2, 
       0xf4, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf7, 0x5, 0xc, 0x7, 0x2, 0xf6, 
       0xf5, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xfa, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf6, 
       0x3, 0x2, 0x2, 0x2, 0xf8, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xf9, 0x5, 0x3, 
       0x2, 0x2, 0x2, 0xfa, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xfc, 0x7, 0x3, 
       0x2, 0x2, 0xfc, 0xfd, 0x9, 0x2, 0x2, 0x2, 0xfd, 0xfe, 0x7, 0x64, 
       0x2, 0x2, 0xfe, 0x7, 0x3, 0x2, 0x2, 0x2, 0xff, 0x100, 0x7, 0x4, 0x2, 
       0x2, 0x100, 0x101, 0x7, 0x7e, 0x2, 0x2, 0x101, 0x102, 0x7, 0x64, 
       0x2, 0x2, 0x102, 0x9, 0x3, 0x2, 0x2, 0x2, 0x103, 0x104, 0x9, 0x3, 
       0x2, 0x2, 0x104, 0xb, 0x3, 0x2, 0x2, 0x2, 0x105, 0x106, 0x5, 0xa, 
       0x6, 0x2, 0x106, 0x107, 0x5, 0x34, 0x1b, 0x2, 0x107, 0x108, 0x7, 
       0x7b, 0x2, 0x2, 0x108, 0x109, 0x7, 0x64, 0x2, 0x2, 0x109, 0xd, 0x3, 
       0x2, 0x2, 0x2, 0x10a, 0x111, 0x5, 0xc8, 0x65, 0x2, 0x10b, 0x111, 
       0x5, 0xc4, 0x63, 0x2, 0x10c, 0x111, 0x5, 0x58, 0x2d, 0x2, 0x10d, 
       0x111, 0x5, 0xda, 0x6e, 0x2, 0x10e, 0x111, 0x5, 0x12, 0xa, 0x2, 0x10f, 
       0x111, 0x5, 0xcc, 0x67, 0x2, 0x110, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x110, 
       0x10b, 0x3, 0x2, 0x2, 0x2, 0x110, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x110, 
       0x10d, 0x3, 0x2, 0x2, 0x2, 0x110, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x110, 
       0x10f, 0x3, 0x2, 0x2, 0x2, 0x111, 0xf, 0x3, 0x2, 0x2, 0x2, 0x112, 
       0x11b, 0x5, 0x82, 0x42, 0x2, 0x113, 0x11b, 0x5, 0x18, 0xd, 0x2, 0x114, 
       0x11b, 0x5, 0x14, 0xb, 0x2, 0x115, 0x11b, 0x5, 0xb8, 0x5d, 0x2, 0x116, 
       0x11b, 0x5, 0xbc, 0x5f, 0x2, 0x117, 0x11b, 0x5, 0xbe, 0x60, 0x2, 
       0x118, 0x11b, 0x5, 0x52, 0x2a, 0x2, 0x119, 0x11b, 0x5, 0x64, 0x33, 
       0x2, 0x11a, 0x112, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x113, 0x3, 0x2, 0x2, 
       0x2, 0x11a, 0x114, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x115, 0x3, 0x2, 0x2, 
       0x2, 0x11a, 0x116, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x117, 0x3, 0x2, 0x2, 
       0x2, 0x11a, 0x118, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x119, 0x3, 0x2, 0x2, 
       0x2, 0x11b, 0x11, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x11d, 0x5, 0x20, 0x11, 
       0x2, 0x11d, 0x11e, 0x7, 0x64, 0x2, 0x2, 0x11e, 0x13, 0x3, 0x2, 0x2, 
       0x2, 0x11f, 0x122, 0x5, 0x46, 0x24, 0x2, 0x120, 0x122, 0x5, 0x38, 
       0x1d, 0x2, 0x121, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x121, 0x120, 0x3, 0x2, 
       0x2, 0x2, 0x122, 0x123, 0x3, 0x2, 0x2, 0x2, 0x123, 0x124, 0x7, 0x64, 
       0x2, 0x2, 0x124, 0x15, 0x3, 0x2, 0x2, 0x2, 0x125, 0x126, 0x5, 0xa0, 
       0x51, 0x2, 0x126, 0x127, 0x5, 0xb0, 0x59, 0x2, 0x127, 0x128, 0x5, 
       0x84, 0x43, 0x2, 0x128, 0x17, 0x3, 0x2, 0x2, 0x2, 0x129, 0x12c, 0x5, 
       0x16, 0xc, 0x2, 0x12a, 0x12c, 0x5, 0x6e, 0x38, 0x2, 0x12b, 0x129, 
       0x3, 0x2, 0x2, 0x2, 0x12b, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x12d, 
       0x3, 0x2, 0x2, 0x2, 0x12d, 0x12e, 0x7, 0x64, 0x2, 0x2, 0x12e, 0x19, 
       0x3, 0x2, 0x2, 0x2, 0x12f, 0x130, 0x7, 0x68, 0x2, 0x2, 0x130, 0x131, 
       0x5, 0x34, 0x1b, 0x2, 0x131, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x132, 0x133, 
       0x7, 0x5d, 0x2, 0x2, 0x133, 0x134, 0x5, 0x84, 0x43, 0x2, 0x134, 0x135, 
       0x7, 0x5e, 0x2, 0x2, 0x135, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x136, 0x137, 
       0x7, 0x7b, 0x2, 0x2, 0x137, 0x139, 0x7, 0x66, 0x2, 0x2, 0x138, 0x136, 
       0x3, 0x2, 0x2, 0x2, 0x139, 0x13c, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x138, 
       0x3, 0x2, 0x2, 0x2, 0x13a, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x13d, 
       0x3, 0x2, 0x2, 0x2, 0x13c, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x13e, 
       0x7, 0x7b, 0x2, 0x2, 0x13e, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x13f, 0x140, 
       0x7, 0x7, 0x2, 0x2, 0x140, 0x142, 0x7, 0x7b, 0x2, 0x2, 0x141, 0x143, 
       0x5, 0x1c, 0xf, 0x2, 0x142, 0x141, 0x3, 0x2, 0x2, 0x2, 0x142, 0x143, 
       0x3, 0x2, 0x2, 0x2, 0x143, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x144, 0x146, 
       0x7, 0x8, 0x2, 0x2, 0x145, 0x147, 0x5, 0x1c, 0xf, 0x2, 0x146, 0x145, 
       0x3, 0x2, 0x2, 0x2, 0x146, 0x147, 0x3, 0x2, 0x2, 0x2, 0x147, 0x148, 
       0x3, 0x2, 0x2, 0x2, 0x148, 0x14a, 0x7, 0x7b, 0x2, 0x2, 0x149, 0x13f, 
       0x3, 0x2, 0x2, 0x2, 0x149, 0x144, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x21, 
       0x3, 0x2, 0x2, 0x2, 0x14b, 0x14c, 0x7, 0x7, 0x2, 0x2, 0x14c, 0x14e, 
       0x7, 0x7b, 0x2, 0x2, 0x14d, 0x14f, 0x5, 0x1c, 0xf, 0x2, 0x14e, 0x14d, 
       0x3, 0x2, 0x2, 0x2, 0x14e, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x156, 
       0x3, 0x2, 0x2, 0x2, 0x150, 0x152, 0x7, 0x8, 0x2, 0x2, 0x151, 0x153, 
       0x5, 0x1c, 0xf, 0x2, 0x152, 0x151, 0x3, 0x2, 0x2, 0x2, 0x152, 0x153, 
       0x3, 0x2, 0x2, 0x2, 0x153, 0x154, 0x3, 0x2, 0x2, 0x2, 0x154, 0x156, 
       0x7, 0x7b, 0x2, 0x2, 0x155, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x155, 0x150, 
       0x3, 0x2, 0x2, 0x2, 0x156, 0x23, 0x3, 0x2, 0x2, 0x2, 0x157, 0x15c, 
       0x5, 0x22, 0x12, 0x2, 0x158, 0x159, 0x7, 0x66, 0x2, 0x2, 0x159, 0x15b, 
       0x5, 0x22, 0x12, 0x2, 0x15a, 0x158, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x15e, 
       0x3, 0x2, 0x2, 0x2, 0x15c, 0x15a, 0x3, 0x2, 0x2, 0x2, 0x15c, 0x15d, 
       0x3, 0x2, 0x2, 0x2, 0x15d, 0x25, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x15c, 
       0x3, 0x2, 0x2, 0x2, 0x15f, 0x160, 0x9, 0x4, 0x2, 0x2, 0x160, 0x27, 
       0x3, 0x2, 0x2, 0x2, 0x161, 0x162, 0x9, 0x5, 0x2, 0x2, 0x162, 0x29, 
       0x3, 0x2, 0x2, 0x2, 0x163, 0x166, 0x7, 0xf, 0x2, 0x2, 0x164, 0x166, 
       0x5, 0xce, 0x68, 0x2, 0x165, 0x163, 0x3, 0x2, 0x2, 0x2, 0x165, 0x164, 
       0x3, 0x2, 0x2, 0x2, 0x166, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x167, 0x168, 
       0x5, 0x28, 0x15, 0x2, 0x168, 0x169, 0x5, 0x1c, 0xf, 0x2, 0x169, 0x175, 
       0x3, 0x2, 0x2, 0x2, 0x16a, 0x175, 0x5, 0x2a, 0x16, 0x2, 0x16b, 0x16d, 
       0x5, 0x26, 0x14, 0x2, 0x16c, 0x16e, 0x5, 0x1c, 0xf, 0x2, 0x16d, 0x16c, 
       0x3, 0x2, 0x2, 0x2, 0x16d, 0x16e, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x175, 
       0x3, 0x2, 0x2, 0x2, 0x16f, 0x170, 0x7, 0x70, 0x2, 0x2, 0x170, 0x171, 
       0x7, 0x5d, 0x2, 0x2, 0x171, 0x172, 0x5, 0x36, 0x1c, 0x2, 0x172, 0x173, 
       0x7, 0x5e, 0x2, 0x2, 0x173, 0x175, 0x3, 0x2, 0x2, 0x2, 0x174, 0x167, 
       0x3, 0x2, 0x2, 0x2, 0x174, 0x16a, 0x3, 0x2, 0x2, 0x2, 0x174, 0x16b, 
       0x3, 0x2, 0x2, 0x2, 0x174, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x175, 0x2d, 
       0x3, 0x2, 0x2, 0x2, 0x176, 0x177, 0x7, 0x74, 0x2, 0x2, 0x177, 0x178, 
       0x7, 0x5d, 0x2, 0x2, 0x178, 0x179, 0x5, 0x2c, 0x17, 0x2, 0x179, 0x17a, 
       0x7, 0x66, 0x2, 0x2, 0x17a, 0x17b, 0x5, 0xac, 0x57, 0x2, 0x17b, 0x17c, 
       0x7, 0x5e, 0x2, 0x2, 0x17c, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x17d, 0x182, 
       0x5, 0xac, 0x57, 0x2, 0x17e, 0x17f, 0x7, 0x76, 0x2, 0x2, 0x17f, 0x180, 
       0x7, 0x67, 0x2, 0x2, 0x180, 0x182, 0x5, 0x84, 0x43, 0x2, 0x181, 0x17d, 
       0x3, 0x2, 0x2, 0x2, 0x181, 0x17e, 0x3, 0x2, 0x2, 0x2, 0x182, 0x31, 
       0x3, 0x2, 0x2, 0x2, 0x183, 0x184, 0x7, 0x74, 0x2, 0x2, 0x184, 0x185, 
       0x7, 0x5d, 0x2, 0x2, 0x185, 0x186, 0x5, 0x2c, 0x17, 0x2, 0x186, 0x187, 
       0x7, 0x66, 0x2, 0x2, 0x187, 0x188, 0x5, 0x30, 0x19, 0x2, 0x188, 0x189, 
       0x7, 0x5e, 0x2, 0x2, 0x189, 0x33, 0x3, 0x2, 0x2, 0x2, 0x18a, 0x18d, 
       0x5, 0x2c, 0x17, 0x2, 0x18b, 0x18d, 0x5, 0x2e, 0x18, 0x2, 0x18c, 
       0x18a, 0x3, 0x2, 0x2, 0x2, 0x18c, 0x18b, 0x3, 0x2, 0x2, 0x2, 0x18d, 
       0x35, 0x3, 0x2, 0x2, 0x2, 0x18e, 0x18f, 0x5, 0x28, 0x15, 0x2, 0x18f, 
       0x190, 0x5, 0x1c, 0xf, 0x2, 0x190, 0x37, 0x3, 0x2, 0x2, 0x2, 0x191, 
       0x192, 0x7, 0x72, 0x2, 0x2, 0x192, 0x193, 0x5, 0x34, 0x1b, 0x2, 0x193, 
       0x194, 0x7, 0x7b, 0x2, 0x2, 0x194, 0x195, 0x5, 0xae, 0x58, 0x2, 0x195, 
       0x39, 0x3, 0x2, 0x2, 0x2, 0x196, 0x197, 0x5, 0x28, 0x15, 0x2, 0x197, 
       0x198, 0x5, 0x1c, 0xf, 0x2, 0x198, 0x19a, 0x7, 0x7b, 0x2, 0x2, 0x199, 
       0x19b, 0x5, 0xae, 0x58, 0x2, 0x19a, 0x199, 0x3, 0x2, 0x2, 0x2, 0x19a, 
       0x19b, 0x3, 0x2, 0x2, 0x2, 0x19b, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x19c, 
       0x19d, 0x5, 0x2a, 0x16, 0x2, 0x19d, 0x19f, 0x7, 0x7b, 0x2, 0x2, 0x19e, 
       0x1a0, 0x5, 0xae, 0x58, 0x2, 0x19f, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x19f, 
       0x1a0, 0x3, 0x2, 0x2, 0x2, 0x1a0, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x1a1, 
       0x1a2, 0x7, 0xa, 0x2, 0x2, 0x1a2, 0x1a4, 0x7, 0x7b, 0x2, 0x2, 0x1a3, 
       0x1a5, 0x5, 0x1c, 0xf, 0x2, 0x1a4, 0x1a3, 0x3, 0x2, 0x2, 0x2, 0x1a4, 
       0x1a5, 0x3, 0x2, 0x2, 0x2, 0x1a5, 0x1ac, 0x3, 0x2, 0x2, 0x2, 0x1a6, 
       0x1a8, 0x7, 0x9, 0x2, 0x2, 0x1a7, 0x1a9, 0x5, 0x1c, 0xf, 0x2, 0x1a8, 
       0x1a7, 0x3, 0x2, 0x2, 0x2, 0x1a8, 0x1a9, 0x3, 0x2, 0x2, 0x2, 0x1a9, 
       0x1aa, 0x3, 0x2, 0x2, 0x2, 0x1aa, 0x1ac, 0x7, 0x7b, 0x2, 0x2, 0x1ab, 
       0x1a1, 0x3, 0x2, 0x2, 0x2, 0x1ab, 0x1a6, 0x3, 0x2, 0x2, 0x2, 0x1ac, 
       0x1ae, 0x3, 0x2, 0x2, 0x2, 0x1ad, 0x1af, 0x5, 0xae, 0x58, 0x2, 0x1ae, 
       0x1ad, 0x3, 0x2, 0x2, 0x2, 0x1ae, 0x1af, 0x3, 0x2, 0x2, 0x2, 0x1af, 
       0x3f, 0x3, 0x2, 0x2, 0x2, 0x1b0, 0x1b1, 0x7, 0x70, 0x2, 0x2, 0x1b1, 
       0x1b2, 0x7, 0x5d, 0x2, 0x2, 0x1b2, 0x1b3, 0x5, 0x36, 0x1c, 0x2, 0x1b3, 
       0x1b4, 0x7, 0x5e, 0x2, 0x2, 0x1b4, 0x1b6, 0x7, 0x7b, 0x2, 0x2, 0x1b5, 
       0x1b7, 0x5, 0xae, 0x58, 0x2, 0x1b6, 0x1b5, 0x3, 0x2, 0x2, 0x2, 0x1b6, 
       0x1b7, 0x3, 0x2, 0x2, 0x2, 0x1b7, 0x41, 0x3, 0x2, 0x2, 0x2, 0x1b8, 
       0x1bb, 0x7, 0x5f, 0x2, 0x2, 0x1b9, 0x1bc, 0x5, 0x84, 0x43, 0x2, 0x1ba, 
       0x1bc, 0x5, 0x42, 0x22, 0x2, 0x1bb, 0x1b9, 0x3, 0x2, 0x2, 0x2, 0x1bb, 
       0x1ba, 0x3, 0x2, 0x2, 0x2, 0x1bc, 0x1c4, 0x3, 0x2, 0x2, 0x2, 0x1bd, 
       0x1c0, 0x7, 0x66, 0x2, 0x2, 0x1be, 0x1c1, 0x5, 0x84, 0x43, 0x2, 0x1bf, 
       0x1c1, 0x5, 0x42, 0x22, 0x2, 0x1c0, 0x1be, 0x3, 0x2, 0x2, 0x2, 0x1c0, 
       0x1bf, 0x3, 0x2, 0x2, 0x2, 0x1c1, 0x1c3, 0x3, 0x2, 0x2, 0x2, 0x1c2, 
       0x1bd, 0x3, 0x2, 0x2, 0x2, 0x1c3, 0x1c6, 0x3, 0x2, 0x2, 0x2, 0x1c4, 
       0x1c2, 0x3, 0x2, 0x2, 0x2, 0x1c4, 0x1c5, 0x3, 0x2, 0x2, 0x2, 0x1c5, 
       0x1c7, 0x3, 0x2, 0x2, 0x2, 0x1c6, 0x1c4, 0x3, 0x2, 0x2, 0x2, 0x1c7, 
       0x1c8, 0x7, 0x60, 0x2, 0x2, 0x1c8, 0x43, 0x3, 0x2, 0x2, 0x2, 0x1c9, 
       0x1ca, 0x5, 0x2e, 0x18, 0x2, 0x1ca, 0x1d0, 0x7, 0x7b, 0x2, 0x2, 0x1cb, 
       0x1ce, 0x7, 0x67, 0x2, 0x2, 0x1cc, 0x1cf, 0x5, 0x42, 0x22, 0x2, 0x1cd, 
       0x1cf, 0x5, 0x84, 0x43, 0x2, 0x1ce, 0x1cc, 0x3, 0x2, 0x2, 0x2, 0x1ce, 
       0x1cd, 0x3, 0x2, 0x2, 0x2, 0x1cf, 0x1d1, 0x3, 0x2, 0x2, 0x2, 0x1d0, 
       0x1cb, 0x3, 0x2, 0x2, 0x2, 0x1d0, 0x1d1, 0x3, 0x2, 0x2, 0x2, 0x1d1, 
       0x45, 0x3, 0x2, 0x2, 0x2, 0x1d2, 0x1d8, 0x5, 0x3a, 0x1e, 0x2, 0x1d3, 
       0x1d8, 0x5, 0x3c, 0x1f, 0x2, 0x1d4, 0x1d8, 0x5, 0x3e, 0x20, 0x2, 
       0x1d5, 0x1d8, 0x5, 0x40, 0x21, 0x2, 0x1d6, 0x1d8, 0x5, 0x44, 0x23, 
       0x2, 0x1d7, 0x1d2, 0x3, 0x2, 0x2, 0x2, 0x1d7, 0x1d3, 0x3, 0x2, 0x2, 
       0x2, 0x1d7, 0x1d4, 0x3, 0x2, 0x2, 0x2, 0x1d7, 0x1d5, 0x3, 0x2, 0x2, 
       0x2, 0x1d7, 0x1d6, 0x3, 0x2, 0x2, 0x2, 0x1d8, 0x47, 0x3, 0x2, 0x2, 
       0x2, 0x1d9, 0x1da, 0x5, 0x34, 0x1b, 0x2, 0x1da, 0x1db, 0x7, 0x66, 
       0x2, 0x2, 0x1db, 0x1dd, 0x3, 0x2, 0x2, 0x2, 0x1dc, 0x1d9, 0x3, 0x2, 
       0x2, 0x2, 0x1dd, 0x1e0, 0x3, 0x2, 0x2, 0x2, 0x1de, 0x1dc, 0x3, 0x2, 
       0x2, 0x2, 0x1de, 0x1df, 0x3, 0x2, 0x2, 0x2, 0x1df, 0x1e1, 0x3, 0x2, 
       0x2, 0x2, 0x1e0, 0x1de, 0x3, 0x2, 0x2, 0x2, 0x1e1, 0x1e2, 0x5, 0x34, 
       0x1b, 0x2, 0x1e2, 0x49, 0x3, 0x2, 0x2, 0x2, 0x1e3, 0x1e4, 0x5, 0x28, 
       0x15, 0x2, 0x1e4, 0x1e5, 0x5, 0x1c, 0xf, 0x2, 0x1e5, 0x1e8, 0x3, 
       0x2, 0x2, 0x2, 0x1e6, 0x1e8, 0x5, 0x2a, 0x16, 0x2, 0x1e7, 0x1e3, 
       0x3, 0x2, 0x2, 0x2, 0x1e7, 0x1e6, 0x3, 0x2, 0x2, 0x2, 0x1e8, 0x1e9, 
       0x3, 0x2, 0x2, 0x2, 0x1e9, 0x1ea, 0x7, 0x7b, 0x2, 0x2, 0x1ea, 0x200, 
       0x3, 0x2, 0x2, 0x2, 0x1eb, 0x1ec, 0x7, 0xa, 0x2, 0x2, 0x1ec, 0x1ee, 
       0x7, 0x7b, 0x2, 0x2, 0x1ed, 0x1ef, 0x5, 0x1c, 0xf, 0x2, 0x1ee, 0x1ed, 
       0x3, 0x2, 0x2, 0x2, 0x1ee, 0x1ef, 0x3, 0x2, 0x2, 0x2, 0x1ef, 0x200, 
       0x3, 0x2, 0x2, 0x2, 0x1f0, 0x1f2, 0x7, 0x9, 0x2, 0x2, 0x1f1, 0x1f3, 
       0x5, 0x1c, 0xf, 0x2, 0x1f2, 0x1f1, 0x3, 0x2, 0x2, 0x2, 0x1f2, 0x1f3, 
       0x3, 0x2, 0x2, 0x2, 0x1f3, 0x1f4, 0x3, 0x2, 0x2, 0x2, 0x1f4, 0x200, 
       0x7, 0x7b, 0x2, 0x2, 0x1f5, 0x1f6, 0x7, 0x70, 0x2, 0x2, 0x1f6, 0x1f7, 
       0x7, 0x5d, 0x2, 0x2, 0x1f7, 0x1f8, 0x5, 0x36, 0x1c, 0x2, 0x1f8, 0x1f9, 
       0x7, 0x5e, 0x2, 0x2, 0x1f9, 0x1fa, 0x7, 0x7b, 0x2, 0x2, 0x1fa, 0x200, 
       0x3, 0x2, 0x2, 0x2, 0x1fb, 0x1fc, 0x9, 0x6, 0x2, 0x2, 0x1fc, 0x1fd, 
       0x5, 0x32, 0x1a, 0x2, 0x1fd, 0x1fe, 0x7, 0x7b, 0x2, 0x2, 0x1fe, 0x200, 
       0x3, 0x2, 0x2, 0x2, 0x1ff, 0x1e7, 0x3, 0x2, 0x2, 0x2, 0x1ff, 0x1eb, 
       0x3, 0x2, 0x2, 0x2, 0x1ff, 0x1f0, 0x3, 0x2, 0x2, 0x2, 0x1ff, 0x1f5, 
       0x3, 0x2, 0x2, 0x2, 0x1ff, 0x1fb, 0x3, 0x2, 0x2, 0x2, 0x200, 0x4b, 
       0x3, 0x2, 0x2, 0x2, 0x201, 0x206, 0x5, 0x4a, 0x26, 0x2, 0x202, 0x203, 
       0x7, 0x66, 0x2, 0x2, 0x203, 0x205, 0x5, 0x4a, 0x26, 0x2, 0x204, 0x202, 
       0x3, 0x2, 0x2, 0x2, 0x205, 0x208, 0x3, 0x2, 0x2, 0x2, 0x206, 0x204, 
       0x3, 0x2, 0x2, 0x2, 0x206, 0x207, 0x3, 0x2, 0x2, 0x2, 0x207, 0x4d, 
       0x3, 0x2, 0x2, 0x2, 0x208, 0x206, 0x3, 0x2, 0x2, 0x2, 0x209, 0x20c, 
       0x5, 0x4a, 0x26, 0x2, 0x20a, 0x20c, 0x5, 0x22, 0x12, 0x2, 0x20b, 
       0x209, 0x3, 0x2, 0x2, 0x2, 0x20b, 0x20a, 0x3, 0x2, 0x2, 0x2, 0x20c, 
       0x4f, 0x3, 0x2, 0x2, 0x2, 0x20d, 0x20e, 0x5, 0x4e, 0x28, 0x2, 0x20e, 
       0x20f, 0x7, 0x66, 0x2, 0x2, 0x20f, 0x211, 0x3, 0x2, 0x2, 0x2, 0x210, 
       0x20d, 0x3, 0x2, 0x2, 0x2, 0x211, 0x214, 0x3, 0x2, 0x2, 0x2, 0x212, 
       0x210, 0x3, 0x2, 0x2, 0x2, 0x212, 0x213, 0x3, 0x2, 0x2, 0x2, 0x213, 
       0x215, 0x3, 0x2, 0x2, 0x2, 0x214, 0x212, 0x3, 0x2, 0x2, 0x2, 0x215, 
       0x216, 0x5, 0x4e, 0x28, 0x2, 0x216, 0x51, 0x3, 0x2, 0x2, 0x2, 0x217, 
       0x218, 0x7, 0x10, 0x2, 0x2, 0x218, 0x219, 0x7, 0x7b, 0x2, 0x2, 0x219, 
       0x21a, 0x7, 0x67, 0x2, 0x2, 0x21a, 0x21b, 0x5, 0x54, 0x2b, 0x2, 0x21b, 
       0x21c, 0x7, 0x64, 0x2, 0x2, 0x21c, 0x53, 0x3, 0x2, 0x2, 0x2, 0x21d, 
       0x21e, 0x8, 0x2b, 0x1, 0x2, 0x21e, 0x21f, 0x5, 0x84, 0x43, 0x2, 0x21f, 
       0x225, 0x3, 0x2, 0x2, 0x2, 0x220, 0x221, 0xc, 0x3, 0x2, 0x2, 0x221, 
       0x222, 0x7, 0x11, 0x2, 0x2, 0x222, 0x224, 0x5, 0x54, 0x2b, 0x4, 0x223, 
       0x220, 0x3, 0x2, 0x2, 0x2, 0x224, 0x227, 0x3, 0x2, 0x2, 0x2, 0x225, 
       0x223, 0x3, 0x2, 0x2, 0x2, 0x225, 0x226, 0x3, 0x2, 0x2, 0x2, 0x226, 
       0x55, 0x3, 0x2, 0x2, 0x2, 0x227, 0x225, 0x3, 0x2, 0x2, 0x2, 0x228, 
       0x22a, 0x5, 0x84, 0x43, 0x2, 0x229, 0x228, 0x3, 0x2, 0x2, 0x2, 0x229, 
       0x22a, 0x3, 0x2, 0x2, 0x2, 0x22a, 0x22b, 0x3, 0x2, 0x2, 0x2, 0x22b, 
       0x22d, 0x7, 0x63, 0x2, 0x2, 0x22c, 0x22e, 0x5, 0x84, 0x43, 0x2, 0x22d, 
       0x22c, 0x3, 0x2, 0x2, 0x2, 0x22d, 0x22e, 0x3, 0x2, 0x2, 0x2, 0x22e, 
       0x231, 0x3, 0x2, 0x2, 0x2, 0x22f, 0x230, 0x7, 0x63, 0x2, 0x2, 0x230, 
       0x232, 0x5, 0x84, 0x43, 0x2, 0x231, 0x22f, 0x3, 0x2, 0x2, 0x2, 0x231, 
       0x232, 0x3, 0x2, 0x2, 0x2, 0x232, 0x57, 0x3, 0x2, 0x2, 0x2, 0x233, 
       0x234, 0x7, 0x12, 0x2, 0x2, 0x234, 0x235, 0x5, 0x5a, 0x2e, 0x2, 0x235, 
       0x236, 0x5, 0x5e, 0x30, 0x2, 0x236, 0x59, 0x3, 0x2, 0x2, 0x2, 0x237, 
       0x23d, 0x5, 0x5c, 0x2f, 0x2, 0x238, 0x23a, 0x7, 0x61, 0x2, 0x2, 0x239, 
       0x23b, 0x5, 0x1e, 0x10, 0x2, 0x23a, 0x239, 0x3, 0x2, 0x2, 0x2, 0x23a, 
       0x23b, 0x3, 0x2, 0x2, 0x2, 0x23b, 0x23c, 0x3, 0x2, 0x2, 0x2, 0x23c, 
       0x23e, 0x7, 0x62, 0x2, 0x2, 0x23d, 0x238, 0x3, 0x2, 0x2, 0x2, 0x23d, 
       0x23e, 0x3, 0x2, 0x2, 0x2, 0x23e, 0x23f, 0x3, 0x2, 0x2, 0x2, 0x23f, 
       0x240, 0x5, 0x1e, 0x10, 0x2, 0x240, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x241, 
       0x242, 0x9, 0x7, 0x2, 0x2, 0x242, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x243, 
       0x248, 0x7, 0x5f, 0x2, 0x2, 0x244, 0x247, 0x5, 0x64, 0x33, 0x2, 0x245, 
       0x247, 0x5, 0x60, 0x31, 0x2, 0x246, 0x244, 0x3, 0x2, 0x2, 0x2, 0x246, 
       0x245, 0x3, 0x2, 0x2, 0x2, 0x247, 0x24a, 0x3, 0x2, 0x2, 0x2, 0x248, 
       0x246, 0x3, 0x2, 0x2, 0x2, 0x248, 0x249, 0x3, 0x2, 0x2, 0x2, 0x249, 
       0x24b, 0x3, 0x2, 0x2, 0x2, 0x24a, 0x248, 0x3, 0x2, 0x2, 0x2, 0x24b, 
       0x24c, 0x7, 0x60, 0x2, 0x2, 0x24c, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x24d, 
       0x24e, 0x5, 0xba, 0x5e, 0x2, 0x24e, 0x24f, 0x5, 0x62, 0x32, 0x2, 
       0x24f, 0x61, 0x3, 0x2, 0x2, 0x2, 0x250, 0x25a, 0x5, 0x64, 0x33, 0x2, 
       0x251, 0x255, 0x7, 0x5f, 0x2, 0x2, 0x252, 0x254, 0x5, 0x64, 0x33, 
       0x2, 0x253, 0x252, 0x3, 0x2, 0x2, 0x2, 0x254, 0x257, 0x3, 0x2, 0x2, 
       0x2, 0x255, 0x253, 0x3, 0x2, 0x2, 0x2, 0x255, 0x256, 0x3, 0x2, 0x2, 
       0x2, 0x256, 0x258, 0x3, 0x2, 0x2, 0x2, 0x257, 0x255, 0x3, 0x2, 0x2, 
       0x2, 0x258, 0x25a, 0x7, 0x60, 0x2, 0x2, 0x259, 0x250, 0x3, 0x2, 0x2, 
       0x2, 0x259, 0x251, 0x3, 0x2, 0x2, 0x2, 0x25a, 0x63, 0x3, 0x2, 0x2, 
       0x2, 0x25b, 0x25c, 0x5, 0x66, 0x34, 0x2, 0x25c, 0x25d, 0x7, 0x64, 
       0x2, 0x2, 0x25d, 0x260, 0x3, 0x2, 0x2, 0x2, 0x25e, 0x260, 0x5, 0xd8, 
       0x6d, 0x2, 0x25f, 0x25b, 0x3, 0x2, 0x2, 0x2, 0x25f, 0x25e, 0x3, 0x2, 
       0x2, 0x2, 0x260, 0x65, 0x3, 0x2, 0x2, 0x2, 0x261, 0x267, 0x5, 0x78, 
       0x3d, 0x2, 0x262, 0x267, 0x5, 0x68, 0x35, 0x2, 0x263, 0x267, 0x5, 
       0x6c, 0x37, 0x2, 0x264, 0x267, 0x5, 0x6a, 0x36, 0x2, 0x265, 0x267, 
       0x5, 0x70, 0x39, 0x2, 0x266, 0x261, 0x3, 0x2, 0x2, 0x2, 0x266, 0x262, 
       0x3, 0x2, 0x2, 0x2, 0x266, 0x263, 0x3, 0x2, 0x2, 0x2, 0x266, 0x264, 
       0x3, 0x2, 0x2, 0x2, 0x266, 0x265, 0x3, 0x2, 0x2, 0x2, 0x267, 0x67, 
       0x3, 0x2, 0x2, 0x2, 0x268, 0x26a, 0x5, 0x72, 0x3a, 0x2, 0x269, 0x268, 
       0x3, 0x2, 0x2, 0x2, 0x26a, 0x26d, 0x3, 0x2, 0x2, 0x2, 0x26b, 0x269, 
       0x3, 0x2, 0x2, 0x2, 0x26b, 0x26c, 0x3, 0x2, 0x2, 0x2, 0x26c, 0x26e, 
       0x3, 0x2, 0x2, 0x2, 0x26d, 0x26b, 0x3, 0x2, 0x2, 0x2, 0x26e, 0x26f, 
       0x7, 0x15, 0x2, 0x2, 0x26f, 0x270, 0x7, 0x61, 0x2, 0x2, 0x270, 0x271, 
       0x5, 0x84, 0x43, 0x2, 0x271, 0x27a, 0x7, 0x62, 0x2, 0x2, 0x272, 0x277, 
       0x5, 0xa0, 0x51, 0x2, 0x273, 0x274, 0x7, 0x66, 0x2, 0x2, 0x274, 0x276, 
       0x5, 0xa0, 0x51, 0x2, 0x275, 0x273, 0x3, 0x2, 0x2, 0x2, 0x276, 0x279, 
       0x3, 0x2, 0x2, 0x2, 0x277, 0x275, 0x3, 0x2, 0x2, 0x2, 0x277, 0x278, 
       0x3, 0x2, 0x2, 0x2, 0x278, 0x27b, 0x3, 0x2, 0x2, 0x2, 0x279, 0x277, 
       0x3, 0x2, 0x2, 0x2, 0x27a, 0x272, 0x3, 0x2, 0x2, 0x2, 0x27a, 0x27b, 
       0x3, 0x2, 0x2, 0x2, 0x27b, 0x69, 0x3, 0x2, 0x2, 0x2, 0x27c, 0x27d, 
       0x7, 0x16, 0x2, 0x2, 0x27d, 0x27e, 0x5, 0xa0, 0x51, 0x2, 0x27e, 0x6b, 
       0x3, 0x2, 0x2, 0x2, 0x27f, 0x280, 0x7, 0x17, 0x2, 0x2, 0x280, 0x281, 
       0x5, 0xa0, 0x51, 0x2, 0x281, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x282, 0x285, 
       0x5, 0x6c, 0x37, 0x2, 0x283, 0x284, 0x7, 0x68, 0x2, 0x2, 0x284, 0x286, 
       0x5, 0xa0, 0x51, 0x2, 0x285, 0x283, 0x3, 0x2, 0x2, 0x2, 0x285, 0x286, 
       0x3, 0x2, 0x2, 0x2, 0x286, 0x28c, 0x3, 0x2, 0x2, 0x2, 0x287, 0x288, 
       0x5, 0xa0, 0x51, 0x2, 0x288, 0x289, 0x7, 0x67, 0x2, 0x2, 0x289, 0x28a, 
       0x5, 0x6c, 0x37, 0x2, 0x28a, 0x28c, 0x3, 0x2, 0x2, 0x2, 0x28b, 0x282, 
       0x3, 0x2, 0x2, 0x2, 0x28b, 0x287, 0x3, 0x2, 0x2, 0x2, 0x28c, 0x6f, 
       0x3, 0x2, 0x2, 0x2, 0x28d, 0x296, 0x7, 0x18, 0x2, 0x2, 0x28e, 0x293, 
       0x5, 0xa0, 0x51, 0x2, 0x28f, 0x290, 0x7, 0x66, 0x2, 0x2, 0x290, 0x292, 
       0x5, 0xa0, 0x51, 0x2, 0x291, 0x28f, 0x3, 0x2, 0x2, 0x2, 0x292, 0x295, 
       0x3, 0x2, 0x2, 0x2, 0x293, 0x291, 0x3, 0x2, 0x2, 0x2, 0x293, 0x294, 
       0x3, 0x2, 0x2, 0x2, 0x294, 0x297, 0x3, 0x2, 0x2, 0x2, 0x295, 0x293, 
       0x3, 0x2, 0x2, 0x2, 0x296, 0x28e, 0x3, 0x2, 0x2, 0x2, 0x296, 0x297, 
       0x3, 0x2, 0x2, 0x2, 0x297, 0x71, 0x3, 0x2, 0x2, 0x2, 0x298, 0x29c, 
       0x7, 0x19, 0x2, 0x2, 0x299, 0x29c, 0x5, 0x74, 0x3b, 0x2, 0x29a, 0x29c, 
       0x5, 0x76, 0x3c, 0x2, 0x29b, 0x298, 0x3, 0x2, 0x2, 0x2, 0x29b, 0x299, 
       0x3, 0x2, 0x2, 0x2, 0x29b, 0x29a, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x29d, 
       0x3, 0x2, 0x2, 0x2, 0x29d, 0x29e, 0x7, 0x1a, 0x2, 0x2, 0x29e, 0x73, 
       0x3, 0x2, 0x2, 0x2, 0x29f, 0x2a0, 0x7, 0x1b, 0x2, 0x2, 0x2a0, 0x2a1, 
       0x7, 0x61, 0x2, 0x2, 0x2a1, 0x2a2, 0x5, 0x84, 0x43, 0x2, 0x2a2, 0x2a3, 
       0x7, 0x62, 0x2, 0x2, 0x2a3, 0x75, 0x3, 0x2, 0x2, 0x2, 0x2a4, 0x2a9, 
       0x9, 0x8, 0x2, 0x2, 0x2a5, 0x2a6, 0x7, 0x61, 0x2, 0x2, 0x2a6, 0x2a7, 
       0x5, 0x84, 0x43, 0x2, 0x2a7, 0x2a8, 0x7, 0x62, 0x2, 0x2, 0x2a8, 0x2aa, 
       0x3, 0x2, 0x2, 0x2, 0x2a9, 0x2a5, 0x3, 0x2, 0x2, 0x2, 0x2a9, 0x2aa, 
       0x3, 0x2, 0x2, 0x2, 0x2aa, 0x77, 0x3, 0x2, 0x2, 0x2, 0x2ab, 0x2ad, 
       0x5, 0x72, 0x3a, 0x2, 0x2ac, 0x2ab, 0x3, 0x2, 0x2, 0x2, 0x2ad, 0x2b0, 
       0x3, 0x2, 0x2, 0x2, 0x2ae, 0x2ac, 0x3, 0x2, 0x2, 0x2, 0x2ae, 0x2af, 
       0x3, 0x2, 0x2, 0x2, 0x2af, 0x2b1, 0x3, 0x2, 0x2, 0x2, 0x2b0, 0x2ae, 
       0x3, 0x2, 0x2, 0x2, 0x2b1, 0x2b6, 0x5, 0x5c, 0x2f, 0x2, 0x2b2, 0x2b3, 
       0x7, 0x61, 0x2, 0x2, 0x2b3, 0x2b4, 0x5, 0xac, 0x57, 0x2, 0x2b4, 0x2b5, 
       0x7, 0x62, 0x2, 0x2, 0x2b5, 0x2b7, 0x3, 0x2, 0x2, 0x2, 0x2b6, 0x2b2, 
       0x3, 0x2, 0x2, 0x2, 0x2b6, 0x2b7, 0x3, 0x2, 0x2, 0x2, 0x2b7, 0x2b8, 
       0x3, 0x2, 0x2, 0x2, 0x2b8, 0x2bd, 0x5, 0xa0, 0x51, 0x2, 0x2b9, 0x2ba, 
       0x7, 0x66, 0x2, 0x2, 0x2ba, 0x2bc, 0x5, 0xa0, 0x51, 0x2, 0x2bb, 0x2b9, 
       0x3, 0x2, 0x2, 0x2, 0x2bc, 0x2bf, 0x3, 0x2, 0x2, 0x2, 0x2bd, 0x2bb, 
       0x3, 0x2, 0x2, 0x2, 0x2bd, 0x2be, 0x3, 0x2, 0x2, 0x2, 0x2be, 0x79, 
       0x3, 0x2, 0x2, 0x2, 0x2bf, 0x2bd, 0x3, 0x2, 0x2, 0x2, 0x2c0, 0x2c1, 
       0x9, 0x9, 0x2, 0x2, 0x2c1, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x2c2, 0x2c3, 
       0x9, 0xa, 0x2, 0x2, 0x2c3, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x2c4, 0x2c5, 
       0x9, 0xb, 0x2, 0x2, 0x2c5, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x2c6, 0x2c7, 
       0x9, 0xc, 0x2, 0x2, 0x2c7, 0x81, 0x3, 0x2, 0x2, 0x2, 0x2c8, 0x2c9, 
       0x5, 0x84, 0x43, 0x2, 0x2c9, 0x2ca, 0x7, 0x64, 0x2, 0x2, 0x2ca, 0x83, 
       0x3, 0x2, 0x2, 0x2, 0x2cb, 0x2cc, 0x8, 0x43, 0x1, 0x2, 0x2cc, 0x2d0, 
       0x5, 0xa2, 0x52, 0x2, 0x2cd, 0x2d0, 0x5, 0x98, 0x4d, 0x2, 0x2ce, 
       0x2d0, 0x5, 0x86, 0x44, 0x2, 0x2cf, 0x2cb, 0x3, 0x2, 0x2, 0x2, 0x2cf, 
       0x2cd, 0x3, 0x2, 0x2, 0x2, 0x2cf, 0x2ce, 0x3, 0x2, 0x2, 0x2, 0x2d0, 
       0x2d6, 0x3, 0x2, 0x2, 0x2, 0x2d1, 0x2d2, 0xc, 0x3, 0x2, 0x2, 0x2d2, 
       0x2d3, 0x7, 0x27, 0x2, 0x2, 0x2d3, 0x2d5, 0x5, 0x86, 0x44, 0x2, 0x2d4, 
       0x2d1, 0x3, 0x2, 0x2, 0x2, 0x2d5, 0x2d8, 0x3, 0x2, 0x2, 0x2, 0x2d6, 
       0x2d4, 0x3, 0x2, 0x2, 0x2, 0x2d6, 0x2d7, 0x3, 0x2, 0x2, 0x2, 0x2d7, 
       0x85, 0x3, 0x2, 0x2, 0x2, 0x2d8, 0x2d6, 0x3, 0x2, 0x2, 0x2, 0x2d9, 
       0x2da, 0x8, 0x44, 0x1, 0x2, 0x2da, 0x2db, 0x5, 0x88, 0x45, 0x2, 0x2db, 
       0x2e1, 0x3, 0x2, 0x2, 0x2, 0x2dc, 0x2dd, 0xc, 0x3, 0x2, 0x2, 0x2dd, 
       0x2de, 0x7, 0x26, 0x2, 0x2, 0x2de, 0x2e0, 0x5, 0x88, 0x45, 0x2, 0x2df, 
       0x2dc, 0x3, 0x2, 0x2, 0x2, 0x2e0, 0x2e3, 0x3, 0x2, 0x2, 0x2, 0x2e1, 
       0x2df, 0x3, 0x2, 0x2, 0x2, 0x2e1, 0x2e2, 0x3, 0x2, 0x2, 0x2, 0x2e2, 
       0x87, 0x3, 0x2, 0x2, 0x2, 0x2e3, 0x2e1, 0x3, 0x2, 0x2, 0x2, 0x2e4, 
       0x2e5, 0x8, 0x45, 0x1, 0x2, 0x2e5, 0x2e6, 0x5, 0x8a, 0x46, 0x2, 0x2e6, 
       0x2ec, 0x3, 0x2, 0x2, 0x2, 0x2e7, 0x2e8, 0xc, 0x3, 0x2, 0x2, 0x2e8, 
       0x2e9, 0x7, 0x28, 0x2, 0x2, 0x2e9, 0x2eb, 0x5, 0x8a, 0x46, 0x2, 0x2ea, 
       0x2e7, 0x3, 0x2, 0x2, 0x2, 0x2eb, 0x2ee, 0x3, 0x2, 0x2, 0x2, 0x2ec, 
       0x2ea, 0x3, 0x2, 0x2, 0x2, 0x2ec, 0x2ed, 0x3, 0x2, 0x2, 0x2, 0x2ed, 
       0x89, 0x3, 0x2, 0x2, 0x2, 0x2ee, 0x2ec, 0x3, 0x2, 0x2, 0x2, 0x2ef, 
       0x2f0, 0x8, 0x46, 0x1, 0x2, 0x2f0, 0x2f1, 0x5, 0x8c, 0x47, 0x2, 0x2f1, 
       0x2f7, 0x3, 0x2, 0x2, 0x2, 0x2f2, 0x2f3, 0xc, 0x3, 0x2, 0x2, 0x2f3, 
       0x2f4, 0x7, 0x29, 0x2, 0x2, 0x2f4, 0x2f6, 0x5, 0x8c, 0x47, 0x2, 0x2f5, 
       0x2f2, 0x3, 0x2, 0x2, 0x2, 0x2f6, 0x2f9, 0x3, 0x2, 0x2, 0x2, 0x2f7, 
       0x2f5, 0x3, 0x2, 0x2, 0x2, 0x2f7, 0x2f8, 0x3, 0x2, 0x2, 0x2, 0x2f8, 
       0x8b, 0x3, 0x2, 0x2, 0x2, 0x2f9, 0x2f7, 0x3, 0x2, 0x2, 0x2, 0x2fa, 
       0x2fb, 0x8, 0x47, 0x1, 0x2, 0x2fb, 0x2fc, 0x5, 0x8e, 0x48, 0x2, 0x2fc, 
       0x302, 0x3, 0x2, 0x2, 0x2, 0x2fd, 0x2fe, 0xc, 0x3, 0x2, 0x2, 0x2fe, 
       0x2ff, 0x7, 0x2a, 0x2, 0x2, 0x2ff, 0x301, 0x5, 0x8e, 0x48, 0x2, 0x300, 
       0x2fd, 0x3, 0x2, 0x2, 0x2, 0x301, 0x304, 0x3, 0x2, 0x2, 0x2, 0x302, 
       0x300, 0x3, 0x2, 0x2, 0x2, 0x302, 0x303, 0x3, 0x2, 0x2, 0x2, 0x303, 
       0x8d, 0x3, 0x2, 0x2, 0x2, 0x304, 0x302, 0x3, 0x2, 0x2, 0x2, 0x305, 
       0x306, 0x8, 0x48, 0x1, 0x2, 0x306, 0x307, 0x5, 0x90, 0x49, 0x2, 0x307, 
       0x30e, 0x3, 0x2, 0x2, 0x2, 0x308, 0x309, 0xc, 0x3, 0x2, 0x2, 0x309, 
       0x30a, 0x5, 0x7e, 0x40, 0x2, 0x30a, 0x30b, 0x5, 0x90, 0x49, 0x2, 
       0x30b, 0x30d, 0x3, 0x2, 0x2, 0x2, 0x30c, 0x308, 0x3, 0x2, 0x2, 0x2, 
       0x30d, 0x310, 0x3, 0x2, 0x2, 0x2, 0x30e, 0x30c, 0x3, 0x2, 0x2, 0x2, 
       0x30e, 0x30f, 0x3, 0x2, 0x2, 0x2, 0x30f, 0x8f, 0x3, 0x2, 0x2, 0x2, 
       0x310, 0x30e, 0x3, 0x2, 0x2, 0x2, 0x311, 0x312, 0x8, 0x49, 0x1, 0x2, 
       0x312, 0x313, 0x5, 0x92, 0x4a, 0x2, 0x313, 0x31a, 0x3, 0x2, 0x2, 
       0x2, 0x314, 0x315, 0xc, 0x3, 0x2, 0x2, 0x315, 0x316, 0x5, 0x7c, 0x3f, 
       0x2, 0x316, 0x317, 0x5, 0x92, 0x4a, 0x2, 0x317, 0x319, 0x3, 0x2, 
       0x2, 0x2, 0x318, 0x314, 0x3, 0x2, 0x2, 0x2, 0x319, 0x31c, 0x3, 0x2, 
       0x2, 0x2, 0x31a, 0x318, 0x3, 0x2, 0x2, 0x2, 0x31a, 0x31b, 0x3, 0x2, 
       0x2, 0x2, 0x31b, 0x91, 0x3, 0x2, 0x2, 0x2, 0x31c, 0x31a, 0x3, 0x2, 
       0x2, 0x2, 0x31d, 0x31e, 0x8, 0x4a, 0x1, 0x2, 0x31e, 0x31f, 0x5, 0x94, 
       0x4b, 0x2, 0x31f, 0x325, 0x3, 0x2, 0x2, 0x2, 0x320, 0x321, 0xc, 0x3, 
       0x2, 0x2, 0x321, 0x322, 0x9, 0xd, 0x2, 0x2, 0x322, 0x324, 0x5, 0x94, 
       0x4b, 0x2, 0x323, 0x320, 0x3, 0x2, 0x2, 0x2, 0x324, 0x327, 0x3, 0x2, 
       0x2, 0x2, 0x325, 0x323, 0x3, 0x2, 0x2, 0x2, 0x325, 0x326, 0x3, 0x2, 
       0x2, 0x2, 0x326, 0x93, 0x3, 0x2, 0x2, 0x2, 0x327, 0x325, 0x3, 0x2, 
       0x2, 0x2, 0x328, 0x329, 0x8, 0x4b, 0x1, 0x2, 0x329, 0x32a, 0x5, 0x96, 
       0x4c, 0x2, 0x32a, 0x330, 0x3, 0x2, 0x2, 0x2, 0x32b, 0x32c, 0xc, 0x3, 
       0x2, 0x2, 0x32c, 0x32d, 0x9, 0xe, 0x2, 0x2, 0x32d, 0x32f, 0x5, 0x96, 
       0x4c, 0x2, 0x32e, 0x32b, 0x3, 0x2, 0x2, 0x2, 0x32f, 0x332, 0x3, 0x2, 
       0x2, 0x2, 0x330, 0x32e, 0x3, 0x2, 0x2, 0x2, 0x330, 0x331, 0x3, 0x2, 
       0x2, 0x2, 0x331, 0x95, 0x3, 0x2, 0x2, 0x2, 0x332, 0x330, 0x3, 0x2, 
       0x2, 0x2, 0x333, 0x334, 0x8, 0x4c, 0x1, 0x2, 0x334, 0x335, 0x5, 0x98, 
       0x4d, 0x2, 0x335, 0x33b, 0x3, 0x2, 0x2, 0x2, 0x336, 0x337, 0xc, 0x3, 
       0x2, 0x2, 0x337, 0x338, 0x9, 0xf, 0x2, 0x2, 0x338, 0x33a, 0x5, 0x98, 
       0x4d, 0x2, 0x339, 0x336, 0x3, 0x2, 0x2, 0x2, 0x33a, 0x33d, 0x3, 0x2, 
       0x2, 0x2, 0x33b, 0x339, 0x3, 0x2, 0x2, 0x2, 0x33b, 0x33c, 0x3, 0x2, 
       0x2, 0x2, 0x33c, 0x97, 0x3, 0x2, 0x2, 0x2, 0x33d, 0x33b, 0x3, 0x2, 
       0x2, 0x2, 0x33e, 0x340, 0x5, 0x7a, 0x3e, 0x2, 0x33f, 0x33e, 0x3, 
       0x2, 0x2, 0x2, 0x33f, 0x340, 0x3, 0x2, 0x2, 0x2, 0x340, 0x341, 0x3, 
       0x2, 0x2, 0x2, 0x341, 0x342, 0x5, 0x9a, 0x4e, 0x2, 0x342, 0x99, 0x3, 
       0x2, 0x2, 0x2, 0x343, 0x344, 0x8, 0x4e, 0x1, 0x2, 0x344, 0x345, 0x5, 
       0x9e, 0x50, 0x2, 0x345, 0x34b, 0x3, 0x2, 0x2, 0x2, 0x346, 0x347, 
       0xc, 0x3, 0x2, 0x2, 0x347, 0x348, 0x7, 0x2d, 0x2, 0x2, 0x348, 0x34a, 
       0x5, 0x9e, 0x50, 0x2, 0x349, 0x346, 0x3, 0x2, 0x2, 0x2, 0x34a, 0x34d, 
       0x3, 0x2, 0x2, 0x2, 0x34b, 0x349, 0x3, 0x2, 0x2, 0x2, 0x34b, 0x34c, 
       0x3, 0x2, 0x2, 0x2, 0x34c, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x34d, 0x34b, 
       0x3, 0x2, 0x2, 0x2, 0x34e, 0x35e, 0x7, 0x5d, 0x2, 0x2, 0x34f, 0x35f, 
       0x5, 0xb2, 0x5a, 0x2, 0x350, 0x353, 0x5, 0x84, 0x43, 0x2, 0x351, 
       0x353, 0x5, 0x56, 0x2c, 0x2, 0x352, 0x350, 0x3, 0x2, 0x2, 0x2, 0x352, 
       0x351, 0x3, 0x2, 0x2, 0x2, 0x353, 0x35b, 0x3, 0x2, 0x2, 0x2, 0x354, 
       0x357, 0x7, 0x66, 0x2, 0x2, 0x355, 0x358, 0x5, 0x84, 0x43, 0x2, 0x356, 
       0x358, 0x5, 0x56, 0x2c, 0x2, 0x357, 0x355, 0x3, 0x2, 0x2, 0x2, 0x357, 
       0x356, 0x3, 0x2, 0x2, 0x2, 0x358, 0x35a, 0x3, 0x2, 0x2, 0x2, 0x359, 
       0x354, 0x3, 0x2, 0x2, 0x2, 0x35a, 0x35d, 0x3, 0x2, 0x2, 0x2, 0x35b, 
       0x359, 0x3, 0x2, 0x2, 0x2, 0x35b, 0x35c, 0x3, 0x2, 0x2, 0x2, 0x35c, 
       0x35f, 0x3, 0x2, 0x2, 0x2, 0x35d, 0x35b, 0x3, 0x2, 0x2, 0x2, 0x35e, 
       0x34f, 0x3, 0x2, 0x2, 0x2, 0x35e, 0x352, 0x3, 0x2, 0x2, 0x2, 0x35f, 
       0x360, 0x3, 0x2, 0x2, 0x2, 0x360, 0x361, 0x7, 0x5e, 0x2, 0x2, 0x361, 
       0x9d, 0x3, 0x2, 0x2, 0x2, 0x362, 0x363, 0x8, 0x50, 0x1, 0x2, 0x363, 
       0x364, 0x5, 0xa2, 0x52, 0x2, 0x364, 0x369, 0x3, 0x2, 0x2, 0x2, 0x365, 
       0x366, 0xc, 0x3, 0x2, 0x2, 0x366, 0x368, 0x5, 0x9c, 0x4f, 0x2, 0x367, 
       0x365, 0x3, 0x2, 0x2, 0x2, 0x368, 0x36b, 0x3, 0x2, 0x2, 0x2, 0x369, 
       0x367, 0x3, 0x2, 0x2, 0x2, 0x369, 0x36a, 0x3, 0x2, 0x2, 0x2, 0x36a, 
       0x9f, 0x3, 0x2, 0x2, 0x2, 0x36b, 0x369, 0x3, 0x2, 0x2, 0x2, 0x36c, 
       0x370, 0x7, 0x7b, 0x2, 0x2, 0x36d, 0x36f, 0x5, 0x9c, 0x4f, 0x2, 0x36e, 
       0x36d, 0x3, 0x2, 0x2, 0x2, 0x36f, 0x372, 0x3, 0x2, 0x2, 0x2, 0x370, 
       0x36e, 0x3, 0x2, 0x2, 0x2, 0x370, 0x371, 0x3, 0x2, 0x2, 0x2, 0x371, 
       0xa1, 0x3, 0x2, 0x2, 0x2, 0x372, 0x370, 0x3, 0x2, 0x2, 0x2, 0x373, 
       0x382, 0x7, 0x77, 0x2, 0x2, 0x374, 0x382, 0x7, 0x7a, 0x2, 0x2, 0x375, 
       0x382, 0x7, 0x7c, 0x2, 0x2, 0x376, 0x382, 0x7, 0x6f, 0x2, 0x2, 0x377, 
       0x382, 0x5, 0xa4, 0x53, 0x2, 0x378, 0x382, 0x7, 0x7b, 0x2, 0x2, 0x379, 
       0x382, 0x7, 0x7e, 0x2, 0x2, 0x37a, 0x382, 0x5, 0xa6, 0x54, 0x2, 0x37b, 
       0x382, 0x5, 0xc6, 0x64, 0x2, 0x37c, 0x382, 0x5, 0xd2, 0x6a, 0x2, 
       0x37d, 0x37e, 0x7, 0x61, 0x2, 0x2, 0x37e, 0x37f, 0x5, 0x84, 0x43, 
       0x2, 0x37f, 0x380, 0x7, 0x62, 0x2, 0x2, 0x380, 0x382, 0x3, 0x2, 0x2, 
       0x2, 0x381, 0x373, 0x3, 0x2, 0x2, 0x2, 0x381, 0x374, 0x3, 0x2, 0x2, 
       0x2, 0x381, 0x375, 0x3, 0x2, 0x2, 0x2, 0x381, 0x376, 0x3, 0x2, 0x2, 
       0x2, 0x381, 0x377, 0x3, 0x2, 0x2, 0x2, 0x381, 0x378, 0x3, 0x2, 0x2, 
       0x2, 0x381, 0x379, 0x3, 0x2, 0x2, 0x2, 0x381, 0x37a, 0x3, 0x2, 0x2, 
       0x2, 0x381, 0x37b, 0x3, 0x2, 0x2, 0x2, 0x381, 0x37c, 0x3, 0x2, 0x2, 
       0x2, 0x381, 0x37d, 0x3, 0x2, 0x2, 0x2, 0x382, 0xa3, 0x3, 0x2, 0x2, 
       0x2, 0x383, 0x384, 0x9, 0x10, 0x2, 0x2, 0x384, 0xa5, 0x3, 0x2, 0x2, 
       0x2, 0x385, 0x389, 0x5, 0xa8, 0x55, 0x2, 0x386, 0x389, 0x5, 0xaa, 
       0x56, 0x2, 0x387, 0x389, 0x7, 0x75, 0x2, 0x2, 0x388, 0x385, 0x3, 
       0x2, 0x2, 0x2, 0x388, 0x386, 0x3, 0x2, 0x2, 0x2, 0x388, 0x387, 0x3, 
       0x2, 0x2, 0x2, 0x389, 0x38a, 0x3, 0x2, 0x2, 0x2, 0x38a, 0x38b, 0x7, 
       0x61, 0x2, 0x2, 0x38b, 0x38c, 0x5, 0xac, 0x57, 0x2, 0x38c, 0x38d, 
       0x7, 0x62, 0x2, 0x2, 0x38d, 0xa7, 0x3, 0x2, 0x2, 0x2, 0x38e, 0x38f, 
       0x9, 0x11, 0x2, 0x2, 0x38f, 0xa9, 0x3, 0x2, 0x2, 0x2, 0x390, 0x391, 
       0x5, 0x34, 0x1b, 0x2, 0x391, 0xab, 0x3, 0x2, 0x2, 0x2, 0x392, 0x397, 
       0x5, 0x84, 0x43, 0x2, 0x393, 0x394, 0x7, 0x66, 0x2, 0x2, 0x394, 0x396, 
       0x5, 0x84, 0x43, 0x2, 0x395, 0x393, 0x3, 0x2, 0x2, 0x2, 0x396, 0x399, 
       0x3, 0x2, 0x2, 0x2, 0x397, 0x395, 0x3, 0x2, 0x2, 0x2, 0x397, 0x398, 
       0x3, 0x2, 0x2, 0x2, 0x398, 0xad, 0x3, 0x2, 0x2, 0x2, 0x399, 0x397, 
       0x3, 0x2, 0x2, 0x2, 0x39a, 0x39b, 0x7, 0x67, 0x2, 0x2, 0x39b, 0x39c, 
       0x5, 0x84, 0x43, 0x2, 0x39c, 0xaf, 0x3, 0x2, 0x2, 0x2, 0x39d, 0x39e, 
       0x9, 0x12, 0x2, 0x2, 0x39e, 0xb1, 0x3, 0x2, 0x2, 0x2, 0x39f, 0x3a0, 
       0x7, 0x5f, 0x2, 0x2, 0x3a0, 0x3a5, 0x5, 0x84, 0x43, 0x2, 0x3a1, 0x3a2, 
       0x7, 0x66, 0x2, 0x2, 0x3a2, 0x3a4, 0x5, 0x84, 0x43, 0x2, 0x3a3, 0x3a1, 
       0x3, 0x2, 0x2, 0x2, 0x3a4, 0x3a7, 0x3, 0x2, 0x2, 0x2, 0x3a5, 0x3a3, 
       0x3, 0x2, 0x2, 0x2, 0x3a5, 0x3a6, 0x3, 0x2, 0x2, 0x2, 0x3a6, 0x3a8, 
       0x3, 0x2, 0x2, 0x2, 0x3a7, 0x3a5, 0x3, 0x2, 0x2, 0x2, 0x3a8, 0x3a9, 
       0x7, 0x60, 0x2, 0x2, 0x3a9, 0xb3, 0x3, 0x2, 0x2, 0x2, 0x3aa, 0x3b1, 
       0x5, 0xb2, 0x5a, 0x2, 0x3ab, 0x3ac, 0x7, 0x5d, 0x2, 0x2, 0x3ac, 0x3ad, 
       0x5, 0x56, 0x2c, 0x2, 0x3ad, 0x3ae, 0x7, 0x5e, 0x2, 0x2, 0x3ae, 0x3b1, 
       0x3, 0x2, 0x2, 0x2, 0x3af, 0x3b1, 0x7, 0x7b, 0x2, 0x2, 0x3b0, 0x3aa, 
       0x3, 0x2, 0x2, 0x2, 0x3b0, 0x3ab, 0x3, 0x2, 0x2, 0x2, 0x3b0, 0x3af, 
       0x3, 0x2, 0x2, 0x2, 0x3b1, 0xb5, 0x3, 0x2, 0x2, 0x2, 0x3b2, 0x3be, 
       0x5, 0x10, 0x9, 0x2, 0x3b3, 0x3be, 0x5, 0xc2, 0x62, 0x2, 0x3b4, 0x3b9, 
       0x7, 0x5f, 0x2, 0x2, 0x3b5, 0x3b8, 0x5, 0x10, 0x9, 0x2, 0x3b6, 0x3b8, 
       0x5, 0xc2, 0x62, 0x2, 0x3b7, 0x3b5, 0x3, 0x2, 0x2, 0x2, 0x3b7, 0x3b6, 
       0x3, 0x2, 0x2, 0x2, 0x3b8, 0x3bb, 0x3, 0x2, 0x2, 0x2, 0x3b9, 0x3b7, 
       0x3, 0x2, 0x2, 0x2, 0x3b9, 0x3ba, 0x3, 0x2, 0x2, 0x2, 0x3ba, 0x3bc, 
       0x3, 0x2, 0x2, 0x2, 0x3bb, 0x3b9, 0x3, 0x2, 0x2, 0x2, 0x3bc, 0x3be, 
       0x7, 0x60, 0x2, 0x2, 0x3bd, 0x3b2, 0x3, 0x2, 0x2, 0x2, 0x3bd, 0x3b3, 
       0x3, 0x2, 0x2, 0x2, 0x3bd, 0x3b4, 0x3, 0x2, 0x2, 0x2, 0x3be, 0xb7, 
       0x3, 0x2, 0x2, 0x2, 0x3bf, 0x3c0, 0x7, 0x48, 0x2, 0x2, 0x3c0, 0x3c1, 
       0x7, 0x61, 0x2, 0x2, 0x3c1, 0x3c2, 0x5, 0x84, 0x43, 0x2, 0x3c2, 0x3c3, 
       0x7, 0x62, 0x2, 0x2, 0x3c3, 0x3c6, 0x5, 0xb6, 0x5c, 0x2, 0x3c4, 0x3c5, 
       0x7, 0x49, 0x2, 0x2, 0x3c5, 0x3c7, 0x5, 0xb6, 0x5c, 0x2, 0x3c6, 0x3c4, 
       0x3, 0x2, 0x2, 0x2, 0x3c6, 0x3c7, 0x3, 0x2, 0x2, 0x2, 0x3c7, 0xb9, 
       0x3, 0x2, 0x2, 0x2, 0x3c8, 0x3c9, 0x7, 0x4a, 0x2, 0x2, 0x3c9, 0x3ca, 
       0x7, 0x7b, 0x2, 0x2, 0x3ca, 0x3cb, 0x7, 0x4b, 0x2, 0x2, 0x3cb, 0x3d2, 
       0x5, 0xb4, 0x5b, 0x2, 0x3cc, 0x3cd, 0x7, 0x4c, 0x2, 0x2, 0x3cd, 0x3ce, 
       0x7, 0x61, 0x2, 0x2, 0x3ce, 0x3cf, 0x5, 0x84, 0x43, 0x2, 0x3cf, 0x3d0, 
       0x7, 0x62, 0x2, 0x2, 0x3d0, 0x3d2, 0x3, 0x2, 0x2, 0x2, 0x3d1, 0x3c8, 
       0x3, 0x2, 0x2, 0x2, 0x3d1, 0x3cc, 0x3, 0x2, 0x2, 0x2, 0x3d2, 0xbb, 
       0x3, 0x2, 0x2, 0x2, 0x3d3, 0x3d4, 0x5, 0xba, 0x5e, 0x2, 0x3d4, 0x3d5, 
       0x5, 0xb6, 0x5c, 0x2, 0x3d5, 0xbd, 0x3, 0x2, 0x2, 0x2, 0x3d6, 0x3d7, 
       0x7, 0x4d, 0x2, 0x2, 0x3d7, 0x3d8, 0x7, 0x64, 0x2, 0x2, 0x3d8, 0xbf, 
       0x3, 0x2, 0x2, 0x2, 0x3d9, 0x3dc, 0x7, 0x4e, 0x2, 0x2, 0x3da, 0x3dd, 
       0x5, 0x84, 0x43, 0x2, 0x3db, 0x3dd, 0x5, 0x6c, 0x37, 0x2, 0x3dc, 
       0x3da, 0x3, 0x2, 0x2, 0x2, 0x3dc, 0x3db, 0x3, 0x2, 0x2, 0x2, 0x3dc, 
       0x3dd, 0x3, 0x2, 0x2, 0x2, 0x3dd, 0x3de, 0x3, 0x2, 0x2, 0x2, 0x3de, 
       0x3df, 0x7, 0x64, 0x2, 0x2, 0x3df, 0xc1, 0x3, 0x2, 0x2, 0x2, 0x3e0, 
       0x3e1, 0x9, 0x13, 0x2, 0x2, 0x3e1, 0x3e5, 0x7, 0x64, 0x2, 0x2, 0x3e2, 
       0x3e5, 0x5, 0xbe, 0x60, 0x2, 0x3e3, 0x3e5, 0x5, 0xc0, 0x61, 0x2, 
       0x3e4, 0x3e0, 0x3, 0x2, 0x2, 0x2, 0x3e4, 0x3e2, 0x3, 0x2, 0x2, 0x2, 
       0x3e4, 0x3e3, 0x3, 0x2, 0x2, 0x2, 0x3e5, 0xc3, 0x3, 0x2, 0x2, 0x2, 
       0x3e6, 0x3e7, 0x7, 0x51, 0x2, 0x2, 0x3e7, 0x3e8, 0x7, 0x7b, 0x2, 
       0x2, 0x3e8, 0x3ea, 0x7, 0x61, 0x2, 0x2, 0x3e9, 0x3eb, 0x5, 0x48, 
       0x25, 0x2, 0x3ea, 0x3e9, 0x3, 0x2, 0x2, 0x2, 0x3ea, 0x3eb, 0x3, 0x2, 
       0x2, 0x2, 0x3eb, 0x3ec, 0x3, 0x2, 0x2, 0x2, 0x3ec, 0x3ee, 0x7, 0x62, 
       0x2, 0x2, 0x3ed, 0x3ef, 0x5, 0x1a, 0xe, 0x2, 0x3ee, 0x3ed, 0x3, 0x2, 
       0x2, 0x2, 0x3ee, 0x3ef, 0x3, 0x2, 0x2, 0x2, 0x3ef, 0x3f0, 0x3, 0x2, 
       0x2, 0x2, 0x3f0, 0x3f1, 0x7, 0x64, 0x2, 0x2, 0x3f1, 0xc5, 0x3, 0x2, 
       0x2, 0x2, 0x3f2, 0x3f3, 0x7, 0x7b, 0x2, 0x2, 0x3f3, 0x3f5, 0x7, 0x61, 
       0x2, 0x2, 0x3f4, 0x3f6, 0x5, 0xac, 0x57, 0x2, 0x3f5, 0x3f4, 0x3, 
       0x2, 0x2, 0x2, 0x3f5, 0x3f6, 0x3, 0x2, 0x2, 0x2, 0x3f6, 0x3f7, 0x3, 
       0x2, 0x2, 0x2, 0x3f7, 0x3f8, 0x7, 0x62, 0x2, 0x2, 0x3f8, 0xc7, 0x3, 
       0x2, 0x2, 0x2, 0x3f9, 0x3fa, 0x7, 0x52, 0x2, 0x2, 0x3fa, 0x3fb, 0x7, 
       0x7b, 0x2, 0x2, 0x3fb, 0x3fd, 0x7, 0x61, 0x2, 0x2, 0x3fc, 0x3fe, 
       0x5, 0x50, 0x29, 0x2, 0x3fd, 0x3fc, 0x3, 0x2, 0x2, 0x2, 0x3fd, 0x3fe, 
       0x3, 0x2, 0x2, 0x2, 0x3fe, 0x3ff, 0x3, 0x2, 0x2, 0x2, 0x3ff, 0x401, 
       0x7, 0x62, 0x2, 0x2, 0x400, 0x402, 0x5, 0x1a, 0xe, 0x2, 0x401, 0x400, 
       0x3, 0x2, 0x2, 0x2, 0x401, 0x402, 0x3, 0x2, 0x2, 0x2, 0x402, 0x403, 
       0x3, 0x2, 0x2, 0x2, 0x403, 0x404, 0x5, 0xca, 0x66, 0x2, 0x404, 0xc9, 
       0x3, 0x2, 0x2, 0x2, 0x405, 0x409, 0x7, 0x5f, 0x2, 0x2, 0x406, 0x408, 
       0x5, 0x10, 0x9, 0x2, 0x407, 0x406, 0x3, 0x2, 0x2, 0x2, 0x408, 0x40b, 
       0x3, 0x2, 0x2, 0x2, 0x409, 0x407, 0x3, 0x2, 0x2, 0x2, 0x409, 0x40a, 
       0x3, 0x2, 0x2, 0x2, 0x40a, 0x40d, 0x3, 0x2, 0x2, 0x2, 0x40b, 0x409, 
       0x3, 0x2, 0x2, 0x2, 0x40c, 0x40e, 0x5, 0xc0, 0x61, 0x2, 0x40d, 0x40c, 
       0x3, 0x2, 0x2, 0x2, 0x40d, 0x40e, 0x3, 0x2, 0x2, 0x2, 0x40e, 0x40f, 
       0x3, 0x2, 0x2, 0x2, 0x40f, 0x410, 0x7, 0x60, 0x2, 0x2, 0x410, 0xcb, 
       0x3, 0x2, 0x2, 0x2, 0x411, 0x412, 0x7, 0x53, 0x2, 0x2, 0x412, 0x416, 
       0x7, 0x5f, 0x2, 0x2, 0x413, 0x415, 0x5, 0x10, 0x9, 0x2, 0x414, 0x413, 
       0x3, 0x2, 0x2, 0x2, 0x415, 0x418, 0x3, 0x2, 0x2, 0x2, 0x416, 0x414, 
       0x3, 0x2, 0x2, 0x2, 0x416, 0x417, 0x3, 0x2, 0x2, 0x2, 0x417, 0x419, 
       0x3, 0x2, 0x2, 0x2, 0x418, 0x416, 0x3, 0x2, 0x2, 0x2, 0x419, 0x41a, 
       0x7, 0x60, 0x2, 0x2, 0x41a, 0xcd, 0x3, 0x2, 0x2, 0x2, 0x41b, 0x41c, 
       0x9, 0x14, 0x2, 0x2, 0x41c, 0xcf, 0x3, 0x2, 0x2, 0x2, 0x41d, 0x41f, 
       0x7, 0x56, 0x2, 0x2, 0x41e, 0x420, 0x5, 0x1c, 0xf, 0x2, 0x41f, 0x41e, 
       0x3, 0x2, 0x2, 0x2, 0x41f, 0x420, 0x3, 0x2, 0x2, 0x2, 0x420, 0x421, 
       0x3, 0x2, 0x2, 0x2, 0x421, 0x422, 0x5, 0x5e, 0x30, 0x2, 0x422, 0xd1, 
       0x3, 0x2, 0x2, 0x2, 0x423, 0x42c, 0x7, 0x7d, 0x2, 0x2, 0x424, 0x425, 
       0x7, 0x57, 0x2, 0x2, 0x425, 0x428, 0x7, 0x61, 0x2, 0x2, 0x426, 0x429, 
       0x7, 0x7b, 0x2, 0x2, 0x427, 0x429, 0x5, 0x5e, 0x30, 0x2, 0x428, 0x426, 
       0x3, 0x2, 0x2, 0x2, 0x428, 0x427, 0x3, 0x2, 0x2, 0x2, 0x429, 0x42a, 
       0x3, 0x2, 0x2, 0x2, 0x42a, 0x42c, 0x7, 0x62, 0x2, 0x2, 0x42b, 0x423, 
       0x3, 0x2, 0x2, 0x2, 0x42b, 0x424, 0x3, 0x2, 0x2, 0x2, 0x42c, 0xd3, 
       0x3, 0x2, 0x2, 0x2, 0x42d, 0x42e, 0x9, 0x15, 0x2, 0x2, 0x42e, 0xd5, 
       0x3, 0x2, 0x2, 0x2, 0x42f, 0x435, 0x5, 0xd4, 0x6b, 0x2, 0x430, 0x432, 
       0x7, 0x61, 0x2, 0x2, 0x431, 0x433, 0x5, 0xac, 0x57, 0x2, 0x432, 0x431, 
       0x3, 0x2, 0x2, 0x2, 0x432, 0x433, 0x3, 0x2, 0x2, 0x2, 0x433, 0x434, 
       0x3, 0x2, 0x2, 0x2, 0x434, 0x436, 0x7, 0x62, 0x2, 0x2, 0x435, 0x430, 
       0x3, 0x2, 0x2, 0x2, 0x435, 0x436, 0x3, 0x2, 0x2, 0x2, 0x436, 0x437, 
       0x3, 0x2, 0x2, 0x2, 0x437, 0x438, 0x5, 0x1c, 0xf, 0x2, 0x438, 0x43d, 
       0x5, 0xa0, 0x51, 0x2, 0x439, 0x43a, 0x7, 0x66, 0x2, 0x2, 0x43a, 0x43c, 
       0x5, 0xa0, 0x51, 0x2, 0x43b, 0x439, 0x3, 0x2, 0x2, 0x2, 0x43c, 0x43f, 
       0x3, 0x2, 0x2, 0x2, 0x43d, 0x43b, 0x3, 0x2, 0x2, 0x2, 0x43d, 0x43e, 
       0x3, 0x2, 0x2, 0x2, 0x43e, 0xd7, 0x3, 0x2, 0x2, 0x2, 0x43f, 0x43d, 
       0x3, 0x2, 0x2, 0x2, 0x440, 0x441, 0x5, 0xd6, 0x6c, 0x2, 0x441, 0x442, 
       0x7, 0x64, 0x2, 0x2, 0x442, 0x445, 0x3, 0x2, 0x2, 0x2, 0x443, 0x445, 
       0x5, 0xd0, 0x69, 0x2, 0x444, 0x440, 0x3, 0x2, 0x2, 0x2, 0x444, 0x443, 
       0x3, 0x2, 0x2, 0x2, 0x445, 0xd9, 0x3, 0x2, 0x2, 0x2, 0x446, 0x449, 
       0x5, 0xdc, 0x6f, 0x2, 0x447, 0x449, 0x5, 0xde, 0x70, 0x2, 0x448, 
       0x446, 0x3, 0x2, 0x2, 0x2, 0x448, 0x447, 0x3, 0x2, 0x2, 0x2, 0x449, 
       0xdb, 0x3, 0x2, 0x2, 0x2, 0x44a, 0x44b, 0x7, 0x5a, 0x2, 0x2, 0x44b, 
       0x44c, 0x5, 0xe0, 0x71, 0x2, 0x44c, 0x44d, 0x7, 0x64, 0x2, 0x2, 0x44d, 
       0xdd, 0x3, 0x2, 0x2, 0x2, 0x44e, 0x44f, 0x7, 0x5b, 0x2, 0x2, 0x44f, 
       0x455, 0x7, 0x7b, 0x2, 0x2, 0x450, 0x452, 0x7, 0x61, 0x2, 0x2, 0x451, 
       0x453, 0x5, 0xe2, 0x72, 0x2, 0x452, 0x451, 0x3, 0x2, 0x2, 0x2, 0x452, 
       0x453, 0x3, 0x2, 0x2, 0x2, 0x453, 0x454, 0x3, 0x2, 0x2, 0x2, 0x454, 
       0x456, 0x7, 0x62, 0x2, 0x2, 0x455, 0x450, 0x3, 0x2, 0x2, 0x2, 0x455, 
       0x456, 0x3, 0x2, 0x2, 0x2, 0x456, 0x457, 0x3, 0x2, 0x2, 0x2, 0x457, 
       0x459, 0x5, 0x1e, 0x10, 0x2, 0x458, 0x45a, 0x5, 0x1a, 0xe, 0x2, 0x459, 
       0x458, 0x3, 0x2, 0x2, 0x2, 0x459, 0x45a, 0x3, 0x2, 0x2, 0x2, 0x45a, 
       0x45b, 0x3, 0x2, 0x2, 0x2, 0x45b, 0x45f, 0x7, 0x5f, 0x2, 0x2, 0x45c, 
       0x45e, 0xb, 0x2, 0x2, 0x2, 0x45d, 0x45c, 0x3, 0x2, 0x2, 0x2, 0x45e, 
       0x461, 0x3, 0x2, 0x2, 0x2, 0x45f, 0x460, 0x3, 0x2, 0x2, 0x2, 0x45f, 
       0x45d, 0x3, 0x2, 0x2, 0x2, 0x460, 0x462, 0x3, 0x2, 0x2, 0x2, 0x461, 
       0x45f, 0x3, 0x2, 0x2, 0x2, 0x462, 0x463, 0x7, 0x60, 0x2, 0x2, 0x463, 
       0xdf, 0x3, 0x2, 0x2, 0x2, 0x464, 0x465, 0x9, 0x16, 0x2, 0x2, 0x465, 
       0xe1, 0x3, 0x2, 0x2, 0x2, 0x466, 0x469, 0x5, 0x4c, 0x27, 0x2, 0x467, 
       0x469, 0x5, 0xac, 0x57, 0x2, 0x468, 0x466, 0x3, 0x2, 0x2, 0x2, 0x468, 
       0x467, 0x3, 0x2, 0x2, 0x2, 0x469, 0xe3, 0x3, 0x2, 0x2, 0x2, 0x79, 
       0xe7, 0xe9, 0xed, 0xf2, 0xf8, 0x110, 0x11a, 0x121, 0x12b, 0x13a, 
       0x142, 0x146, 0x149, 0x14e, 0x152, 0x155, 0x15c, 0x165, 0x16d, 0x174, 
       0x181, 0x18c, 0x19a, 0x19f, 0x1a4, 0x1a8, 0x1ab, 0x1ae, 0x1b6, 0x1bb, 
       0x1c0, 0x1c4, 0x1ce, 0x1d0, 0x1d7, 0x1de, 0x1e7, 0x1ee, 0x1f2, 0x1ff, 
       0x206, 0x20b, 0x212, 0x225, 0x229, 0x22d, 0x231, 0x23a, 0x23d, 0x246, 
       0x248, 0x255, 0x259, 0x25f, 0x266, 0x26b, 0x277, 0x27a, 0x285, 0x28b, 
       0x293, 0x296, 0x29b, 0x2a9, 0x2ae, 0x2b6, 0x2bd, 0x2cf, 0x2d6, 0x2e1, 
       0x2ec, 0x2f7, 0x302, 0x30e, 0x31a, 0x325, 0x330, 0x33b, 0x33f, 0x34b, 
       0x352, 0x357, 0x35b, 0x35e, 0x369, 0x370, 0x381, 0x388, 0x397, 0x3a5, 
       0x3b0, 0x3b7, 0x3b9, 0x3bd, 0x3c6, 0x3d1, 0x3dc, 0x3e4, 0x3ea, 0x3ee, 
       0x3f5, 0x3fd, 0x401, 0x409, 0x40d, 0x416, 0x41f, 0x428, 0x42b, 0x432, 
       0x435, 0x43d, 0x444, 0x448, 0x452, 0x455, 0x459, 0x45f, 0x468, 
  };

  _serializedATN.insert(_serializedATN.end(), serializedATNSegment0,
    serializedATNSegment0 + sizeof(serializedATNSegment0) / sizeof(serializedATNSegment0[0]));


  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

qasmParser::Initializer qasmParser::_init;
