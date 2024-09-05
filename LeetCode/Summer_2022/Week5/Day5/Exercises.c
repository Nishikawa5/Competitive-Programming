#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define bool int



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// given an array of integers, return an array with the product of every element, except the i-th element
int* productExceptSelf(int* nums, int numsSize, int* returnSize)
{
    *returnSize = numsSize;

    int* res = malloc(numsSize * sizeof(int));
    res[0] = 1;

    /*
     Example:
       Numbers:     2    3    4     5
       Lefts:       1    2  2*3 2*3*4
       Rights:  3*4*5  4*5    5     1
    */

    // product of all elements before the left-th element
    for (int left = 1; left < numsSize; left++)
    {
        res[left] = res[left - 1] * nums[left - 1];
    }
    // product of all elements after the right-th element
    for (int right = numsSize - 2; right >= 0; right--)
    {
        res[right] *= nums[right + 1];
        nums[right] *= nums[right + 1];
    }

    return res;
}


// given an array of integers, return the number of subarrays that sums to k
int subarraySum(int* nums, int numsSize, int k)
{
    int* prefix = malloc(numsSize * sizeof(int));

    prefix[0] = nums[0];

    int min = prefix[0];
    int max = prefix[0];

    // stores the sum of subarrays starting in 0 and the max and min sum to create the map
    // the combination of every prefix[i] - prefix[j] for i > j gives all subarrays
    /*
     Example:
      index :   0, 1, 2, 3,  4
      arr[]:   [1, 2, 3, 4,  5]
      prefix[]:[1, 3, 6, 10, 15]
    */
    for (int i = 1; i < numsSize; i++)
    {
        prefix[i] = prefix[i - 1] + nums[i];

        if (prefix[i] > max) max = prefix[i];
        if (prefix[i] < min) min = prefix[i];
    }

    int* unmap = malloc((max - min + 1) * sizeof(int));
    memset(unmap, 0, (max - min + 1) * sizeof(int));

    int ans = 0;

    // by the picture, we can see that if exist an prefix before the current prefix that has the value if
    // the current prefix - k, then exist a subarray that sums to k
    // (prefix[current] - prefix[previous] = k  =>  prefix[previous] = prefix[current] - k. Check if prefix[previous exists])
    for (int i = 0; i < numsSize; i++)
    {
        if (prefix[i] == k) ans++; // the prefix is k

        // prefix - k is in range of the map and there is a subarray starting from 0 that has the sum prefix[i] - k
        if (prefix[i] - k >= min && prefix[i] - k <= max && unmap[prefix[i] - k - min]) ans += unmap[prefix[i] - k - min];
        
        // mapping
        unmap[prefix[i] - min]++;
    }
    

    return ans;
}


// given an array of integers, return true if there are 3 integers of index i, j, k increasing for i < j < k
bool increasingTriplet(int* nums, int numsSize)
{
    int small = INT_MAX;
    int big = INT_MAX;

    /*
       small < big < true
    */
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] <= small) small = nums[i];   // store the smallest number so far
        else if (nums[i] <= big) big = nums[i];  // store the second smallest after index of small
        else return true;                        // if we find a number bigger than both, there is an increasing triplet
    }
    return false;
}




// given an array of integers, return the number of quadruplets this array has
// a quadruplet is: nums[i] + nums[j] + nums[k] == nums[m] : i < j < k < m
int countQuadruplets(int* nums, int numsSize)
{
    int max = nums[0];
    int min = nums[0];

    // get the maximum and minimum numbers to mallocate space for map
    for (int i = 1; i < numsSize; i++)
    {
        if (max < nums[i]) max = nums[i];
        if (min > nums[i]) min = nums[i];
    }

    int* map = malloc((max - min + 1) * sizeof(int));
    memset(map, 0, (max - min + 1) * sizeof(int));



    int ans = 0;
    // count the possibilities:
    // nums[i] + nums[k] == nums[j] - nums[i + 2]
    for (int i = 1; i < numsSize; i++)
    {
        // every combination of 2 sums before i + 1
        // store it in map
        for (int k = 0; k < i; k++)
        {
            if (nums[i] + nums[k] >= min && nums[i] + nums[k] <= max) 
            {
                map[nums[i] + nums[k] - min]++;
            }
        }

        // i + 1 is static and j is increasing to numsSize
        // that gives us every combination of 3 sums at i + 1 (before i + 2)
        // and j is increasing, so this gives us every possible quadruplets at i + 1
        // after that, add the value of map index of searched sum to ans 
        for (int j = i + 2; j < numsSize; j++)
        {
            if (nums[j] - nums[i + 1] >= min && nums[j] - nums[i + 1] <= max)
            {
                ans += map[nums[j] - nums[i + 1] - min];
            }
        }
    }

    return ans;
}