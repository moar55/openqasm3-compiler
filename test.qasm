OPENQASM 3.0;
qubit[2] q;
X q[1];
bit[2] c;
c = measure q;
print(c);
// bug fix regarding measuring two qubits