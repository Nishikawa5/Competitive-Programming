#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    
    int left = 0;
    int right = n-1;
    for (int i = 1; i <= n; i++) {

        if (i % 2 == 1) {
            arr[left++] = i;
        } else {
            arr[right--] = i;
        }
    }
    for (auto a: arr) {
        cout << a << " ";
    }
    cout << endl;
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
