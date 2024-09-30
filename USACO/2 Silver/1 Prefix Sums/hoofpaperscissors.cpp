#include <bits/stdc++.h>
using namespace std;

/*
be careful with                         
prefixes[j][i] = prefixes[j][i - 1] + (moves[i - 1] == possibilities[j]);

didn't need the suffix or to check every possibility
*/
int main() {
    freopen("hps.in", "r", stdin);
	freopen("hps.out", "w", stdout);

    int n;
    cin >> n;

    vector<char> moves(n);
    vector<char> possibilities = {'H', 'P', 'S'};
    vector<vector<int>> prefixes(3, vector<int>(n + 1, 0));
    vector<vector<int>> suffixes(3, vector<int>(n + 1, 0));

    // calculate prefix and suffix of every possibility then calculate
    for (char &c: moves) {
        cin >> c;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            prefixes[j][i] = prefixes[j][i - 1] + (moves[i - 1] == possibilities[j]);
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 3; j++) {
            suffixes[j][i] = suffixes[j][i + 1] + (moves[i] == possibilities[j]);
        }
    }

    int max_wins = 0;
    for (int i = 0; i <= n; i++) {
        for (int k = 0; k < 3; k++) {
            for (int j = 0; j < 3; j++) {
                max_wins = max(max_wins, prefixes[k][i] + suffixes[j][i]);
            }
        }
    }
    cout << max_wins << endl;
}