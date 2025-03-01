#include <bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/how-to-find-intersection-of-two-sets-in-cpp/

bool is_inside(vector<pair<int, int>> square, pair<int, int> point) {
    return (square[0].first < point.first && point.first < square[1].first) &&
           (square[0].second < point.second && point.second < square[2].second);
}

bool overlaps(vector<pair<int, int>> square, pair<int, int> point) {
    return (square[0].first <= point.first && point.first <= square[1].first) &&
           (square[0].second <= point.second && point.second <= square[2].second);
}

pair<int, int> gx_sy(pair<int, int> a, pair<int, int> b) {
    if (a.first < b.first) {
        return b;
    } else if (a.first > b.first) {
        return a;
    } else {
        if (a.second > b.second) {
            return b;
        } else {
            return a;
        }
    }
}

pair<int, int> sx_gy(pair<int, int> a, pair<int, int> b) {
    if (a.first < b.first) {
        return a;
    } else if (a.first > b.first) {
        return b;
    } else {
        if (a.second > b.second) {
            return a;
        } else {
            return b;
        }
    }
}

void floodfill(int i, int j, vector<vector<int>> &box) {
    if (i < 0 || i >= (int)box.size() || j < 0 || j >= (int)box.size() || box[i][j]) return;

    box[i][j] = 2;
    floodfill(i + 1, j, box);
    floodfill(i, j + 1, box);
    floodfill(i - 1, j, box);
    floodfill(i, j - 1, box);
}


void printArrayInt(vector<vector<int>> arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void solve() {
    int dim;
    cin >> dim;
    vector<vector<int>> box(dim + 2, vector<int>(dim + 2));

    // lu, ru, ld, rd
    // assume band rectangle
    vector<pair<int, int>> coord1(4);
    vector<pair<int, int>> coord2(4);
    string mov1;
    string mov2;

    cin >> coord1[0].first >> coord1[0].second;
    cin >> mov1;

    cin >> coord2[0].first >> coord2[0].second;
    cin >> mov2;

    int overlap_count = 0;
    set<pair<int, int>> band1;
    set<pair<int, int>> band2;
    
    pair<int, int> curr1 = {coord1[0].first, coord1[0].second};
    pair<int, int> curr2 = {coord2[0].first, coord2[0].second};


    // color the outside
    // one of the corners must be blank, if not the two bands are the same or it is inside
    // fill the outside
    floodfill(box.size() - 1, box.size() - 1, box);

    for (int i = 0; i < (int)mov1.size(); i++) {
        if (mov1[i] == 'r') {
            curr1.second += 1;
        } else if (mov1[i] == 'd') {
            curr1.first += 1;
        } else if (mov1[i] == 'l') {
            curr1.second -= 1;
        } else if (mov1[i] == 'u') {
            curr1.first -= 1;
        }
        box[curr1.first + 1][curr1.second + 1] = 1;

        band1.insert(curr1);
    }

    bool touches_0 = false;
    bool touches_2 = false;
    int intersect = 0;
    for (int i = 0; i < (int)mov2.size(); i++) {
        if (mov2[i] == 'r') {
            curr2.second += 1;
        } else if (mov2[i] == 'd') {
            curr2.first += 1;
        } else if (mov2[i] == 'l') {
            curr2.second -= 1;
        } else if (mov2[i] == 'u') {
            curr2.first -= 1;
        }

        // must touch 0 and 2 to be impossible
        if (box[curr2.first + 1][curr2.second + 1] == 0) {
            touches_0 = true;
        } else if (box[curr2.first + 1][curr2.second + 1] == 2) {
            touches_2 = true;
        } else {

        }
        band2.insert(curr2);
    }

    /*
25
0 0
rrrrrdddddllllluuuuu
0 0
rrrrrrrrrrddddddddddlllllllllluuuuuuuuuu
    
    */
    printArrayInt(box);

    for (int i = 0; i < (int)box.size(); i++) {
        for (int j = 0; j < (int)box.size(); j++) {
            if (!box[i][j]) {
                // check if this i, j is one of band thing
                if (band2.find({i - 1, j - 1}) != band2.end()) {
                    cout << "Impossible\n" << endl;
                    return;
                }
            }
        }
    }



    set<pair<int, int>> result;

    set_intersection(band1.begin(), band1.end(), band2.begin(),
                     band2.end(),
                     inserter(result, result.begin()));

    cout << result.size() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 1;

    while (tc--) {
        solve();
    }
    return 0;
}
