#include <bits/stdc++.h>
using namespace std;

/*
Count the number of interceptions
T(1) = 2
T(n) = T(n - 1) + interceptions + 1
interceptions + 1

every l->r will intercept with every u->d
see if it's possible to intercept l->r before the limit
ok

2 1
3 2
1 3

1 3
2 1
3 2

*/
bool intercept(pair<int, int> c1, pair<int, int> c2) {
    // find the interception
    return (c1.first > c2.first && c1.second < c2.second) ||
           (c2.first > c1.first && c2.second < c1.second);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    int x, y;
    cin >> x >> y;

    int lrs_num, uds_num;
    cin >> lrs_num >> uds_num;
    vector<pair<int, int>> lrs(lrs_num);
    vector<pair<int, int>> uds(uds_num);

    for (auto &x: lrs) {
        cin >> x.first >> x.second;
    }
    for (auto &y: uds) {
        cin >> y.first >> y.second;
    }

    long long int max_slices = 2;
    for (int i = 1; i < lrs_num; i++) {
        // assume we add cut i

        // how many interceptions?
        max_slices++;
        for (int j = 0; j < i; j++) {
            max_slices += intercept(lrs[i], lrs[j]);
        }
    }

    for (int i = 0; i < uds_num; i++) {
        // assume we add cut i

        // how many interceptions?
        max_slices++;
        for (int j = 0; j < i; j++) {
            max_slices += intercept(uds[i], uds[j]);
        }
        max_slices += lrs.size();
    }
    cout << max_slices << endl;
}