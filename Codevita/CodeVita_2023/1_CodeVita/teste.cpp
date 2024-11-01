#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long int
/*
array of integers
*/
ull strtobit(string s) {
    ull sum = 0;
    ull mult = 1;
    for (int i = 0; i < (int) s.length() && i < 64; i++) {
        sum += (s[i] - '0') * mult;
        mult *= 2;
    }
    return sum;
}

int findmaxind(vector <int> arr) {
    int max = INT_MIN;
    int ind = -1;
    for (int i = 0; i < (int) arr.size(); i++) {
        if (max < arr[i]) {
            max = arr[i];
            ind = i;
        }
    }
    return ind;
}

int main(void) {
    vector <int> arr;
    vector <int> sortedarr;

    string Ra[2];
    string Ru[2];

    int k;

    char i;
    int temp;

    scanf("%d", &temp);
    arr.push_back(temp);
    while ((i = getchar()) != '\n') {
        scanf("%d", &temp);
        arr.push_back(temp);
    }

    cin >> Ra[0];
    cin >> Ra[1];
    cin >> Ru[0];
    cin >> Ru[1];

    cin >> k;

    ull bra[2];
    ull bru[2];

    bra[0] = strtobit(Ra[0]);
    bra[1] = strtobit(Ra[1]);

    bru[0] = strtobit(Ru[0]);
    bru[1] = strtobit(Ru[1]);

    int sumra = 0;
    int sumru = 0;

    int round = 0;

    while(!arr.empty()) {
        int start = findmaxind(arr);
        int dif = start - k;
        int iterations = 2 * k + 1;
        start = max(start - k, 0);

        if (start + iterations > (int) arr.size()) {
            iterations -= (start + iterations - (int) arr.size());
        } else if (dif < 0) {
            iterations += dif;
        }
        
        int tempsum = 0;
        for (int i = 0; i < iterations; i++) {
            if (!arr.empty()) {
                tempsum += arr[start];
                arr.erase(arr.begin() + start);
            }
        }


        if (round % 2 == 0) {
            // ra
            sumra += tempsum;
        } else {
            sumru += tempsum;
        }
        round++;
    }


    if ((round - 1) % 2 == 0) {
        bra[0] = ~bra[0];
    } else {
        bru[0] = ~bru[0];
    }

    if (sumra > sumru) {
        bra[1] = ~bra[1];
    } else if (sumru > sumra) {
        bru[1] = ~bru[1];
    } else {
        bra[1] = ~bra[1];
        bru[1] = ~bru[1];
    }

    if (bra[0] ^ bra[1] > bru[0] ^ bru[1]) {
        printf("Rahul\n");
    } else if (bra[0] ^ bra[1] < bru[0] ^ bru[1]) {
        printf("Rupesh\n");
    } else {
        printf("Rahul\n");
        printf("Rupesh\n");
    }
}