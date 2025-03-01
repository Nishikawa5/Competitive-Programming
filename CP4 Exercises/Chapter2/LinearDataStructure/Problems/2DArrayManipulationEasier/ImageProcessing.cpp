#include <bits/stdc++.h>

using namespace std;

void fliprow(int **mat, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n / 2; j++) {
            int temp = mat[i][j];
            mat[i][j] = mat[i][n - j - 1];
            mat[i][n - j - 1] = temp;
        }
    }
}

void flipcol(int **mat, int m, int n) {
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m / 2; i++) {
            int temp = mat[i][j];
            mat[i][j] = mat[m - i - 1][j];
            mat[m - i - 1][j] = temp;
        }
    }
}

/* 
x and y are increasing values
mker and nker are the kernel dimensions
assume the dimensions are right
*/
int multker(int **mat, int **ker, int x, int y, int mker, int nker) {
    int result = 0;

    for (int i = 0; i < mker; i++) {
        for (int j = 0; j < nker; j++) {
            result += mat[x + i][y + j] * ker[i][j];
        }
    }
    return result;
}

int main(void) {
    int heightim, widthim, heightker, widthker;

    scanf("%d %d", &heightim, &widthim);
    scanf("%d %d", &heightker, &widthker);
    int **image = (int **) malloc(sizeof(int *) * heightim);
    int **kernel = (int **) malloc(sizeof(int *) * heightker);

    // read im
    for (int i = 0; i < heightim; i++) {
        image[i] = (int *) malloc(sizeof(int) * widthim);
        for (int j = 0; j < widthim; j++) {
            scanf("%d", &image[i][j]);
        }
    }

    // read ker
    for (int i = 0; i < heightker; i++) {
        kernel[i] = (int *) malloc(sizeof(int) * widthker);
        for (int j = 0; j < widthker; j++) {
            scanf("%d", &kernel[i][j]);
        }
    }

    // flip kernel
    flipcol(kernel, heightker, widthker);
    fliprow(kernel, heightker, widthker);


    // do the multiplication and show matrix
    for (int i = 0; i < heightim - heightker + 1; i++) {
        printf("%d", multker(image, kernel, i, 0, heightker, widthker));
        for (int j = 1; j < widthim - widthker + 1; j++) {
            printf(" %d", multker(image, kernel, i, j, heightker, widthker));
        }
        printf("\n");
    }
}