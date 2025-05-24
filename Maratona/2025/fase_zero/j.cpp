#include <bits/stdc++.h>
using namespace std;

#define ll long long

// TLE

void solve() {
    int filters_num;
    int k;

    cin >> filters_num >> k;

    vector<int> filters(filters_num);
    for (auto &f: filters) {
        cin >> f;
    }

    // start at i=1
    // cant we simulate?
    // i dont think so O(n**2)
    // every cycle it increases k*(filters_num)
    // it is guaranteed that after 1 cycle the particle is gone
    // can we sort and store position?
    
    for (int i = 0; i < filters_num; i++) {

        ll curr_sum = filters[i];

        for (int j = i + 1; j <= filters_num + i; j++) {
            curr_sum += k;

            if (curr_sum > filters[j % filters_num]) {
                cout << (j%filters_num) + 1 << " ";
                break;
            }
        }

    }
    cout << endl;
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
