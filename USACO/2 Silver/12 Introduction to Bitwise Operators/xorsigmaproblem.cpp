#include <bits/stdc++.h>
using namespace std;

/*
1 xor 1 == 0
1 xor 0 == 1
0 xor 1 == 1
0 xor 0 == 0

1 ? 1 == 1
1 ? 0 == 0
0 ? 1 == 0
0 ? 0 == 1

a xor b = c => b = a ? c

0 1 1
1 0 1
1 1 0
0 0 0


(a and b) or (not a and not b)

*/

int not_xor(int a, int b) {
    return (a & b) | (~a & ~b);
}   


int main() {
    int n;
    cin >> n;

    int total_xor;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        if (!i) {
            total_xor = arr[i];
        } else {
            total_xor ^= arr[i];
        }
    }

    int total_sum = 0;
    int total_xor_left = total_xor;
    for (int i = 0; i < n - 1; i++) {
        total_sum += total_xor_left * (i + 1);
        total_xor_left = arr[i] ^ total_xor_left;
    }

    int total_xor_right = total_xor;
    for (int i = 0; i < n - 1; i++) {
        total_sum += total_xor_right * (i);
        total_xor_right = arr[n - i - 1] ^ total_xor_right;
    }

    cout << total_sum << endl;
}