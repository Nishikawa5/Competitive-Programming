#include <bits/stdc++.h>

using namespace std;

// generalizing the idea in beststockIII
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    int buy[k];
    int profit[k];
    for (int i = 0; i < k; i++) {
        buy[i]    = INT_MAX;
        profit[i] = INT_MIN;
    }

    for (int i = 0; i < n; i++) {
        buy[0] = min(buy[0], prices[i]);
        profit[0] = max(profit[0], prices[i] - buy[0]);
        for (int j = 1; j < k; j++) {
            buy[j] = min(buy[j], prices[i] - profit[j - 1]);
            profit[j] = max(profit[j], prices[i] - buy[j]);
        }
    }
    return profit[k - 1];
}