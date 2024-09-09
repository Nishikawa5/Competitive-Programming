#include <bits/stdc++.h>
using namespace std;

void solve(string &word) {
    int total_changes;
    char fav_letter;
    cin >> total_changes;
    getchar();
    cin >> fav_letter;
    getchar();

    int changes = 0;
    int max_favorite = 0;
    for (int l = 0, r = 0; r < word.size(); r++) {
        if (word[r] != fav_letter) {
            changes++;
        }

        while (changes > total_changes) {
            if (word[l++] != fav_letter) {
                changes--;
            }
        }

        max_favorite = max(max_favorite, r - l + 1);
    }
    cout << max_favorite << endl;
}

int main() {
    int queries;
    int n;
    string word;
    cin >> n >> word;
    cin >> queries;

    while (queries--) {
        solve(word);
    }
}