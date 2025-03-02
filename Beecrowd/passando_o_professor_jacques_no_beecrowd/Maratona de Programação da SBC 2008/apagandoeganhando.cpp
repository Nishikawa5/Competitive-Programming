#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int digits_num, erase_num;

    while (cin >> digits_num >> erase_num && (digits_num || erase_num)) {
        string digits;
        cin >> digits;

        
        vector<char> stack;
        /*
        try to make the greatest digit first
        */

        // within the erase limit, what is the greatest digit we can put first? then second and so on...
        int erased = 0;

        for (int i = 0; i < digits_num; i++) {
            // lets kinda sort our digits in order, if we find a greater char, go back
            
            while (erased < erase_num && !stack.empty() && stack.back() < digits[i]) {
                erased++;
                stack.pop_back();
            }

            stack.push_back(digits[i]);
        }

        while (erased < erase_num && !stack.empty()) {
            stack.pop_back();
            erased++;
        }

        string ans(stack.begin(), stack.end());
        cout << ans << endl;
    }
    return 0;
}