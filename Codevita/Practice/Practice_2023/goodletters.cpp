#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getMinDist(char *goodletters, char *map, char letter) {
    int len = strlen(goodletters);
    int min = 1000;
    int k;
    for (int i = 0; i < len; i++) {
        int dist = abs(goodletters[i] - letter);
        if (dist < min) {
            min = dist;
            k = i;
        }
    }
    map[letter] = goodletters[k];
    goodletters[k] = 128;
    return min;
}

int main(void) {
    char *map         = (char *) malloc(sizeof(char) * 256);
    char *goodletters = (char *) malloc(sizeof(char) * 101);
    char *name        = (char *) malloc(sizeof(char) * 10001);
    memset(map, 0, sizeof(char) * 256);

    scanf("%s", goodletters);
    getchar();
    scanf("%s", name);
    getchar();

    int len = strlen(name);
    int sum = 0;
    int minDist;
    for (int i = 0; i < len; i++) {
        if (map[name[i]]) {
            sum += abs(map[name[i]] - name[i]);
        } else {
            sum += getMinDist(goodletters, map, name[i]);
        }
    }
    printf("%d\n", sum);
}