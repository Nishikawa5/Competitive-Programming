#include <bits/stdc++.h>
using namespace std;

// + just with bitwise op
int add_bitwise(int a, int b) {
    /*
    a + b = 2 * (a & b) + a xor b

    => a + b = (a & b) << 1 + a ^ b
    => a + b = ((a & b) << 1 & a ^ b) + (a & b) << 1 ^ (a ^ b)         a            b
    => a + b = (((a & b) << 1 & a ^ b) & (a & b) << 1 ^ (a ^ b)) + ((a & b) << 1 & a ^ b) ^ (a & b) << 1 ^ (a ^ b) 
    
    */
    if (((a & b) << 1) == 0) {
        // carry == 0, so return a xor b
        return a ^ b;
    }

    return add_bitwise((a & b) << 1, a ^ b);
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << add_bitwise(a, b) << endl;
}