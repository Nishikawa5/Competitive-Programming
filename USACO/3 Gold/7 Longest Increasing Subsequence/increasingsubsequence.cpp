#include <bits/stdc++.h>
using namespace std;

int first_true(int hi, int lo, function<bool(int)> f) {
    hi++;

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;

        if (f(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto &a: arr) {
        cin >> a;
    }

    // can use multiset
    vector<int> lis;
    lis.push_back(arr[0]);
    for (int i = 1; i < n; i++) {
        if (arr[i] > lis.back()) {
            lis.push_back(arr[i]);
        } else {
            int first_greatest_idx = first_true(lis.size() - 1, 0, [&](int curr) {
                return arr[i] <= lis[curr];
            });
            lis[first_greatest_idx] = arr[i];
        }
    }

    cout << lis.size() << endl;
}