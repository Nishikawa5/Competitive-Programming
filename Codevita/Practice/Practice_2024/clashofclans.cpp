#include <bits/stdc++.h>
using namespace std;

/*
max dmg
barracks with capacity
troop s with dps

at most one or none for each

*/
int main(void) {
    vector<pair<int, int>> attr;

    // attributes separated by category
    vector<vector<pair<int, int>>> troops(20);

    int barrack;

    int temp;
    int garbage;
    scanf("%d", &temp);
    attr.push_back({temp, 0});
    while ((garbage = getchar()) != '\n') {
        scanf("%d", &temp);
        attr.push_back({temp, 0});
    }
    
    for (auto &at: attr) {
        scanf("%d", &temp);
        at.second = temp;
    }

    for (int i = 0; i < attr.size(); i++) {
        scanf("%d", &temp);
        troops[temp].push_back(attr[i]);
    }

    scanf("%d", &barrack);

    // dp table dp: size -> dps
    vector<int> dp(barrack + 1, 0);
    vector<int> dp_copy;

    // use each category
    for (int i = 0; i < 20; i++) {
        dp_copy = dp;
        for (int j = 0; j < troops[i].size(); j++) {
            // change the copy based on last dp
            for (int size = barrack; size >= troops[i][j].second; size--) {
                dp_copy[size] = max(dp_copy[size], dp[size - troops[i][j].second] + troops[i][j].first);
            }
        }
        dp = dp_copy;
    }

    printf("%d\n", dp[barrack]);
}