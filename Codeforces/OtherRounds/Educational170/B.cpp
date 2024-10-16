#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9 + 7;

long long power_mod(long long a, long long b) {
    long long ans = 1;

    while (b) {
        if (b % 2 == 1) {
            ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return ans;
}

void solve() {
    int queries;
    cin >> queries;

    // n condition of existence or 1, k power of 2
    vector<pair<int, int>> pairs(queries); 
    for (auto &p: pairs) {
        cin >> p.first;
    }

    for (auto &p: pairs) {
        cin >> p.second;
    }

    for (auto &p: pairs) {
        if (p.first == p.second) {
            cout << 1 << endl;
        } else {
            cout << power_mod(2, p.second) << endl;
        }
    }
}

int main() {
    int tc = 1;

    while (tc--) {
        solve();
    }
}