#include <stdio.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int vertices;

int hasSelfLoop() {
    for (int i = 0; i < vertices; i++) {
        if (graph[i][i] == 1) {
            return 1; 
        }
    }
    return 0; 
}

int main() {
    vertices = 4;
    graph[0][0] = 0; graph[0][1] = 1; graph[0][2] = 0; graph[0][3] = 0;
    graph[1][0] = 1; graph[1][1] = 0; graph[1][2] = 1; graph[1][3] = 0;
    graph[2][0] = 0; graph[2][1] = 1; graph[2][2] = 0; graph[2][3] = 1;
    graph[3][0] = 0; graph[3][1] = 0; graph[3][2] = 1; graph[3][3] = 0;

    if (hasSelfLoop()) {
        printf("The graph has self-loops.\n");
    } else {
        printf("The graph does not have self-loops.\n");
    }

    return 0;
}
