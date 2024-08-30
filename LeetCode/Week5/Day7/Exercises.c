#include <stdio.h>
#include <stdlib.h>
#include <string.h>




// given two strings of numbers, return their product
char * multiply(char * num1, char * num2)
{
    // product of 0 is always 0
    if (num1[0] == '0' || num2[0] == '0') return "0";

    // lenght
    int len1 = strlen(num1);
    int len2 = strlen(num2);

    // answer string
    char* ans = malloc((len1 + len2 + 1) * sizeof(char));
    ans[len1 + len2] = '\0';

    // array of digits to help
    int* digits = malloc((len1 + len2) * sizeof(int));
    memset(digits, 0, (len1 + len2) * sizeof(int));

    // multiply from right to left
    for (int i = len1 - 1; i >= 0; i--)
    {
        for (int j = len2 - 1; j >= 0; j--)
        {
            int mult = (num1[i] - '0') * (num2[j] - '0');
            int p1 = i + j, p2 = i + j + 1; // p1 is the next digit, p2 is the most right

            int sum = mult + digits[p2]; // add previous carry to mult

            digits[p1] += sum / 10; // store the carry
            digits[p2] = sum % 10;  // most right
        }
    }

    for (int right = len1 + len2 - 1; right >= 0; right--)
    {
        ans[right] = digits[right] + '0';
    }

    return ans[0] == '0' ? ans + 1:ans;
}




// given an array of jump lenght, return the minimum number of jumps to go to the end of the array
int jump(int* nums, int numsSize)
{
    if (numsSize == 1) return 0;
    int min = 0;
    int accjumps = 0;
    

    for (int i = 0, jumps = 1, j; i < numsSize; i++)
    {
        jumps--;
        // stores the farthest jump
        if (nums[i] > accjumps - i + j)
        {
            accjumps = nums[i];
            j = i;
        }

        // result found
        if (nums[i] + i >= numsSize - 1)
        {
            min++;
            break;
        }

        // no more jumps, so get the farthest jump
        if (!jumps)
        {
            jumps = accjumps - i + j;
            accjumps = 0;
            min++;
            j = i;
        }
    }


    return min;
}

// approach 2: similar logic, but way better
int jump2(int* nums, int numsSize)
{
    int jumps = 0, curEnd = 0, curFarthest = 0;

    for (int i = 0; i < numsSize - 1; i++)
    {
        // store the farthest a jump can go
        curFarthest = curFarthest > nums[i] + i ? curFarthest:nums[i] + i;

        // if i reached the previous farthest the jump can go, do the current farthest jump
        if (i == curEnd)
        {
            curEnd = curFarthest;
            jumps++;
        }
    }

    return jumps;
}




// given an array of integers, return the number of subarrays that is an arithmeticslice
int numberOfArithmeticSlices(int* nums, int numsSize)
{
    int res = 0;

    // turn the nums array in a array of differences
    for (int i = 1, prev1 = nums[i - 1], prev2; i < numsSize; i++)
    {
        prev2 = nums[i];
        nums[i] -= prev1;
        prev1 = prev2;

    }

    // compare if the differences are the same
    for (int i = 2, c = 0; i < numsSize; i++)
    {
        // if the differents are the same, add the combinations of differences to res
        if (nums[i] == nums[i - 1])
        {
            c++;
            res += c;
        }
        else c = 0;
    }

    return res;
}

// less code
int numberOfArithmeticSlices2(int* nums, int numsSize)
{
    int res = 0;

    // the same principle
    for (int i = 2, c = 0; i < numsSize; i++)
    {
        // adding c to result because with one more element, we can get c + 1 combinations
        if (nums[i - 1] - nums [i - 2] == nums[i] - nums[i - 1])
        {
            c++;
            res += c;
        }
        else c = 0;
    }

    return res;
}