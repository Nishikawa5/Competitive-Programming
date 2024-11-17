#include <bits/stdc++.h>
using namespace std;

/*
get the value corresponding to str2 (every combination)
-> use this value as mod to calculate the rest of str1

str1 divide str2 <=> rest == 0
*/
void solve() {
    string dividend;
    string divisor;
    cin >> dividend >> divisor;

    vector<int> ast_pos;
    int ast_num_dividend = 0;
    for (int i = 0; i < dividend.size(); i++) {
        if (dividend[i] == '*') {
            ast_pos.push_back(i);
            ast_num_dividend++;
        }
    }

    int ast_num_divisor = 0;
    for (int i = 0; i < divisor.size(); i++) {
        if (divisor[i] == '*') {
            ast_pos.push_back(i);
            ast_num_divisor++;
        }
    }
    
    // every combination of asterisks
    for (int combination = 0; combination < (1 << ast_pos.size()); combination++) {
        // substitute the asterisks according to this
        // combination
        for (int j = 0; j < ast_pos.size(); j++) {
            char curr_bit = ((combination >> j) & 1) ? '1':'0';
            if (j < ast_num_dividend) {
                // substitute dividend
                dividend[ast_pos[j]] = curr_bit;
            } else {
                // substitute divisor
                divisor[ast_pos[j]] = curr_bit;
            }
        }
        // assume we have this dividend and divisor

        // divisor -> int
        int modulo = 0;
        for (int i = 0; i < divisor.size(); i++) {
            modulo = modulo * 2 + divisor[i] - '0';
        }

        int rest = 0;
        for (int i = 0; i < dividend.size(); i++) {
            rest = rest * 2 + dividend[i] - '0';
            rest %= modulo;
        }

        if (rest == 0) {
            cout << dividend << endl;
            return;
        }
    }
}

int main() {
    int tc = 1;

    while (tc--) {
        solve();
    }
}