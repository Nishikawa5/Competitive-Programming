#include <stdio.h>
#include <stdlib.h>
 
int max(int a, int b) {
    return (a < b ? b : a);
}

void rec(int n, char *hexa) {
    if (n == 0) {
        return;
    }
    rec(n >> 4, hexa);
    printf("%c", hexa[n & 0xF]);
}


int main() {
    int n;
    scanf("%d", &n);

    char *hexa = (char *)malloc(sizeof(char) * 16);
    int curr_element = 0;
    for (int i = '0'; i <= '9'; i++) {
        hexa[curr_element++] = i;
    }
    for (int i = 'A'; i <= 'F'; i++) {
        hexa[curr_element++] = i;
    }

    rec(n, hexa);
    printf("\n");

    return 0;
}