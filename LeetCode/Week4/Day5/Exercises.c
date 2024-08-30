#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define bool int




// given two strings, return true if after backspacing them, these strings are equal
bool backspaceCompare(char * s, char * t)
{
    int jumps; // count how many characters to jump
    int backS = strlen(s) - 1, backT = strlen(t) - 1;

    /*
      goes from right to left, ignoring the backspaced characters and comparing the not backspaced
    */

    while(1)
    {
        jumps = 0;
        while (backS >= 0 && (s[backS] =='#' || jumps))
        {
            if (s[backS] == '#')
            {
                jumps++;
            }
            else jumps--;
            backS--;
        }

        jumps = 0;
        while (backT >= 0 && (t[backT] =='#' || jumps))
        {
            if (t[backT] == '#')
            {
                jumps++;
            }
            else jumps--;
            backT--;
        }

        // at least one has reached the end of string, so break to compare if both has reached the end
        if (backT == -1 || backS == -1 || t[backT] != s[backS]) break;
        else
        {
            backT--;
            backS--;
        }
    }

    return backS == -1 && backT == -1;
}


// given a string, remove the character before the '*' as the last exercise
char * removeStars(char * s)
{
    int jumps;
    int endS = strlen(s) - 1;
    int address = endS;

    while (1)
    {
        // same logic
        jumps = 0;
        while (endS >= 0 && (s[endS] == '*' || jumps))
        {
            if (s[endS] == '*')
            {
                jumps++;
            }
            else jumps--;

            endS--;
        }

        // but stores the string elements at the end of the string
        if (endS >= 0)
        {
            s[address--] = s[endS--];
        }
        else break;
    }
    // and return the end
    return s + sizeof(char) * (address + 1);
}

// remembering
// given an array of heights, return the maximum area of water that can be stored in this heights
int maxArea(int* height, int heightSize)
{
    int water = 0;
    int left = 0, right = heightSize - 1;

    /*
       starting from the extremum left and right, it's only possible to get a greater area if the heights are greater
       so we search for a greater height and store the max value in water
    */
    while (left < right)
    {
        int smallerh = height[left] > height[right] ? height[right]:height[left];
        water = (water > smallerh * (right - left)) ? water:smallerh * (right - left);

        if (height[left] > height[right]) right--;
        else left++;
    }
    return water;
}

