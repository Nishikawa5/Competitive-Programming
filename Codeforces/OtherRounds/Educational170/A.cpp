#include <bits/stdc++.h>
using namespace std;

void solve() {
    // input first equal substring
    // paste
    // + the rest

    string str1, str2;
    cin >> str1 >> str2;

    int i = 0;
    while (i < str1.size() && i < str2.size() && str1[i] == str2[i]) {
        i++;
    }

    // dont have to input i letters, but it cost 1
    int ans;
    if (i) {
        ans = str1.size() + str2.size() - i + 1;
    } else {
        ans = str1.size() + str2.size();
    }
    cout << ans << endl;
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
}
