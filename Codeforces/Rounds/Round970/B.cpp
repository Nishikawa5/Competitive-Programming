#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        string matrix;
        cin >> n >> matrix;
        

        

        // count the zeros to try to form a matrix
        int max_seq = 0;
        int curr_seq = 0;
        for (int i = 0; i < n; i++) {
            if (matrix[i] == '0') {
                curr_seq++;
                max_seq = max(max_seq, curr_seq);
            } else {
                curr_seq = 0;
            }
        }
        if (max_seq == 0 && n > 2) {
            cout << "No\n";
            continue;
        }

        // so we must have rows of max_seq + 2
        int rows = max_seq + 2;
        int col = n / rows;
        bool isValid = true;
        if (rows * col == n) {
            // check first and last row
            for (int i = 0; i < col; i++) {
                if (matrix[i] == '0' || matrix[n - i] == '0') {
                    isValid = false;
                    break;
                }
            }

            if (isValid) {
                for (int i = 1; i < rows - 1; i++) {
                    if (matrix[i * col] == '0' || matrix[i * col + col - 1] == '0') {
                        isValid = false;
                        break;
                    }
                    for (int j = 1; j < col - 1; j++) {
                        if (matrix[i * col + j] == '1') {
                            isValid = false;
                            break;
                        }
                    }
                    if (!isValid) {
                        break;
                    }
                }
            }
        } else {
            isValid = false;
        }

        if (!isValid) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
    }
}