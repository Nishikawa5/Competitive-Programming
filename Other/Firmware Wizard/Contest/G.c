#include <stdio.h>
#include <stdlib.h>
 
int max(int a, int b) {
    return (a < b ? b : a);
}


int main() {
    int cols, rows, size;

    while (scanf("%d %d %d", &cols, &rows, &size) && (cols || rows || size)) {
        
        int **arr = (int**)malloc(sizeof(int*) * rows);

        for (int i = 0; i < rows; i++) {
            arr[i] = (int *)malloc(sizeof(int) * cols);
            for (int j = 0; j < cols; j++) {
                scanf("%d", &arr[i][j]);
            }
        }

        int ans = 0;
        for (int j = 0; j < cols; j++) {
            int curr_size = 0;
            for (int i = 0; i < rows; i++) {
                
                curr_size += arr[i][j];
                if (arr[i][j] == 0) {
                    if (curr_size >= size) {
                        ans++;
                    }
                    curr_size = 0;
                }
            }
            if (curr_size >= size) {
                ans++;
            }
        }
        printf("%d\n", ans);

    }

    return 0;
}