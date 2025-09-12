#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));
    int min_element = INT_MAX;
    for (auto &v: arr) {
        for (auto &a: v) {
            cin >> a;
            min_element = min(min_element, a);
        }
    }

    if (arr[0][0] == min_element) {
        cout << 0 << endl;
    } else if (arr[0][n-1] == min_element) {
        cout << 1 << endl;
    } else if (arr[n-1][n-1] == min_element) {
        cout << 2 << endl;
    } else if (arr[n-1][0] == min_element) {
        cout << 3 << endl;
    }
}