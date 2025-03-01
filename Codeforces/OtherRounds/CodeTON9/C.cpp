#include <bits/stdc++.h>
using namespace std;

/*
x xor y | x  then  x xor y < x
x xor y | y  then  x xor y < y
for x != y

and

d | p then  d <= floor(p / 2), since the smallest divisor != 1 == 2
so p >> 1 >= d, which means highest bits of p and d are different

and if y >= 2 * x then x xor y has same highest bit as y, which contradicts the above statement
so x xor y dont divide y

and if y >= 2 * x then x xor y > x, so x xor y dont divide x

so we just consider y < 2 * x cases
2 <= 2 * x <= 2 * 10^6, then can brute force every y

*/

#define ll long long
void solve() {
    ll x, m;
    cin >> x >> m;

    int ans = 0;
    for (int y = 1; y <= m && y < 2 * x; y++) {
        ll xxory = x ^ y;

        ans += (xxory && (x % xxory == 0 || y % xxory == 0) && x != y);
    }
    cout << ans << "\n";
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
