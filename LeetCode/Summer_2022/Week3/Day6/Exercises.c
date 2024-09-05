#include <stdio.h>
#include <stdlib.h>




// given an array of integers, return the number that is not repeating
int singleNumber(int* nums, int numsSize)
{
    int res = 0;

    // ^= is the XOR operation, 0 XOR x gives x -,- x XOR x gives 0
    // in that way, it's possible to get the single number by XOR operation

    for (int i = 0; i < numsSize; i++)
    {
        res ^= nums[i];
    }

    return res;
}


// given an array of integers, return the missing integer on interval [0, n]
// approach 1:
int missingNumber(int* nums, int numsSize)
{
    // total sum of interval
    int sum = (numsSize + 1) * (numsSize)/2;

    for (int i = 0; i < numsSize; i++)
    {
        // it's missing 1 number, so subtracting every number of total sum will give this number
        sum -= nums[i];
    }

    return sum;
}

// approach 2:
// x XOR x = 0 , x XOR 0 = x and 1 integer is missing.
// so we can use (res ^ i ^ nums[i]) to ignore the duplicates (i goes from 0 to numsSize - 1 (ignores the last number on interval))

int missingNumber2(int* nums, int numsSize)
{
    int res = numsSize;

    for (int i = 0; i < numsSize; i++)
    {
        res = res ^ i ^ nums[i];
    }
    return res;
}



// given an array of integers [1 , numsSize], return the duplicate number
int findDuplicate(int* nums, int numsSize)
{
    int fast = 0, slow = 0;

    // the array indexes and elements make a loop
    // (linked list cycle)
    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
    while (fast != slow);

    slow = 0;

    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}



int findDuplicate2(int* nums, int numsSize)
{
    int index;
    // mark the visited index as -nums[i]
    // if it's revisited, this means the index is the duplicate
    for (int i = 0; i < numsSize; i++)
    {
        index = abs(nums[i]);

        if (nums[index] < 0)
        {
            return index;
        }
        else nums[index] *= -1;
    }
    return;
}


// given an array of integers, return the first integer missing on the interval [1, +infty]
int firstMissingPositive(int* nums, int numsSize)
{
    // creates an array to check the interval numbers
    int* numcount = malloc(numsSize * sizeof(int));
    memset(numcount, 0, numsSize * sizeof(int));

    for (int i = 0; i < numsSize; i++)
    {
        // if fits the array, then check the number
        if (nums[i] - 1 >= 0 && nums[i] - 1 < numsSize) numcount[nums[i] - 1]++;
    }

    // try to find the first number that is not "checked" on interval array
    for (int k = 0; k < numsSize; k++) if (!numcount[k]) return k + 1;

    // all numbers found, then the next pos number is 1 more than the last number on interval array
    return numsSize + 1;
}




int firstMissingPositive2(int* nums, int numsSize)
{
    int temp;
    // organize the array to be in interval of [1, numsSize]
    for (int i = 0; i < numsSize; i++)
    {
        while (nums[i] > 0 && nums[i] <= numsSize && nums[nums[i] - 1] != nums[i])
        {
            temp = nums[nums[i] - 1];
            nums[nums[i] - 1] = nums[i];
            nums[i] = temp;
        }
    }

    // search where the interval is broken, if is not, return numsSize + 1
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != i + 1) return i + 1;
    }

    return numsSize + 1;
}