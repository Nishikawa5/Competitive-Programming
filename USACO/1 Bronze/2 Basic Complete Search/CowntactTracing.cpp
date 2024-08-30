#include <bits/stdc++.h>
using namespace std;

struct cowinter {
    int t;
    int x;
    int y;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("tracing.in", "r", stdin);
    freopen("tracing.out", "w", stdout);

    int n, t;
    string cowhealth;

    cin >> n >> t;
    cin >> cowhealth;

    vector<cowinter> interactions(t);
    for (int i = 0; i < t; i++) {
        int a, x, y;
        cin >> a >> x >> y;

        interactions[i] = {a, x, y};
    }

    sort(interactions.begin(), interactions.end(), [&](const cowinter &c1, const cowinter &c2) { return c1.t < c2.t; });

    // assume one of the infected cow is the patient zero and test
    // after testing, check if the infected string is the same
    int minK = INT_MAX;
    int maxK = -1;
    int possiblePatients = 0;
    for (int i = 0; i < n; i++) {
        // if is infected then test
        if (cowhealth[i] == '1') {
            // test for each possible k
            bool wasPossiblePatient = false;
            for (int k = 0; k <= t; k++) {
                vector<int> hooves(n, 0);       // number of hooves of each cow
                                                // take the last effect hoove max
                string currinf(n, '0');
                currinf[i] = '1';
                bool isPossibleK = true;
                for (int j = 0; j < t; j++) {
                    int intleft = interactions[j].x - 1;
                    int intright = interactions[j].y - 1;

                    // increases number of hooves
                    if (currinf[intleft] == '1') {
                        hooves[intleft]++;
                    }
                    if (currinf[intright] == '1') {
                        hooves[intright]++;
                    }

                    // if infects, changes hooves
                    if (currinf[intleft] != currinf[intright] && hooves[intleft] <= k && hooves[intright] <= k) {
                        // left / right infects
                        if (hooves[intleft] > k || hooves[intright] > k) {
                            isPossibleK = false;
                            break;
                        }

                        currinf[intleft] = '1';
                        currinf[intright] = '1';
                    }
                }

                if (currinf == cowhealth && isPossibleK) {
                    minK = min(minK, k);
                    maxK = max(maxK, k);
                    wasPossiblePatient = true;
                }
            }
            if (wasPossiblePatient) {
                possiblePatients++;
            }
        }
    }
    cout << possiblePatients << " " << minK << " " << ((maxK == t) ? "Infinity" : to_string(maxK)) << endl;
}