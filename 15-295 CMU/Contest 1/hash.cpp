#include <bits/stdc++.h>
using namespace std;

int main() {
    // p buckets from 0 to p-1
    int p, n;
    cin >> p >> n;

    int ans = -1;
    bool conflict = false;
    vector<int> buckets(p, 0);
    for (int i = 1; i <= n; i++) {
        int curr_num;
        cin >> curr_num;

        if (buckets[curr_num % p] && !conflict) {
            ans = i;
            conflict = true;
        }
        buckets[curr_num % p] = 1;
    }

    cout << ans << endl;
}