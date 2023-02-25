#include <iostream>
#include <mlir/Dialect/MemRef/IR/MemRef.h>
#include <mlir/Dialect/Arith/IR/Arith.h>
#include <quantum-mlir/Dialect/Quantum/IR/QuantumOps.h>
#include "quantum-mlir/Dialect/RestrictedQuantum/IR/RestrictedQuantumOps.h"
#include "quantum-mlir/Conversion//Passes.h"
#include "PassImp.h"
#include <cmath>
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/Dialect/SCF/IR/SCF.h"
#include "mlir/Dialect/Vector/IR/VectorOps.h"
#include <mlir/Transforms/DialectConversion.h>

using namespace mlir;

template <typename... Args>
void replaceWithGenGate(PatternRewriter &rewriter, Operation op, Args... args) {
  rewriter.replaceOpWithNewOp<quantum::GenGate>(op, args...);
}

class ConvertXRewrite : public OpConversionPattern<quantum::XOp> {
public :
    using OpConversionPattern::OpConversionPattern;

    LogicalResult matchAndRewrite(quantum::XOp op, OpAdaptor adaptor,
                                  ConversionPatternRewriter &rewriter) const override {
      rewriter.replaceOpWithNewOp<quantum::GenGate>(op, op.getType(), rewriter.getStringAttr("X"), op.getOperand(), std::vector<Value>{});
      return success();
    }
};

class ConvertYRewrite : public OpConversionPattern<quantum::YOp> {
public :
    using OpConversionPattern::OpConversionPattern;

    LogicalResult matchAndRewrite(quantum::YOp op, OpAdaptor adaptor,
                                  ConversionPatternRewriter &rewriter) const override {
      rewriter.replaceOpWithNewOp<quantum::GenGate>(op, op.getType(), rewriter.getStringAttr("Y"), op.getOperand(), std::vector<Value>{});
      return success();
    }
};


class ConvertZRewrite : public OpConversionPattern<quantum::ZOp> {
public :
    using OpConversionPattern::OpConversionPattern;

    LogicalResult matchAndRewrite(quantum::ZOp op, OpAdaptor adaptor,
                                  ConversionPatternRewriter &rewriter) const override {
      rewriter.replaceOpWithNewOp<quantum::GenGate>(op, op.getType(), rewriter.getStringAttr("Z"), op.getOperand(), std::vector<Value>{});
      return success();
    }
};

class ConvertIRewrite : public OpConversionPattern<quantum::IOp> {
public :
    using OpConversionPattern::OpConversionPattern;

    LogicalResult matchAndRewrite(quantum::IOp op, OpAdaptor adaptor,
                                  ConversionPatternRewriter &rewriter) const override {
      rewriter.replaceOpWithNewOp<quantum::GenGate>(op, op.getType(), rewriter.getStringAttr("I"), op.getOperand(), std::vector<Value>{});
      return success();
    }
};

class ConvertHRewrite : public OpConversionPattern<quantum::HOp> {
public :
    using OpConversionPattern::OpConversionPattern;

    LogicalResult matchAndRewrite(quantum::HOp op, OpAdaptor adaptor,
                                  ConversionPatternRewriter &rewriter) const override {
      rewriter.replaceOpWithNewOp<quantum::GenGate>(op, op.getType(), rewriter.getStringAttr("H"), op.getOperand(), std::vector<Value>{});
      return success();
    }
};


class ConvertSRewrite : public OpConversionPattern<quantum::SOp> {
public :
    using OpConversionPattern::OpConversionPattern;

    LogicalResult matchAndRewrite(quantum::SOp op, OpAdaptor adaptor,
                                  ConversionPatternRewriter &rewriter) const override {
      rewriter.replaceOpWithNewOp<quantum::GenGate>(op, op.getType(), rewriter.getStringAttr("S"), op.getOperand(), std::vector<Value>{});
      return success();
    }
};

class ConvertTRewrite : public OpConversionPattern<quantum::SOp> {
public :
    using OpConversionPattern::OpConversionPattern;

    LogicalResult matchAndRewrite(quantum::SOp op, OpAdaptor adaptor,
                                  ConversionPatternRewriter &rewriter) const override {
      rewriter.replaceOpWithNewOp<quantum::GenGate>(op, op.getType(), rewriter.getStringAttr("T"), op.getOperand(), std::vector<Value>{});
      return success();
    }
};

class ConvertRXRewrite : public OpConversionPattern<quantum::RxOp> {
public :
    using OpConversionPattern::OpConversionPattern;

    LogicalResult matchAndRewrite(quantum::RxOp op, OpAdaptor adaptor,
                                  ConversionPatternRewriter &rewriter) const override {
      rewriter.replaceOpWithNewOp<quantum::GenGate>(op, op.getType(), rewriter.getStringAttr("RX"), op->getOperand(0), op->getOperand(1));
      return success();
    }
};

class ConvertRYRewrite : public OpConversionPattern<quantum::RyOp> {
public :
    using OpConversionPattern::OpConversionPattern;

    LogicalResult matchAndRewrite(quantum::RyOp op, OpAdaptor adaptor,
                                  ConversionPatternRewriter &rewriter) const override {
      rewriter.replaceOpWithNewOp<quantum::GenGate>(op, op.getType(), rewriter.getStringAttr("RY"), op->getOperand(0), op->getOperand(1));
      return success();
    }
};

class ConvertRZRewrite : public OpConversionPattern<quantum::RzOp> {
public :
    using OpConversionPattern::OpConversionPattern;

    LogicalResult matchAndRewrite(quantum::RzOp op, OpAdaptor adaptor,
                                  ConversionPatternRewriter &rewriter) const override {
      rewriter.replaceOpWithNewOp<quantum::GenGate>(op, op.getType(), rewriter.getStringAttr("RZ"), op->getOperand(0), op->getOperand(1));
      return success();
    }
};

class ConvertCXRewrite : public OpConversionPattern<quantum::CXOp> {
public :
    using OpConversionPattern::OpConversionPattern;

    LogicalResult matchAndRewrite(quantum::CXOp op, OpAdaptor adaptor,
                                  ConversionPatternRewriter &rewriter) const override {
      rewriter.replaceOpWithNewOp<quantum::GenGate>(op, op->getResultTypes(), rewriter.getStringAttr("CX"), op->getOperands(), std::vector<Value>{});
      return success();
    }
};


class ConvertToGenGate
        : public quantum::ConvertToGenGateBase<ConvertToGenGate> {
public:
    void runOnOperation() override {
      MLIRContext *context = &getContext();
      ConversionTarget target(*context);
      target.addLegalOp<ModuleOp>();
      target.addLegalDialect<
              memref::MemRefDialect,arith::ArithDialect,restquantum::RestrictedQuantumDialect, vector::VectorDialect, func::FuncDialect, scf::SCFDialect>();
      target.addLegalOp<quantum::MzOp, quantum::GenGate, quantum::QallocOp, quantum::ExtractQubitOp>();
      TypeConverter typeConverter;
      typeConverter.addConversion([](Type type) {return type;});
      RewritePatternSet patterns(context);
      patterns.add<ConvertXRewrite, ConvertYRewrite, ConvertZRewrite, ConvertIRewrite, ConvertSRewrite, ConvertTRewrite, ConvertRXRewrite, ConvertRYRewrite, ConvertRZRewrite, ConvertCXRewrite>(typeConverter, context);
      if (failed(applyFullConversion(getOperation(), target,
                                     std::move(patterns)))) {
        return signalPassFailure();
      }
    };
};

std::unique_ptr<OperationPass<ModuleOp>>
mlir::quantum::createConvertToGenGatePass() {
  return std::make_unique<ConvertToGenGate>();
}