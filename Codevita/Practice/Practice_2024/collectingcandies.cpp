#include <bits/stdc++.h>
using namespace std;

// 3 + 6 + 9 + 15
void solve() {
    int candies_num;
    cin >> candies_num;

    priority_queue<int> box_times;
    for (int i = 0; i < candies_num; i++) {
        int candy;
        cin >> candy;

        box_times.push(-candy);
    }

    int min_time = 0;
    while (box_times.size() > 1) {
        int smallest_time = box_times.top();
        box_times.pop();
        int second_smallest_time = box_times.top();
        box_times.pop();

        int this_move_time = -(smallest_time + second_smallest_time);
        box_times.push(-this_move_time);
        min_time += this_move_time;
    }
    cout << min_time << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
    return 0;
}
