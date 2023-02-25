OPENQASM 3.0;
qubit [2] q;
CX q[0], q[1];
Z q[0];
H q[0];
Y q[0];
H q[0];
X q[0];
X q[0];
RZ(0.5 * pi) q[0];
RZ(pi) q[0];

bit c0;
c0 = measure q[0];

//TODO: change CX to iswap...etc