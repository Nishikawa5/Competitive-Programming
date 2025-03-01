#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int queries;
    char *action = (char *) malloc(sizeof(char) * 6);
    char *name;
    stack<char*> dream;

    scanf("%d", &queries);
    getchar();

    while (queries--) {
        scanf("%s", action);

        // is Sleep
        if (!strcmp(action, "Sleep")) {
            name = (char *) malloc(sizeof(char) * 16);
            scanf("%s", name);
            dream.push(name);
        } else if (!strcmp(action, "Test")) {
            if (!dream.empty()) {
                printf("%s\n", dream.top());
            } else {
                printf("Not in a dream\n");
            }
        } else {
            if (!dream.empty()) {
                dream.pop();
            }
        }
    }
}