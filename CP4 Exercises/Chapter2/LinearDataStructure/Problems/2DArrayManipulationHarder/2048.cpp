#include <bits/stdc++.h>
using namespace std;

#define GRID_SIZE 4

void reverserow(int grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE / 2; j++) {
            swap(grid[i][j], grid[i][GRID_SIZE - 1 - j]);
        }
    }
}

void transpose(int grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = i + 1; j < GRID_SIZE; j++) {
            swap(grid[i][j], grid[j][i]);
        }
    }
}

void rotate90(int grid[GRID_SIZE][GRID_SIZE]) {
    reverserow(grid);
    transpose(grid);
}


int main() {
    int grid[GRID_SIZE][GRID_SIZE];

    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            cin >> grid[i][j];
        }
    }

    int rot;
    cin >> rot;
    for (int i  = 0; i < rot; i++) {
        // rotates 90 degrees rot times
        rotate90(grid);
    }

    for (int i = 0; i < GRID_SIZE; i++) {
        // merge line right to left
        queue<int> merge;
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] != 0) {
                merge.push(grid[i][j]);
            }
        }
        int curr_col = 0;
        while (!merge.empty()) {
            int curr = merge.front();
            merge.pop();
            if (curr == merge.front()) {
                curr += merge.front();
                merge.pop();
            }
            grid[i][curr_col++] = curr;
        }
        for (int k = curr_col; k < GRID_SIZE; k++) {
            grid[i][k] = 0;
        }
    }

    for (int i  = 0; i < ((GRID_SIZE - rot) % 4); i++) {
        // rotates 90 degrees rot times
        rotate90(grid);
    }

    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}