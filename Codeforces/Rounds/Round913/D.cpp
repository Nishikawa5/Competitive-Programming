#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>

using namespace std;


/*
n segments
get the maximum distance between those segments
try jumping with this max distance, if we cant, change the maximum so we can

*/
int main(void) {
    int interval[200000][2];
    int t;
    int n;

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            scanf("%d %d", &interval[i][0], &interval[i][1]);
        }

        int min = 0;
        int leftstart = 0;
        int rightstart = 0;
        int lefts = 0;
        int rights = 0;
        int curr = 0;
        for (int i = 0; i < n; i++) {
            /* go left or go right 
               try to jump*/
            if (curr < interval[i][0]) {
                // need to jump to right
                rights++;
                lefts = 0;
                if (min < abs(curr - interval[i][0])) min = ceil(abs(curr - interval[i][0]) / (double) rights);
                curr += min; // change to go to the most left/right inside the interval depending on the next interval

            } else if (curr > interval[i][1]) {
                lefts++;
                rights = 0;
                if (min < abs(curr - interval[i][1])) min = ceil(abs(curr - interval[i][1]) / (double) lefts);
                curr -= min; // change to go to the most left/right inside the interval depending on the next interval
            }
        }
        printf("%d\n", min);
    }
}