#include <bits/stdc++.h>
using namespace std;

/*


*/
void printArrayInt(vector<vector<int>> arr) {
    for (int i = 0; i < (int)arr.size(); i++) {
        for (int j = 0; j < (int)arr.size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
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
    
    pair<int, int> curr1 = {coord1[0].first, coord1[0].second};
    pair<int, int> curr2 = {coord2[0].first, coord2[0].second};


    // color the outside
    // one of the corners must be blank, if not the two bands are the same or it is inside
    // fill the outside
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
    }

    floodfill(box.size() - 1, box.size() - 1, box);

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
            intersect++;
        }
    }

    if (touches_0 && touches_2) {
        cout << "Impossible" << endl;
    } else {
        cout << intersect << endl;
    }
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
