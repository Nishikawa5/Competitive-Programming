#include <bits/stdc++.h>
using namespace std;

/*
Using next_permutation builtin function is much faster to write. 
We also could use unordered_map<string, int> to make comparisons faster 
*/

int getcowindex(vector<string> currorder, string cow) {
    for (int i = 0; i < currorder.size(); i++) {
        if (currorder[i] == cow) return i;
    }
    return -1;
}

// checks if the order is satisfied
bool satisfy(vector<string> currorder, vector<pair<string, string>> order) {
    for (int i = 0; i < order.size(); i++) {
        int cow1 = getcowindex(currorder, order[i].first);
        int cow2 = getcowindex(currorder, order[i].second);

        if (cow1 == -1 || cow2 == -1) {
            return false;
        }
        if (abs(cow1 - cow2) != 1) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);

    vector<string> cownames{"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
    sort(cownames.begin(), cownames.end());

    int n;
    cin >> n;
    vector<pair<string, string>> order(n);
    for (int i = 0; i < n; i++) {
        string dummy;
        cin >> order[i].first >> dummy >> dummy >> dummy >> dummy >> order[i].second;
    }

    while (next_permutation(cownames.begin(), cownames.end())) {
        if (satisfy(cownames, order)) {
            for (int i = 0; i < cownames.size(); i++) {
                cout << cownames[i] << endl;
            }
            return 0;
        }
    }
}