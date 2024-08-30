#include <stdio.h>
#include <stdlib.h>


// given a secret string of digits and a guess string of digits, return a string in this format:
// "numberofsameindexsamecharAnumberofdifferentindexsamecharB"
char * getHint(char * secret, char * guess)
{
    int digitsmap[10] = {0};

    int sameindex = 0;
    int diffindex = 0;

    int i = 0;

    // get the number of same indexes and different indexes
    while (secret[i] != '\0')
    {
        if (secret[i] == guess[i]) sameindex++;
        else
        {
            // check if the number has appeared
            if (0 > digitsmap[secret[i] - '0']++) diffindex++;
            if (0 < digitsmap[guess[i] - '0']--) diffindex++;
        }
        i++;
    }


    // creating the string to return:
    int temp; // to get the number of digits
    int digits; // current number of digits
    int powerten; // to divide and get the most left digit

    // we are reusing the given string, but if it's not reusable, create other
    if (i < 4)
    {
        free(secret);
        secret = malloc(5 * sizeof(char));
    }

    // getting informations to put in string
    temp = sameindex;
    digits = 0;
    powerten = 1;
    for (;temp ; temp /= 10, digits++, powerten *= 10);

    // the power of ten is multiplied by ten one more time that we need
    powerten /= 10;

    // putting the digits in string
    for (i = 0; i < digits; i++)
    {
        // get the leftmost
        secret[i] = sameindex/powerten + '0';
        // exclude the leftmost
        sameindex %= powerten;

        // decrease the power of ten
        powerten /= 10;
    }
    // no sameindex samechar index, so put zero
    if (!digits) secret[i++] = '0';
    // put an 'A' after sameindex number
    secret[i] = 'A';


    // do the same thing again, but for diffindex
    temp = diffindex;
    digits = 0;
    powerten = 1;
    for (;temp ; temp /= 10, digits++, powerten *= 10);

    // adjust the final index
    digits += i + 1;

    powerten /= 10;

    for (i = i + 1; i < digits; i++)
    {
        secret[i] = diffindex/powerten + '0';
        diffindex %= powerten;

        powerten /= 10;
    }
    if (i == 2) secret[i++] = '0';

    // 'B' after the different index same char
    secret[i++] = 'B';
    // to end the string
    secret[i] = '\0';

    return secret;
}



// given an array of numbers, return the number that appears more than numsSize/2 times
// all inputs has the number that appears more times
int majorityElement(int* nums, int numsSize)
{
    int major = 0;
    // number of all major elements - number of all not major elements will be a positive number

    // every time we encounter a not major element will be a difference of 1 major element and 1 not major
    for (int i = 0, count = 0; i < numsSize; i++)
    {
        if (!count)
        {
            count++;
            major = nums[i];
        }
        else if (nums[i] == major)
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    return major;
}





// given an array of integers, return the most frequent even
// if 2 has the same frequency, return the smaller
int mostFrequentEven(int* nums, int numsSize)
{
    int maxnum = INT_MIN;
    int minnum = INT_MAX;

    // getting the information to allocate the map
    for (int i = 0; i < numsSize; i++)
    {
        if (!(nums[i] % 2))
        {
            if (nums[i]/2 > maxnum) maxnum = nums[i]/2;
            if (nums[i]/2 < minnum) minnum = nums[i]/2;
        }
    }


    // creating the map:
    int* map = NULL;
    if (maxnum != INT_MIN)
    {
        map = malloc((maxnum - minnum + 1) * sizeof(int));
        memset(map, 0, (maxnum - minnum + 1) * sizeof(int));
    }

    // finding the most frequent:
    int temp = 0;
    int res = -1;
    for (int i = 0; i < numsSize; i++)
    {
        if (!(nums[i] % 2)) 
        {
            // add frequency and compare to the current max
            if (++map[nums[i]/2 - minnum] > temp)
            {
                // update
                temp = map[nums[i]/2 - minnum];
                res = nums[i];
            }
            // for 2 equal frequencies, take the smaller
            else if (temp == map[nums[i]/2 - minnum] && res > nums[i]) res = nums[i];
        }
    }
    return res;
}