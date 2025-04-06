#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;

    vector<pair<int, int>> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i + 1;
    }

    sort(arr.begin(), arr.end());

    int left = 0;
    int right = n - 1;

    while (left < right) {
        int curr_sum = arr[left].first + arr[right].first;

        if (target > curr_sum) {
            left++;
        } else if (target < curr_sum) {
            right--;
        } else {
            cout << arr[left].second << " " << arr[right].second << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}