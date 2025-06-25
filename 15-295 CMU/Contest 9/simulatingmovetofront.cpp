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
    int n, m;
    cin >> n >> m;


    // we can use a sumsegtree(n+m) to where the numbers are
    // and we can get the idx of the numbers by queries
    // and an array of locations of the numbers
    vector<int> locations(n);
    SumSegmentTree<int> segtree(n+m);
    // the first m's will be used to store the result of requests

    for (int i = 0; i < n; i++) {
        locations[i] = m + i;
        segtree.set(m + i, 1);
    }

    for (int curr_seg = m-1; curr_seg >= 0; curr_seg--) {
        int move_num;
        cin >> move_num;

        // we move the move_num to the front, which is located at
        int seg_idx = locations[move_num];
        // at segtree
        // so to get the idx of it, sum every position before it
        int idx = segtree.range_sum(0, seg_idx);
        // and move it
        locations[move_num] = curr_seg;
        segtree.set(seg_idx, 0);
        segtree.set(curr_seg, 1);

        cout << idx-1 << " ";
    }
    cout << endl;
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
