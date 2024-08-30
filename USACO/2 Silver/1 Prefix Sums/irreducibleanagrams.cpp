#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n;
    cin >> n;

    // store the prefixes of every lowercase letter
    vector<vector<int>> char_prefix(s.size() + 1, vector<int>(26));
    for (int i = 0; i < 26; i++) {
        char_prefix[0][i] = 0;
    }

    for (int i = 0; i < s.size(); i++) {
        for (int k = 0; k < 26; k++) {
            char_prefix[i + 1][k] = char_prefix[i][k]; 
        }
        char_prefix[i + 1][s[i] - 'a']++;
    }

    // process the queries
    while (n--) {
        int l, r;
        cin >> l >> r;

        int different_char = 0;
        for (int i = 0; i < 26; i++) {
            // check if there are 3 different characters in this subset
            if (char_prefix[r][i] > char_prefix[l - 1][i]) {
                different_char++;
            }
        }

        if (s[l - 1] != s[r - 1] || different_char >= 3 || l == r) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}