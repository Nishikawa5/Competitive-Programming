#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        int tot = 0;
        cin >> n;

        vector<int> times(n);
        for (int i = 0; i < n; i++) {
            cin >> times[i];
            tot += times[i];
        }

        int minmod = n - 1;
        // lets assume the best time is k, where k is in the interval [0, sum(times)]
        for (int k = 0; k <= tot; k++) {
            if (k != 0 && tot % k != 0) {
                // not possible because is not a multiple
                continue;
            }

            int sum = 0;
            int totmod = 0;
            bool isPossible = true;
            for (int i = 0; i < n; i++) {
                // try to form sums that results in
                sum += times[i];
                if (sum > k) {
                    // cant be n
                    isPossible = false;
                    break;
                } else if (sum == k) {
                    // back to 0
                    sum = 0;
                } else {
                    // we merge 1 time
                    totmod++;
                }
            }
            if (sum == 0 && isPossible) {
                minmod = min(minmod, totmod);
            }
        }
        cout << minmod << endl;
    }
}