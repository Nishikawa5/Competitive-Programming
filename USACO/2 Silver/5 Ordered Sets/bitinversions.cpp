#include <bits/stdc++.h>
using namespace std;

void modify(int x, set<int> &diff, multiset<int> &intervals, int max_size) {
    if (x == 0 || x == max_size) {
        return;
    }

    auto it = diff.find(x);

    if (it != diff.end()) {
        // it is in diff, think about 1001001, where x is the middle index
        auto left_ptr = prev(it);
        auto right_ptr = next(it);

        intervals.erase(intervals.find(*right_ptr - *it));
        intervals.erase(intervals.find(*it - *left_ptr));

        intervals.insert(*right_ptr - *left_ptr);
        diff.erase(it);
    } else {
        // insert it, since x is now different, think about 0000000, where x is the middle index
        it = diff.insert(x).first;

        int a = *prev(it);
        int b = *next(it);
        intervals.erase(intervals.find(b - a));
        intervals.insert(*it - a);
        intervals.insert(b - *it);
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

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

    for (auto it = diff.begin(); next(it) != diff.end(); it++) {
        intervals.insert(*next(it) - *it);
    }

    int queries;
    cin >> queries;

    while (queries--) {
        int change;
        cin >> change;
        change--;

        /*
        two cases:
        with the first change we also have to add the next 
            example: 000000000 -> 000010000 => add mid index and add index mid + 1
        with the first change we have to erase the next
            example: 101 -> 111 => erase mid and erase next
        */

        // idx change
        modify(change, diff, intervals, bitstr.size());
        // consequently, the next idx will also change
        modify(change + 1, diff, intervals, bitstr.size());

        cout << *intervals.rbegin() << " ";
    }
    cout << "\n";
}