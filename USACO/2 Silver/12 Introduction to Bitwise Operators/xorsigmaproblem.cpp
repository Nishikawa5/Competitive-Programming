#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int &a : v) { cin >> a; }

    long long ans = 0;

    /*
    count the number of subsequences where xor == 1
    example:
    i-th bit of every a
    1 0 0 0 1 0 0 0 1
    1 2 3 4 4 4 4 4 5

    5 4 4 4 4 1 1 1 1

    so we have 25 subseq where xor == 1
    5 ways of xor == 1
    ...

    */

    for (int i = 0; i < 32; i++) {

        int xoreq1 = 0;

        int curr_bit = 0;
        for (int a: v) {
            if ((a >> i) & 1) {
                curr_bit = !curr_bit;
            }

            // count the number of xor that results in one of every subsequence
            // (from the most left to the most right)
            if (curr_bit == 1) {
                xoreq1++;
            }
        }

        for (int j = 0; j < v.size(); j++) {
            ans += 1LL * xoreq1 << i;

            if ((v[j] >> i) & 1) {
                // invert the bits.
                // we found a 1 so we invert every xor
                // so now we have xoreq1 = n - j - xoreq1
                // -j to not count the subsequences again
                xoreq1 = n - j - xoreq1;
            }
        }
    }

    // - accumulate since it's counting the subsequences of 1 element and the problem dont count that
	cout << ans - accumulate(v.begin(), v.end(), 0LL) << endl;
}
