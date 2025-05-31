#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x;
    cin >> x;

    int sqrtx = sqrt(x);

    int count = (sqrtx*sqrtx == x);
    for (int div = 1; div*div < x; div++) {
        if (x % div == 0) {
            count += 2;
        }
    }
    cout << count << endl;
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
