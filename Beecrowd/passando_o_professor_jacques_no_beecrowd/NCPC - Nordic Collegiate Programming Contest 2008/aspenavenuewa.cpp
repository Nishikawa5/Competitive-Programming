#include <bits/stdc++.h>
using namespace std;

/*
first trees beginning of road
last        end


*/


int main() {
    cout << fixed;
    cout << setprecision(10);

    int num_trees;
    double length;
    double width;

    cin >> num_trees >> length >> width;

    vector<double> positions(num_trees);

    for (auto &p: positions) {
        cin >> p;
    }

    sort(positions.begin(), positions.end());

    double pair_distance =  length / ((num_trees / 2) - 1);
    double total_cost = 0;

    // now just pair them
    for (int i = 0; i < num_trees; i += 2) {
        // adjust the first
        // this pair is at
        double at = pair_distance * i/2;

        double cost1 = 0;
        double cost2 = 0;

        cost1 = abs(at - positions[i]);
        cost2 = abs(at - positions[i + 1]);
        
        if (positions[i + 1] == at) {
            cost1 += width;
        } else {
            double y = at - positions[i + 1];
            cost1 += sqrt(y * y + width * width);
        }


        if (positions[i] == at) {
            cost2 += width;
        } else {
            double y = at - positions[i];
            cost2 += sqrt(y * y + width * width);
        }

        total_cost += min(cost1, cost2);
    }
    cout << total_cost << endl;
}