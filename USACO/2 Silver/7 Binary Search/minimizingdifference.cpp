#include <bits/stdc++.h>
using namespace std;

#define ll long long
/*
diff <=
F F T T T T ...
*/
ll first_true(ll lo, ll hi, function<bool(ll)> f) {
    hi++;

    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;

        if (f(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

int main() {
    ll n, k;
    cin >> n >> k;

    vector<ll> arr(n);
    vector<ll> prefix(n + 1);
    for (auto &e: arr) {
        cin >> e;
    }

    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + arr[i];
    }

    ll ans = first_true(0, 1e9, [&](ll curr_diff) {
        // pick a number that is the closest to be max/min
        // and calculate if is possible
        for (int i = 0; i < n; i++) {
            // range [arr[i], arr[i] + curr_diff]
            ll max_num = arr[i] + curr_diff;
            ll right = upper_bound(arr.begin(), arr.end(), max_num) - arr.begin();
            // 0 to i - 1 add the difference
            // right to n just add the accumulative sum
            ll ops = (prefix[n] - prefix[right]) - (n - right) * max_num;
            ops += i * arr[i] - prefix[i];
            if (ops <= k) return true;

            // range [arr[i] - curr_diff, arr[i]]
            ll min_num = arr[i] - curr_diff;
            ll left = lower_bound(arr.begin(), arr.end(), min_num) - arr.begin();
            // 0 to left - 1 add the difference
            // i to n        just add the accumulative sum 
            ops = left * min_num - prefix[left];
            ops += (prefix[n] - prefix[i + 1]) - (n - (i + 1)) * arr[i];
            if (ops <= k) return true;
        }
        return false;
    });
    cout << ans << endl;
}