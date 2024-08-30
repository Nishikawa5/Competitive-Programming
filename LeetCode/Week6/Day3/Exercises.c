#include <stdio.h>
#include <stdlib.h>


// maximum of 3 numbers
#define MAX(a,b,c) c > (a > b ? a:b) ? c:(a > b ? a:b)

// given 2 strings, return the length of the maximum subsequence of them
int longestCommonSubsequence(char * text1, char * text2)
{
    // lengths (1 <= len1, len2 <= 1000)
    unsigned short len1 = strlen(text1), len2 = strlen(text2);

    // mallocating matrix , can be done using only a vector
    short* dp = malloc((len2 + 1) * sizeof(short));
    memset(dp, 0, (len2 + 1) * sizeof(short));

 
    int curval, preval;

    for (short i = 0; i < len1; i++)
    {
        preval = 0;
        for (short j = 0; j < len2; j++)
        {
            // stores the current maximum subsequence length in dp as seen in image, but for a vector
            curval = dp[j + 1];
            dp[j + 1] = MAX(dp[j], dp[j + 1], preval + (text1[i] == text2[j]));
            preval = curval;
        }
    }

    return dp[len2];
}




// given 2 strings, return the minimum number of steps to make word1 == word2
int minDistance(char * word1, char * word2)
{
    // get the LongestCommonSubsequence
    unsigned short len1 = strlen(word1), len2 = strlen(word2);

    short* dp = malloc((len2 + 1) * sizeof(short));
    memset(dp, 0, (len2 + 1) * sizeof(short));

    int curval, preval;

    for (short i = 0; i < len1; i++)
    {
        preval = 0;
        for (short j = 0; j < len2; j++)
        {
            curval = dp[j + 1];
            dp[j + 1] = MAX(dp[j], dp[j + 1], preval + (word1[i] == word2[j]));
            preval = curval;
        }
    }

    // length of word1 - LCS + word2 - LCS
    // every character of word1 that is not part of subsequence will have to be deleted, and this is word1 - LCS operations
    // and every character that is in word2 but not part of subsequence will have to be typed, and this is word2 - LCS operations
    // and vice versa
    return len1 + len2 - 2* dp[len2];
}





struct ListNode {
    int val;
    struct ListNode *next;
};

// reverse a linked list (used this)
struct ListNode* reverseList2(struct ListNode* head)
{
    struct ListNode* next = NULL;
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;

    while (cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
}






struct ListNode* reverseList(struct ListNode* begin, struct ListNode* end);

// given a linkedlist, reverse it in groups of k
struct ListNode* reverseKGroup(struct ListNode* head, int k)
{
    // we allocate a dummy node to change the initial node
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->next = head;

    struct ListNode* begin = dummy;

    int n = 0;
    // iterate through the list
    while (head)
    {
        n++;

        // find a group to reverse
        if (n % k == 0)
        {
            begin = reverseList(begin, head->next);
            head = begin->next;
        }
        else
        {
            head = head->next;
        }
    }
    return dummy->next;
}

// given 2 points of a linked list, return it reversed
struct ListNode* reverseList(struct ListNode* begin, struct ListNode* end)
{
    struct ListNode* next;
    struct ListNode* prev = begin;
    struct ListNode* cur = begin->next;

    struct ListNode* first = cur;


    while (cur != end)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    begin->next = prev;
    first->next = cur;
    return first;
}