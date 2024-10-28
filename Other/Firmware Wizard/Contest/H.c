#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

int size = 0;
void heapifyPrioQueue(int array[], int size, int i) {
    if (size != 1) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < size && array[l] > array[largest]) {
            largest = l;
        }
        if (r < size && array[r] > array[largest]) {
            largest = r;
        }

        if (largest != i) {
            swap(&array[i], &array[largest]);
            heapifyPrioQueue(array, size, largest);
        }
    }
}

void insertPrioQueue(int array[], int val) {
    if (size == 0) {
        array[0] = val;
        size += 1;
    } else {
        array[size] = val;
        size += 1;
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapifyPrioQueue(array, size, i);
        }
    }
}

void deleteRootPrioQueue(int array[], int num) {
    int i;
    for (i = 0; i < size; i++) {
        if (num == array[i])
        break;
    }

    swap(&array[i], &array[size - 1]);
    size -= 1;
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapifyPrioQueue(array, size, i);
    }
}

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

int main() {

    int n;
    while (scanf("%d", &n) != EOF) {
        ListImpl *stack = createList();
        ListImpl *queue = createList();
        int prioQueue[n];
        size = 0;

        bool isStack = true;
        bool isQueue = true;
        bool isPrioQueue = true;

        for (int i = 0; i < n; i++) {
            int command;
            int val;
            scanf("%d %d", &command, &val);
            
            // test stack
            if (command == 1) {
                // insert
                insertList(stack, val);
                insertList(queue, val);
                insertPrioQueue(prioQueue, val);
            } else {

                // test stack
                if (isStack && !stack->isEmpty && stack->tail->val == val) {
                    deleteTailList(stack);
                } else {
                    isStack = false;
                }

                // test queue
                if (isQueue && !queue->isEmpty && queue->head->val == val) {
                    deleteHeadList(queue);
                } else {
                    isQueue = false;
                }

                if (isPrioQueue && size && prioQueue[0] == val) {
                    deleteRootPrioQueue(prioQueue, val);
                } else {
                    isPrioQueue = false;
                }
            }
        }

        if (isStack + isQueue + isPrioQueue > 1) {
            printf("not sure\n");
        } else if (isStack + isQueue + isPrioQueue == 0) {
            printf("impossible\n");
        } else if (isStack) {
            printf("stack\n");
        } else if (isQueue) {
            printf("queue\n");
        } else if (isPrioQueue) {
            printf("priority queue\n");
        }

    }
}