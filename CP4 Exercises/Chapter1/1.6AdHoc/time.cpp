#include <stdio.h>
#include <stdlib.h>

/* Forgot that the minutes also influences in the hour hand 
angles between hour hand and minute hand less than 180
hours * 30
minutes * 6
*/
int clockhands(void) {
    int hours;
    int minutes;

    while (scanf("%d:%d", &hours, &minutes) && (hours || minutes)) {
        double anglehour = ((hours + minutes / 60.0) * 30);
        int anglemin  = (minutes * 6);
        double anglebetween = anglehour - anglemin;

        if (anglebetween < 0) anglebetween *= -1;
        if (anglebetween > 180) anglebetween = 360 - anglebetween;

        printf("%.3lf\n", anglebetween);
    }
}










int marswindow(void) {
    int months;

    scanf("%d", &months);
    months -= 2018;
    months = (months ? (months * 12 - 3) : (0)); // months till the searched year
    months = months % 26; // months left to get in the year

    if (26 - months <= 12 || !months) printf("yes\n");
    else printf("no\n");
}