#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

void solve() {
    /*
    _ _ _ _ _ ... _
    P = (how many pairs of 1 in every combination * (2^(k - 1))^n) * k
    Q = (2^k)^n
    */

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 1;

    while (tc--) {
        solve();
    }
    return 0;
}
