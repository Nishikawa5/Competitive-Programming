#include <bits/stdc++.h>
using namespace std;

/*
abs(si - si+1) <= m
=>
-m <= si - si+1 <= m
=>
si <= si+1 + m
=> si+1 >= si - m
and
si+1 <= si + m
=> si-1 >= si - m

*/
int main() {
    int n, m;
    cin >> n >> m;

    vector<int> salt(n);
    for (auto &s: salt) {
        cin >> s;
    }

    for (int i = 1; i < n; i++) {
        // salt[i] can't decrease so to make si+1 >= si - m true
        // we have two cases: salt[i] is already bigger and can't decrease
        //                    salt[i] is lower so we add the minimum amount of salt possible (== si-1 - m)
        salt[i] = max(salt[i], salt[i - 1] - m);
    }
    for (int i = n - 2; i >= 0; i--) {
        // same for that, but for si-1 >= si - m
        salt[i] = max(salt[i], salt[i + 1] - m);
    }
    // with that, abs(si - si+1) <= m for every i < n - 1

    for (int i = 0; i < n; i++) {
        cout << salt[i] << " ";
    }
    cout << endl;
}