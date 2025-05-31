#include <bits/stdc++.h>
using namespace std;

int operation(int x, vector<bool> &is_prime, vector<int> &primes) {

    for (auto it = primes.begin(); it != primes.end(); it++) {
        if (is_prime[x - *it]) {
            return (x - *it) - *it;
        }
    }
    return -1;
}

void solve() {
    int x;
    cin >> x;

    vector<bool> is_prime(x+1, true);
    vector<int> primes;


    is_prime[0] = is_prime[1] = false;

    for (long long i = 2; i <= x; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (long long j = i * i; j <= x; j += i) {
                is_prime[j] = false;
            }
        }
    }


    int steps = 0;
    while (x >= 4) {
        x = operation(x, is_prime, primes);
        steps++;
    }
    cout << steps << endl;
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
