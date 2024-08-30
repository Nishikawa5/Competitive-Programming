#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
string s with n lowercase letters

*/

int main(void) {
    int t;
    int n;
    int map[26];
    scanf("%d", &t);

    while (t--) {
        memset(map, 0, sizeof(map));
        scanf("%d", &n);
        getchar();
        for (int i = 0; i < n; i++) {
            map[getchar() - 'a']++;
        }

        int max = 0;
        for (int i = 0; i < 26; i++) {
            if (max < map[i]) {
                max = map[i];
            }
        }

        if (max > (n - max)) printf("%d\n", max - (n - max));
        else printf("%d\n", n % 2);
    }
}