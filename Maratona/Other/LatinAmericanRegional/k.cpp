#include <bits/stdc++.h>
using namespace std;

void solve() {
    int kool;
    string bin;
    cin >> kool >> bin;

    // kool == 2 => find the best alternating bin
    // else divide seq by kool
    if (kool == 2) {
        // get the biggest alternating sequence? not enough
        // we can combinate 2 sequences
        // but there are just 2 alternating, check which is
        // smaller

        // 01
        int curr1 = '0';
        int changes1 = 0;
        for (int i = 0; i < bin.size(); i++) {
            if (curr1 != bin[i]) {
                changes1++;
            }

            curr1 = (curr1 == '0' ? '1':'0');
        }

        // 10
        int curr2 = '1';
        int changes2 = 0;
        for (int i = 0; i < bin.size(); i++) {
            if (curr2 != bin[i]) {
                changes2++;
            }

            curr2 = (curr2 == '0' ? '1':'0');
        }

        char start = '0';
        if (changes1 > changes2) {
            start = '1';
        }
        cout << min(changes1, changes2) << " ";
        for (int i = 0; i < bin.size(); i++) {
            cout << start;
            start = (start == '0' ? '1':'0');
        }
        cout << endl;
    } else {
        int start_idx = 0;
        int curr_idx = 0;
        int min_transformations = 0;

        while (curr_idx+1 < bin.size()) {
            start_idx = curr_idx;
            while (curr_idx+1 < bin.size() && bin[curr_idx] == bin[curr_idx+1]) {
                curr_idx++;
            }

            int count = curr_idx - start_idx + 1;

            int div = count / kool;
            int ceil_div = (count + kool - 1) / kool;

            if (ceil_div == div) {
                for (int i = 1; i < div; i++) {
                    bin[start_idx + i * kool - 1] = (bin[start_idx + i * kool - 1] == '0' ? '1':'0');
                }
                bin[start_idx + (div) * kool - 2] = (bin[start_idx + (div) * kool - 2] == '0' ? '1':'0');
            } else {
                for (int i = 1; i <= div; i++) {
                    bin[start_idx + i * kool - 1] = (bin[start_idx + i * kool - 1] == '0' ? '1':'0');
                }
            }
            min_transformations += div;

            curr_idx++;
        }
        cout << min_transformations << " " << bin << endl;
    }
}


int main() {
    solve();
}