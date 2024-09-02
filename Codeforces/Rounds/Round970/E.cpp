#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        string str;
        cin >> n >> str;

        if (n % 2 == 0) {
            vector<int> count[2] = {vector<int>(26, 0), vector<int>(26, 0)};

            int maxeo[2] = {0};
            for (int i = 0; i < n; i++) {
                count[i % 2][str[i] - 'a']++;
                maxeo[i % 2] = max(maxeo[i % 2], count[i % 2][str[i] - 'a']);
            }
            cout << n - maxeo[0] - maxeo[1] << endl;
        } else {
            vector<int> prefix_even_odd[2] = {vector<int>(26, 0), vector<int>(26, 0)};
            vector<int> suffix_even_odd[2] = {vector<int>(26, 0), vector<int>(26, 0)};
            int ans = n;

            for (int i = 0; i < n; i++) {
                suffix_even_odd[i % 2][str[i] - 'a']++;
            }
            
            for (int i = 0; i < n; i++) {
                // we choose the i-th to remove
                suffix_even_odd[i % 2][str[i] - 'a']--;

                int curr_best = n;
                for (int k = 0; k < 2; k++) {
                    int max_letter = 0;
                    for (int j = 0; j < 26; j++) {
                        // search for the best even/odd letter
                        // since we are removing i-th, change everything after i and maintain before
                        // for suffix evens are odds and odds are even
                        max_letter = max(max_letter, prefix_even_odd[k][j] + suffix_even_odd[1 - k][j]);
                    }
                    curr_best -= max_letter;
                }
                prefix_even_odd[i % 2][str[i] - 'a']++;
                ans = min(ans, curr_best);
            }
            cout << ans << endl;
        }
    }
}