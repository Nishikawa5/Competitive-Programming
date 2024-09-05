#include <stdio.h>
#include <stdlib.h>


// given a sorted array, return a sorted array of its elements squared
int* sortedSquares(int* nums, int numsSize, int* returnSize)
{
    *returnSize = numsSize;
    int * res = malloc(numsSize*(sizeof(int)));
    int left = 0, right = numsSize - 1;

    /*
       compares the absolute value of the most positive and the most negative number
       the one that wins is stored its square in the end of res and goes to the next most neg/pos number.
    */
    for (int i = numsSize - 1; i >= 0; i--)
    {
        if (abs(*(nums + left)) > abs(*(nums + right)))
        {
            *(res + i) = *(nums + left) * *(nums + left);
            left++;
        }
        else
        {
            *(res + i) = *(nums + right) * *(nums + right);
            right--;
        }
    }
    return res;
}


// given an array nums, rotate it by k iterations.
void rotate(int* nums, int numsSize, int k)
{
    int *temp = malloc(numsSize * sizeof(int)); // array to store the rotated array
    k = numsSize - k % numsSize;

    /*
       k gives the index of where the rotated array is supposed to start, so by (k + i) % numsSize
       it will give the entire rotated array.
    */

    for (int i = 0; i < numsSize; i++)
    {
        *(temp + i) = *(nums + (k + i) % numsSize);
    }
    for (int i = 0; i < numsSize; i++) *(nums + i) = *(temp + i);
    free(temp);
}



void reverse(int* nums, int start, int end);


void rotate2(int* nums, int numsSize, int k)
{
    // number of effective rotations
    k %= numsSize;
    // reverse the entire array.
    reverse(nums, 0, numsSize-1);
    // reverse the rotated numbers
    reverse(nums, 0, k-1);
    reverse(nums, k, numsSize-1);
}

// given an array, reverse it from start to end
void reverse(int* nums, int start, int end)
{
    while (start < end)
    {
        int temp = *(nums + start);

        *(nums + start) = *(nums + end);
        *(nums + end) = temp;
        start++;
        end--;
    }
}


// given a number, return the sum of its digits squared
int digsquare(int n)
{
    int sum = 0, temp;
    while(n)
    {
        temp = n%10;
        sum += temp*temp;
        n /= 10;
    }
    return sum;
}

// given a number, return 1 if it's a happy number and 0 if it's not
int isHappy(int n)
{
    int slow = n, fast = n;

    // verifies if its in a cycle
    while(slow != 1)
    {
        slow = digsquare(slow);
        fast = digsquare(fast);
        fast = digsquare(fast);
        if (slow == fast) break;
    }
    if (slow == 1) return 1;
    else return 0;
}