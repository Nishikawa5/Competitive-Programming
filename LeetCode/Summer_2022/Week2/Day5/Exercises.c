#include <stdio.h>
#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize);

void main(void)
{
    int **matrix = malloc(3*sizeof(int*));
    for (int i = 0; i < 3; i++) *(matrix + i) = malloc(4*sizeof(int));
    int *retsuze = malloc(sizeof(int));
    *retsuze = 4;

    for (int i = 0; i < 3; i++) for (int j = 0; j < 4; j++) matrix[i][j] = i + j;
    for (int i = 0; i < 3; i++) {for (int j = 0; j < 4; j++) printf("%d", matrix[i][j]); printf("\n");}


    int * temp = spiralOrder(matrix, 3, retsuze, retsuze);

    for (int i = 0; i < *retsuze; i++) printf("%d ", temp[i]);
}





//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
 };

// given a linked list, return the linked list with n-th node removed
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    struct ListNode * temp = head;
    int count = 0;

    // counts how many nodes the list have
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    // temp goes to the node before the selected node
    temp = head;
    for (int i = 0, iter = count - n - 1; i < iter; i++)
    {
        temp = temp->next;
    }


    // exists a node before (change the head)
    if (count - n) temp->next = temp->next->next;
    // no node before (first element)
    else return temp->next;


    return head;
}

// faster, cleaner
struct ListNode* removeNthFromEnd2(struct ListNode* head, int n)
{
    struct ListNode* fast = head;
    struct ListNode* slow = head;

    // advance n nodes
    for (int i = 0; i < n; i++) fast = fast->next;
    // when advancing n nodes, if fast goes to NULL, it means that it's removing the first element of the linked list
    if (!fast) return slow->next;

    fast = fast->next; // the loop stops just before the element to be removed
    // fast has already moved n + 1 elements, so slow will move the lenght of linked list - (n + 1)
    while (fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    // slow is just before the element to be removed
    slow->next = slow->next->next;

    return head;
}



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// given a array and its sizes, return a vector of the elements in spiral order
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize)
{
    // method used: to iterate through the matrix in spiral, it always goes from L to R, U to D, R to L, D to U
    // and it decreases the number of iterations by 1 for each iteration

    int steps[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // right down left up

    int quant[2], pos[2];
    int temp = 0;

    // quant is a vector to control the for loops
    quant[1] = matrixSize - 1;
    quant[0] = *matrixColSize - 1;

    // pos is a vector to control the position of element to put in the vector
    pos[0] = 0;
    pos[1] = *matrixColSize - 1;

    // vector to return
    int *res = malloc(matrixSize * *matrixColSize * (sizeof(int)));

    // goes through the first row (the first row is irregular in this method)
    for (int i = 0; i < *matrixColSize; i++) res[temp++] = matrix[0][i];

    // the return size, used to control the for loop
    *returnSize = matrixSize * *matrixColSize;

    // if temp == *returnSize, then all elements is in the vector
    for (int i = 1; temp != *returnSize; i++)
    {
        // varies the position in according to the method and store the element in this position in the vector
        for (int k = 0, numstp = quant[i % 2]; k < numstp; k++)
        {
            pos[0] += steps[i % 4][0];
            pos[1] += steps[i % 4][1];
            
            res[temp++] = matrix[pos[0]][pos[1]];
        }
        // the quantity of next iteration on (up or down (1)) or (left or right (0)) decreases by 1
        quant[i % 2]--;
    }

    return res;
}


// given a matrix, rotate it by 90 degrees
void rotate(int** matrix, int matrixSize, int* matrixColSize)
{
    int temp;
    // swap first row with last one, second row with second last one, ...
    for (int i = 0, n = matrixSize - 1; i < n; i++, n--)
    {
        for (int j = 0; j < * matrixColSize; j++)
        {
            temp = matrix[i][j];
            matrix[i][j] = matrix[n][j];
            matrix[n][j] = temp;
        }
    }

    // change the matrix symmetry
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = i + 1; j < *matrixColSize; j++)
        {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

}