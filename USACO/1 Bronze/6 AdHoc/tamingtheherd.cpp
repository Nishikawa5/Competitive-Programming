#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("taming.in", "r", stdin);
	freopen("taming.out", "w", stdout);

    int n;
    cin >> n;

    vector<int> breakouts(n);
    for (int i = 0; i < n; i++) {
        cin >> breakouts[i];
    }
    if (breakouts[0] > 0) {
        cout << -1 << endl;
        return 0;
    }
    breakouts[0] = 0;

    int maxbreak = 0;
    int minbreak = 0;
    int lastnew = 0;
    for (int i = 0; i < n; i++) {

        if (breakouts[i] > 0) {
            // impossible
            if (i - breakouts[i] < 0) {
                cout << -1 << endl;
                return 0;
            }

            if (breakouts[i - breakouts[i]] != 0) {
                maxbreak -= breakouts[i] - 1;
                minbreak++;
                breakouts[i - breakouts[i]] = 0;
            } else {
                maxbreak -= i - lastnew - 1;
            }
            lastnew = i;
        } else {
            if (breakouts[i] == 0) {
                minbreak++;
                lastnew = i;
            }
            maxbreak++;
        }
    }
    
    // lets check if is impossible
    int last0;
    for (int i = 0; i < n; i++) {
        if (breakouts[i] == 0) {
            last0 = i;
        } else if (breakouts[i] > 0) {
            // check if the distance agrees
            if (i - last0 != breakouts[i]) {
                // wrong!
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout << minbreak << " " << maxbreak << endl;
}