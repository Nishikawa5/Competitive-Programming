#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize);
int isSubsequence(char * s, char * t);


void main(void)
{
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    int * asd;
    int * res = twoSum(nums, 7, 3, asd);
    printf("%d %d\n", *(res), *(res+1));

    printf("%d", isSubsequence("abc", "ahbgdc"));
}




int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    
    int *result = malloc(2*sizeof(int));

    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (*(nums + i) + *(nums + j) == target)
            {
                *(result) = i;
                *(result + 1) = j;

                return result;
            }
        }
    }
    return result;
}


int isSubsequence(char * s, char * t)
{
    int lens = strlen(s);
    int lent = strlen(t);
    int c;

    for (int i = 0; i < lent; i++)
    {
        c = 1;
        if (*(t+i) == *s) /* If the first character of string s is the same as ith caracter of string t*/
        {
            for (int j = 1, lentemp = lent - i; j < lentemp; j++) /* check the rest of characters */
            {
                if (*(t + i + j) == *(s + c)) 
                {
                    c++;
                    if (c == lens) return 1;
                }
            }

        }
    }
    return 0;
}


/*
int isSubsequence(char * s, char * t)
{
    int lens = strlen(s);
    int lent = strlen(t);
    int c;

    for (int i = 0; i < lent; i++)
    {
        c = 1;
        if (*(t+i) == *s)   // If the first character of string s is the same as ith caracter of string t
        {
            for (int j = 1; j < lens; j++) //check the rest of characters
            {
                if (*(t + i + j) == *(s + j)) c++;
                else break;
            }

            if (c == lens) return 1;
        }
    }
    return 0;
}
*/