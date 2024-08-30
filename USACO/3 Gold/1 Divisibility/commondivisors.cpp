#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> count_div(1e6 + 1, 0);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        for (int div = 1; div * div <= x; div++) {
            if (x % div == 0) {
                count_div[div]++;

                if (div != x / div) {
                    count_div[x / div]++;
                }
            }
            
        }
    }

    for (int i = count_div.size() - 1; i >= 0; i--) {
        if (count_div[i] >= 2) {
            cout << i << endl;
            break;
        }
    }
}