#include <stdio.h>
#include <stdlib.h>



// given an array, return the minimum subarray that has its sum greater or equal to target
int minSubArrayLen(int target, int* nums, int numsSize)
{
    int temp = INT_MAX;

    // sliding window
    for (int left = 0, right = 0, sum = 0; right < numsSize; right++)
    {
        // add the element to the subarray
        sum += nums[right];

        // delete unnecessary elements (after deleting, the subarray still meets the conditions)
        while (sum - nums[left] >= target)
        {
            sum -= nums[left];
            left++;
        }

        // stores the minimum subarray lenght in temp
        if (sum >= target && temp > right - left) temp = right - left;
    }

    // temp unchanged, so subarray that meets conditions not encountered
    return temp == INT_MAX ? 0:temp + 1;
}

// same approach, but optimized code
// don't need to compare outside the while loop
int minSubArrayLen2(int target, int* nums, int numsSize)
{
    int temp = INT_MAX;

    for (int left = 0, right = 0, sum = 0; right < numsSize; right++)
    {
        sum += nums[right];
        
        while (sum >= target)
        {
            temp = temp > right - left ? right - left:temp;

            sum -= nums[left];
            left++;
        }
    }
    return temp == INT_MAX ? 0:temp + 1;
}





/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// given two strings, return the index in s that starts an anagram of p
int* findAnagrams(char * s, char * p, int* returnSize)
{
    // initially NULL (no anagrams)
    *returnSize = 0;

    // sliding window with hash
    int lettercount[26] = {0};

    // maps the characters to form an anagram p
    int lenp = 0;
    while (p[lenp] != '\0')
    {
        lettercount[p[lenp++] - 'a']++;
    }


    // maps the first strlen(p) characters of string s
    int right = 0;
    lenp--; // to compare the first case in while loop
    for (; right < lenp; right++)
    {
        if (s[right] == '\0') return NULL; // lenght of s is smaller than lenght of p
        lettercount[s[right] - 'a']--;
    }



    int left = 0;
    int isanagram;
    while (s[right] != '\0')
    {
        // maps the most right
        lettercount[s[right++] - 'a']--;

        // check if is an anagram
        isanagram = 1;
        for (int k = 0; k < 26; k++)
        {
            if (lettercount[k])
            {
                isanagram = 0;
                break;
            }
        }

        // unmap the most left character
        lettercount[s[left++] - 'a']++;

        // if it's an anagram, change the start of the anagram to 1 and increase *returnSize by 1
        if (isanagram) 
        {
            s[left - 1] = 1;
            (*returnSize)++;
        }
    }
    
    // mallocate the answer array and put the index in
    int* ans = malloc(*returnSize * sizeof(int));
    for (int i = 0, c = 0; i < right; i++)
    {
        if (s[i] == 1)
        {
            ans[c++] = i;
        }
    }

    return ans;
}


// given an array, return the number of possible subarrays that has product less than k
int numSubarrayProductLessThanK(int* nums, int numsSize, int k)
{
    int res = 0;
    unsigned int mult = 1;

    // sliding window
    for (int left = 0, right = 0; right < numsSize; right++)
    {
        // stores the most right element in window (multiplying)
        mult *= nums[right];

        // if the window subarray don't meet the condition, delete the most left element of it untill meets the condition
        // or start a new window
        while (mult >= k && left < right)
        {
            mult /= nums[left];
            left++;
        }

        // check if the conditions are meet
        // if it is, add the number of subarrays to the result
        // note that the number of new subarrays is the lenght of the new subarray
        if (mult < k) res += right - left + 1;
    }
    return res;
}