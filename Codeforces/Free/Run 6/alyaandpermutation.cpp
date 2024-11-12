#include <bits/stdc++.h>
using namespace std;

int highestOneBit(int i) {
    i |= (i >>  1);
    i |= (i >>  2);
    i |= (i >>  4);
    i |= (i >>  8);
    i |= (i >> 16);
    return i - (i >> 1);
}

/*
i is odd => k = k & pi
else     => k | pi

max k
*/
void solve() {
    int n;
    cin >> n;

    if (n % 2) {
        // the last op is &
        // so k <= last num
        // lets choose the last to be n then
        // we can make n with & | operations (the or before doesnt matter):
        // ((1 & 3) | n - 1) == n, since n is odd
        cout << n << endl;
        for (int i = 1; i <= n; i++) {
            if (!(i == 1 || i == 3 || i == n - 1 || i == n)) {
                cout << i << " ";
            } 
        }
        cout << "1 3 " << n - 1 << " " << n << endl; 
    } else {
        // the last op is |, we have two cases:
        if (n > 0 && (n & (n - 1)) == 0) {
            // is power of 2
            // the last is n, since bit of n is unique
            // | 1 & 3 | n - 2 == n - 1, since n - 1 is odd
            cout << n + n - 1 << endl;
            for (int i = 1; i <= n; i++) {
                if (!(i == 1 || i == 3 || i == n - 2 || i == n - 1 || i == n)) {
                    cout << i << " ";
                }
            }
            cout << "1 3 " << n - 2 << " " << n - 1 << " " << n << endl;
        } else {
            // the best we can do is 111..111
            // to make that: | ((n & n - 1) == highest bit + smt) | highest bit - 1
            
            // highest bit
            int highest_bit = highestOneBit(n);
            cout << highest_bit + highest_bit - 1 << endl;
            for (int i = 1; i <= n; i++) {
                if (!(i == highest_bit - 1 || i == n || i == n - 1)) {
                    cout << i << " ";
                }
            }
            cout << n << " " << n - 1 << " " << highest_bit - 1 << " " << endl; 
        }
    }
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
