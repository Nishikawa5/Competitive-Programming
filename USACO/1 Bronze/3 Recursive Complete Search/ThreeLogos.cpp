#include <bits/stdc++.h>
using namespace std;
/*
Finished the recursion part in ~1 hour after starting
printing the square ~2 hours after starting (passed)

ps: i hate my code. Everything was right till the print rectangle, should have read and plan first
*/
vector<pair<int, int>> coordinates(3);

bool putRectAt(pair<int, int> coord, pair<int, int> measure, vector<int> &rows, vector<int> &columns) {
    for (int i = 0; i < measure.first; i++) {
        if (i + coord.first >= rows.size()) {
            // not possible to put rectangle here
            return false;
        }
        rows[i + coord.first] -= measure.second;
    }
    for (int i = 0; i < measure.second; i++) {
        if (i + coord.second >= columns.size()) {
            // not possible to put rectangle here
            return false;
        }
        columns[i + coord.second] -= measure.first;
    }
    return true;
}

pair<int, int> getNextCoord(vector<int> rows, vector<int> columns) {
    pair<int, int> coord;

    for (int i = 0; i < rows.size(); i++) {
        if (rows[i] > 0) {
            coord.first = i;
            break;
        }
    }
    for (int i = 0; i < columns.size(); i++) {
        if (columns[i] > 0) {
            coord.second = i;
            break;
        }
    }
    return coord;
}

bool checksquare(vector<pair<int, int>> measures, int n) {
    vector<int> rows(n, n);
    vector<int> columns(n, n);

    // put the first in top left, then try to put the second beside the first in the right
    // if every square was occupied, put it down, same for the third
    for (int i = 0; i < measures.size(); i++) {
        coordinates[i] = getNextCoord(rows, columns);
        if (!putRectAt(coordinates[i], measures[i], rows, columns)) {
            return false;
        }      
    }

    // check if every row and column have been covered
    for (int i = 0; i < rows.size(); i++) {
        if (rows[i] != 0) {
            return false;
        }
    }
    for (int i = 0; i < columns.size(); i++) {
        if (columns[i] != 0) {
            return false;
        }
    }
    return true;
}

// get the area of square -> get the size of side -> try to cover every part of square by trying every combination

int main() {
    vector<pair<int, int>> measures(3);
    vector<pair<int, int>> reversemeasures(3);

    vector<int> order(3);
    int occupied = 0;

    for (int i = 0; i < 3; i++) {
        cin >> measures[i].first >> measures[i].second; 
        reversemeasures[i].first = measures[i].second;
        reversemeasures[i].second = measures[i].first;
        occupied += measures[i].first * measures[i].second;
    }

    // check if it is a perfect square
    int side = sqrt(occupied);
    if (side * side != occupied) {
        // false
        cout << "-1" << endl;
        return 0;
    }

    // try every combination of height x width and width x height
    for (int mask = 0; mask < (1 << measures.size()); mask++) {
        vector<pair<int, int>> tempmeasures = measures;

        // measures.size() bits
        for (int i = 0; i < measures.size(); i++) {
            if (mask & (1 << i)) {
                int temp = tempmeasures[i].first;
                tempmeasures[i].first = tempmeasures[i].second;
                tempmeasures[i].second = temp;
            }
        }
        sort(tempmeasures.begin(), tempmeasures.end());

        do {
            // test for every possible combination
            if (checksquare(tempmeasures, side)) {
                vector<vector<char>> board(side, vector<char>(side));
                for (int k = 0; k < tempmeasures.size(); k++) {
                    // get the logo
                    char currLogo;
                    for (int i = 0; i < measures.size(); i++) {
                        if (tempmeasures[k] == measures[i]) {
                            currLogo = 'A' + i;
                            measures[i].first = -1;
                            measures[i].second = -1;
                            reversemeasures[i].first = -1;
                            reversemeasures[i].second = -1;
                            break;
                        } else if (tempmeasures[k] == reversemeasures[i]) {
                            currLogo = 'A' + i;
                            measures[i].first = -1;
                            measures[i].second = -1;
                            reversemeasures[i].first = -1;
                            reversemeasures[i].second = -1;
                            break;
                        }
                    }

                    for (int i = coordinates[k].first; i < coordinates[k].first + tempmeasures[k].first; i++) {
                        for (int j = coordinates[k].second; j < coordinates[k].second + tempmeasures[k].second; j++) {
                            board[i][j] = currLogo;
                        }
                    }
                }

                cout << side << endl;
                for (int i = 0; i < board.size(); i++) {
                    for (int j = 0; j < board[0].size(); j++) {
                        cout << board[i][j];
                    }
                    cout << endl;
                }

                return 0;
            }
        } while (next_permutation(tempmeasures.begin(), tempmeasures.end()));
    }
    cout << "-1" << endl;
    return 0;
}