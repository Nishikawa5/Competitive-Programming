#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int max(int a, int b) {
    return (a < b ? b : a);
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

bool dfs(int vertice, int curr_it, int from, int to, bool *foundEnd, int *visited, int *recstack, ListImpl *graph[]) {


    if (visited[vertice] != curr_it) {

        visited[vertice] = curr_it;
        recstack[vertice] = curr_it;

        for (NodeImpl *curr_vertice = graph[vertice]->head; curr_vertice != NULL; curr_vertice = curr_vertice->next) {

            if (visited[curr_vertice->val] != curr_it &&
                dfs(curr_vertice->val, curr_it, from, to, foundEnd, visited, recstack, graph)) {
                return true;
            } else if (recstack[curr_vertice->val] == curr_it) {
                return true;
            }
        }
    }

    recstack[vertice] = false;
    return false;
}

int main() {
    int in, circuits, out;
    scanf("%d %d %d", &in, &circuits, &out);

    int total = in + circuits + out;
    ListImpl *graph[total];
    
    for (int i = 0; i < total; i++) {
        graph[i] = createList();
    }

    for (int i = 0; i < circuits; i++) {
        int connections;
        scanf("%d", &connections);
        for (int j = 0; j < connections; j++) {
            int val;
            scanf("%d", &val);
            val--;
            insertList(graph[in + i], val);
        }
    }

    for (int i = 0; i < out; i++) {
        int connection;
        scanf("%d", &connection);
        connection--;
        insertList(graph[in + circuits + i], connection);
    }

    int visited[total];
    int recstack[total];
    int visited_circuit[total];
    memset(visited_circuit, 0, sizeof(visited_circuit));
    memset(visited, 0, sizeof(visited));
    memset(recstack, 0, sizeof(recstack));

    bool *foundEnd = (bool*) malloc(sizeof(bool));
    bool isOk = true;
    for (int i = in + circuits; i < total && isOk; i++) {
        bool isLoop = false;
        isLoop = dfs(i, 1, in + circuits, total - 1, foundEnd, visited, recstack, graph);

        // bad code
        *foundEnd = false;
        for (int j = in + circuits; j < total; j++) {
            if (visited[j] == i + 1) {
                visited_circuit[j] = true;
                *foundEnd = true;
            }
        }

        isOk = *foundEnd && !isLoop;
    }

    for (int i = in + circuits; i < total; i++) {
        if (!visited_circuit[i]) {
            isOk = false;
            break;
        }
    }

    if (isOk) {
        printf("o.o\n");
    } else {
        printf("u.u\n");
    }

    return 0;
}

/*
3 3 3
3 1 2 3
3 1 2 6
2 3 4
1 5 6

3 3 2
3 1 2 3
1 6
1 5
4 6

3 3 2
3 1 2 3
3 1 2 6
2 3 4
1 6
*/