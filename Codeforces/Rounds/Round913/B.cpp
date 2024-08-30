#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

/*
'b' backspace if has lower case
'B' backspace if has uppercase


*/
struct aux {
    int index;
    char c;
};

typedef struct aux ci;

int main(void) {
    int t;
    char *str = (char *) malloc(sizeof(char) * 1000000);

    scanf("%d", &t);
    getchar();

    while (t--) {
        deque <ci> uppercase;
        deque <ci> lowercase;

        char nc;
        int i = 0;
        while ((nc = getchar()) != '\n') {
            if ('A' <= nc && nc <= 'Z') {
                if (nc != 'B') {
                    ci tmp;
                    tmp.c = nc;
                    tmp.index = i;
                    uppercase.push_back(tmp);
                } else {
                    if (!uppercase.empty()) uppercase.pop_back();
                }
            } else {
                if (nc != 'b') {
                    ci tmp;
                    tmp.c = nc;
                    tmp.index = i;
                    lowercase.push_back(tmp);                
                } else {
                    if (!lowercase.empty()) lowercase.pop_back();
                }
            }
            i++;
        }

        ci temp;
        while (!uppercase.empty() && !lowercase.empty()) {
            if (uppercase.front().index > lowercase.front().index) {
                printf("%c", lowercase.front().c);
                lowercase.pop_front();
            } else {
                printf("%c", uppercase.front().c);
                uppercase.pop_front();            
            }
        }

        while (!uppercase.empty()) {
            printf("%c", uppercase.front().c);
            uppercase.pop_front();               
        }
        while (!lowercase.empty()) {
            printf("%c", lowercase.front().c);
            lowercase.pop_front();         
        }
        printf("\n");
    }
}