#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define true 1
#define false 0
#define bool int
#define usi unsigned short int


int main(void) {
    int T;
    int n;

    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);
        int candidates = n;

        int temp;
        int max;
        int sum;
        int mark;
        int repeat = false; // true if it repeats, false if not

        scanf("%d", &max);

        sum = max;
        mark = 1;
        n--;
        while (n--) {
            scanf("%d", &temp);

            if (max < temp) {
                max = temp;
                mark = candidates - n;
                repeat = false; // initially doesn't repeat
            }
            else if (max == temp) {
                repeat = true;
            }

            sum += temp;
        }
        if (repeat) printf("no winner\n");
        else if (2 * max > sum) printf("majority winner %d\n", mark);
        else printf("minority winner %d\n", mark);
    }
}







int isin(char* item, char* str);

int peasoup(void) {
    int n; // number of restaurants
    int k; // number of menus items
    char *rname; // restaurant name
    char *item;  // item name
    char *firstgo = NULL; // final restaurant
    int ngood = 0; // number of good restaurants

    item = (char *) malloc(sizeof(char) * 101);

    scanf("%d", &n);

    while (n--) {
        scanf("%d", &k);
        int pea, pan;
        pea = 0;
        pan = 0;
        
        rname = (char *) malloc(sizeof(char) * 101);
        scanf(" %[^\n]s", rname);

        while (k--) {
            scanf(" %[^\n]s", item);

            if (isin(item, "pea soup")) {
                pea = 1;
            }
            if (isin(item, "pancakes")) {
                pan = 1;
            }
        }
        if (pan && pea && !firstgo) {
            firstgo = rname;
        } else free(rname);

        if (pan && pea) ngood++;
    }

    printf("%s\n", !firstgo ? "Anywhere is fine I guess" : firstgo);
}

int isin(char* item, char* str) {
    int i = 0;
    while (item[i] == str[i] && (str[i] != '\0' && item[i] != '\0')) {
        i++;
    }

    return str[i] == item[i];
}










struct list{
    int n;
    struct list *back;
};

typedef struct list ll;


int rain(void) {
    int N;
    char *struc = (char *) malloc(sizeof(char) * 10001);
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        int open = 0;
        int wid = 0;
        int sum = 0;
        ll *opens = (ll *) malloc(sizeof(ll));
        opens->back = NULL; // dummy

        int k = 0;
        scanf(" %s", struc);
        while (struc[k] != '\0') {
            if (struc[k] == '\\') {
                // add a new node
                ll *node = (ll *) malloc(sizeof(ll));
                node->n = k;
                node->back = opens;

                opens = node;
            } else if (struc[k] == '/') {
                if (opens->back) {
                    sum += k - opens->n;
                    opens = opens->back;
                }
            }

            k++;
        }

        printf("%d\n", sum);
    }
}





int scupture(void) {
    int height;
    int length;

    while (true) {
        scanf("%d %d", &height, &length);
        if (height == 0) break;

        int cur;
        int last = height;
        int sum = 0;
        int i;

        for (i = 0; i < length; i++) {
            scanf("%d", &cur);

            if (cur < last) {
                sum += last - cur;
            }

            last = cur;
        }

        printf("%d\n", sum);
    }
}










int findsmallestscanf(int *toppingprices);

int bubbletea(void) {
    int N;
    int M;
    int **prices = malloc(sizeof(int*) * 2); // 0 are the bubbletea price and 1 are the toppings prices
    int money; // the money pvh has

    scanf("%d", &N);
    prices[0] = malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &prices[0][i]);
    }

    scanf("%d", &M);
    prices[1] = malloc(sizeof(int) * M);
    for (int j = 0; j < M; j++) {
        scanf("%d", &prices[1][j]);
    }

    int cheap = prices[0][0] + findsmallestscanf(prices[1]);
    for (int i = 1; i < N; i++) {
        int temp = prices[0][i] + findsmallestscanf(prices[1]);
        if (temp < cheap) cheap = temp;
    }

    scanf("%d", &money);
    printf("%d\n", money / cheap >= 1 ? money / cheap - 1 : 0);
}

int findsmallestscanf(int *toppingprices) {
    int N;
    int temp;
    int smallest;
    scanf("%d", &N);        // quantity of toppings
    scanf("%d", &temp);     // first num
    smallest = toppingprices[temp - 1];

    for (int i = 1; i < N; i++) {
        scanf("%d", &temp);
        temp = toppingprices[temp - 1];

        if (temp < smallest) smallest = temp;
    }

    return smallest;
}




// use %g to don't print the zero decimals
int average(void) {
    int N;
    int sum = 0;
    int times = 0;
    int point;

    scanf("%d", &N);
        
    for (int i = 0; i < N; i++) {
        scanf("%d", &point);
        
        if (point >= 0) {
            sum += point;
            times++;
        }
    }
    
    printf("%.16g\n", (double) (sum / (double) times));
}

// character recognition
char checknum(char *line);

int cgheck(void) {
    int N;    
    scanf("%d", &N);

    // get to desired line
    char *line = malloc(sizeof(char) * (4 * N + 1));
    for (int i = 0; i < 4; i++) {
        scanf("%s", line);
    }

    // create the answer vector
    char *ans = malloc(sizeof(char) * (N + 1));
    int i;
    for (i = 0; i < N; i++) {
        ans[i] = checknum(line + i*4);
    }
    ans[i] = '\0';
    printf("%s\n", ans);
}

char checknum(char *line) {
    if (line[1] == '*') return '1';
    if (line[0] == '*') return '2';
    if (line[2] == '*') return '3';

    return '\0';
}



int score(void) {
    int T;
    char *str;

    str = malloc(sizeof(char) * 81); // max 80 characters

    scanf("%d", &T);

    while (T--) {
        int score = 0;
        int streak = 1;
        int i = 0;
        scanf("%s", str);

        while (str[i] != '\0') {
            if (str[i] == 'O') {
                score += streak;
                streak++;
            } else if (str[i] == 'X') {
                streak = 1;
            }
            i++;
        }

        printf("%d\n", score);
    }
}




int lineup(void) {
    int n;
    int *line;

    scanf("%d", &n);
    line = malloc(n * sizeof(int));

    for (int i = 2, bet; i <= n; i++) {
        scanf("%d", &bet);
        line[bet + 1] = i;
    }
    line[0] = 1;

    for (int i = 0; i < n - 1; i++) {
        printf("%d ", line[i]);
    }
    printf("%d\n", line[n - 1]);
}




// price(k)=p⋅(sin(a⋅k+b)+cos(c⋅k+d)+2)
int asd(void) {
    int p, a, b, c, d, n;

    scanf("%d %d %d %d %d %d", &p, &a, &b, &c, &d, &n);
    double maxp = 0;
    double maxdecl = 0;

    for (int k = 1; k <= n; k++) {
        double currprice = p * (sin(a*k + b) + cos(c*k + d) + 2);
        if (maxp < currprice) { maxp = currprice; }

        if (maxp - currprice > maxdecl) { maxdecl = maxp - currprice; }
    }

    printf("%.7llf", maxdecl);
}








int sumdigRec(long long int n);
int sumdigs(long long int n);

int UVa11332(void) {
    long long int n;

    scanf("%lld", &n);

    while(n) {
        printf("%d\n", sumdigRec(n));

        scanf("%lld", &n);
    }
}

int sumdigRec(long long int n) {
    n = sumdigs(n);
    if (n < 10) return n;

    return sumdigRec(n);
}

int sumdigs(long long int n) {
    int sum;
    for (sum = 0; n != 0; sum += n % 10, n /= 10);

    return sum;
}


int present(void) {
    int N, s = 0;
    int W, H, L;

    scanf("%d", &N);

    while (s++ < N) {
        scanf("%d %d %d", &L, &W, &H);

        printf("Case %d: %s\n", s, (L <= 20 && W <= 20 && H <= 20) ? "good" : "bad");
    }
}

int as(void) {
    int N, n;
    scanf("%d", &N);

    while (N--) {
        scanf("%d", &n);
        n = (((n * 63 + 92) * 5) - 98);
        if (n < 0) n = -n;
        printf("%d\n", (n % 100) / 10);
    }
}


int bru(void){
    int m, n;
    int N;
    scanf("%d", &N);
    while (N--) {
       scanf("%d %d", &m, &n);
       m -= 2;
       n -= 2;
       if (m < 0) m = 0;
       if (n < 0) n = 0;
       printf("%d\n", (m % 3 ? m / 3 + 1: m / 3) * (n % 3 ? n / 3 + 1 : n / 3));
    }
}





// https://vjudge.net/problem/UVA-11614
int soldierproblem(void) {
    long long int num;
    int tc;

    scanf("%d", &tc);
    // (1 + r) * r/2 = n, with r being the number of rows, so the number of row-soldiers is n
    // => r*r + r - 2*n = 0 => r = (-1 + sqrt(8*n + 1))/2 when n is not a perfect row, it's truncated
    while(tc--) {
        scanf("%lld", &num);
        printf("%lld\n", (long long int) ((sqrt((double) (8 * num + 1)) - 1)/2));
    }
}