#include <bits/stdc++.h>
using namespace std;

int limit = 1e5 + 1;
vector<int> primes;
vector<bool> isPrime(limit, false);

void sieve_erastotenes() {
    for (int curr_num = 2; curr_num < limit; curr_num++) {
        // the falses are prime
        if (!isPrime[curr_num]) {
            primes.push_back(curr_num);
            int mult_prime = 2 * curr_num;
            while (mult_prime < limit) {
                // not prime
                isPrime[mult_prime] = true;
                mult_prime += curr_num;
            }
        }
    }
}


void solve() {
    int n;
    cin >> n;

    int total_sum = 5;
    int ans = 0;
    for (int i = 2; i < primes.size() && total_sum <= n; i++) {
        ans += !isPrime[total_sum];
        total_sum += primes[i];
    }

    cout << ans << endl;
}

int main() {
    int tc;
    cin >> tc;

    sieve_erastotenes();

    while (tc--) {
        solve();
    }
}