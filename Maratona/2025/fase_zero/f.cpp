#include <bits/stdc++.h>
using namespace std;

// WA

void solve() {
    int n;
    cin >> n;

    vector<int> arr;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr.push_back(a);
    }

    
    int num;
    cin >> num;

    while (num--) {
        int target;
        cin >> target;

        vector<vector<pair<int, int>>> dp(target + 16000+1);
        
        dp[8000].push_back({0, 0});

        // first add every coin of one type to dont make duplicates
        // note that we not adding in a ordered way, but it works the same way
        // because we want only the number of ways

        // 8000 is the 0
        for (int &curr_coin: arr) {
            for (int i = 0; i <= target + 16000; i++) {
                if (i - curr_coin >= 0) {

                    for (auto &v: dp[i - curr_coin]) {

                        if (v.second <= 4) {
                            dp[i - curr_coin + 4000].push_back({v.first + curr_coin, v.second + 1});
                        }
                    }
                }
            }
        }
        cout << dp[target + 8000].size() << endl;
    }
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
