#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("berries.in", "r", stdin);
	freopen("berries.out", "w", stdout);

    int berry_trees_num;
    int baskets_num;
    cin >> berry_trees_num >> baskets_num;

    vector<int> berries(berry_trees_num);
    int max_berries = 0;
    for (auto &b: berries) {
        cin >> b;
        max_berries = max(max_berries, b);
    }

    int max_berries_bessie = 0;
    // both get the same amount of berries <=> every basket has the same amount of berries
    // can only get more berries for bessie <=> we can add one berry for berries_num/2 + 1 baskets
    for (int curr_berries = 1; curr_berries <= max_berries; curr_berries++) {
        // check if it is possible to put curr_berries in every basket for sister
        
        int baskets_filled = 0;
        for (int i = 0; i < berries.size(); i++) {
            baskets_filled += berries[i] / curr_berries;
        }

        if (baskets_filled < baskets_num / 2) {
            // cant fill every basket of sister with that
            // so there's a better solution
            // since the number of berries in bessie's basket is
            // at most curr_berries - 1
            continue;
        }

        if (baskets_filled >= baskets_num) {
            // dont try to add, since we will consider this case later
            max_berries_bessie = max(max_berries_bessie, baskets_num / 2 * curr_berries);
            continue;
        }

        /*
        now since we have only trees with < currberries berries,
        give the leftovers to bessie
        */

        // sort by remainder
        sort(berries.begin(), berries.end(), [&](int a, int b) {
            return a % curr_berries > b % curr_berries;
        });
        int curr_berries_bessie = (baskets_filled - baskets_num / 2) * curr_berries;
        for (int i = 0; i < berries.size() && i + baskets_filled < baskets_num; i++) {
            curr_berries_bessie += berries[i] % curr_berries;
        }

        max_berries_bessie = max(max_berries_bessie, curr_berries_bessie);
    }
    cout << max_berries_bessie << endl;
}