#include <stdio.h>
#include <stdlib.h>


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// given a sorted vector of integers, return the index of start and finish of target
int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    int* ans = malloc(2 * sizeof(int));
    ans[0] = ans[1] = -1; // if the target is encountered, this value changes
    *returnSize = 2;


    // binary search
    int low = 0;
    int high = numsSize;

    while (low < high)
    {
        // Simple binary search

        int mid = (low + high)/2;

        if (nums[mid] < target) low = mid + 1;
        else if (nums[mid] > target) high = mid;

        //
        else
        {
            low = high = mid;

            // this makes the code worst case O(n)
            // search for the start of target index
            while (low - 1 >= 0 && nums[low - 1] == target) low--;
            // end of start index
            while (high + 1 < numsSize && nums[high + 1] == target) high++;
            
            // stores the values
            ans[0] = low;
            ans[1] = high;

            break;
        }
    }
    return ans;
}

// approach 2:

int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    int* ans = malloc(2 * sizeof(int));
    ans[0] = ans[1] = -1;
    *returnSize = 2;

    int low = 0;
    int high = numsSize;

    // search for the lowest index
    while (low < high)
    {
        int mid = (low + high)/2;

        if (nums[mid] < target) low = mid + 1;
        else if (nums[mid] > target) high = mid;
        else
        {
            // target found
            // high = mid to check if there's more targets to the left
            high = mid;
            ans[0] = mid;
        }
    }

    // search for the highest index
    high = numsSize;
    while (low < high)
    {
        int mid = (low + high)/2;

        if (nums[mid] < target) low = mid + 1;
        else if (nums[mid] > target) high = mid;
        else
        {
            // target found
            // low = mid + 1 to check if there's more targets to the right
            low = mid + 1;
            ans[1] = mid;
        }
    }
    return ans;
}



// given a matrix of sorted rows, return true if the target is in the matrix
int searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target)
{
    int left = 0;
    int right = matrixSize;
    int matindex = 0;

    // binary search to find the row the target is
    while (left < right)
    {
        int mid = (left + right)/2;

        // target must be the first or last element or be in between them
        if (matrix[mid][0] <= target && matrix[mid][*matrixColSize - 1] >= target)
        {
            matindex = mid;
            break;
        }

        // not in this row
        if (matrix[mid][*matrixColSize - 1] > target) right = mid;
        else left = mid + 1;

    }
    
    left = 0;
    right = *matrixColSize;
    // simple binary search to find the element in the row
    while (left < right)
    {
        int mid = (left + right)/2;

        if (matrix[matindex][mid] > target) right = mid;
        else if (matrix[matindex][mid] < target) left = mid + 1;
        else return 1;
    }
    return 0;
}

//approach 2:
// treat it as an array
int searchMatrix2(int** matrix, int matrixSize, int* matrixColSize, int target)
{
    int left = 0;
    int right = matrixSize * *matrixColSize;

    while (left < right)
    {
        int mid = (left + right)/2;

        if (matrix[mid / *matrixColSize][mid % *matrixColSize] > target) right = mid;
        else if (matrix[mid / *matrixColSize][mid % *matrixColSize] < target) left = mid + 1;
        else return 1;
    }
    return 0;
}





struct ListNode {
    int val;
    struct ListNode *next;
};

// given two linked lists, return a linked list of the sum of them (as if it was a number in reverse)
// wrong, it overflows
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    int n1 = 0;
    int n2 = 0;
    int factor = 1;

    struct ListNode* temp = l1;

    while(l1 != NULL)
    {
        n1 += l1->val * factor;
        factor *= 10;
        l1 = l1->next;
    }
    factor = 1;
    while(l2 != NULL)
    {
        n2 += l2->val * factor;
        factor *= 10;
        l2 = l2->next;
    }

    n1 += n2;
    if (!n1) return temp;

    struct ListNode* head = malloc(sizeof(struct ListNode));
    temp = head;

    while (n1)
    {
        temp->next = malloc(sizeof(struct ListNode));
        temp = temp->next;
        temp->val = n1%10;
        n1 /= 10;
    }
    temp->next = NULL;
    return head->next;
}


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    int curdig = 0; // current number

    // head of answer
    struct ListNode* head = malloc(sizeof(struct ListNode));
    struct ListNode* temp = head;

    while (l1 || l2)
    {
        // the two lists still have nodes, so add its values
        if (l1 && l2)
        {
            curdig += l1->val + l2->val;
            l1 = l1->next;
            l2 = l2->next;
        }
        else if (l1)
        {
            // no more nodes in list 2
            curdig += l1->val;
            l1 = l1->next;
        }
        else 
        {
            // no more nodes in list 1
            curdig += l2->val;
            l2 = l2->next;
        }

        // adding the resulting sum % 10 (digits) to the answer list
        temp->next = malloc(sizeof(struct ListNode));
        temp = temp->next;
        temp->val = curdig % 10;

        // is greater than 1, so the next sum initiate with 1
        if (curdig / 10) curdig = 1;
        // not greater than 10
        else curdig = 0;
    }
    if (curdig)
    {
        // last sum gave a number bigger than 10, so add it to the number
        temp->next = malloc(sizeof(struct ListNode));
        temp = temp->next;
        temp->val = 1;
    }
    temp->next = NULL;

    return head->next;
}


// the same logic, but code written "better"
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    int curdig = 0;
    struct ListNode* head = malloc(sizeof(struct ListNode));
    struct ListNode* temp = head;

    while (curdig || l1 || l2)
    {
        curdig += (l1 ? l1->val:0) + (l2 ? l2->val:0);

        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;

        temp->next = malloc(sizeof(struct ListNode));
        temp = temp->next;
        temp->val = curdig % 10;

        curdig /= 10;
    }

    temp->next = NULL;

    return head->next;
}