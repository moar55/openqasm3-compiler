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
#include "mlir/Dialect/Math/IR/Math.h"
#include "mlir/Dialect/Complex/IR/Complex.h"
#include <algorithm>
#include <numeric>
#include <vector>

using namespace mlir;

//TODO: Add support for other gates
//TODO: file can be heavily refactored, seperate diff gates in functions
// Moreover, we can use mlir functions, but they can be costly

class ConvertExtractToIndex : public OpConversionPattern<quantum::ExtractQubitOp> {
public :
    using OpConversionPattern::OpConversionPattern;

    LogicalResult matchAndRewrite(quantum::ExtractQubitOp op, OpAdaptor adaptor,
                                  ConversionPatternRewriter &rewriter) const override {
//      op->remove();
        rewriter.replaceOpWithNewOp<arith::ConstantOp>(op, IntegerAttr::get(rewriter.getI64Type(), 1),
                                                       rewriter.getI64Type());
        return success();
    };
};


class ConvertMeasure : public OpConversionPattern<quantum::ExtractQubitOp> {
public :
    using OpConversionPattern::OpConversionPattern;

    LogicalResult matchAndRewrite(quantum::ExtractQubitOp op, OpAdaptor adaptor,
                                  ConversionPatternRewriter &rewriter) const override {
//      op->remove();
        rewriter.replaceOpWithNewOp<arith::ConstantOp>(op, IntegerAttr::get(rewriter.getI64Type(), 1),
                                                       rewriter.getI64Type());
        return success();
    };
};

class ConvertRy180 : public OpConversionPattern<restquantum::Ry180Op> {

public:
    Value global_vector;

    ConvertRy180(TypeConverter &typeConverter, MLIRContext *context, Value global_vector, PatternBenefit benefit = 1)
            : OpConversionPattern<restquantum::Ry180Op>(typeConverter, context, benefit) {
        this->global_vector = global_vector;
    }

    ConvertRy180(MLIRContext *context, Value global_vector, PatternBenefit benefit = 1)
            : OpConversionPattern<restquantum::Ry180Op>(context, benefit) {
        this->global_vector = global_vector;
    }

    LogicalResult matchAndRewrite(restquantum::Ry180Op op, OpAdaptor adaptor,
                                  ConversionPatternRewriter &rewriter) const override {
        std::cout << "hi" << "\n";
        //julia uses column to row syntax

        auto operand = op->getOperand(0).getDefiningOp();
        auto offset = operand->getOperand(0).getDefiningOp<quantum::QallocOp>().getOffsetAttr().getInt();
//        auto offsetVal = rewriter.create<arith::ConstantOp>(rewriter.getUnknownLoc(), offset, rewriter.getI64Type());
        auto index = operand->getOperand(1).getDefiningOp<arith::ConstantOp>().getValue().dyn_cast<IntegerAttr>().getInt();
        auto net_index = offset + index;

        auto vector = rewriter.create<memref::LoadOp>(rewriter.getUnknownLoc(), global_vector).getResult();

        auto in_shape = vector.getType().dyn_cast<VectorType>().getShape();
//        print input vector shape
        std::cout << "input shape: " << std::endl;
        for (auto &el: in_shape) {
            std::cout << el << " ";
        }
        std::cout << std::endl;
//        auto two_as_val = rewriter.create<arith::ConstantOp>(rewriter.getUnknownLoc(), IntegerAttr::get(rewriter.getI64Type(), 2));

        //dimensions
        // First dimension
        int64_t first_dim = pow(2, net_index);
        // Second dimension
        auto second_dim = 2;
        // Third dimension
        int64_t num_of_qubits = std::accumulate(in_shape.begin(), in_shape.end(), 1, std::multiplies<int64_t>()) / 4;
        int64_t third_dim = pow(2, num_of_qubits - net_index  - 1);
        // fourth dimension (the complex dimension)
        int64_t fourth_dim = 2;

        ArrayRef<int64_t> out_shape{first_dim, second_dim, third_dim, fourth_dim};
        // print output vector shape
        std::cout << "output shape: " << std::endl;
        for (auto &el: out_shape) {
            std::cout << el << " ";
        }
        std::cout << std::endl;

        auto vector_type = VectorType::get(out_shape,rewriter.getF64Type());
        Value new_vec =  rewriter.replaceOpWithNewOp<vector::ShapeCastOp>(op, vector_type, vector);

        auto zero =  rewriter.create<arith::ConstantOp>(rewriter.getUnknownLoc(), FloatAttr::get(rewriter.getF64Type(), 0), rewriter.getF64Type());
        auto neg_1 = rewriter.create<arith::ConstantOp>(rewriter.getUnknownLoc(), FloatAttr::get(rewriter.getF64Type(), -1), rewriter.getF64Type());

        // flip the two columns (second dimension
        for (int i = 0; i < out_shape[0]; i++) {
            Value first_column = rewriter.create<vector::ExtractOp>(rewriter.getUnknownLoc(), new_vec, ArrayRef<int64_t>{i,0});
            Value second_column = rewriter.create<vector::ExtractOp>(rewriter.getUnknownLoc(), new_vec, ArrayRef<int64_t>{i,1});
            // extract element as complex number and multiply by -i
            for (int j = 0; j < out_shape[2]; j++) {
                auto real = rewriter.create<vector::ExtractOp>(rewriter.getUnknownLoc(), second_column, ArrayRef<int64_t>{j,0});
                auto imag = rewriter.create<vector::ExtractOp>(rewriter.getUnknownLoc(), second_column, ArrayRef<int64_t>{j,1});
                // build complex number
                auto complex_val = rewriter.create<complex::CreateOp>(rewriter.getUnknownLoc(),ComplexType::get(rewriter.getF64Type()), real, imag);

                // multiply by -i
                auto minus_i = rewriter.create<complex::CreateOp>(rewriter.getUnknownLoc(), ComplexType::get(rewriter.getF64Type()),
                                                                  zero, neg_1);
                auto new_complex_val = rewriter.create<complex::MulOp>(rewriter.getUnknownLoc(), complex_val, minus_i);
                // insert new complex val components into jth element of second column
                auto new_real = rewriter.create<complex::ReOp>(rewriter.getUnknownLoc(), rewriter.getF64Type() ,new_complex_val);
                auto new_imag = rewriter.create<complex::ImOp>(rewriter.getUnknownLoc(), rewriter.getF64Type() , new_complex_val);
                second_column = rewriter.create<vector::InsertOp>(rewriter.getUnknownLoc(), new_real, second_column, ArrayRef<int64_t>{j,0});
                second_column = rewriter.create<vector::InsertOp>(rewriter.getUnknownLoc(), new_imag, second_column, ArrayRef<int64_t>{j,1});
                rewriter.create<vector::InsertOp>(rewriter.getUnknownLoc(), real, first_column, ArrayRef<int64_t>{j,1});
            }
            new_vec = rewriter.create<vector::InsertOp>(rewriter.getUnknownLoc(), second_column, new_vec, ArrayRef<int64_t>{i,0});
            // extract element as complex number and multiply by -i
            for (int j = 0; j < out_shape[2]; j++) {
                auto real = rewriter.create<vector::ExtractOp>(rewriter.getUnknownLoc(), first_column, ArrayRef<int64_t>{j,0});
                auto imag = rewriter.create<vector::ExtractOp>(rewriter.getUnknownLoc(), first_column, ArrayRef<int64_t>{j,1});
                // build complex number
                auto complex_val = rewriter.create<complex::CreateOp>(rewriter.getUnknownLoc(), ComplexType::get(rewriter.getF64Type()), real, imag);
                // multiply by i
                auto one = rewriter.create<arith::ConstantOp>(rewriter.getUnknownLoc(), FloatAttr::get(rewriter.getF64Type(), 1), rewriter.getF64Type());
                auto pos_i = rewriter.create<complex::CreateOp>(rewriter.getUnknownLoc(), ComplexType::get(rewriter.getF64Type()), zero, one);
                auto new_complex_val = rewriter.create<complex::MulOp>(rewriter.getUnknownLoc(), complex_val, pos_i);
                // insert new complex val components into jth element of firth column
                auto new_real = rewriter.create<complex::ReOp>(rewriter.getUnknownLoc(), rewriter.getF64Type() ,new_complex_val);
                auto new_imag = rewriter.create<complex::ImOp>(rewriter.getUnknownLoc(), rewriter.getF64Type() , new_complex_val);
                first_column = rewriter.create<vector::InsertOp>(rewriter.getUnknownLoc(), new_real, first_column, ArrayRef<int64_t>{j,0});
                first_column = rewriter.create<vector::InsertOp>(rewriter.getUnknownLoc(), new_imag, first_column, ArrayRef<int64_t>{j,1});
                rewriter.create<vector::InsertOp>(rewriter.getUnknownLoc(), real, first_column, ArrayRef<int64_t>{j,1});
            }
            new_vec = rewriter.create<vector::InsertOp>(rewriter.getUnknownLoc(), first_column, new_vec, ArrayRef<int64_t>{i,1});
        }

        rewriter.create<vector::PrintOp>(rewriter.getUnknownLoc(), new_vec);

        // reshape vector back into original shape
        auto original_shape_type = VectorType::get(in_shape, rewriter.getF64Type());
        new_vec = rewriter.create<vector::ShapeCastOp>(rewriter.getUnknownLoc(), original_shape_type, new_vec);
        // store into global vector
        rewriter.create<memref::StoreOp>(rewriter.getUnknownLoc(), new_vec, global_vector);
        return success();
    };
};


class ConvertRx90 : public OpConversionPattern<restquantum::Rx90Op> {

public:
    Value global_vector;

    ConvertRx90(TypeConverter &typeConverter, MLIRContext *context, Value global_vector, PatternBenefit benefit = 1)
            : OpConversionPattern<restquantum::Rx90Op>(typeConverter, context, benefit) {
        this->global_vector = global_vector;
    }

    ConvertRx90(MLIRContext *context, Value global_vector, PatternBenefit benefit = 1)
            : OpConversionPattern<restquantum::Rx90Op>(context, benefit) {
        this->global_vector = global_vector;
    }

    LogicalResult matchAndRewrite(restquantum::Rx90Op op, OpAdaptor adaptor,
                                  ConversionPatternRewriter &rewriter) const override {
        std::cout << "hi" << "\n";
        //julia uses column to row syntax

        auto operand = op->getOperand(0).getDefiningOp();
        auto offset = operand->getOperand(0).getDefiningOp<quantum::QallocOp>().getOffsetAttr().getInt();
//        auto offsetVal = rewriter.create<arith::ConstantOp>(rewriter.getUnknownLoc(), offset, rewriter.getI64Type());
        auto index = operand->getOperand(1).getDefiningOp<arith::ConstantOp>().getValue().dyn_cast<IntegerAttr>().getInt();
        auto net_index = offset + index;

        auto vector = rewriter.create<memref::LoadOp>(rewriter.getUnknownLoc(), global_vector).getResult();

        auto in_shape = vector.getType().dyn_cast<VectorType>().getShape();
//        print input vector shape
        std::cout << "input shape: " << std::endl;
        for (auto &el: in_shape) {
            std::cout << el << " ";
        }
        std::cout << std::endl;
//        auto two_as_val = rewriter.create<arith::ConstantOp>(rewriter.getUnknownLoc(), IntegerAttr::get(rewriter.getI64Type(), 2));

        //dimensions
        // First dimension
        int64_t first_dim = pow(2, net_index);
        // Second dimension
        auto second_dim = 2;
        // Third dimension
        int64_t num_of_qubits = std::accumulate(in_shape.begin(), in_shape.end(), 1, std::multiplies<int64_t>()) / 4;
        int64_t third_dim = pow(2, num_of_qubits - net_index  - 1);
        // fourth dimension (the complex dimension)
        int64_t fourth_dim = 2;

        ArrayRef<int64_t> out_shape{first_dim, second_dim, third_dim, fourth_dim};
        // print output vector shape
        std::cout << "output shape: " << std::endl;
        for (auto &el: out_shape) {
            std::cout << el << " ";
        }
        std::cout << std::endl;

        auto vector_type = VectorType::get(out_shape,rewriter.getF64Type());
        Value new_vec =  rewriter.replaceOpWithNewOp<vector::ShapeCastOp>(op, vector_type, vector);

        auto zero =  rewriter.create<arith::ConstantOp>(rewriter.getUnknownLoc(), FloatAttr::get(rewriter.getF64Type(), 0), rewriter.getF64Type());
        auto neg_1_div_sqrt_2 = rewriter.create<arith::ConstantOp>(rewriter.getUnknownLoc(), FloatAttr::get(rewriter.getF64Type(), (-1.0/
                sqrt(2))), rewriter.getF64Type());
        auto neg_i_div_sqrt_2 = rewriter.create<complex::CreateOp>(rewriter.getUnknownLoc(), ComplexType::get(rewriter.getF64Type()),
                                                          zero, neg_1_div_sqrt_2);

        for (int i = 0; i < out_shape[0]; i++) {
            Value first_column = rewriter.create<vector::ExtractOp>(rewriter.getUnknownLoc(), new_vec, ArrayRef<int64_t>{i,0});
            Value second_column = rewriter.create<vector::ExtractOp>(rewriter.getUnknownLoc(), new_vec, ArrayRef<int64_t>{i,1});
            // extract element as complex number and multiply by -i
            for (int j = 0; j < out_shape[2]; j++) {
                auto real = rewriter.create<vector::ExtractOp>(rewriter.getUnknownLoc(), second_column, ArrayRef<int64_t>{j,0});
                auto imag = rewriter.create<vector::ExtractOp>(rewriter.getUnknownLoc(), second_column, ArrayRef<int64_t>{j,1});
                // build complex number
                auto complex_val = rewriter.create<complex::CreateOp>(rewriter.getUnknownLoc(),ComplexType::get(rewriter.getF64Type()), real, imag);

                // multiply by -i/sqrt(2)
                auto new_complex_val = rewriter.create<complex::MulOp>(rewriter.getUnknownLoc(), complex_val, neg_i_div_sqrt_2);
                // insert new complex val components into jth element of second column
                auto new_real = rewriter.create<complex::ReOp>(rewriter.getUnknownLoc(), rewriter.getF64Type() ,new_complex_val);
                auto new_imag = rewriter.create<complex::ImOp>(rewriter.getUnknownLoc(), rewriter.getF64Type() , new_complex_val);
                first_column = rewriter.create<vector::InsertOp>(rewriter.getUnknownLoc(), new_real, first_column, ArrayRef<int64_t>{j,0});
                first_column = rewriter.create<vector::InsertOp>(rewriter.getUnknownLoc(), new_imag, first_column, ArrayRef<int64_t>{j,1});
                rewriter.create<vector::InsertOp>(rewriter.getUnknownLoc(), real, first_column, ArrayRef<int64_t>{j,1});
            }
            new_vec = rewriter.create<vector::InsertOp>(rewriter.getUnknownLoc(), first_column, new_vec, ArrayRef<int64_t>{i,0});
            for (int j = 0; j < out_shape[2]; j++) {
                auto real = rewriter.create<vector::ExtractOp>(rewriter.getUnknownLoc(), second_column, ArrayRef<int64_t>{j,0});
                auto imag = rewriter.create<vector::ExtractOp>(rewriter.getUnknownLoc(), second_column, ArrayRef<int64_t>{j,1});
                // build complex number
                auto complex_val = rewriter.create<complex::CreateOp>(rewriter.getUnknownLoc(), ComplexType::get(rewriter.getF64Type()), real, imag);
                // multiply by -i/sqrt(2)
                auto new_complex_val = rewriter.create<complex::MulOp>(rewriter.getUnknownLoc(), complex_val, neg_i_div_sqrt_2);
                // insert new complex val components into jth element of firth column
                auto new_real = rewriter.create<complex::ReOp>(rewriter.getUnknownLoc(), rewriter.getF64Type() ,new_complex_val);
                auto new_imag = rewriter.create<complex::ImOp>(rewriter.getUnknownLoc(), rewriter.getF64Type() , new_complex_val);
                second_column = rewriter.create<vector::InsertOp>(rewriter.getUnknownLoc(), new_real, second_column, ArrayRef<int64_t>{j,0});
                second_column = rewriter.create<vector::InsertOp>(rewriter.getUnknownLoc(), new_imag, second_column, ArrayRef<int64_t>{j,1});
                rewriter.create<vector::InsertOp>(rewriter.getUnknownLoc(), real, first_column, ArrayRef<int64_t>{j,1});
            }
            new_vec = rewriter.create<vector::InsertOp>(rewriter.getUnknownLoc(), second_column, new_vec, ArrayRef<int64_t>{i,1});
        }

        rewriter.create<vector::PrintOp>(rewriter.getUnknownLoc(), new_vec);

        // reshape vector back into original shape
        auto original_shape_type = VectorType::get(in_shape, rewriter.getF64Type());
        new_vec = rewriter.create<vector::ShapeCastOp>(rewriter.getUnknownLoc(), original_shape_type, new_vec);
        // store into global vector
        rewriter.create<memref::StoreOp>(rewriter.getUnknownLoc(), new_vec, global_vector);
        return success();
    };
};


class ConvertRx180 : public OpConversionPattern<restquantum::Rx180Op> {

public:
    Value global_vector;

    ConvertRx180(TypeConverter &typeConverter, MLIRContext *context, Value global_vector, PatternBenefit benefit = 1)
            : OpConversionPattern<restquantum::Rx180Op>(typeConverter, context, benefit) {
        this->global_vector = global_vector;
    }

    ConvertRx180(MLIRContext *context, Value global_vector, PatternBenefit benefit = 1)
            : OpConversionPattern<restquantum::Rx180Op>(context, benefit) {
        this->global_vector = global_vector;
    }

    LogicalResult matchAndRewrite(restquantum::Rx180Op op, OpAdaptor adaptor,
                                  ConversionPatternRewriter &rewriter) const override {
        std::cout << "hi" << "\n";
        //julia uses column to row syntax

        auto operand = op->getOperand(0).getDefiningOp();
        auto offset = operand->getOperand(0).getDefiningOp<quantum::QallocOp>().getOffsetAttr().getInt();
//        auto offsetVal = rewriter.create<arith::ConstantOp>(rewriter.getUnknownLoc(), offset, rewriter.getI64Type());
        auto index = operand->getOperand(1).getDefiningOp<arith::ConstantOp>().getValue().dyn_cast<IntegerAttr>().getInt();
        auto net_index = offset + index;

        auto vector = rewriter.create<memref::LoadOp>(rewriter.getUnknownLoc(), global_vector).getResult();

        auto in_shape = vector.getType().dyn_cast<VectorType>().getShape();
//        print input vector shape
        std::cout << "input shape: " << std::endl;
        for (auto &el: in_shape) {
            std::cout << el << " ";
        }
        std::cout << std::endl;
//        auto two_as_val = rewriter.create<arith::ConstantOp>(rewriter.getUnknownLoc(), IntegerAttr::get(rewriter.getI64Type(), 2));

        //dimensions
        // First dimension
        int64_t first_dim = pow(2, net_index);
        // Second dimension
        auto second_dim = 2;
        // Third dimension
        int64_t num_of_qubits = std::accumulate(in_shape.begin(), in_shape.end(), 1, std::multiplies<int64_t>()) / 4;
        int64_t third_dim = pow(2, num_of_qubits - net_index  - 1);
        // fourth dimension (the complex dimension)
        int64_t fourth_dim = 2;

        ArrayRef<int64_t> out_shape{first_dim, second_dim, third_dim, fourth_dim};
        // print output vector shape
        std::cout << "output shape: " << std::endl;
        for (auto &el: out_shape) {
            std::cout << el << " ";
        }
        std::cout << std::endl;

        auto vector_type = VectorType::get(out_shape,rewriter.getF64Type());
        Value new_vec =  rewriter.replaceOpWithNewOp<vector::ShapeCastOp>(op, vector_type, vector);

        // flip the two columns
        for (int i = 0; i < out_shape[0]; i++) {
            auto first_column = rewriter.create<vector::ExtractOp>(rewriter.getUnknownLoc(), new_vec, ArrayRef<int64_t>{i,0});
            auto second_column = rewriter.create<vector::ExtractOp>(rewriter.getUnknownLoc(), new_vec, ArrayRef<int64_t>{i,1});
            new_vec = rewriter.create<vector::InsertOp>(rewriter.getUnknownLoc(), second_column, new_vec, ArrayRef<int64_t>{i,0});
            new_vec = rewriter.create<vector::InsertOp>(rewriter.getUnknownLoc(), first_column, new_vec, ArrayRef<int64_t>{i,1});
        }

        // print the new_vec
        rewriter.create<vector::PrintOp>(rewriter.getUnknownLoc(), new_vec);

        // reshape vector back into original shape
        auto original_shape_type = VectorType::get(in_shape, rewriter.getF64Type());
        new_vec = rewriter.create<vector::ShapeCastOp>(rewriter.getUnknownLoc(), original_shape_type, new_vec);
        // store into global vector
        rewriter.create<memref::StoreOp>(rewriter.getUnknownLoc(), new_vec, global_vector);
        return success();
    };
};


class ConvertRz : public OpConversionPattern<restquantum::RzOp> {

public:
    Value global_vector;

    ConvertRz(TypeConverter &typeConverter, MLIRContext *context, Value global_vector, PatternBenefit benefit = 1)
            : OpConversionPattern<restquantum::RzOp>(typeConverter, context, benefit) {
        this->global_vector = global_vector;
    }

    ConvertRz(MLIRContext *context, Value global_vector, PatternBenefit benefit = 1)
            : OpConversionPattern<restquantum::RzOp>(context, benefit) {
        this->global_vector = global_vector;
    }

    LogicalResult matchAndRewrite(restquantum::RzOp op, OpAdaptor adaptor,
                                  ConversionPatternRewriter &rewriter) const override {
        std::cout << "hi" << "\n";
        //julia uses column to row syntax

        auto operand = op->getOperand(0).getDefiningOp();
        auto offset = operand->getOperand(0).getDefiningOp<quantum::QallocOp>().getOffsetAttr().getInt();
//        auto offsetVal = rewriter.create<arith::ConstantOp>(rewriter.getUnknownLoc(), offset, rewriter.getI64Type());
        auto index = operand->getOperand(1).getDefiningOp<arith::ConstantOp>().getValue().dyn_cast<IntegerAttr>().getInt();
        auto net_index = offset + index;
        auto angle = op->getOperand(1).getDefiningOp<arith::ConstantOp>().getValue().dyn_cast<FloatAttr>().getValueAsDouble();

        auto vector = rewriter.create<memref::LoadOp>(rewriter.getUnknownLoc(), global_vector).getResult();

        auto in_shape = vector.getType().dyn_cast<VectorType>().getShape();
//        print input vector shape
        std::cout << "input shape: " << std::endl;
        for (auto &el: in_shape) {
            std::cout << el << " ";
        }
        std::cout << std::endl;
//        auto two_as_val = rewriter.create<arith::ConstantOp>(rewriter.getUnknownLoc(), IntegerAttr::get(rewriter.getI64Type(), 2));

        //dimensions
        // First dimension
        int64_t first_dim = pow(2, net_index);
        // Second dimension
        auto second_dim = 2;
        // Third dimension
        int64_t num_of_qubits = std::accumulate(in_shape.begin(), in_shape.end(), 1, std::multiplies<int64_t>()) / 4;
        int64_t third_dim = pow(2, num_of_qubits - net_index  - 1);
        // fourth dimension (the complex dimension)
        int64_t fourth_dim = 2;

        ArrayRef<int64_t> out_shape{first_dim, second_dim, third_dim, fourth_dim};
        // print output vector shape
        std::cout << "output shape: " << std::endl;
        for (auto &el: out_shape) {
            std::cout << el << " ";
        }
        std::cout << std::endl;

        auto vector_type = VectorType::get(out_shape,rewriter.getF64Type());
        Value new_vec =  rewriter.replaceOpWithNewOp<vector::ShapeCastOp>(op, vector_type, vector);

        // global phase removed, hence omission of divide by 2
        auto real_factor = cos(angle);
        auto imag_factor = -1 * sin(angle);
        auto real_val = rewriter.create<arith::ConstantOp>(rewriter.getUnknownLoc(), FloatAttr::get(rewriter.getF64Type(), real_factor), rewriter.getF64Type());
        auto imag_val = rewriter.create<arith::ConstantOp>(rewriter.getUnknownLoc(), FloatAttr::get(rewriter.getF64Type(), imag_factor), rewriter.getF64Type());
        auto complex_factor = rewriter.create<complex::CreateOp>(rewriter.getUnknownLoc(), ComplexType::get(rewriter.getF64Type()),
                                                                   real_val, imag_val);

        for (int i = 0; i < out_shape[0]; i++) {
            Value first_column = rewriter.create<vector::ExtractOp>(rewriter.getUnknownLoc(), new_vec, ArrayRef<int64_t>{i,0});
            Value second_column = rewriter.create<vector::ExtractOp>(rewriter.getUnknownLoc(), new_vec, ArrayRef<int64_t>{i,1});
            // iterate over second dimension, and multiply each element by e^(-i*angle)
            for (int j = 0; j < out_shape[2]; j++) {
                auto real = rewriter.create<vector::ExtractOp>(rewriter.getUnknownLoc(), second_column, ArrayRef<int64_t>{j,0});
                auto imag = rewriter.create<vector::ExtractOp>(rewriter.getUnknownLoc(), second_column, ArrayRef<int64_t>{j,1});
                // build complex number
                auto complex_val = rewriter.create<complex::CreateOp>(rewriter.getUnknownLoc(),ComplexType::get(rewriter.getF64Type()), real, imag);

                // multiply by -i/sqrt(2)
                auto new_complex_val = rewriter.create<complex::MulOp>(rewriter.getUnknownLoc(), complex_val, complex_factor);
                // insert new complex val components into jth element of second column
                auto new_real = rewriter.create<complex::ReOp>(rewriter.getUnknownLoc(), rewriter.getF64Type() ,new_complex_val);
                auto new_imag = rewriter.create<complex::ImOp>(rewriter.getUnknownLoc(), rewriter.getF64Type() , new_complex_val);
                first_column = rewriter.create<vector::InsertOp>(rewriter.getUnknownLoc(), new_real, first_column, ArrayRef<int64_t>{j,0});
                first_column = rewriter.create<vector::InsertOp>(rewriter.getUnknownLoc(), new_imag, first_column, ArrayRef<int64_t>{j,1});
                rewriter.create<vector::InsertOp>(rewriter.getUnknownLoc(), real, first_column, ArrayRef<int64_t>{j,1});
            }
            new_vec = rewriter.create<vector::InsertOp>(rewriter.getUnknownLoc(), first_column, new_vec, ArrayRef<int64_t>{i,0});
            //second column remains unchanged
            new_vec = rewriter.create<vector::InsertOp>(rewriter.getUnknownLoc(), second_column, new_vec, ArrayRef<int64_t>{i,1});
        }

        rewriter.create<vector::PrintOp>(rewriter.getUnknownLoc(), new_vec);

        // reshape vector back into original shape
        auto original_shape_type = VectorType::get(in_shape, rewriter.getF64Type());
        new_vec = rewriter.create<vector::ShapeCastOp>(rewriter.getUnknownLoc(), original_shape_type, new_vec);
        // store into global vector
        rewriter.create<memref::StoreOp>(rewriter.getUnknownLoc(), new_vec, global_vector);
        return success();
    };
};


class QuantumSimulator
        : public quantum::QuantumSimulatorBase<QuantumSimulator> {
public:
    void runOnOperation() override {
        MLIRContext *context = &getContext();
        Operation *moduleOp = getOperation();
        OpBuilder builder(context);
        auto &moduleOpRegion = moduleOp->getRegion(0); // get root region
        auto &moduleOpBlock = moduleOpRegion.front();
        auto &funcOp = moduleOpBlock.front();
        auto &funcOpBlock = funcOp.getRegion(0).front();
        Operation *lastOp;
        int total_qubits = 0;
        std::vector<Operation *> qallocs_to_remove, qextracts_to_remove;
        for (auto &op: funcOpBlock) {
            auto name = op.getName().getStringRef().str();
            if (name == "quantum.qalloc") {
                total_qubits += llvm::dyn_cast<quantum::QallocOp>(op).getSizeAttr().getInt();
                lastOp = &op;
                qallocs_to_remove.push_back(&op);
            } else if (name == "quantum.qextract") {
                qextracts_to_remove.push_back(&op);
            }
        }
        builder.setInsertionPointAfter(lastOp);

        if (total_qubits == 0) {
            return;
        }

        // 16x1
        // 8 x 2 x 1


        auto size = (long) pow(2, total_qubits) * 2;
        ArrayRef<int64_t> shape{size};//
        std::vector<double> init(size);
        // set to |0....0>
        std::fill(init.begin(), init.end(), 0.0);
        init[0] = 1.0;
        auto vector_type = VectorType::get(shape, builder.getF64Type());
        auto attr = DenseFPElementsAttr::get(vector_type, init);
        Value vector = builder.create<arith::ConstantOp>(builder.getUnknownLoc(), attr, vector_type);
        vector = builder.create<vector::ShapeCastOp>(builder.getUnknownLoc(),
                                                     VectorType::get({(long) pow(2, total_qubits), 2},
                                                                     builder.getF64Type()), vector);
        auto global_vector = builder.create<memref::AllocOp>(builder.getUnknownLoc(),
                                                             MemRefType::get({}, vector.getType()));
        builder.create<memref::StoreOp>(builder.getUnknownLoc(), vector, global_vector);

        ConversionTarget target(*context);
        target.addLegalOp<ModuleOp, quantum::QallocOp>();
        target.addLegalDialect<memref::MemRefDialect, arith::ArithDialect, vector::VectorDialect,
        complex::ComplexDialect,
        func::FuncDialect, scf::SCFDialect, quantum::QuantumDialect>();
        target.addIllegalOp<restquantum::Rx180Op, restquantum::Rx90Op, restquantum::Ry180Op, restquantum::RzOp>();
        TypeConverter typeConverter;
        typeConverter.addConversion([](Type type) { return type; });
//      target.addIllegalOp<quantum::ExtractQubitOp >();
        RewritePatternSet patterns(context);
//      patterns.add<ConvertExtractToIndex>(typeConverter, context);
        patterns.add<ConvertRx90>(typeConverter, context, global_vector);
        patterns.add<ConvertRx180>(typeConverter, context, global_vector);
        patterns.add<ConvertRy180>(typeConverter, context, global_vector);
        patterns.add<ConvertRz>(typeConverter, context, global_vector);


        if (failed(applyFullConversion(getOperation(), target, std::move(patterns)))) {
            return signalPassFailure();
        }

      for (const auto op: qextracts_to_remove) {
        op->erase();
      }

      //remove all quantum dialect operations
    for (const auto op: qallocs_to_remove) {
        op->erase();
    }
//        auto operation = val.getResult().getDefiningOp();
//        operation->moveAfter(lastOp);
    }
};

std::unique_ptr<OperationPass<ModuleOp>>
mlir::quantum::createQuantumSimulator() {
    return std::make_unique<QuantumSimulator>();
}