#include <bits/stdc++.h>
using namespace std;

// could have used lowerbound instead
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

    char last_char = goodstring[0];

    sort(goodstring.begin(), goodstring.end());

    int min_dist = 0;
    for (char c: name) {

        int first_greater = first_true(0, goodstring.size() - 1, [&](int idx) {
            return goodstring[idx] >= c;
        });

        if (first_greater == 0) {
            // no smaller char to the left
            min_dist += abs(goodstring[first_greater] - c);
        } else if (first_greater == goodstring.size()) {
            // no bigger char to the right
            min_dist += abs(goodstring[first_greater - 1] - c);
        } else {
            // check if the distances between left and right are equal
            if (abs(goodstring[first_greater] - c) == abs(goodstring[first_greater - 1] - c)) {
                // equal distances
                min_dist += min(abs(last_char - goodstring[first_greater]), 
                                abs(last_char - goodstring[first_greater - 1]));
            } else {
                // not equal, just add
                min_dist += min(abs(goodstring[first_greater] - c), 
                                abs(goodstring[first_greater - 1] - c));
            }
        }
        last_char = goodstring[first_greater];
    }
    cout << min_dist << endl;
}