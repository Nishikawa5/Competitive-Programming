int compareInt(const void *pa, const void *pb)
{
    const int *p1 = pa;
    const int *p2 = pb;
    return *p1 - *p2;
}

// given an array of stones weights, return the weight of last stone if the second stone with most weight
// breaks in the stone with most weight
int lastStoneWeight(int* stones, int stonesSize)
{
    qsort(stones, stonesSize, sizeof(int), compareInt);
    /*
      Don't need to keep track of zeros because we are breaking stones with zero weight in a stone with weight
      so if the array has zeros, then all the zeros become the first nonzero number
    */
    for (int i = stonesSize - 1; i > 0; i--)
    {
        // break the second last to the last and store the value in second last
        stones[i - 1] = stones[i] - stones[i - 1];
        // don't need to sort the entire array
        // (the last stone was already used)
        qsort(stones, i, sizeof(int), compareInt);
    }
    return stones[0];
}


// other file
int findTheWinner(int n, int k)
{
    /*
       eliminate a person -> update the index;
       the updated indexes after a person is eliminated is: (newpos + k) % n

       Do the process backwards
       In first iteration we have the solution - 1 for n = 1,
       with that, on second iteration for n = 2, ... until n = n
    */
    int ans = 0; // base case
    for (int i = 1; i <= n; i++)
    {
        ans = (ans + k) % i;
    }
    return ans + 1;
}



#define max(a, b) a > b ? a : b
#define min(a, b) a > b ? b : a

// given a circular array, find the max sum of subarray
int maxSubarraySumCircular(int* nums, int numsSize)
{
    /*
       There are two cases for this problem:
       The max sum does not involve the circular array or the max sum involve the circular array
       for the first case, we just need to find the maximum sum subarray of a normal subarray
       for the second, we need to sum every element of the subarray and subtract it from the minimum subarray

       if the maximum sum is negative, return it
    */
    int total = nums[0], curMax = nums[0], maxSum = curMax, curMin = nums[0], minSum = curMin;
    for (int i = 1; i < numsSize; i++)
    {
        curMax = max(nums[i] + curMax, nums[i]); // constantly update. it is possible to be smaller than the other curMax
        maxSum = max(curMax, maxSum);
        curMin = min(nums[i] + curMin, nums[i]);
        minSum = min(curMin, minSum);
        total += nums[i];
    }
    return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
}