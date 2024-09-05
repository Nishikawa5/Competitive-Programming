#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <map>

using namespace std;

int main(void) {
    bool arr = true;
    cout << arr << endl;
}

int praint(void) {
    char word[7][6];
    for (int i = 0; i < 7; i++) {
        scanf("%[^\n]s", word[i]);
        getchar();
    }
    printf("{");
    for (int i = 0; i < 7; i++) {
        printf("    \"%s\",\n", word[i]);
    }

    printf("},\n");
}

#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

bool *inttobit(int n) {
    bool *word = (bool *) malloc(sizeof(bool) * 8);
    short i = 7;
    while (i >= 0) {
        word[i--] = n % 2;
        n /= 2;
    }
    return word;
}
/*
from right to left
11100011 -> 1 and 2 activated 3 and 4 unabled
*/
int main(void) {
    short T;
    int M; // measurement interval
    int S; // startup delay
    int th[4]; // thresh hold temperatures
    int C;    // alarms behavior
    short K;  // time temp quant
    bool *word;

    scanf("%hd", &T);
    getchar();
    int cases = 1;
    while (T--) {
        int time, temp;
        scanf("%d %d %d %d %d %d %d %hd", &M, &S, th, th + 1, th + 2, th + 3, &C, &K);
        getchar();
        word = inttobit(C);
        int currtime = -S;
        bool activated[4] = {false, false, false, false};
        int L, R;
        while (K--) {
            scanf("%d %d", &time, &temp);
            getchar();
            currtime += time;
            if (currtime >= 0 && (currtime % M == 0 || time >= M)) {
                for (int i = 0; i < 4; i++) {
                    if (word[7 - i]) {
                        if (word[3 - i]) {
                            if (th[i] < temp) activated[i] = true;
                        } else {
                            if (th[i] > temp) activated[i] = true;
                        } 
                    }
                }
            }
        }
        printf("Case %d:", cases++);
        for (int i = 0; i < 4; i++) {
            if (activated[i]) printf(" yes");
            else printf(" no");
        }
        printf("\n");
    }
}