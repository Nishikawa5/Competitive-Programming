#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Only programming
n days
P points
f points for each practice each week any day 1 to n 8 to n,...
l points for each lesson every day 1 to n

study or rest

study - lesson and complete no more than 2 tasks

max number of rest

goes from max number of points to least and compare with minpoints
*/
unsigned long long ceil(unsigned long long a, unsigned long long b) {
    unsigned long long div = a / b;
    return div + ((div * b) < a);
}

int main(void) {
    int tc;

    unsigned long long days;
    unsigned long long minpoints;
    unsigned long long pointlesson;
    unsigned long long pointtask;
    unsigned long long needed;
    unsigned long long daysrest;

    scanf("%d", &tc);

    while (tc--) {
        scanf("%llu %llu %llu %llu", &days, &minpoints, &pointlesson, &pointtask);

        unsigned long long currpoints = 0;
        unsigned long long tasks = ceil(days, 7);
        unsigned long long doubletasks = tasks / 2;
        unsigned long long solotasks = tasks % 2;

        daysrest = days;

        needed = ceil(minpoints, (unsigned long long) (pointtask * 2 + pointlesson));
        if (doubletasks >= needed) {
            daysrest -= needed;
        } else {
            daysrest -= doubletasks;
            minpoints -= (pointtask * 2 + pointlesson) * doubletasks;

            needed = ceil(minpoints, (unsigned long long) (pointtask * 1 + pointlesson));
            if (solotasks >= needed) {
                daysrest -= needed;
            } else {
                daysrest -= solotasks;
                minpoints -= (pointtask * 1 + pointlesson) * solotasks;

                needed = ceil(minpoints, (unsigned long long) pointlesson);
                daysrest -= needed;
            }
        }
        printf("%llu\n", daysrest);
    }
}