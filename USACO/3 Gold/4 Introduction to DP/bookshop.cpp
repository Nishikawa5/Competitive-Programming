#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, money;
    cin >> n >> money;

    vector<pair<int, int>> prices_books(n);
    for (auto &p: prices_books) {
        cin >> p.first;
    }
    for (auto &p: prices_books) {
        cin >> p.second;
    }

    vector<int> dp(money + 1, 0);
    for (int i = 0; i < n; i++) {
        // select the book we are buying

        for (int k = money; k >= prices_books[i].first; k--) {
            // select the value we are at
            dp[k] = max(dp[k], dp[k - prices_books[i].first] + prices_books[i].second);
        }
    }
    cout << dp[money] << endl;
}