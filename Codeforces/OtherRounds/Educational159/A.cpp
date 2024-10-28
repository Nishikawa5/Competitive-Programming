#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    int t;
    char *s = (char *) malloc(sizeof(char) * 101);

    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);
        getchar();
        scanf("%s", s);
        getchar();

        int zeros = 0;
        bool onezero = false;
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] == '0' && s[i + 1] == '0' && i != n - 1) onezero = true;
            if (s[i] != s[i + 1]) {
                if (s[i] == '1') onezero = true;
                else zeros += n - i - 1;
            }
            if (s[i] == '0') zeros++;
        }
        if (s[n - 1] == '0') zeros++;

        if (zeros * 2 > n || onezero) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}