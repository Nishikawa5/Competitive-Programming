#include <bits/stdc++.h>
using namespace std;

long long get_cost(vector<long long> arr, long long div, long long clockwise) {
    int idx = arr.size() * 2;

    long long carrying = 0;
    long long cost = 0;
    for (int i = 0; i < 2 * arr.size(); i++) {
        int curr_idx = (idx + i*clockwise) % arr.size();

        if (div > arr[curr_idx]) {
            // deposit carrying
            if (carrying >= div - arr[curr_idx]) {
                carrying -= div - arr[curr_idx];
                arr[curr_idx] = div;
            } else {
                arr[curr_idx] += carrying;
                carrying = 0;
            }
        } else {
            // arr -> carrying
            carrying += arr[curr_idx] - div;
            arr[curr_idx] = div;
        }
        cost += carrying;
    }
    return cost;
}

int main() {
    // cycle 2 times, start pos doesnt matter
    // only if it is clockwise or counter

    int n;
    cin >> n;

    vector<long long> arr(n);
    long long sum = 0;
    for (auto &a: arr) {
        cin >> a;
        sum += a;
    }

    long long div = sum / n;

    cout << min(get_cost(arr, div, 1), get_cost(arr, div, -1)) << endl;
}