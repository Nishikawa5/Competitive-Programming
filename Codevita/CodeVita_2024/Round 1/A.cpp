#include <bits/stdc++.h>
using namespace std;

/* AC */

// check if there is a sl in this block
int is_sl(int curr_block, vector<pair<int, int>> &sl) {
    for (auto &c: sl) {
        if (c.first == curr_block) {
            if (c.first > c.second) {
                // snake
                return c.second;
            } else {
                // ladder
                return c.second;
            }
        }
    }
    return curr_block;
}

void solve() {
    int n;
    cin >> n;

    // brute force
    vector<pair<int, int>> sl(n);
    for (auto &p: sl) {
        int a, b;
        scanf("%d %d", &a, &b);
        getchar();

        p.first = a;
        p.second = b;
    }

    vector<int> dices;
    int temp;
    scanf("%d", &temp);
    dices.push_back(temp);

    char garbage;
    while ((garbage = getchar()) != '\n' && garbage != '\r') {
        int dice;
        scanf("%d", &dice);

        dices.push_back(dice);
    }

    int goal;
    cin >> goal;

    for (int i = -1; i < n; i++) {
        if (i != -1) {
            // change
            swap(sl[i].first, sl[i].second);
        }

        int curr_block = 1;
        curr_block = is_sl(curr_block, sl);
        for (int j = 0; j < (int)dices.size(); j++) {

            curr_block += dices[j];
            curr_block = is_sl(curr_block, sl);
        }

        if (curr_block == goal) {
            if (i == -1) {
                cout << "Not affected\n";
                return;
            } else {
                if (sl[i].first < sl[i].second) {
                    // changed to a ladder
                    cout << "Ladder " << sl[i].first << " " << sl[i].second << "\n";
                } else {
                    // changed to a snake
                    cout << "Snake " << sl[i].first << " " << sl[i].second << "\n";
                }
                return;
            }
        }

        if (i != -1) {
            // change back
            swap(sl[i].first, sl[i].second);
        }
    }
    cout << "Not reachable\n";
}

int main() {
    int tc = 1;

    while (tc--) {
        solve();
    }
    return 0;
}
