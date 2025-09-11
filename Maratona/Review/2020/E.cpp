#include <bits/stdc++.h>

using namespace std;


void solve() {
    // is there a city that is closer
    // and has more value?
    // how many greater than the currcity
    // to left and right?

    int n;
    cin >> n;

    vector<int> arr(n);

    for (auto &a: arr) {
        cin >> a;
    }


    stack<int> monotonic_dec;
    vector<int> prefix(n+1);

    for (int i = 0; i < n; i++) {
        // [(j-i) + j, i + (j-i)]
        // we calculate from [2j, i]
        while (!monotonic_dec.empty() && arr[monotonic_dec.top()] <= arr[i]) {
            monotonic_dec.pop();
        }

        // Consider just the greatest number
        if (!monotonic_dec.empty()) {
            int mid = (monotonic_dec.top() + i) / 2;
            // [mid + 1, i - 1] is guaranteed to benefit from this val
            // considering just left values
            prefix[mid+1]++;
            prefix[i]--;
        } else {
            // [0, i-1]
            prefix[0]++;
            prefix[i]--;
        }

        monotonic_dec.push(i);
    }

    monotonic_dec = stack<int>();
    // do the same thing from right -> left
    for (int i = n-1; i >= 0; i--) {
        // [(j-i) + j, i + (j-i)]
        // we calculate from [2j, i]
        while (!monotonic_dec.empty() && arr[monotonic_dec.top()] <= arr[i]) {
            monotonic_dec.pop();
        }

        // Consider just the greatest number
        if (!monotonic_dec.empty()) {
            int mid = (monotonic_dec.top() + i + 1) / 2;
            // [i + 1, mid - 1] is guaranteed to benefit from this val
            // considering just left values
            prefix[i+1]++;
            prefix[mid]--;
        } else {
            // [i+1, n-1]
            prefix[i+1]++;
            //prefix[n]--;
        }

        monotonic_dec.push(i);
    }

    for (int i = 0; i < prefix.size()-1; i++) {
        if (i) prefix[i] += prefix[i-1];
        cout << prefix[i] << " ";
    }
    cout << endl;
}


int main() {
    solve();
}