#include <bits/stdc++.h>
using namespace std;

/*
maximum sum is as small as possible
at most x
find the first
*/
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

int main() {
    int n, max_div;
    cin >> n >> max_div;

    vector<int> arr(n);
    for (int &x: arr) {
        cin >> x;
    }

    long long ans = first_true(0, 1e14 * 2, [&](long long at_most) {
        int subarrays = 1;
        long long current_sum = 0;
        for (int i = 0; i < n; i++) {
            current_sum += arr[i];
            if (current_sum > at_most) {
                current_sum = arr[i];
                subarrays++;
            }
            if (arr[i] > at_most) {
                return false;
            }
        }

        return subarrays <= max_div;
    });
    cout << ans << endl;
}