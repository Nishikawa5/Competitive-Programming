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

int prod_bitwise(int a, int b) {
    /*
    a * b = a * (b31 * 2**31 + b30 * 2**30 + ... )
          = a * b0 * 2 ** 1 + a * b1 * 2 ** 2 + ...
    */
    
    int total_sum = 0;
    
    while (b > 0) {
        if ((b & 1) == 1) {
            total_sum = add_bitwise(a, total_sum);
        }

        a <<= 1;
        b >>= 1;
    }
    return total_sum;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << prod_bitwise(a, b) << endl;
}