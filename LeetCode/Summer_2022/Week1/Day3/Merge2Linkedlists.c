#include <stdio.h>
#include <stdlib.h>


struct ListNode {
     int val;
     struct ListNode *next;
 };
 
// Merge 2 sorted lists
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    struct ListNode *aux = malloc(sizeof(struct ListNode));
    struct ListNode *resultlist = aux;
    struct ListNode *temporary;
    int temp;

    // if a list has no elements, then return the elements of other list.
    if(list1 == NULL) return list2;
    else if (list2 == NULL) return list1;

    while(list1 != NULL && list2 != NULL)
    {
        // while both lists have elements, do:

        if (list1->val > list2->val) // compare values to add in the result list
        {
            temp = list2->val;
            list2 = list2->next;
        }
        else
        {
            temp = list1->val;
            list1 = list1->next;
        }

        // new element after the last element of list
        aux->val = temp;
        aux->next = malloc(sizeof(struct ListNode));
        temporary = aux;
        aux = aux->next;
    }
    free(aux); // free the malloc unused

    // the list that still has elements is appended to the end of result
    if (list1 == NULL) temporary->next = list2;
    else temporary->next = list1;


    return resultlist;
}



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// reverse the linked list
struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode* result = NULL;
    struct ListNode* aux;

    while(head != NULL)
    {
        // insert the head value before all elements of result list
        aux = malloc(sizeof(struct ListNode));
        aux->val = head->val;
        aux->next = result;
        result = aux;

        head = head->next;
    }
    return result;
}



// return the max profit given an array of the product prices according to time
// not the best solution (brute force)
int maxProfit(int* prices, int pricesSize)
{
    int temp = 0; // temp = 0 means no profit

    for (int i = 0; i < pricesSize; i++)
    {
        for (int j = i + 1; j < pricesSize; j++)
        {
            // If there's a smaller price you are comparing to, then *(prices + i) is not the best choice
            if (*(prices + i) >= *(prices + j)) break;
            if (*(prices + j) - *(prices + i) > temp) temp = *(prices + j) - *(prices + i); // the maximum difference
        }
    }
    return temp;
}