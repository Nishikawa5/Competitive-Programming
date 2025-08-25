#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define dir int
#define RIGHT 1
#define LEFT 0

void solve() {
    int tflight, period;
    cin >> tflight >> period;

    vector<ll> pos(tflight);
    vector<ll> delay(tflight);
    for (auto &p: pos) {
        cin >> p;
    }
    for (auto &d: delay) {
        cin >> d;
    }

    map<ll, ll> positions;
    for (int i = 0; i < tflight; i++) {
        positions[pos[i]] = delay[i];
    }
    pos.push_back(0);
    pos.push_back(1e15+1);
    sort(pos.begin(), pos.end());


    int queries;
    cin >> queries;

    while (queries--) {
        // if the same trafficlight is visited 2 times with same dir, not possible
        // since every tl has the same period
        map<pair<ll, dir>, bool> is_visited;

        dir curr_dir = RIGHT;
        ll curr_pos;
        ll curr_time = 0;
        cin >> curr_pos;

        //cout << curr_pos << endl << endl;
        while (true) {
            //cout << curr_pos << " " << curr_dir << " " << curr_time << endl;

            if (curr_dir == RIGHT) {
                // get next tl to the right
                auto it = lower_bound(pos.begin(), pos.end(), curr_pos);

                if (*it == 0 || *it == 1e15+1) {
                    // passed
                    cout << "YES\n";
                    break;
                }

                curr_time += *it - curr_pos;
                curr_pos = *it;
                
                if ((curr_time - positions[*it]) % period) {
                    // green light
                    curr_time++;
                    curr_pos++;
                } else {
                    pair<ll, dir> state = {curr_pos, curr_dir};
                    if (is_visited[state]) {
                        cout << "NO\n";
                        break;
                    }
                    is_visited[state] = true;

                    curr_time += 1;
                    curr_pos--;
                    curr_dir = LEFT;
                }
            } else {
                // get next tl to the left
                auto it = upper_bound(pos.begin(), pos.end(), curr_pos);
                it--;
                if (*it == 0 || *it == 1e15+1) {
                    // passed
                    cout << "YES\n";
                    break;
                }

                curr_time += curr_pos - *it;
                curr_pos = *it;
                
                if ((curr_time - positions[*it]) % period) {
                    // green light
                    curr_time++;
                    curr_pos--;
                } else {
                    pair<ll, dir> state = {curr_pos, curr_dir};
                    if (is_visited[state]) {
                        cout << "NO\n";
                        break;
                    }
                    is_visited[state] = true;

                    curr_time += 1;
                    curr_pos++;
                    curr_dir = RIGHT;
                }       
            }

        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
    return 0;
}
