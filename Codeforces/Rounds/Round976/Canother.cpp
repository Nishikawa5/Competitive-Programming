#include <bits/stdc++.h>
using namespace std;

#define ll long long

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
so we can't have 0 - 1
*/
void solve() {
    long long a, b, c, d;
    cin >> b >> c >> d;
    // increasing

    long long bit_ptr = 1;
    long long ans = 0;
    for (int i = 0; i < 64; i++) {
        ll bit_b, bit_c, bit_d;

        bit_b = (bit_ptr & b) != 0;
        bit_c = (bit_ptr & c) != 0;
        bit_d = (bit_ptr & d) != 0;
        
        if ((bit_b && !bit_c && !bit_d) || (!bit_b && bit_c && bit_d)) {
            // not covered by the table
            cout << -1 << "\n";
            return;
        }
        
        if (bit_b && bit_c) {
            a += (1LL - bit_d) * bit_ptr;
        } else {
            a += bit_d * bit_ptr;
        }

        bit_ptr <<= 1;
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