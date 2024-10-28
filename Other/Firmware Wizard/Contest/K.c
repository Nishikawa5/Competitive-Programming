#include <stdio.h>
#include <stdlib.h>
 
int max(int a, int b) {
    return (a < b ? b : a);
}


int main() {
    int n;

    unsigned long long mod = 1e9 + 7;

    while (scanf("%d", &n) != EOF) {        
        unsigned long long *jutsus = (unsigned long long *)malloc(sizeof(unsigned long long) * n);

        for (int i = 0; i < n; i++) {
            scanf("%llu", &jutsus[i]);
        }

        unsigned long long attack = 0;
        for (int i = 0; i < n; i++) {
            unsigned long long curr_secret = 0;
            for (int j = i; j < n; j++) {
                curr_secret ^= jutsus[j];

                attack += curr_secret % mod;
                attack %= mod;
            }
        }
        printf("%llu\n", attack);
    }

    return 0;
}