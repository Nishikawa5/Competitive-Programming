#include <bits/stdc++.h>
using namespace std;

void solve() {
    int class_num, teachers_num, queries;
    cin >> class_num >> teachers_num >> queries;

    // find the two closest teachers to david
    set<int> teachers;
    for (int i = 0; i < teachers_num; i++) {
        int t;
        cin >> t;
        teachers.insert(t);
    }

    for (int i = 0; i < queries; i++) {
        int david, t1, t2;
        cin >> david;

        auto it2 = teachers.upper_bound(david);
        auto it1 = prev(it2);

        if (it2 == teachers.begin()) {
            // no teachers to the left, so add 1 to the right
            t1 = *it2;
            t2 = class_num;
        } else if (it2 == teachers.end()) {
            // no teachers to the right, so add 1 to the left
            t1 = *it1;
            t2 = 1;
        } else {
            t1 = *it1;
            t2 = *it2;
        }

        // three cases
        int ans = 0;
        if (t1 < david && t2 < david) {
            // david goes to n and wait the teachers to get in there, so
            ans = min(class_num - t1, class_num - t2);
        } else if (t1 > david && t2 > david) {
            // now go to 1
            ans = min(t1 - 1, t2 - 1);
        } else {
            // david is between both teachers, so david will go to the middle of them
            int middle = (t1 + t2) / 2;
            ans = min(abs(t1 - middle), abs(t2 - middle));
        }

        cout << ans << endl;
    }
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
}