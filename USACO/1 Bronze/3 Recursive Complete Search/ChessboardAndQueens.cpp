#include <bits/stdc++.h>
using namespace std;

/*
put a queen -> go one y up -> put another queen -> check -> not possible -> go one x up

Takeaway: we can represent the diagonals as vectors, 
since in every diagonal 
x++ y-- or x-- y++ (plus operation          x + 1 + y - 1 = x + y)  
y-- x-- or x++ y++ (minus operation         (x + 1) - (y + 1) = x - y)
*/
void backtrack(int y, int &ways, vector<string> board, vector<bool> columns, vector<bool> diag1, vector<bool> diag2) {
    if (y == board.size()) {
        ways++;
    } else {
        // check for every column
        int n = board[0].size();
        for (int x = 0; x < n; x++) {
            if(board[y][x] == '*' || columns[x] || diag1[(n - 1) + (x - y)] || diag2[x + y]) {
                // not valid place for a queen
                continue;
            }
            // put the queen here and test
            columns[x] = true;
            diag1[(n - 1) + (x - y)] = true;
            diag2[x + y] = true;
            backtrack(y + 1, ways, board, columns, diag1, diag2);
            columns[x] = false;
            diag1[(n - 1) + (x - y)] = false;
            diag2[x + y] = false;
        }
    }
}

int main() {
    int n = 8;
    int m = 8;
    vector<string> board(n);

    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }
    
    int ways = 0;
    vector<bool> columns(m, false);
    vector<bool> diag1(n + m - 1, false);
    vector<bool> diag2(n + m - 1, false);
    backtrack(0, ways, board, columns, diag1, diag2);

    cout << ways << endl;
}