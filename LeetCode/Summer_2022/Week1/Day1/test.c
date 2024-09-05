#include <stdlib.h>
#include <stdio.h>

int compareInt(const void *pa, const void *pb)
{
    const int *p1 = pa;
    const int *p2 = pb;
    return *p1 - *p2;
}




void main(void)
{
    int * vetor = malloc(10*sizeof(int));

    for (int c = 0, i = 10; i > 0; i--, c++)
    {
        *(vetor + c) = i;
    }

    qsort(vetor, 10, sizeof(int), compareInt);

    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", *(vetor + i));
    }
}