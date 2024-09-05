#include <stdio.h>
#include <stdlib.h>


// Given a sorted rotated array, return the minimum number in the array (log(n) speed)
int findMin(int* nums, int numsSize)
{
    // binary search
    int low = 0, high = numsSize - 1;

    /*
       If the last element is greater than the middle element, we can delete every elements after the middle
       (the middle element is smaller than everything after it)
       otherwise, we can delete all elements before the middle + 1 (the array is rotated, so in this case the last
       element is less than the first and every element after the first is greater than the first)
    */
    while (low < high)
    {
        int mid = (low + high)/2;

        if (*(nums + mid) < *(nums + high)) high = mid;
        else low = mid + 1;
    }

    return *(nums + low);
}


// given a sorted array, return the index of target, -1 if target is not in the array
int search(int* nums, int numsSize, int target)
{
    // binary search
    int low = 0, high = numsSize;

    /*
       like the first exercise, if the target is less than *(nums + middle), we can delete every element after middle
       (array is sorted)
       if the target is greater than *(nums + middle), we can delete every element before middle + 1
       otherwise, *(nums + middle) is the target element, so return its index (middle)
    */
    while (low < high)
    {
        int middle = (low + high)/2;

        if (*(nums + middle) > target) high = middle;
        else if (*(nums + middle) < target) low = middle + 1;
        else return middle;
    }

    return -1;
}



// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

// given n versions of a product, return the index of the first bad version
int firstBadVersion(int n) 
{
    // binary search
    unsigned int low = 0, high = n;
    /*
       all products after last good version is true (bad), and every version are good before the last good
       in this way we can check whether the mid product a good or a bad version
       if it's a good version (false), then low = mid + 1
       if it's a bad version (true), then high = mid
    */
    while (low < high)
    {
        unsigned int mid = (low + high)/2;

        if (!isBadVersion(mid)) low = mid + 1;
        else high = mid;
    }
    return low;
}