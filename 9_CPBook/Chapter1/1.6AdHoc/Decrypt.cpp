#include <stdio.h>
#include <stdlib.h>

/* 
Hierogryph -> message

the columns i (from 1 to 9) gives a char each
we have the information:
'/' if (c / pow(2, i) mod 2 = 0)
'\' if (c / pow(2, i) mod 2 = 1)
to get each char
this describes a binary word of the char

10000 -> 10000 -> 1000 -> 100 -> 10 -> 1
 0 1      0 2      0 4     0 8   0 16  16 32

Took a while to understand but easy to implement
*/
int main(void) {
    char hierogryph[10][81];
    int N;

    scanf("%d", &N);
    getchar();
    while (N--) {
        for (int i = 0; i < 10; i++) {
            scanf("%s", hierogryph[i]);
        }
        int j;
        for (j = 1; hierogryph[0][j + 1]; j++) {
            char c = 0;
            char power = 1;
            for (int i = 1; i < 9; i++) {
                if (hierogryph[i][j] == '\\') {
                    c += power;
                }
                power *= 2;
            }
            printf("%c", c);
        }
        printf("\n");
    }
}





















bool isUpper(char c) {
    return (c >= 'A' && c <= 'Z');
}

bool isLower(char c) {
    return (c >= 'a' && c <= 'z');
}

void cypher_caesar(int N, char *message) {
    int i = 0;
    while (message[i] != '\0') {
        if (isLower(message[i])) message[i] = (((message[i] - 'a') + N) % 26 + 26) % 26 + 'a';
        else if (isUpper(message[i])) message[i] = (((message[i] - 'A') + N) % 26 + 26) % 26 + 'A';
        i++;
    }
}
/* Easy to implement, but i think the harder problem would be to decrypt the text, which was given to us as hint */
int Wuymul_Wixcha(void) {
    char *message = (char *) malloc(sizeof(char) * 65536);
    int N;
    scanf("%d", &N);
    getchar();
    while (N != 0 && scanf("%[^\n]s", message) != EOF) {
        cypher_caesar(N, message);
        printf("%s\n", message);
        getchar();
        scanf("%d", &N);
        getchar();
    }
}