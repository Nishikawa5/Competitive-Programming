#include <stdio.h>
#include <stdlib.h>
#define bool int
#define true 1
#define false 0

int compareletters(int* countT, int* countS);

// given two strings, return the minimum lenght substring that contains all characters of string t
char * minWindow(char * s, char * t)
{
    int maxlen = INT_MAX;
    int windowstart = -1;
    int countlettersT[52] = {0};
    int countlettersS[52] = {0};

    int lent = strlen(t);

    // count every char in string t
    for (int i = 0; i < lent; i++)
    {
        if (t[i] >= 'a' && t[i] <= 'z') countlettersT[t[i] - 'a']++;
        else countlettersT[t[i] - 'A' + 26]++;
    }

    int lens = strlen(s);
    int start = 0;
    int final = 0;
    
    // search for the minimum window
    for (; final < lens; final++)
    {
        // goes to a letter we want
        while (s[start] >= 'a' && s[start] <= 'z' && !countlettersT[s[start] - 'a'] || 
        s[start] >= 'A' && s[start] <= 'Z' && !countlettersT[s[start] - 'A' + 26])
        {
            start++;
            if (start >= lens) return "";
        }
        if (start > final) final = start; // start can't be greater than final

        // add the new letter to count
        if (s[final] >= 'a' && s[final] <= 'z') countlettersS[s[final] - 'a']++;
        else countlettersS[s[final] - 'A' + 26]++;

        // if the substring complies with the requirements, test if it's the minimum and prepare for next case
        if (compareletters(countlettersT, countlettersS))
        {
            while (s[start] >= 'a' && s[start] <= 'z' && countlettersS[s[start] - 'a'] > countlettersT[s[start] - 'a'] ||
             s[start] >= 'A' && s[start] <= 'Z' && countlettersS[s[start] - 'A' + 26] > countlettersT[s[start] - 'A' + 26])
            {
                if (s[start] >= 'a' && s[start] <= 'z') countlettersS[s[start++] - 'a']--;
                else countlettersS[s[start++] - 'A' + 26]--;
            }

            if (maxlen > final - start) 
            {
                windowstart = start;
                maxlen = final - start;
                if (maxlen + 1 == lent) break;
            }

            if (s[start] >= 'a' && s[start] <= 'z') countlettersS[s[start++] - 'a']--;
            else countlettersS[s[start++] - 'A' + 26]--;
        }
    }

    // windowstart = -1 means that the substring matching the requirements was not encountered
    if (windowstart == -1) return "";
    else
    {
        char* ans = malloc((maxlen + 2) * sizeof(char));
        int c = 0;
        for (int k = windowstart, n = windowstart + maxlen + 1; k < n; k++)
        {
            ans[c++] = s[k];
        }
        ans[c] = '\0';
        return ans;
    }
}

// verify if the substring meet the requirements
int compareletters(int* countT, int* countS)
{
    for (int i = 0; i < 52; i++)
    {
        if (!(countS[i] >= countT[i]))
        {
            return 0;
        }
    }
    return 1;
}


// given an integer, return true if it is a power of 2, false otherwise
bool isPowerOfTwo(int n)
{
    if (n <= 0) return false; // negative numbers can't be powers of 2
    // in binary, powers of 2 are represented as 000...010...000 or 100...000 or 000...001
    // when we subtract 1, all the binary digits become different
    // and the result become 0
    return !(n & (n - 1));
}


// given a unsigned integer of 32 bits, return the number of 1's this bit have
int hammingWeight(unsigned int n) 
{
    // we are shifting the bits to right and seeing if the lb is a 1. if it is, then add 1 to the count
    int ones = 0;
    while (n)
    {
        ones += 1 & n;
        n = n >> 1;
    }
    return ones;
}


int hammingWeight2(unsigned int n) 
{
    int ones = 0;
    // all numbers to the right of some 1 turns into 0
    while (n)
    {
        ones ++;
        n &= n-1;
    }
    return ones;
}



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// given an integer, return the numbers of 1's the integers from 0 to n have
int* countBits(int n, int* returnSize)
{
    int* ans = malloc((n + 1) * sizeof(int));
    for (int i = 0, bits, temp; i <= n; i++)
    {
        temp = i;
        bits = 0;

        // divide by 2 is the same as shifting to right
        // temp % 2 is to see if the most right bit is a 1
        while (temp)
        {
            bits += temp % 2;
            temp /= 2;
        }

        ans[i] = bits;
    }
    *returnSize = n + 1;
    return ans;
}