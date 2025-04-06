#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll reachable(pair<ll, pair<ll, ll>> a, pair<ll, pair<ll, ll>> b) {
    // sqrt(dx ** 2 + dy ** 2) = dist = t2 - t1
    // => dx**2 + d**2 <= (t2-t1)**2 is reachable 
    ll distance = (a.second.first - b.second.first) * (a.second.first - b.second.first) + (a.second.second - b.second.second) * (a.second.second - b.second.second);
    ll can_travel = (a.first - b.first) * (a.first - b.first);  

    return distance <= can_travel;
}

int main() {
    // always possible for a cow to go to all
    // grazings everytime =>
    // for t1 >= t2 >= t3, we can reach 1 and 3 from 2
    // => we just need to check if the cow can reach one grazing
    int grazings_num, n;
    cin >> grazings_num >> n;

    vector<pair<ll, pair<ll, ll>>> grazings(grazings_num);
    vector<pair<ll, pair<ll, ll>>> cows(n);

    for (auto &g: grazings) {
        cin >> g.second.first >> g.second.second >> g.first;
    }

    for (auto &c: cows) {
        cin >> c.second.first >> c.second.second >> c.first;
    }

    sort(grazings.begin(), grazings.end());

    int proved = 0;
    int i = 0;
    for (auto &c: cows) {
        // can this cow reach a grazing?
        auto it = lower_bound(grazings.begin(), grazings.end(), c);

        bool is_innocent = false;
        if (it != grazings.end()) {
            is_innocent = is_innocent || !reachable(c, *it);
        }

        if (it != grazings.begin()) {
            is_innocent = is_innocent || !reachable(c, *prev(it));
        }
        proved += is_innocent;
    }
    cout << proved << endl;
}