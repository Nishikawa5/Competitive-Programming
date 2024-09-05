#include <stdio.h>
#include <stdlib.h>
#include <stack>
using namespace std;

/*
Medium to understand and to implement but had a corner cases hard to see
*/
bool compareBracket(char left, char right) {
    if (left == '(') return right == ')';
    else if (left == '{') return right == '}';
    else if (left == '[') return right == ']';
    else if (left == '<') return right == '>';
    else return right == 'a'; // case a' == a'
}

void problem1(void) {
    stack <char> exp; // stores the brackets of expression given, only stores the left side and (* is 'a'
    bool nested = true;
    char c;
    char c2 = 'a';
    bool starbracket = false;
    bool bracketstar = false;
    int n = 0;

    while (c2 == '\n' || scanf("%c", &c) != EOF) {
        // found a new line, so reset the stacks and variables
        if (c == '\n' || c2 == '\n') {
            if (exp.empty() && nested) {
                printf("YES\n");
            } else if (!nested) {
                printf("NO %d\n", n);
            } else {
                printf("NO %d\n", n + 1);
            }
            n = 0;
            c2 = 'a';
            bracketstar = false;
            starbracket = false;
            nested = true;
            exp = stack<char>();
        } else {
            if (nested) {
                // have to change c's later, this 'a' is just illustration for now
                // we need to put while to search for the next star or '('
                while (c == '*') {
                    scanf("%c", &c2);
                    if (c2 == ')') {
                        starbracket = true;
                        c = 'a';
                    } else {
                        c = c2;
                        if (c2 != '\n') n++;
                    }
                }

                while (c == '(') {
                    scanf("%c", &c2);
                    if (c2 == '*') {
                        bracketstar = true;
                        c = 'a';
                    } else {
                        if (c2 != '\n') n++;
                        exp.push(c);
                        c = c2;
                    }
                }

                if (c == ')' || c == '}' || c == ']' || c == '>' || starbracket) {
                    if (!exp.empty() && compareBracket(exp.top(), c)) {
                        exp.pop();
                    } else {
                        nested = false;
                    }
                } else if (c == '(' || c == '{' || c == '[' || c == '<' || bracketstar) {
                    exp.push(c);
                }
                starbracket = false;
                bracketstar = false;
                n++;
            }
        }
    }
}