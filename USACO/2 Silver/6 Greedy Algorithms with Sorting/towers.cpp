#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    multiset<int> cubes = {0};
    for (int i = 0; i < n; i++) {
        int curr_cube;
        cin >> curr_cube;
        auto curr_max = cubes.end();
        --curr_max;

        if (curr_cube >= *curr_max) {
            cubes.insert(curr_cube);
        } else {
            auto greater_it = cubes.upper_bound(curr_cube);
            cubes.erase(greater_it);
            cubes.insert(curr_cube);
        }
    }
    cout << cubes.size() - 1 << endl;
}