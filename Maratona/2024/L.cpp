#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> count_bits(32);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        int curr_bit = 0;
        while (a) {
            count_bits[curr_bit++] += a & 1;
            a >>= 1;
        }
    }

    for (int i = 0; i < n; i++) {
        int curr_element = 0;
        for (int j = 0; j < 32; j++) {
            if (count_bits[j]) {
                curr_element |= (1 << j);
                count_bits[j]--;
            }
        }
        cout << curr_element << " ";
    }
    cout << "\n";
}