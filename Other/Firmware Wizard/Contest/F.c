#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int val;
    struct Node *next;
    struct Node *back;
};

typedef struct Node NodeImpl;

struct List {
    NodeImpl *head;
    NodeImpl *tail;
    bool isEmpty;
};

typedef struct List ListImpl;

ListImpl* createList() {
    ListImpl *newList = (ListImpl*)malloc(sizeof(ListImpl));
    newList->head = NULL;
    newList->tail = NULL;
    newList->isEmpty = true;
    return newList;
}

void insertList(ListImpl *list, int val) {
    NodeImpl *newNode = (NodeImpl *)malloc(sizeof(NodeImpl));
    newNode->val = val;
    newNode->next = NULL;

    if (list->isEmpty) {
        list->head = newNode;
        list->tail = newNode;
        list->isEmpty = false;
        newNode->back = NULL;
    } else {
        newNode->back = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

bool deleteHeadList(ListImpl *list) {
    if (list->isEmpty) {
        return false;
    } else {
        if (list->head == list->tail) {
            list->head = NULL;
            list->tail = NULL;
            list->isEmpty = true;
        } else {
            list->head = list->head->next;
        }
        return true;
    }
}

bool deleteTailList(ListImpl *list) {
    if (list->isEmpty) {
        return false;
    } else {
        if (list->head == list->tail) {
            list->head = NULL;
            list->tail = NULL;
            list->isEmpty = true;
        } else {
            list->tail = list->tail->back;
            list->tail->next = NULL;
        }
        return true;
    }
}

int max(int a, int b) {
    return (a < b ? b : a);
}




int main() {
    int n;
    scanf("%d", &n);

    ListImpl *stack = createList();
    int ram[101] = {0};

    char *command = (char *)malloc(sizeof(char) * 30);
    for (int i = 0; i < n; i++) {
        scanf("%s", command);

        if (command[0] == 'p' && command[1] == 'u') {
            int val;
            if (command[5] == 'R') {
                int pos = atoi(command + 6);
                val = ram[pos];
            } else {
                val = atoi(command + 5);
            }
            insertList(stack, val);
        } else if (command[0] == 'p' && command[1] == 'o') {
            int pos = atoi(command + 5);
            ram[pos] = stack->tail->val;

            deleteTailList(stack);

        } else if (command[0] == 'p') {
            printf("%d\n", stack->tail->val);
            deleteTailList(stack);

        } else {
            int val1 = stack->tail->val;
            deleteTailList(stack);
            int val2 = stack->tail->val;
            deleteTailList(stack);

            if (command[0] == 'a') {
                insertList(stack, val1 + val2);

            } else if (command[0] == 'm') {
                insertList(stack, val1 * val2);

            } else if (command[0] == 'd') {
                insertList(stack, val2 / val1);

            } else if (command[0] == 's') {
                insertList(stack, val2 - val1);
            }
        }

    }

    return 0;
}