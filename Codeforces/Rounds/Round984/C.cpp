#include <bits/stdc++.h>
using namespace std;

void solve() {
    string str;
    cin >> str;

    int q;
    cin >> q;
    // mark the start of str as true if satisfy
    // after changing check if we removed a 1100 by checking the 4 idx before
    // check if we made a 1100 by checking the 4 before and after
    vector<bool> is_sequence(str.size());
    
    int desired_num = 0;
    string desired_str = "1100";
    for (int i = 0; i < str.size(); i++) {
        bool is_desired = true;

        for (int j = i; j < i + desired_str.size(); j++) {
            if (str[j] != desired_str[j - i]) {
                is_desired = false;
                break;
            }
        }

        desired_num += is_desired;
        is_sequence[i] = is_desired;
    }

    while (q--) {
        int pos;
        char bit;
        cin >> pos >> bit;
        pos--;

        str[pos] = bit;

        for (int i = max(pos - 3, 0); i <= pos; i++) {
            if (is_sequence[i]) {
                desired_num--;
                is_sequence[i] = false;
            }
        }

        for (int i = max(pos - 3, 0); i <= pos; i++) {
            bool is_desired = true;

            for (int j = i; j < i + desired_str.size(); j++) {
                if (str[j] != desired_str[j - i]) {
                    is_desired = false;
                    break;
                }
            }

            desired_num += is_desired;
            is_sequence[i] = is_desired;
        }

        if (desired_num > 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
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
