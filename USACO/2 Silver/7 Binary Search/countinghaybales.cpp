#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<
    pair<int, int>,
    null_type,
    less<pair<int, int>>,
    rb_tree_tag,
    tree_order_statistics_node_update>
statisticsTree;


int main() {
    freopen("haybales.in", "r", stdin);
	freopen("haybales.out", "w", stdout);

    int n, q;
    cin >> n >> q;

    statisticsTree ord;
    for (int i = 0; i < n; i++) {
        int pos;
        cin >> pos;
        ord.insert({pos, i});
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << ord.order_of_key({r, INT_MAX}) - ord.order_of_key({l, -1}) << endl;
    }
}