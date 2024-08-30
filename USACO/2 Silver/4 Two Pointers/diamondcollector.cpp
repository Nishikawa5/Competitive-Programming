#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("diamond.in", "r", stdin);
	freopen("diamond.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    vector<int> diamonds(n);
    for (int &d: diamonds) {
        cin >> d;
    }
    sort(diamonds.begin(), diamonds.end());

    vector<int> best_left(n);
    int r = 0;
    for (int l = 0; l < n; l++) {
        while (r < n && diamonds[r] - diamonds[l] <= k) {
            r++;
        }
        best_left[l] = r - l;
    }

    vector<int> best_after(n + 1);
    best_after[n] = 0; 
    for (int i = n - 1; i >= 0; i--) {
        best_after[i] = max(best_after[i + 1], best_left[i]);
    }

    int max_diamonds = 0;
    for (int l = 0; l < n; l++) {
        max_diamonds = max(max_diamonds, best_left[l] + best_after[best_left[l] + l]);
    }
    cout << max_diamonds << endl;
}