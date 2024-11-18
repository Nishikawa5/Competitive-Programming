#include <bits/stdc++.h>

using namespace std;

#define PI 3.14159265358979323

double calculate_x_curve(int r, double deg) {
    return 2 * PI * r * (min(deg, 360 - deg) / 360.0);
}

/*
r,h,s
d,g
*/

double calculate_dist_to_point_inside(double theta, int r, int d, int g) {
    double angle_diff = (g - theta) * PI / 180.0;

    return sqrt(r * r + d * d - 2 * r * d * cos(angle_diff));
}

double calculate_dist_top(double theta, int h, int r, int d, int g) {
    double x_dist = calculate_x_curve(r, theta);
    double term1 = sqrt(h * h + x_dist * x_dist);
    double term2 = calculate_dist_to_point_inside(theta, r, d, g);

    return term1 + term2;
}

double calculate_gradient(double theta, int h, int r, int d, int g, double epsilon = 1e-5) {
    double f_plus = calculate_dist_top(theta + epsilon, h, r, d, g);
    double f_minus = calculate_dist_top(theta - epsilon, h, r, d, g);
    return (f_plus - f_minus) / (2 * epsilon);
}

int main(void) {
    int rad, height, start;
    int dist, deg;
    scanf("%d,%d,%d", &rad, &height, &start);
    scanf("%d,%d", &dist, &deg);

    double min_dist;
    if (dist < 0) {
        // calculate 
        // go to the top
        // test some possible degrees and get the min
        // dont need to test every degree since result is rounded?

        /*
        minimize:
        sqrt(h^2 + x_curve(theta)^2) +
        sqrt(h^2 + d^2 - 2 * h * d * cos(g - theta))

        x_curve(theta) = 2 * PI * r * theta / 360.0

        depends only on theta, so lets try grad descent
        */
        dist = -dist;
        double delta = 1e-2;
        double lr = 0.01;
        double gradient;

        double theta = 0;
        double theta_new;

        double curr_distance;
        double last_distance;

        do {
            gradient = calculate_gradient(theta, start, rad, dist, deg);
            theta_new = theta - lr * gradient;

            curr_distance = calculate_dist_top(theta, start, rad, dist, deg);
            last_distance = calculate_dist_top(theta_new, start, rad, dist, deg);

            theta = theta_new;
        } while (fabs(curr_distance - last_distance) > delta);

        min_dist = curr_distance;
    } else {
        // curve
        double dist_x = calculate_x_curve(rad, deg);
        double dist_y = dist - start;
        min_dist = sqrt(dist_x * dist_x + dist_y * dist_y);
    }

    cout << round(min_dist) << endl;
}