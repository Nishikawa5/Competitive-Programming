#include <bits/stdc++.h>

using namespace std;

int highestOneBit(int i) {
    i |= (i >>  1);
    i |= (i >>  2);
    i |= (i >>  4);
    i |= (i >>  8);
    i |= (i >> 16);
    return i - (i >> 1);
}

int main(void) {
    int tc;

    cin >> tc;

    while (tc--) {
        int n;
        int k;

        scanf("%d %d", &n, &k);

        if (n == 1) {
            printf("%d\n", k);
        } else {
            // 2^x <= k < 2^(x + 1)
            // => can't have more than x + 1 bits

            // 2^x - 1 (x bits set)
            int msb = highestOneBit(k);

            printf("%d", msb - 1);
            printf(" %d", k - (msb - 1));
            for (int i = 2; i < n; i++) {
                printf(" 0");
            }
            printf("\n");
        }
    }
}