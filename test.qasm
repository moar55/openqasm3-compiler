OPENQASM 3.0;
bit[3] c;
bit[3] c1;
qubit[3] q;
qubit[3] z;
X q[0];
X q[1];
X q[2];

c = measure q;
c1 = measure z;
bit [3] c2;
c2 = c / c1;
print(c);