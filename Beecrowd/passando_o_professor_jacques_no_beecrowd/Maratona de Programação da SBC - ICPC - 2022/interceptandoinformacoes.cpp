#include <bits/stdc++.h>
using namespace std;

int main() {
    bool valid = true;
    for (int i = 0; i < 8; i++) {
        short bit;
        cin >> bit;

        if (bit != 0 && bit != 1) {
            valid = false;
        }
    }
    if (valid) {
        cout << "S\n";
    } else {
        cout << "F\n";
    }
}