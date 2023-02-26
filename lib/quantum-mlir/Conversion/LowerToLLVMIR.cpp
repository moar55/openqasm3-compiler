#include <iostream>
#include <mlir/Transforms/DialectConversion.h>
#include <quantum-mlir/Dialect/Quantum/IR/QuantumOps.h>
#include "mlir/Conversion/ArithToLLVM/ArithToLLVM.h"
#include "mlir/Conversion/FuncToLLVM/ConvertFuncToLLVM.h"
#include "mlir/Conversion/FuncToLLVM/ConvertFuncToLLVMPass.h"
#include "mlir/Conversion/VectorToLLVM/ConvertVectorToLLVM.h"
#include "mlir/Conversion/LLVMCommon/ConversionTarget.h"
#include "mlir/Conversion/LLVMCommon/TypeConverter.h"
#include "mlir/Conversion/MemRefToLLVM/MemRefToLLVM.h"
#include "mlir/Conversion/SCFToControlFlow/SCFToControlFlow.h"
#include "mlir/Dialect/Arith/IR/Arith.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/Dialect/SCF/IR/SCF.h"
#include "mlir/Dialect/Vector/IR/VectorOps.h"
#include "mlir/Dialect/LLVMIR/LLVMDialect.h"
#include "mlir/Dialect/Complex/IR/Complex.h"
#include "mlir/Conversion/ControlFlowToLLVM/ControlFlowToLLVM.h"
#include "mlir/Conversion/SCFToControlFlow/SCFToControlFlow.h"
#include "mlir/Conversion/ComplexToLLVM/ComplexToLLVM.h"
#include "mlir/Pass/Pass.h"
#include "quantum-mlir/Conversion/Passes.h"
#include "PassImp.h"

using namespace mlir;

class LowerToLLVM
        : public quantum::LowerToLLVMBase<LowerToLLVM> {
public:
    void runOnOperation() override {
        ConversionTarget target(getContext());
        target.addLegalOp<ModuleOp>();
//      target.addLegalOp<vector::ShapeCastOp>();
        target.addIllegalDialect<complex::ComplexDialect>();
        LLVMTypeConverter typeConverter(&getContext());
        RewritePatternSet patterns(&getContext());
        populateComplexToLLVMConversionPatterns(typeConverter, patterns);
//      populateSCFToControlFlowConversionPatterns(patterns);
//      mlir::arith::populateArithToLLVMConversionPatterns(typeConverter, patterns);
//      populateMemRefToLLVMConversionPatterns(typeConverter, patterns);
//      cf::populateControlFlowToLLVMConversionPatterns(typeConverter, patterns);
//      populateFuncToLLVMConversionPatterns(typeConverter, patterns);
//      populateVectorToLLVMConversionPatterns(typeConverter, patterns);
        auto module = getOperation();
        if (failed(applyPartialConversion(module, target, std::move(patterns)))) {
            signalPassFailure();
        }
    };
};

std::unique_ptr<OperationPass<ModuleOp>>
mlir::quantum::createLowerToLLVMPass() {
    return std::make_unique<LowerToLLVM>();
}