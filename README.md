# OPENQASM 3.0 compiler
## Installation steps
## How to build
## How to Run
 * create symbolic link to test.qasm in your build/bin folder:
   `ln -s ../../test.qasm .`
 * setup your ide to run or use following command: `<some_command>`


## How to run JIT with a .mlir file
```
 mlir-opt test.mlir -convert-scf-to-cf -convert-vector-to-llvm -convert-func-to-llvm -reconcile-unrealized-casts | /
 mlir-cpu-runner --entry-point-result=i32  -shared-libs=/usr/local/lib/libmlir_runner_c_utils.so
```