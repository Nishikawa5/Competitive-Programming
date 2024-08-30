#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string.h>
using namespace std;

/* Sorting exercises */
/* 2.2.1.3 
1. We can sort or use Hashtable (faster)
2. We can sort or use Hashtable (faster)
3. We can use two pointers
4. We need to sort and use binart search to find the left limit
5. Dynamic programming
6. Sort and get the element in the middle 
7. Get the element in the middle

2.2.1.4
1. Invert and transpose the matrix
2. Just change the ij to ji elements
3. 

2.2.2
Special sorting problems
Merge sort - divide the list in 2 -> divide again -> ... -> sort the list -> merge the lists

Count sort O(n + k) - we create a frequency array with size k and all 0, where k = R - L + 1 for L < n < R
then we pass through the array updating the frequencies
after that, change the frequency array to prefix sums like f[i] = f[i] + f[i - 1];

radix sort -
sort the digits (make all integers have d digits) from left to right
2.2.2.2 - We can separe the negatives from positives in O(n), then sort negatives and positives separated and
ignoring the signs, after that we invert the array of negatives and append negative and positives
*/
void cmpStr() {

}

/* given L <= n <= R, sort in O(n + k) */
int main(void) {
    int L = 2;
    int R = 5;
    vector <int> arr = {2, 5, 2, 2, 3, 3};
    int k = R - L + 1;
    int *freq = (int *) malloc(sizeof(int) * k);
    for (int i = 0; i < k; i++) freq[i] = 0;

    // get the frequency of elements
    for (int i = 0; i < arr.size(); i++) {
        freq[arr[i] - L]++;
    }

    // prefix sum to make easier to put element in place
    for (int i = 1; i < k; i++) {
        freq[i] += freq[i - 1];
    }
    /* we have the frequency array as follows
    index            -  0       1         2          3
    numbers/quantity - 2/2   2/2 3/2   2/2 3/2  2/2 3/2 5/1
    the sum of the quantities is the index the next number should be
    */
    int *A = (int *) malloc(sizeof(int) * arr.size());
    for (int i = arr.size() - 1; i >= 0; i--) {
        // place the elements of arr in A in sorted order with the order the repeated numbers appears
        A[--freq[arr[i] - L]] = arr[i];
    }
    for (int i = 0; i < arr.size(); i++) {
        printf("%d, ", A[i]);
    }
}







int asd(void) {
    vector <string> names = {"asdasdasd", "basdasd", "asdaa", "a", "b", "c", "d"};
    vector <int> ages = {1, 34 , 51, 2, 0, 124, -1};
    vector <double> fraction = {0.23, 41, 42.12, 0.12, 0, 32.11, 1.21};

    sort(names.begin(), names.end());
    sort(ages.begin(), ages.end());
    sort(fraction.begin(), fraction.end());
    
    for (int i = 0; i < names.size(); i++) {
        printf("age: %d fraction: %lf name: %s\n", ages[i], fraction[i], names[i].c_str());
    }
    sort(fraction.rbegin(), fraction.rend());

}