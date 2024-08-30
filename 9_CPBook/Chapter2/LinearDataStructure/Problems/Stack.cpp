#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <iostream>
#include <vector>

using namespace std;

/*
wash plates the same order they come

only two piles of plates in table
not necessary to make the min number of moves?
*/
int main(void) {
    int N;
    bool firstRun = true;
    while (cin >> N && N) {
        if (!firstRun) printf("\n");

        int pile1;   // take
        int pile2;   // drop
        pile1 = 0;
        pile2 = 0;

        string action;
        int plates;
        while (N--) {
            cin >> action >> plates;

            if (action == "DROP") {
                // always drop in pile 2, move all to pile1 and take from pile1
                // store it
                pile2 += plates;
                printf("DROP 2 %d\n", plates);
            } else {
                // if pile1 is empty move every plate from pile2 to pile1
                if (pile1 == 0) {
                    printf("MOVE 2->1 %d\n", pile2);
                    pile1 = pile2;
                    pile2 = 0;
                }

                // if pile1 is not empty take from that,
                // move everything if necessary
                // take
                if (pile1 < plates) {
                    printf("TAKE 1 %d\n", pile1);
                    plates -= pile1;
                    pile1 = 0;
                    printf("MOVE 2->1 %d\n", pile2);
                    pile1 = pile2;
                    pile2 = 0;
                    printf("TAKE 1 %d\n", plates);
                    pile1 -= plates;
                } else {
                    // just take the plates, not necessary to move
                    printf("TAKE 1 %d\n", plates);
                    pile1 -= plates;
                }
            }
        }
        firstRun = false;
    }
}



/*
Container -> ship

loading time increases when containers are not on the top of stacks

stacks of containers
minimize stacks needed

order ship and arrive


*/
int containers(void) {
    string containers;

    int cases = 1;

    while ((cin >> containers) && containers[0] != 'e') {
        vector<stack<char>> stacks;

        for (int i = 0; containers[i]; i++) {
            int pos = -1;       // initially no position

            for (int k = 0; k < stacks.size(); k++) {
                // try to find the minimum top container that we can put the actual container
                if (stacks[k].top() >= containers[i]) {
                    if (pos == -1) {
                        pos = k;
                    } else if (stacks[pos].top() > stacks[k].top()) {
                        pos = k;
                    }
                }
            }

            if (pos == -1) {
                // stack not found
                stack<char> newStack;
                newStack.push(containers[i]);
                stacks.push_back(newStack);
            } else {
                stacks[pos].push(containers[i]);
            }

        }

        printf("Case %d: %d\n", cases++, stacks.size());
    }
}




int fails(void) {
    string containers;

    stack<char> stacks[26];   // total of 26 stacks

    int cases = 1;

    while ((cin >> containers) && containers != "end") {

        for (int i = 0; containers[i]; i++) {
            // try to find a stack that is possible to put the container
            // the earlier the better
            // if it finds, then stack there.
            // if it finds a container that has lower prio just stack above
            // but if it finds a container that has greater prio, go back and see if it can stack
            // in place of this container
            // else just place the container in letter
            bool found = false;
            for (int j = containers[i] - 'A'; j < 26; j++) {

                if (!stacks[j].empty()) {
                    // check the priority and do the thing
                    if (stacks[j].top() >= containers[i]) {
                        // the container has greater prio
                        // so just stack
                        stacks[j].push(containers[i]);
                    } else {
                        // lower priority
                        // create another in place of containers[j]
                        stacks[containers[i] - 'A'].push(containers[i]);
                        // unstack and put there
                        while (stacks[containers[i] - 'A'].top() >= stacks[j].top()) {
                            stacks[containers[i] - 'A'].push(stacks[j].top());
                            stacks[j].pop();
                        }
                    }
                    found = true;
                }
            }
            if (found) {
                // create another stack in place of containers[i]
                stacks[containers[i] - 'A'].push(containers[i]);
            }
        }

        printf("Case %d: %d");
    }
}







































/*
Rails

marshal coaches continuing in direction B

very hard to understand

we have ordered numbers 1, ..., N
we can get ordered subsets and put the last number out
so we make the sequence we want

we have a list 1-N
we add the first n numbers to a stack that can remove anytime and exclude the n numbers of this list
we want to make a sequence by adding to the stack and removing

*/
stack <int> addCoachs(stack <int> simulation, int coach, int maxcoach) {
    for (int i = maxcoach; i <= coach; i++) {
        simulation.push(i);
    }
    return simulation;
}


int rails(void) {
    int totalcoaches;

    while ((scanf("%d", &totalcoaches) != EOF) && totalcoaches) {

        int coach;
        while ((scanf("%d", &coach) != EOF) && coach) {
            int maxcoach = coach;
            stack <int> simulation;
            bool isPossible = true;

            simulation = addCoachs(simulation, coach - 1, 1);

            for (int i = 1; i < totalcoaches; i++) {
                scanf("%d", &coach);

                if (!isPossible) continue;

                if (coach > maxcoach) {
                    simulation = addCoachs(simulation, coach - 1, maxcoach + 1);
                    maxcoach = coach;
                } else if (!simulation.empty() && simulation.top() == coach) {
                    simulation.pop();
                } else {
                    isPossible = false;
                }
            }
            if (simulation.empty() && isPossible) printf("Yes\n");
            else printf("No\n");
        }
        printf("\n");
    }
}


















// question 1
int card(void) {
    int n;
    int rst = 0;
    int card1, card2;

    stack <int> cards;

    scanf("%d", &n);

    while(n--) {
        scanf("%d", &card1);
        if (!cards.empty()) {
            card2 = cards.top();

            if ((card1 + card2) % 2 == 0) {
                cards.pop();
            } else {
                cards.push(card1);
            }
        } else {
            cards.push(card1);
        }
    }
    printf("%d\n", cards.size());
    return 0;
}