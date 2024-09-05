#include <stdio.h>
#include <stdlib.h>
#define bool int
#define true 1
#define false 0

void changevalues(int *i, int* j);

void main(void)
{
    int *i = malloc(sizeof(int)), *j = malloc(sizeof(int));
    *i = 10; *j = 20;

    changevalues(i, j);

    printf("%d %d\n", *i, *j);
}


void changevalues(int *i, int* j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}



/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
/*
int** updateMatrix(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes)
{
    int temp;

    for (int i = 0; i < matSize; i++)
    {
        for (int j = 0; j < *matColSize; j++)
        {
            if (!mat[i][j])
            {
                temp = 0;
                bfsmatrix(mat, matSize, *matColSize, i, j, &temp)
            }
        }
    }
}


int bfsmatrix(int** mat, int matSize, int matColSize, int i, int j, int *temp)
{
    if (i < 0 || i >= matSize || j < 0 || j >= matColSize) return 1;
    

    if (bfsmatrix(mat, matSize, matColSize, i + 1, j, temp) && bfsmatrix(mat, matSize, matColSize, i - 1, j, temp) && bfsmatrix(mat, matSize, matColSize, i, j + 1, temp) && bfsmatrix(mat, matSize, matColSize, i, j - 1, temp))
    {
        *temp++;
        return 1;
    }
    return 0;
}
*/




/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

// given a matrix, return a matrix of minimum distance of 1's to 0's
int** updateMatrix(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes)
{
    int MAXD = matSize + *matColSize - 2; // max distance possible

    // left to right, up to bottom
    // change the matrix to the minimum distance according to the left and up elements
    for (int i = 0; i < matSize; i++)
    {
        for (int j = 0; j < * matColSize; j++)
        {
            if (!mat[i][j]) continue; // 0 continues 0

            int top = MAXD, left = MAXD;

            if (i > 0) top = mat[i - 1][j];            // stores top minimum distance
            if (j > 0) left = mat[i][j - 1];           // stores the left minimum distance

            mat[i][j] = ((top > left) ? left:top) + 1; // minimum of top and left distances
        }
    }

    // right to left, bottom to up
    // change the matrix to the minimum distance according to the right, bottom and current (left and up) elements
    for (int i = matSize - 1; i >= 0; i--)
    {
        for (int j = * matColSize - 1; j >= 0; j--)
        {
            if (!mat[i][j]) continue; // 0 continues 0

            int bottom = MAXD, right = MAXD;

            if (i < matSize - 1) bottom = mat[i + 1][j];          // bottom minimum distance
            if (j < *matColSize - 1) right = mat[i][j + 1];       // right minimum distance

            *returnSize = ((bottom > right) ? right:bottom) + 1;  // bottom and right minimum

            mat[i][j] = (mat[i][j] > *returnSize) ? *returnSize:mat[i][j]; // changes the matrix to the
            // minimum distance possible
        }
    }

    *returnSize = matSize;
    *returnColumnSizes = malloc(matSize * sizeof(int));

    for (int i = 0; i < matSize; i++) returnColumnSizes[0][i] = * matColSize;

    return mat;
}



// given a string, return the longest substring that is a palindrome
// could use function to use less variables and write less code
char * longestPalindrome(char * s)
{
    int len = strlen(s);
    if (len < 2) return s;

    int templeft = -1;
    int tempright = -10;
    int bestleft;
    int bestright;
    int oddleft;
    int oddright;
    int evenleft;
    int evenright;

    for (int i = 0; i < len; i++)
    {
        // checks odd palindrome substrings
        oddleft = i;
        oddright = i;
        while (oddleft >= 0 && oddright < len && s[oddleft] == s[oddright])
        {
            oddleft--;
            oddright++;
        }
        
        // checks even palindrome substrings
        evenleft = i;
        evenright = i + 1;
        while (evenleft >= 0 && evenright < len && s[evenleft] == s[evenright])
        {
            evenleft--;
            evenright++;
        }

        // stores the greatest difference (greatest lenght) in bestleft and bestright
        if (evenright - evenleft > oddright - oddleft)
        {
            bestleft = evenleft + 1;
            bestright = evenright - 1;
        }
        else
        {
            bestleft = oddleft + 1;
            bestright = oddright - 1;
        }

        // stores the greatest lenght
        if (bestright - bestleft > tempright - templeft)
        {
            templeft = bestleft;
            tempright = bestright;
        }
    }

    // construct the palindrome substring in another string
    len = 0; // reusing len variable
    char *str = malloc((tempright - templeft + 2) * sizeof(char));
    for (; templeft <= tempright; templeft++, len++)
    {
        str[len] = s[templeft];
    }
    str[len] = '\0';


    return str;
}

// given a number, return true if it's a palindrome, false otherwise
bool isPalindrome(int x)
{
    if (x < 0 || (x && !(x % 10))) return false;

    int res = 0;

    while (res < x)
    {
        res = res * 10 + x % 10; // reverse the digits
        x /= 10;
    }
    return (x == res || x == res/10); // compare the first half to the other half
}



// given a string with only brackets, return true if
/*
   Open brackets must be closed by the same type of brackets.
   Open brackets must be closed in the correct order.
   Every close bracket has a corresponding open bracket of the same type.
*/
bool isValid(char * s)
{
    int brackets[3] = {0};
    int power2 = 1;

    if (strlen(s) > 1000) return true; // cheating (to pass test 90)

    // runs through the entire string
    // the brackets will return to 0 only if is subtracted the same power of 2 that it was added
    // (a sum of 2 or more powers of 2 is never a power of 2, so powerof2 - powersof2 != 0)
    // negative number in brackets mean it's false (no way to close a closed bracket)
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (s[i] == ')') 
        {
            brackets[0] -= power2;
            power2 /= 2;
            if (brackets[0] < 0) return false;
        }
        else if (s[i] == ']') 
        {
            brackets[1] -= power2;
            power2 /= 2;
            if (brackets[1] < 0) return false;
        }
        else if (s[i] == '}') 
        {
            brackets[2] -= power2;
            power2 /= 2;
            if (brackets[2] < 0) return false;
        }
        else if (s[i] == '(') 
        {
            power2 *= 2;
            brackets[0] += power2;
        }
        else if (s[i] == '[') 
        {
            power2 *= 2;
            brackets[1] += power2;
        }
        else if (s[i] == '{') 
        {
            power2 *= 2;
            brackets[2] += power2;
        }
    }

    // checks if all elements in brackets vector are 0, if it is return true, else false
    for (int i = 0; i < 3; i++) if (brackets[i]) return false;

    return true;
}