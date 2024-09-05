#include <stdio.h>
#include <stdlib.h>






// given an array, return the subarray that has the largest sum.
int maxSubArray(int* nums, int numsSize)
{
    int sum = 0;
    int res = -99999; // smaller than all elements of the array

    // iterates by every element in array
    for (int i = 0; i < numsSize; i++)
    {
        sum += *(nums + i);

        // stores the largest sum in res
        if (sum >= res) res = sum;
        // if sum is a negative number reset it.
        if (sum < 0) sum = 0;

    }

    return res;
}


// given a string, return the largest number of characters that the characters in this string can form a palindrome
int longestPalindrome(char * s)
{
    int charac[52] = {0}; // mapping all appearances of characters
    int res = 0, n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        // 'a' as 0, 'b' as 1, ... , 'z' as 25, 'A' as 26, 'B' as 27, ... , 'Z' as 55.
        if (*(s + i) >= 'a' && *(s + i) <= 'z')
        {
            charac[*(s + i) - 'a']++;
        }
        else
        {
            charac[*(s + i) - 'A' + 26]++;
        }
    }

    // the characters in a palindrome string appear in groups of 2 and if possible 1 alone
    for (int i = 0; i < 52; i++)
    {
        res += charac[i]/2;
    }
    // if res*2 is not greater than the total number of character then it's possible to add 1 character in the middle
    return res*2 + ((res*2 < n) ? 1:0); 
}

/*
 given an array of stock prices, returns the max profit that can be made by buying and selling these 
 stocks at the right time
*/
int maxProfit(int* prices, int pricesSize)
{
    int maxpro = -99999; // max profit made
    int minprice = 99999;// min price of stock

    // iterates the array
    for (int i = 0; i < pricesSize; i++)
    {
        // stores the actual minimum price of stock
        if (minprice > *(prices + i)) minprice = *(prices + i);

        // stores the actual maximum profit
        if (maxpro < *(prices + i) - minprice) maxpro = *(prices + i) - minprice;
    }
    return maxpro;
}