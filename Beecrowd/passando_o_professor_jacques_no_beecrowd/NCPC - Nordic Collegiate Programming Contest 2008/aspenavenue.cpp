#include <bits/stdc++.h>
using namespace std;

/*
first trees beginning of road
last        end

works on kattis but fails beecrowd, must be some float precision error
*/


int main() {
    int num_trees;
    double length;
    double width;

    cin >> num_trees >> length >> width;

    vector<double> positions(num_trees);

    for (auto &p: positions) {
        cin >> p;
    }

    sort(positions.begin(), positions.end());

    double pair_distance =  length / ((double)num_trees / 2-1);

    // cost[num_left][num_right] == optimal cost to place numleft trees at left, numright at right  
    vector<vector<double>> cost(num_trees/2 + 1, vector<double>(num_trees/2 + 1, 1e10)); 
    
    // no trees placed yet
    cost[0][0] = 0;

    for (int i = 0; i < num_trees / 2; i++) {
        // the trees are initially on the left
        cost[i + 1][0] = cost[i][0] + fabs(pair_distance * i - positions[i]);

        // we have to move to the right
        double c1 = fabs(pair_distance * i - positions[i]);
        double c2 = width;
        cost[0][i + 1] = cost[0][i] + sqrt(c1*c1 + c2*c2);

        // note that we use just the first n/2 in sorted order, since we will use every tree
    }

    for (int i = 1; i <= num_trees / 2; i++) {
        for (int j = 1; j <= num_trees / 2; j++) {
            // calculate every combination. We can place the tree either left (i++) or right (j++)
            double height_left = fabs(pair_distance * (i-1) - positions[i + j - 1]);
            double height_right = pair_distance * (j-1) - positions[i + j - 1];

            // place new tree on the left
            double left_cost  = cost[i - 1][j] + height_left;
            // place new tree on the right
            double right_cost = cost[i][j - 1] + sqrt(height_right*height_right + width*width);

            cost[i][j] = min(left_cost, right_cost);
        }
    }

    printf("%.10lf\n", cost[num_trees/2][num_trees/2]);
}