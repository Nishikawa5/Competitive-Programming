#include <bits/stdc++.h>
using namespace std;

int divisors(int x) {
    int result = 1;
    for (int i = 2; i * i <= x; i++) {
        int curr_rst = 0;
        while (!(x % i)) {
            curr_rst += result;
            x /= i;
        }
        result += curr_rst;
    }
    if (x > 1) {
        result += result;
    }
    return result;
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        int x;
        cin >> x;

        cout << divisors(x) << endl;
    }
}