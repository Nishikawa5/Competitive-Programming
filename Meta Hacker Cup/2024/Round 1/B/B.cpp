#include <bits/stdc++.h>
using namespace std;

int n = 1e7;

vector<bool> is_prime(n + 1, true);
void precompute_primes() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && (long long)i * i <= n) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

vector<int> subtrac_prefix(n + 1);
void precompute_subtractorization() {
    /*
        odd - even = odd
        odd - odd = even

        the only prime even = 2 and 2 is N-subtractorization for N >= 5
        so we want to find primes > 2 where
        prime1 - 2 = prime2
        =>
        prime1 = prime2 + 2
        twin primes
        won't repeat if we go from least to max
    */

    subtrac_prefix[0] = 0;
    for (int i = 2; i <= n; i++) {
        subtrac_prefix[i] = subtrac_prefix[i - 1];
        if (is_prime[i] && is_prime[i - 2]) {
            subtrac_prefix[i]++;
        }
    }
}


void solve() {

    int n;
    cin >> n;
    cout << subtrac_prefix[n] + (n >= 5) << endl;
}

int main() {
    int tc;
    cin >> tc;
    cout << fixed << setprecision(7);

    precompute_primes();
    precompute_subtractorization();

    for (int i = 1; i <= tc; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}