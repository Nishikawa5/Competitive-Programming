#include <bits/stdc++.h>
using namespace std;

vector<int> nimbers(5001);

void pre_calculate_nimbers() {
    nimbers[0] = nimbers[1] = 0;

    for (int n = 2; n < nimbers.size(); n++) {
        set<int> reachable_nimbers;

        for (int i = 0; i <= (n-2)/2; i++) {
            int j = n - 2 - i;

            int nim_sum = nimbers[i] ^ nimbers[j];

            reachable_nimbers.insert(nim_sum);
        }

        int mex = 0;
        while (reachable_nimbers.count(mex)) {
            mex++;
        }
        nimbers[n] = mex;
    }
}

void solve() {
    int n;
    cin >> n;

    // a winner strategy: make 2 equal groups of coins, 
    // so one can do what the other did in the opposite side

    // lets say n is even, so alice can always make 2 equal groups by removing the middle => she always wins
    if (n % 2 == 0) {
        cout << "First\n";
    } else {
        // dont remove a pair that makes the connected coins odd since it would lead to case 1

        // by solution we can calculate the nimbers like that:
        // N(n) = MEX{N(0)⊕N(n-2), N(1)⊕N(n-3), … N(n-2)⊕N(0)} if n > 1
        // N(0/1) = 0

        if (nimbers[n] == 0) {
            cout << "Second\n";
        } else {
            cout << "First\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;

    pre_calculate_nimbers();

    while (tc--) {
        solve();
    }
    return 0;
}
