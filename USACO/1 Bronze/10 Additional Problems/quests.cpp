#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int quests, total_complete;
        cin >> quests >> total_complete;

        vector<int> first_complete(quests);
        vector<int> other_complete(quests);

        for (int i = 0; i < quests; i++) {
            cin >> first_complete[i];
        }
        for (int i = 0; i < quests; i++) {
            cin >> other_complete[i];
        }

        int max_exp = 0;
        int total_sum_first = 0;
        int max_other = 0;
        for (int completed = 1; completed <= quests && total_complete >= completed; completed++) {
            // assume we have completed the completed - 1 quest
            total_sum_first += first_complete[completed - 1];
            max_other = max(max_other, other_complete[completed - 1]);
            max_exp = max(max_exp, total_sum_first + max_other * (total_complete - completed));
        }
        cout << max_exp << endl;
    }
}