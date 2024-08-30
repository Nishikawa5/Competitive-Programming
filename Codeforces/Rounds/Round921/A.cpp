#include <bits/stdc++.h>

using namespace std;


int main(void) {
    int t;
    int n, k;
    char alphabet[27] = "abcdefghijklmnopqrstuvwxyz";

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &n, &k);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                printf("%c", alphabet[j]);
            }
        }
        printf("\n");
    }
}