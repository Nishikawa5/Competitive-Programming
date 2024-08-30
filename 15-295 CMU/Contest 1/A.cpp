////////////////////////////////////////////////////////////////////////
/*
Try to don't mix C with C++. Lost much time because of that, 
since i didn't knew the qsort (from C) doesn't sort strings
and can't malloc strings

Better to use just C++ or just C

I also complicated this problem. Should see the boundaries before coding.
*/

#include <bits/stdc++.h>

using namespace std;

struct meas {
    int day;
    char name;
    int change;
};

typedef struct meas meas;

int compfunc(const void *a, const void *b) {
    return ((*(meas*)a).day - (*(meas*)b).day);
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);

    int n;
    cin >> n;

    meas *measurement = new meas[n];

    for (int i = 0; i < n; i++) {
        cin >> measurement[i].day;
        string temp;
        cin >> temp;
        measurement[i].name = temp[0];
        cin >> measurement[i].change;
    }

    qsort(measurement, n, sizeof(meas), compfunc);

    int times = 0;
    int maxmk = 0;
    int maxcows = 3;
    unordered_map<char, int> cows;
    set<char> cownames = {'M', 'B', 'E'};

    for (int i = 0; i < n; i++) {
        cows[measurement[i].name] += measurement[i].change;

        // get the max of the 3 cows, if is different then change
        int currmaxmk = max(cows['M'], max(cows['B'], cows['E']));

        set<char> currcownames;
        if (cows['M'] == currmaxmk) {
            currcownames.insert('M');
        }
        if (cows['B'] == currmaxmk) {
            currcownames.insert('B');
        }
        if (cows['E'] == currmaxmk) {
            currcownames.insert('E');
        }

        if (cownames != currcownames) {
            cownames = currcownames;
            times++;
        }
    }

    cout << times << endl;
}