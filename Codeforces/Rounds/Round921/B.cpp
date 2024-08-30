#include <bits/stdc++.h>

using namespace std;

/*
problem with n subproblems
with difficulty sum equal to x

balance GCD of the difficulties

want to find the maximum balance of

n1 + n2 + ... + nn = x
max(gcd(n1, n2, ..., nn));
*/
int main(void) {
    int t;
    int x, n;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &x, &n);

        int div = x / n;
        int rem = x % n;

        while (rem % div) {
            div -= 1;
            rem += n;
        }
        printf("%d\n", div);
    }
}