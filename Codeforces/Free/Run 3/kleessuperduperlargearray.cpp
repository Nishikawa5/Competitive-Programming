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

long long sum(long long from, long long to) {
    return (from + to) * (to - from + 1) / 2;
}

void solve() {
    int n, k;
    cin >> n >> k;

    // find first that makes this difference positive
    long long left_ptr = k;
    long long right_ptr = k + n - 1;

    // find the first true s.t. sum of left >= sum of right
    long long first_greater = first_true(k, k + n - 1, [&](long long curr_middle) {
        return sum(k, curr_middle) >= sum(curr_middle + 1, k + n - 1);
    });

    // get the smallest difference
    long long positive_difference = sum(k, first_greater) - sum(first_greater + 1, k + n - 1);
    long long negative_difference = sum(first_greater, k + n - 1) - sum(k, first_greater - 1);

    cout << min(positive_difference, negative_difference) << endl;
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
}