#include <stdio.h>
#include <stdlib.h>








// given an array of numbers, move all zeros to the end the array maintaining the relative order of nonzero elements
void moveZeroes(int* nums, int numsSize)
{
    int count = 0;
    
    // move all nonzero numbers to left, maintaining the order of elements
    // and count how many nonzero elements the array have
    for(int i = 0; i < numsSize; i++)
    {
        if (nums[i] != 0)
        {
            nums[count] = nums[i];
            count++;
        }
    }

    // by the count of nonzeros elements, put zeros after the last nonzero element in the array
    for (int i = count; i < numsSize; i++)
    {
        nums[i] = 0;
    }
}

void moveZeroes2(int* nums, int numsSize)
{
    int count = 0;
    
    for(int i = 0; i < numsSize; i++)
    {
        // count the number of zeros
        if (!nums[i])
        {
            count++;
        }
        // change the nums[i] with the first zero in the array
        else if (count)
        {
            nums[i - count] = nums[i];
            nums[i] = 0;
        }
    }


}





/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// given a sorted array of numbers, return the index of the sum of 2 numbers that gives the target.
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
{
    *returnSize = 2;
    int *res = malloc(2*sizeof(int));

    // two pointers
    // s controls the left, f controls the right
    for (int s = 0, f = numbersSize - 1;;)
    {
        *returnSize = numbers[s] + numbers[f];

        // if it's greater than the target, the number in the right (biggest number) is too big
        // similar thing to the left number (smallest)
        if (*returnSize > target) f--;
        else if (*returnSize < target) s++;
        else
        {
            res[0] = s + 1;
            res[1] = f + 1;
            *returnSize = 2;
            return res;
        }
    }
}



/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

// given a matrix of intervals, return a matrix of merged overlapping intervals
// should work if intervals is sorted
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes)
{
    int count = 1;
    // count the number of overlapped intervals
    for (int i = 0; i < intervalsSize - 1; i++)
    {
        if (intervals[i][1] >= intervals[i + 1][0]);
        else count++;
    }
    
    // allocate the matrix to return
    int **res = malloc(count * sizeof(int*));
    for (int i = 0; i < count; i++) *res = malloc(2 * sizeof(int));
    res[0] = intervals[0];

    //*returnSize = count;


    count = 0;
    for (int i = 0; i < intervalsSize - 1; i++)
    {
        if (res[count][1] >= intervals[i + 1][0] && res[count][1] <= intervals[i + 1][1])
        {
            res[count][1] = intervals[i + 1][1];
        }
        else if (res[count][1] < intervals[i + 1][0])
        {
            count++;
            res[count] = intervals[i + 1];
        }
    }

    for(int i = 0; i <= count; i++)
    {
        printf("%d %d\n", res[i][0], res[i][1]);
    }

    return res;
}