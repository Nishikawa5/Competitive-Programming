#include <bits/stdc++.h>
using namespace std;

int main() {

    // how many operations are needed to go from 2**(n-1), 2**(n-1) to (x,y)?
    // we can get to (1, 1) with n-1 steps, by activacting attractor in (0, 0)
    // attractor values: [0, 2**N]
    // particle values: [1, 2**(N-1)]
    // => (attractorval + particleval) / 2: [0, 2**(N-1) + 2**(N-2)]
    // lets say particle is at x
    // => new_x: [x >> 2, 2**(N-1) + x >> 2]
    // => so we need to go to the first 1 that we have to change
    int n, x, y;
    cin >> n >> x >> y;

    int first_1x = 0;
    int first_1y = 0;

    while (!(x & 0b1)) {
        x >>= 1;
        first_1x++;
    }
    
    while (!(y & 0b1)) {
        y >>= 1;
        first_1y++;
    }

    // n-1 bits -> (n-1) - first_1 (position of first 1 we have to change)
    int ans = n - 1 - min(first_1x, first_1y);
    cout << ans << endl;
}