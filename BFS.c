#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(struct Queue* q) {
    return q->rear == -1;
}

void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX_SIZE - 1)
        printf("Queue is full\n");
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(struct Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
    return item;
}

void bfs(int** graph, int* visited, int n, int start) {
    struct Queue* q = createQueue();
    visited[start] = 1;
    enqueue(q, start);

    while (!isEmpty(q)) {
        int current = dequeue(q);
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (!visited[i] && graph[current][i] == 1) {
                visited[i] = 1;
                enqueue(q, i);
            }
        }
    }
    free(q);
}

int main() {
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int** graph = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph[i] = (int*)malloc(n * sizeof(int));
    }

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int start;
    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    int* visited = (int*)calloc(n, sizeof(int));

    printf("BFS Traversal: ");
    bfs(graph, visited, n, start);

    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);
    free(visited);

    return 0;
}
