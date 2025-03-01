#include <bits/stdc++.h>
using namespace std;

/*
ideas:
use list to simulate it
pros: easy pushs
cons: high get cost

use array
pros: low cost get
cons: have to move when push

use two deque
*/
void balance_queues(deque<int> &left, deque<int> &right) {
    // difference always <= 1
    while (abs((int) left.size() - (int) right.size()) > 1) {
        if (left.size() > right.size()) {
            // left back -> right front
            right.push_front(left.back());
            left.pop_back();
        } else {
            // right front -> left back
            left.push_back(right.front());
            right.pop_front();
        }
    }
    // make left bigger
    if (right.size() > left.size()) {
        left.push_back(right.front());
        right.pop_front();
    }

}

int main() {
    int n;
    cin >> n;

    deque<int> left, right;
    while (n--) {
        string command;
        int x;
        cin >> command >> x;

        if (command[0] == 'g') {
            // get
            if (x < left.size()) {
                cout << left[x];
            } else {
                cout << right[x - left.size()];
            }
            cout << endl;
        } else if (command[5] == 'b') {
            // pushback
            right.push_back(x);
            balance_queues(left, right);
        } else if (command[5] == 'f') {
            // pushfront
            left.push_front(x);
            balance_queues(left, right);
        } else {
            // pushmiddle always pushback to left to pushmiddle
            // that means always make left.size() <= right.size() 
            left.push_back(x);
            balance_queues(left, right);
        }
    }
}