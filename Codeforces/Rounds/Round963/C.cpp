#include <bits/stdc++.h>
using namespace std;

/*
The answer must be in [an, an + 2k) interval since all of the lights
have the same period, so we will have the same thing in every 2k

Now to check if we have all on we can make a prefix sum
*/
int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int n, k;
        cin >> n >> k;

        vector<int> start(n);
        for (auto& s: start) {
            cin >> s;
        }
        sort(start.begin(), start.end());

        // put everything 1 period before greatest start
        for (int i = 0; i < n - 1; i++) {
            int difference = start[start.size() - 1] - start[i];
            int periods = floor(difference / ((double) (k)));
            start[i] += (periods + (periods % 2)) * k;  
        }

        // calculate the prefix
        vector<int> prefix(k + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[max(start[i], start.back()) - start.back()]++;
            prefix[min(start[i] + k, start.back() + k) - start.back()]--;
        }
        int max_lights = -1;
        for (int i = 0; i <= k; i++) {
            if (i != 0) {
                prefix[i] += prefix[i - 1];
            }
            if (prefix[i] == n) {
                max_lights = i + start.back();
                break;
            }
        }
        cout << max_lights << endl;
    }
    
}