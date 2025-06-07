#include <bits/stdc++.h>
using namespace std;


template <typename T>
class MaxSegmentTree {
private:
    const T DEFAULT = std::numeric_limits<T>::lowest();

    vector<T> segtree;
    // we need to pad to a power of two to make get_min_idx work correctly
    int original_len; // user-provided length (e.g., 10)
    int seg_len;      // padded, power-of-two length (e.g., 16)

public:
    MaxSegmentTree(int n) {
        original_len = n;
        // smallest power of 2 < n
        seg_len = 1;
        while (seg_len < original_len) {
            seg_len *= 2;
        }
        // seglen is the new len
        segtree.assign(seg_len * 2, DEFAULT);
    }

    void set(int ind, T val) {
        ind += seg_len;
        segtree[ind] = val;
        for (; ind > 1; ind /= 2) {
            segtree[ind / 2] = std::max(segtree[ind], segtree[ind ^ 1]);
        }
    }

    T get(int ind) {
        return segtree[ind + seg_len];
    }

    T range_max(int start, int end) {
        T maxn = DEFAULT;
        for (start += seg_len, end += seg_len; start < end; start /= 2, end /= 2) {
            if (start % 2 == 1) { maxn = std::max(maxn, segtree[start++]); }
            if (end % 2 == 1) { maxn = std::max(maxn, segtree[--end]); }
        }
        return maxn;
    }

    int get_min_idx(T val) {
        if (segtree[1] < val) {
            return -1;
        }

        int curr_idx = 1;
        while (curr_idx < seg_len) {
            if (segtree[curr_idx * 2] >= val) {
                curr_idx *= 2;
            } else {
                curr_idx = curr_idx * 2 + 1;
            }
        }

        int final_idx = curr_idx - seg_len;
        if (final_idx >= original_len) {
            return -1;
        }

        return final_idx;
    }
};


void solve() {
    int n, m;
    cin >> n >> m;

    // since maxn*m = 4e10 we cant bruteforce, and we can use maxsegtree instead
    MaxSegmentTree<int> max_rooms(n);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        max_rooms.set(i, x);
    }

    while (m--) {
        int rooms;
        cin >> rooms;

        int idx = max_rooms.get_min_idx(rooms);

        if (idx != -1) {
            cout << idx+1 << " ";
            max_rooms.set(idx, max_rooms.get(idx)-rooms);
        } else {
            cout << 0 << " ";
        }
    }

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
