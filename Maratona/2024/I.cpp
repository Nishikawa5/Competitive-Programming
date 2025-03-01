#include <bits/stdc++.h>
using namespace std;

int N = 1e6 + 1;
long long mod = 1e9 + 7;
/*
mobius[i] == 1  iff    i is a product of even distinct primes
          == -1 iff    i is a product of odd distinct primes
          == 0  iff    i is divisible by a perfect square > 1
*/
vector<int> mobius(N);
vector<long long> power2(N); 

void solve() {
    int n;
    cin >> n;

    // count[i] different foods with same ingredients i
    vector<int> count(N);
    // dp[i] == number of dishes without ingredient i
    vector<int> dp(N);

    while (n--) {
        int food;
        cin >> food;

        count[food]++;
    }

    for (int i = 1; i < N; i++) {
        for (int j = i + i; j < N; j += i) {
            // number of foods divisible by i
            count[i] += count[j];
        }
    }

    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            // odd num of primes:  overcounted foods
            // even num of primes: foods divisible by i
            // i's are every divisor of j
            dp[j] += count[i] * mobius[i];
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int allergy;
        cin >> allergy;
        // can form 2^foods subsets
        cout << power2[dp[allergy]] << endl;
    }
}

int main() {
    int tc;
    tc = 1;

    // fill mobius
    // base case
    mobius[1] = 1;
    for (int i = 1; i < N; i++) {
        for (int j = i + i; j < N; j += i) {           
            mobius[j] -= mobius[i];
        }
    }

    long long powerof2 = 1;
    for (int i = 0; i < N; i++) {
        power2[i] = powerof2;
        powerof2 = (powerof2 * 2) % mod;
    }

    while (tc--) {
        solve();
    }
}