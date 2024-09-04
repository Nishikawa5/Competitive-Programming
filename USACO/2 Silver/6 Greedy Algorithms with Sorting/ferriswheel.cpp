#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, max_w;
    cin >> n >> max_w;

    vector<int> weights(n);
    for (int &w: weights) {
        cin >> w;
    }

    sort(weights.begin(), weights.end());

    int total_gondola = 0;
    for (int l = 0, r = weights.size() - 1; l <= r;) {
        if (weights[l] + weights[r] <= max_w || l == r) {
            total_gondola++;
            l++;
            r--;
        } else {
            // allocate just for the heaviest
            total_gondola++;
            r--;
        }
    }
    cout << total_gondola << endl;
}