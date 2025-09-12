#include <bits/stdc++.h>
using namespace std;

int main() {
    string dividend, divisor;
    cin >> dividend >> divisor;

    // try every combination of *
    int num_dividend = 0;
    int num_divisor = 0;
    
    vector<int> idxs;
    for (int i = 0; i < dividend.size(); i++) {
        if (dividend[i] == '*') {
            num_dividend++;
            idxs.push_back(i);
        }
    }
    for (int i = 0; i < divisor.size(); i++) {
        if (divisor[i] == '*') {
            num_divisor++;
            idxs.push_back(i);
        }
    }

    for (int combination = 0; combination < (1 << idxs.size()); combination++) {

        for (int i = 0; i < idxs.size(); i++) {
            char substitute = ((combination >> i) & 1) == 1 ? '1':'0';
            if (num_dividend > i) {
                dividend[idxs[i]] = substitute;
            } else {
                divisor[idxs[i]] = substitute;
            }
        }

        // divisor -> int
        int int_divisor = 0;
        for (int i = 0; i < divisor.size(); i++) {
            int_divisor = int_divisor * 2 + (divisor[i] - '0');
        }

        // lets check if this divisor divides dividend
        int remainder = 0;
        for (int i = 0; i < dividend.size(); i++) {
            remainder = remainder * 2 + dividend[i] - '0';
            remainder %= int_divisor;
        }

        if (remainder == 0) {
            cout << dividend << endl;
            return 0;
        }
    }
}