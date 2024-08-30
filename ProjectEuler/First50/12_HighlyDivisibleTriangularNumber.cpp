#include <bits/stdc++.h>

using namespace std;

/*
Triangular numbers have the following form:
n(n + 1) / 2 by arithmetic progression

how do we get the # of divisors of a number?

can we get every factor and combine them?

or just brute force. lets bruteforce
*/

// return the n-th triangle number
long triangle(int n) {
    return n * (n + 1) / 2;
}


int main(void) {
    vector<int> triangleMultiples;
    triangleMultiples.push_back(1);

    int n = 500;
    int i = 2;
    while (triangleMultiples.back() <= n) {
        long currTriangle = triangle(i);
        // we have the multiples smaller than square root and greater than square root
    }
}