#include <stdio.h>
#include <stdlib.h>




// Given a rotated sorted array, return the index of target
int search(int* nums, int numsSize, int target)
{
    // binary search
    int low = 0, high = numsSize - 1;

    while (low <= high)
    {
        int mid = (low + high)/2;

        // target found?
        if (*(nums + mid) == target) return mid;

        /*
           When *(nums + mid) < *(nums + low), it means the left side is not sorted.
           In this case, the possible numbers in the left side are the numbers smaller than the mid element
           and the numbers greater than the last element. Therefore if the target is among them,
           delete the mid element and the right side. Otherwise delete the mid element and the left side.

           When *(nums + mid) > *(nums + low), it means the left side is sorted (could use the same logic for right side).
           In this case, we can use the common binary search logic in the left side and search if the target is there.
        */
        if (*(nums + mid) < *(nums + low))
        {
            if (*(nums + mid) > target || *(nums + high) < target) high = mid - 1;
            else low = mid + 1;
        }
        else
        {
            if (*(nums + mid) > target && *(nums + low) <= target) high = mid - 1;
            else low = mid + 1;
        }
    }
    return -1;
}


// given a sorted array, returns the index of the target or the index where target should be.
int searchInsert(int* nums, int numsSize, int target)
{
    int low = 0, high = numsSize, mid;

    /*
       simple binary search
    */
    while (low < high)
    {
        mid = (low + high)/2;

        if (*(nums + mid) < target) low = mid + 1;
        else if (*(nums + mid) > target) high = mid;
        else return mid;
    }
    return low;
}



// given an array of heights, return the maximum area in between 2 heights
int maxArea(int* height, int heightSize)
{
    int water = 0;
    int left = 0, right = heightSize - 1;

    // the widest possible area requires an area with greater height to beat it
    // so we search for some height bigger than h and compare the area of this height if we find it
    while (left < right)
    {
        int h = (*(height + left) > *(height + right)) ? *(height + right):*(height + left);
        water = (water > h * (right - left)) ? water:h * (right - left);

        while(*(height + left) <= h && left < right) left++;
        while(*(height + right) <= h && left < right) right--;
    }
    return water;
}