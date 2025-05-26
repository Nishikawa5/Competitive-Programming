#include <bits/stdc++.h>
using namespace std;

void solve() {
    int start, interval, target;
    cin >> start >> target >> interval;

    // get every factor of x and y
    // try to make them equal by multiplying and dividing?
    // we may have a combination of primes, so we get the factors?

    set<int> factors_x;
    set<int> factors_y;
    

    // we need
    int multiple = gcd(start, target);
    int need = target/multiple;
    int erase = start/multiple;

    int ans = 0;

    for (int i = min((int)need, interval); i >= 2; i--) {
        while (i <= interval && (need % i) == 0) {
            need /= i;
            ans++;
        }
    }

    for (int i = min((int)erase, interval); i >= 2; i--) {
        while (i <= interval && (erase % i) == 0) {
            erase /= i;
            ans++;
        }
    }

    if (need == 1 && erase == 1) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
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
