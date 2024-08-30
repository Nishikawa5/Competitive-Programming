#include <bits/stdc++.h>
using namespace std;

// n / m
int main() {
    string n, m;
    cin >> n >> m;

    if (n == "0") {
        cout << 0 << endl;
        return 0;
    }

    while (n.back() == '0' && m.back() == '0') {
        n.pop_back();
        m.pop_back();
    }

    if (m.size() > n.size()) {
        // print the number < 1
        cout << "0.";
        for (int i = 0; i < m.size() - n.size() - 1; i++) {
            cout << 0;
        }
        cout << n << endl;
    } else {
        if (m.size() != 1) {
            n.insert(n.end() - (m.size() - 1), '.');
        }
        cout << n << endl;
    }
}