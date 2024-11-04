#include <bits/stdc++.h>
using namespace std;

void solve() {
    int shelves_num, bottles_num;
    cin >> shelves_num >> bottles_num;

    vector<int> brand(bottles_num);
    for (int i = 0; i < bottles_num; i++) {
        int a, b;
        cin >> a >> b;
        brand[a - 1] += b;
    }

    sort(brand.begin(), brand.end(), greater<int>());

    int shelves_used = 0;
    int ans = 0;
    for (int i = 0; shelves_used < shelves_num && i < bottles_num; i++) {
        shelves_used++;

        ans += brand[i];
    }
    cout << ans << endl;
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
