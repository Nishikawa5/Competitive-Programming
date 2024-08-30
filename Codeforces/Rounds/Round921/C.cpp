#include <bits/stdc++.h>

using namespace std;


int main(void) {
    int t;
    int sublen, fletters, totallen;
    char alphabet[27] = "abcdefghijklmnopqrstuvwxyz";
    int countlr[26];
    int countrl[26];
    char str[1000];

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d %d", &sublen, &fletters, &totallen);
        getchar();
        bool isCoveredlr[26];
        bool isCoveredrl[26];
        memset(countlr, 0, sizeof(countlr));
        memset(countrl, 0, sizeof(countrl));
        memset(isCoveredlr, 0, sizeof(isCoveredlr));
        memset(isCoveredrl, 0, sizeof(isCoveredrl));

        for (int i = 0; i < totallen; i++) {
            str[i] = getchar();
        }

        for (int i = 0; i < totallen; i++) {
            // i l to r
            // j r to l
            int j = totallen - 1 - i;

            countlr[str[i] - 'a']++;
            countrl[str[j] - 'a']++;

            for (int k = 0; k < fletters; k++) {
                if (countlr[k] < sublen - 1) {
                    break;
                } else if (k == fletters - 1) {
                    isCoveredlr[str[i] - 'a'] = true;
                }
            }

            for (int k = 0; k < fletters; k++) {
                if (countrl[k] < sublen - 1) {
                    break;
                } else if (k == fletters - 1) {
                    isCoveredrl[str[j] - 'a'] = true;
                }
            }
        }

        bool allCovered = true;
        char notCovered;
        char dir;
        for (int i = 0; i < fletters; i++) {
            if (!isCoveredlr[i]) {
                allCovered = false;
                notCovered = i + 'a';
                dir = 'r'; // put the char in right
                break;
            }

            if (!isCoveredrl[i]) {
                allCovered = false;
                notCovered = i + 'a';
                dir = 'l'; // put the char in left
                break;
            }
        }
        if (allCovered) {
            printf("YES\n");
        } else {
            printf("NO\n");

            if (dir == 'r') printf("%c", notCovered);

            for (int i = 0; i < sublen; i++) {
                if (alphabet[i] != notCovered) {
                    printf("%c", alphabet[i]);
                }
            }

            if (dir == 'l') printf("%c", notCovered);
            printf("\n");
        }
    }
}