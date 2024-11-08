#include <bits/stdc++.h>
using namespace std;

bool dfs(int v, vector<int> &ana_candies, vector<bool> &visited, vector<vector<int>> &graph) {
    ana_candies.push_back(v);

    if (v == 0) {
        return true;
    }

    for (auto cv: graph[v]) {
        if (!visited[cv] && dfs(cv, ana_candies, visited, graph)) {
            return true;
        }
    }
    ana_candies.pop_back();
    return false;
}


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
        vector<vector<int>> back(target + 1);
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (int i = 0; i < candies.size(); i++) {
            for (int j = target; j >= 0; j--) {
                // target -> 0 to get only one of each amount candy
                if (j - candies[i] >= 0) {
                    if (dp[j - candies[i]]) {
                        dp[j] = 1;
                        back[j].push_back(j - candies[i]);
                    }
                }
            }
        }

        if (dp[target]) {
            // is possible, so lets get the order
            int curr_sum = target;

            vector<int> candies_path;
            // dfs back to 0
            vector<bool> visited(target, false);
            dfs(target, candies_path, visited, back);


            vector<int> alice_candies(candies_path.size() - 1);
            for (int i = 0; i < alice_candies.size(); i++) {
                alice_candies[i] = candies_path[i] - candies_path[i + 1];

                for (int j = 0; j < candies.size(); j++) {
                    if (alice_candies[i] == candies[j]) {
                        candies.erase(candies.begin() + j);
                        break;
                    }
                }
            }

            // manipulate candy order to make them equal
            int alice_sum = 0;
            int bob_sum = 0;
            int a_idx = 0;
            int b_idx = 0;
            while (a_idx + b_idx < n) {
                if (alice_sum > bob_sum) {
                    cout << candies[b_idx] << " ";
                    bob_sum += candies[b_idx++];
                } else {
                    cout << alice_candies[a_idx] << " ";
                    alice_sum += alice_candies[a_idx++];
                }
            }


        } else {
            // not possible
            cout << "-1\n";
        }

    }
}