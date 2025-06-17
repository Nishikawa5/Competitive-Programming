#include <bits/stdc++.h>
using namespace std;


/*
we cant simply sort and put the balls from left to right
since we may have a situation like
1 1
1 3
1 4
1 5
2 2
we fill 1-4 and cant put 2 2, but we need to
put 2 2 in 2, which would be possible if we change
the way we are putting
*/

void solve() {
    int balls_num;
    cin >> balls_num;

    vector<pair<int, int>> interval(balls_num);
    set<int> from;
    map<int, vector<int>> from_to; 
    
    for (auto &p: interval) {
        cin >> p.first >> p.second;
        from.insert(p.first);
        from_to[p.first].push_back(p.second);
    }

    int i = *from.lower_bound(1);
    // we get the next later
    auto next_i = from.lower_bound(1); 

    priority_queue<int> pq;
    while (i <= 1e9) {
        if (next_i != from.end() && *next_i <= i) {
            for (auto r: from_to[*next_i]) {
                pq.push(-r);
            }

            next_i = from.lower_bound(*next_i + 1);
        }

        if (pq.empty()) {

            if (next_i == from.end()) {
                // no more balls to place,
                // so it is possible
                cout << "YES\n";
                return;
            } else {
                i = *next_i;
            }
            // dont update it here, since we have
            // to put this next_i balls in pq
            //next_i = from.lower_bound(*next_i + 1);
        } else {
            int best = -pq.top();
            pq.pop();
            if (i <= best) {
                i++;
            } else {
                // cant put the ball
                cout << "NO\n";
                return;
            }
        }
    }
    // we may have the case where the last
    // ball was placed at 1e9, so we need to
    // check if it is empty
    if (pq.empty()) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    };
}