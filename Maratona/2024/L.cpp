#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> list(n);
    for (auto &l: list) {
        cin >> l;
    }

    for (int i = 0; i < n; i++) {
        int curr = list[i];
        for (int j = i + 1; j < n; j++) {
            for (int k = 0; k <= 32; k++) {
                if (((curr & (1 << k)) == 0) && ((list[j] & (1 << k)) == (1 << k))) {
                    curr |= (1 << k);
                    list[j] &= ~(1 << k);
                }
            }
        }
        cout << curr << " ";
    }
    cout << endl;
}