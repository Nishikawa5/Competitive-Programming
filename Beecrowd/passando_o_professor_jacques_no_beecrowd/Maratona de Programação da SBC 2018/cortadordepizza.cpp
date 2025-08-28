#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// ordered datastructure which we can find the
// rank of some number
// e.g. [20, 30, 40, 50, 60], so
// s.order_of_key(40) == 2
// s.order_of_key(45) == 3
typedef tree<
    int,
    null_type,
    greater<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
statisticsTree;


void solve() {
    int x, y;
    cin >> x >> y;


    int hor_num, ver_num;
    cin >> hor_num >> ver_num;

    vector<pair<int, int>> horizontal_cuts(hor_num);
    vector<pair<int, int>> vertical_cuts(ver_num);
    for (auto &h: horizontal_cuts) {
        cin >> h.first >> h.second;
    }
    for (auto &v: vertical_cuts) {
        cin >> v.first >> v.second;
    }

    auto get_intersections = [&](vector<pair<int, int>> &cuts) {
        sort(cuts.begin(), cuts.end());
        statisticsTree ord;

        long long ans = 0;
        for (int i = 0; i < cuts.size(); i++) {
            // get the order of opposite side
            ans += ord.order_of_key(cuts[i].second);
            ord.insert(cuts[i].second);
        }
        return ans;
    };

    long long total_intersections = 1LL * (hor_num + 1) * (ver_num + 1);
    total_intersections += get_intersections(horizontal_cuts);
    total_intersections += get_intersections(vertical_cuts);
    cout << total_intersections << endl;
}


int main() {
    solve();
}