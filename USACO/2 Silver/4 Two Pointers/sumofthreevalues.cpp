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

    for (int i = 0; i < n; i++) {
        // select one then do the same as sumoftwovalues
        int new_target = target - arr[i].first;

        int left = 0;
        int right = n - 1;

        while (left < right) {
            int curr_sum = arr[left].first + arr[right].first;

            if (left == i) {
                left++;
            } else if (right == i) {
                right--;
            } else if (new_target > curr_sum) {
                left++;
            } else if (new_target < curr_sum) {
                right--;
            } else {
                cout << arr[left].second << " " << arr[i].second << " " << arr[right].second << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}