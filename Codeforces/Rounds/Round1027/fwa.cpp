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

    int sqrtx = sqrt(need);
    int sqrty = sqrt(erase);
    for (int i = 2; i <= sqrtx; i++) {
        if (!(need % i)) {
            factors_x.insert(i);
            factors_x.insert(need/i);
        }
    }
    for (int i = 2; i <= sqrty; i++) {
        if (!(erase % i)) {
            factors_y.insert(i);
            factors_y.insert(erase/i);
        }
    }
    if (need != 1) {
        factors_x.insert(need);
    }
    if (erase != 1) {
        factors_y.insert(erase);
    }


    int ans = 0;
    for (auto i = factors_x.rbegin(); i != factors_x.rend(); i++) {
        int curr_factor = *i;
        while (curr_factor <= interval && (need % curr_factor) == 0) {
            need /= curr_factor;
            ans++;
        }
    }

    for (auto i = factors_y.rbegin(); i != factors_y.rend(); i++) {
        int curr_factor = *i;
        while (curr_factor <= interval && (erase % curr_factor) == 0) {
            erase /= curr_factor;
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
