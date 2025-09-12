#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> bit_count(32, 0);
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        for (int j = 0; j < 32; j++) {
            bit_count[j] += (temp >> j) & 1;
        }
    }

    for (int i = 0; i < n; i++) {

        int curr = 0;
        for (int j = 31; j >= 0; j--) {
            if (bit_count[j]) {
                bit_count[j]--;

                curr |= 1<<j;
            }
        }
        cout << curr << " ";
    }
    cout << endl;
}