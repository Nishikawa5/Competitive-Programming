#include <bits/stdc++.h>

using namespace std;

/*
Board:
    Word | Word

*/
int main(void) {
    int N;
    vector<int> count(26, 0);

    cin >> N;
    // we just need the maximums of both sides
    while (N--) {
        string l, r;
        cin >> l >> r;

        // maps the number of each letter
        vector<int> countleft(26, 0);
        vector<int> countright(26, 0);
        for (int i = 0; i < l.size(); i++) {
            countleft[l[i] - 'a']++;
        }
        for (int i = 0; i < r.size(); i++) {
            countright[r[i] - 'a']++;
        }

        // add max
        for (int i = 0; i < 26; i++) {
            count[i] += max(countleft[i], countright[i]);
        } 
    }

    for (int i = 0; i < 26; i++) {
        cout << count[i] << endl;
    }
}