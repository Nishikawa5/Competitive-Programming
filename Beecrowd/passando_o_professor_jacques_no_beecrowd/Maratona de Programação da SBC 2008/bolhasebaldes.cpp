#include <iostream>
#include <vector>
using namespace std;

/*
also could solve it with merge sort (already solved it in some of cp4 files)
*/

void solve(const vector<int>& arr) {
    int n = arr.size();
    vector<int> fenwick_tree(n + 1, 0);
    long long inversions = 0;

    for (int i = 0; i < n; i++) {
        int current_num = arr[i];
        
        // smaller elements before curr num
        int smaller_count = 0;
        for (int j = current_num - 1; j > 0; j -= j & (-j)) {
            smaller_count += fenwick_tree[j];
        }
        
        // at this idx i, we have smallercount numbers smaller than arr[i]
        // we need to invert the bigger numbers, so we invert i - smallercount numbers
        inversions += i - smaller_count;
        
        // update fw tree
        for (int j = current_num; j <= n; j += j & (-j)) {
            fenwick_tree[j]++;
        }
    }

    cout << ((inversions % 2 == 1) ? "Marcelo" : "Carlos") << endl;
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<int> arr(n);
        
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        solve(arr);
    }
    
    return 0;
}