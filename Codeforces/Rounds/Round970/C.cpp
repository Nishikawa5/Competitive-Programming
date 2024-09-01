#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int l, r;
        cin >> l >> r;

        int a1, a2, difference, length;
        length = 1;
        difference = 1;
        a1 = l;
        a2 = l + difference;

        while (a2 <= r) {
            length++;

            a1 = a2;
            a2 = a1 + ++difference;
        }
        cout << length << endl;
    }
}