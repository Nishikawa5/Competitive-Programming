#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <string>
#include <list>
#include <climits>
#include <deque>

using namespace std;

/*
Reverse and drop

R reverses
D drops first element and returns rest or gives error if list is empty

return the list or error

*/
int main(void) {
    int cases;

    scanf("%d", &cases);

    while (cases--) {
        int leng;
        string command;
        cin >> command;
        scanf("%d", &leng);
        getchar();  // erase '\n'
        getchar();  // erase '['

        int temp;
        deque<int> arr;

        // format to put in a deque
        while (leng--) {
            scanf("%d", &temp);
            arr.push_back(temp);
            getchar(); // erase next thing
        }
        getchar();  // erase '/n'

        int i = 0;              // iterates through the string
        bool direction = 1;     // goes from right to left (1) or left to right (0)
        bool error = false;
        while (command[i] != '\0') {
            if (command[i] == 'R') {
                direction = !direction;
            } else {
                if (arr.empty()) {
                    printf("error\n");
                    error = true;
                    break;
                }
                if (direction) {
                    arr.pop_front();
                } else {
                    arr.pop_back();
                }
            }
            i++;
        }

        if (!error) {
            if (arr.empty()) {
                printf("[]\n");
            } else {
                if (direction) {
                    printf("[%d", arr.front());
                    arr.pop_front();

                    while (!arr.empty()) {
                        printf(",%d", arr.front());
                        arr.pop_front();
                    }

                    printf("]\n");
                } else {
                    printf("[%d", arr.back());
                    arr.pop_back();

                    while (!arr.empty()) {
                        printf(",%d", arr.back());
                        arr.pop_back();
                    }

                    printf("]\n");                
                }
            }
        }
    }
}




























int gcd(int a, int b) {
    if (a % b == 0) return b;
    else return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int extratired(void) {
    int numstudents;
    int studentstatus[10];           // time relative to the start
    int awakentime[10];
    int sleepingtime[10];
    int testcase = 1;

    while ((scanf("%d", &numstudents) != EOF) && numstudents) {
        int maxtime = 1;

        for (int i = 0; i < numstudents; i++) {
            scanf("%d %d %d", &awakentime[i], &sleepingtime[i], &studentstatus[i]);

            // we calculate the lcm to get the maximum time allowed
            // by lcm, we have every combination of intervals, after lcm it will repeat
            maxtime = lcm(maxtime, awakentime[i] + sleepingtime[i]);
        }

        bool found;
        int sol = -1;
        for (int i = 0; i < maxtime; i++) {
            int count = 0;
            found = false;
            for (int k = 0; k < numstudents; k++) {
                if (studentstatus[k] <= awakentime[k]) {
                    count++;
                }
            }
            if (count == numstudents) {
                sol = i + 1;                
                break;
            }

            for (int k = 0; k < numstudents; k++) {
                if (studentstatus[k] == awakentime[k] + sleepingtime[k] ||
                    (studentstatus[k] == awakentime[k] && numstudents <= count * 2)) {
                    
                    studentstatus[k] = 1;
                } else {
                    studentstatus[k]++;
                }
            }
        }
        
        printf("Case %d: %d\n", testcase++, sol);
    }
}





















// fail
/*
check if the student k is awaken at time t
*/
bool isAwaken(int awakentime[10], int sleepingtime[10], int k, int t) {
    t %= awakentime[k] + sleepingtime[k];
    return t < awakentime[k];
}

int nextAwaken(int awakentime[10], int sleepingtime[10], int k, int t) {
    t %= awakentime[k] + sleepingtime[k];
    int x = t - awakentime[k];
    int rst = sleepingtime[k] - x;

    return rst;
}

/*
We have intervals of a + b. We have to find a time where n / 2 people are not sleeping

*/
int failExtTired(void) {
    int numstudents;
    int start[10];           // time relative to the start
    int awakentime[10];
    int sleepingtime[10];
    int testcase = 1;

    while ((scanf("%d", &numstudents) != EOF) && numstudents) {
        int maxtime = 1;

        for (int i = 0; i < numstudents; i++) {
            scanf("%d %d %d", &awakentime[i], &sleepingtime[i], &start[i]);
            start[i]--;

            // we calculate the lcm to get the maximum time allowed
            // by lcm, we have every combination of intervals, after lcm it will repeat
            maxtime = lcm(maxtime, awakentime[i] + sleepingtime[i]);
        }

        int sol = -1;
        for (int i = 0; i <= maxtime; i++) {
            int awaken = 0;
            for (int k = 0; k < numstudents; k++) {
                if (isAwaken(awakentime, sleepingtime, k, start[k] + i)) {
                    awaken++;
                }
            }

            if (awaken == numstudents) {
                sol = i + 1;
                break;
            }
            if (awaken > numstudents / 2) {
                int lastawaken = INT_MIN;
                for (int k = 0; k < numstudents; k++) {
                    if (!isAwaken(awakentime, sleepingtime, k, start[k] + i) ) {
                        lastawaken = max(lastawaken, nextAwaken(awakentime, sleepingtime, k, start[k] + i));
                    }
                }
                sol = i + lastawaken + 1;
                break;
            }
        }
        printf("Case %d: %d\n", testcase++, sol);
    }
}















int brokenkeyboard(void) {
    char chr;
    while ((chr = getchar()) != EOF) {
        list <string> text;
        string temp = "";
        temp.push_back(chr);

        if (chr != '[' && chr != ']') {
            text.push_back(temp);
        } else {
            text.push_back("");
        }
        int lastcall = 0; // 0: HOME, 1: END

        if (chr == '\n') {
            printf("\n");
        } else {
            while ((chr = getchar()) != '\n') {
                if (chr == '[') {
                    // HOME
                    lastcall = 0;
                    text.push_front("");

                } else if (chr == ']') {
                    // END
                    lastcall = 1;
                    text.push_back("");

                } else {
                    if (!lastcall) {
                        text.front().push_back(chr);
                    } else {
                        text.back().push_back(chr);
                    }
                }
            }
            for (list<string>::iterator it = text.begin(); it != text.end(); it++) {
                cout << *it;
            }
            cout << endl;
        }

    }
}

























/*
Easy to understand and medium to implement but it doesn't specify corner cases like for N = 1 (spent much time)
could make it store the indexes in a vector and after the last input we print the strings of corresponding indexes
recursively
*/
struct Node {
    struct Node *next;
    string str;
};

struct List {
    struct Node *head;
    struct Node *end;
};

typedef struct Node myNode;
typedef struct List myList;

myList *createList(string str) {
    myList *temp = new myList();
    myNode *node = new myNode(); // don't use malloc when we have cpp structure in struct

    node->str = str;
    node->next = NULL;

    temp->end = node;
    temp->head = node;

    return temp;
}

void appendList(myList *l1, myList *l2) {
    l1->end->next = l2->head;
    l1->end = l2->end;
}

void printList(myList *l) {
    myNode *n = l->head;
    while (n != NULL) {
        printf("%s", n->str.c_str());
        n = n->next;
    }
    printf("\n");
}

int faster(void) {
    myList **strs;
    string temp;
    int N;
    int i1 = 1;
    int i2 = 1;
    
    scanf("%d", &N);
    getchar();

    strs = (myList **) malloc(sizeof(myList *) * N);

    // store the strings in vector of lists
    for (int i = 0; i < N; i++) {
        getline(cin, temp);
        strs[i] = createList(temp);
    }
    // join the strings
    for (int i = 1; i < N; i++) {
        scanf("%d %d", &i1, &i2);
        getchar();

        appendList(strs[i1 - 1], strs[i2 - 1]);
    }
    printList(strs[i1 - 1]);
}




















/* Too slow */
int joinstringslow(void) {
    int N;
    int i1, i2;
    string str;
    vector <string> strs;

    scanf("%d", &N);
    getchar();

    for (int i = 0; i < N; i++) {
        getline(cin, str);
        strs.push_back(str);
    }

    for (int i = 1; i < N; i++) {
        scanf("%d %d", &i1, &i2);
        getchar();
        strs[i1 - 1] += strs[i2 - 1];
    }
    printf("%s\n", strs[i1 - 1].c_str());
}