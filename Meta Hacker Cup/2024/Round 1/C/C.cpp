#include <bits/stdc++.h>
using namespace std;

/*
the expected number of days to lose 1 weight is the same for every w
lets calculate it for different L:
F(0) = 0    (always lose 1)

F(x) = 1/2 * (F(x - 1) + F(x) + 1)       +          1/2 * (1)
            (+1 weight in 1 day)                    (-1 weight in 1 day)
we have probability of 1/2 to gain 1 weight and lose 1 weight

=>
2 * F(x) = F(x - 1) + F(x) + 1 + 1
=>
F(x) = F(x - 1) + 2
=>
F(x) = x * 2 + 1

=>
ans = (L * 2 + 1) * (W - G)
*/
long long mod = 998244353;
void solve() {
    unsigned long long W, G, L;
    cin >> W >> G >> L;

    cout << (((L * 2 + 1) % mod) * ((W - G) % mod)) % mod << endl;
}

int main() {
    int tc;
    cin >> tc;
    cout << fixed << setprecision(7);

    for (int i = 1; i <= tc; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}