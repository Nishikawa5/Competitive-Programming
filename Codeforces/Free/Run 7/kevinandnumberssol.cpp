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

    // cant decrease
    while (!desired.empty() && !initial.empty()) {
        // generate the 2 values for each desired num
        // n, n     for even
        // n, n + 1 for odd
        // go from greatest to smallest
        // terminate if smallest desired is smaller than initial
        int split = *desired.rbegin();
        desired.erase(prev(desired.end()));

        int greatest = *initial.rbegin();

        if (greatest == split) {
            // no need to split, so just erase it
            initial.erase(prev(initial.end()));
        } else {
            desired.insert(split / 2);
            desired.insert(split / 2 + split % 2);
        }
        
        if (*desired.begin() < *initial.begin() || desired.size() > initial.size()) {
            cout << "No\n";
            return;
        }
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