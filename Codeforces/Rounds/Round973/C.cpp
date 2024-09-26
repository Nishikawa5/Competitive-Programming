#include <bits/stdc++.h>
using namespace std;

void check_right(string &check, char bit) {
    cout << "? " << check << bit << endl;
}

void check_left(string &check, char bit) {
    cout << "? " << bit << check << endl;
}

bool get_ans() {
    bool ans;
    cin >> ans;
    return ans;
}

void print_ans(string &ans) {
    cout << "! " << ans << endl;
}

void solve() {
    int n;
    cin >> n;

    // keep adding 0 or 1 to the right, if it fails we add to the left
    string ans;
    check_right(ans, '0');
    if (get_ans()) {
        ans.push_back('0');
    } else {
        // all of ones
        cout << "! ";
        for (int i = 0; i < n; i++) {
            cout << "1";
        }
        cout << "\n";
        return;
    }

    if (ans.size() == n) {
        print_ans(ans);
        return;
    }

    bool right;
    do {
        right = false;
        check_right(ans, '0');
        if (get_ans()) {
            ans.push_back('0');
            right = true;
        } else {
            check_right(ans, '1');
            if (get_ans()) {
                ans.push_back('1');
                right = true;
            }
        }
    } while (right && ans.size() < n);

    while (ans.size() < n) {
        check_left(ans, '0');
        if (get_ans()) {
            ans.insert(0, 1, '0');
        } else {
            ans.insert(0, 1, '1');
        }
    }
    print_ans(ans);
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
}