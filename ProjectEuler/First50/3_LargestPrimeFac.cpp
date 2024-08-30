#include <bits/stdc++.h>

using namespace std;

long longsqrt(long x) {
    long left = 0;
    long right = x;

    while (left < right) {
        long mid = left + (right - left) / 2;

        long square = mid * mid;
        if (square == x) {
            return mid;
        } else if (square < x) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

long longmax(long a, long b) {
    return (a > b) ? a:b;
}

int main(void) {
    // lets find the factor by start and end pointers
    long x = 600851475143;
    long maxFactor = 1;

    while (x % 2 == 0) {
        x /= 2;
        maxFactor = 2;
    }

    long root = sqrt(x);
    // maybe use x > maxFactor
    for (int i = 3; i <= root; i += 2) {
        while (x % i == 0) {
            x /= i;
            maxFactor = i;
        }
    }

    if (x > 2) {
        // x is prime and is greater than root, so is obviously bigger than maxFactor
        maxFactor = x;
    }

    printf("%ld\n", maxFactor);
}