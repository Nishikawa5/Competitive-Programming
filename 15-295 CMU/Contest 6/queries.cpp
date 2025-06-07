#include <bits/stdc++.h>
using namespace std;

// T is a class placeholder
template <typename T> class SumSegmentTree {
private:
    const T DEFAULT = 0;

    vector<T> segtree;
    int len;

public:
    SumSegmentTree(int len) : len(len), segtree(len * 2, DEFAULT) {}

    void set(int ind, T val) {
        ind += len;
        segtree[ind] = val;
        for (; ind > 1; ind /= 2) {
            segtree[ind / 2] = (segtree[ind] + segtree[ind ^ 1]);
        }
    }

    T range_sum(int start, int end) {
        T sum = DEFAULT;
        for (start += len, end += len; start < end; start /= 2, end /= 2) {
            if (start % 2 == 1) { sum += segtree[start++]; }
            if (end % 2 == 1) { sum += segtree[--end]; }
        }
        return sum;
    }
};



void solve() {
    int n, queries;
    cin >> n >> queries;

    SumSegmentTree<long long> segtree(n);
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;

        segtree.set(i, x);
    }

    while (queries--) {
        int query_type, v1, v2;
        cin >> query_type >> v1 >> v2;

        if (query_type == 1) {
            segtree.set(v1-1, v2);
        } else if (query_type == 2) {
            cout << segtree.range_sum(v1-1, v2) << endl;
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
