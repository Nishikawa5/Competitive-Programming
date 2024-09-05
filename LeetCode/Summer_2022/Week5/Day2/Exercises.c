#include <stdio.h>
#include <stdlib.h>


// given a grid, return the shortest path from [0][0] to [gridSize - 1][*gridColSize - 1]
// it's only possible to travel by zeros

// could not make dfs work (time limit exceeded)
int shortestPathBinaryMatrix2(int** grid, int gridSize, int* gridColSize)
{
    if (grid[gridSize - 1][*gridColSize - 1]) return -1;
    
    dfsShortest(grid, gridSize, *gridColSize, 0, 0, 0);
    
    return grid[gridSize - 1][*gridColSize - 1] ? grid[gridSize - 1][*gridColSize - 1]:-1;
}


void dfsShortest(int** grid, int gridSize, int gridColSize, int i, int j, int count)
{
    if (i >= 0 && i < gridSize && j >= 0 && j < gridColSize && 
    (!grid[i][j] || grid[i][j] != 1 && count < grid[i][j] && count < grid[gridSize - 1][gridColSize - 1]))
    {
        count++;

        grid[i][j] = count;

        dfsShortest(grid, gridSize, gridColSize, i + 1, j + 1, count);
        
        dfsShortest(grid, gridSize, gridColSize, i + 1, j, count);
        dfsShortest(grid, gridSize, gridColSize, i + 1, j - 1, count);

        dfsShortest(grid, gridSize, gridColSize, i, j + 1, count);
        dfsShortest(grid, gridSize, gridColSize, i - 1, j + 1, count);

        dfsShortest(grid, gridSize, gridColSize, i - 1, j, count);
        dfsShortest(grid, gridSize, gridColSize, i, j - 1, count);
        dfsShortest(grid, gridSize, gridColSize, i - 1, j - 1, count);
    }
    return;
}




// given a board of O's and X's, change it to after all O's have been flipped
// an O is flipped if it is not connected to another O that will not be flipped
// an O will not be flipped if it is connected to the border
void solve(char** board, int boardSize, int* boardColSize)
{
    /*
      To check the connected O's to the board I used dfs on all the O's connected to the border and marked them
      as 'S', this means that this O will not be flipped and after that changed all the S's to O's and all the remaining O's to X's
    */

    // check the O's connected to the border O
    for (int row = 0; row < boardSize; row++)
    {
        dfsolve (board, boardSize, *boardColSize, row, 0);
        dfsolve (board, boardSize, *boardColSize, row, *boardColSize - 1);
    }
    for (int col = 0; col < *boardColSize; col++)
    {
        dfsolve (board, boardSize, *boardColSize, 0, col);
        dfsolve (board, boardSize, *boardColSize, boardSize - 1, col);
    }

    // change the board
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < *boardColSize; j++)
        {
            if (board[i][j] == 'S') board[i][j] = 'O';
            else board[i][j] = 'X';
        }
    }
}

// check all connected O's
void dfsolve (char** board, int boardSize, int boardColSize, int i, int j)
{
    if (i >= 0 && i < boardSize && j >= 0 && j < boardColSize && board[i][j] == 'O')
    {
        board[i][j] = 'S';

        dfsolve (board, boardSize, boardColSize, i + 1, j);
        dfsolve (board, boardSize, boardColSize, i, j + 1);
        dfsolve (board, boardSize, boardColSize, i - 1, j);
        dfsolve (board, boardSize, boardColSize, i, j - 1);
    }

    return;
}




/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

// quicksort
// swap 2 addresses
void swap(int **a, int **b) 
{
    int* t = *a;
    *a = *b;
    *b = t;
}

int partition(int** array, int low, int high) 
{
    
    int pivot = array[high][0];
    
    int i = (low - 1);


    for (int j = low; j < high; j++) 
    {
        if (array[j][0] <= pivot) 
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[high]);
    
    return (i + 1);
}

void quickSort(int** array, int low, int high) {
    if (low < high) 
    {
        
        int pi = partition(array, low, high);
        
        quickSort(array, low, pi - 1);
        
        quickSort(array, pi + 1, high);
    }
}


// given an array of intervals, return an array without overlapping intervals
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes)
{

    quickSort(intervals, 0, intervalsSize - 1);

    int resind = 0;
    for (int i = 1; i < intervalsSize; i++)
    {
        // the intervals are sorted, so we can check if the initial interval continues after the start of next interval
        // and stops before the end of next interval. If it is true, change the end of current interval
        // if it is not true and the start of next interval is greater than the end of current interval, add another interval to the array
        // else do nothing
        if (intervals[resind][1] >= intervals[i][0] && intervals[resind][1] <= intervals[i][1])
        {
            intervals[resind][1] = intervals[i][1];
        }
        else if (intervals[resind][1] < intervals[i][0])
        {
            intervals[++resind] = intervals[i];
        }
    }

    *returnSize = ++resind;

    returnColumnSizes[0] = malloc((resind) * sizeof(int));
    for (int i = 0; i < resind; i++) returnColumnSizes[0][i] = 2;


    return intervals;
}

// given an array of sorted integers change it to remove duplicates and return the size of new array with duplicates removed
int removeDuplicates(int* nums, int numsSize)
{
    // start from second element
    int left = 1;

    for (int right = 1; right < numsSize; right++)
    {
        // check if the consecutive elements are different, if it is, change the left
        if (nums[right - 1] != nums[right]) nums[left++] = nums[right];
    }

    return left;
}