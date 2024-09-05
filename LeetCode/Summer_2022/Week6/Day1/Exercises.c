#include <stdio.h>
#include <stdlib.h>


// given a signed integer, reverse it
int reverse(int x)
{
    int n = 0;
    for (; x != 0; x /= 10)
    {
        // n * 10 + x % 10 >= INT_MIN    =>      n * (10/10) + (x % 10)/10 >= INT_MIN/10
        // => n >= INT_MIN/10;
        if (n >= -214748364 && n <= 214748364)
        {
            n = n * 10 + x % 10;
        }
        else return 0;
    }
    return n;
}

// approach 2:
int reverse2(int x)
{
    int result = 0;
    for (; x; x /= 10)
    {
        int newResult = result * 10 + x % 10;

        if (newResult / 10 != result) return 0; // newResult overflows 

        result = newResult;
    }
    return result;
}




struct ListNode {
    int val;
    struct ListNode *next;
};

// given two linked lists, return the linked list they intercept each other
// NULL if they don't
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) 
{
    struct ListNode* temp;

    // The lenght of the linked lists will be = (lenght of linked list to return) + (lenght of nodes before)
    // so we can make the nodes before the linked list to return the same size
    // after that, run both until they are equal

    // getting lenghts
    int lenA = 0;
    temp = headA;
    while (temp)
    {
        temp = temp->next;
        lenA++;
    }
    int lenB = 0;
    temp = headB;
    while (temp)
    {
        temp = temp->next;
        lenB++;
    }

    // same size of nodes before
    int diff = lenA - lenB;
    if (diff > 0)
    {
        for (int i = 0; i < diff; i++)
        {
            headA = headA ->next;
        }
    }
    else
    {
        diff = -diff;
        for (int i = 0; i < diff; i++)
        {
            headB = headB->next;
        }
    }

    // run both
    while (headA)
    {
        if (headA == headB) return headA;
        headA = headA->next;
        headB = headB->next;
    }

    return NULL;
}

// approach 2:
struct ListNode *getIntersectionNode2(struct ListNode *headA, struct ListNode *headB) 
{
    struct ListNode* ptrA = headA;
    struct ListNode* ptrB = headB;

    /*
      Both pointers go to the end of their heads, if they don't meet, both switch heads after reaching the end.
      After both reached the end and switched heads, they will have the same number of nodes before the intersection
      linked list. So now we just need to run both at the same time and they will either point to the same node or to NULL

      Suppose the linked list A has n elements more than the other. Therefore the linked list B will reach NULL n iterations before A
      Now linked list advance n nodes until A reaches the end and switch to B. Now both have the same number of elements,
      thats means they have the (intersection linked list + before linked list) (before linked list A = before linked list B)
    */

    while (ptrA != ptrB)
    {
        ptrA = ptrA ? ptrA->next:headB;
        ptrB = ptrB ? ptrB->next:headA;
    }

    return ptrA;
}



int numDecodings(char * s)
{
    int p = 1, pp, n = strlen(s);
    for(int i = n-1; i >= 0; i--) 
    {
        int cur = s[i]=='0' ? 0 : p;
        if (i < n-1 && (s[i] == '1' || s[i] == '2' && s[i+1]<'7')) cur+=pp;
        pp = p;
        p = cur;
        
    }
    return p;   
}


// given a string of numbers, return the number of combination of decoded numbers
// 1 -> A, 2 -> B, ... , 26 -> Z;
int numDecodings(char * s)
{
    // p - previous, pp - previous previous
    int p = 1, pp, n = strlen(s) - 1;
    // runs from right to left
    // cur is the current number of combinations
    // p is the previous number of combinations
    // pp is previous of the previous number of combinations
    // the current number is not a zero, so we can add every previous combination to cur
    // and if this number form another decoded letter, add the previous previous to the cur combination
    // if a '0' appears, than the number of combinations will be the previous previous (10 1, not possible to make more combinations)
    for(int i = n; i >= 0; i--) 
    {
        int cur = (s[i]=='0') ? 0 : p;
        if (i < n && (s[i] == '1'|| s[i] == '2' && s[i+1]<'7')) cur += pp;
        pp = p;
        p = cur;
        
    }
    return p;   
}