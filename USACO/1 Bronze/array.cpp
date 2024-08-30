#include <bits/stdc++.h>

using namespace std;

int main(void) {
    // initialize a vector w/ size n
    int n = 5;
    vector<int> v1(n);
    
    v1.resize(10);       // resize it

    // iterate
    vector<int> v{1, 7, 4, 5, 2};
    for (auto it = begin(v); it != end(v); it = next(it)) {
        cout << *it << " ";  // prints the values in the vector using the iterator
    }

    for (int element : v) {
        cout << element << " ";  // prints the values in the vector
    }

    // pair
    pair<string, int> pair1 = make_pair("Testing", 123);
}