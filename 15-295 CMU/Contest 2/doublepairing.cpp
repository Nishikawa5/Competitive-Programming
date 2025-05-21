#include <bits/stdc++.h>
using namespace std;


int last_true(int lo, int hi, function<bool(int)> f) {
    lo--;

    while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;

        if (f(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    return lo;
}


int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto &a: arr) {
        cin >> a;
    }

    sort(arr.begin(), arr.end());

    // from xi
    //    get the number >= 2*xi by binary search
    //    erase this number from arr...
    // wont work, since is O(n**2 * logn)

    // assume we have k pairs
    // if x works => x - 1 works => x - 2 works => ...
    // so we want to find the last k that works

    // without bin search could work with two pointers?
    // search for the first that doubles the first, then just iterate? 
    // i dont think it would work since the double of first could be used as a pair too...

    int num_pairs = last_true(1, n/2, [&](int total_pairs) {
        // try to get every double from 0 to totalpairs
        int idx_biggest_of_smallest = total_pairs - 1;
        
        for (int i = arr.size() - 1; i >= total_pairs && idx_biggest_of_smallest >= 0; i--, idx_biggest_of_smallest--) {
            if (2LL*arr[idx_biggest_of_smallest] > arr[i]) {
                return false;
            }
        }
        return true;
    });

    cout << num_pairs << endl;
}