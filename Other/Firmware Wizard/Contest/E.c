#include <stdio.h>
#include <stdlib.h>
 
int max(int a, int b) {
    return (a < b ? b : a);
}


int main() {
    int n;
    scanf("%d", &n);

    int multiplos[4] = {0, 0, 0, 0};
    int divisores[4] = {2, 3, 4, 5};

    int curr_num;
    for (int i = 0; i < n; i++) {
        scanf("%d", &curr_num);

        for (int j = 0; j < 4; j++) {
            if (curr_num % divisores[j] == 0) {
                multiplos[j]++;
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        printf("%d Multiplo(s) de %d\n", multiplos[i], divisores[i]);
    }

    return 0;
}