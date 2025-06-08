#include <bits/stdc++.h>
using namespace std;

int first_true(int hi, int lo, function<bool(int)> f) {
    hi++;

    while (lo < hi) {
        int mid = lo + (hi - lo)/2;

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


    // a number that points to the other next number
    vector<pair<int, int>> arr(n);

    unordered_map<int, int> last_n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        
        if (last_n.find(a) != last_n.end()) {
            int idx = last_n[a];
            arr[idx].second = i;
        }

        last_n[a] = i;
        arr[i] = {a, -1};
    }


    int ans = 1;
    int goal = arr[0].second;

    bool stop = false;
    int k = 0;
    while (k < n) {
        if (goal == -1) {
            break;
        }

        int next_goal = -1;
        for (int j = k; j <= goal; j++) {

            if (arr[j].second == -1) {
                next_goal = -1;
                break;
            } else {
                next_goal = max(next_goal, arr[j].second);
            }
        }

        goal = next_goal;
        ans++;
        k++;
    }


    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
    return 0;
}
