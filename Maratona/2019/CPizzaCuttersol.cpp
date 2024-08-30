#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

/*
Count the number of interceptions
T(1) = 2
T(n) = T(n - 1) + interceptions + 1
interceptions + 1

every l->r will intercept with every u->d
see if it's possible to intercept l->r before the limit

*/

typedef tree<
    int,
    null_type,
    greater<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
statisticsTree;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    int h, v;
    cin >> h >> h >> h >> v;

    vector<pair<int, int>> hor(h), ver(v);
    for (auto &p: hor) {
        cin >> p.first >> p.second;
    }
    for (auto &p: ver) {
        cin >> p.first >> p.second;
    }

    // careful with product overflow
    long long max_slices = 1LL * (h + 1) * (v + 1);
    auto f = [&](vector<pair<int, int>> lines) {
        sort(lines.begin(), lines.end());
        statisticsTree ord;
        for (auto &p: lines) {
            max_slices += ord.order_of_key(p.second);
            ord.insert(p.second);
        }
        return;
    };
    f(hor);
    f(ver);
    cout << max_slices << endl;

}