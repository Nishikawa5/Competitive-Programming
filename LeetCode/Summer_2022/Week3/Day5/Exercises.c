#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};


// given a linked list, return it so that the odd elements are all before the even elements
// (odd and even elements must be in the same order as before)
struct ListNode* oddEvenList1stsol(struct ListNode* head)
{
    if (!head) return NULL;

    /*
      aux will be the linked list of odd elements
      temp will be the linked list of even elements

      then join them together
    */

    struct ListNode* aux = head;
    struct ListNode* temp = aux->next;
    struct ListNode* tempaux = temp;

    while (aux != NULL && aux->next != NULL && aux->next->next != NULL)
    {
        aux->next = aux->next->next;
        aux = aux->next;

        tempaux->next = aux->next;
        tempaux = tempaux->next;
    }
    aux->next = temp;


    return head;
}


// the same logic, but better writen
struct ListNode* oddEvenList(struct ListNode* head)
{
    if (!head) return NULL;

    struct ListNode* odd = head;
    struct ListNode* evenhead = odd->next;
    struct ListNode* even = evenhead;

    // even will goes beyond odd in every iteration, so we just need to check even->next and even
    while (even->next && even)
    {
        // get the next odd/even elements
        odd->next = odd->next->next;
        even->next = even->next->next;
        
        // advance
        odd = odd->next;
        even = even->next;
    }
    // put them together
    odd->next = evenhead;


    return head;
}





/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// to exclude elements, it's better to exclude from left to right in this case
// if the left element is far from the right element, it just need to go 1 time to the right
// but in the same case from left to right, we need to go many times from left to right
// applying queue
struct queue {
    int val;
    int index;
    struct queue *next;
    struct queue *back;
};

// given an array, return an array of maximum values of windows of k elements
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize)
{
    // res array
    *returnSize = (numsSize - k + 1);
    int* res = malloc(*returnSize * sizeof(int));


    struct queue* head = malloc(sizeof(struct queue));
    head->val = INT_MIN;
    struct queue* tail = head;
    struct queue* aux;

    k--;
    for (int i = 0, m = numsSize, c = 0; i < m; i++)
    {
        // nums[i] is greater than all elements in queue, so add it to the queue and exclude others
        if (head->val <= nums[i])
        {
            free(head);
            head = malloc(sizeof(struct queue));
            head->val = nums[i];
            head->index = i;

            // to make the queue easier to control
            head->next = malloc(sizeof(struct queue));
            head->next->val = INT_MIN;


            tail = head;
        }
        // exclude the elements smaller than nums[i]
        else if (tail->val <= nums[i])
        {
            // find the node that has a element smaller than nums[i] and change it (node values are sorted)
            while (tail->val <= nums[i]) tail = tail->back;

            tail = tail->next;
            tail->val = nums[i];
            tail->index = i;

            tail->next = malloc(sizeof(struct queue));
            tail->next->val = INT_MIN;
        }
        // nums[i] is smaller than all other elements, so add it to the end of queue
        else
        {
            aux = tail;
            tail = tail->next;

            tail->val = nums[i];
            tail->index = i;
            tail->back = aux;

            tail->next = malloc(sizeof(struct queue));
            tail->next->val = INT_MIN;
        }

        if (i >= k)
        {
            // the head->val is always bigger than all other elements
            // so we just need to adjust to fit window

            while(head->index < i - k) head = head->next;

            res[c] = head->val;
            c++;
        }
    }


    return res;
}



// given a string, return the maximum substring lenght that if substitute k chars it is all the same chars
int characterReplacement(char * s, int k)
{
    int len = strlen(s);
    int maxsubs = -1;
    int charac[26] = {0};

    /*
      sliding window
      charac array maps the characters in window

      end - start + 1 - maxsubs is the number of characters that are different than the most numerous character in subs
      (end - start + 1 is the window and maxsubs is the number of most numerous character)

      if the number of characters that are different than the most numerous character is greater than k, the condition
      of problem is broken, so start is increased to make the condition true again.

      the window substring is controlled by maxsubs, but it don't have to change
      a substring is only able to have maxsubs greater than the previous maxsubs if the substring is greater
      than the previous substring.
    */

    for (int end = 0, start = 0; end < len; end++)
    {
        if (maxsubs < ++charac[s[end] - 'A']) maxsubs = charac[s[end] - 'A'];

        if (end - start + 1 - maxsubs > k)
        {
            charac[s[start] - 'A']--;
            start++;
        }
    }

    if (maxsubs + k > len) maxsubs = len;
    else maxsubs += k;

    return maxsubs;
}