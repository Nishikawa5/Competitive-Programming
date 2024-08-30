#include <bits/stdc++.h>

using namespace std;

bool isInterleaved(char *A, char *B, char *C) {
    int m = strlen(A);
    int n = strlen(B);

    bool dp[m + 1][n + 1];
    dp[0][0] = true;

    for (int i = 0; i < m; i++) {
        if (A[i] == C[i]) {
            dp[i + 1][0] = dp[i][0];
        } else {
            dp[i + 1][0] = false;
        }
    }

    for (int j = 0; j < n; j++) {
        if (B[j] == C[j]) {
            dp[0][j + 1] = dp[0][j];
        } else {
            dp[0][j] = false;
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (A[i - 1] != C[i + j - 1] && B[j - 1] != C[i + j - 1]) {
                // not possible to interleave
                dp[i][j] = false;
            } else if (A[i - 1] == C[i + j - 1] && B[j - 1] != C[i + j - 1]) {
                // add A[i - 1] to one of interleaving
                dp[i][j] = dp[i - 1][j];
            } else if (B[i - j] == C[i + j - 1] && A[i - 1] != C[i + j - 1]) {
                // add B[j - 1] to one of interleaving
                dp[i][j] = dp[i][j - 1];
            } else {
                // add one of A[i - 1] or B[j - 1] to interleaving
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
        }
    }

    return dp[m][n];
}

int main(void) {

}