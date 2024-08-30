#include <bits/stdc++.h>

using namespace std;

void printv(int *v, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}


/*
start at any block, and fill not wet people using wet as jumps.
When we filled the not wet, try to put the not wet people

start at m
*/
int check(int m, int notwet, int wet, int *seq, int blocks, int rest) {
    int extra = 0;
    int dist = 0;

    int startwetcase = 0;
    if (m % 2 == 1) {
        extra += seq[m]; // fix starting point
        m++;
        startwetcase = seq[m];
    }
    
    while (notwet > 0 && m < blocks && wet >= 0) {
        if (m % 2 == 0) {
            notwet -= seq[m];
        } else {
            wet -= seq[m] / 15;
            extra += seq[m] - seq[m] / 15;
        }
        dist += seq[m];
        m++;
    }
    dist += notwet;

    rest -= dist;
    if (startwetcase && (rest + extra - startwetcase < wet)) {
        dist += wet - rest + extra - startwetcase;
    }
    
    if (rest + extra >= wet && notwet <= 0) {
        if (extra >= wet) {
            return dist;
        } else {
            return dist + wet - extra;
        }
    }
    return INT_MAX;
}

int main(void) {
    int seats;
    int people;
    int wet;
    int blocks;

    scanf("%d,%d,%d,%d", &seats, &people, &wet, &blocks);

    int *seq = (int *) malloc(sizeof(int) * blocks);

    for (int i = 0; i < blocks; i++) {
        scanf("%d", &seq[i]);
        getchar();
    }

    int min = INT_MAX;
    int rest = seats;
    int temp;
    for (int i = 0; i < blocks; i++) {
        temp = check(i, people - wet, wet, seq, blocks, rest);
        if (min > temp) {
            min = temp;
        }
        rest -= seq[i];
    }
    printf("%d\n", (min == INT_MAX) ? 0 : min - 1);
}