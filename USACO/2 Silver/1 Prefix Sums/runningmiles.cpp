#include <bits/stdc++.h>
using namespace std;

/*
we have 
bi_1 + bi_2 + bi_3 - (r - l)
since increasing the interval is not optimal we have that
bl + bm + br - (r - l), where l < m < r is the solution
= (bl + l) + (br - r) + bm

*/
int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;

        vector<int> beauties(n);
        vector<int> prefixmax(n);
        vector<int> suffixmax(n);

        for (int i = 0; i < n; i++) {
            cin >> beauties[i];
            prefixmax[i] = beauties[i] + i;
            suffixmax[i] = beauties[i] - i;
        }

        for (int i = 1; i < n; i++) {
            prefixmax[i] = max(prefixmax[i - 1], prefixmax[i]);
        }

        for (int i = n - 2; i >= 0; i--) {
            suffixmax[i] = max(suffixmax[i + 1], suffixmax[i]);
        }

        int rst = INT_MIN;
        for (int i = 1; i < n - 1; i++) {
            rst = max(rst, prefixmax[i - 1] + beauties[i] + suffixmax[i + 1]);
        }

        cout << rst << endl;
    }
}