#include <bits/stdc++.h>

using namespace std;

/*
Square free is not divisible by a perfect square
*/
bool checkSquareFree(int N) {
    for (int i = 2; i <= 19; i++) {
        if (N % (i * i) == 0) {
            // Not square free
            return false;
        }
    }
    // Square free
    return true;
}

int main(void) {
    int N;
    scanf("%d", &N);

    int freesq = 0;
    for (int i = 2; i < N; i++) {
        if (N % i == 0) {
            if (checkSquareFree(i)) {
                freesq++;
            }
        }
    }
    printf("%d\n", freesq);
}