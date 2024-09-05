#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int mult3 = 3;
    int mult5 = 5;

    int result = 0;
    while (mult3 < 1000) {
        result += mult3;
        mult3 += 3;
    }

    while (mult5 < 1000) {
        if (mult5 % 3) {
            result += mult5;
        }
        mult5 += 5;
    }
    printf("%d\n", result);
}