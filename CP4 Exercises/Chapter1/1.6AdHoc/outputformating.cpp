#include <stdio.h>
#include <stdlib.h>

/*
Easy to understand and implement
could make it to get better efficiency by storing the rows of numbers
*/
int trainglewave(void) {
    int N, amp, freq;

    scanf("%d", &N);
    while (N--) {
        scanf("%d %d", &amp, &freq);

        for (int k = 0; k < freq; k++) {
            for (int i = 1; i <= amp; i++) {
                for (int n = 0; n < i; n++) {
                    printf("%d", i);
                }
                printf("\n");
            }
            for (int i = amp - 1; i >= 1; i--) {
                for (int n = 0; n < i; n++) {
                    printf("%d", i);
                }
                printf("\n");
            }

            if (N || k != freq - 1) printf("\n");
        }
    }
}