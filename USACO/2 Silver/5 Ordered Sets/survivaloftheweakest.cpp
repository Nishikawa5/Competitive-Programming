#include <bits/stdc++.h>
using namespace std;

int main() {
    long long mod = 1e9 + 7;
    int n;
    cin >> n;

    vector<long long> arr(n);
    for (auto &a: arr) {
        cin >> a;
    }
    sort(arr.begin(), arr.end());

    for (int curr_len = arr.size() - 1; curr_len >= 1; curr_len--) {
        vector<long long> next_arr(curr_len);
        priority_queue<array<long long, 3>> min_heap;

        for (int i = 0; i < curr_len; i++) {
            min_heap.push({-(arr[i] + arr[i + 1]), i, i + 1});
        }

        // store the array after applying the function
        for (int i = 0; i < curr_len; i++) {
            long long val = -(min_heap.top()[0]);
            long long l = min_heap.top()[1];
            long long r = min_heap.top()[2];
            min_heap.pop();

            // the best value
            next_arr[i] = val;

            if (r + 1 < arr.size()) {
                min_heap.push({-(arr[l] + arr[r + 1]), l, r + 1});
            }
        }
        
        // mean
        if (next_arr[0] >= mod) {
            // cant apply mod since after it we may
            // not have sorted arr
            int mult = next_arr[0] / mod;
            for (int i = 0; i < next_arr.size(); i++) {
                next_arr[i] -= mult * mod;
            }
        }
        arr = next_arr;
    }
    cout << arr[0] << endl;
}