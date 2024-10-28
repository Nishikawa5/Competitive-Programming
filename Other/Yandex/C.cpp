#include <bits/stdc++.h>
using namespace std;


/*
get the max width

minimize the difference of Ls and Rs

*/
void solve() {
    string dance;
    cin >> dance;

    // go max left or max right
    pair<int, int> go_left = {0, 0};
    int left_curr_place = 0;
    pair<int, int> go_right = {0, 0};
    int right_curr_place = 0;

    for (int i = 0; i < dance.size(); i++) {
        if (dance[i] == 'L') {
            left_curr_place--;
            right_curr_place--;

            go_left.first = min(go_left.first, left_curr_place);
            go_right.first = min(go_right.first, right_curr_place);
        } else if (dance[i] == 'R') {
            left_curr_place++;
            right_curr_place++;

            go_left.second = max(go_left.second, left_curr_place);
            go_right.second = max(go_right.second, right_curr_place);
        } else {
            left_curr_place--;
            right_curr_place++;

            go_left.first = min(go_left.first, left_curr_place);
            go_right.second = max(go_right.second, right_curr_place);
        }
    }
    cout << max((go_left.second - go_left.first), (go_right.second - go_right.first)) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc = 1;

    while (tc--) {
        solve();
    }
    return 0;
}