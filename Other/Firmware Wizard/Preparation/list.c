#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    void *val;
    struct Node *next;
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

void insertList(ListImpl *list, void *val) {
    NodeImpl *newNode = (NodeImpl *)malloc(sizeof(NodeImpl));
    newNode->val = val;
    newNode->next = list->head;

    list->head = newNode;

    if (list->isEmpty) {
        list->tail = newNode;
        list->isEmpty = false;
    }
}




int first_true(int lo, int hi, bool (*f)(int)) {
    hi++;

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;

        if (f(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}





int main() {

    bool f(int);
}