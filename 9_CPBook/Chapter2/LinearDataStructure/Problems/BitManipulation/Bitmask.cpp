#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

#define max(a, b) (((a) > (b)) ? (a):(b))

int bitbybit(void) {
    int instructions;

    while (cin >> instructions && instructions) {
        string bitstr = "????????????????????????????????";
        string command;
        int i;
        int j;

        while (instructions--) {
            cin >> command;

            if (command == "SET") {
                cin >> i;
                bitstr[i] = '1';
            } else if (command == "CLEAR") {
                cin >> i;
                bitstr[i] = '0';
            } else if (command == "AND") {
                cin >> i >> j;
                if (bitstr[j] == '0') {
                    bitstr[i] = '0';
                } else if (bitstr[i] == '1' && bitstr[j] == '?') {
                    bitstr[i] = '?';
                }
            } else if (command == "OR") {
                cin >> i >> j;
                if (bitstr[j] == '1') {
                    bitstr[i] = '1';
                } else if (bitstr[i] == '0' && bitstr[j] == '?') {
                    bitstr[i] = '?';
                }
            }
        }
        reverse(bitstr.begin(), bitstr.end());
        cout << bitstr << endl;
    }
}



















int algoOfPhil(void) {
    string A;

    int t;
    scanf("%d", &t);

    for (int i = 1; i <= t; i++) {
        // in modulo 1000000007
        int decimalS = 0;
        cin >> A;
        bool parity = (((int) A.size()) % 2);

        stack<int> left;
        queue<int> right;
        // put the first n / 2 in a stack
        for (int i = 0; i < A.size() / 2; i++) {
            left.push(A[i]);
        }
        // put the last n / 2 in a queue
        for (int i = A.size() / 2; i < A.size(); i++) {
            right.push(A[i]);
        }

        while (left.size() + right.size() != 0) {
            int bit;
            
            if (left.size() > right.size()) {
                bit = left.top() - '0';
                left.pop();
            } else if (right.size() > left.size()) {
                bit = right.front() - '0';
                right.pop(); 
            } else {
                if (left.top() > right.front()) {
                    bit = left.top() - '0';
                    left.pop();
                } else {
                    bit = right.front() - '0';
                    right.pop(); 
                }
            }


            decimalS *= 2;
            decimalS += bit;
            decimalS = decimalS % 1000000007;

            parity = !parity;
        }
        // |A| is empty => terminates and return decimal representation of S
        printf("Case #%d: %d\n", i, decimalS);
    }
}






/*
slow because we've done with string and string.erase().
lets do with stack
*/
int slowAlgo(void) {
    string A;

    int t;
    scanf("%d", &t);

    for (int i = 1; i <= t; i++) {
        // in modulo 1000000007
        int decimalS = 0;
        cin >> A;
        int sizeA = A.size();
        bool parity = (((int) A.size()) % 2);

        while (sizeA != 0) {
            int bit;
            if (parity) {
                // |A| is odd => middle bit of A is added to end of S and removed from A
                bit = A[sizeA / 2] - '0';
                A.erase(sizeA / 2, 1);
            } else {
                // |A| is even => both middle of A are compared. The bigger is added to end of S and removed from A

                if (A[sizeA / 2] > A[sizeA / 2 - 1]) {
                    bit = A[sizeA / 2] - '0';
                    A.erase(sizeA / 2, 1);
                } else {
                    bit = A[sizeA / 2 - 1] - '0';
                    A.erase(sizeA / 2 - 1, 1);
                }
            }

            decimalS *= 2;
            decimalS += bit;
            decimalS = decimalS % 1000000007;

            parity = !parity;
            sizeA--;
        }
        // |A| is empty => terminates and return decimal representation of S
        printf("Case #%d: %d\n", i, decimalS);
    }


}


























int maxQueries(void) {
    int tc;

    scanf("%d", &tc);

    while(tc--) {
        int integers;
        int queries;

        scanf("%d %d", &integers, &queries);

        int x[integers];
        for (int i = 0; i < integers; i++) {
            scanf("%d ", &x[i]);
        }

        int maxQueries[231];
        for (int i = 0; i < 231; i++) {
            int maxAnd = 0;

            for (int k = 0; k < integers; k++) {
                maxAnd = max(maxAnd, i & x[k]);
            }
            maxQueries[i] = maxAnd;
        }

        int a;


        while (queries--) {
            scanf("%d", &a);

            printf("%d\n", maxQueries[a]);
        }
    } 
}

































// question 2

/*
N-dimensional unict cube
corners have weight
potency is the sum of weights of all neighbouring

*/
int potentcorner(void) {
    int dim;
    int weights[32768 + 1]; // the max number of corners is 2^15
    int potency[32768 + 1]; // potency per corner
    
    while (scanf("%d", &dim) != EOF) {
        int corners = 1 << dim;
        memset(potency, 0, sizeof(int) * corners);

        for (int i = 0; i < corners; i++) {
            scanf("%d", &weights[i]);
        }

        // for 2 corners be neighbours, the bits strings must have 1 different bit
        // brute force would take O(corners * dim)
        
        // get the potencies
        for (int i = 0; i < corners; i++) {
            // we want to change one bit from the string of bits
            // for that just use xor with 0...1...
            for (int k = 1; k < corners; k <<= 1) {
                potency[i] += weights[i ^ k];
            }
        }

        // get the maximum sum of 2 neighbors
        int maxsum = 0;
        for (int i = 0; i < corners; i++) {
            for (int k = 1; k < corners; k <<= 1) {
                if (potency[i] + potency[i ^ k] > maxsum) {
                    maxsum = potency[i] + potency[i ^ k];
                }
            }
        }
        printf("%d\n", maxsum);
    }
}




















/*
get the 1 bits in alternate order, 1001 would give a(n) = 0001 and b(n) = 1000 for example

*/

int getlastOne(int n) {
    return (n) & (-n);
}

int alternateorder(void) {
    int a[2]; // represents the numbers a and b
    int N;
    int temp;

    while ((scanf("%d", &N) != EOF) && N) {
        int i = 0;
        a[0] = 0;
        a[1] = 0;
        while(N) {
            temp = getlastOne(N);
            a[(i++) % 2] += temp;
            N -= temp;
        }
        printf("%d %d\n", a[0], a[1]);
    }
    return 0;
}