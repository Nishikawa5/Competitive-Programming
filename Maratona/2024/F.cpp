#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    // a/b
    // a_0 = 1
    // b_0 = 2
    // a_i = b_i-1
    // b_i = a_i-1 + b_i-1

    int a = 1;
    int b = 2;

    n--;
    while (n--) {
        int temp = b;
        b = a + b;
        a = temp;
    }
    cout << a << endl;
}