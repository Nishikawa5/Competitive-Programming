#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;


int maxvec(int n, int *v) {
    int maxim = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (v[i] > maxim) {
            maxim = v[i];
        }
    }
    return maxim;
}

int main(void) {
    int t;
    scanf("%d", &t);

    int n;
    int *verticesl = (int *) malloc(sizeof(int) * 100000);
    int *verticesr = (int *) malloc(sizeof(int) * 100000);
    while (t--) {
        scanf("%d", &n);
        memset(verticesl, 0, sizeof(int) * n);
        memset(verticesr, 0, sizeof(int) * n);

        int v1, v2;
        int branches = 1;
        n--;
        while (n--) {
            scanf("%d %d", &v1, &v2);
            verticesl[v1 - 1]++;
            verticesr[v2 - 1]++;

            if (verticesl[v1 - 1] > 1) branches++;
            if (verticesr[v2 - 1] > 1) branches++;
        }
        int temp = max(maxvec(n, verticesl), maxvec(n, verticesr));
        


        printf("%d\n", branches / 2 + branches % 2);
    }
}