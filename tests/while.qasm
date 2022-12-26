OPENQASM 3.0;
int [24] x = 10;
int [24] y = 20;
qubit q;
while(y > 0) {
 int[24] z = 12;
 while (z < 20) {
    z = z + 1;
    y = y + 1;
    X q;
 }
 x = x + z;
}
y = y + x;
qubit z;
H z;
CX q, z;