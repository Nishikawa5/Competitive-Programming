#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define lli long long int

/*
have an array A
insert a_n+1
choose an x to make every element of array equal

get the max
get the gcd of every difference (that is x)


*/

long long int gcd(long long int a, long long int b) {
    long long int r = a % b;
    if (r == 0) return b;
    return gcd(b, r);
}

int main(void) {
    int t;
    int n;
    lli *arr = (lli *) malloc(sizeof(lli) * 200000);
    lli *diff = (lli *) malloc(sizeof(lli) * 200000);
    lli x;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        long long int temp;
        lli maximum = LONG_LONG_MIN;
        for (int i = 0; i < n; i++) {
            scanf("%lli", &temp);
            if (maximum < temp) maximum = temp;
            arr[i] = temp;
        }

        for (int i = 0; i < n; i++) {
            diff[i] = maximum - arr[i];
        }

        x = diff[0];
        for (int i = 1; i < n; i++) {
            x = gcd(x, diff[i]);
        }
        printf("test");
        int op = 0;
        for (int i = 0; i < n; i++) {
            while (arr[i] < maximum) {
                arr[i] += x;
                op++;
            }
        }


    }
}