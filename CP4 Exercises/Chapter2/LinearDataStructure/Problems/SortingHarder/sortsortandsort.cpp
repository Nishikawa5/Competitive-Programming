#include <bits/stdc++.h>
using namespace std;

/*
Sort ascending according to modulo m
odd > even
larger odd precede smaller odd
smaller even precede larger even
*/
int main() {
    int num, modulo;

    while (cin >> num >> modulo && num && modulo) {
        vector<int> arr(num);
        
        for (auto &a: arr) {
            cin >> a;
        }
        sort(arr.begin(), arr.end(), [&] (int a, int b) {
            int amodm = a % modulo;
            int bmodm = b % modulo;

            if (amodm < bmodm) {
                return true;
            } else if (amodm > bmodm) {
                return false;
            } else {
                if ((a % 2) && !(b % 2)) {
                    // a odd b even
                    return true;
                } else if (!(a % 2) && (b % 2)) {
                    // a even b odd
                    return false;
                } else if (a % 2 && b % 2) {
                    // both odd
                    return a > b;
                } else {
                    // both even
                    return a < b;
                }
            }
        });

        cout << num << " " << modulo << endl;
        for (int x: arr) {
            cout << x << endl;
        }
    }
    cout << 0 << " " << 0 << endl;
}