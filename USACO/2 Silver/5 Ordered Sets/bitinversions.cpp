#include <bits/stdc++.h>
using namespace std;

int main() {
    string bitstr;
    cin >> bitstr;

    set<int> diff;
    diff.insert(0);
    diff.insert(bitstr.size());
    multiset<int> intervals;

    for (int i = 1; i < bitstr.size(); i++) {
        if (bitstr[i] != bitstr[i - 1]) {
            diff.insert(i);
        }
    }

    auto last = diff.begin();
    for (auto it = next(diff.begin(), 1); it != diff.end(); it++) {
        intervals.insert(*it - *last);
        last = it;
    }

    int queries;
    cin >> queries;

    while (queries--) {
        int change;
        cin >> change;
        change--;

        // get the locations of changed interval
        auto right = diff.lower_bound(change);
        auto left = prev(diff.lower_bound(change));
        
        // erase the interval
        intervals.erase(intervals.find(*right - *left));

        // erase the lowerbound, go right and calculate again
        if (change + 1 != bitstr.size() && *right == change && *next(right) == change + 1) {
            // erase both right and right + 1
            diff.erase(next(right));
            diff.insert(change + 2);
            diff.erase(right);

            // insert this new interval
            auto t = diff.lower_bound(change + 2);
            intervals.insert(*t - *prev(t));
        } else {
            diff.erase(right);
        }

        // add the new intervals
        right = diff.lower_bound(change);
        left = prev(right);

        intervals.insert(*right - *left);

        auto it_max = intervals.end();
        --it_max;
        cout << *it_max << " ";
    }
    cout << "\n";
}