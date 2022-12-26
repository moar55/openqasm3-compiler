OPENQASM 3.0;
bit[1] c;
  GNU nano 4.8                                                                                                                                              test.mlir                                                                                                                                                        "builtin.module"() ({
  "func.func"() ({
    %1 = memref.alloc() : memref<5xi1>
    %2 = "arith.constant"() {value = 1 : index} : () -> index
    %12 = memref.load %1[%2] : memref<5xi1>
    %13 = arith.extui %12 : i1 to i32
    "func.return"(%13) : (i32) -> ()
  }) {function_type = () -> i32, sym_name = "main"} : () -> ()
}) : () -> ()






 mlir-opt --convert-func-to-llvm --convert-vector-to-llvm --convert-arith-to-llvm test.mlir | mlir-cpu-runner --entry-point-result=i32 -shared-libs=/usr/local/lib/libmlir_runner_untis.so