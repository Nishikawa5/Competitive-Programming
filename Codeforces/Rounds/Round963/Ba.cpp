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
        vector<int> even;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            odd += (1 & x); 
            if (x % 2 == 1) {
                largest_odd = max(largest_odd, x);
            } else {
                even.push_back(x);
            }
        }

        if (odd == 0 || odd == n) {
            // already same
            cout << 0 << endl;
        } else {
            sort(even.begin(), even.end());

            long long int curr_sum = largest_odd; 
            int i = 0;
            while (i < even.size() && even[i] < curr_sum && curr_sum <= 10e9) {
                curr_sum += even[i];
                i++;
            }

            if (i == even.size() || curr_sum > 10e9) {
                cout << n - odd << endl;
            } else {
                cout << n - odd + 1 << endl;
            }
        }
    }
}