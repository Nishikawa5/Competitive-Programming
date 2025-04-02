#include <bits/stdc++.h>
using namespace std;

int main() {
    int cache_size;
    int diff_obj;
    int accesses;

    cin >> cache_size >> diff_obj >> accesses;

    vector<int> access_order(accesses);
    for (auto &a: access_order) {
        cin >> a;
    }

    vector<int> last_seen(diff_obj, INT_MAX);    
    vector<int> next_idx_of_obj(accesses);

    for (int i = accesses - 1; i >= 0; i--) {
        next_idx_of_obj[i] = last_seen[access_order[i]];
        last_seen[access_order[i]] = i;
    }

    // cache of idx
    set<int> cache;

    int insertions = 0;
    for (int i = 0; i < accesses; i++) {
        if (!cache.count(i)) {
            // insert this object to the cache
            if (cache.size() >= cache_size) {
                // erase the farthest object
                cache.erase(*(cache.rbegin()));
            }
            insertions++;
        } else {
            // but wont be used anymore. We can keep it or erase
            cache.erase(i);
        }
        // keep it just if it will be accessed again
        // (we are counting just the number of reads, so we can just erase if needed
        // else we wont have this if)
        if (next_idx_of_obj[i] < accesses) {
            cache.insert(next_idx_of_obj[i]);
        }
    }
    cout << insertions << endl;
}