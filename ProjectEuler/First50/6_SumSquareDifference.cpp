#include <bits/stdc++.h>

using namespace std;

int main(void) {
    // (1 + 2 + ... + N)^2 - (1^2 + 2^2 + ... + N^2) = (2 + 3 + ... + N) + 2*(1 + 2 + ... + N) + ...
    long N = 10000;

    long sum1toN = (N*(N + 1)) / 2;

    long ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += i * (sum1toN - i);
    }
    cout << ans << endl;
} 