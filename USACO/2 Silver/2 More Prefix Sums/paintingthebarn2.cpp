#include <bits/stdc++.h>
using namespace std;

/*
1 Rectangle:
Change every submatrix of k-1 by 1 and every k by -1
find the maximum sum

2 Rectangles:

*/
void printArrayInt(vector<vector<int>> arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

#define MAX_SZ 10

int main() {
    int n, k;
    int max_coats = 0;
    cin >> n >> k;

    vector<vector<int>> barn(MAX_SZ, vector<int>(MAX_SZ, 0));

    // count the coats
    while (n--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        barn[x1][y1]++;
        barn[x2][y2]++;
        barn[x1][y2]--;
        barn[x2][y1]--;
    }
    
    for (int i = 0; i < MAX_SZ; i++) {
        for (int j = 0; j < MAX_SZ; j++) {
            if (i) {
                barn[i][j] += barn[i - 1][j];
            }
            if (j) {
                barn[i][j] += barn[i][j - 1];
            }
            if (i && j) {
                barn[i][j] -= barn[i - 1][j - 1];
            }
            if (barn[i][j] == k) {
                max_coats++;
            }
        }
    }

    printArrayInt(barn);


    // compute the max subarray
    for (int i = 0; i < MAX_SZ; i++) {
        for (int j = 0; j < MAX_SZ; j++) {
            if (barn[i][j] == k - 1) {
                barn[i][j] = 1;
            } else if (barn[i][j] == k) {
                barn[i][j] = -1;
            } else {
                barn[i][j] = 0;
            }
        }
    }

    printArrayInt(barn);

    // precompute the matrix (columns prefix)
    for (int i = 0; i < MAX_SZ; i++) {
        for (int j = 0; j < MAX_SZ; j++) {
            if (j) barn[j][i] += barn[j - 1][i];
        }
    }

    printArrayInt(barn);


    vector<int> position(MAX_SZ);
    vector<int> max_sum(MAX_SZ);
    int curr_num;
    int max_subarray = 0;
    for (int i = 0; i < MAX_SZ; i++) {
        for (int j = i; j < MAX_SZ; j++) {
            // assume we already have the top and bottom rows
            // use kadane algo
            for (int a = 0; a < MAX_SZ; a++) {
                if (!i) {
                    // don't have a row to subtract
                    curr_num = barn[i][a];
                } else {
                    // subtract the row above i
                    curr_num = barn[j][a] - barn[i - 1][a];
                }

                if (!a) {
                    position[0] = 0;
                    max_sum[a] = curr_num;
                } else {
                    if (max_sum[a - 1] > 0) {
                        max_sum[a] = max_sum[a - 1] + curr_num;
                        position[a] = position[a - 1];
                    } else {
                        max_sum[a] = curr_num;
                        position[a] = a;
                    }
                }
                max_subarray = max(max_subarray, max_sum[a]);
            }
        }
    }

    cout << max_subarray << " " << max_coats << endl;
}