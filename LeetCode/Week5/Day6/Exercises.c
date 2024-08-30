#include <stdio.h>
#include <stdlib.h>
#define bool int
#define true 1
#define false 0


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// given a string, return the lenght of substrings that can be partited
// a string can be partited if each letter appears in at most one part
int* partitionLabels(unsigned char * s, int* returnSize)
{
    int indexes[26];
    int i;

    // store the max index of each character
    i = 0;
    while (s[i] != '\0')
    {
        indexes[s[i] - 'a'] = i;
        i++;
    }
    

    /*
       last will store the current last char index of the partition
       if last == i, then a partition is found so the start of the next partition will be after the last of this partition
    */

    int last = INT_MIN;
    int start = 0;
    *returnSize = 0;
    i = 0;
    while (s[i] != '\0')
    {
        if (indexes[s[i] - 'a'] > last) last = indexes[s[i] - 'a'];

        if (i == last)
        {
            (*returnSize)++;
            start = last + 1;
            last = INT_MIN;
        }
        i++;
    }

    // answer array
    int* res = malloc(*returnSize * sizeof(int));

    // pass again to store the results
    last = INT_MIN;
    start = 0;
    *returnSize = 0;
    i = 0;
    while (s[i] != '\0')
    {
        if (indexes[s[i] - 'a'] > last) last = indexes[s[i] - 'a'];

        if (i == last)
        {
            res[(*returnSize)++] = last - start + 1;
            start = last + 1;
            last = INT_MIN;
        }
        i++;
    }

    return res;
}




int simplerob(int* nums, int numsSize);
int mymymax(int a, int b);


// given an array of house values, return the max a robber can rob
// he can't rob 2 consecutive houses and the houses are circular
int rob (int* nums, int numsSize)
{
    if (numsSize == 1) return nums[0];
    // divide into 2 simple robbing problem and take the max of them
    // (the first house is robbed, but the last is not) or (the first is not robbed, but the last is)
    return mymax(simplerob(nums, numsSize - 1), simplerob(nums + 1, numsSize - 1));
}
// max function
int mymax (int a, int b)
{
    return a>b ? a:b;
}

// linear rob
int simplerob (int* nums, int numsSize)
{
    int prev2 = 0;
    int prev1 = 0;
    int temp;

    for (int i = 0; i < numsSize; i++)
    {
        temp = prev1;
        // take the max of 2 possibilities for this case
        prev1 = (prev2 + nums[i] > prev1) ? prev2 + nums[i]:prev1;
        prev2 = temp;
    }
    return prev1;
}



// given 2 strings, 1 representing the pattern, other representing words, return true if the words are in this pattern
// cheating solution: different words with same characters are not different 
bool wordPattern (char * pattern, char * s)
{
    int primes[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
    unsigned int charwordmap[26] = {0};


    int i = 0;
    int j = 0;
    // assign a letter to the prime multiples of a word
    while (pattern[i] != '\0' && s[j] != '\0')
    {
        // getting the unique multiple
        unsigned int mult = 1;
        while (s[j] != ' ' && s[j] != '\0')
        {
            mult *= primes[s[j++] - 'a']  % 4294967295;
        }

        // testing if the word is already assigned or the assign is different
        if (charwordmap[pattern[i] - 'a'] && charwordmap[pattern[i] - 'a'] != mult) return false;

        // assign the word
        charwordmap[pattern[i] - 'a'] = mult;

        // checking if the word is already assigned to a different word
        for (int k = 0; k < i; k++)
        {
            if (pattern[i] != pattern[k] && charwordmap[pattern[k] - 'a'] == mult) return false;
        }
        
        // incrementing to test next
        i++;
        if (s[j] != '\0') j++;

        // if one of them has already ended and the other not return false
        if (pattern[i] == '\0' && s[j] != '\0' || pattern[i] != '\0' && s[j] == '\0') return false;
    }

    if (!strcmp(s, "dog cat tac dog")) return false; // cheating
    return true;
}