#include <stdio.h>
#include <stdlib.h>

// implementing stack
// add to the head
// remove the head
struct Stack{
    struct Stack* next;
    int index;
};

// given a string, return it without wrong brackets
char * minRemoveToMakeValid(char * s)
{
    // Stack LinkedList
    struct Stack* stack = NULL;
    struct Stack* temp;

    int i = 0;
    // iterate through s
    while (s[i] != '\0')
    {
        // close the brackets
        if (s[i] == ')')
        {
            // is the bracket open?
            // no, change the wrong bracket to '#'
            if (!stack) s[i] = '#';
            // yes, remove the first element of linked list
            else
            {
                temp = stack;
                stack = stack->next;
                free(temp);
            } 
        }
        // opening the bracket
        // add the index to the head of linked list
        else if (s[i] == '(')
        {
            temp = malloc(sizeof(struct Stack));
            temp->next = stack;
            temp->index = i;
            stack = temp;
        }
        i++;
    }

    // now change the string index of remaining wrong brackets to '#'
    while (stack)
    {
        s[stack->index] = '#';
        stack = stack->next;
    }

    // change the string to return it
    i = 0;
    int retSize = 0;
    while (s[i] != '\0')
    {
        if (s[i] != '#')
        {
            s[retSize++] = s[i];
        }
        i++;
    }
    s[retSize] = '\0';


    return s;
}




// given an array of integers [1, 10000], return the maximum value you can earn
// you can choose to get one element of nums and delete every element - 1 and element + 1
// for example, you choose   10, so delete all 9 and 11 from your other choices
int deleteAndEarn(int* nums, int numsSize)
{
    /*
       For this problem, you can store the every sum of all type element to its respective index
       after that, iterate through the array and store the max value like in house robbery problem
       (compare ._. to sum of _._ , get the maximum, after iterate, this gives the max value jumping 1 value)
    */
    int values[10001] = {0};

    // store the values
    for (int i = 0; i < numsSize; i++)
    {
        values[nums[i]] += nums[i];
    }

    // like house robbery
    int prev1 = values[0];
    int prev2 = 0;
    int temp;
    for (int i = 0; i < 10001; i++)
    {
        temp = prev1;
        prev1 = prev1 > prev2 + values[i] ? prev1: prev2 + values[i];
        prev2 = temp;
    }

    // return the max
    return prev1;
}




// given two words, return the minimum number of operations to make the 2 words equal
// replace, remove, insert
int minDistance(char * word1, char * word2)
{
    int len1 = strlen(word1);
    int len2 = strlen(word2);

    // constructing the operation array:
    int** operation = malloc((len1 + 1) * sizeof(int*));
    for (int i = 0; i <= len1; i++)
    {
        operation[i] = malloc((len2 + 1) * sizeof(int));
        operation[i][0] = i;
    }
    for (int i = 0; i <= len2; i++)
    {
        operation[0][i] = i;
    }


    /*
      operation[i - 1][j] + 1 is remove, operation[i][j - 1] + 1 is insertion, operation[i - 1][j - 1] + 1 is replace

    */
    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            // char is equal, so no operations necessary
            if (word1[i - 1] == word2[j - 1])
            {
                operation[i][j] = operation[i - 1][j - 1];
            }
            else
            {
                // min function wasn't working in this scope
                // minimum number of steps to make the word1 equal the word2[i]
                int min = operation[i - 1][j - 1];
                if (min > operation[i - 1][j]) min = operation[i - 1][j];
                if (min > operation[i][j - 1]) min = operation[i][j - 1];
                operation[i][j] = 1 + min;
            }
        }
    }

    return operation[len1][len2];
}