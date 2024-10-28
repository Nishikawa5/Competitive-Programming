#include <stdio.h>
#include <stdlib.h>
 
int main() {
    int n;
    scanf("%d", &n);

    char *str = (char *)malloc(sizeof(char) * 21);
    for (int i = 0; i < n; i++) {
        scanf("%s", str);

        if (i) {
            printf(" ");
        }
        if (str[0] == 'O' && str[1] == 'B' && str[3] == '\0') {
            printf("OBI");
        } else if (str[0] == 'U' && str[1] == 'R' && str[3] == '\0') {
            printf("URI");
        } else {
            printf("%s", str);
        }
    }
    printf("\n");
 
    return 0;
}