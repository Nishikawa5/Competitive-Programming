#include <bits/stdc++.h>
using namespace std;

#define MAXNM 600
int mat[MAXNM][MAXNM];
int start_idx[MAXNM][MAXNM];
int max_width[MAXNM];

/*
I was getting TLE because of input reading??
cin to scanf and vector to C matrix solved it.

*/

// by the constraints i think we can check every matrix
int main() {
    int n, m;

    while (scanf("%d %d", &n, &m) != EOF && (n || m)) {
        for (int j = 0; j < m; j++) {
            max_width[j] = 1;
        }

        for (int i = 0; i < n; i++) {
            scanf("%d", &mat[i][0]);
            start_idx[i][0] = 0;

            for (int j = 1; j < m; j++) {
                scanf("%d", &mat[i][j]);
                // increasing sequence row
                if (mat[i][j-1] < mat[i][j]) {
                    start_idx[i][j] = start_idx[i][j-1];
                    max_width[j] = max(max_width[j], j - start_idx[i][j] + 1);
                } else {
                    start_idx[i][j] = j;
                }
            }
        }

        // check every possible comb
        int max_subs = 1;
        for (int beg_col = 0; beg_col < m; beg_col++) {
            for (int end_col = m - 1; end_col >= beg_col; end_col--) {
                // every possible width
                
                // width exceeds max
                if ((end_col - beg_col + 1) > max_width[end_col]) continue;

                // cant beat currbest
                if ((end_col - beg_col + 1) * n <= max_subs) continue;


                // check if the first is possible
                // the width of subseq 
                int subs_num = ((end_col - start_idx[0][end_col] + 1) >= (end_col - beg_col + 1));

                int max_subsnum = subs_num;

                for (int row = 1; row < n; row++) {
                    // from begcol to endcol how many sequences there are?

                    if (mat[row - 1][end_col] < mat[row][beg_col] &&
                        ((end_col - start_idx[row][end_col] + 1) >= (end_col - beg_col + 1))) {
                        subs_num++;
                    } else if (((end_col - start_idx[row][end_col] + 1) >= (end_col - beg_col + 1))) {
                        subs_num = 1;
                    } else {
                        subs_num = 0;
                    }
                    max_subsnum = max(max_subsnum, subs_num);
                }
                max_subs = max(max_subs, max_subsnum * (end_col - beg_col + 1));
            }
        }
        printf("%d\n", max_subs);
    }
}