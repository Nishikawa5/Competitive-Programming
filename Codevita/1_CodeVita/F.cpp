#include <bits/stdc++.h>

using namespace std;

int minOperations(int arr[], int n)
{
    // Initializing vector of pair type which contains value
    // and index of arr
    vector<pair<int, int>> vect;
    for (int i = 0; i < n; i++) {
        vect.push_back(make_pair(arr[i], i));
    }
 
    // Sorting array num on the basis of value
    sort(vect.begin(), vect.end());
 
    // Initializing variables used to find maximum
    // length of increasing streak in index
    int res = 1;
    int streak = 1;
    int prev = vect[0].second;
    for (int i = 1; i < n; i++) {
        if (prev < vect[i].second) {
            res++;
 
            // Updating streak
            streak = max(streak, res);
        }
        else
            res = 1;
        prev = vect[i].second;
    }
 
    // Returning number of elements left except streak
    return n - streak;
}

int main(void) {
    int arr[] = {1, 2, 4, 2, 1, 3, 4, 2, 3, 1}; // 1 2 4 2 1 3 4 2 3 1
    printf("%d\n", minOperations(arr, 10));
}