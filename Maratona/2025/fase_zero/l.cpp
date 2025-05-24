#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    ll m;
    cin >> m;

    // mb 10**6 byets
    // 2**qubits = 10**6M
    ll mb = 1e6 * m;

    ll qubits = 0;
    ll pot = 1;
    while (pot < mb) {
        pot *= 2;
        qubits++;
    }
    cout << qubits + 3 << endl;
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
