#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int sub_as = 0;
    int max_as = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') {
            sub_as++;
        } else {
            if (sub_as >= 2) {
                max_as += sub_as;
            }
            sub_as = 0;
        }
    }
    if (sub_as >= 2) {
        max_as += sub_as;
    }
    cout << max_as << endl;
}