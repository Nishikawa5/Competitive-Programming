#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string seq;

    cin >> n >> seq;

    int count = 0;
    int rst = 0;    
    for (int i = 0; i <= n; i++) {
        count += seq[i] == 'a';
        if (seq[i] != 'a') {
            if (count > 1) {
                rst += count;
            }
            count = 0;
        }
    }
    cout << rst << endl;
}