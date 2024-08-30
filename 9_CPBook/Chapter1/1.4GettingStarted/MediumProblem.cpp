#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define true 1
#define false 0
#define bool int
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define ABS(a) ((a) > 0 ? (a) : (-a))

// 0 to 65536
#define usi unsigned short int
#define ui unsigned int

int main(void) {
    usi N;
    usi n, m; // number of different prizes and number of different stickers 

    scanf("%hu", &N);
    while (N--) {
        scanf("%hu %hu", &n, &m);
        int *prize = (int *) malloc(sizeof(int) * n);            // the prices of prizes
        usi **paysticker = (usi **) malloc(sizeof(usi *) * n);   // the stickers to get prize
        usi *stickers = (usi *) malloc(sizeof(usi) * m);         // the stickers we have

        usi *k = (usi *) malloc(sizeof(usi) * n);
        // each sticker can be used to claim one prize
        for (int i = 0; i < n; i++) {
            scanf("%hu", &k[i]);

            paysticker[i] = (usi *) malloc(sizeof(usi) * k[i]);
            for (int j = 0; j < k[i]; j++) {
                scanf("%hu", &paysticker[i][j]);
            }
            scanf("%d", &prize[i]);
        }

        for (int i = 0; i < m; i++) {
            scanf("%hu", &stickers[i]);
        }

        int total = 0;
        for (int i = 0; i < n; i++) {
            usi min = stickers[paysticker[i][0] - 1];
            for (int j = 1; j < k[i]; j++) {
                if (stickers[paysticker[i][j] - 1] < min) min = stickers[paysticker[i][j] - 1];
            }
            total += prize[i] * min;
        }

        printf("%d\n", total);
    }
}

// given an array of usi with length n, return the minimum value of this array
usi minarr(usi *arr, usi n) {
    usi temp = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < temp) temp = arr[i];
    }
}







int bitequalizer(void) {
    char *S = (char *) malloc(sizeof(char) * 101);
    char *T = (char *) malloc(sizeof(char) * 101);

    usi C;

    scanf("%hu", &C);

    // make different 10 and different 01
    for (int i = 1; i <= C; i++) {
        scanf(" %s %s", S, T);

        usi it = 0; // iterates through the strings
        usi qmzero = 0; // number of question marks
        usi qmone  = 0;
        usi zerone = 0;  // S is zero and T is one
        usi onezero = 0; // S is one and T is zero
        while (S[it] != '\0') { // the strings have the same number of char, so we can test just for one
            if (S[it] == '0' && T[it] == '1') zerone++;
            else if (S[it] == '1' && T[it] == '0') onezero++;
            else if (S[it] == '?' && T[it] == '0') qmzero++;
            else if (S[it] == '?' && T[it] == '1') qmone++; //we can just transform 0 into 1 in this case, so it's not necessary

            it++;
        }
        // make onezero and zerone as equal as possible w/ question marks, but don't make it unnecessary
        // qmzero -> onezero and qmone -> zerone
        printf("Case %d: ", i);
        if (onezero <= zerone + qmone) {
            // make the changes, then make the changes again and sum qmarks
            printf("%d\n", MIN(onezero, zerone) + abs(onezero - zerone) + qmone + qmzero);
        } else {
            printf("-1\n");
        }
    }
}










int battlesimulation(void) {
    char *attacks = (char *) malloc(sizeof(char) * 1000001);

    scanf("%s", attacks);

    char* lastwo = (char *) malloc(sizeof(char) * 2); // stores the last two attacks
    lastwo[0] = lastwo[1] = 0; // at first no attacks
    int pstart = 0; // a pointer that points to the "start", the last defense we did
    int pend = 0;   // a pointer that points to the "end". the last attack monster did
    while (attacks[pend] != '\0') {
        char temp = attacks[pend];

        if ((attacks[pend] == lastwo[0] || attacks[pend] == lastwo[1] || lastwo[0] == lastwo[1]) || !lastwo[0]) {
            if (attacks[pend] == 'R') attacks[pstart] = 'S';
            else if (attacks[pend] == 'B') attacks[pstart] = 'K';
            else attacks[pstart] = 'H';

            lastwo[0] = lastwo[1];
            lastwo[1] = temp;
        } else {
            pstart -= 2;
            attacks[pstart] = 'C';

            lastwo[0] = lastwo[1] = 0;
        }

        pend++;
        pstart++;
    }
    attacks[pstart] = '\0';
    printf("%s\n", attacks);
}






/*
Tennis round

Each player is assigned to a number

if the difference is
*/
bool check(int start, int end, int i, int j);
usi round(int start, int end, int i, int j, int acc);
int tennisrounds(void) {
    usi N; // rounds
    int i, j;
    
    while (scanf("%hu %d %d", &N, &i, &j) != EOF) {
        printf("%d\n", round(1, (int) pow(2, N), i, j, N));
    }
}

// return true if i and j is n range of start to end
bool check(int start, int end, int i, int j) {
    return start <= i && end >= i && start <= j && end >= j;
}

// return the least round
usi round(int start, int end, int i, int j, int acc) {
    if (check(start, start + (end - start + 1)/2 - 1, i, j)) return round(start, start + (end - start + 1)/2 - 1, i, j, acc - 1);
    else if (check(start + (end - start + 1)/2, end, i, j)) return round(start + (end - start + 1)/2, end, i, j, acc - 1);
    
    return acc;
}








int ceiling(int numer, int denom);
int call(void) {
    usi T; // test cases
    usi N; // call durations
    usi duration;

    scanf("%hu", &T);

    for (int i = 1; i <= T; i++) {
        int milesum = 0;
        int juicesum = 0;
        scanf("%hu", &N);

        while (N--) {
            scanf("%hu", &duration);

            milesum += ceiling(duration + 1, 30) * 10;
            juicesum += ceiling(duration + 1, 60) * 15;
        }
        if (milesum > juicesum) printf("Case %d: Juice %d\n", i, juicesum);
        else if (milesum < juicesum) printf("Case %d: Mile %d\n", i, milesum);
        else printf("Case %d: Mile Juice %d\n", i, milesum);
    }
}

// given a fraction, return the ceiling
int ceiling(int numer, int denom) {
    int res = numer/denom;
    if (numer % denom) res += 1;

    return res;
}





/*Bender
We initially have a wire (L, 0, 0), then we go back and bend in some direction.
return the direction the wire is pointing (initally is pointing to +x) 
*/
bool changesign(char cur, char sign, char dir);
int Bnder(void) {
    int L;
    char *command = (char *) malloc(sizeof(char) * 3);

    while (scanf("%d", &L)) {
        if (!L) break;

        int sign = 1; // 1 for +, -1 for -
        char cur = 'x';

        while (L-- != 1) {
            scanf("%s", command);

            if (command[0] == 'N') continue;

            if (changesign(cur, command[0], command[1])) sign = -sign;

            if (cur == 'x') cur = command[1];
            else if ((cur == 'z' && command[1] == 'z') || 
                     (cur == 'y' && command[1] == 'y')) cur = 'x';
        }
        printf("%c%c\n", sign == 1 ? '+':'-', cur);
    }
}

bool changesign(char cur, char sign, char dir) {
    if ((cur == 'x' && sign == '-') ||
        (cur == 'y' && sign == '+' && dir == 'y') ||
        (cur == 'z' && sign == '+' && dir == 'z')) return true;
    
    return false;
}


int wrong(void) {
    int L;
    char *command = (char *) malloc(sizeof(char) * 3);

    while (scanf("%d", &L)) {
        if (!L) break;

        int rotation = 0;     // the rotation. The angle is given by rotation * pi/2
        char direction = 0;    // 0 for no direction, 1 for starting with z and 2 for starting with y


        while (L-- != 1) {
            scanf("%s", command);
            // when rotation is 0, there's no direction
            if (!rotation || command[1] == direction) {
                direction = command[1];

                if (command[0] == '+') rotation++;
                else if (command[0] == '-') rotation--;
            }
        }
        int angle = (rotation % 4 + 4) % 4;

        if (angle == 0) {
            printf("+x\n");
        } else if (angle == 1) {
            if (direction == 'z') printf("+z\n");
            else printf("+y\n");
        } else if (angle == 2) {
            printf("-x\n");
        } else { // if (angle == 3)
            if (direction == 'z') printf("-z\n");
            else printf("-y\n");
        }
    }
}













// Basic Programming 1
// 25/27?
int BasicProg(void) {
    int N;
    int t;


    scanf("%d %d", &N, &t);

    if (t == 1) {
        printf("7\n");
    } else if (t == 2) {
        int num1, num2;
        scanf("%d %d", &num1, &num2);
        if (num1 > num2) {
            printf("Bigger\n");
        } else {
            printf("%s\n", num1 == num2 ? "Equal":"Smaller");
        }
    } else if (t == 3) {
        int num[3];
        scanf("%d %d %d", &num[0], &num[1], &num[2]);
        //greater = num[2];
        int median = num[0] >= num[1] ? num[0]:num[1];
        if (num[0] >= num[1] && num[0] >= num[2]) {
            //greater = num[0];
            median = num[1] >= num[2] ? num[1]:num[2];
        }
        else if (num[1] >= num[2] && num[1] >= num[0]) {
            //greater = num[1];
            median = num[0] >= num[2] ? num[0]:num[2];
        }

        printf("%d\n", median);
    } else if (t == 4) {
        int temp;
        int sum = 0;
        while (N--) {
            scanf("%d", &temp);
            sum += temp;
        }
        printf("%d\n", sum);
    } else if (t == 5) {
        int temp;
        int sum = 0;
        while (N--) {
            scanf("%d", &temp);
            if (!(temp % 2)) sum += temp;
        }
        printf("%d\n", sum);
    } else if (t == 6) {
        int temp;
        char *word = (char *) malloc(sizeof(char) * (N + 1));
        
        for (int i = 0; i < N; i++) {
            scanf("%d", &temp);

            word[i] = 'a' + (temp % 26);
        }
        word[N] = '\0';
        printf("%s\n", word);
    } else if (t == 7) {
        int temp;
        int *arr = (int *) malloc(sizeof(int) * N);

        for (int i = 0; i < N; i++) {
            scanf("%d", &temp);

            arr[i] = temp;
        }

        int j = 0;
        for (int i = 0; i < N; i++) {
            j = arr[j];
            if (j >= N || j == N - 1) {
                break;
            }
        }
        if (j >= N) printf("Out\n");
        else if (j == N - 1) printf("Done\n");
        else printf("Cyclic\n");
    }
}