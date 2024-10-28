#include <bits/stdc++.h>

using namespace std;
#define ull unsigned long
/*
We must have at least two equal length sticks?

2^i + 2^j >= 2^k where k > j >= i is false

a + 2^j >= 2^j
2^j + 2^j >= a

a + 2^j >= 2^(j + 1) <=> a >= 2^j


The only possibilities are:
two equal sides j with the other being j + 1 >= n

ull fact[300000] = {0};

ull factorial2(ull n) {
    if (fact[n] != 0) {
        return fact[n];
    }
    fact[n] = n * factorial2(n - 1);
    return fact[n];
}

ull factorial(ull n) {
    ull res = 1;
    for (ull i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}
*/


ull nchoosek(ull n, ull k) {
    if (k > n) return 0;
    
    if (k == 2) {
        return n * (n - 1) / 2;
    } else if (k == 3) {
        return n * (n - 1) * (n - 2) / 6;
    }
    return 0;
}

int main(void) {
    
    ull t;
    ull n;

    scanf("%lu", &t);

    ull *sticks = (ull *) malloc(sizeof(ull) * 300002);
    ull *prefix = (ull *) malloc(sizeof(ull) * 300001);
    while (t--) {
        scanf("%lu", &n);
        memset(sticks, 0, (n + 1) * sizeof(ull));

        ull temp;
        ull res = 0;
        for (ull i = 0; i < n; i++) {
            scanf("%lu", &temp);
            getchar();
            sticks[temp]++;
        }

        prefix[0] = sticks[0];
        for (ull i = 1; i <= n; i++) {
            prefix[i] = sticks[i] + prefix[i - 1];
        }

        res += nchoosek(sticks[0], 3);
        for (ull i = 1; i <= n; i++) {
            res += nchoosek(sticks[i], 3) + nchoosek(sticks[i], 2) * (prefix[i - 1]);
        }
        printf("%lu\n", res);
    }

}