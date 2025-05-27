#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, c;
    cin >> n >> c;

    // only one '*', so we can brute force
    unordered_map<string, int> counting;
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;

        for (int j = 0; j < c; j++) {
            if (word[j] == '*') {
                for (char from = 'a', to = 'z'; from <= to; from++) {
                    word[j] = from;
                    counting[word]++;
                }
            }
        }
    }

    int num_best_word = 0;
    string best_word = "";
    for (auto &c: counting) {

        if (c.second > num_best_word) {
            num_best_word = c.second;
            best_word = c.first;
        } else if (c.second == num_best_word) {
            if (c.first < best_word) {
                best_word = c.first;
            }
        }
    }
    cout << best_word << " " << num_best_word << endl;
}




int main() {
    solve();
}