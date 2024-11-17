#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int max_coin = 0;
    int max_sum = 0;

    /*
    see that in binary:
    1, 10, 100, 1000, 10000, 100000, ...

    can choose any bit to be 1 or 0
    */
    while (max_sum < n) {
        max_coin++;
        
        // 11...10 + 1
        max_sum <<= 1;
        max_sum++;
    }
    cout << max_coin << endl;
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}
