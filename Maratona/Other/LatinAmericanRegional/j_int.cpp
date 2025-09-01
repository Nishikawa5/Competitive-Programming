#include <bits/stdc++.h>
using namespace std;

#define PI 3.14159265358979323

void solve() {
    int theta, n;
    cin >> theta >> n;

    vector<int> pos(n);
    vector<int> height(n);
    vector<int> idx(n);
    
    double const_tan = tan(PI * theta / 180);
    for (int i = 0; i < n; i++) {
        int p, h;
        cin >> p >> h;

        pos[i] = p;
        height[i] = h;
        idx[i] = i;
    }

    sort(idx.begin(), idx.end(), [&](int i, int j) {
        return pos[i] < pos[j];
    });


    double ans = 0;
    for (int i = 0; i < n; i++) {
        double start = pos[idx[i]];

        double max_shadow = pos[idx[i]] + height[idx[i]] / const_tan;
        while (i < n-1 && max_shadow > pos[idx[i+1]]) {
            i++;
            max_shadow = max(max_shadow, pos[idx[i]] + height[idx[i]] / const_tan);
        }
        ans += max_shadow - start;
    }
    cout << fixed << setprecision(13) << ans << endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    solve();
}