#include <bits/stdc++.h>
using namespace std;

bool check_state(vector<int> &bulb_state) {
    for (auto &b: bulb_state) {
        if (b == 1) {
            return false;
        }
    }
    return true;
}


void solve() {

    // try to activate it 2 times
    // cycles of 2N
    // just simulate it?
    // can do it with xor and bitset to make it faster
    int switches_num, bulbs_num;
    cin >> switches_num >> bulbs_num;

    vector<int> bulb_state(bulbs_num, 0);
    
    int initial;
    cin >> initial;
    while (initial--) {
        int a;
        cin >> a;
        bulb_state[a-1] = 1;
    }

    vector<vector<int>> switch_bulb(switches_num);

    for (int i = 0; i < switches_num; i++) {
        int num;
        cin >> num;

        while (num--) {
            int conn;
            cin >> conn;

            switch_bulb[i].push_back(conn-1);
        }
    }


    for (int times = 0; times < 2; times++) {
        // simulate 2 times
        for (int i = 0; i < switches_num; i++) {
            for (auto conn: switch_bulb[i]) {
                bulb_state[conn] = (bulb_state[conn]==1 ? 0:1);
            }

            if (check_state(bulb_state)) {
                cout << (i+1 + times * switches_num) % (2*switches_num) << endl;
                return;
            }
        }
    }

    cout << -1 << endl;
}

int main() {
    solve();
}