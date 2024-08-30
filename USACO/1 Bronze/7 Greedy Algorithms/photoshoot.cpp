#include <bits/stdc++.h>
using namespace std;

/*
Interpreted this problem wrongly, which made me think of a harder? problem
almost completly different. Attention to the interpretation.

G even
H doesn't matter
HHHHGGGGG


GGHGHG
*/
int main() {
    int n;
    cin >> n;

    string cows;
    cin >> cows;

    int rev = 0;
    // go backards since reverse from start
    for (int i = n - 2; i >= 0; i -= 2) {
        if ((cows[i] == 'G' && cows[i + 1] == 'H' && rev % 2 == 0) ||
            (cows[i] == 'H' && cows[i + 1] == 'G' && rev % 2 == 1)) {
            rev++;
        }
    }
    cout << rev << endl;
}