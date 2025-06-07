#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll power(ll x, ll n, ll mod) {
    ll ans = 1;

    while (n) {
        if (n % 2) {
            ans *= x;
            ans %= mod;
            n--;
        } else {
            x *= x;
            x %= mod;
            n /= 2;
        }
    }

    return ans;
}



void solve() {
    // a**(p-1) = 1   modp by fermat little theorem
    // also since n is an integer, n = q(p-1) + r (r < p-1, q < floor(n/p-1))
    // (q(p−1)+r)*a**q(p−1)+r = b    modp
    // ...
    // (r - q)*a**r = b modp
    // q = r-b/(a**r) modp
    // since r < p-1, we can iterate through all r, while counting the number of possible q's
    // we also have that    1 <= n <= x
    // => q(p-1) + r <= x
    // => q <= floor((x-r)/(p-1))
    // we can find the first q that make both conditions true and increase it by p until the
    // condition above becomes false 
    ll a, b, p, x;
    cin >> a >> b >> p >> x;

    ll answers = 0;
    for (ll r = 0; r < p-1; r++) {
        if (x < r) {
            continue;
        }

        ll a_power_r_modp = power(a, r, p);
        ll inv_a_power_r_modp = power(a_power_r_modp, p - 2, p);
        ll term = (b * inv_a_power_r_modp) % p;
        
        ll first_q = (((r - term) % p) + p) % p;

        ll last_q = (x - r) / (p-1);

        if (last_q >= first_q) {
            answers += (last_q - first_q) / p + 1;
        }
    }
    cout << answers << endl;
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
