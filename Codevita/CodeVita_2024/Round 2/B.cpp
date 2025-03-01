#include <bits/stdc++.h>
using namespace std;

void solve() {
    int strings_num, combinations;
    cin >> strings_num >> combinations;

    vector<string> strs(strings_num);
    vector<int> costs(strings_num);
    vector<int> scores(strings_num);
    for (int i = 0; i < strings_num; i++) {
        cin >> strs[i];

        for (char c: strs[i]) {
            scores[i] += c - 'a' + 1;
        }
    }

    for (auto &c: costs) {
        cin >> c;
    }

    unordered_map<string, vector<string>> contradictory;
    for (int i = 0; i < combinations; i++) {
        string str1, str2;
        cin >> str1 >> str2;
        contradictory[str1].push_back(str2);
        contradictory[str2].push_back(str1);
    }

    int max_cost;
    cin >> max_cost;

    int max_score_possible = 20 * 50 * ('z' - 'a' + 1);
    vector<pair<vector<pair<vector<int>, int>>, int>> dp(max_score_possible + 1);
    dp[0].second = 1;
    pair<vector<int>, int> initial;
    initial.second = 0;
    dp[0].first.push_back(initial);

    for (int i = 0; i < strings_num; i++) {
        // use one string

        for (int j = max_score_possible; j - scores[i] >= 0; j--) {

            if (dp[j - scores[i]].second == 1) {


                for (auto &pos: dp[j - scores[i]].first) {
                    // check if is possible adding this string to it

                    int curr_cost = pos.second + costs[i];
                    if (curr_cost > max_cost) continue;

                    bool possible = true;
                    for (auto &checkstr: contradictory[strs[i]]) {

                        for (auto &idx: pos.first) {
                            if (checkstr == strs[idx]) {
                                possible = false;
                                break;
                            }
                        }
                        if (!possible) break;
                    }
                    if (!possible) continue;

                    // possible to add => add
                    vector<int> new_vec = pos.first;
                    new_vec.push_back(i);

                    pair<vector<int>, int> new_node;
                    new_node.first = new_vec;
                    new_node.second = curr_cost;

                    dp[j].first.push_back(new_node);

                    dp[j].second = 1;
                }
            }
        }
    }


    for (int i = max_score_possible; i >= 0; i--) {
        if (dp[i].second) {
            cout << i << endl;
            return;
        }
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
