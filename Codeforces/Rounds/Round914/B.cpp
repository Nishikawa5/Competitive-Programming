#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

#define ull unsigned long long int

int analize(int initial, vector <int> sorted) {
    ull sum = (ull) initial;
    int k = 0;

    bool ignore = true;

    for (int i = 0; i < sorted.size(); i++) {
        if (sum >= sorted[i] && (!ignore || sorted[i] != initial)) {
            sum += (ull) sorted[i];
            k++;
        }

        if (sum >= 1000000000) {
            if (ignore) return sorted.size() - 1;
            return sorted.size() - i - 1 + k;
        }

        if (sorted[i] == initial) {
            ignore = false;
        }
    }
    return k;
}

int main(void) {
    int t;
    int n;

    scanf("%d", &t);

    int temp;
    while(t--) {
        scanf("%d", &n);
        vector <int> sorted;
        vector <int> original;

        for (int i = 0; i < n; i++) {
            scanf("%d", &temp);
            getchar();

            sorted.push_back(temp);
            original.push_back(temp);
        }
        sort(sorted.begin(), sorted.end());

        printf("%d", analize(original[0], sorted));
        for (int i = 1; i < n; i++) {
            printf(" %d", analize(original[i], sorted));
        }
        printf("\n");
    }
}