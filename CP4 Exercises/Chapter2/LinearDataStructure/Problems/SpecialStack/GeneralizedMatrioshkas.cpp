#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;


/*
sum of n's should be less than m

maybe there are more than one toy directly inside one


*/
int main(void) {
    string str;

    while (getline(cin, str)) {
        istringstream ss(str);

        bool isPossible = true;
        int val;
        stack<int> toys;
        stack<int> sum;
        while (ss >> val) {
            if (!isPossible) break;

            if (val > 0) {
                // close a toy
                if (toys.empty() || toys.top() != -val) {
                    // not possible
                    isPossible = false;
                } else {
                    // delete and see the sum
                    int currsize = val;
                    if (currsize <= sum.top()) {
                        // not possible
                        isPossible = false;
                    } else {
                        // pop both
                        sum.pop();
                        toys.pop();
                    }
                }
            } else if (val < 0) {
                // open a toy
                if (sum.empty()) {
                    // no toys opened, start it
                    sum.push(0);
                } else {
                    // add to the sum
                    sum.top() -= val;
                    sum.push(0); 
                }
                toys.push(val);

            }
        }
        if (isPossible && toys.empty()) {
            cout << ":-) Matrioshka!\n";
        } else {
            cout << ":-( Try again.\n";
        }
    }
}