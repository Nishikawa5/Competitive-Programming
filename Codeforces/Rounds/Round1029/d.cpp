#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto &a: arr) {
        cin >> a;
    }
    

    /*
    arr[i] = (x + ny + (i-1)*(x-y))
    so arr[i] must increase by (x-y)
    
    */
    
    int x_plus_ny = arr[0];
    int x_min_y = arr[1] - arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] - arr[i-1] != x_min_y) {
            cout << "NO\n";
            return;
        }
    }

    // x + ny = arr[0]
    // x - y  = arr[1] - arr[0]
    // => y(n+1) = 2arr[0] - arr[1]
    int y = 2*arr[0] - arr[1];
    if (y % (n+1)) {
        // y must be integer
        cout << "NO\n";
        return;
    }

    y /= n+1;
    int x = arr[0] - n*y;
    if (!(x >= 0 && y >= 0)) {
        // cant be negative
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
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
