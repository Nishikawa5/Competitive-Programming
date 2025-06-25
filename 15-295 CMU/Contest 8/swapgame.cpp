#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (auto &a: arr) {
        cin >> a;
    }

    // 0 loses =>
    // see 1 lose, since we decrease and put 0 to arr => 
    // if there's a 2 in arr we can just decrease and put a 2
    // so the one that sees 3 loses
    // if there's a 4 we decrease and put 4
    // so the one that sees 5 loses
    // and so on
    

    // make one of them see the lowest and keep doing that
    // alice start
    // what is the lowest number and who sees it first?
    int target = INT_MAX;
    for (auto &a: arr) {
        target = min(target, a);
    }

    // if alice sees a number that is not the target and target is lower or equal she wins
    if (target == arr[0]) {
        // she decreases target in 1 and put some number
        // now bob has the advantage and wins
        cout << "Bob\n";
    } else {
        // in this case target > arr[0], so she can just force bob keep decreasing
        cout << "Alice\n";
    }
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