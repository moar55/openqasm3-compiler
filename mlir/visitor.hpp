#ifndef Quantum_OPS
#define Quantum_OPS

include "QuantumDialect.td"
include "mlir/Interfaces/SideEffectInterfaces.td"

def QubitType : OpaqueType<"quantum", "Qubit", "opaque qubit type">;
def ResultType : OpaqueType<"quantum", "Result", "opaque result type">;
def ArrayType : OpaqueType<"quantum", "Array", "opaque array type">;
def ArgvType : OpaqueType<"quantum", "ArgvType", "opaque argv type">;
def QregType : OpaqueType<"quantum", "QregType", "opaque qreg type">;
def StringType : OpaqueType<"quantum", "StringType", "opaque string type">;
def TupleType : OpaqueType<"quantum", "Tuple", "opaque tuple type">;
def CallableType : OpaqueType<"quantum", "Callable", "opaque callable type">;

def QallocOp : QuantumOp<"qalloc", []> {
let arguments = (ins AnyI64Attr:$size, StrAttr:$name);
let results = (outs ArrayType:$qubits);

let printer = [{  auto op = *this;
p << "q.qalloc(" << op.size() << ") { name = " << op.name() << " }";
p << " : " << op.qubits().getType(); }];
}

// Create an array holding Qubit pointers for aliasing purposes,
// i.e. not allocating new qubits.
def QaliasArrayAllocOp : QuantumOp<"createQubitArray", []> {
let arguments = (ins AnyI64Attr:$size, StrAttr:$name);
let results = (outs ArrayType:$qubits);
let printer = [{  auto op = *this;
p << "q.createArray(" << op.size() << ") { name = " << op.name() << " }";
p << " : " << op.qubits().getType(); }];
}

def ExtractQubitOp : QuantumOp<"qextract", []> {
let arguments = (ins ArrayType:$qreg, AnyInteger:$idx);
let results = (outs QubitType:$qbit);
let printer = [{  auto op = *this;
p << "q.extract(" << op.getOperands() << ")";
p << " : " << op.qbit().getType(); }];
}

def GeneralArrayExtractOp : QuantumOp<"array_extract", []> {
let arguments = (ins ArrayType:$array, AnyInteger:$idx);
let results = (outs AnyType:$element);
let printer = [{  auto op = *this;
p << "q.array_extract(" << op.getOperands() << ")";
p << " : " << op.element().getType(); }];
}

// Assign a qubit pointer (specified by the Qubit array and index) to an alias pointer.
// Signature: void qassign(Array* destination_array, int destination_idx, Array* source_array, int source_idx)
def AssignQubitOp : QuantumOp<"qassign", []> {
let arguments = (ins ArrayType:$dest_qreg, AnyInteger:$dest_idx, ArrayType:$src_qreg, AnyInteger:$src_idx);
let results = (outs);
let printer = [{  auto op = *this;
p << "q.qassign " << op.src_qreg() << "[" << op.src_idx() << "] -> " << op.dest_qreg() << "[" << op.dest_idx() << "]";}];
}

// Extract array slice
def ArraySliceOp : QuantumOp<"qarray_slice", []> {
let arguments = (ins ArrayType:$qreg, Variadic<I64>:$slice_range);
let results = (outs ArrayType:$array_slice);
let printer = [{  auto op = *this;
p << "q.qarray_slice (" << op.getOperands() << ")";
p << " : " << op.array_slice().getType();
}];
}
// Array Concatenation
def ArrayConcatOp : QuantumOp<"qarray_concat", []> {
let arguments = (ins ArrayType:$qreg1, ArrayType:$qreg2);
let results = (outs ArrayType:$concat_array);
let printer = [{  auto op = *this;
p << "q.qarray_concat (" << op.getOperands() << ")";
p << " : " << op.concat_array().getType();
}];
}

def StartCtrlURegion : QuantumOp<"start_ctrl_u_region", []> {
let arguments = (ins);
let results = (outs);
let printer = [{
p << "q.ctrl_region {";
}];
}

def EndCtrlURegion : QuantumOp<"end_ctrl_u_region", []> {
let arguments = (ins QubitType:$ctrl_qubit);
let results = (outs);
let printer = [{  auto op = *this;
p << "} (ctrl_bit = " << op.ctrl_qubit() << ") // END CTRL";
}];
}

def StartAdjointURegion : QuantumOp<"start_adj_u_region", []> {
let arguments = (ins);
let results = (outs);
let printer = [{
p << "q.adj_region {";
}];
}

def EndAdjointURegion : QuantumOp<"end_adj_u_region", []> {
let arguments = (ins);
let results = (outs);
let printer = [{
p << "} // END ADJOINT";
}];
}

def StartPowURegion : QuantumOp<"start_pow_u_region", []> {
let arguments = (ins);
let results = (outs);
let printer = [{
p << "q.pow_u_region {";
}];
}

def EndPowURegion : QuantumOp<"end_pow_u_region", []> {
let arguments = (ins AnyI64:$pow);
let results = (outs);
let printer = [{
auto op = *this;
p << "} (pow = " << op.pow() << ") // END POWER";
}];
}

def ComputeMarkerOp : QuantumOp<"compute_marker", []> {
let arguments = (ins);
let results = (outs);
let printer = [{
p << "q.mark_compute {";
}];
}

def ComputeUnMarkerOp : QuantumOp<"compute_unmarker", []> {
let arguments = (ins);
let results = (outs);
let printer = [{
p << "} // END COMPUTE";
}];
}

def InstOp : QuantumOp<"inst", [AttrSizedOperandSegments]> {
let arguments = (ins StrAttr:$name, Variadic<QubitType>:$qubits, Variadic<F64>:$params);
let results = (outs Optional<ResultType>:$bit);

let printer = [{  auto op = *this;
p << "q." << op.name() << "(" << op.getOperands() << ") : " << op.getResultTypes(); }];
}

def ValueSemanticsInstOp : QuantumOp<"value_inst", [AttrSizedOperandSegments]> {
let arguments = (ins StrAttr:$name, Variadic<QubitType>:$qubits, Variadic<F64>:$params);
let results = (outs Variadic<AnyTypeOf<[ResultType, QubitType]>>:$result);

let printer = [{  auto op = *this;
p << "qvs." << op.name() << "(" << op.getOperands() << ") : " << op.result().getType(); }];
}

def DeallocOp : QuantumOp<"dealloc", []> {
let arguments = (ins ArrayType:$qubits);
let results = (outs);
let printer = [{  auto op = *this;
p << "q.dealloc(" << op.qubits() << ")"; }];
}

def QRTInitOp : QuantumOp<"init", []> {
let arguments = (ins AnyI32:$argc, ArgvType:$argv, OptionalAttr<StrArrayAttr>:$extra_args);
let results = (outs);
let printer = [{  auto op = *this;
p << "q.init(" << op.getOperands() << ") " << op.extra_argsAttr(); }];
}

def QRTFinalizeOp : QuantumOp<"finalize", []> {
let arguments = (ins);
let results = (outs);
let printer = [{  p << "q.finalize()"; }];
}

def SetQregOp : QuantumOp<"set_qreg", []> {
let arguments = (ins QregType:$qreg);
let results = (outs);
let printer = [{  auto op = *this;
p << "q.set_qreg(" << op.qreg() << ")"; }];
}

def PrintOp : QuantumOp<"print", []> {
let arguments = (ins Variadic<AnyType>:$print_args);
let results = (outs);
let printer = [{  auto op = *this;
p << "q.print(" << op.getOperands() << ")"; }];
}

def CreateStringLiteralOp : QuantumOp<"createString", []> {
let arguments = (ins StrAttr:$text, StrAttr:$varname);
let results = (outs StringType:$result);
let printer = [{  auto op = *this;
p << "q.create_string(\"" << op.text() << "\")"; }];
}

// Cast QIR Result to bool (i1 type)
def ResultCastOp : QuantumOp<"resultCast", []> {
let arguments = (ins ResultType:$measure_result);
let results = (outs I1:$bit_result);
let printer = [{  auto op = *this;
p << "q.resultCast" << "(" << op.measure_result() << ") : " << op.bit_result().getType(); }];
}

// Sign-Unsign cast:
// Rationale: std dialect only accepts signless type (i.e. int but not uint)
// we need to have this cast op in the dialect to finally lower to LLVM cast
// which can handle int -> uint casting at the final lowering phase.
// Note: std.index_cast cannot handle int -> unit casting (one of the type must be an index type).
def IntegerCastOp : QuantumOp<"integerCast", []> {
let arguments = (ins AnyInteger:$input);
let results = (outs AnyInteger:$output);
let printer = [{  auto op = *this;
p << "q.integerCast" << "(" << op.input() << ") : " << op.output().getType(); }];
}

// Unpack a Tuple
def TupleUnpackOp : QuantumOp<"tupleUnpack", []> {
let arguments = (ins TupleType:$tuple);
let results = (outs Variadic<AnyType>:$result);
let printer = [{  auto op = *this;
p << "q.tupleUnpack" << "(" << op.tuple() << ") : " << op.result().getType(); }];
}

def CreateCallableOp : QuantumOp<"createCallable", []> {
let arguments = (ins FlatSymbolRefAttr:$functors, Variadic<AnyType>:$captures);
let results = (outs CallableType:$callable);
let printer = [{  auto op = *this;
p << "q.createCallable" << "(" << op.functors() << ") ";
if (!op.captures().empty()) {
p << "capture " << op.captures() << "(" << op.captures().getType()
<< ")";
}
}];
}

def ConditionalOp : QuantumOp<"ifOp", []> {
let summary = "if-then-else operation conditioned on a quantum Measure";
// Must be conditioned on a Result type (only then clause for now...)
let arguments = (ins ResultType:$result_bit, CallableType:$then_callable);
let results = (outs);

let printer = [{
auto op = *this;
p << "q.If " << op.result_bit() << " { invoke " << op.then_callable() << " }";
}];
}

#endif // Quantum_OPS