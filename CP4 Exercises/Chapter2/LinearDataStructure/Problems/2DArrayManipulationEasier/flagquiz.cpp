#include <bits/stdc++.h>
using namespace std;

string constructStr(bool *last) {
    char c;
    string rst;
    while ((c = getchar()) && c != '\n') {
        if (c == ',') {
            getchar();
            return rst;
        }
        rst.push_back(c);
    }
    *last = true;
    return rst;
}

int main() {
    string dummy;
    getline(cin, dummy);

    int n;
    bool *last = (bool*) malloc(sizeof(bool));
    cin >> n;
    getchar();
    vector<vector<string>> flags(n);
    for (int i = 0; i < n; i++) {
        *last = false;
        while (!(*last)) {
            flags[i].push_back(constructStr(last));
        }
    }

    int min_changes = INT_MAX;
    vector<int> changes(n);
    for (int i = 0; i < n; i++) {
        int max_curr_changes = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            int curr_changes = 0;
            for (int k = 0; k < flags[0].size(); k++) {
                curr_changes += flags[i][k] != flags[j][k];
            }
            max_curr_changes = max(max_curr_changes, curr_changes);
        }
        changes[i] = max_curr_changes;
        min_changes = min(min_changes, max_curr_changes);
    }

    for (int i = 0; i < n; i++) {
        if (changes[i] == min_changes) {
            cout << flags[i][0];
            for (int k = 1; k < flags[i].size(); k++) {
                cout << ", " << flags[i][k];
            }
            cout << endl;
        }
    }
}