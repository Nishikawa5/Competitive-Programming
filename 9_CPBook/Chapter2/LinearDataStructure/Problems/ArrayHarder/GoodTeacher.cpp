#include <bits/stdc++.h>
using namespace std;

/*
UVa 12662 - Good Teacher

*/
int main() {
    int studentsnum;
    cin >> studentsnum;

    vector<string> students(studentsnum);
    for (int i = 0; i < studentsnum; i++) {
        cin >> students[i];
    }

    int queries;
    cin >> queries;
    for (int i = 0; i < queries; i++) {
        int pos;
        cin >> pos;
        pos--;
        if (students[pos] == "?") {
            // check the closest
            int leftnb = 0;
            int rightnb = 0;

            while (students[pos - leftnb] == "?") {
                leftnb++;
                if (pos - leftnb < 0) {
                    leftnb = INT_MAX;
                    break;
                }
            }
            while (students[pos + rightnb] == "?") {
                rightnb++;
                if (rightnb + pos >= studentsnum) {
                    rightnb = INT_MAX;
                    break;
                }
            }

            if (leftnb < rightnb) {
                for (int i = 0; i < leftnb; i++) {
                    cout << "right of ";
                }
                cout << students[pos - leftnb] << endl;
            } else if (leftnb > rightnb) {
                for (int i = 0; i < rightnb; i++) {
                    cout << "left of ";
                }
                cout << students[pos + rightnb] << endl;
            } else {
                cout << "middle of " << students[pos - leftnb] << " and " << students[pos + rightnb] << endl;
            }

        } else {
            cout << students[pos] << endl;
        }
    }
}