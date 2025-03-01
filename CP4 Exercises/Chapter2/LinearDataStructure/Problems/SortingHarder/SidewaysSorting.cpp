#include <bits/stdc++.h>

using namespace std;

// str1 > str2
bool compareString(char *str1, char *str2) {

    for (int i = 0; str1[i] != '\0'; i++) {
        int c1 = tolower(str1[i]);
        int c2 = tolower(str2[i]);
        if (c1 < c2) {
            return false;
        } else if (c1 > c2) {
            return true;
        }
    }
    return false;
}

int main(void) {
    char **verticalwords = (char **) malloc(sizeof(char *) * 15);
    for (int i = 0; i < 15; i++) {
        verticalwords[i] = (char *) malloc(sizeof(char) * 16);
    }

    int r, c;

    while (scanf("%d %d", &r, &c) != EOF && (r || c)) {
        getchar(); // remove new line
        // transform the word or could just read vertically
        // lets transform the word
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++){
                verticalwords[j][i] = getchar();
            }
            getchar();
        }

        for (int i = 0; i < c; i++) {
            verticalwords[i][r] = '\0';
        }

        // use stable sort
        for (int i = 1; i < c; i++) {
            for (int j = 0; j < c - i; j++) {
                if (compareString(verticalwords[j], verticalwords[j + 1])) {
                    char *temp = verticalwords[j];
                    verticalwords[j] = verticalwords[j + 1];
                    verticalwords[j + 1] = temp;
                }
            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                printf("%c", verticalwords[j][i]);
            }
            printf("\n");
        }

        printf("\n");
    }
}