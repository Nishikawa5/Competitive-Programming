#include <bits/stdc++.h>
using namespace std;

void row(int a, int b, vector<vector<char>> &arr) {
    for (int j = 0; j < arr.size(); j++) {
        swap(arr[a][j], arr[b][j]);
    }
}

void col(int a, int b, vector<vector<char>> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        swap(arr[i][a], arr[i][b]);
    }
}

void transpose(vector<vector<char>> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            swap(arr[i][j], arr[j][i]);
        }
    }
}

int main() {
    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        int n;
        int commands;
        int increment = 0;
        cin >> n;
        vector<vector<char>> arr(n, vector<char>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
            getchar();
        }
        cin >> commands;
        for (int i = 0; i < commands; i++) {
            string command;
            cin >> command;

            if (command == "transpose") {
                transpose(arr);
            } else if (command == "row") {
                int a, b;
                cin >> a >> b;
                row(a - 1, b - 1, arr);
            } else if (command == "col") {
                int a, b;
                cin >> a >> b;
                col(a - 1, b - 1, arr);
            } else if (command == "inc") {
                increment++;
            } else if (command == "dec") {
                increment--;
            }
        }
        cout << "Case #" << t << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << (arr[i][j] - '0' + increment + 1000) % 10;
            }
            cout << endl;
        }
        cout << endl;
    }
}