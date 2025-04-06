#include <bits/stdc++.h>
using namespace std;

long long distance(pair<int, int> a, pair<int, int> b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main() {
    // always possible for a cow to go to all
    // grazings everytime =>
    // for t1 >= t2 >= t3, we can reach 1 and 3 from 2
    // => we just need to check if the cow can reach one grazing
    int grazings_num, n;
    cin >> grazings_num >> n;

    vector<pair<int, pair<int, int>>> grazings(grazings_num);
    vector<pair<int, pair<int, int>>> cows(n);

    for (auto &g: grazings) {
        cin >> g.second.first >> g.second.second >> g.first;
    }

    for (auto &c: cows) {
        cin >> c.second.first >> c.second.second >> c.first;
    }

    sort(grazings.begin(), grazings.end());

    int proved = 0;
    for (auto &c: cows) {
        // can this cow reach a grazing?
        auto it = lower_bound(grazings.begin(), grazings.end(), c);

        if (it != grazings.end()) {
            if (distance((*it).second, c.second) <= 
                (c.first - (*it).first) * (c.first - (*it).first)) {
                
                continue;
            }
        }

        if (it != grazings.begin()) {
            it--;
            if (distance((*it).second, c.second) <= 
                (c.first - (*it).first) * (c.first - (*it).first)) {
            
            continue;
        }
        }

        proved++;
    }
    cout << proved << endl;
}