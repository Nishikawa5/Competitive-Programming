#include <stdio.h>
#include <stdlib.h>



// quicksort
void swap(int **a, int **b) 
{
    int* t = *a;
    *a = *b;
    *b = t;
}

int partition(int** array, int low, int high) 
{
    
    int pivot = array[high][1];
    
    int i = (low - 1);


    for (int j = low; j < high; j++) 
    {
        if (array[j][1] <= pivot) 
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

// given an array of intervals, return the minimum number of intervals to remove and the intervals don't overlapp
int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize)
{
    // sort the intervals by it end
    quickSort(intervals, 0, intervalsSize - 1);

    int count = 0;     // ans
    int PrevIndex = 0; // previous index

    for (int i = 1; i < intervalsSize; i++)
    {
        // while the minimum interval is greater than the start of next interval, add 1 to count
        // minimum difference intervals
        if (intervals[PrevIndex][1] > intervals[i][0]) count++;
        else PrevIndex = i;
    }

    return count;
}





// given 2 arrays of the start time and end time of an event, return true if the events overlaps, false if not
int haveConflict(char ** event1, int event1Size, char ** event2, int event2Size)
{
    // check if the events overlaps:
    // s1____s2____e1___e2 or s2____s1____e1___e2
    if (comparevec(event1[0], event2[0]) && comparevec(event2[0], event1[1]) ||
        comparevec(event2[0], event1[0]) && comparevec(event1[0], event2[1])) return 1;

    return 0;
}

// str1 <= str2 ?
// compare the event times
int comparevec(char* str1, char* str2)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        if (str2[i] > str1[i]) return 1;
        else if (str2[i] != str1[i]) break;
    }
    return i == 5 ? 1:0;
}

// approach 2:
// turn the event times in numbers
int haveConflict(char ** event1, int event1Size, char ** event2, int event2Size)
{
    int startend;
    int startafter;
    if (myatoi(event1[0]) > myatoi(event2[0]))
    {
        startend = myatoi(event2[1]);
        startafter = myatoi(event1[0]);
    }
    else
    {
        startend = myatoi(event1[1]);
        startafter = myatoi(event2[0]);
    }

    if (startend >= startafter) return 1;

    return 0;
}

// time to number
int myatoi(char* str)
{
    int sum = 0;

    for (int i = 0; i < 5; i++)
    {
        if (str[i] != ':')
        {
            sum = sum*10 + str[i] - '0';
        }
    }

    return sum;
}



// given 2 strings of numbers, return their sum
char * addStrings(char * num1, char * num2)
{
    int len1 = strlen(num1) - 1;
    int len2 = strlen(num2) - 1;

    // the number could be bigger than the max lenght
    char* res = malloc(((len1 > len2 ? len1:len2) + 3) * sizeof(char));
    // to check the address to return
    res[0] = 0;
    // string end with '\0'
    res[(len1 > len2 ? len1:len2) + 2] = '\0';

    for (int cur = 0, tot = (len1 > len2 ? len1:len2) + 1; tot >= 0; tot--, len1--, len2--)
    {
        // carry?
        cur /= 10;
        // add the most left digit if still have
        cur += (len1 >= 0 ? (num1[len1] - '0'):0) + (len2 >= 0 ? (num2[len2] - '0'):0);

        // add the number in the most right if is not 0
        if (tot || cur) res[tot] = cur%10 + '0';
    }

    // if the number is added, return res address, if not return the address + 1 (ignoring the 1st digit)
    return res[0] ? res:res + 1;
}