#include <bits/stdc++.h>
using namespace std;

long long first_true(long long lo, long long hi, function<bool(long long)> f) {
    hi++;

    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2;

        if (f(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

void solve() {
    long long bulbs_num;
    cin >> bulbs_num;

    // flip all bulbs j divisible by i
    // even divisors => on, odd divisors => off
    // o e e o e e e e o e e e e e e o e 
    // it seems like every idx that is a perfect square is off
    /*
    Proof:
        We can make n pairs (x, y) s.t. x * y = n...

    So we can just get the first perfect square k s.t. n - k = bulbs_num 
    */

    cout << first_true(1, LONG_LONG_MAX - 1, [&](long long curr_bulbs) {
        return curr_bulbs - int(sqrtl(curr_bulbs)) >= bulbs_num;
    }) << endl;
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
}