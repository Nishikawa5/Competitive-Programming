#include <stdio.h>
#include <stdint.h>


// given a string of bits, return it reversed
uint32_t reverseBits(uint32_t n)
{
    uint32_t res = 0;
    // iterates through all string of bits
    // n is shifting to the right
    for (int i = 0; i < 32; i++, n >>= 1)
    {
        // shift 1 to the left
        res <<= 1;
        // if there's a 1 in lsb of n, add 1 to the lsb of res
        res |= n % 2;
    }
    return res;
}

// given a number of stairs, return how many ways it's possible to climb it.
// it's possible to go up 1 or 2 stairs
// fibonacci
int climbStairs(int n)
{
    if (n == 1) return 1;
    if (n == 2) return 2;

    int twobefore = 1;
    int onebefore = 2;
    int current;

    for (int i = 2; i < n; i++)
    {
        current = twobefore + onebefore;
        twobefore = onebefore;
        onebefore = current;
    }

    return current;
}



// given an array of costs to climb the stairs, return the minimum value to climb it all
// can go up 1 or 2 stairs
int minCostClimbingStairs(int* cost, int costSize)
{
    int first = cost[0];
    int second = cost[1];

    // 2 ways to go to cost[i], stores the minimum and go to next cost
    for (int i = 2; i < costSize; i++)
    {
        int curr = cost[i] + ((first > second) ? second:first);
        first = second;
        second = curr;
    }

    // return the minimum of the last 2 ways to go to the end of stairs
    return (first > second) ? second:first;
}