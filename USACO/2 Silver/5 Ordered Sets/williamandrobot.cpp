#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto &a: arr) {
        cin >> a;
    }

    // william can take n/2 elements
    // so his objective is to try to take the greatest
    // n/2 elements

    // we could try to get the greatest elements in order
    // but there's the case where william take the greatest
    // and robot takes the second greatest
    // e.g. 9 1 1 10

    // by going in pairs we can take or not
    // the ones that are in pq,
    // while the popped ones are already taken by robot
    // we make the robot take the lowest numbers
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        pq.push(-arr[i]);

        if (i % 2) {
            // robot takes after us
            pq.pop();
        }
    }

    long long ans = 0;
    for (int i = 0; i < n/2; i++) {
        ans += -pq.top();
        pq.pop();
    }
    cout << ans << endl;
}

int main() {
    solve();
}