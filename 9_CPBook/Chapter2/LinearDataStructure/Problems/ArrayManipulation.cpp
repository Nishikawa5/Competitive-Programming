#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

// every request takes 1000 milliseconds

/*
put every request in a server queue and see if they've already expired
 
*/
int ceildivide(int top, int bot) {
    return (bot + top - 1) / bot;
}

int main(void) {
    int n; // number of requests
    int k; // maximum number of requests per second

    scanf("%d %d", &n, &k);

    queue<int> servers;
    int maxServers = 1;

    int currtime;
    scanf("%d", &currtime);
    servers.push(currtime);

    for (int i = 1; i < n; i++) {
        scanf("%d", &currtime);
        // while the difference is >= 1000, remove from queue
        while (!servers.empty() && currtime - servers.front() >= 1000) {
            servers.pop();
        }

        servers.push(currtime);
        if (ceildivide(servers.size(), k) > maxServers) {
            maxServers = ceildivide(servers.size(), k);
        }
    }
    printf("%d\n", maxServers);
}



/*
didn't read the problem so i was thinking it was like LIS and it wasn't

*/
int greedilyincreasingsequence(void) {
    int n;
    scanf("%d", &n);

    vector<int> arr;
    int current;
    int last;
    cin >> last;
    arr.push_back(last);

    for (int i = 1; i < n; i++) {
        cin >> current;

        if (current > last) {
            arr.push_back(current);
            last = current;
        }
    }

    printf("%d\n", arr.size());

    for (int i = 0; i < arr.size(); i++) {
        if (i) printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
}
















int baloni(void) {
    int N;

    scanf("%d", &N);

    int hcount[100001] = {0};
    int heights[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &heights[i]);
        hcount[heights[i]]++;

        if (hcount[heights[i] + 1] > 0) {
            hcount[heights[i] + 1]--;
        }
    }

    int arrows = 0;

    for (int i = 0; i < N; i++) {
        arrows += hcount[heights[i]];
        hcount[heights[i]] = 0;
    }


    printf("%d\n", arrows);
}



/*
int tmp = heights[N - 1];
    arrows++;
    while (hcount[tmp]) {
        hcount[tmp]--;
        tmp++;
    }

    for (int j = N - 2; j >= 0; j--) {
        if (hcount[heights[j]] && heights[j] != heights[j + 1] + 1) {
            int currheight = heights[j];
            arrows++;

            while (hcount[currheight]) {
                hcount[currheight]--;
                currheight++;
            }
        }
    }
*/



























/*
given rows of '.' and 'X', representing empty beds and nonempty, respectively
must print the max number of beds that are empty between the selected and closest neighbor

*/

int beds(void) {
    string row;

    while (getline(cin, row)) {
        int max = 0;
        int x = 0;
        bool left = true;

        for (int i = 0; i < row.length(); i++) {
            if (row[i] == '.') {
                x++;
            } else {
                if (!left) {
                    if (max < ((x - ((x + 1) % 2)) / 2)) max = ((x - ((x + 1) % 2)) / 2);
                } else {
                    if (max < x - 1) max = x - 1;
                    left = false;
                }
                x = 0;
            }
        }
        if (max < x - 1) max = x - 1;
        printf("%d\n", max);
    }
    return 0;
}













/*
attackline - protect himself, attack and protect the neighbors in left and right
the problem doesn't specify that we can't "kill" killed soldiers

imagine soldiers specified by numbers (1, 2, ..., S)
we can make two arrays to represent what is in left/right of soldier (index)
*/

int armybuddies(void) {
    int S; // soldiers
    int B; // loss reports

    // left to right are killed
    int L;
    int R;

    int lineleft[100002];  // to the left of soldier of index i
    int lineright[100002]; // to the right of soldier of index i


    while (scanf("%d %d", &S, &B) != EOF && S) {

        for (int i = 0; i <= S; i++) {
            lineleft[i] = i - 1;
            lineright[i] = i + 1;
        }

        for (int i = 0; i < B; i++) {
            scanf("%d %d", &L, &R);

            if (lineleft[L] < 1) printf("* ");
            else printf("%d ", lineleft[L]);

            if (lineright[R] > S) printf("*\n");
            else printf("%d\n", lineright[R]);

            // replaces the soldier on index corresponding to the soldier that is behind him after killing
            // the right on the R goes to the left of L, (behind on the left)
            lineleft[lineright[R]] = lineleft[L];
            // the left on the L goes to the right of R, (behind on the right)
            lineright[lineleft[L]] = lineright[R];

            for (int i = 0; i <= S; i++) {
                printf("%d ", lineleft[i]);
            }
            printf("\n");
            for (int i = 0; i <= S; i++) {
                printf("%d ", lineright[i]);
            }
        }

        printf("-\n");
    }
    return 0;
}














void setFalse(bool *set, int n) {
    for (int i = 0; i < n; i++) {
        set[i] = false;
    }
}

bool checkVal2(bool *set, int n) {
    for (int i = 0; i < n; i++) {
        if (!set[i]) return false;
    }
    return true;
}

/* Easy to interpret and implement

*/

int poleposition(void) {
    int N;
    int a, b;
    int positions[1000];
    bool validarr[1000];
    bool valid;

    while ((scanf("%d", &N)) && N != 0) {
        valid = true;
        setFalse(validarr, N);
        for (int i = 0; i < N; i++) {
            scanf("%d %d", &a, &b);
            if (b + i >= 0 && b + i < N) {
                positions[b + i] = a;
                validarr[b + i] = true;
            } else {
                valid = false;
            }
        }

        if (checkVal2(validarr, N) && valid) {
            printf("%d", positions[0]);
            for (int i = 1; i < N; i++) {
                printf(" %d", positions[i]);
            }
            printf("\n");
        } else {
            printf("-1\n");
        }
    }
    return 0;
}






/* 
Return true we get every number from 1 to n - 1 from differences in data given 
*/

bool checkVal(bool *set, int n) {
    for (int i = 1; i < n; i++) {
        if (!set[i]) return false;
    }
    return true;
}

int jolly(void) {
    int n;
    int a, b;
    bool set[3000];

    while(scanf("%d", &n) != EOF) {
        setFalse(set, n);
        scanf("%d", &b);
        for (int i = 1; i < n; i++) {
            a = b;
            scanf("%d", &b);

            set[abs(a - b)] = true;
        }

        if (checkVal(set, n)) printf("Jolly\n");
        else printf("Not jolly\n");
    }
    return 0;
}



int turnOn(int S, int n) {
    return S | (1 << n);
}

/* This way is more efficient but we are limited to 64 elements in a set */
int wbitmask(void) {
    int n;
    int a, b;
    int S = 1;

    while(scanf("%d", &n) != EOF) {
        if (n > 0) scanf("%d", &b);

        for (int i = 1; i < n; i++) {
            a = b;
            scanf("%d", &b);

            S |= (1 << abs(a - b));
        }

        if (S == ((1 << n) - 1)) printf("Jolly\n");
        else printf("Not jolly\n");
    }
    return 0;
}