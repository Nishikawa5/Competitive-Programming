#include <stdio.h>
#include <stdlib.h>



int checkarea(int** grid, int i, int j, int gridSize, int gridColSize);

// given a grid, return the max area of it (numbers of 1's connected)
int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize)
{
    int maxarea = 0;
    int temp;

    // checks through every element
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < *gridColSize; j++)
        {
            if (grid[i][j])
            {
                temp = checkarea(grid, i, j, gridSize, *gridColSize);
                if (temp > maxarea) maxarea = temp;
            }
        }
    }
    return maxarea;
}

// given a grid, and the index of its elements, return the numbers of 1's connecting to it
// bfs
int checkarea(int** grid, int i, int j, int gridSize, int gridColSize)
{
    if (i < 0 || i >= gridSize || j < 0 || j >= gridColSize || !grid[i][j]) return 0;

    grid[i][j] = 0;

    return 1 + checkarea(grid, i + 1, j, gridSize, gridColSize) + checkarea(grid, i - 1, j, gridSize, gridColSize) + checkarea(grid, i, j + 1, gridSize, gridColSize) + checkarea(grid, i, j - 1, gridSize, gridColSize);

}



/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


void checkflood(int** image, int imageSize, int imageColSize, int i, int j, int color, int constantcolor);

// given a matrix of image numbers, return this array with new colors (a number is a color)
int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes)
{
    // change only if the new color is different to the color
    if (image[sr][sc] != color) checkflood(image, imageSize, *imageColSize, sr, sc, color, image[sr][sc]);

    // necessary to give the correct output in leetcode
    *returnSize = imageSize;

    *returnColumnSizes = malloc(imageSize * sizeof(int));
    for (int i = 0; i < imageSize; i++) *(*(returnColumnSizes + 0) + i) = *imageColSize;


    return image;
}

// bfs
// given a matrix of numbers, return this array with new numbers
void checkflood(int** image, int imageSize, int imageColSize, int i, int j, int color, int constantcolor)
{
    // check if the current element is equal to the color we are changing
    if (i >= 0 && i < imageSize && j >=0 && j < imageColSize && image[i][j] == constantcolor)
    {
        // if it is, change it
        image[i][j] = color;

        // and check right/left/up/down
        checkflood(image, imageSize, imageColSize, i + 1, j, color, constantcolor);
        checkflood(image, imageSize, imageColSize, i - 1, j, color, constantcolor);
        checkflood(image, imageSize, imageColSize, i, j + 1, color, constantcolor);
        checkflood(image, imageSize, imageColSize, i, j - 1, color, constantcolor);
    }
    return;
}


// given an array of 0's, 1's and 2's, sort it
void sortColors(int* nums, int numsSize)
{
    int numscount[3] = {0};
    // counts the numbers of 0's, 1's and 2's
    for (int i = 0; i < numsSize; i++)
    {
        numscount[nums[i]]++;
    }
    // put them in place
    for (int i = 0, temp = 0; i < 3; i++)
    {
        for (int j = 0; j < numscount[i]; j++) nums[temp++] = i;
    }
}

// seems a little slower
void sortColors2(int* nums, int numsSize)
{
    int low = 0, high = numsSize - 1;

    // there are 3 numbers, so we can use two pointers:
    for (int i = 0; low < high && i <= high;)
    {
        // test for 0, if zero, change nums[low] to 0 and add 1 (low will always succeed 0's or none)
        if (nums[i] == 0)
        {
            nums[i] = nums[low];
            nums[low] = 0;
            low++;
            i++;
        }
        // test for 2, if two, change nums[high] to 2 and subtract 1 (high will always precede 2's or none)
        else if (nums[i] == 2)
        {
            nums[i] = nums[high];
            nums[high] = 2;
            high--;
        }
        else i++;
    }
}