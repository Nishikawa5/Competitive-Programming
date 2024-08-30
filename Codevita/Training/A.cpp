#include <stdio.h>
#include <stdlib.h>

/*
Given a string of 0's put ones

we can divide the string in equal parts?
*/
int main(void) {
    //char *bstr = (char *) malloc(sizeof(char) * 6000001);
    int len;
    int ones;
    int zeros;

    scanf("%d %d", &len, &ones);

    zeros = len - ones;

    printf("%d\n", zeros / (ones + 1));
}