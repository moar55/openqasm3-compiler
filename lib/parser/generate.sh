#!/bin/bash
set - o errexit
java -jar ../tools/antlr-4.10.1-complete.jar -Dlanguage=Cpp -visitor -o generated/ -package mlir qasm.g4
