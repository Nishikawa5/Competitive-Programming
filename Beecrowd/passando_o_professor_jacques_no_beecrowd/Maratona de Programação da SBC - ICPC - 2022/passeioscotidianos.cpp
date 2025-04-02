#include <bits/stdc++.h>
using namespace std;

/*
rain => y
!rain && !umbdest => y
else n
*/
#define HOME 0
#define WORK 1

bool take_umb(bool is_raining, int h_umb, int w_umb, int from) {
    if (is_raining) {
        return true;
    } else if (from == HOME && w_umb == 0) {
        return true;
    } else if (from == WORK && h_umb == 0) {
        return true;
    }
    return false;
}

int main() {
    int n, h_umb, w_umb;
    cin >> n >> h_umb >> w_umb;

    for (int i = 0; i < n; i++) {
        char home_work, work_home;

        cin >> home_work;
        if (take_umb(home_work == 'Y', h_umb, w_umb, HOME)) {
            h_umb--; w_umb++;
            cout << "Y ";
        } else {
            cout << "N ";
        }

        cin >> work_home;
        if (take_umb(work_home == 'Y', h_umb, w_umb, WORK)) {
            w_umb--; h_umb++;
            cout << "Y\n";
        } else {
            cout << "N\n";
        }
    }
}