#include <stdio.h>
#include <stdlib.h>
#include <iostream>

/*
We can use integers to store lightweight sequences of bits, as it is stored as a sequence of bits in memory
and we have bitwise manipulation that makes it easier to manipulate the string of bits
we can also represent sets, using the bit index as element of set and 1 if it is on the set, 0 if not



1. We can represent integers as bits (power of 2)

2. We can multiply/divide by two by shifting to left/right the positions of bits (automatic truncation)

3. or operation - 34 is 100010 in base two, we can make like 34 | (1 << 3) to add 3 in the set

4. and operation - we can make n & (1 << 3) to se if 3 is in the set given by n
   if n & (1 << j) != 0, the j-th item is on, off otherwise

5. similarly we can make   ~(1<<j) & S to turn off the j-th item
   101010 & 111101 = 101000

6. to flip the status of j-th we use    S ^= (1<<j)

7. T = ((S) & -(S)) to get the value of the least significant bit that is on (two's complement property)
   in two complement we invert everything and add one, so S = ...10000...000 -> -S = ...01111...111 + 1 = ...S

8. To turn on all bits in a set of size n, use S = (1<<n) - 1

9. To enumerate all proper subsets of a given a bitmask, e.g., if mask = (18) = (10010),
then its proper subsets are {(18) = (10010), (16) = (10000), (2) = (00010)},
we can use:
    int mask = 18;
    for (int subset = mask; subset; subset = (mask & (subset-1)))
    cout << subset << "\n";

10. __builtin_popcount(S) to count how many bits that are on in S and
    __builtin_ctz(S) to count how many trailing zeroes in S. (in cpp)
*/


using namespace std;


/* grey to k-th 
xor 
C = A xor B

*/
int main(void) {
    int t; // tests
    int n; // poweroftwo
    int k; // k-th grey

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &n, &k);
        printf("%d\n", k ^ (k >> 1));
    }
}













int turnOnLast(int S);
int turnOffLast(int S);
bool isPowerOfTwo(int S);
int modulo_ex1(void);
void printsubsets(int N);
int getLastZero(int S);
int turnOffSeq(int S);
int turnOnSeq(int S);

/*
000 0 000
001 1 001
011 3 010
010 2 011
110 6 100
111 7 101
101 5 110
100 4 111
We can make a xor operation of some number k shifted to right and k to get the k-th grey number
*/

int k_thgrey(void) {
    int t; // tests
    int n; // poweroftwo
    int k; // k-th grey

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &n, &k);
        printf("%d\n", k ^ (k >> 1));
    }
}

int turnOnSeq(int S) {
    int lastone = (S) & -(S);
    return S + (lastone - 1);
}



int turnOffSeq(int S) {
    int temp = getLastZero(S) - 1;
    temp = -temp - 1;
    return S & temp;
}



// return a set with an one where the last zero is
int getLastZero(int S) {
    int temp = -S - 1;
    return (temp) & -(temp);
}

int turnOnLast(int S) {
    int temp = -S - 1;
    return S + ((temp) & -(temp));
}


int turnOffLast(int S) {
    return S ^ ((S) & -(S));
}


bool isPowerOfTwo(int S) {
    // could also use S & (S - 1) == 0
    return S && ((S) & -(S)) == S;
}





/*
we can see the following algorithm as follows:
a decimal number can be written as a sum of powers of two multiplied by 1 or 0
we can organize them by sorting in crescent order of powers
after one power, every power of two will be divisible by some power of two
we want to get the left side which have powers of two less than the power we are dividing

we can do that by:
A power of two is always 1 followed by zeros, so -1 of this power gives ones after the position of this one
the rest is zero. This sequence of bits is exactly what we need to determine the rest
so making that and N we can reach our result

*/
int modulo_ex1(void) {
    int S = 7;
    int N = 4;

    int modulo = S & (N - 1);
    printf("%d\n", modulo);
}


void printsubsets(int N) {
    int mask = N;
    for (int subset = mask; subset; subset = (mask & (subset - 1))) {
        cout << subset << endl;
    }
}

