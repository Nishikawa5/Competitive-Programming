#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;

// chopin
/* Easy, use map and print
*/
int main(void) {
    string note;
    unordered_map <string, string> map;

    map["A#"] = "Bb";
    map["Bb"] = "A#";
    map["C#"] = "Db";
    map["Db"] = "C#";
    map["D#"] = "Eb";
    map["Eb"] = "D#";
    map["F#"] = "Gb";
    map["Gb"] = "F#";
    map["G#"] = "Ab";
    map["Ab"] = "G#";

    int i = 1;
    while (getline(cin, note)) {
        string part = note.substr(0, 2);
        printf("Case %d: %s\n", i++, (map[part] == "" ? "UNIQUE" : (map[part] + note.substr(2))).c_str());
    }
}








// assume n is positive
int myceil(double n) {
    return (((int) n == n) ? (n) : ((int) n + 1));
}

void printSheet(int sheetn, char *fb, int pg1, int pg2) {
    if (!pg1 && !pg2) return;

    printf("Sheet %d, %s: ", sheetn, fb);
    if (pg1 && pg2) printf("%d, %d\n", pg1, pg2);
    else if (pg1 && !pg2) printf("%d, Blank\n", pg1);
    else if (!pg1 && pg2) printf("Blank, %d\n", pg2);
}
/* Was kinda hard to interpret the problem but was easy to implement
 Apparently, we can't declare char * as strings
 for example: char *front = "front"; but we can declare as 
 char front[] = "front"; */
int bookletprinting(void) {
    int n;
    int blanks;
    int sheets;
    int curpg1;
    int curpg2;
    char front[] = "front";
    char back[] = "back ";

    while ((scanf("%d", &n) == 1) && n) {
        blanks = (4 - n % 4) % 4;           // at most 4 blanks
        sheets = myceil(n / 4.0);   // we have that much sheet
        curpg1 = 1;
        curpg2 = 0;

        printf("Printing order for %d pages:\n", n);
        // put blanks
        for (int i = 0; i < blanks; i++) {
            if (!(i % 2)) printSheet(i / 2 + 1, front, 0, curpg1);
            else printSheet(i / 2 + 1, back, curpg1, 0);
            curpg1++;

            if (curpg1 > n) break;
        }

        // put full sheets
        curpg2 = n;
        for (int i = blanks, tot = sheets * 2; i < tot; i++) {
            if (!(i % 2)) printSheet(i / 2 + 1, front, curpg2, curpg1);
            else printSheet(i / 2 + 1, back, curpg1, curpg2);
            curpg1++;
            curpg2--;
        }

    }
}







/* Very confusing to construct the map, would be easier to build 3 strings with the keyboard specifications
 and try to find the letter in these strings and go back one index
 Example char *row1 = "QWERTYUIOP"; */
int wertyu(void) {
    char *word = (char *) malloc(sizeof(char) * 10001);
    char *c = (char *) malloc(sizeof(char) * 256);
    c['W'] = 'Q';
    c['S'] = 'A';
    c['X'] = 'Z';
    c['E'] = 'W';
    c['D'] = 'S';
    c['C'] = 'X';
    c['R'] = 'E';
    c['F'] = 'D';
    c['V'] = 'C';
    c['T'] = 'R';
    c['G'] = 'F';
    c['B'] = 'V';
    c['Y'] = 'T';
    c['H'] = 'G';
    c['N'] = 'B';
    c['U'] = 'Y';
    c['J'] = 'H';
    c['M'] = 'N';
    c['I'] = 'U';
    c['K'] = 'J';
    c[','] = 'M';
    c['O'] = 'I';
    c['L'] = 'K';
    c['.'] = ',';
    c['P'] = 'O';
    c[';'] = 'L';
    c['/'] = '.';
    c['['] = 'P';
    c[']'] = '[';
    c['\\'] = ']';
    c['\''] = ';';
    c['1'] = '`';
    c['2'] = '1';
    c['3'] = '2';
    c['4'] = '3';
    c['5'] = '4';
    c['6'] = '5';
    c['7'] = '6';
    c['8'] = '7';
    c['9'] = '8';
    c['0'] = '9';
    c['-'] = '0';
    c['='] = '-';
    c[' '] = ' ';
    
    while ((scanf("%[^\n]s", word) != EOF)) {
        int it = 0;
        while (word[it] != '\0') {
            word[it] = c[word[it]];
            it++;
        }

        printf("%s\n", word);
        getchar(); // to ignore the end line
    }
}