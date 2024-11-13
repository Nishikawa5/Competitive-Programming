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

    cout << goodstring << endl;

    int min_dist = 0;
    for (char c: name) {

        int first_greater = first_true(0, goodstring.size() - 1, [&](int idx) {
            return goodstring[idx] >= c;
        });

        if (first_greater == 0) {
            min_dist += abs(goodstring[first_greater] - c);
        } else if (first_greater == goodstring.size()) {
            min_dist += abs(goodstring[first_greater - 1] - c);
        } else {
            min_dist += min(abs(goodstring[first_greater] - c), abs(goodstring[first_greater - 1] - c));
        }
    }
    cout << min_dist << endl;
}