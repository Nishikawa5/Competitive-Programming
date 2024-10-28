#include <stdio.h>
#include <stdlib.h>
 
int max(int a, int b) {
    return (a < b ? b : a);
}

int main() {
    int f1, f2, f3;
    int m;

    scanf("%d %d %d", &m, &f1, &f2);
    f3 = m - f1 - f2;

    printf("%d\n", max(max(f1, f2), f3));
 
    return 0;
}