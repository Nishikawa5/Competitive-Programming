#include <stdio.h>
#include <stdlib.h>

/* Easy to implement and understand
could have an error with '?'
a+b=c
a-b=c
we can use %c to get either + or -
*/
int homeworkchecker(void) {
    short int a, b, c;
    char sign;
    unsigned short ans = 0;
    
    while (scanf("%hd%c%hd=%hd", &a, &sign, &b, &c) != EOF) {
        if (sign == '+' && a + b == c) {
            ans++;
        } else if (a - b == c) {
            ans++;
        }
        getchar();
    }
    printf("%d\n", ans);
}