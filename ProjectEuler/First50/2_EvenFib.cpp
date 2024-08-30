#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int f1 = 1;
    int f2 = 2;
    int temp;

    long int result = 0;
    while (f2 < 4000000) {
        if (f2 % 2 == 0) {
            result += f2;
        }
        temp = f1 + f2;
        f1 = f2;
        f2 = temp;
    }
    printf("%ld\n", result);
}