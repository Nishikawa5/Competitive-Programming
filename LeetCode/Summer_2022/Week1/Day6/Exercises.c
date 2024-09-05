#include <stdio.h>
#include <stdlib.h>



// given an array, returns the product of the subarray that has the largest product
int maxProduct(int* nums, int numsSize)
{
    int max = *nums;

    // minprod stores the current minimum product
    // maxprod stores the current maximum product
    for (int i = 1, minprod = max, maxprod = max; i < numsSize; i++)
    {
        // maxprod gains the value of minprod and minprod gains the value of maxprod
        if (*(nums + i) < 0)
        {
            maxprod = minprod + maxprod;
            minprod = maxprod - minprod;
            maxprod = maxprod - minprod;
        }

        // if the current maxprod is less than the current element, maxprod gains the element value else multiply
        if (maxprod * *(nums + i) > *(nums + i)) maxprod *= *(nums + i);
        else maxprod = *(nums + i);

        // if the current minprod is greater than the current element, minprod gains the element value else multiply
        if (minprod * *(nums + i) < *(nums + i)) minprod *= *(nums + i);
        else minprod = *(nums + i);


        // max stores the greatest value of maxprod
        if(max < maxprod) max = maxprod;
    }

    return max;
}


// given an array of numbers, returns the maximum product of 3 non-equal elements in the array.
int maximumProduct(int* nums, int numsSize)
{
    int max1 = -1001, max2 = -1001, max3 = -1001, min1 = 1001, min2 = 1002;

    /*
      The maximum product of 3 non-equal elements have 2 possibilities:
       - 2 negative elements and 1 positive element
       - 3 positive elements
      So we need to find the 3 maximum elements in the array and the 2 minimum element in the array
      multiply those 2 minimum and the maximum
      multiply those 3 maximum
      compare them
      return the greatest
    */

    
    for (int i = 0; i < numsSize; i++)
    {
        if (max1 < *(nums + i))
        {
            max3 = max2;
            max2 = max1;
            max1 = *(nums + i);
        }
        else if (max2 < *(nums + i))
        {
            max3 = max2;
            max2 = *(nums + i);
        }
        else if (max3 < *(nums + i)) max3 = *(nums + i);

        if(min1 > *(nums + i))
        {
            min2 = min1;
            min1 = *(nums + i);
        }
        else if (min2 > *(nums + i)) min2 = *(nums + i);
    }

    return (min1*min2*max1 > max1*max2*max3) ? min1*min2*max1:max1*max2*max3;
}



/*
   Given an array and its sizes, this function modifies the array according to the following rules:
    - Any live cell with fewer than two live neighbors dies as if caused by under-population.
    - Any live cell with two or three live neighbors lives on to the next generation.
    - Any live cell with more than three live neighbors dies, as if by over-population.
    - Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
*/
void gameOfLife(int** board, int boardSize, int* boardColSize)
{
    // allocate an array to store the board values
    // allocating rows:
    int ** tempboard = malloc(boardSize * sizeof(int*));

    // array of steps to check tempboard 1's
    int steps[8][2] = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};

    // check if the steps is outside the matrix and how many 1's are around the current element
    int checkrow, checkcol, count;

    // allocating columns:
    for(int i = 0; i < boardSize; i++) *(tempboard + i) = malloc(*boardColSize * sizeof(int));
    // copying elements:
    for(int i = 0; i < boardSize; i++)
    {
        for(int j = 0; j < *boardColSize; j++)
        {
            *(*(tempboard + i) + j) = *(*(board + i) + j);
        }
    }

    
    for(int i = 0; i < boardSize; i++)
    {
        for(int j = 0; j < *boardColSize; j++)
        {
            count = 0;
            // checking how many 1's are around the element
            for (int k = 0; k < 8; k++)
            {
                checkrow = i + steps[k][0];
                checkcol = j + steps[k][1];

                // check if the step is in the matrix
                if ((checkrow >= 0 && checkcol >= 0) && (checkrow < boardSize && checkcol < *boardColSize))
                {
                    // in the matrix, then check if the surrounding is 1 or 0; if 1 count++
                    if (*(*(tempboard + checkrow) + checkcol)) count++;
                }
            }
            // applying the rules
            if (count == 3) *(*(board + i) + j) = 1;
            else if (count != 2) *(*(board + i) + j) = 0;
        }
    }

    // freeing the board allocated
    for (int i = 0; i < boardSize; i++) free(*(tempboard + i));
    free(tempboard);
}