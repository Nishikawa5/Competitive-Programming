#include <bits/stdc++.h>
using namespace std;

long long mod_inverse(long long x, long long mod) {
    long long result = 1;
    long long power = mod - 2; // Since mod is prime, use mod-2 for modular inverse
    while (power) {
        if (power % 2) {
            result = (result * x) % mod;
        }
        x = (x * x) % mod;
        power /= 2;
    }
    return result;
}

int main() {
    int tc;
    int mod = (int) 1e9 + 7;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;

        long long tot_sum = 0;
        vector<long long> balls(n);
        for (auto &b: balls) {
            cin >> b;
            tot_sum += b;
            tot_sum %= mod;
        }

        long long product_sum = 0;
        long long max_div = 0;
        for (int i = 0; i < n; i++) {
            tot_sum += mod;
            tot_sum -= balls[i];
            tot_sum %= mod;

            product_sum += tot_sum * balls[i];
            product_sum %= mod;
            max_div += n - i - 1;
            max_div %= mod;
        }

        cout << (product_sum * mod_inverse(max_div, mod)) % mod << endl;
    }
}