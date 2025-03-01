#include <bits/stdc++.h>
using namespace std;

pair<int, bool> check_min(int room_w, int room_h, int w, map<int, int> &num_board) {
    int boards = 0;

    for (auto rit = num_board.rbegin(); rit != num_board.rend() && room_h > 0; rit++) {
        int curr = (*rit).first;
        int desired = (room_w - curr);

        // could have just subtracted instead of 1 by 1
        while (num_board[curr] > 0 && num_board[desired] > 0 && room_h > 0) {
            if (curr == desired) {
                if (num_board[curr] == 1) {
                    break;
                }
            }

            if (curr == room_w) {
                // only one needed
                boards++;
            } else {
                boards += 2;
            }

            num_board[curr]--;
            num_board[desired]--;
            room_h -= w;
        }
    }

    return {boards, room_h == 0};
}


int main(void) {
    int room_w, room_h;

    while (cin >> room_w >> room_h && (room_w || room_h)) {
        room_w *= 100;
        room_h *= 100;
        
        int w, n;

        cin >> w >> n;

        /*
        all boards should be placed in same direction, and a board can be emended with
        at most one board, so this leaves us with something like a twosum problem
        */

        map<int, int> num_board1;
        map<int, int> num_board2;
        num_board1[0] = INT_MAX;     // for simpler implementation

        for (int i = 0; i < n; i++) {
            int horw;
            cin >> horw;
            num_board1[horw*100]++;
        }
        num_board2 = num_board1;

        // lets say all boards are 
        
        // horizontal
        // so the board w should be able to cover room_h
        pair<int, bool> result1 = {0, false};
        pair<int, bool> result2 = {0, false};
        if (room_h % w == 0) {
            result1 = check_min(room_w, room_h, w, num_board1);
        }

        // vertical
        // same
        if (room_w % w == 0) {
            result2 = check_min(room_h, room_w, w, num_board2);
        }

        int min_boards;
        if (result1.second && result2.second) {
            min_boards = min(result1.first, result2.first);
        } else if (result1.second) {
            min_boards = result1.first;
        } else if (result2.second) {
            min_boards = result2.first;
        } else {
            cout << "impossivel\n";
            continue;
        }

        cout << min_boards << endl;
    }
}