#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    struct Edge* edge;
};

struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}


int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}


void Union(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}


int compare(const void* a, const void* b) {
    struct Edge* aEdge = (struct Edge*)a;
    struct Edge* bEdge = (struct Edge*)b;
    return aEdge->weight - bEdge->weight;
}


void KruskalMST(struct Graph* graph) {
    int V = graph->V;
    struct Edge resultMST[V]; 
    int e = 0; 
    int i = 0; 

    
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compare);


    int* parent = (int*)malloc(V * sizeof(int));
    for (int v = 0; v < V; ++v)
        parent[v] = -1; 

    while (e < V - 1 && i < graph->E) {
    
        struct Edge nextEdge = graph->edge[i++];

        int x = find(parent, nextEdge.src);
        int y = find(parent, nextEdge.dest);

        if (x != y) {
            resultMST[e++] = nextEdge;
            Union(parent, x, y);
        }
    }
    printf("Edges in the constructed MST:\n");
    for (i = 0; i < e; ++i)
        printf("(%d, %d) -> %d\n", resultMST[i].src, resultMST[i].dest, resultMST[i].weight);

    free(parent);
}

int main() {
    int V = 4; 
    int E = 5; 

    struct Graph* graph = createGraph(V, E);

    
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;
    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;
    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;

    KruskalMST(graph);

    return 0;
}
