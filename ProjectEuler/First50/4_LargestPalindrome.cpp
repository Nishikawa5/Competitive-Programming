#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(int x) {
    if (x < 0 || (x != 0 && x % 10 == 0)) return false;
    int revx = 0;

    while (x > revx) {
        revx = x % 10 + revx * 10;
        x /= 10;
    }
    return revx == x || revx / 10 == x;
}
/*
we could also get the max 3 digit and duplicate it (1000 * 1000 = 1000000 => x * y < 1000000 for (x and y < 1000))
and see if we have two factors of 3 digits. if we have we are done
*/
int main(void) {
    int x = 999 * 999;

    // get the greatest number with 3 digits that can divide the total and be 3 digit
    int left = 100;
    int right = 999;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (x / mid >= 100) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    // now lets search and store the maximum palindrome
    // fix left and change right
    int maxPalindrome = 0;
    int left3digit = left;

    while (left3digit >= 100) {
        for (int right3digit = min(x / left3digit - 1, 999); right3digit >= 100; right3digit--) {
            int mult = left3digit * right3digit;

            if (isPalindrome(mult)) {
                maxPalindrome = max(maxPalindrome, mult);
            }
        }
        left3digit--;
    }
    cout << maxPalindrome << endl;
}