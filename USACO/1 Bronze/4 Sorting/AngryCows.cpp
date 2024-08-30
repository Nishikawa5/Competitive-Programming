#include <bits/stdc++.h>
using namespace std;

/*
Order the hay bales then just complete search

Easy to interpret easy to implement. I complicated the way to implement it so it took a little time
Could have drawn the cases before implementing
*/
int main() {
	freopen("angry.in", "r", stdin);
	freopen("angry.out", "w", stdout);

    int n;
    cin >> n;

    vector<int> balepos(n);
    for (int i = 0; i < n; i++) {
        cin >> balepos[i];
    }
    sort(balepos.begin(), balepos.end());

    int explodedmax = 0;
    for (int shootat = 0; shootat < n; shootat++) {
        int currexplosion;
        int chain;
        int exploded = 1;

        // exploding right
        currexplosion = 1;
        chain = shootat;
        while (chain < n-1 && balepos[chain + 1] - balepos[chain] <= currexplosion) {
            int explodidx = chain;
            // get chain into position
            while (chain < n-1 && balepos[chain + 1] - balepos[explodidx] <= currexplosion) {
                exploded++;
                chain++;
            }
            currexplosion++;
        }

        // exploding left
        currexplosion = 1;
        chain = shootat;
        while (chain > 0 && balepos[chain] - balepos[chain - 1] <= currexplosion) {
            int explodidx = chain;
            // get the chain into position
            while (chain > 0 && balepos[explodidx] - balepos[chain - 1] <= currexplosion) {
                exploded++;
                chain--;
            }
            currexplosion++;
        }
        explodedmax = max(exploded, explodedmax);
    }
    cout << explodedmax << endl;
}