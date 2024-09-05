#include <bits/stdc++.h>
using namespace std;

/*
it fails iff
ooo...ooo
or
a...aab...b
greedy: maximize the number of 3 chars subset by putting every available char one by one

~1 hour
hard to understand the solution even reading the edital (to me)

*/
int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        string str;
        cin >> n >> str;

        vector<pair<int, int>> freq(26);
        for (int i = 0; i < 26; i++) {
            freq[i].second = i;
        }

        for (int i = 0; i < n; i++) {
            freq[str[i] - 'a'].first++;
        }

        sort(freq.begin(), freq.end());

        queue<pair<int, int>> iterate;
        for (int i = 0; i < 26; i++) {
            iterate.push(freq[i]);
        }

        while (!iterate.empty()) {
            pair<int, int> curr = iterate.front();
            iterate.pop();

            if (curr.first <= 0) {
                continue;
            }
            putchar('a' + curr.second);
            curr.first--;
            iterate.push(curr);
        }
        cout << endl;
    }
}