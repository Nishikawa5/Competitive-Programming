#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;

    for (int i = 1; i <= tc; i++) {
        int n, k;
        cin >> n >> k;

        int power_two = 1 << n;
        k %= power_two;

        cout << "Case #" << i << ": ";
        if (k == power_two - 1) {
            cout << "ON";
        } else {
            cout << "OFF";
        }
        cout << endl;
    }
}