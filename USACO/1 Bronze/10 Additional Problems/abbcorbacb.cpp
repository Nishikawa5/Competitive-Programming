#include <bits/stdc++.h>
using namespace std;

void solve() {
    // from left to right ba transformation is always the best?
    string str;
    cin >> str;

    // larga escala

    // theres a b => count all a's in the sequence
    // A A ... A B A ... A, which side will use this B?
    // what if A A A B A A A ... A B, so we need info about other B's

    // to simplify that lets make a vector separated by b's
    vector<int> count_a;

    int a = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'A') {
            a++;
        } else {
            count_a.push_back(a);
            a = 0;
        }
    }
    count_a.push_back(a);
    sort(count_a.begin(), count_a.end());
    
    // we can get str.size()-1 elements, since there are str.size()-1 b's and 
    // since we have b's on both sides of a's sequence we can select any sequence of a's
    // so just sort and sum it to get the most amount of coins
    int ans = 0;
    for (int i = 1; i < count_a.size(); i++) {
        ans += count_a[i];
    }
    cout << ans << endl;
}

int main() {
    int tc;
    cin >> tc;

    while(tc--) {
        solve();
    }
}