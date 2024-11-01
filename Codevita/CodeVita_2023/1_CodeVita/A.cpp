#include <bits/stdc++.h>

using namespace std;

#define PI 3.14
#define lli long long int

long long int getRadius(float A[2], float B[2]) {
    return ceil(sqrt((A[0] - B[0]) * (A[0] - B[0]) + (A[1] - B[1]) * (A[1] - B[1])));
}

long long int getArea(long long int r) {
    return ceil(PI * r * r);
}

int main(void) {
    float A[2], B[2], C[2];

    scanf("%f %f", &A[0], &A[1]);
    scanf("%f %f", &B[0], &B[1]);
    scanf("%f %f", &C[0], &C[1]);

    long long int rB = getRadius(A, B);
    long long int rC = getRadius(A, C);

    // B is what shiva need to give, C is what Krishna receives
    long long int aB = getArea(rB);
    long long int aC = getArea(rC);

    long long int diff = aB - aC;

    if (diff < 0) {
        // Shiva gives more than needed so Krishna gives the closest square and maybe money
        // occupied more than actual
        // given land is a perfect square nearest to what Shiva deserves
        long long int temp = sqrt(abs(diff));

        // find the closest perfect square to equalize
        long long int closestpsq;
        if (temp * temp == diff) {
            closestpsq = diff;
        } else if (abs((temp + 1) * (temp + 1) - abs(diff)) < abs(temp * temp - abs(diff))) {
            closestpsq = (temp + 1) * (temp + 1);
        } else {
            closestpsq = temp * temp;
        }

        long long int diff2 = closestpsq - abs(diff);
        if (diff2 > 0) {
            printf("Krishna %lli\n", diff2 * 20);
        } else if (diff2 < 0) {
            printf("Shiva %lli\n", -diff2 * 20);
        } else {
            printf("-1\n");
        }
    } else if (diff > 0) {
        // occupied less than actual
        printf("Krishna %lli\n", diff * 20);
    } else {
        printf("-1");
    }
}