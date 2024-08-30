#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("taming.in", "r", stdin);
	freopen("taming.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> log(n);

    for (int i = 0; i < n; i++) {
        cin >> log[i];
    }
    if (log[0] > 0) {
        cout << -1 << endl;
        return 0;
    }
    log[0] = 0;

    int t = -1;
    int maxbreak = 0;
    int minbreak = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (log[i] == -1 && t == -1) {
            maxbreak++;
        } else if (log[i] != -1 && t == -1) {
            t = log[i];
        }
        
        if (t > -1) {
            // change/compare the time
            if (t > 0 && log[i] != -1 && log[i] != t) {
                cout << -1 << endl;
                return 0;
            }
            log[i] = t--;
        }
        if (log[i] == 0) {
            minbreak++;
        }
    }
    cout << minbreak << " " << maxbreak + minbreak << endl;
} 