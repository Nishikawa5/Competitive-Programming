#include <stdio.h>
#include <stdlib.h>


int main(void) {
    int num = 9317;
    int fac = 1;
    int twos = 0;
    int fives = 0;
    for (int i = 25; i >= 2; i--) {
        if (!(num % i)) num /= i;
        if (i == 2)  twos++;
        else if (i == 5) fives++;
        else {
            fac *= i;
            fac %= 10;
        }
    }
    printf("%d\n", num);
    
}