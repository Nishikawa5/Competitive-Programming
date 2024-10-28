#include <stdio.h>
#include <stdlib.h>
 
int max(int a, int b) {
    return (a < b ? b : a);
}
int min(int a, int b) {
    return (a > b ? b : a);
}

int main() {
    int etapas;
    while (scanf("%d", &etapas) != EOF) {

        int start1, start2;
        scanf("%d %d", &start1, &start2);

        int exec[2][etapas];

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < etapas; j++) {
                scanf("%d", &exec[i][j]);
            }
        }

        int change[2][etapas - 1];

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < etapas - 1; j++) {
                scanf("%d", &change[i][j]);
            }
        }

        int exit1, exit2;
        scanf("%d %d", &exit1, &exit2);


        int min_dist[2][etapas];

        min_dist[0][0] = start1;
        min_dist[1][0] = start2;

        for (int i = 1; i < etapas; i++) {
            min_dist[0][i] = min(min_dist[0][i - 1] + exec[0][i - 1], min_dist[1][i - 1] + change[1][i - 1] + exec[1][i - 1]);
            min_dist[1][i] = min(min_dist[1][i - 1] + exec[1][i - 1], min_dist[0][i - 1] + change[0][i - 1] + exec[0][i - 1]);
        }

        printf("%d\n", min(min_dist[0][etapas - 1] + exit1 + exec[0][etapas - 1], min_dist[1][etapas - 1] + exit2 + exec[1][etapas - 1]));
    }
    return 0;
}