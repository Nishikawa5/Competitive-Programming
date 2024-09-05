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

mistakes:
i was checking the interval usign M starting at 0, but it starts at S

insights:
can make n & 1 to get the least significant bit
n & 2 to get the second last...
((int) (M / N)) * N gives the closest multiple of N in left of M
we can pick the closest to right because 
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
        int currtime;
        bool activated[4] = {false, false, false, false};
        int L = 0;
        int R = 0;
        while (K--) {
            scanf("%d %d", &time, &temp);
            getchar();
            R += time;
            currtime = (R / M) * M;
            if (R >= S && (L <= currtime && currtime <= R)) {
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
            L += time;
        }
        printf("Case %d:", cases++);
        for (int i = 0; i < 4; i++) {
            if (activated[i]) printf(" yes");
            else printf(" no");
        }
        printf("\n");
    }
}











/* ASCII Addition
It was really a time waster. Easy to implement but it took some time
First we map:
int -> ASCII
ASCII -> int

After that, we get the input and we format this input to use in map
after formatting, use the map in input and store the values given in ASCII input in int type
we sum and then print the output in specified format (ASCII)

What i learned:
we can use vector <string> to map
manipulate a little better the map and strings
if we make a string = char*; the string is everything before the '\0' including '\0'

we can use boolean &= value instead of making an if and break if some condition achieved
we can use vector.resize(n) to create a vector <type> of n
*/

int ASCIIaddition(void) {
    vector <vector <string>> asciinum = 
    {  {"xxxxx",
        "x...x",
        "x...x",
        "x...x",
        "x...x",
        "x...x",
        "xxxxx"
    }, {"....x",
        "....x",
        "....x",
        "....x",
        "....x",
        "....x",
        "....x",
    }, {"xxxxx",
        "....x",
        "....x",
        "xxxxx",
        "x....",
        "x....",
        "xxxxx",
    }, {"xxxxx",
        "....x",
        "....x",
        "xxxxx",
        "....x",
        "....x",
        "xxxxx",
    }, {"x...x",
        "x...x",
        "x...x",
        "xxxxx",
        "....x",
        "....x",
        "....x",
    }, {"xxxxx",
        "x....",
        "x....",
        "xxxxx",
        "....x",
        "....x",
        "xxxxx",
    }, {"xxxxx",
        "x....",
        "x....",
        "xxxxx",
        "x...x",
        "x...x",
        "xxxxx",
    }, {"xxxxx",
        "....x",
        "....x",
        "....x",
        "....x",
        "....x",
        "....x",
    }, {"xxxxx",
        "x...x",
        "x...x",
        "xxxxx",
        "x...x",
        "x...x",
        "xxxxx",
    }, {"xxxxx",
        "x...x",
        "x...x",
        "xxxxx",
        "....x",
        "....x",
        "xxxxx",}
    };
    map <vector <string>, int> convert;
    vector <string> curnum;
    curnum.resize(7);
    char initialval[7][126];

    convert[asciinum[0]] = 10;
    for (int i = 1; i < 10; i++) {
        convert[asciinum[i]] = i;
    }
    for (int i = 0; i < 7; i++) {
        scanf("%s", initialval[i]);
        getchar();
    }
    int n[2] = {0, 0};
    int k = 0;
    // convert ascii to the numbers
    for (int i = 5, tot = strlen(initialval[0]); i <= tot; i += 6) {
        for (int j = 0; j < 7; j++) {
            initialval[j][i] = '\0';
            curnum[j] = initialval[j] - 5 + i;
        }

        short digit = convert[curnum];
        if (digit) {
            if (digit == 10) digit = 0;
            n[k] *= 10;
            n[k] += digit;
        } else {
            k++;
        }
    }
    int sum = n[0] + n[1];
    int digits[12];
    int i;
    for (i = 0; sum; i++, sum /= 10) {
        digits[i] = sum % 10;
    }

    for (int k = 0; k < 7; k++) {
        for (int j = i - 1; j >= 0; j--) {
            printf("%s", asciinum[digits[j]][k].c_str());
            if (j) printf(".");
        }
        printf("\n");
    }
}