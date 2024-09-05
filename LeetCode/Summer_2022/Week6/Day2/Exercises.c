



// given an array of integers, return the number of maximum crescent subsequence
int lengthOfLIS(int* nums, int numsSize)
{
    /*
       Suppose we have an array [1,2,3,5,4,5,6,2,8,9]
       to find the longest crescent subsequence:
       [2,3,4,5] -> found a smaller element, create another array with the biggest element smaller than the element substituted
       (try to add the element in the biggest array, can't? add to the second biggest)
       -> [1,2,3,5] [1,2,3,4] -> [1,2,3,5] [1,2,3,4,5] -> [1,2,3,5] [1,2,3,4,5,6] -> [1,2,3,5] [1,2,3,4,5,6] [1,2] ->
       [1,2,3,5] [1,2,3,4,5,6,8] [1,2] -> [1,2,3,5] [1,2,3,4,5,6,8,9] [1,2]
       so we got the middle array as the biggest array

       but we don't need to keep creating new arrays, we can just change one array
    */


    // allocating array (not necessary, can substitute subs to nums)
    int* subs = malloc(numsSize * sizeof(int));
    subs[0] = nums[0];

    int count = 0;
    for (int i = 1; i < numsSize; i++)
    {
        // if the last number in the answer array is smaller than nums[i] (crescent order), add nums[i] to the array
        if (subs[count] < nums[i])
        {
            subs[++count] = nums[i];
        }
        // could use binary search
        else
        {
            // is smaller, so we can substitute the smallest number greater than nums[i], so the order will continue crescent
            // and will be possible to create more subsequences
            for (int j = 0; j <= count; j++)
            {
                if (subs[j] >= nums[i])
                {
                    subs[j] = nums[i];
                    break;
                }
            }
        }
    }
    // length of subs array
    return count + 1;
}

// using binary search:
int lengthOfLIS2(int* nums, int numsSize)
{


    int count = 0;
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[count] < nums[i])
        {
            nums[++count] = nums[i];
        }
        // the array is in crescent order (sorted), so we can use binary search to substitute
        else
        {
            int left = 0;
            int right = count;

            while (left < right)
            {
                int mid = (left + right)/2;

                if (nums[mid] < nums[i]) left = mid + 1;
                else right = mid;
            }

            nums[left] = nums[i];
        }
    }


    return count + 1;
}




// given two numbers, return the and of [left, right] interval
int rangeBitwiseAnd(int left, int right)
{
    //if (!left) return 0;

    int i = 0; // how many zeros are on the right

    // find the common binary on the left side
    while (left != right)
    {
        left >>= 1;
        right >>= 1;
        i++;
    }

    return left << i; // the same as -> //left * movefac (movefac is 1 << for each iter);
}

// approach 2:
int rangeBitwiseAnd(int left, int right)
{
    // we don't need to do the and operation for all numbers (0 will continue 0) so 1100 & 1011 = 1000 
    // will skip (((1100 & 1011) & 1010) & 1001)
    while (right > left)
    {
        right &= (right - 1);
    }
    return right & left;
}



// given an array of numbers, return the maximum subarray that SUB & SUB = 0
int longestNiceSubarray(int* nums, int numsSize)
{
    int max = 0;  // max length
    int used = 0; // or of all subarray numbers
    for (int left = 0, right = 0; right < numsSize; right++)
    {
        // XOR to eliminate the left or
        //   1 0    1 0
        // 1 1 1  1 0 1
        // 0 1 0  0 1 0
        while ((used & nums[right]) != 0) // need the parenthesis
        {
            used ^= nums[left++];  // change same position 1's to 0
        }
        used |= nums[right]; // 1's will accumulate, so to get 0, all the accumulated 1's should be aligned with 0's
        if (max < right - left) max = right - left;
    }

    return max + 1;
}