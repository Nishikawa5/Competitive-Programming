#include <bits/stdc++.h>
using namespace std;

#define lli long long int

// how do we avoid overflow in 10^8 * 10 ^ 8
lli fastpow(int result, lli a, lli b) {
    if (b == 0) {
        return result;
    }

    if (b % 2 == 0) {
        return fastpow(result, (a * a) % (lli) (1e9 + 7), b / 2);
    } else {
        return fastpow((result * a) % (lli) (1e9 + 7), a, b - 1);
    }
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        long long int a, b;
        cin >> a >> b;
        cout << fastpow(1, a, b) << endl;
    }
}