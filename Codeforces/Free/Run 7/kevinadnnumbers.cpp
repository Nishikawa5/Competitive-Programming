#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    multiset<int> initial;
    multiset<int> desired;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        initial.insert(temp);
    }
    for (int i = 0; i < m; i++) {
        int temp;
        cin >> temp;

        desired.insert(temp);
    }

    // eraseable iff adjacent
    // cant decrease
    while (initial != desired && initial.size() >= 2 && !desired.empty()) {
        // keep adding until we get the desired thing
        int get = *(desired.begin());
        desired.erase(desired.begin());

        while (initial.size() >= 2 && get != *(initial.begin())) {
            // keep adding until we get the desired val
            // cant keep adding, since there are 2 possibilities
            // 0 and 1
            int first = *(initial.begin());
            initial.erase(initial.begin());
            int second = *(initial.begin());
            initial.erase(initial.begin());

            if (abs(first - second) <= 1) {
                initial.insert(first + second);
            } else {
                cout << "No\n";
                return;
            }
        }
        if (get != *(initial.begin())) {
            cout << "No\n";
            return; 
        }
        initial.erase(initial.begin());
    }
    if (initial == desired) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}


int main(void) {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
}