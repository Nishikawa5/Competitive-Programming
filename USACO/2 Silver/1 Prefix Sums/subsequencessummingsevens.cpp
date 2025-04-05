#include <bits/stdc++.h>
using namespace std;

/*
want the max number of ids that the sum is divisible by 7

we use prefix to keep track of the last cow with remainder e [0, 7)

*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    const int multiple = 7;
    int n;
    cin >> n;

    vector<int> cows(n);
    for (auto &c: cows) {
        cin >> c;
    }

    vector<int> rest_prefix(multiple, 0);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += cows[i];
        rest_prefix[sum % multiple] = i;
    }

    int max_cows = 0;
    sum = 0;
    for (int i = 0; i < n; i++) {
        max_cows = max(max_cows, rest_prefix[sum % multiple] - i + 1);
        sum += cows[i];
    }
    cout << max_cows << endl;
}