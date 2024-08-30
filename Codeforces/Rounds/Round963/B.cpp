#include <bits/stdc++.h>
using namespace std;

/*
even + even = even
odd + odd = even

odd + even = odd
*/
int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;

        int odd = 0;
        int largest_odd = 0;
        // get the largest_even before the largest_odd somehow
        vector<int> arr(n);
        for (int &x: arr) {
            cin >> x;
            odd += (1 & x); 
            if (x % 2 == 1) {
                largest_odd = max(largest_odd, x);
            }
        }
        sort(arr.begin(), arr.end());

        int i = 0;
        long long int even_sum_before_lo = 0;
        while (i < n && arr[i] < largest_odd && even_sum_before_lo <= 10e9) {
            if (arr[i] % 2 == 0) {
                even_sum_before_lo += arr[i];
            }
            i++;
        }


        if (odd == 0 || odd == n) {
            // already same
            cout << 0 << endl;
        } else {
            // if we have a number that is bigger than the odd: n - odd + 1
            // else: n - odd
            if (largest_odd + even_sum_before_lo > arr[n - 1]) {
                cout << n - odd << endl;
            } else {
                cout << n - odd + 1 << endl;
            }
        }
    }
}