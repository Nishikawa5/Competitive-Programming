#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int char_num, colors;
        cin >> char_num >> colors;

        vector<int> count(26, 0);
        char curr_char;
        while (char_num--) {
            cin >> curr_char;
            count[curr_char - 'a']++;
        }
        int pairs = 0;
        int not_pairs = 0;
        for (int i = 0; i < 26; i++) {
            pairs += count[i] / 2;
            not_pairs += count[i] & 1;
        }

        // fill the pairs
        int filled = pairs / colors;
        int total = filled * 2;
        not_pairs += (pairs - filled * colors) * 2;

        if (not_pairs >= colors) {
            total++;
        }
        cout << total << endl;
    }
}