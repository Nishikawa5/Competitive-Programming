#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, b;
    cin >> n >> k >> b;

    vector<int> arr(n+1, 1);
    for (int i = 0; i < b; i++) {
        int k;
        cin >> k;

        arr[k] = 0;
    }

    int failing = 0;
    for (int i = 1; i <= k; i++) {
        failing += (arr[i] == 0);
    }
    
    int min_failing = failing;
    for (int s = 1, e = k+1; e <= n; s++, e++) {
        failing -= (arr[s]==0);        
        failing += (arr[e]==0);
        min_failing = min(min_failing, failing);
    }
    cout << min_failing << endl;
}

int main() {
    solve();
}