#include <stdio.h>
#include <stdlib.h>
 
int max(int a, int b) {
    return (a < b ? b : a);
}

int main() {
    int n;
    int a, b;

    char op;

    scanf("%d", &n);
    scanf("%d %c %d", &a, &op, &b);
 
    int res;
    if (op == '+') {
        res = a + b; 
    } else if (op == '*') {
        res = a * b;
    }

    if (res > n) {
        printf("OVERFLOW\n");
    } else {
        printf("OK\n");
    }

    return 0;
}