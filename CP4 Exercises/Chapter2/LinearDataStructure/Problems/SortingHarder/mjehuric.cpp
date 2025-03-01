#include <bits/stdc++.h>

using namespace std;

void printarr(int arr[5]) {
    printf("%d", arr[0]);
    for (int i = 1; i < 5; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");
    return;
}

int main(void) {
    int arr[5];

    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 1; i < 5; i++) {
        for (int j = 0; j < 5 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                printarr(arr);
            }
        }
    }
}