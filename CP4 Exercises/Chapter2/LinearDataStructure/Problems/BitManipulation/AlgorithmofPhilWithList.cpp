#include <bits/stdc++.h>

using namespace std;

void oddLen(string A, string S) {

}

/*
Can read the strings as a list and point to the middle to get faster and dont have to keep moving
the chars
*/

struct mylist {
    struct mylist *next;
    char c;
};

struct middle {
    struct mylist *middle;
};

typedef struct mylist node;
typedef struct middle middle;


int main(void) {
    middle *A;
    middle *S;

    int t;
    scanf("%d", &t);

    for (int i = 1; i <= t; i++) {
        
        // read the input in a list
        char c;
        while ((c = getchar()) != '\n') {

        }


        // |A| is odd => middle bit of A is added to end of S and removed from A

        // |A| is even => both middle of A are compared. The bigger is added to end of S and removed from A

        // |A| is empty => terminates and return decimal representation of S
    }


}