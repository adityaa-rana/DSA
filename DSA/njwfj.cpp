#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

typedef struct {
    int dest;
    int weight;
} Edge;

typedef struct {
    Edge *edges;
    int size;
    int capacity;
} AdjList;

void addEdge(AdjList *graph, int u, int v, int w) {
    if (graph[u].size == graph[u].capacity) {
        graph[u].capacity = (graph[u].capacity == 0) ? 2 : graph[u].capacity * 2;
        graph[u].edges = (Edge *)realloc(graph[u].edges, graph[u].capacity * sizeof(Edge));
        if (graph[u].edges == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
    }
    graph[u].edges[graph[u].size].dest = v;
    graph[u].edges[graph[u].size].weight = w;
    graph[u].size++;
}

void dijkstra(AdjList *graph, int n, int start, int *distances) {
    int *visited = (int *)malloc(n * sizeof(int));
    if (visited == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        distances[i] = INF;
        visited[i] = 0;
    }
    distances[start] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && (u == -1 || distances[i] < distances[u])) {
                u = i;
            }
        }

        if (u == -1 || distances[u] == INF)
            break;

        visited[u] = 1;

        for (int i = 0; i < graph[u].size; i++) {
            int v = graph[u].edges[i].dest;
            int weight = graph[u].edges[i].weight;
            if (!visited[v] && distances[u] != INF && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
            }
        }
    }

    free(visited);
}

int main() {
    int n, e;
    scanf("%d %d", &n, &e);

    AdjList *graph = (AdjList *)malloc(n * sizeof(AdjList));
    if (graph == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        graph[i].edges = NULL;
        graph[i].size = 0;
        graph[i].capacity = 0;
    }

    for (int i = 0; i < e; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(graph, u, v, w);
    }

    int start;
    scanf("%d", &start);

    int *distances = (int *)malloc(n * sizeof(int));
    if (distances == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    dijkstra(graph, n, start, distances);

    int maxDistance = 0;
    int allReachable = 1;
    for (int i = 0; i < n; i++) {
        if (distances[i] == INF) {
            allReachable = 0;
            break;
        }
        if (distances[i] > maxDistance) {
            maxDistance = distances[i];
        }
    }

    if (!allReachable) {
        printf("-1\n");
    } else {
        printf("%d\n", maxDistance);
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(graph[i].edges);
    }
    free(graph);
    free(distances);

    return 0;
}