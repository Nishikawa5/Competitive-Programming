#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;

    for (int i = 1; i <= tc; i++) {
        string street;
        cin >> street;

        int ans = street.size();
        for (int k = 0; k < street.size(); k++) {
            if ((k < (street.size() - 1) && (street[k + 1] == 'B' || street[k + 1] == 'S')) || 
                (k < (street.size() - 2) && street[k + 2] == 'B') ||
                (k > 0 && street[k - 1] == 'S') || (street[k] != '-')) {
                ans--;
            }
        }

        cout << "Case " << i <<  ": " << ans << endl;
    } 
}