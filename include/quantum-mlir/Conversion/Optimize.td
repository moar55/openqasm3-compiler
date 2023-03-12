include "mlir/IR/PatternBase.td"
include "QuantumOps.td"
include "mlir/Dialect/Arith/IR/ArithOps.td"

def HYH: Pat<(HOp (YOp (HOp $input))), (YOp $input)>;
def HXH: Pat<(HOp (XOp (HOp $input))), (ZOp $input)>;
def HZH: Pat<(HOp (ZOp (HOp $input))), (XOp $input)>;
def HZXH: Pat<(HOp (ZOp (XOp (HOp $input)))), (YOp $input)>;
def HIdentity: Pat<(HOp (HOp $input)), (replaceWithValue $input)>;
def XIdentity: Pat<(XOp (XOp $input)), (replaceWithValue $input)>;
def YIdentity: Pat<(YOp (YOp $input)), (replaceWithValue $input)>;
def ZIdentity: Pat<(ZOp (ZOp $input)), (replaceWithValue $input)>;
def SIdentity: Pat<(SOp (SOp $input)), (replaceWithValue $input)>;
def TIdentity: Pat<(TOp (TOp $input)), (replaceWithValue $input)>;

//reference: https://github.com/Cloudpurp/tensorflow_me/blob/b280285a9d3031f1265f9d22355a1daf2087f201/tensorflow/compiler/xla/mlir_hlo/mhlo/transforms/legalize_to_standard/legalize_to_standard_patterns.td#L39
def createFastMathNone : NativeCodeCall<
    "::mlir::arith::FastMathFlagsAttr::get("
      "$_builder.getContext(), ::mlir::arith::FastMathFlags::none"
    ")">;

def RzRz: Pat<(RzOp (RzOp $input, $theta2), $theta1),(RzOp $input, (Arith_AddFOp $theta1, $theta2, (createFastMathNone)))>;


