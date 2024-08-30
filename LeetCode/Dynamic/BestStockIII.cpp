#include <bits/stdc++.h>

using namespace std;

int maxProfit(vector<int>& prices) {
    if (prices.size() == 0) {
        return 0;
    }
    int n = prices.size();
    // the price of buy2 is relative, depending of the profit of first stock
    int buy1 = INT_MAX;
    int buy2 = INT_MAX;
    // profit after 1 and 2 buy -> sell
    int profit1 = INT_MIN;
    int profit2 = INT_MIN;

    for (int i = 0; i < n; i++) {
        buy1 = min(buy1, prices[i]);
        profit1 = max(profit1, prices[i] - buy1);
        buy2 = min(buy2, prices[i] - profit1);
        profit2 = max(profit2, prices[i] - buy2);
    }
    return profit2;
}