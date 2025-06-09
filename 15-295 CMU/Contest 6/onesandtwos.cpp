#include <bits/stdc++.h>
using namespace std;

template <class T> class SumSegmentTree {

  private:

	const T DEFAULT = 0;
	int len;
	vector<T> segtree;

	T combine(const T &a, const T &b) { return a + b; }


    // [at left, at right]
    // by at*2 we go to the left, so the new range is 
    // [at left, mid]

    // by at*2+1 we go to the right, so the new range is 
    // [mid+1, at right]
	void build(const vector<T> &arr, int at, int at_left, int at_right) {

		if (at_left == at_right) {
			segtree[at] = arr[at_left];
			return;
		}

		int mid = (at_left + at_right) / 2;

        build(arr, 2 * at, at_left, mid);
		build(arr, 2 * at + 1, mid + 1, at_right);

        segtree[at] = combine(segtree[2 * at], segtree[2 * at + 1]);
	}


	void set(int ind, T val, int at, int at_left, int at_right) {

		if (at_left == at_right) {
			segtree[at] = val;
			return;
		}

		int mid = (at_left + at_right) / 2;

		if (ind <= mid) {
			set(ind, val, 2 * at, at_left, mid);
		} else {
			set(ind, val, 2 * at + 1, mid + 1, at_right);
		}

		segtree[at] = combine(segtree[2 * at], segtree[2 * at + 1]);
	}

    T get(int ind, int at, int at_left, int at_right) {

        if (at_left == at_right) {
            return segtree[at];
        }

        int mid = at_left + (at_right - at_left) / 2;

        if (ind <= mid) {
            return get(ind, 2 * at, at_left, mid);
        } else {
            return get(ind, 2 * at + 1, mid + 1, at_right);
        }
    }


	T range_sum(int start, int end, int at, int at_left, int at_right) {
		if (at_right < start || end < at_left) { return DEFAULT; }
		if (start <= at_left && at_right <= end) { return segtree[at]; }

		int mid = (at_left + at_right) / 2;

		T left_res = range_sum(start, end, 2 * at, at_left, mid);
		T right_res = range_sum(start, end, 2 * at + 1, mid + 1, at_right);

        return combine(left_res, right_res);
	}


  public:
	SumSegmentTree(int len) : len(len) { segtree = vector<T>(len * 4, DEFAULT); };

	SumSegmentTree(const vector<T> &arr) : len(arr.size()) {
		segtree = vector<T>(len * 4, DEFAULT);
		build(arr, 1, 0, len - 1);
	}


	void set(int ind, T val) { 
        // at 1 since we start at the root
        set(ind, val, 1, 0, len - 1); 
    }

    T get(int ind) {
        return get(ind, 1, 0, len-1);
    }

	T range_sum(int start, int end) { return range_sum(start, end, 1, 0, len - 1); }
};

void solve() {
    int n, q;
    cin >> n >> q;

    SumSegmentTree<int> sums(n);
    set<int> ones_idx;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        sums.set(i, x);
        if (x == 1) {
            ones_idx.insert(i);
        }
    }

    while (q--) {
        int op;
        cin >> op;

        if (op == 1) {
            int target;
            cin >> target;
            
            int range_sum = 0;
            // we need to check 3 ranges:
            
            if (!ones_idx.empty()) {
                // from leftmost 1 to right >= target
                range_sum = sums.range_sum(*ones_idx.begin(), n-1);
                if (range_sum >= target) {
                    cout << "YES\n";
                    continue;
                }

                // from rightmost 1 to left >= target
                range_sum = sums.range_sum(0, *ones_idx.rbegin());
                if (range_sum >= target) {
                    cout << "YES\n";
                    continue;
                }
            }

            // full range >= target && same parity
            range_sum = sums.range_sum(0, n-1);
            if (range_sum >= target && ((range_sum % 2) == (target % 2))) {
                cout << "YES\n";
                continue;
            }

            cout << "NO\n";
        } else if (op == 2) {
            int idx, val;
            cin >> idx >> val;
            idx--;

            if (sums.get(idx) == 1 && val == 2) {
                ones_idx.erase(idx);
            }
            if (val == 1) {
                ones_idx.insert(idx);
            }
            sums.set(idx, val);
        }
    }
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
}