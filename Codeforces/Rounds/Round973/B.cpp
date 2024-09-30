#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;

    if (n == 2) {
        int a, b;
        cin >> a >> b;
        cout << (b - a) << endl;
        return;
    }

    ll total_sum = 0;
    for (int i = 0; i < n - 2; i++) {
        ll fighter;
        cin >> fighter;
        total_sum += fighter;
    }
    ll penultimate_fighter;
    ll last_fighter;
    cin >> penultimate_fighter >> last_fighter;

    cout << last_fighter - (penultimate_fighter - total_sum) << endl;
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
}