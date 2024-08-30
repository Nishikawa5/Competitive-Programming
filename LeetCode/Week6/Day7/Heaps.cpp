#include <iostream>
#include <queue>

using namespace std;


class Solution {
public:
    // given an array, return the k-th greatest element if the array in sorted order
    int findKthLargest(vector<int>& nums, int k) {
        // an array that is always sorted
        priority_queue<int> kthmax;

        for (int num : nums) {
            // invert the array
            kthmax.push(-num);

            // make it always of size k
            if (kthmax.size() > k) {
                // delete from the top
                kthmax.pop();
            }
        }
        
        // it's inverse, so the top will be less than the other k - 1 elements
        return -kthmax.top();
    }
};