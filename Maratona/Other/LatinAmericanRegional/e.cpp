#include <bits/stdc++.h>
using namespace std;

void solve() {
    // up -> down
    int n;
    cin >> n;

    vector<int> arr(n);
    vector<bool> is_there(n+1);
    vector<int> to_complete;
    vector<int> next_nonzero(n, -1);
    vector<int> prev_nonzero(n, -1);
    for (auto &a: arr) {
        cin >> a;

        is_there[a] = true;
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            for (int j = i; next_nonzero[j] == -1 && j >= 0; j--) {
                next_nonzero[j] = i;
            }
        }
    }
    for (int i = n-1; i >= 0; i--) {
        if (arr[i] != 0) {
            for (int j = i; prev_nonzero[j] == -1 && j < n; j++) {
                prev_nonzero[j] = i;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!is_there[i]) {
            to_complete.push_back(i);
        }
    }

    int curr_complete = 0;
    for (int left = 0, right = n-1; curr_complete != to_complete.size();) {
        if (arr[left] <= to_complete[curr_complete] &&
            arr[right] <= to_complete[curr_complete] &&
            arr[right] + arr[left] != 0) {
            cout << "*\n";
            return;
        }
        
        // put the smallest in the side of smalles
        
        if (arr[left] + arr[right] == 0) {
            if (next_nonzero[left] + prev_nonzero[right] == -2) {
                // any side
                arr[left++] = to_complete[curr_complete++];
            } else if (next_nonzero[left] == prev_nonzero[right]) {
                // choose the side that has less zeros
                if (next_nonzero[left] - left >= right - prev_nonzero[right]) {
                    arr[right--] = to_complete[curr_complete++];
                } else {
                    arr[left++] = to_complete[curr_complete++];
                }
            } else if (arr[next_nonzero[left]] < arr[prev_nonzero[right]]) {
                arr[left++] = to_complete[curr_complete++];
            } else {
                arr[right--] = to_complete[curr_complete++];
            }
        } else if (arr[right] == 0) {
            arr[right--] = to_complete[curr_complete++];
        } else if (arr[left] == 0) {
            arr[left++] = to_complete[curr_complete++];
        }

        if (arr[left] && arr[left] < to_complete[curr_complete]) {
            left++;
        }
        if (arr[right] && arr[right] < to_complete[curr_complete]) {
            right--;
        }

        // for (auto a: arr) {
        //     cout << a << " ";
        // }
        // cout << endl;
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    solve();
}