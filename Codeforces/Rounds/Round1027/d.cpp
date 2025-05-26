#include <bits/stdc++.h>
using namespace std;

long long calculate_area(int l, int r, int u, int d, int num_monsters) {
    int side1 = (r-l+1);
    int side2 = (u-d+1);

    if (side1*side2 == num_monsters-1) {
        if (side1 < side2) {
            side2++;
        } else {
            side1++;
        }
    } 

    return 1LL * side1 * side2;
}


void solve() {
    int num_monsters;
    cin >> num_monsters;

    vector<pair<int, int>> x_pos(num_monsters);
    vector<pair<int, int>> y_pos(num_monsters);
    for (int i = 0; i < num_monsters; i++) {
        int x, y;
        cin >> x >> y;

        x_pos[i] = {x, i};
        y_pos[i] = {y, i};
    }

    if (num_monsters == 1) {
        cout << 1 << endl;
        return;
    }

    sort(x_pos.begin(), x_pos.end());
    sort(y_pos.begin(), y_pos.end());

    // if we dont have a full rectangle of monsters we can just add the monster in the middle of rect
    // else we may need add some dimension to the monster rectangle
    long long area = LONG_LONG_MAX;
    
    int left, right, up, down;
    
    // remove the most left
    left = x_pos[1].first;
    right = x_pos[num_monsters-1].first;
    up = y_pos[num_monsters-1].first;
    down = y_pos[0].first; 

    // check if the most left has the same id as most up or most right
    if (x_pos[0].second == y_pos[0].second) {
        down = y_pos[1].first;
    }
    if (x_pos[0].second == y_pos[num_monsters-1].second) {
        up = y_pos[num_monsters-2].first;
    }
    area = min(area, calculate_area(left, right, up, down, num_monsters));
    
    // remove the most right
    left = x_pos[0].first;
    right = x_pos[num_monsters-2].first;
    up = y_pos[num_monsters-1].first;
    down = y_pos[0].first; 

    // check if the most left has the same id as most up or most right
    if (x_pos[num_monsters-1].second == y_pos[0].second) {
        down = y_pos[1].first;
    }
    if (x_pos[num_monsters-1].second == y_pos[num_monsters-1].second) {
        up = y_pos[num_monsters-2].first;
    }
    area = min(area, calculate_area(left, right, up, down, num_monsters));
    
    // remove the most up
    left = x_pos[0].first;
    right = x_pos[num_monsters-1].first;
    up = y_pos[num_monsters-2].first;
    down = y_pos[0].first; 

    // check if the most left has the same id as most up or most right
    if (y_pos[num_monsters-1].second == x_pos[0].second) {
        left = x_pos[1].first;
    }
    if (y_pos[num_monsters-1].second == x_pos[num_monsters-1].second) {
        right = x_pos[num_monsters-2].first;
    }
    area = min(area, calculate_area(left, right, up, down, num_monsters));


    // remove the most down
    left = x_pos[0].first;
    right = x_pos[num_monsters-1].first;
    up = y_pos[num_monsters-1].first;
    down = y_pos[1].first; 

    // check if the most left has the same id as most up or most right
    if (y_pos[0].second == x_pos[0].second) {
        left = x_pos[1].first;
    }
    if (y_pos[0].second == x_pos[num_monsters-1].second) {
        right = x_pos[num_monsters-2].first;
    }
    area = min(area, calculate_area(left, right, up, down, num_monsters));


    cout << area << endl;
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
