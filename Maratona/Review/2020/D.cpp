#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<int, int> count;

    for (int t = 0; t < n; t++) {
        int i;
        cin >> i;

        if (count[i] == 1) {
            int idx = i;
            while (count[idx] == 1) {
                count[idx++] = 0;
            }
            count[idx] = 1;
        } else {
            count[i] = 1;
        }
    }
    
    int ones = 0;
    for (auto &p: count) {
        ones += p.second;
    }

    cout << ((ones <= 2 && n != 1) ? "Y\n":"N\n");
}