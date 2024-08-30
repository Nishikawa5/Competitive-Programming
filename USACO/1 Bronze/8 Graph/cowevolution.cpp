#include <bits/stdc++.h>
using namespace std;

/*
check if we have cows that has A and not B
                      that has B and not A
                      and has both

watched the video solution and tried to reimplement
*/
bool notPossible(int A, int B, vector<string> allChar, vector<string> cows[], int n) {
    bool aNotB = false;
    bool bNotA = false;
    bool both = false;
    for (int cow = 0; cow < n; cow++) {
        bool hasA = false;
        bool hasB = false;
        for (int charac = 0; charac < cows[cow].size(); charac++) {
            if (cows[cow][charac] == allChar[A]) {
                hasA = true;
            }
            if (cows[cow][charac] == allChar[B]) {
                hasB = true;
            }
        }
        if (hasA && !hasB) {
            aNotB = true;
        } else if (hasB && !hasA) {
            bNotA = true;
        } else if (hasA && hasB) {
            both = true;
        }
    }
    return (aNotB && bNotA && both);
}

int main() {
    freopen("evolution.in", "r", stdin);
	freopen("evolution.out", "w", stdout);

    int n;
    cin >> n;

    vector<string> cows[n];
    vector<string> allChar;
    for (int i = 0; i < n; i++) {
        int num_char;
        cin >> num_char;

        string charac;
        for (int j = 0; j < num_char; j++) {
            cin >> charac;
            
            cows[i].push_back(charac);
            // make every element in allChar unique
            if (find(allChar.begin(), allChar.end(), charac) == allChar.end()) {
                allChar.push_back(charac);
            }
        }
    }


    for (int characA = 0; characA < allChar.size(); characA++) {
        for (int characB = characA + 1; characB < allChar.size(); characB++) {
            if (notPossible(characA, characB, allChar, cows, n)) {
                cout << "no" << endl;
                return 0;
            }
        }
    }
    cout << "yes" << endl;
}