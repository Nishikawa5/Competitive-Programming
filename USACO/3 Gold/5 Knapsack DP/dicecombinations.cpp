#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> sums(n + 1, 0);
    sums[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= 6; k++) {
            if (i - k < 0) break;
            sums[i] += sums[i - k];
            sums[i] %= (int) (1e9 + 7);
        }
    }
    cout << sums[n] << endl;
}