#include <bits/stdc++.h>
using namespace std;

int MAX_N = 5e3+1;
vector<vector<int>> gcd_table(MAX_N, vector<int>(MAX_N));

void precompute_gcds() {
    for (int i = 0; i < MAX_N; i++) {
        gcd_table[i][0] = i;
        gcd_table[0][i] = i;
    }

    for (int i = 1; i < MAX_N; ++i) {
        for (int j = 1; j <= i; ++j) {
            // gcd(i, j) = gcd(j, i % j)
            gcd_table[i][j] = gcd_table[j][i % j];
            gcd_table[j][i] = gcd_table[i][j];
        }
    }
}

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto &a: arr) {
        cin >> a;
    }

    // every number will be equal to the gcd of every number in arr
    int the_gcd = arr[0];
    for (auto a: arr) {
        the_gcd = gcd_table[the_gcd][a];
    }

    int changes = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != the_gcd) {
            changes++;
        }
    }
    if (changes != n) {
        // in case we already have the gcd there
        cout << changes << endl;
        return;
    }

    // now lets make this gcd using the least amount of moves
    vector<int> min_ops_to_create(MAX_N, 0x3f3fffff);

    int max_val = 0;
    for (int i = 0; i < n; i++) {
        arr[i] /= the_gcd;
        max_val = max(max_val, arr[i]);
        
        // note that we dont need to consider the element multiplied by gcd,
        // so the answer should be minopstocreate 1
        min_ops_to_create[arr[i]] = 0;
    }

    for (int x = max_val; x >= 1; x--) {
        for (int i = 0; i < n; i++) {
            // minimum amount of ops to create x
            min_ops_to_create[gcd_table[x][arr[i]]] = min(
                min_ops_to_create[gcd_table[x][arr[i]]],    // already the min
                min_ops_to_create[x] + 1                    // we can create this gcd by gcd(x, arr[i])
            );
        }
    }

    cout << (changes - 1) + min_ops_to_create[1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;

    precompute_gcds();

    while (tc--) {
        solve();
    }
    return 0;
}