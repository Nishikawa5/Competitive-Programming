#include <bits/stdc++.h>
using namespace std;

struct Cow {
    int x, y; // coordinates
    int i;    // index
};

/*
if we sort the cows by x (east cow) and y (north cow) positions, then iterating:
y with every x and seeing if it colides it colides with this cow.

*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<Cow> east;
    vector<Cow> north;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        char dir;
        int x, y;
        cin >> dir >> x >> y;

        Cow newCow = {x, y, i};
        if (dir == 'E') {
            east.push_back(newCow);
        } else if (dir == 'N') {
            north.push_back(newCow);
        }
    }

    // sort the Cows
    sort(east.begin(), east.end(), [&](const Cow &c1, const Cow &c2) { return c1.y < c2.y; });
    sort(north.begin(), north.end(), [&](const Cow &c1, const Cow &c2) { return c1.x < c2.x; });

    // calculate the distance of each cow (-1 means no colision)
    vector<int> dist(n, -1);
    for (auto &ecow : east) {
        for (auto &ncow : north) {
            int dx = ncow.x - ecow.x;
            int dy = ecow.y - ncow.y;

            // all x and y are different, so can only collide if east cow is left down the north cow or direcly down/left
            if (dx >= 0 && dy >= 0) {
                // cow colide iff dx != dy

                // north cow collide (collide just 1 time)
                if (dist[ncow.i] == -1 && dy > dx) {
                    dist[ncow.i] = dy;
                }
                // east cow collide (cant collide with n that has already collided)
                if (dist[ncow.i] == -1 && dy < dx) {
                    dist[ecow.i] = dx;
                    break;              // collided, so this east cow cant colide anymore
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ((dist[i] == -1) ? "Infinity" : to_string(dist[i])) << endl;
    }
}