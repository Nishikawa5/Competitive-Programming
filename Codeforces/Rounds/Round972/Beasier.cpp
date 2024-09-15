#include <bits/stdc++.h>
using namespace std;

void solve() {
    int class_num, teachers_num, queries;
    cin >> class_num >> teachers_num >> queries;


    // david move then teacher move
    // teacher always moves to the student, david always move away
    // so david try to move in a direction that is away from the closest teacher

    int t1, t2, david;
    cin >> t1 >> t2 >> david;

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

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
}