#include <bits/stdc++.h>
using namespace std;

/* TLE */
void solve() {
    vector<int> var1(4), var2(4);
    int lte1, lte2;

    char dummy;
    for (int i = 0; i < 4; i++) {
        int num;
        char var, sign;
        cin >> num >> var;

        var1[i] = num;
    }
    cin >> dummy >> dummy >> lte1;

    for (int i = 0; i < 4; i++) {
        int num;
        char var, sign;
        cin >> num >> var;

        var2[i] = num;
    }
    cin >> dummy >> dummy >> lte2;

    int R;
    cin >> R;
    int count = 0;
    map<int, int> is_sum1;
    map<int, int> is_sum2;
    for (int x = 0; x <= R; x++) {
        for (int y = 0; y <= R; y++) {
            for (int z = 0; z <= R; z++) {
                for (int w = 0; w <= R; w++) {
                    if (x + y + z + w > R) break;

                    // calculate equations
                    int rst1 = var1[0] * x + var1[1] * y + var1[2] * z + var1[3] * w;
                    int rst2 = var2[0] * x + var2[1] * y + var2[2] * z + var2[3] * w;

                    if (rst1 <= lte1) {
                        is_sum1[rst1]++;
                    }
                    if (rst2 <= lte2) {
                        is_sum2[rst2]++;
                    }
                }
            }
        }
    }

    for (auto p: is_sum1) {
        count += is_sum2[p.first] * p.second;
    }

    cout << count << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 1;

    while (tc--) {
        solve();
    }
    return 0;
}
