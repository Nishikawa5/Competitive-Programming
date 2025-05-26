#include <bits/stdc++.h>
using namespace std;

void solve() {
    int strsize, pairs;
    cin >> strsize >> pairs;
    string bitstr;
    cin >> bitstr;

    // we cant have just -1
    vector<int> arrangements(4);
    for (int i = 0; i < strsize/2; i++) {
        if (bitstr[i] == '0' && bitstr[strsize-1-i] == '0') {
            arrangements[0]++;
        } else if (bitstr[i] == '0' && bitstr[strsize-1-i] == '1') {
            arrangements[1]++;    
        } else if (bitstr[i] == '1' && bitstr[strsize-1-i] == '0') {
            arrangements[2]++;
        } else if (bitstr[i] == '1' && bitstr[strsize-1-i] == '1') {
            arrangements[3]++;
        }
    }

    int curr_pairs = arrangements[0] + arrangements[3];

    if (curr_pairs > pairs && (curr_pairs % 2) == (pairs % 2)) {
        curr_pairs -= 2*min(arrangements[0], arrangements[3]); 

        if (curr_pairs <= pairs) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        
    } else if (curr_pairs < pairs && (curr_pairs % 2) == (pairs % 2)) {
        curr_pairs += 2*((arrangements[1] + arrangements[2])/2); 

        if (curr_pairs >= pairs) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

    } else if (curr_pairs == pairs) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
    return 0;
}
