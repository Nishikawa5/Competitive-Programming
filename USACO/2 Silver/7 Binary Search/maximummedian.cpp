#include <bits/stdc++.h>
using namespace std;

/*
median will be at most [mid / 2 + 1]? no 
we will increase [mid / 2] >=
we have
(do we need <= k operations to make median = x?)
T, T, T, T, ..., T, F, ..., F
*/
int last_true(int lo, int hi, function<bool(int)> f) {
    lo--;
    while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;
        if (f(mid)) {
            // every number before mid is true 
            // and mid is f(mid) => last true is not before mid
            lo = mid;
        } else {
            // false 
            hi = mid - 1;
        }
    }
    return lo;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int &a: arr) {
        cin >> a;
    }

    sort(arr.begin(), arr.end());

    cout << last_true(1, 2e9, [&](int x) {
		// Returns true if the median can be raised to x
		long long ops_needed = 0;
		for (int i = (n - 1) / 2; i < n; i++) {
			ops_needed += max(0, x - arr[i]);
		}
		return ops_needed <= k;
    });

}