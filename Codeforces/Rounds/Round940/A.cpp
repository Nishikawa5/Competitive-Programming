#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int tc;
    int sticks;
    int slen;

    scanf("%d", &tc);

    while (tc--) {
        scanf("%d", &sticks);

        int leng[101];
        memset(leng, 0, sizeof(leng));
        int temp;
        while (sticks--) {
            scanf("%d", &temp);

            leng[temp]++;
        }

        int total = 0;
        for (int i = 1; i < 101; i++) {
            total += leng[i] / 3;
        }
        printf("%d\n", total);
    }
}