#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;

        if (n < 6) {
            // < 4 colors
            if (n == 1)
                cout << 1 << '\n' << "1" << '\n';
            else if (n == 2)
                cout << 2 << '\n' << "1 2" << '\n';
            else if (n == 3)
                cout << 2 << '\n' << "1 2 2" << '\n';
            else if (n == 4)
                cout << 3 << '\n' << "1 2 2 3" << '\n';
            else if (n == 5)
                cout << 3 << '\n' << "1 2 2 3 3" << '\n';
        } else {
            // 4 colors
            // so we can put the same color every 4: 1 2 3 4 1 2 3 4 ...
            // i + 4 - i = 4 => last 2 digits are equal in both numbers (00 or 01 or 10 or 11) => (i + 4) ^ i = bbbbb00 which is divisible by four. So is not a prime number 
            cout << 4 << endl;
            cout << 1;
            for (int i = 1; i < n; i++) {
                cout << " " << i % 4 + 1;
            }
            cout << endl;
        }
    }
    
}