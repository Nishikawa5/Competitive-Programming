#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long tosses_num;
    cin >> tosses_num;

    // maximize the number of ways we can make
    // the number of repeating 0's or 1's for the same
    // idx 
    
    // lets see some cases
    // 0 / 1, not possible
    // 01 / 10     00 and 11 discarded
    // 010, 110 / 001, 011          the rest discarded
    // other way for 3?

    // we must have the same number of combinations which sums
    // to k zeros, since the coin may be bended
    // so

    // n choose k: how many strings can we create
    // with k zeros
    // if it is even, strings can be evenly distributed
    // if it is odd, we must discard one
    // how to count it efficientily?
    // n choose k is odd iff for every bit pos

    // n choose k is odd iff k fits n
    // by lucas theorem
    // (m  n)  =  PIk (mi  ni)    (mod p)
    // p == 2 
    // the above eq will be a product of 1's and 0's
    // lets say (0  1): 0 by convention
    // (0  0) , (1  1) , (1  0): 1
    // but we cant just  N & k == k
    // since that is O(N) and max(N) == 1e18
    
    // a way to count it is by creating k
    // if the bit in N is 0, this index in k must be 0 (1 possibility)
    // if the bit in N is 1, this index in k can be 0 or 1
    // so we multiply the possibilities of k by 2

    // start at 1 for counting *= 2
    // N == 0 is not possible
    long long ans = 1;

    while (tosses_num) {
        if (tosses_num & 1) {
            ans *= 2;
        }

        tosses_num >>= 1;
    }
    cout << ans << endl;
}

int main() {
    solve();
}