#include <bits/stdc++.h>
using namespace std;


int main() {
    int v, n;
    cin >> v >> n;

    int total = v*n;
    for (int i = 1; i < 10; i++) {
        cout << (total * i + 9) / 10;

        if (i != 9) cout << " ";
    }
    cout << endl;
}