#include <bits/stdc++.h>
using namespace std;

/*
a symmetric matrix with flight costs
*/
int main() {
    int n;
    cin >> n;

    vector<vector<int>> flights(n, vector<int>(n));
    for (auto &vec: flights) {
        for (auto &cost: vec) {
            cin >> cost;
        }
    }

    vector<vector<bool>> deleted(n, vector<bool>(n, false));
    for (int from = 0; from < n; from++) {
        for (int mid = 0; mid < n; mid++) {
            for (int to = 0; to < n; to++) {
                // we have 2 possibilities of going from from to to
                // from -> mid -> to (multi_stop) or from -> to (direct) 
                if (from != mid && mid != to && from != to) {
                    int multi_stop = flights[from][mid] + flights[mid][to];
                    int direct     = flights[from][to];

                    // incoherent
                    if (direct > multi_stop) {
                        // not coherent
                        cout << -1 << endl;
                        return 0;
                    }

                    // possible to delete <=> they are equal
                    if (direct == multi_stop) {
                        // can delete this direct flight
                        deleted[from][to] = true;
                    }
                }
            }
        }
    }

    int max_deleted = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            max_deleted += deleted[i][j];
        }
    }
    cout << max_deleted / 2 << endl;
}