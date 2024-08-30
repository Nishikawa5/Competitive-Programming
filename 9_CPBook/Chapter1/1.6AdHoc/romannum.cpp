#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <map>

using namespace std;
/* Every number from 0 to 3999 can be formed with roman numerals, so we can go from the greatest roman numeral
to the least, that will form the number we search */
const char roman[13][3] = {"M", "CM", "D", "CD", "C", "XC", "L",
                           "XL", "X", "IX", "V", "IV", "I"};
const int val[13] = {1000, 900, 500, 400, 100, 90, 50,
                     40, 10, 9, 5, 4, 1};

char *intToRoman(int n) {
    char *romanchars = (char *) malloc(sizeof(char) * 21);
    int idx = 0;

    for (int i = 0; i < 13; i++) {
        while (n >= val[i]) {
            n -= val[i];
            romanchars[idx++] = roman[i][0];
            if (roman[i][1] != '\0') {
                romanchars[idx++] = roman[i][1];
            }
        }
    }
    romanchars[idx] = '\0';
    return romanchars;
}

int ReturnOfRoman(void) {
    map <string, int> romap;
    string romannum;
    for (int i = 1; i < 4000; i++) {
        romap[intToRoman(i)] = i; // maps the roman number to the integer
    }

    while (cin >> romannum) {
        if (romannum[0] == '\0') printf("0\n");
        else if (romap[romannum] == 0) printf("This is not a valid number\n");
        else printf("%d\n", romap[romannum]);
    }
}

/* Another solution, it failed.
we have the cases VIV, DCD and some other corner cases.
Not a good solution because of that*/
int ReturnOfRomanFailed(void) {
    int roman[26];
    string number;
    
    roman['I' - 'A'] = 1;
    roman['V' - 'A'] = 5;
    roman['X' - 'A'] = 10;
    roman['L' - 'A'] = 50;
    roman['C' - 'A'] = 100;
    roman['D' - 'A'] = 500;
    roman['M' - 'A'] = 1000;

    while(cin >> number) {
        int sum = 0;
        int max = 0;
        int same;
        short cur;
        bool valid = true;
        for (int i = number.size() - 1; i >= 0; i--) {
            // get the number
            if (i != 0 && roman[number[i] - 'A'] > roman[number[i - 1] - 'A']) {
                if (number[i - 1] == 'I' && number[i] == 'V') cur = 4;
                else if (number[i - 1] == 'I' && number[i] == 'X') cur = 9;
                else if (number[i - 1] == 'X' && number[i] == 'L') cur = 40;
                else if (number[i - 1] == 'X' && number[i] == 'C') cur = 90;
                else if (number[i - 1] == 'C' && number[i] == 'D') cur = 400;
                else if (number[i - 1] == 'C' && number[i] == 'M') cur = 900;
                else {
                    valid = false;
                    break;
                }
                i--;
                same = 3;
            } else {
                cur = roman[number[i] - 'A'];
            }

            // check if the number is ok
            if (max < cur) {
                if (cur == 5 || cur == 50 || cur == 500) {
                    if (max == 4 || max == 40 || max == 400) {
                        valid = false;
                        break;
                    }
                    same = 3;
                }
                else same = 1;
                max = cur;
            } else if (cur == max) {
                same++;
            } else {
                valid = false;
                break;
            }

            if (same > 3) {
                valid = false;
                break;
            }
            sum += cur;
        }

        if (valid) printf("%d\n", sum);
        else printf("This is not a valid number\n");
    }
}