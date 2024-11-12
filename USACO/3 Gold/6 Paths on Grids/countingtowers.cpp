#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll mod = 1e9 + 7;
// the added height is separated
vector<ll> dp1(1e6 + 1);
// the added height isnt separated
vector<ll> dp2(1e6 + 1);


void solve() {
    int n;
    cin >> n;

    cout << (dp1[n] + dp2[n]) % mod << endl;
}

/*
 _  _ 
| || | => add that to the top, now we can either add a division or not to bot squares

 _ _ 
|   |  => add to the top, now we can either separe or not this height from rect

dp1[i] = 4 * (dp1[i - 1] + dp2[i - 1]) % mod;
dp2[i] = 2 * (dp2[i - 1] + dp1[i - 1]) % mod;
that fails because it counts invalid moves like:
 _ _ 
|   |
|_| |

*/


int main() {
    /*
    assume we have a rectangle of height h and width 2
    how many ways can we place divisors in this rectangle
    as exemplified in the problem

    */
    int tc;
    cin >> tc;

    dp1[1] = 1;
    dp2[1] = 1;

    for (int i = 2; i <= 1e6; i++) {
        /* 
        we have only these possibilities:
        // transition:
        //              _  _    _  _    _  _    _  _     _ _
        //  _  _       | || |  |_|| |  | ||_|  |_||_|   |_ _|
        // | || | =>   | || |, | || |, | || |, | || |,  | | |
        //              _ _    _ _    _ _ 
        //  _ _        |   |  |_|_|  |_ _|
        // |   |  =>   |   |, |   |, |   |
        */
        dp1[i] = (4 * dp1[i - 1] + dp2[i - 1]) % mod;
        dp2[i] = (2 * dp2[i - 1] + dp1[i - 1]) % mod;
    }

    while (tc--) {
        solve();
    }

}