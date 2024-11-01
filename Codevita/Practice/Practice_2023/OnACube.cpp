#include <bits/stdc++.h>

using namespace std;

/*
10x10x10 cube
got too many cases
*/
float dist(float x0, float y0, float z0, float x, float y, float z) {
    if (((x0 == 0 || x0 == 10) && x0 == x) || (y0 == 0 ||)) {

    }
}

int main(void) {
    int n;
    scanf("%d", &n);

    float x0, y0, z0;
    float x , y , z ;
    float totaldist = 0;

    scanf("%f,%f,%f", &x0, &y0, &z0); // initial points
    getchar();
    for (int i = 0; i < n; i++) {
        scanf("%f,%f,%f", &x, &y, &z);
        getchar();

        totaldist += dist(x0, y0, z0, x, y, z);

        x0 = x;
        y0 = y;
        z0 = z;
    }
}