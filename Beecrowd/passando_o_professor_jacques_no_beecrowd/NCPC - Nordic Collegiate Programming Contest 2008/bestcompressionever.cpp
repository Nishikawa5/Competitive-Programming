#include <bits/stdc++.h>
using namespace std;

#define ll long long 

int main() {
    // n != files of 1000 bits
    // compressed to B bits

    // can    N != files of 1000 bits -> N != files of B bits
    // we can have 2**(B+1) - 1 different files
    // =>    N <= 2**(B+1) - 1    => N + 1 <= 2**(B+1)       => divide by 2 
    
    ll n, bits;
    cin >> n >> bits;

    // check which has more bits
    while (bits) {
        n >>= 1;
        bits--;
    }

    if (n <= 1) {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }
}