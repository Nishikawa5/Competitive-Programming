#include <bits/stdc++.h>
using namespace std;

// ~40
vector<int> operations(2e5 + 1);
void pre_calculate() {
    operations[0] = 0;
    for (int i = 1; i <= 2e5; i++) {
        int curr_num = i;
        int ans = 0;
        while (curr_num) {
            curr_num /= 3;
            ans++;
        }

        operations[i] = ans + operations[i - 1];
    }
}

void solve() {
    // make a zero then make the others zero (by finding the lowest num)
    // first pick the first two
    int l, r;
    cin >> l >> r;

    cout << operations[r] - operations[l - 1] + operations[l] - operations[l - 1] << endl;
}
 
int main() {
    pre_calculate();

    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
}