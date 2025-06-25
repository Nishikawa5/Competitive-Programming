#include <bits/stdc++.h>
using namespace std;

void solve() {
    // lets say its m turn
    // n is even so he just subtract n
    // n is odd so if he subtract any even number the result still odd and he loses

    // same for ehab but for diff parities
    int n;
    cin >> n;

    if (n % 2) {
        cout << "Ehab\n";
    } else {
        cout << "Mahmoud\n";
    }
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
