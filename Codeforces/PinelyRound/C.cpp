#include <bits/stdc++.h>
using namespace std;

/*
Idea:

0 <= a[i] <= 10^9
=>
0 <= a[i] <= 2^31
=>
-2^30 <= a[i] - 2^30 <= 2^30
=>
0 <= abs(a[i] - 2^30) <= 2^30
=>
.
.
.
=>
0 <= abs(abs(...(abs(a[i]) - 4) - ...)) <= 4
=>
0 <= abs(abs(...(abs(a[i]) - 1) - ...)) <= 1
*/
void operation(vector<int> &a, int x) {
    for (auto &a_i: a) {
        a_i = abs(a_i - x);
    }
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;
        vector<int> a(n);

        int odd = 0;    // count the number of odds
        for (auto &x: a) {
            cin >> x;
            odd += 1 & x;
        }
        
        if (odd && odd < n) {
            // if we have odd and even is not possible
            cout << -1 << endl;
            continue;
        }

        if (odd) {
            cout << 32 << endl;
        } else {
            cout << 31 << endl;
        }
        cout << (1 << 29);
        //operation(a, 1 << 29);
        for (int i = 28; i >= 0; i--) {
            cout << " " << (1 << i);
            //operation(a, 1 << i);
        }
        cout << " 1";
        if (odd) {
            cout << " 1";
            //operation(a, 1);
        }
        cout << "\n";
        
        /*
        for (int i = 0; i < n; i++) {
            cout << a[i] << endl;
        }*/
    }
}