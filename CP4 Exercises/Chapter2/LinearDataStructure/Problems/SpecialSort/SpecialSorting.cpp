#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <limits.h>
#include <map>
#include <iostream>
#include <vector>

#define ui unsigned int

using namespace std;

void mergesort(int *arr, int l, int r, long *inv) {
    if (l >= r) return;
    
    int mid = l + (r - l) / 2;
    mergesort(arr, l, mid, inv);
    mergesort(arr, mid + 1, r, inv);


    // Assume the 2 arrays are sorted
    // merge the 2 arrays
    int size = r - l + 1;
    int merge[size];

    int leftpointer = l;
    int rightpointer = mid + 1;
    int i = 0;

    while (leftpointer <= mid && rightpointer <= r) {
        if (arr[leftpointer] <= arr[rightpointer]) {
            merge[i] = arr[leftpointer];
            leftpointer++;
        } else {
            merge[i] = arr[rightpointer];
            rightpointer++;
            // add the number of inversions
            (*inv) += mid - leftpointer + 1;
        }
        i++;
    }

    while (leftpointer <= mid) {
        merge[i] = arr[leftpointer];
        i++;
        leftpointer++;
    }

    while (rightpointer <= r) {
        merge[i] = arr[rightpointer];
        i++;
        rightpointer++;
    }

    for (int j = 0; j < size; j++) {
        arr[l + j] = merge[j];
    }
}

int main(void) {
    int N;
    long *inv = (long *)malloc(sizeof(long));
    int *seq = (int *)malloc(sizeof(int) * 1000000);
    while (scanf("%d", &N) != EOF && N) {
        for (int i = 0; i < N; i++) {
            scanf("%d", &seq[i]);
        }

        (*inv) = 0;
        mergesort(seq, 0, N - 1, inv);
        
        printf("%ld\n", *inv);
    }
}





/*
Marcelo is the first

choose a pair of consecutive elements that are out of order and swap

the first that gets the sequence sorted wins

the same as counting the number of moves for bubble sort?
We can use mergesort to get a better way to count the number of moves

*/

int BubblesAndBuckets(void) {
    int N;
    long *inv = (long *) malloc(sizeof(long));
    int *seq = (int *)malloc(sizeof(int) * 100000);
    while (scanf("%d", &N) != EOF && N) {
        for (int i = 0; i < N; i++) {
            scanf("%d", &seq[i]);
        }

        (*inv) = 0;
        mergesort(seq, 0, N - 1, inv);
        
        if ((*inv) % 2 == 0) printf("Carlos\n");
        else printf("Marcelo\n");
    }
}



/*
    int *arr = (int *)malloc(sizeof(int) * 10);
    int temp[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    // {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
    for (int i = 0; i < 10; i++) {
        arr[i] = temp[i];
    }
*/













int TLEbubblesort(void) {
    int N;

    while (scanf("%d", &N) != EOF && N) {
        vector<int> seq;
        int temp;

        for (int i = 0; i < N; i++) {
            scanf("%d", &temp);
            seq.push_back(temp);
        }

        int count = 0;
        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j < N - i - 1; j++) {
                if (seq[j] > seq[j + 1]) {
                    swap(seq[j], seq[j + 1]);
                    count++;
                }
            }
        }
        
        if (count % 2 == 0) printf("Carlos\n");
        else printf("Marcelo\n");
    }
    return 1;
}















/*
We can see inversions as the number of changes from left to right characters
to make something sorted
for example:
CAAA # 0
ACAA # 1
AACA # 2
AAAC # 3
it has 3 inversions

we can invert going from right to left to make an array sorted
*/

int DNASORTING(void) {
    int t;
    scanf("%d", &t);
    getchar();

    ui *inv = (ui *) malloc(sizeof(ui) * 100);              // stores the inversions of each dna
    char **DNAS = (char **) malloc(sizeof(char *) * 100);
    for (int i = 0; i < 100; i++) {
        DNAS[i] = (char *) malloc(sizeof(char) * 51);
    }

    while (t--) {
        int len, qtstr;
        scanf("%d %d", &len, &qtstr);

        // store the DNAS and count the inversions for each DNA
        for (int i = 0; i < qtstr; i++) {
            scanf("%s", DNAS[i]);

            inv[i] = 0;

            for (int j = 0; j < len; j++) {
                for (int k = j + 1; k < len; k++) {
                    if (DNAS[i][j] > DNAS[i][k]) {
                        inv[i]++;
                    }
                }
            }
        }

        // now lets sort the DNAs in according to inversions
        // use some algorithm of stable sort. Used bubble sort
        for (int i = 0; i < qtstr - 1; ++i){
            for (int j = 0; j < qtstr - i - 1; ++j){
                if (inv[j] > inv[j+1]){
                    swap(inv[j], inv[j+1]);
                    swap(DNAS[j], DNAS[j+1]);
                }
            }
        }
        
        for (int i = 0; i < qtstr; i++) {
            printf("%s\n", DNAS[i]);
        }
        if (t) printf("\n");
    }
    return 0;
}



/*
        for (int i = 0; i < qtstr; i++) {
            for (int j = i + 1; j < qtstr; j++) {
                if (inv[i] > inv[j]) {
                    swap(inv[i], inv[j]);
                    swap(DNAS[i], DNAS[j]);
                }
            }
        }
*/




















int cmpfunc( const void *a, const void *b) {
    return *(char*)a - *(char*)b;
}

struct DNA {
    char *dna;
    // char *sorted;
    int difference;

    DNA(char *dna, int n) {
        this->dna = (char *) malloc(sizeof(char) * (n + 1));
        char *sorted = (char *) malloc(sizeof(char) * (n + 1));
        strcpy(this->dna, dna);
        strcpy(sorted, dna);
        qsort(sorted, n, sizeof(char), cmpfunc);
        
        this->difference = 0;

        for (int i = 0; i < n; i++) {
            if (this->dna[i] != sorted[i]) {
                this->difference++;
            }
        }
    }

    bool operator < (const DNA& a) const {
        if (a.difference >= difference) {
            return true;
        }
        return false;
    }
};

int FAILED(void) {
    int M;
    int n, m;
    char *DNAstr;
    vector<DNA> DNAs;

    scanf("%d", &M);
    while(M--) {
        scanf("%d %d", &n, &m);
        DNAstr = (char *) malloc(sizeof(char) * (n + 1));
        for (int i = 0; i < m; i++) {
            scanf("%s", DNAstr);
            DNAs.push_back(DNA(DNAstr, n));
        }
        sort(DNAs.begin(), DNAs.end());
        printf("\n"); // delete
        for (int i = 0; i < m; i++) {
            printf("%s\n", DNAs[i]);
        }
    }
    return 0;
}















/* Easy to understand and implement but i was too focused in algorithm presented in the book and it wasted time
just need an array of frequencies and then print the numbers using the frequency array.
*/
int agesort(void) {
    ui ages[101]; // vector to store the number of people who have this age
    ui a;
    short age;
    ui t;
    
    while ((scanf("%u", &t) != EOF) && t) {
        memset(ages, 0, sizeof(ages));
        a = 1;
        for (int i = 0; i < t; i++) {
            scanf("%hd", &age);
            ages[age]++;
        }

        for (int i = 1; i < 101; i++) {
            for (int k = 0; k < ages[i]; k++) {
                printf("%d", i);

                if (a++ != t) printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}