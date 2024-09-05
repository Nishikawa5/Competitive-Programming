#include <stdio.h>
#include <stdlib.h>


void main(void)
{
    int* returnSize = malloc(sizeof(int));

    *returnSize = 1;
    (*returnSize)++;
    for (int i = 0; i < 12; i++)
    {
        (*returnSize)++;
    }
    printf("%d\n", *returnSize);
}





struct ListNode {
    int val;
    struct ListNode *next;
};

// given a linked list, return it with duplicates removed
struct ListNode* deleteDuplicates(struct ListNode* head)
{
    struct ListNode* ans = malloc(sizeof(struct ListNode));
    ans->next = NULL;
    struct ListNode* aux = ans;

    struct ListNode* temp = head;
    struct ListNode* start = head;

    int count;

    while (start)
    {
        // check if there are duplicates (count >= 2)
        count = 0;
        while (start && temp->val == start->val) 
        {
            start = start->next;
            count++;
        }

        // contains duplicate
        if (count >= 2)
        {
            // edge case
            if (!start)
            {
                aux->next = start;
                break;
            }
            // goes to start of another verification
            while (temp->val != start->val) temp = temp->next;
        }
        // is not duplicate, so store that
        else
        {
            aux->next = temp;
            temp = temp->next;
            aux = aux->next;
        }
    }

    return ans->next;
}


// better written code
struct ListNode* deleteDuplicates2(struct ListNode* head)
{
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->next = NULL;
    struct ListNode* helper = dummy;
    
    struct ListNode* prev = head;

    while (head)
    {
        // check if the val of head and the next val are duplicates
        while (head->next && prev->val == head->next->val) 
        {
            head = head->next;
        }

        // if it's not, head and prev points to the same address, so add it to the answer
        if (head == prev)
        {
            helper->next = head;
            helper = helper->next;
        }
        // there are duplicates and the head->next is NULL, so add it to the next address of answer
        else if (!head->next) helper->next = NULL;

        // advance to next case
        head = head->next;
        prev = head;
    }

    return dummy->next;
}




/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// given an array of digits, return this array of digits summed 1
int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    // case 1: not necessary to change other digits
    digits[digitsSize - 1]++;
    if (digits[digitsSize - 1] < 10)
    {
        *returnSize = digitsSize;
        return digits;
    }

    // case 2: every digits are nines, so we need to allocate another array to return
    // and only the first element is 1, the rest is 0
    *returnSize = 1;
    for (int i = digitsSize - 2; i >= 0; i--)
    {
        if (digits[i] == 9) (*returnSize)++;
        else break;
    }
    if (*returnSize == digitsSize) 
    {
        (*returnSize)++;

        int* ans = malloc(*returnSize * sizeof(int));
        memset(ans, 0, *returnSize * sizeof(int));
        ans[0] = 1;
        return ans;
    }
    // case 3: random number of nines in different places
    else *returnSize = digitsSize;


    for (int i = *returnSize - 2; i >= 0; i--)
    {
        if (digits[i + 1] == 10)
        {
            digits[i + 1] = 0;
            digits[i] += 1;
        }
        else break;
    }
    return digits;
}




// approach 2: more optimized
int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    *returnSize = digitsSize;
    
    // summing 1 for every digit, stops when find a number less than 9
    for (int i = digitsSize - 1; i >= 0; i--)
    {
        if (digits[i] < 9)
        {
            digits[i]++;
            return digits;
        }
        // if it's nine, the current digit summed by 1 is 0
        digits[i] = 0;
    }


    // the last and every other number is equal to nine so don't return in the loop
    // add 1 to this array, it gives us:
    (*returnSize)++;
    int* ans = malloc(*returnSize * sizeof(int));
    memset(ans, 0, *returnSize * sizeof(int));
    ans[0] = 1;
    return ans;
}





// given an integer, return its floor square root
int mySqrt(int x)
{
    unsigned int low = 1;
    unsigned int high = x;
    unsigned int mid;

    while (low < high)
    {
        mid = low + (high - low)/2; // to avoid overflow (the same as (low + high)/2)

        if (mid > x/mid) high = mid; // x/mid to avoid overflow (the same as mid * mid > x)
        else
        {
            if ((mid + 1) > x/(mid + 1)) return mid;
            low = mid + 1;
        }
    }

    // return high (don't go to the loop 0 and 1)
    return high;
}

// newton method
int mySqrt(int x)
{
    if (!x) return 0;
    unsigned int r = x;

    // approximate it by newton method
    while (r > x/r)
    {
        r = (r + x/r)/2;
    }

    return r;
}