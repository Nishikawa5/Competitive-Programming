#include <bits/stdc++.h>
using namespace std;

/*
didn't need to use upperbounds since we can just consider bessie will play her
n / 2 greatest cards in the first n / 2 rounds, so we can just play the current strongest
bessie card for every strongest card of elsie
*/
int main() {
    freopen("cardgame.in", "r", stdin);
	freopen("cardgame.out", "w", stdout);

    int n;
    cin >> n;

    vector<int> first_rule_elsie(n / 2);
    vector<int> second_rule_elsie(n / 2);
    vector<bool> used(n * 2, false);
    vector<int> bessie;
    for (auto &c: first_rule_elsie) {
        cin >> c;
        c--;
        used[c] = true;
    }
    for (auto &c: second_rule_elsie) {
        cin >> c;
        c--;
        used[c] = true;
    }
    sort(first_rule_elsie.begin(), first_rule_elsie.end(), greater<>());
    sort(second_rule_elsie.begin(), second_rule_elsie.end());

    for (int i = 0; i < n * 2; i++) {
        if (!used[i]) {
            bessie.push_back(i);
        }
    }

    int max_wins = 0;
    for (int i = 0; i < n / 2; i++) {
        auto least_greater = upper_bound(bessie.begin(), bessie.end(), first_rule_elsie[i]);
        if (least_greater != bessie.end()) {
            // pick last and erase
            auto it = bessie.end();
            --it;
            bessie.erase(it);
            max_wins++;
        } else {
            // dont do anything since we can just consider the first n / 2 of bessie later
        }
    }
    // now consider just the n / 2
    for (int i = n / 2 - 1; i >= 0; i--) {
        auto least_greater = upper_bound(second_rule_elsie.begin(), second_rule_elsie.end(), bessie[i]);
        if (least_greater != second_rule_elsie.end()) {
            // we have a greater so bessie can score
            second_rule_elsie.erase(least_greater);
            max_wins++;
        } else {
            // dont do anything since we can just consider the first n / 2 of bessie later
        }
    }
    cout << max_wins << endl;
}