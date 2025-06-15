#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    /*
    Separate the numbers in 2 parts:
        left    0 < len <  4      
            for len == 1 => 1
                len == 2 => 1
                len == 3 => 0

        right   len % 4 == 0      == 0
    */

    vector<int> rest = {0, 1, 1, 0};
    int printed_numbers = 0;

    int left_part = n % 4;    
    int right_part_num = (n - left_part) / 2;

    cout << rest[n % 4] << endl;

    // for 0 do nothing, since we just output right part
    int extra = n % 4;
    if (n % 4 == 1) {
        cout << right_part_num;
         
    } else if (n % 4 == 2) {
        // do the 2 case
        cout << right_part_num + 1;
        cout << " 1";
    } else if (n % 4 == 3) {
        // do the 3 case
        cout << right_part_num + 1;
        cout << " 3";
    } else {
        cout << right_part_num;
    }

    // right_part_num always even now
    int idx = 1;
    for (int i = 0; i < right_part_num; i += 2) {
        cout << " " << idx + extra;
        cout << " " << n - idx + 1;
        idx++;
    }

    cout << endl;
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
