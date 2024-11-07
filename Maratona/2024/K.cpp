#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    // the one that has less candy take the candy
    // we want to make they get the same amount of candy
    // so the amount of candies both get is sum / 2
    // we can put the candy in any order that satisfies that
    // then if we can get sum / 2 candies for one we can get
    // sum / 2 candies for the other by manipulating the order of candies
    vector<int> candies(n);
    int sum = 0;
    for (auto &c: candies) {
        cin >> c;
        sum += c;
    }

    if (sum % 2) {
        cout << "-1\n";
    } else {
        int target = sum / 2;

        // lets try to get the candies for one
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (int i = 0; i < candies.size(); i++) {
            for (int j = target; j >= 0; j--) {
                // target -> 0 to get only one of each amount candy
                if (j - candies[i] >= 0) {
                    dp[j] |= dp[j - candies[i]];
                }
            }
        }

        if (dp[target]) {
            // is possible, so lets get the order
            int curr_sum = target;

            vector<int> ana_candies;
            while (curr_sum != 0) {
                for (int i = 0; i < candies.size(); i++) {
                    if (dp[curr_sum - candies[i]]) {
                        ana_candies.push_back(candies[i]);
                        curr_sum -= candies[i];
                        candies.erase(candies.begin() + i);
                        break;
                    }
                }
            }

            // manipulate candy order to make them equal
            int ana_sum = ana_candies[0];
            int bob_sum = 0;
            cout << ana_candies[0] << " ";
            int a_idx = 1;
            int b_idx = 0;
            while (a_idx + b_idx < n) {
                if (ana_sum > bob_sum) {
                    cout << candies[b_idx] << " ";
                    bob_sum += candies[b_idx++];
                } else {
                    cout << ana_candies[a_idx] << " ";
                    ana_sum += ana_candies[a_idx++];
                }
            }


        } else {
            // not possible
            cout << "-1\n";
        }

    }
}