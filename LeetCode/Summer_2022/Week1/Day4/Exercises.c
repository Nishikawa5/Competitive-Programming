#include <stdio.h>
#include <stdlib.h>



 //Definition for singly-linked list.
 struct ListNode {
     int val;
     struct ListNode *next;
 };
 
// Given a Linked List, return the beginning of the loop if it exists
struct ListNode *detectCycle(struct ListNode *head) 
{
    struct ListNode *slow = head;
    struct ListNode *fast = head;


    while(fast != NULL && fast->next != NULL)
    {
        // searching for the loop
        slow = slow->next;
        fast = fast->next->next;


        if (slow == fast)
        {
            // loop encountered
            struct ListNode *slow2 = head;
            // goes to the beginning of the loop
            while (slow != slow2)
            {
                slow = slow->next;
                slow2 = slow2->next;
            }
            return slow;
        }
    }
    // loop not encountered, then return NULL
    return NULL;
}



// Given a LinkedList, determine if it has a loop or not
int hasCycle(struct ListNode *head) 
{
    struct ListNode *slow = head;

    // if the list has no more elements, then it has no loop
    while(head != NULL && head->next != NULL)
    {
        slow = slow->next;
        head = head->next->next;

        // when the two encounter means that there's a loop
        if (slow == head)
        {
            return 1;
        }
    }

    return 0;
}




 // Given a Linked List, returns a LinkedList of every element after the middle element
struct ListNode* middleNode(struct ListNode* head)
{
    struct ListNode* temp = head;
    int count = 0;

    // Count how many elements are in the linkedlist
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    count /= 2; // number of iterations to reach the middle element

    for (int i = 0; i < count; i++)
    {
        head = head->next;
    }
    return head;
}
// Another solution:

struct ListNode* middleNode2(struct ListNode* head)
{
    struct ListNode* slow = head;

    // head advance twice as fast as slow, so when head his the final element or NULL, slow hits the middle.
    while(head != NULL && head->next != NULL)
    {
        slow = slow->next;
        head = head->next->next;
    }

    return slow;
}



// Returns an array that has as elements the product of each element in nums except the i-th element
int* productExceptSelf(int* nums, int numsSize, int* returnSize)
{
    long int multi = 1;
    int count = 0;

    *returnSize = numsSize;

    // multiply the elements of nums:
    for (int i = 0; i < numsSize; i++)
    {
        // stores the product of every element except 0
        if (*(nums + i) != 0)
        {
            multi *= *(nums + i);
        }
        else count++;

        // if the array has 2 or more 0's then all elements of the product array will be 0's
        if (count >= 2)
        {
            multi = 0;
            break;
        }
    }

    // change nums array to a productexceptself array
    for (int i = 0; i < numsSize; i++)
    {
        // no zeros in nums
        if (*(nums + i) != 0 && !count)
        {
            *(nums + i) = multi / *(nums + i);
        }
        // one or more zero in nums, so if *(nums + i) is not zero, then the product of other elements will be 0
        else if(*(nums + i) != 0) *(nums + i) = 0;
        // the case *(nums + i) is zero
        else *(nums + i) = multi;
    }
    return nums;
}