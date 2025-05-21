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
    int benches, came;
    cin >> benches >> came;

    vector<int> people(benches);
    int max_sitted = 0;
    for (auto &n: people) {
        cin >> n;
        max_sitted = max(max_sitted, n);
    }

    // the maximum: just add the people that came to the max
    int max_possible_k = max_sitted + came;

    // the minimum: assume a value -> keep adding until this value
    // try to fit the m people that came with benchs that have max capacity of some value

    // i think the problem allows to solve it with brute force too, since 100*10000 = 1e7
    int min_possible_k = first_true(2, 1e4 + 100, [&](int minimum_sitted) {
        if (minimum_sitted < max_sitted) return false;

        int possible_sit = 0;
        for (auto p: people) {
            possible_sit += max(0, minimum_sitted - p);
        }

        return possible_sit >= came;
    });

    cout << min_possible_k << " " << max_possible_k << endl;
}