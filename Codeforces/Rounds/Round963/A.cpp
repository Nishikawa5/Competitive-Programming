#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;
        string answers;
        cin >> answers;
        int max_score = 0;

        vector<int> count_ans(4, 0);
        for (int i = 0; i < answers.size(); i++) {
            if (answers[i] != '?') {
                count_ans[answers[i] - 'A']++;
            }
        }
        for (int i = 0; i < 4; i++) {
            max_score += min(n, count_ans[i]);
        }
        cout << max_score << endl;
    }
}