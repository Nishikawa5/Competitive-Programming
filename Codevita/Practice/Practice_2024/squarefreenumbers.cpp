#include <bits/stdc++.h>
using namespace std;
int limit = sqrt(1e9) + 2;
vector<int> primes;
vector<bool> isnot_prime(limit);

void sieve_erastotenes() {
    for (int i = 2; i < 1e5; i++) {
        if (!isnot_prime[i]) {
            primes.push_back(i);

            for (int curr_prime = i * 2; curr_prime < limit; curr_prime += i) {
                isnot_prime[curr_prime] = true;
            }
        }
    }
}

bool is_squarefree(int n, vector<int> &factors) {
    int i = 0;
    while (i < factors.size() && factors[i] * factors[i] <= n) {
        if (!(n % (factors[i] * factors[i]))) {
            return false;
        }
        i++;
    }
    return true;
}

void solve() {
    int n, N;
    cin >> N;
    n = N;

    int i = 0;
    vector<int> factors;

    while (n != 1) {
        if (!(n % primes[i])) {
            factors.push_back(primes[i]);

            while (!(n % primes[i])) {
                n /= primes[i];
            }
        }
        i++;
    }

    // 
    int ans = 0;
    for (int i = 2; i < N; i++) {
        ans += (N % i == 0) && is_squarefree(i, factors);
    }
    
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 1;

    sieve_erastotenes();

    while (tc--) {
        solve();
    }
    return 0;
}
