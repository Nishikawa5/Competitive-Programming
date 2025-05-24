#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll find_lowest_insertion(ll curr_x, set<ll> &factors) {
    ll min_insertions = INT_MAX;
    ll lowest_factor = -1;

    for (auto &f: factors) {
        ll multiple = gcd(curr_x, f);
        ll insertions = f/multiple - 1;

        if (min_insertions >= insertions) {
            min_insertions = insertions;
            lowest_factor = f;
        }
    }

    factors.erase(lowest_factor);

    return lowest_factor;
}

void solve() {
    ll y, k;
    cin >> y >> k;

    ll pos = 1;
    // 1, 1, 1, 1, ...
    // x1, x1, x1, ...
    // x2, ...
    // 1, 2, 4, 8

    set<ll> factors;
    int sqrty = sqrt(y);
    for (int i = 1; i <= sqrty; i++) {
        if (y % i == 0) {
            factors.insert(i);
            factors.insert(y/i);
        }
    }

    ll curr_x = 1;
    ll last_factor = 1;//find_lowest_insertion(curr_x, factors);
    ll curr_k = 0;

    for (int i = 0, f = factors.size(); i < f; i++) {
        // insert that xi - 1 times
        // or insert that xi / factors times?
        // what if we have a gcd that has a lower thing
        ll factor = find_lowest_insertion(curr_x, factors);


        ll multiple = gcd(curr_x, factor);
        ll insertions = factor/multiple - 1;

        if (curr_k + insertions <= k) {
            curr_x = curr_x + (last_factor)*(insertions);
            last_factor = max(factor, last_factor);
            curr_k += insertions;
        }


        if (curr_k > k) {
            break;
        }
    }

    curr_x += (k-curr_k)*last_factor;

    cout << curr_x << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 1;

    while (tc--) {
        solve();
    }
    return 0;
}
