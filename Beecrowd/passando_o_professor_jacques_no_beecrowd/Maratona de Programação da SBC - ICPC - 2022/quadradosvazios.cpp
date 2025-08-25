#include <bits/stdc++.h>
using namespace std;

void solve() {
    // != != !=
    // just use the tiles
    
    // != = =
    // = = !=
    // just use != and try to fill =?
    // is there a case where we use != to fill =?
    // != is bigger => no problem
    // == is bigger => can complete with ==-1 + 1

    // = = =
    // = != =

    // 3 tiles are redundant =>
    int board_size, used, left;
    cin >> board_size >> used >> left;
    
    int right = board_size - (used + left);
    int available = left + right;
    int ans = available;

    set<int> used_tiles;
    used_tiles.insert(used);

    // lets try every 2 combination
    for (int ll = 0; ll <= left; ll++) {
        // verify if we can use this tile
        if (used_tiles.find(ll) != used_tiles.end()) {
            continue;
        }

        // start at 0 for 1 tile possibility at left
        if (ll) {
            used_tiles.insert(ll);
        }
     

        for (int rl = 0; rl <= right; rl++) {
            // verify if we can use this tile
            if (used_tiles.find(rl) != used_tiles.end()) {
                continue;
            }

            // start at 0 for 1 tile possibility at right
            if (rl) {
                used_tiles.insert(rl);
            }

            int curr_available = available - ll - rl;

            int val = -1;
            for (int lr = left-ll; lr >= 0; lr--) {
                // try to find the best tile for this case
                if (used_tiles.find(lr) != used_tiles.end()) {
                    continue;
                }

                // found
                curr_available -= lr;
                used_tiles.insert(lr);
                val = lr;
                break;
            }

            for (int rr = right-rl; rr >= 0; rr--) {
                // try to find the best tile for this case
                if (used_tiles.find(rr) != used_tiles.end()) {
                    continue;
                }

                // found
                curr_available -= rr;
                break;
            }

            ans = min(ans, curr_available);

            if (rl) {
                used_tiles.erase(rl);
            }
            if (val != -1) {
                used_tiles.erase(val);
            }
        }
        
        if (ll) {
            used_tiles.erase(ll);
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 1;

    while (tc--) {
        solve();
    }
    return 0;
}
