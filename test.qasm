OPENQASM 3.0;
qubit[2] q;
H q[0];
X q[1];
// prints the global vector,
// state is written from right to left, where right most bit is the least significant bit
PRINT_GLOBAL_VECTOR();
bit[2] c;
c[0] = measure q[0];
c[1] = measure q[1];
print(c);
// bits are printed from left to right, where left most bit is the least significant bit
// bug fix regarding measuring two qubits