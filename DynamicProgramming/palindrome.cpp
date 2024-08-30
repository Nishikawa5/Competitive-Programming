#include <bits/stdc++.h>

using namespace std;

// palindrome subsequence
string longestPalindrome(string s) {
    int len = s.size();

    int table[len][len];
    
    for (int i = 0; i < len; i++) {
        table[i][i] = 1;
        if (i < len - 1) {
            table[i + 1][i] = 0;
        }
    }

    int start = 0;
    int maxlen = 1;
    for (int j = 1; j < len; j++) {
        for (int i = len - 2; i >= 0; i--) {
            int k = i + j;
            if (k >= len) continue;
            
            if (s[k] == s[i]) {
                table[i][k] = table[i + 1][k - 1] + 2;
                if (table[i][k] > maxlen) {
                    start = i;
                    maxlen = table[i][k];
                }
            } else {
                table[i][k] = max(table[i + 1][k], table[i][k - 1]);
            }
        }
    }
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < i; j++) {
            printf("  ");
        }
        for (int j = i; j < len; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
    return s.substr(start, maxlen);
}