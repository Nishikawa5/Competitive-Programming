#include <stdio.h>
#include <stdlib.h>


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// given the row index of pascal triangle, return it
int* getRow(int rowIndex, int* returnSize)
{
    *returnSize = rowIndex + 1;

    int* ans = malloc(*returnSize * sizeof(int));
    memset(ans, 0, *returnSize * sizeof(int));

    // ans[0] is the pascal triangle row 0
    ans[0] = 1;
    for (int i = 1; i < *returnSize; i++)
    {
        for (int j = i; j >= 1; j--)
        {
            // we can continue the pascal triangle by adding the most right number - 1 to the most right
            ans[j] += ans[j - 1];
        }
    }
    return ans;
}



/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void swapdir(int* x, int* y);

// given an integer n, return a spiral matrix that has n rows and n columns
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes)
{
    // return info
    *returnSize = n;
    returnColumnSizes[0] = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) returnColumnSizes[0][i] = n;

    // mallocating the array
    int** ans = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) 
    {
        ans[i] = malloc(n * sizeof(int));
        memset(ans[i], 0, n * sizeof(int));
    }
    
    // directions of x and y: 
    //   |left -> right|      | up -> down  |      |right -> left |      | down -> up    |
    //   |dy = 0 dx = 1|      |dy = 1 dx = 0|      |dy = 0 dx = -1|      | dy = -1 dx = 0|

    int dy = 0;
    int dx = 1;

    int x = 0;
    int y = 0;
    for (int i = 1, tot = n*n; i <= tot; i++)
    {
        // put the element
        ans[y][x] = i;

        // condition to change the directions (out of matrix or already existing element)
        if (x + dx >= n || x + dx < 0 || y + dy >= n || y + dy < 0 || ans[y + dy][x + dx])
        {
            swapdir(&dx, &dy);
        }
        // advance the direction
        x += dx;
        y += dy;
    }
    return ans;
}

// swap the directions
void swapdir(int* x, int* y)
{
    int temp = *x;
    *x = -*y;
    *y = temp;
}



// given a matrix with sorted rows and columns and a target, return true if the target is in the matrix
int searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target)
{
    // starting from the last element on first row
    int row = 0;
    int col = *matrixColSize - 1;

    /*
       The rows are sorted, so if the current element is bigger than the target, go to previous columns if possible
       the columns are sorted, so if the current element is smallet than the target, go to the next row if possible
    */

    while (row < matrixSize && col >= 0)
    {
        if (matrix[row][col] == target) return 1;
        else if (matrix[row][col] > target) col--;
        else if (matrix[row][col] < target) row++;
    }

    return 0;
}



/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
// given an array of integers (color numbers) return the matrix avaraged in 3x3 to make the image smoother
int** imageSmoother(int** img, int imgSize, int* imgColSize, int* returnSize, int** returnColumnSizes)
{
    // creating the array and return infos
    int** res = malloc(imgSize * sizeof(int*));
    *returnSize = imgSize;
    returnColumnSizes[0] = malloc(imgSize * sizeof(int));
    for (int i = 0; i < imgSize; i++)
    {
        returnColumnSizes[0][i] = *imgColSize;
        res[i] = malloc(*imgColSize * sizeof(int));
    }

    // every possible combination of it in vector of 2 is all directions
    int steps[3] = {0, 1, -1};
    int sum, div;


    for (int i = 0; i < imgSize; i++)
    {
        for (int j = 0; j < *imgColSize; j++)
        {
            sum = 0;
            div = 0;

            // calculate the sum of all directions
            for (int m = 0; m < 3; m++)
            {
                for (int n = 0; n < 3; n++)
                {
                    if (steps[m] + i >= 0 && steps[m] + i < imgSize &&
                    steps[n] + j >= 0 && steps[n] + j < *imgColSize)
                    {
                        sum += img[steps[m] + i][steps[n] + j];
                        div++;
                    }
                }
            }

            // store it in res
            res[i][j] = sum/div;
        }
    }


    return res;
}