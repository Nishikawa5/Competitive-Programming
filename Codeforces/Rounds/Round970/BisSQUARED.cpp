#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        string matrix;
        cin >> n >> matrix;
        
        int sqr = sqrt(n);
        bool isValid = true;
        if (sqr * sqr != n) {
            isValid = false;
        } else {
            int rows = sqr;
            int col = sqr;

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
        }

        if (!isValid) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
    }
}