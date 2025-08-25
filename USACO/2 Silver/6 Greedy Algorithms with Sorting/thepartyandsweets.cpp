#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int num_boys, num_girls;
    cin >> num_boys >> num_girls;

    vector<ll> from(num_boys);
    vector<ll> to(num_girls);

    for (auto &b: from) {
        cin >> b;
    }
    for (auto &g: to) {
        cin >> g;
    }
    sort(from.begin(), from.end());
    sort(to.begin(), to.end());

    if (from[num_boys-1] > to[0]) {
        cout << -1 << endl;
        return;
    }

    // highest fill the reqs
    int curr_highest = num_girls - 1;
    ll ans = 0;
    for (int i = num_boys-1; i >= 0; i--) {
        int presented = 0;

        while (curr_highest >= 0 && from[i] <= to[curr_highest]) {
            ans += to[curr_highest--];
            presented++;
        }
        if (presented == num_girls && to[0] != from[i]) {
            // he presented every girl, so no minimum. so give the minimum to last girl
            ans -= to[++curr_highest];
            presented--;
        }

        ans += (num_girls - presented) * from[i];
    }
    if (curr_highest == -1) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }

}


int main() {
    solve();
}