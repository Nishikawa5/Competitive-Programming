#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<string> john_cows(n);
    vector<string> plain_cows(n);

    for (int i = 0; i < n; i++) {
        cin >> john_cows[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> plain_cows[i];
    }

    unordered_map<char, bool> count;
    int ans = 0;
    for (int j = 0; j < m; j++) {
        count['A'] = false;
        count['C'] = false;
        count['G'] = false;
        count['T'] = false;

        for (int i = 0; i < n; i++) {
            count[john_cows[i][j]] = true;
        }
        bool thisone = true;
        for (int i = 0; i < n; i++) {
            if (count[plain_cows[i][j]]) {
                thisone = false;
                break;
            }
        }
        if (thisone) {
            ans++;
        }
    }
    cout << ans << endl;
}