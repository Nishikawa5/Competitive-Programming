#include <stdio.h>
#include <stdlib.h>

char * reverseWords(char * s);

// can't change constant string
void main(void)
{
    char *str = malloc(100 * sizeof(char));
    scanf(" %[^\n]", str);

    printf("%s", reverseWords(str));
}




// given a string, reverse it
void reverseString(char* s, int sSize)
{
    char temp;
    // change the first to the last, the second to the last-1 and so on
    for (int i = 0, j = sSize - 1; i < j; i++, j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

// the same thing but a better memory use
void reverseString2(char* s, int sSize)
{
    sSize--;
    for (int i = 0; i < sSize; i++, sSize--)
    {
        s[i] = s[i] + s[sSize];
        s[sSize] = s[i] - s[sSize];
        s[i] = s[i] - s[sSize];
    }
}


// given a changeable string, return a string that has its words reversed
char * reverseWords(char * s)
{
    int i = 0;
    int j = 0;
    char temp;
    while (s[i] != '\0')
    {
        // localize the index that separates words
        if (s[i] == ' ')
        {
            // change the first and last letters of word, second and last-1, and so on
            for (int k = j, n = i - 1; k < n; k++, n--)
            {
                temp = s[k];
                s[k] = s[n];
                s[n] = temp;
            }
            j = i + 1;
        }
        i++;
    }

    // reverse the last word
    for (int k = j, n = --i; k < n; k++, n--)
    {
        temp = s[k];
        s[k] = s[n];
        s[n] = temp;
    }
    return s;
}







// given a matrix, change every row that has a 0 to 0 and every column that has a 0 to 0
void setZeroes(int** matrix, int matrixSize, int* matrixColSize)
{
    int c = 0, col = 0, row = 0;
    // if c is 1 then after change every element in col and row 0 to 0
    if (!matrix[0][0])
    {
        c = 1;
    }
    // else verify the other states
    else
    {
        for (int i = 0; i < matrixSize; i++)
        {
            if (!matrix[i][0]) col = 1;
        }
        for (int j = 0; j < *matrixColSize; j++)
        {
            if (!matrix[0][j]) row = 1;
        }
    }

    // turns the first element in the row and the first element in the column to zero if verify a zero
    for (int i = 1; i < matrixSize; i++)
    {
        for (int j = 1; j < *matrixColSize; j++)
        {
            if (!matrix[i][j])
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // change every element in the column to zero if the first element checked is 0
    for (int j = 1; j < *matrixColSize; j++)
    {
        if (!matrix[0][j])
        {
            for(int i = 0; i < matrixSize; i++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    // change every element in the row to zero if the first element checked is 0
    for (int i = 1; i < matrixSize; i++)
    {
        if (!matrix[i][0])
        {
            for (int j = 1; j < *matrixColSize; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    if (c)
    {
        for (int i = 0; i < matrixSize; i++) matrix[i][0] = 0;
        for (int j = 0; j < *matrixColSize; j++) matrix[0][j] = 0;
    }
    else
    {
        if (col) for (int i = 0; i < matrixSize; i++) matrix[i][0] = 0;
        if (row) for (int j = 0; j < *matrixColSize; j++) matrix[0][j] = 0;
    }
}