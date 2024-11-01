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

string negatestr(string s) {
    for (int i = 0; i < (int) s.length(); i++) {
        if (s[i] == '0') s[i] = '1';
        else s[i] = '0';
    }
    return s;
}

string xorstr(string bits1, string bits2) {
    int minimum = min(bits1.length(), bits2.length());

    bool bits1greatest;

    if (bits1.length() > bits2.length()) {
        bits1greatest = true;
    } else {
        bits1greatest = false;
    }

    for (int i = 0; i < minimum; i++) {
        if (bits1[bits1.length() - i - 1] == bits2[bits2.length() - i - 1]) {
            if (bits1greatest) {
                bits1[bits1.length() - i - 1] = '0';
            } else {
                bits2[bits2.length() - i - 1] = '0';
            }
        } else {
            if (bits1greatest) {
                bits1[bits1.length() - i - 1] = '1';
            } else {
                bits2[bits2.length() - i - 1] = '1';
            }
        }
    }


    if (bits1greatest) return bits1;
    else return bits2;
}

// return true if bits1 > bits2
int comparebit(string bits1, string bits2) {

    // assume bits1 is the greatest string

    for (int i = 0; i < (int) bits1.length(); i++) {
        char bit1;
        char bit2;

        if ((int) bits2.length() - (int) bits1.length() + i < 0) {
            bit2 = '0';
        } else {
            bit2 = bits2[(int) bits2.length() - (int) bits1.length() + i ];
        }
        bit1 = bits1[i];

        if (bit1 == '1' && bit2 == '0') {
            return 1;
        } else if (bit1 == '0' && bit2 == '1') {
            return 2;
        }
    }
    return 0;
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
        Ra[1] = negatestr(Ra[1]);
    } else {
        Ru[1] = negatestr(Ru[1]);
    }

    if (sumra > sumru) {
        Ra[0] = negatestr(Ra[0]);
    } else if (sumru > sumra) {
        Ru[0] = negatestr(Ru[0]);
    } else {
        Ra[0] = negatestr(Ra[0]);
        Ru[0] = negatestr(Ru[0]);
    }

    string xRa = xorstr(Ra[0], Ra[1]);
    string xRu = xorstr(Ru[0], Ru[1]);

    if (xRu.length() > xRa.length()) {
        int rst = comparebit(xRu, xRa);
        if (rst == 2) {
            printf("Rahul\n");
        } else if (rst == 1) {
            printf("Rupesh\n");
        } else {
            printf("Rahul\n");
            printf("Rupesh\n");
        }
    } else {
        int rst = comparebit(xRa, xRu);
        if (rst == 1) {
            printf("Rahul\n");
        } else if (rst == 2) {
            printf("Rupesh\n");
        } else {
            printf("Rahul\n");
            printf("Rupesh\n");
        }
    }

}