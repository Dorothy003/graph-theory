#include <stdio.h>
#include <stdlib.h>

void createGraph(int v) {

    int** graph = (int**)malloc(v * sizeof(int*));
    for (int i = 0; i < v; i++)
        graph[i] = (int*)malloc(v * sizeof(int));

    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
            graph[i][j] = 0;

    for (int i = 0; i < v; i++)
        for (int j = i + 1; j < v; j++)
            graph[i][j] = graph[j][i] = 1;

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }
}

int main() {
    int v;
    printf("Enter the number of vertices: ");
    scanf("%d", &v);

    createGraph(v);

    return 0;
}