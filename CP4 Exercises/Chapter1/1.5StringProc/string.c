#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define bool int
//using namespace std;
// we use gets(string) to get a string in cstring library?
bool invalid(char *line);
void copy(char *str1, char *str2);
void concat(char *T, char *str);
// use p = strstr(str, substr); to get the first appearence of substr in str, p will be the address of the first
// appearence, NULL if not found

int Csol(void) {
    char *T = (char *) malloc(sizeof(char) * 311);
    char *line = (char *) malloc(sizeof(char) * 31);

    scanf(" %s", T);
    // could use strcmp(T, ".......", 7) == 0; instead of invalid(T);
    if (!invalid(T)) {
        while(true) {
            scanf(" %[^\n]s", line);
            if (invalid(line)) break;
            
            concat(T, line);
        }
    }


    printf("%s\n", T);
}

void concat(char *T, char *str) {
    int size = strlen(T);
    T[size] = ' ';
    copy(T + size + 1, str);
}

// str1 is an empty string an we copy str2 to it
void copy(char *str1, char *str2) {
    int i = 0;
    while(str2[i] != '\0') {
        str1[i] = str2[i];
        i++;
    }
    str1[i] = '\0';
}

bool invalid(char *line) {
    int i = 0;
    while(line[i] != '\0' && line[i] == '.') i++;

    return i >= 7;
}

void readUnknown(char **store) {
    int size = 16;
    char ch;
    char *str;
    str = (char *) malloc(sizeof(char) * size);

    if (str == NULL) return;
    int len = 0;

    while ((ch = getchar()) && ch != '\n') {
        str[len++] = ch;

        if (len == size) {
            realloc(str, sizeof(char) * (size += 16));
            if (str == NULL) return;
        }
    }
    str[len] = '\0';

    *store = str;
}


int main(void) {
    char *str;
    readUnknown(&str);

    printf("%s\n", str);
}