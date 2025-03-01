#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("snowboots.in", "r", stdin);
	freopen("snowboots.out", "w", stdout);

    int tiles, boots_num;
    cin >> tiles >> boots_num;

    set<pair<int, int>> depth;
    for (int i = 0; i < tiles; i++) {
        int curr_depth;
        cin >> curr_depth;
        depth.insert({curr_depth, i});
    }

    int idx = 0;
    vector<pair<pair<int, int>, int>> boots(boots_num);
    for (auto &b: boots) {
        cin >> b.first.first >> b.first.second;
        b.second = idx++;
    }

    sort(boots.begin(), boots.end(), greater<pair<pair<int, int>, int>>());

    set<int> available_tiles;
    for (int i = 0; i <= tiles; i++) {
        available_tiles.insert(i);
    }

    vector<bool> is_possible(boots_num);
    int max_step = 1;
    for (auto &b: boots) {
        // erase every not achievable
        while (true) {
            auto removed = depth.upper_bound({b.first.first, INT_MAX});

            if (removed == depth.end()) {
                // no more greater steps
                break;
            }

            int removed_idx = (*removed).second;
            auto rmv = available_tiles.find(removed_idx);
            max_step = max(max_step, *next(rmv) - *prev(rmv));


            // erase
            depth.erase(removed);
            available_tiles.erase(rmv);
        }
        is_possible[b.second] = (max_step <= b.first.second); 
    }

    for (auto p: is_possible) {
        cout << p << endl;
    }
}
