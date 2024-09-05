#include <stdio.h>
#include <stdlib.h>
#include <stack>
using namespace std;

int precedence(char c) {
    if (c == '*' || c == '/') return 1;
    else if (c == '+' || c == '-') return 0;
    else return -1;
}

int main(void) {
    int t;


    scanf("%d", &t);
    getchar();
    getchar();

    while (t--) {
        stack<char> operations;
        char c;
        while ((c = getchar()) != '\n' && c != EOF) {
            getchar();

            if ('0' <= c && c <= '9') {
                printf("%c", c);
            } else if (c == '(') {
                operations.push(c);
            } else if (c == ')') {
                while (operations.top() != '(') {
                    printf("%c", operations.top());
                    operations.pop();
                }
                operations.pop();
            } else {
                while (!operations.empty() && 
                       precedence(c) <= precedence(operations.top())) {
                    printf("%c", operations.top());
                    operations.pop();
                }
                operations.push(c);
            }
        }
        
        while (!operations.empty()) {
            printf("%c", operations.top());
            operations.pop();
        }
        printf("\n");
        if (t) printf("\n");
    }
}