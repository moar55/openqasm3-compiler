#include <iostream>
#include <mlir/Transforms/DialectConversion.h>
#include <quantum-mlir/Dialect/Quantum/IR/QuantumOps.h>
#include "quantum-mlir/Dialect/RestrictedQuantum/IR/RestrictedQuantumOps.h"
#include "mlir/Dialect/Arith/IR/Arith.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/Dialect/MemRef/IR/MemRef.h"
#include "mlir/Dialect/SCF/IR/SCF.h"
#include "mlir/Dialect/LLVMIR/LLVMDialect.h"
#include "mlir/Pass/Pass.h"
#include "quantum-mlir/Conversion/Passes.h"
#include "PassImp.h"
#include "mlir/Dialect/Vector/IR/VectorOps.h"
#include <vector>

using namespace mlir;

class ConvertExtractToIndex : public OpConversionPattern<quantum::ExtractQubitOp> {
public :
    using OpConversionPattern::OpConversionPattern;

    LogicalResult matchAndRewrite(quantum::ExtractQubitOp op, OpAdaptor adaptor,
                                  ConversionPatternRewriter &rewriter) const override {
//      op->remove();
      rewriter.replaceOpWithNewOp<arith::ConstantOp>(op, IntegerAttr::get(rewriter.getI32Type(), 1), rewriter.getI32Type());
      return success();
    };
};


class ConvertRx180 : public OpConversionPattern<restquantum::Rx180Op> {

public:
    Value global_vector;

    ConvertRx180(TypeConverter &typeConverter, MLIRContext *context, Value global_vector, PatternBenefit benefit = 1): OpConversionPattern<restquantum::Rx180Op>(typeConverter, context, benefit) {
      this->global_vector = global_vector;
    }

    ConvertRx180(MLIRContext *context, Value global_vector, PatternBenefit benefit = 1): OpConversionPattern<restquantum::Rx180Op>(context, benefit) {
      this->global_vector = global_vector;
    }

    LogicalResult matchAndRewrite(restquantum::Rx180Op op, OpAdaptor adaptor,
                                  ConversionPatternRewriter &rewriter) const override {
      std::cout << "hi" << "\n";
      //julia uses column to row syntax

      auto operand = op->getOperand(0).getDefiningOp();
      auto offset = IntegerAttr::get(rewriter.getI64Type(), operand->getOperand(0).getDefiningOp<quantum::QallocOp>().getOffsetAttr().getInt());
      auto offsetVal = rewriter.create<arith::ConstantOp>(rewriter.getUnknownLoc(), offset, rewriter.getI64Type());
      auto index = operand->getOperand(1);
      index.getType().dump();
      auto total_offset = rewriter.create<arith::AddIOp>(rewriter.getUnknownLoc(), offsetVal, index);

      std::vector<int> in_values{4};
      std::vector<int> out_values{2,2};
      std::vector<Value> in_shape;

      for (const auto &el: in_values) {
        auto elAttr = IntegerAttr::get(rewriter.getIndexType(), el);
        auto elVal = rewriter.create<arith::ConstantOp>(rewriter.getUnknownLoc(), elAttr, rewriter.getIndexType());
        in_shape.push_back(elVal);
      }
      std::vector<Value> out_shape;
      for (const auto &el: out_values) {
        auto elAttr = IntegerAttr::get(rewriter.getIndexType(), el);
        auto elVal = rewriter.create<arith::ConstantOp>(rewriter.getUnknownLoc(), elAttr, rewriter.getIndexType());
        out_shape.push_back(elVal);
      }
      auto vec = rewriter.create<memref::LoadOp>(rewriter.getUnknownLoc(), global_vector);
      // reshape input to 2,2,4
      auto new_vec = rewriter.replaceOpWithNewOp<vector::ShapeCastOp>(op, VectorType::get({2,2,2}, rewriter.getF64Type()), vec);

//      rewriter.create<memref::StoreOp>(rewriter.getUnknownLoc(), global_vector);

//      operand->erase();


//      rewriter.replaceOpWithNewOp<vector::ReshapeOp>(op, VectorType::get({2,2}, rewriter.getI1Type()), vec, in_shape, out_shape,
//                                                     ArrayAttr::get(getContext(), IntegerAttr::get(rewriter.getI64Type(), 4)));

//      auto offset = IntegerAttr::get(rewriter.getI64Type(), op->getOperand(0).getDefiningOp<quantum::QallocOp>().getOffsetAttr().getInt());
//      auto offsetVal = rewriter.create<arith::ConstantOp>(rewriter.getUnknownLoc(), offset, rewriter.getI64Type());
//      rewriter.replaceOpWithNewOp<arith::AddIOp>(op, offsetVal, op.getOperand(1));
      return success();
    };
};

class QuantumSimulator
        : public quantum::QuantumSimulatorBase<QuantumSimulator> {
public:
    void runOnOperation() override {
        MLIRContext* context = &getContext();
        Operation *moduleOp = getOperation();
        OpBuilder builder(context);
        auto &moduleOpRegion = moduleOp->getRegion(0); // get root region
        auto &moduleOpBlock = moduleOpRegion.front();
        auto &funcOp = moduleOpBlock.front();
        auto &funcOpBlock = funcOp.getRegion(0).front();
        Operation* lastOp;
        int total_qubits = 0;
        std::vector<Operation*> ops_to_remove;
        for (auto &op: funcOpBlock) {
          auto name = op.getName().getStringRef().str();
          if (name == "quantum.qalloc") {
            total_qubits += llvm::dyn_cast<quantum::QallocOp>(op).getSizeAttr().getInt();
            lastOp = &op;
            ops_to_remove.push_back(&op);
          }
        }
        builder.setInsertionPointAfter(lastOp);

        if (total_qubits == 0) {
          return;
        }

        // 16x1
        // 8 x 2 x 1


      auto size = (long)pow(2, total_qubits) * 2;
      ArrayRef<int64_t> shape {size};//
      std::vector<double> init(size);
      std::fill(init.begin(), init.end(), 0.0);
      init[0] = 1.0;
      auto vector_type = VectorType::get(shape, builder.getF64Type());
      auto attr = DenseFPElementsAttr::get(vector_type, init);
      Value global_vector = builder.create<arith::ConstantOp>(builder.getUnknownLoc(), attr, vector_type);
      global_vector = builder.create<vector::ShapeCastOp>(builder.getUnknownLoc(), VectorType::get({(long)pow(2, total_qubits), 2}, builder.getF64Type()), global_vector);
      auto global_vector_mem = builder.create<memref::AllocOp>(builder.getUnknownLoc(),
                                                               MemRefType::get({}, global_vector.getType()));
      builder.create<memref::StoreOp>(builder.getUnknownLoc(), global_vector, global_vector_mem);

      ConversionTarget target(*context);
      target.addLegalOp<ModuleOp, quantum::QallocOp>();
      target.addLegalDialect<memref::MemRefDialect, arith::ArithDialect, vector::VectorDialect, func::FuncDialect, scf::SCFDialect, quantum::QuantumDialect>();
      target.addIllegalOp<restquantum::Rx180Op>();
      TypeConverter typeConverter;
      typeConverter.addConversion([](Type type) {return type;});
//      target.addIllegalOp<quantum::ExtractQubitOp >();
      RewritePatternSet patterns(context);
//      patterns.add<ConvertExtractToIndex>(typeConverter, context);
      patterns.add<ConvertRx180>(typeConverter, context, global_vector_mem);



      if (failed(applyFullConversion(getOperation(), target, std::move(patterns)))) {
        return signalPassFailure();
      }

//      for (const auto op: ops_to_remove) {
//        op->erase();
//      }
//        auto operation = val.getResult().getDefiningOp();
//        operation->moveAfter(lastOp);
    }
  };

std::unique_ptr<OperationPass<ModuleOp>>
mlir::quantum::createQuantumSimulator() {
  return std::make_unique<QuantumSimulator>();
}