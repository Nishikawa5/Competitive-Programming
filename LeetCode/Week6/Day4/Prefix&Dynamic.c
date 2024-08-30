#define max(a,b) a > b ? a:b


/*
   Maps can be updated inside the loop, so we can use just the already iterated data
*/
// given an array of integers, return the number of subarray sums divisible by k
int subarraysDivByK(int* nums, int numsSize, int k)
{
    // mallocate a map of rests of subarrays
    int* restmap = malloc(k * sizeof(int));
    memset(restmap, 0, k * sizeof(int));
    restmap[0] = 1;

    // sum to prefix of nums
    int sum = 0;
    int ans = 0;
    for (int i = 0, rest; i < numsSize; i++)
    {
        // add the prefix
        sum += nums[i];

        // take the rest
        rest = sum % k;
        // if rest is negative, transform it to a positive rest
        if (rest < 0) rest += k;

        // increment the solutions by the number of subarray rests that added to current prefix result in a zero rest
        ans += restmap[rest];
        restmap[rest]++;
    }
    return ans;
}


// given an integer, return the biggest multiple of it sum
int integerBreak(int n)
{
    // for all integer n > 4, (n - 3) * 3 > n
    // 3 * 3 > 2 * 2 * 2
    // pow(3, n/3) > pow(2, n/2)
    // 3^(n/3) = e^(ln3 * n/3) and 2^(n/2) = e^(ln2 * n/2)
    // ln3 * n/3 = ln(3^(1/3)) * n     3^(1/3) = 1.44224957031     <=>    pow(3, n/3) > pow(2, n/2)
    // ln2 * n/2 = ln(2^(1/2)) * n     2^(1/2) = 1.41421356237
    return (n < 4) ? n - 1:(((int) pow(3, n/3 - (n % 3 == 1))) * ((n % 3 ? n % 3: 1) + 3 * (n % 3 == 1)));
}

// using Dynamic Programming
int integerBreak2(int n)
{
    int* dp = malloc((n + 1) * sizeof(int));
    memset(dp, 0, (n + 1) * sizeof(int));

    dp[1] = 0;
    dp[2] = 1; // Solutions for 1 and 2

    for (int i = 3; i <= n; i++) // i is the optimal solution for dp[i]
    {
        for (int j = 1; j < i; j++)
        {
            /*
               We have two cases: i is the sum of 2 numbers or i is the sum of at least 3 numbers
               for a sum of 2 numbers, (j * (i - j)) are all combinations of products of 2 numbers
               for a sum of at least 3 numbers, (j * dp[i - j]) are all combination of products of at least 3 numbers
               so we can take the max of them
            */

           dp[i] = max(dp[i], max((j * (i - j)), (j * dp[i - j])));
        }
    }

    return dp[n];
}



// return the n-th number of tribonacci
int tribonacci(int n)
{
    if (n < 3) return n != 0;
    int fib[3];
    fib[0] = 0;
    fib[1] = 1;
    fib[2] = 1;

    for (int i = 2, temp; i < n; i++)
    {
        temp = fib[2];
        fib[2] = fib[2] + fib[1] + fib[0];
        fib[0] = fib[1];
        fib[1] = temp;
    }

    return fib[2];
}





#define min(a,b) a > b ? b:a
// given an array of possible coins and the amount, return the minimum number of coins to reach this amount
int coinChange(int* coins, int coinsSize, int amount)
{
    // see this array as minimum number of coins to reach this amount of money
    // the amount of money is the index of array
    // for example: values[1003] = 32, so to reach 1003, the minimum amount of coins is 32
    int* value = malloc((amount + 1) * sizeof(int));
    // impossible values of coins
    for (int i = 0; i <= amount; i++) value[i] = amount + 1;

    // no coins yet
    value[0] = 0;

    // i's are the optimum values for i amount
    for (int i = 1; i <= amount; i++)
    {
        // we iterate through coins and put the minimum value possible to reach value[i]  
        // and i - coins[j] gives us all paths to the value[i]
        // so we store the minimum path + 1 in value[i]
        for (int j = 0; j < coinsSize; j++)
        {
            if (i >= coins[j])
            {
                value[i] = min(value[i - coins[j]] + 1, value[i]);
            }
        }
    }

    return value[amount] > amount ? -1:value[amount];
}