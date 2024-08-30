#include <stdio.h>
#include <stdlib.h>




/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

struct ListNodee {
    unsigned long int val;
    int counter;
    int numberofchar;
    struct ListNodee *next;
};


struct ListNode {
    int val;
    struct ListNode *next;
};

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    unsigned long int constant = 1e12; // to avoid overflow

    // to use in hash
    // there's no other integer multiplication that result in a multiplication of prime numbers
    int primes[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
    int count = 0;

    // linked list to store the hash values
    struct ListNodee* head = malloc(sizeof(struct ListNodee));
    head->next = NULL;
    struct ListNodee* aux;
    struct ListNodee* temp = head;
    unsigned long int mult;
    
    // get the data to create the result matrix
    for (int i = 0, k; i < strsSize; i++)
    {
        mult = 1;
        k = 0;
        aux = head->next;

        // hash
        while (strs[i][k] != '\0')
        {
            mult *= primes[strs[i][k] - 'a'];
            mult %= constant;
            k++;
        }

        while (aux != NULL && aux->val != mult)
        {
            temp = aux;
            aux = aux->next;
        }

        // create a new node if the multiplication is not encountered
        if (!aux)
        {
            temp->next = malloc(sizeof(struct ListNodee));
            temp->next->counter = 1;
            temp->next->numberofchar = k + 1;
            temp->next->val = mult;
            temp->next->next = NULL;
        }
        // encountered, them add 1 in counter to create the resulting matrix
        else
        {
            aux->counter++;
        }
    }

    // number of nodes (number of rows in the string matrix)
    aux = head->next;
    while (aux != NULL)
    {
        count++;
        aux = aux->next;
    }

    // return informations and creating res matrix
    aux = head->next;
    char*** res = malloc(count * sizeof(char**));
    *returnSize = count;
    *returnColumnSizes = malloc(count * sizeof(int));
    for (int i = 0; i < count; i++)
    {
        res[i] = malloc(aux->counter * sizeof(char*));

        *((*returnColumnSizes) + i) = aux->counter;
        for (int j = 0; j < aux->counter; j++)
        {
            res[i][j] = malloc(aux->numberofchar * (sizeof(char)));
        }

        aux = aux->next;
    }


    // vector of indexes
    int* indvect = malloc(count * sizeof(int));
    for (int i = 0; i < count; i++) indvect[i] = 0;

    for (int i = 0, k, index; i < strsSize; i++)
    {
        mult = 1;
        k = 0;
        index = 0;
        aux = head->next;

        // multiply again to add in the res matrix
        while (strs[i][k] != '\0')
        {
            mult *= primes[strs[i][k] - 'a'];
            k++;
        }

        while (aux->val != mult)
        {
            aux = aux->next;
            mult %= constant;
            index++;
        }

        // stores the string in matrix
        res[index][indvect[index]++] = strs[i];
    }

    return res;
}



// given 2 linked lists, merge them
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    // if one of the lists is null, return the not null list (no more elements to merge in the other list)
    if (!list1) return list2;
    if (!list2) return list1;

    // keep the lowest element in the list and change its next to the partially merged list until merge every element
    if (list1->val < list2->val)
    {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
    else
    {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}

// given a linked list, reverse it
struct ListNode* reverseList(struct ListNode* head)
{
    if (!head || !(head->next)) return head;

    struct ListNode* new_head = reverseList(head->next);
    struct ListNode* new_tail = head->next;
    new_tail->next = head;
    head->next = NULL;

    return new_head;
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// given an array of numbers and a vector, return the index of numbers that sums up to target
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int maxnum = 0;
    int minnum = 0;
    *returnSize = 2;
    int *res = malloc(2*sizeof(int));

    // find the max positive number and mininum negative number to form the hash array
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] >= maxnum) maxnum = nums[i];
        else if (nums[i] <= minnum) minnum = nums[i];
    }

    // mallocs the array
    int *map = malloc((maxnum - minnum + 1) * sizeof(int));
    // puts all element in map array to 0
    memset(map, 0, (maxnum - minnum + 1) * sizeof(int));

    // check if there's an element in hash that corresponds to target - nums[i], because
    // target - nums[i] + nums[i] = target
    // if don't have, them add the index of element to the hash.
    for (int i = 0, lookfornum; i < numsSize; i++)
    {
        lookfornum = target - nums[i];

        if (lookfornum <= maxnum && lookfornum >= minnum && map[lookfornum - minnum])
        {
            res[0] = i;
            res[1] = map[lookfornum - minnum] - 1;
            break;
        }
        else map[nums[i] - minnum] = i + 1;
    }

    return res;
}