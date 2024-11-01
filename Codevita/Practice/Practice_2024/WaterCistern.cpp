#include <bits/stdc++.h>

using namespace std;

#define PI 3.14159265358979323

double calculate_x_curve(int r, int deg) {
    return 2 * PI * r * (min(deg, 360 - deg) / 360.0);
}

int main(void) {
    int rad, height, start;
    int dist, deg;
    scanf("%d,%d,%d", &rad, &height, start);
    scanf("%d,%d", &dist, &deg);

    double min_dist;
    if (dist < 0) {
        // calculate 

        // go to the top
        // test every possible degree and get the min
        for (int dg_test = 0; dg_test < 360; dg_test++) {

        }
    } else {
        // curve
        double dist_x = calculate_x_curve(rad, deg);
        double dist_y = dist - start;
        min_dist = sqrt(dist_x * dist_x + dist_y * dist_y);
    }

}