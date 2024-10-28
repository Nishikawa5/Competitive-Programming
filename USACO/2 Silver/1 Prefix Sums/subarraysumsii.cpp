#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, target;
    cin >> n >> target;
    vector<long long> array(n + 1);

    for (int i = 1; i < array.size(); i++) {
        cin >> array[i];
    }

    for (int i = 1; i < array.size(); i++) {
        array[i] += array[i - 1];
    }

    // reduce to a "two sum problem"
    // pref[i] - pref[j] = x (j < i) => pref[j] = pref[i] - x
    map<long long, int> count_pref;
    long long ans = 0;
    for (int i = 0; i < array.size(); i++) {
        ans += count_pref[array[i] - target];
        count_pref[array[i]]++;
    }
    cout << ans << endl;
}