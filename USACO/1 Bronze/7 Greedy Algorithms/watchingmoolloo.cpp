#include <bits/stdc++.h>
using namespace std;

#define lli long long int

lli minlli(lli a, lli b) {
    return (a > b) ? b : a;
}

int main() {
    int daysnum, price;
    cin >> daysnum >> price;

    vector<lli> days(daysnum);

    lli prev;
    lli curr;
    lli totalcost = 0;
    cin >> prev;
    // we buy one
    totalcost += price + 1;
    for (int i = 1; i < daysnum; i++) {
        cin >> curr;

        totalcost += minlli(curr - prev, (lli) (price + 1));
    }
    cout << totalcost << endl;
}