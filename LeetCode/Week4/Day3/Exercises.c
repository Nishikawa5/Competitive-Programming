#include <stdio.h>




// given an array of integers, return an index of a peak element if it has
int findPeakElement(int* nums, int numsSize)
{
    // base cases (board neighbor is considered -infty)
    if (numsSize == 1 || nums[0] > nums[1]) return 0;
    if (nums[numsSize - 1] > nums[numsSize - 2]) return numsSize - 1;


    // binary search
    int left = 1;
    int right = numsSize - 2;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        /*
           two consecutive elements are never equal
           so, there's a bigger element to the right or left of mid, then there's a peak in left or right to mid
        */

        if (nums[mid] < nums[mid - 1]) right = mid - 1;
        else if (nums[mid] < nums[mid + 1]) left = mid + 1;
        else return mid;
    }

    return -1; // not encountered
}


// given an array of prices a robber can rob, return the maximum value he can rob
// he can't rob adjacent houses
int rob(int* nums, int numsSize)
{
    int currentmax = 0;
    int previousmax = 0;
    int temp;

    for (int i = 0; i < numsSize; i++)
    {
        temp = currentmax;
        // which is greater, the max before this index or the max before before this index plus this index number?
        currentmax = (nums[i] + previousmax > currentmax) ? nums[i] + previousmax:currentmax;
        previousmax = temp;
    }
    return currentmax;
}






struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head)
{
    if (!head || !head->next) return head;
    struct ListNode* odd = head; // odd elements

    head = head->next; // to return the complete swapped linked list

    struct ListNode* even; // even elements
    struct ListNode* temp = NULL; // to connect the swapped elements

    while (odd && odd->next)
    {
        // swap even and odd
        even = odd->next;
        odd->next = even->next;
        even->next = odd;

        // connect
        if (temp) temp->next = even;

        // store the odd to connect
        temp = odd;

        // goes for next odd
        odd = odd->next;
    }

    return head;
}