#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    /*
    cases:
    same number of characters for both strings <=> 2 | characters

    one odd >= 3 and the other characters are equal counts? no

    state of a parity:
    a string is happy <=>  two states [0, l - 1] and [0, r] are identical
    (we have this state extra digits in [0, l - 1] and this state extra digits [0, r]
    so if we have the same extra digits in both, combining the states would have no extra digit
    (by removing the left state))
    we can make (n - 1) * n / 2 combinations with those states

    sliding window would be too slow O(n^2)
    */
    string number;
    cin >> number;

    // store the current state of parity
    // 0 => digit appeared even times
    // 1 => digit appeared odd times
    int curr_state = 0;

    // count the number of states
    map<int, ll> state_count;
    state_count[0] = 1;

    for (char digit: number) {
        curr_state ^= 1 << (digit - '0');
        state_count[curr_state]++;
    }

    ll ans = 0;
    for (auto state_num: state_count) {
        ans += (state_num.second - 1) * state_num.second / 2; 
    }
    cout << ans << endl;
}

int main() {
    int tc = 1;

    while (tc--) {
        solve();
    }
}