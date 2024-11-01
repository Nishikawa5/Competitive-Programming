#include <bits/stdc++.h>

using namespace std;
#define PI 3.141592653589793232

void gradDesc(float *theta, int L) {

}

int main(void) {
    int N;
    float L;

    scanf("%d", &N);
    int logs[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &logs[i]);
    }
    scanf("%d", &L);
    L -= logs[N / 2];

    for (int i = 0; i < N; i++) {
        if (i == N / 2) {
            printf("0 ");
        } else if (i == N - 1) {
            printf("%.2f\n", 90 - atan((logs[i] * logs[i] - L * L) / logs[i]));
            L -= logs[i] * cos(90 - atan((logs[i] * logs[i] - L * L) / logs[i]));
        } else {
            printf("45.00 ");
            L -= logs[i] * cos(PI / 4);
        }
    }
    printf("%.2f", L);
}