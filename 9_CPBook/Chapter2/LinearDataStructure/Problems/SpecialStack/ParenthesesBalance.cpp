#include <stack>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(void) {
    int t;

    scanf("%d", &t);
    getchar();

    while (t--) {
        stack <char> seq;
        bool isCorrect = true;
        char currchar;

        while ((currchar = getchar()) != '\n') {
            if (currchar == '(' || currchar == '[') {
                seq.push(currchar);
            } else {
                if (!seq.empty() &&
                    ((seq.top() == '(' && currchar == ')') ||
                     seq.top() == '[' && currchar == ']')) {
                    seq.pop();
                } else {
                    isCorrect = false;
                }
            }
        }
        if (isCorrect && seq.empty()) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}