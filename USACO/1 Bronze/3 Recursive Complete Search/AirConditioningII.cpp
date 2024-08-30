#include <bits/stdc++.h>
using namespace std;

struct AirConditioner {
    int from;
    int to;
    int temp;
    int cost;
};


bool verifyStalls(vector<int> stalls) {
    for (int i = 0; i < stalls.size(); i++) {
        if (stalls[i] > 0) {
            return false;
        }
    }
    return true;
}

/*
Try every combination of air conditioners
*/
void rec(int aci, int currcost, int &mincost, vector<int> &stalls,  vector<AirConditioner> acs) {
    if (verifyStalls(stalls)) {
        mincost = min(mincost, currcost);
    } else if (aci != acs.size()) {
        // we have two options:
        // use this air conditioner
        for (int i = acs[aci].from; i <= acs[aci].to; i++) {
            stalls[i] -= acs[aci].temp;
        }
        rec(aci + 1, currcost + acs[aci].cost, mincost, stalls, acs);

        // don't use this air conditioner
        for (int i = acs[aci].from; i <= acs[aci].to; i++) {
            stalls[i] += acs[aci].temp;
        }
        rec(aci + 1, currcost, mincost, stalls, acs);
    }
}

int main() {
    vector<int> stalls(101, 0);
    int cownum, acnum;
    cin >> cownum >> acnum;

    int s, t, c;
    for (int i = 0; i < cownum; i++) {
        cin >> s >> t >> c;
        for (int j = s; j <= t; j++) {
            stalls[j] += c;
        }
    }

    vector<AirConditioner> acs(acnum);
    for (int i = 0; i < acnum; i++) {
        cin >> acs[i].from >> acs[i].to >> acs[i].temp >> acs[i].cost;
    }

    int mincost = INT_MAX;
    rec(0, 0, mincost, stalls, acs);
    cout << mincost << endl;
}