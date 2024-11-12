#include <bits/stdc++.h>
using namespace std;

int first_true(int lo, int hi, function<bool(int)> f) {
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
    string goodstring, name;
    cin >> goodstring >> name;

    sort(goodstring.begin(), goodstring.end());

    int min_dist = 0;
    for (char c: name) {

        first_true(0, goodstring.size() - 1, [&](int idx) {
            return goodstring[idx] <= c;
        });
    }
}