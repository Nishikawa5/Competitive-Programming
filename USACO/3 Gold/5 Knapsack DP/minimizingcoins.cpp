#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, desired_sum;
    cin >> n >> desired_sum;

    vector<int> coins;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        if (c <= desired_sum) {
            coins.push_back(c);
        }
    }

    vector<int> min_coins(desired_sum + 1, INT_MAX - 1);
    n = coins.size();
    for (int i = 0; i < n; i++) {
        min_coins[coins[i]] = 1;
    }

    for (int i = 1; i <= desired_sum; i++) {
        for (int c = 0; c < n; c++) {
            if (i - coins[c] >= 1) {
                min_coins[i] = min(min_coins[i], min_coins[i - coins[c]] + 1);
            }
        }
    }
    cout << (min_coins[desired_sum] == (INT_MAX - 1) ? -1 : min_coins[desired_sum]) << endl;
}