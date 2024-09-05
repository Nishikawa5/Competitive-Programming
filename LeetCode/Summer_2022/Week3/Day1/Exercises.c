#include <stdio.h>
#include <stdlib.h>
#define bool int
#define false 0
#define true 1

 struct ListNode {
     int val;
     struct ListNode *next;
 };

// given an array of sorted linked lists, merge them
// very bad code:
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
    struct ListNode * res = malloc(sizeof(struct ListNode));
    struct ListNode * aux = res;
    struct ListNode * temporary;

    int temp;
    int c = 0;
    int index;

    // no lists, so return NULL
    if (listsSize == 0) return NULL;

    // check if there's only 1 list with elements or no lists with elements
    for (int i = 0; i < listsSize; i++)
    {
        if (!lists[i])
        {
            c++;
        }
        if (c >= listsSize - 1)
        {
            for (int j = 0; j < listsSize; j++)
            {
                if (lists[j]) return lists[j];
            }
            return NULL;
        }
    }

    while(1)
    {
        c = 0;
        temp = INT_MAX;

        // check how many lists left to merge, if it's 1, return the linked list already merged and the list left
        for (int i = 0; i < listsSize; i++)
        {
            if (lists[i] == NULL) 
            {
                c++;
                if (c >= listsSize - 1) 
                {
                    for (int j = 0; j < listsSize; j++)
                    {
                        if (lists[j])
                        {
                            temporary->next = lists[j];
                            return res;
                        }
                    }
                }
            }
        }

        // stores the smallest element in temp
        for (int i = 0; i < listsSize; i++)
        {
            if (lists[i] && temp >= lists[i]->val)
            {
                temp = lists[i]->val;
                index = i;
            }
        }


        // put the smallest element in the res linked list
        aux->val = temp;
        aux->next = malloc(sizeof(struct ListNode));

        temporary = lists[index];
        lists[index] = lists[index]->next;
        free(temporary);

        temporary = aux;
        aux = aux->next;
    }
}


/*
void reverse(struct ListNode **head)
{
    struct ListNode prev = NULL, curr = *head, next;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
}
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// returns the lenght of linked list
int linkedlistlenght(struct ListNode* head)
{
    int c = 0;
    while (head != NULL)
    {
        c++;
        head = head->next;
    }
    return c;
}

// given a linked list, modify it to go from L0 → L1 → … → Ln - 1 → Ln |to| L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
void reorderList(struct ListNode* head)
{
    int len = linkedlistlenght(head);
    int start = 0;
    // create an array to store the linked list nodes (first node to last in 0, second to last in 1, ..., last)
    struct ListNode **array = malloc(len * sizeof(struct ListNode *));
    struct ListNode *temp = head;

    // stores it
    for(int i = 0; i < len; i++)
    {
        array[i] = temp;
        temp = temp->next;
    }

    len--;
    // connects the first to the last, last to second, second to last - 1, last - 1 to third...
    while (start < len)
    {
        array[start]->next = array[len];
        start++;

        array[len]->next = array[start];
        len--;
    }

    array[start]->next = NULL;
}



// given an array of numbers of jumps, return true if the last element can be reached
bool canJump(int* nums, int numsSize)
{
    numsSize--; // don't need the last element of the array
    for (int i = 0, jumps = 1; i < numsSize; i++)
    {
        jumps--; // decrement by 1 per iteration (you need to use 1 jump to go to the next iteration)

        // nums[i] represents the max number of jumps and it's possible to jump less times
        // so we just need to store the current maximum number of jumps
        if (nums[i] >= jumps) jumps = nums[i];

        if (!jumps) return false; // return false if it has no more jumps
    }
    return true;
}