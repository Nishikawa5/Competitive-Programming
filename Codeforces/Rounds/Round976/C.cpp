#include <bits/stdc++.h>
using namespace std;

/*

a  b c  d
0  0 0  0
0  0 1  0
0  1 0  1
0  1 1  1
1  0 0  1
1  0 1  0
1  1 0  1
1  1 1  0

a | b >= a & c
so we can't have (0 - 1)
*/
void solve() {
    long long b, c, d;
    cin >> b >> c >> d;
    // increasing

    long long bit_ptr = 1;
    long long ans = 0;
    for (int i = 0; i < 64; i++) {
        long long curr_bit_b = b & bit_ptr;
        long long curr_bit_c = c & bit_ptr;
        long long curr_bit_d = d & bit_ptr;

        /*
        Following the table:
        Note that we can have multiple solutions (in the table both 0 and 1 are possibilities of a when 
        b = 1, c = 0, d = 1 and b = 0, c = 1, d = 0)
        we can output any of them
        */
        if (!curr_bit_b && !curr_bit_c && !curr_bit_d) {
            ans += 0;
        } else if (!curr_bit_b && curr_bit_c && !curr_bit_d) {
            ans += 0;
        } else if (curr_bit_b && !curr_bit_c && curr_bit_d) {
            ans += 0;
        } else if (curr_bit_b && curr_bit_c && curr_bit_d) {
            ans += 0;
        } else if (!curr_bit_b && !curr_bit_c && curr_bit_d) {
            ans += bit_ptr;
        } else if (!curr_bit_b && curr_bit_c && !curr_bit_d) {
            ans += bit_ptr;
        } else if (curr_bit_b && !curr_bit_c && curr_bit_d) {
            ans += bit_ptr;
        } else if (curr_bit_b && curr_bit_c && !curr_bit_d) {
            ans += bit_ptr;
        } else {
            cout << -1 << endl;
            return;
        }

        bit_ptr = bit_ptr << 1;
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