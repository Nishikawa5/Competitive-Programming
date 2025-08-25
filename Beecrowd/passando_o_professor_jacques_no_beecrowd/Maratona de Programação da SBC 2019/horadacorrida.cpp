#include <bits/stdc++.h>
using namespace std;


int main() {
    int v, n;
    cin >> v >> n;

    double total = v*n;
    for (int i = 1; i < 10; i++) {
        double frac = (total/10)*i;
        cout << (int)(frac + ((int)frac != frac));

        if (i != 9) cout << " ";
    }
    cout << endl;
}