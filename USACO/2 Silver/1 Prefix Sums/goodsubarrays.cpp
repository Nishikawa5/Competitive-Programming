#include <bits/stdc++.h>
using namespace std;

/*
sum = length
=>
sum - length = 0
=>
al + a_l+1 + ... + a_r + r - l = 0
=>
prefix_r - prefix_left + r - l = 0
=>
prefix_r + r = prefix_left + l
now that is a two sum problem 
*/
int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;
        string digits;
        cin >> digits;

        unordered_map<int, int> prefixes;
        prefixes[0]++;

        int prefix = 0;
        long long int good_subarrays = 0;
        for (int i = 0; i < n; i++) {
            int a_i = digits[i] - '0'; 

            prefix += a_i;
            good_subarrays += prefixes[prefix - i - 1]++;
        }
        cout << good_subarrays << endl;
    }

}