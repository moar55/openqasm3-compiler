OPENQASM 3.0;
qubit[2] q;
CX q[0], q[1];
PRINT_GLOBAL_VECTOR();
bit [2] b;
b[0] = measure q[0];
b[1] = measure q[1];
print(b);