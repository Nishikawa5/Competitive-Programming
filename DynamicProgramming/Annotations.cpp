#include <bits/stdc++.h>

using namespace std;

void printTable(int n, int i) {
    if (i > 10) return;
    printf("%d * %d = %d\n", n, i, (n * i));

    printTable(n, i + 1);
}

#define N 1000
// fib with memo
int memo[N] = {0};

int fib(int n) {
    if (memo[n] != 0) return memo[n];

    if (n == 1 || n == 2) memo[n] = 1;
    else memo[n] = fib(n - 1) + fib(n - 2);

    return memo[n];
}

int main(void) {
    printTable(9, 1);

}