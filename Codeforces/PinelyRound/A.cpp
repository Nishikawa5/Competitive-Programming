#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;

        int max_num = 0;
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            if (i % 2 == 0) {
                max_num = max(max_num, t);
            } 
        }
        cout << max_num << endl;
    }
}