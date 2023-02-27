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
#include "mlir/Dialect/Tensor/IR/Tensor.h"
#include "mlir/Dialect/Linalg/IR/Linalg.h"
#include "mlir/Dialect/Math/IR/Math.h"
#include "mlir/Dialect/Complex/IR/Complex.h"
#include <algorithm>
#include <numeric>
#include <vector>

using namespace mlir;

/*** Quantum Simulator Pass ***/
//Note: qubits are read from right to left


/** Helper functions **/

// extremely hacky function to obtain value of AddFOp as double
double obtain_value(Operation *operation) {
    // recursively iterate over each operand of the operation until we find a constant
    // then return the value of the constant
    // add returned values
    // check if operation is a ConstantOp
    if (auto constant_op = dyn_cast<arith::ConstantOp>(operation)) {
        // if it is, return the value of the constant
        return constant_op.getValue().cast<FloatAttr>().getValueAsDouble();
    } else {
        // if it is not, recursively iterate over each operand of the operation
        double lhs = obtain_value(operation->getOperand(0).getDefiningOp());
        double rhs = obtain_value(operation->getOperand(1).getDefiningOp());
        double sum = lhs + rhs;
        return sum;
    }
}

// helper function to compute output shape for reshaping
// necessary for computing quantum gates
std::vector<int64_t> compute_output_shape(ArrayRef<int64_t> in_shape, int64_t net_index) {
    //dimensions
    // First dimension
    int64_t num_of_qubits = std::accumulate(in_shape.begin(), in_shape.end(), 1, std::multiplies<int64_t>()) / 4;
    int64_t first_dim = pow(2, num_of_qubits - net_index  - 1);
    // Second dimension
    auto second_dim = 2;
    // Third dimension
    int64_t third_dim = pow(2, net_index);
    // fourth dimension (the complex dimension)
    int64_t fourth_dim = 2;

    std::vector<int64_t> out_shape{first_dim, second_dim, third_dim, fourth_dim};
    std::cout << "proper shape size: " ;
    for (auto i : out_shape)
        std::cout << i << " ";
    std::cout << std::endl;
    return out_shape;
}

// helper function to compute offset for reshaping
int64_t compute_offset(Operation *operand) {
    int offset = 0;
    // if operand is a qalloc, get offset attribute, else check if operand is an arith::ConstantOp
    if (operand->getOperand(0).getDefiningOp<quantum::QallocOp>()) {
        offset = operand->getOperand(0).getDefiningOp<quantum::QallocOp>().getOffsetAttr().getInt();
    } else { //extremely hacky method for now
        // loop over operand 0 until we find a qalloc op
        while (!operand->getOperand(0).getDefiningOp<quantum::QallocOp>()) {
            operand = operand->getOperand(0).getDefiningOp();
        }
        offset = operand->getOperand(0).getDefiningOp<quantum::QallocOp>().getOffsetAttr().getInt();
    }
    auto index = operand->getOperand(1).getDefiningOp<arith::ConstantOp>().getValue().dyn_cast<IntegerAttr>().getInt();
    auto net_offset = offset + index;
    return net_offset;
}

//TODO: Add support for other gates
//TODO: file can be heavily refactored, seperate diff gates in functions
//TODO: combine rotation operators with diff angles in one function
//TODO: create more tracable operations/types
//i.e: create a qubit type that has an index and an offset
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


class ConvertMeasure: public OpConversionPattern<quantum::MzOp> {
public:
    Value global_vector;

    ConvertMeasure(TypeConverter &typeConverter, MLIRContext *context, Value global_vector, PatternBenefit benefit = 1)
            : OpConversionPattern<quantum::MzOp>(typeConverter, context, benefit) {
        this->global_vector = global_vector;
    }

    ConvertMeasure(MLIRContext *context, Value global_vector, PatternBenefit benefit = 1)
            : OpConversionPattern<quantum::MzOp>(context, benefit) {
        this->global_vector = global_vector;
    }

    LogicalResult matchAndRewrite(quantum::MzOp op, OpAdaptor adaptor,
                                  ConversionPatternRewriter &rewriter) const override {
        auto vector = rewriter.create<memref::LoadOp>(rewriter.getUnknownLoc(), global_vector).getResult();
        // get index of qubit to measure
        Operation *operand = op.getQubit().getDefiningOp();
        auto net_offset = compute_offset(operand);
        int stride = pow(2, net_offset);

//        //for now do it the hacky way
//        // probability of measuring 0 or 1
//        double meas_zero_prob = 0.0;
//        double meas_one_prob = 0.0;
//        // loop over the vector and compute the probability of measuring 0 and 1
//        // switching between either at each stride
//        auto in_shape = vector.getType().dyn_cast<VectorType>().getShape();
//        auto is_zero = true;
//        for (int i = 0; i < in_shape[0]; i++) {
//            //extract real and img parts
//            auto real = rewriter.create<vector::ExtractOp>(rewriter.getUnknownLoc(), vector, ArrayRef<int64_t>{i,0}).getResult();
//            auto imag = rewriter.create<vector::ExtractOp>(rewriter.getUnknownLoc(), vector, ArrayRef<int64_t>{i,1}).getResult();
//            // compute the probability of measuring 0 or 1
//            // recursively try to obtain the value of the constant
//            auto real_ = obtain_value(real.getDefiningOp());
//            auto imag_ = obtain_value(imag.getDefiningOp());
//            // use c++ std::complex to compute the probability
//            std::complex<double> c(real_, imag_);
//            auto prob = std::norm(c);
//
//            // if we have reached the stride, switch between 0 and 1
//            if (i % stride == 0) {
//                is_zero = !is_zero;
//            }
//            // add the probability to the correct value
//            if (is_zero) {
//                meas_zero_prob += prob;
//            } else {
//                meas_one_prob += prob;;
//            }
//
//        }
//
//        std::cout << "meas_zero_prob: " << meas_zero_prob << std::endl;
//        std::cout << "meas_one_prob: " << meas_one_prob << std::endl;
//        rewriter.replaceOpWithNewOp<arith::ConstantOp>(op, FloatAttr::get(rewriter.getF64Type(), meas_zero_prob),
//                                                       rewriter.getF64Type());


        Value zer_val_prob = rewriter.create<arith::ConstantOp>(rewriter.getUnknownLoc(), FloatAttr::get(rewriter.getF64Type(), 0.0));
        Value one_val_prob = rewriter.create<arith::ConstantOp>(rewriter.getUnknownLoc(), FloatAttr::get(rewriter.getF64Type(), 0.0));
        // loop over the vector and compute the probability of measuring 0 and 1
        // switching between either at each stride
        auto in_shape = vector.getType().dyn_cast<VectorType>().getShape();
        auto is_zero = true;
        for (int i = 0; i < in_shape[0]; i++) {
            //extract real and img parts
            auto real = rewriter.create<vector::ExtractOp>(rewriter.getUnknownLoc(), vector, ArrayRef<int64_t>{i,0});
            auto imag = rewriter.create<vector::ExtractOp>(rewriter.getUnknownLoc(), vector, ArrayRef<int64_t>{i,1});
            auto complex_val = rewriter.create<complex::CreateOp>(rewriter.getUnknownLoc(), ComplexType::get(rewriter.getF64Type()) , real, imag);
            Value prob = rewriter.create<complex::AbsOp>(rewriter.getUnknownLoc(), rewriter.getF64Type(), complex_val).getResult();
            // change to f64
            if (i > 0 && i % stride == 0) {
                is_zero = !is_zero;
            }
            if (is_zero) {
                zer_val_prob = rewriter.create<arith::AddFOp>(rewriter.getUnknownLoc(),  rewriter.getF64Type() ,zer_val_prob, prob);
            } else {
                one_val_prob = rewriter.create<arith::AddFOp>(rewriter.getUnknownLoc(),  rewriter.getF64Type(), one_val_prob, prob);
            }
        }

        // print zero and one value probs using vector::PrintOp
        rewriter.create<vector::PrintOp>(rewriter.getUnknownLoc(), zer_val_prob);
        rewriter.create<vector::PrintOp>(rewriter.getUnknownLoc(), one_val_prob);


//        rewriter.replaceOpWithNewOp<arith::ConstantOp>(op, FloatAttr::get(rewriter.getF64Type(), 0.0), rewriter.getF64Type());

//        // initalize a 0-d tensor
//        // create a tensor type
        auto tensor_type = RankedTensorType::get({1,1}, rewriter.getF64Type());
        // create a tensor attr
        auto tensor_attr = DenseElementsAttr::get(tensor_type, 2.5);
        // create a tensor
        auto tensor = rewriter.create<arith::ConstantOp>(rewriter.getUnknownLoc(), tensor_type, tensor_attr);
        // obtain element in tensor
        // zero var
        auto zero = rewriter.create<arith::ConstantOp>(rewriter.getUnknownLoc(), IntegerAttr::get(rewriter.getIndexType(), 0));
//        auto element = rewriter.create<tensor::ExtractOp>(rewriter.getUnknownLoc(), tensor, std::vector<Value>{zero, zero});

//        rewriter.create<vector::PrintOp>(rewriter.getUnknownLoc(), element);
        // generate a random number using linalg fill
        // create seed value
        auto seed = rewriter.create<arith::ConstantOp>(rewriter.getUnknownLoc(), IntegerAttr::get(rewriter.getI32Type(), 0));
        // create min value
        auto min = rewriter.create<arith::ConstantOp>(rewriter.getUnknownLoc(), FloatAttr::get(rewriter.getF64Type(), 0.0));
        // create max value
        auto max = rewriter.create<arith::ConstantOp>(rewriter.getUnknownLoc(), FloatAttr::get(rewriter.getF64Type(), 1.0));
        // create a random tensor
        auto random_tensor = rewriter.create<linalg::FillRng2DOp>(rewriter.getUnknownLoc(), std::vector<Value>{min, max, seed}, std::vector<Value>{tensor});
        // extract the random number
        auto random_number = rewriter.create<tensor::ExtractOp>(rewriter.getUnknownLoc(), random_tensor.getResult(0), std::vector<Value>{zero, zero});
        // check if random number is less than zero value prob
        auto less_than = rewriter.create<arith::CmpFOp>(rewriter.getUnknownLoc(), arith::CmpFPredicate::OLT, random_number, zer_val_prob);
        auto output = rewriter.create<scf::IfOp>(rewriter.getUnknownLoc(), std::vector<Type>{rewriter.getF64Type()}, less_than, [&](OpBuilder &builder, Location loc) { //if less than yield 0
             // yield 0
             builder.create<scf::YieldOp>(builder.getUnknownLoc(), rewriter.create<arith::ConstantOp>(builder.getUnknownLoc(), FloatAttr::get(builder.getF64Type(), 0.0)).getResult());
         }, [&](OpBuilder &builder, Location loc) {
             // yield 1
            builder.create<scf::YieldOp>(builder.getUnknownLoc(), rewriter.create<arith::ConstantOp>(builder.getUnknownLoc(), FloatAttr::get(builder.getF64Type(), 1.0)).getResult());
         });
        // print output
        rewriter.create<vector::PrintOp>(rewriter.getUnknownLoc(), output.getResult(0));

        rewriter.create<vector::PrintOp>(rewriter.getUnknownLoc(), random_number);
        random_tensor.getResult(0).getType().dump();
//         print random number
        rewriter.create<vector::PrintOp>(rewriter.getUnknownLoc(), random_tensor.getResult(0));
        rewriter.create<vector::PrintOp>(rewriter.getUnknownLoc(), tensor);
        rewriter.replaceOp(op, {tensor});
        return success();
    };
};

class ConvertPrintGlobalVector : public OpConversionPattern<quantum::PrintGlobalVectorOp> {
public:
    Value global_vector;

    ConvertPrintGlobalVector(TypeConverter &typeConverter, MLIRContext *context, Value global_vector, PatternBenefit benefit = 1)
            : OpConversionPattern<quantum::PrintGlobalVectorOp>(typeConverter, context, benefit) {
        this->global_vector = global_vector;
    }

    ConvertPrintGlobalVector(MLIRContext *context, Value global_vector, PatternBenefit benefit = 1)
            : OpConversionPattern<quantum::PrintGlobalVectorOp>(context, benefit) {
        this->global_vector = global_vector;
    }

    LogicalResult matchAndRewrite(quantum::PrintGlobalVectorOp op, OpAdaptor adaptor,
                                  ConversionPatternRewriter &rewriter) const override {
        auto vector = rewriter.create<memref::LoadOp>(rewriter.getUnknownLoc(), global_vector).getResult();
        rewriter.replaceOpWithNewOp<vector::PrintOp>(op, vector);
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
        auto net_index = compute_offset(operand);

        auto vector = rewriter.create<memref::LoadOp>(rewriter.getUnknownLoc(), global_vector).getResult();

        auto in_shape = vector.getType().dyn_cast<VectorType>().getShape();

        std::vector<int64_t> out_shape = compute_output_shape(in_shape, net_index);

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

//        rewriter.create<vector::PrintOp>(rewriter.getUnknownLoc(), new_vec);

        // reshape vector back into original shape
        auto original_shape_type = VectorType::get(in_shape, rewriter.getF64Type());
        new_vec = rewriter.create<vector::ShapeCastOp>(rewriter.getUnknownLoc(), original_shape_type, new_vec);
        // store into global vector
        rewriter.create<memref::StoreOp>(rewriter.getUnknownLoc(), new_vec, global_vector);
        return success();
    };
};


class ConvertRy90 : public OpConversionPattern<restquantum::Ry90Op> {

public:
    Value global_vector;

    ConvertRy90(TypeConverter &typeConverter, MLIRContext *context, Value global_vector, PatternBenefit benefit = 1)
            : OpConversionPattern<restquantum::Ry90Op>(typeConverter, context, benefit) {
        this->global_vector = global_vector;
    }

    ConvertRy90(MLIRContext *context, Value global_vector, PatternBenefit benefit = 1)
            : OpConversionPattern<restquantum::Ry90Op>(context, benefit) {
        this->global_vector = global_vector;
    }

    LogicalResult matchAndRewrite(restquantum::Ry90Op op, OpAdaptor adaptor,
                                  ConversionPatternRewriter &rewriter) const override {
        std::cout << "hi" << "\n";
        //julia uses column to row syntax

        auto operand = op->getOperand(0).getDefiningOp();
        auto net_index = compute_offset(operand);

        auto vector = rewriter.create<memref::LoadOp>(rewriter.getUnknownLoc(), global_vector).getResult();

        auto in_shape = vector.getType().dyn_cast<VectorType>().getShape();

        std::vector<int64_t> out_shape = compute_output_shape(in_shape, net_index);

        auto vector_type = VectorType::get(out_shape,rewriter.getF64Type());
        Value new_vec =  rewriter.replaceOpWithNewOp<vector::ShapeCastOp>(op, vector_type, vector);

        auto zero =  rewriter.create<arith::ConstantOp>(rewriter.getUnknownLoc(), FloatAttr::get(rewriter.getF64Type(), 0), rewriter.getF64Type());
        auto one_div_sqrt_2 = rewriter.create<arith::ConstantOp>(rewriter.getUnknownLoc(), FloatAttr::get(rewriter.getF64Type(), (1.0/
                                                                                                                                  sqrt(2))), rewriter.getF64Type());
        auto one_div_sqrt_2_comp = rewriter.create<complex::CreateOp>(rewriter.getUnknownLoc(), ComplexType::get(rewriter.getF64Type()),
                                                                      one_div_sqrt_2, zero);
        auto neg_1_div_sqrt_2 = rewriter.create<arith::ConstantOp>(rewriter.getUnknownLoc(), FloatAttr::get(rewriter.getF64Type(), (-1.0/
                                                                                                                                    sqrt(2))), rewriter.getF64Type());
        auto neg_1_div_sqrt_2_comp = rewriter.create<complex::CreateOp>(rewriter.getUnknownLoc(), ComplexType::get(rewriter.getF64Type()),
                                                                        neg_1_div_sqrt_2, zero);

        for (int i = 0; i < out_shape[0]; i++) {
            Value first_column = rewriter.create<vector::ExtractOp>(rewriter.getUnknownLoc(), new_vec, ArrayRef<int64_t>{i,0});
            Value second_column = rewriter.create<vector::ExtractOp>(rewriter.getUnknownLoc(), new_vec, ArrayRef<int64_t>{i,1});
            Value first_column_ = first_column;
            Value second_column_ = second_column;

            for (int j = 0; j < out_shape[2]; j++) {
                auto real = rewriter.create<vector::ExtractOp>(rewriter.getUnknownLoc(), first_column, ArrayRef<int64_t>{j,0});
                auto imag = rewriter.create<vector::ExtractOp>(rewriter.getUnknownLoc(), first_column, ArrayRef<int64_t>{j,1});
                // build complex number
                auto complex_val = rewriter.create<complex::CreateOp>(rewriter.getUnknownLoc(),ComplexType::get(rewriter.getF64Type()), real, imag);

                // multiply by 1/sqrt(2)
                Value new_complex_val = rewriter.create<complex::MulOp>(rewriter.getUnknownLoc(), complex_val, one_div_sqrt_2_comp);

                // repeat with second column
                auto real_ = rewriter.create<vector::ExtractOp>(rewriter.getUnknownLoc(), second_column, ArrayRef<int64_t>{j,0});
                auto imag_ = rewriter.create<vector::ExtractOp>(rewriter.getUnknownLoc(), second_column, ArrayRef<int64_t>{j,1});
                // build complex number
                auto complex_val_ = rewriter.create<complex::CreateOp>(rewriter.getUnknownLoc(),ComplexType::get(rewriter.getF64Type()), real_, imag_);
                // multiply by -1/sqrt(2)
                auto new_complex_val_ = rewriter.create<complex::MulOp>(rewriter.getUnknownLoc(), complex_val_, neg_1_div_sqrt_2_comp);
                // add the two
                new_complex_val = rewriter.create<complex::AddOp>(rewriter.getUnknownLoc(), new_complex_val, new_complex_val_);

                // insert new complex val components into jth element of second column
                auto new_real = rewriter.create<complex::ReOp>(rewriter.getUnknownLoc(), rewriter.getF64Type() ,new_complex_val);
                auto new_imag = rewriter.create<complex::ImOp>(rewriter.getUnknownLoc(), rewriter.getF64Type() , new_complex_val);
                first_column_ = rewriter.create<vector::InsertOp>(rewriter.getUnknownLoc(), new_real, first_column_, ArrayRef<int64_t>{j,0});
                first_column_ = rewriter.create<vector::InsertOp>(rewriter.getUnknownLoc(), new_imag, first_column_, ArrayRef<int64_t>{j,1});
            }
            for (int j = 0; j < out_shape[2]; j++) {
                auto real = rewriter.create<vector::ExtractOp>(rewriter.getUnknownLoc(), first_column, ArrayRef<int64_t>{j,0});
                auto imag = rewriter.create<vector::ExtractOp>(rewriter.getUnknownLoc(), first_column, ArrayRef<int64_t>{j,1});
                // build complex number
                auto complex_val = rewriter.create<complex::CreateOp>(rewriter.getUnknownLoc(), ComplexType::get(rewriter.getF64Type()), real, imag);
                // multiply by 1/sqrt(2)
                Value new_complex_val = rewriter.create<complex::MulOp>(rewriter.getUnknownLoc(), complex_val, one_div_sqrt_2_comp);

                //repeat with second column
                auto real_ = rewriter.create<vector::ExtractOp>(rewriter.getUnknownLoc(), second_column, ArrayRef<int64_t>{j,0});
                auto imag_ = rewriter.create<vector::ExtractOp>(rewriter.getUnknownLoc(), second_column, ArrayRef<int64_t>{j,1});
                // build complex number
                auto complex_val_ = rewriter.create<complex::CreateOp>(rewriter.getUnknownLoc(), ComplexType::get(rewriter.getF64Type()), real_, imag_);
                // multiply by 1/sqrt(2)
                auto new_complex_val_ = rewriter.create<complex::MulOp>(rewriter.getUnknownLoc(), complex_val_, one_div_sqrt_2_comp);
                // add the two
                new_complex_val = rewriter.create<complex::AddOp>(rewriter.getUnknownLoc(), new_complex_val, new_complex_val_);

                // insert new complex val components into jth element of firth column
                auto new_real = rewriter.create<complex::ReOp>(rewriter.getUnknownLoc(), rewriter.getF64Type() ,new_complex_val);
                auto new_imag = rewriter.create<complex::ImOp>(rewriter.getUnknownLoc(), rewriter.getF64Type() , new_complex_val);
                second_column_ = rewriter.create<vector::InsertOp>(rewriter.getUnknownLoc(), new_real, second_column_, ArrayRef<int64_t>{j,0});
                second_column_ = rewriter.create<vector::InsertOp>(rewriter.getUnknownLoc(), new_imag, second_column_, ArrayRef<int64_t>{j,1});
            }
            new_vec = rewriter.create<vector::InsertOp>(rewriter.getUnknownLoc(), first_column_, new_vec, ArrayRef<int64_t>{i,0});
            new_vec = rewriter.create<vector::InsertOp>(rewriter.getUnknownLoc(), second_column_, new_vec, ArrayRef<int64_t>{i,1});
        }


        // reshape vector back into original shape
        auto original_shape_type = VectorType::get(in_shape, rewriter.getF64Type());
        new_vec = rewriter.create<vector::ShapeCastOp>(rewriter.getUnknownLoc(), original_shape_type, new_vec);

        std::cout << "RY90 gate output: " << std::endl;
//        rewriter.create<vector::PrintOp>(rewriter.getUnknownLoc(), new_vec);
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
        auto net_index = compute_offset(operand);

        auto vector = rewriter.create<memref::LoadOp>(rewriter.getUnknownLoc(), global_vector).getResult();

        auto in_shape = vector.getType().dyn_cast<VectorType>().getShape();
//        print input vector shape
        std::cout << "input shape: " << std::endl;
        for (auto &el: in_shape) {
            std::cout << el << " ";
        }
        std::cout << std::endl;
//        auto two_as_val = rewriter.create<arith::ConstantOp>(rewriter.getUnknownLoc(), IntegerAttr::get(rewriter.getI64Type(), 2));

        std::vector<int64_t> out_shape = compute_output_shape(in_shape, net_index);
        // print output vector shape
        std::cout << "output shape: " << std::endl;
        for (auto &el: out_shape) {
            std::cout << el << " ";
        }
        std::cout << std::endl;

        auto vector_type = VectorType::get(out_shape,rewriter.getF64Type());
        Value new_vec =  rewriter.replaceOpWithNewOp<vector::ShapeCastOp>(op, vector_type, vector);

        auto zero =  rewriter.create<arith::ConstantOp>(rewriter.getUnknownLoc(), FloatAttr::get(rewriter.getF64Type(), 0), rewriter.getF64Type());
        auto one_div_sqrt_2 = rewriter.create<arith::ConstantOp>(rewriter.getUnknownLoc(), FloatAttr::get(rewriter.getF64Type(), (1.0/
                sqrt(2))), rewriter.getF64Type());
        auto one_div_sqrt_2_comp = rewriter.create<complex::CreateOp>(rewriter.getUnknownLoc(), ComplexType::get(rewriter.getF64Type()),
                                                                    one_div_sqrt_2, zero);
        auto neg_1_div_sqrt_2 = rewriter.create<arith::ConstantOp>(rewriter.getUnknownLoc(), FloatAttr::get(rewriter.getF64Type(), (-1.0/
                sqrt(2))), rewriter.getF64Type());
        auto neg_i_div_sqrt_2 = rewriter.create<complex::CreateOp>(rewriter.getUnknownLoc(), ComplexType::get(rewriter.getF64Type()),
                                                          zero, neg_1_div_sqrt_2);

        for (int i = 0; i < out_shape[0]; i++) {
            Value first_column = rewriter.create<vector::ExtractOp>(rewriter.getUnknownLoc(), new_vec, ArrayRef<int64_t>{i,0});
            Value second_column = rewriter.create<vector::ExtractOp>(rewriter.getUnknownLoc(), new_vec, ArrayRef<int64_t>{i,1});
            Value first_column_ = first_column;
            Value second_column_ = second_column;

            for (int j = 0; j < out_shape[2]; j++) {
                auto real = rewriter.create<vector::ExtractOp>(rewriter.getUnknownLoc(), first_column, ArrayRef<int64_t>{j,0});
                auto imag = rewriter.create<vector::ExtractOp>(rewriter.getUnknownLoc(), first_column, ArrayRef<int64_t>{j,1});
                // build complex number
                auto complex_val = rewriter.create<complex::CreateOp>(rewriter.getUnknownLoc(),ComplexType::get(rewriter.getF64Type()), real, imag);

                // multiply by 1/sqrt(2)
                Value new_complex_val = rewriter.create<complex::MulOp>(rewriter.getUnknownLoc(), complex_val, one_div_sqrt_2_comp);

                // repeat with second column
                auto real_ = rewriter.create<vector::ExtractOp>(rewriter.getUnknownLoc(), second_column, ArrayRef<int64_t>{j,0});
                auto imag_ = rewriter.create<vector::ExtractOp>(rewriter.getUnknownLoc(), second_column, ArrayRef<int64_t>{j,1});
                // build complex number
                auto complex_val_ = rewriter.create<complex::CreateOp>(rewriter.getUnknownLoc(),ComplexType::get(rewriter.getF64Type()), real_, imag_);
                // multiply by -i/sqrt(2)
                auto new_complex_val_ = rewriter.create<complex::MulOp>(rewriter.getUnknownLoc(), complex_val_, neg_i_div_sqrt_2);
                // add the two
                new_complex_val = rewriter.create<complex::AddOp>(rewriter.getUnknownLoc(), new_complex_val, new_complex_val_);

                // insert new complex val components into jth element of second column
                auto new_real = rewriter.create<complex::ReOp>(rewriter.getUnknownLoc(), rewriter.getF64Type() ,new_complex_val);
                auto new_imag = rewriter.create<complex::ImOp>(rewriter.getUnknownLoc(), rewriter.getF64Type() , new_complex_val);
                first_column_ = rewriter.create<vector::InsertOp>(rewriter.getUnknownLoc(), new_real, first_column_, ArrayRef<int64_t>{j,0});
                first_column_ = rewriter.create<vector::InsertOp>(rewriter.getUnknownLoc(), new_imag, first_column_, ArrayRef<int64_t>{j,1});
            }
            for (int j = 0; j < out_shape[2]; j++) {
                auto real = rewriter.create<vector::ExtractOp>(rewriter.getUnknownLoc(), first_column, ArrayRef<int64_t>{j,0});
                auto imag = rewriter.create<vector::ExtractOp>(rewriter.getUnknownLoc(), first_column, ArrayRef<int64_t>{j,1});
                // build complex number
                auto complex_val = rewriter.create<complex::CreateOp>(rewriter.getUnknownLoc(), ComplexType::get(rewriter.getF64Type()), real, imag);
                // multiply by -i/sqrt(2)
                Value new_complex_val = rewriter.create<complex::MulOp>(rewriter.getUnknownLoc(), complex_val, neg_i_div_sqrt_2);

                //repeat with second column
                auto real_ = rewriter.create<vector::ExtractOp>(rewriter.getUnknownLoc(), second_column, ArrayRef<int64_t>{j,0});
                auto imag_ = rewriter.create<vector::ExtractOp>(rewriter.getUnknownLoc(), second_column, ArrayRef<int64_t>{j,1});
                // build complex number
                auto complex_val_ = rewriter.create<complex::CreateOp>(rewriter.getUnknownLoc(),ComplexType::get(rewriter.getF64Type()), real_, imag_);
                // multiply by 1/sqrt(2)
                auto new_complex_val_ = rewriter.create<complex::MulOp>(rewriter.getUnknownLoc(), complex_val_, one_div_sqrt_2_comp);
                // add the two
                new_complex_val = rewriter.create<complex::AddOp>(rewriter.getUnknownLoc(), new_complex_val, new_complex_val_);

                // insert new complex val components into jth element of firth column
                auto new_real = rewriter.create<complex::ReOp>(rewriter.getUnknownLoc(), rewriter.getF64Type() ,new_complex_val);
                auto new_imag = rewriter.create<complex::ImOp>(rewriter.getUnknownLoc(), rewriter.getF64Type() , new_complex_val);
                second_column_ = rewriter.create<vector::InsertOp>(rewriter.getUnknownLoc(), new_real, second_column_, ArrayRef<int64_t>{j,0});
                second_column_ = rewriter.create<vector::InsertOp>(rewriter.getUnknownLoc(), new_imag, second_column_, ArrayRef<int64_t>{j,1});
            }
            new_vec = rewriter.create<vector::InsertOp>(rewriter.getUnknownLoc(), first_column_, new_vec, ArrayRef<int64_t>{i,0});
            new_vec = rewriter.create<vector::InsertOp>(rewriter.getUnknownLoc(), second_column_, new_vec, ArrayRef<int64_t>{i,1});
        }

//        rewriter.create<vector::PrintOp>(rewriter.getUnknownLoc(), new_vec);

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
        auto net_index = compute_offset(operand);

        auto vector = rewriter.create<memref::LoadOp>(rewriter.getUnknownLoc(), global_vector).getResult();

        auto in_shape = vector.getType().dyn_cast<VectorType>().getShape();

        std::vector<int64_t> out_shape = compute_output_shape(in_shape, net_index);

        auto vector_type = VectorType::get(out_shape,rewriter.getF64Type());
        Value new_vec =  rewriter.replaceOpWithNewOp<vector::ShapeCastOp>(op, vector_type, vector);

        // flip the two columns
        for (int i = 0; i < out_shape[0]; i++) {
            auto first_column = rewriter.create<vector::ExtractOp>(rewriter.getUnknownLoc(), new_vec, ArrayRef<int64_t>{i,0});
            auto second_column = rewriter.create<vector::ExtractOp>(rewriter.getUnknownLoc(), new_vec, ArrayRef<int64_t>{i,1});
            new_vec = rewriter.create<vector::InsertOp>(rewriter.getUnknownLoc(), second_column, new_vec, ArrayRef<int64_t>{i,0});
            new_vec = rewriter.create<vector::InsertOp>(rewriter.getUnknownLoc(), first_column, new_vec, ArrayRef<int64_t>{i,1});
        }

        // reshape vector back into original shape
        auto original_shape_type = VectorType::get(in_shape, rewriter.getF64Type());
        new_vec = rewriter.create<vector::ShapeCastOp>(rewriter.getUnknownLoc(), original_shape_type, new_vec);
        std::cout << "X gate output: " << "\n";
//        rewriter.create<vector::PrintOp>(rewriter.getUnknownLoc(), new_vec);
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
        auto net_index = compute_offset(operand);

        //TODO: this might unnecessary
        double angle = obtain_value(op->getOperand(1).getDefiningOp());

        auto vector = rewriter.create<memref::LoadOp>(rewriter.getUnknownLoc(), global_vector).getResult();

        auto in_shape = vector.getType().dyn_cast<VectorType>().getShape();

        std::vector<int64_t> out_shape = compute_output_shape(in_shape, net_index);

        auto vector_type = VectorType::get(out_shape,rewriter.getF64Type());
        Value new_vec =  rewriter.replaceOpWithNewOp<vector::ShapeCastOp>(op, vector_type, vector);

        // global phase removed, hence omission of divide by 2
        auto real_factor = cos(angle);
        auto imag_factor = -1 * sin(angle);
        //round real and imag up to 14 decimal places
        real_factor = round(real_factor * 10000000000000) / 10000000000000;
        imag_factor = round(imag_factor * 10000000000000) / 10000000000000;
        auto real_val = rewriter.create<arith::ConstantOp>(rewriter.getUnknownLoc(), FloatAttr::get(rewriter.getF64Type(), real_factor), rewriter.getF64Type());
        auto imag_val = rewriter.create<arith::ConstantOp>(rewriter.getUnknownLoc(), FloatAttr::get(rewriter.getF64Type(), imag_factor), rewriter.getF64Type());
        auto complex_factor = rewriter.create<complex::CreateOp>(rewriter.getUnknownLoc(), ComplexType::get(rewriter.getF64Type()),
                                                                   real_val, imag_val);

        for (int i = 0; i < out_shape[0]; i++) {
            Value first_column = rewriter.create<vector::ExtractOp>(rewriter.getUnknownLoc(), new_vec, ArrayRef<int64_t>{i,0});
            Value second_column = rewriter.create<vector::ExtractOp>(rewriter.getUnknownLoc(), new_vec, ArrayRef<int64_t>{i,1});
            //first column remains unchanged
            new_vec = rewriter.create<vector::InsertOp>(rewriter.getUnknownLoc(), first_column, new_vec, ArrayRef<int64_t>{i,0});
            // iterate over second dimension, and multiply each element in second comlumn by e^(-i*angle)
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
                second_column = rewriter.create<vector::InsertOp>(rewriter.getUnknownLoc(), new_real, second_column, ArrayRef<int64_t>{j,0});
                second_column = rewriter.create<vector::InsertOp>(rewriter.getUnknownLoc(), new_imag, second_column, ArrayRef<int64_t>{j,1});
                rewriter.create<vector::InsertOp>(rewriter.getUnknownLoc(), real, second_column, ArrayRef<int64_t>{j,1});
            }
            new_vec = rewriter.create<vector::InsertOp>(rewriter.getUnknownLoc(), second_column, new_vec, ArrayRef<int64_t>{i,1});

        }

//        rewriter.create<vector::PrintOp>(rewriter.getUnknownLoc(), new_vec);

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
        target.addLegalOp<ModuleOp, quantum::QallocOp, tensor::EmptyOp>();
        target.addLegalDialect<memref::MemRefDialect, arith::ArithDialect, vector::VectorDialect,
        complex::ComplexDialect, linalg::LinalgDialect, tensor::TensorDialect,
        func::FuncDialect, scf::SCFDialect, quantum::QuantumDialect>();
        target.addIllegalOp<restquantum::Rx180Op, restquantum::Rx90Op, restquantum::Ry180Op, restquantum::RzOp, quantum::PrintGlobalVectorOp, quantum::MzOp>();
        TypeConverter typeConverter;
        typeConverter.addConversion([](Type type) { return type; });
//      target.addIllegalOp<quantum::ExtractQubitOp >();
        RewritePatternSet patterns(context);
//      patterns.add<ConvertExtractToIndex>(typeConverter, context);
        patterns.add<ConvertRx90>(typeConverter, context, global_vector);
        patterns.add<ConvertRx180>(typeConverter, context, global_vector);
        patterns.add<ConvertRy180>(typeConverter, context, global_vector);
        patterns.add<ConvertRz>(typeConverter, context, global_vector);
        patterns.add<ConvertRy90>(typeConverter, context, global_vector);
        patterns.add<ConvertPrintGlobalVector>(typeConverter, context, global_vector);
        patterns.add<ConvertMeasure>(typeConverter, context, global_vector);
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