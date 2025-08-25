#include <bits/stdc++.h>
using namespace std;

int first_true(int lo, int hi, function<bool(int)> f) {
    hi++;

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;

        if (f(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    return lo;
}

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto &a: arr) {
        cin >> a;
    }

    vector<vector<int>> sequences(n);
    int nofseq = 0;
    sequences[0].push_back(arr[0]);

    for (int i = 1; i < n; i++) {
        // v non dec seq => arr[i] < target => 
        // arr[i + j] < target
        // from 0 to nofseq
        int vector_idx = first_true(0, nofseq, [&](int curr_idx) {
            return sequences[curr_idx][sequences[curr_idx].size() - 1] < arr[i];
        });

        if (vector_idx > nofseq) {
            nofseq = vector_idx;
        }

        sequences[vector_idx].push_back(arr[i]);
    }


    for (int i = 0; i < nofseq+1; i++) {
        for (int j = 0; j < sequences[i].size(); j++) {
            cout << sequences[i][j] << " ";
        }
        cout << endl;
    }
}






int main() {
    solve();
}