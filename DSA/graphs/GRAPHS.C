#include <stdio.h>
#include <stdlib.h>

#define MAX_USERS 1000  // Maximum number of users

// Graph structure
typedef struct {
    int adj[MAX_USERS][MAX_USERS];  // Adjacency matrix
    int visited[MAX_USERS];         // Visited status for each node
    int n, m;                       // Number of vertices (users) and edges (connections)
} Graph;

// Function to initialize the graph
void initGraph(Graph* graph, int n, int m) {
    graph->n = n;
    graph->m = m;

    // Initialize adjacency matrix and visited array
    for (int i = 0; i < n; i++) {
        graph->visited[i] = 0;
        for (int j = 0; j < n; j++) {
            graph->adj[i][j] = 0;
        }
    }
}

// Function to add a directed edge from u to v
void addEdge(Graph* graph, int u, int v) {
    graph->adj[u][v] = 1;
}

// DFS function
void DFS(Graph* graph, int vertex) {
    // Mark the current vertex as visited
    graph->visited[vertex] = 1;
    
    // Print the vertex
    printf("%d ", vertex);
    
    // Recur for all the adjacent vertices
    for (int i = 0; i < graph->n; i++) {
        if (graph->adj[vertex][i] == 1 && graph->visited[i] == 0) {
            DFS(graph, i);
        }
    }
}

int main() {
    Graph graph;
    int n, m, s;
    
    // Read number of vertices and edges
    scanf("%d %d", &n, &m);
    
    // Initialize the graph
    initGraph(&graph, n, m);
    
    // Read the edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(&graph, u, v);
    }
    
    // Read the starting vertex
    scanf("%d", &s);
    
    // Perform DFS starting from the given vertex
    DFS(&graph, s);
    
    printf("\n");
    
    return 0;
}



#include<stdio.h>
#include<stdlib.h>
#define max 100

typedef struct graph{
    int adj[max][max];
    int visited[max];
    int n,m;
}graph;

void init(graph* g,int n,int m){
    g->n=n;
    g->m=m;
    for(int i=0;i<n;i++){
        g->visited[i]=0;
        for(int j=0;j<n;j++){
            g->adj[i][j]=0;
        }
    }
}

void addedge(graph* g,int u,int v){
    g->adj[u][v]=1;
}

int bfslevel(graph* g,int start,int target){
    int ans;
    int count=1;
    int queue[max];
    int front=0,rear=0;
    queue[rear++]=start;
    g->visited[start]=1;
    while(front<rear){
        int node=queue[front++];
        for(int i=0;i<g->n;i++){
            if(g->adj[node][i]==1 && node!=i && g->visited[i]==0){
                queue[rear++]=i;
                g->visited[i]=1;
            }
        }
    }
}


void dfscount(graph* g,int target,int node,int* count){
    g->visited[node]=1;
    for(auto it:g->adj[node]){
        
    }
}


#include <stdio.h>
#include <limits.h>

#define V 5  // Number of vertices in the graph

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, minIndex;
    
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }
    
    return minIndex;
}

// Function to implement Dijkstra's algorithm
void dijkstra(int graph[V][V], int start) {
    int dist[V];  // Array to store the shortest distance from the start vertex
    int visited[V];  // Array to track visited vertices

    // Initialize all distances as infinite and visited[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    // Distance to the source vertex is 0
    dist[start] = 0;

    // Perform Dijkstra's algorithm
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet visited
        int u = minDistance(dist, visited);
        
        // Mark the selected vertex as visited
        visited[u] = 1;

        // Update dist[] for the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the shortest distances from the start vertex
    printf("Vertex\t Distance from Source (%d)\n", start);
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) {
            printf("%d\t INFINITY\n", i);
        } else {
            printf("%d\t %d\n", i, dist[i]);
        }
    }
}

int main() {
    // Example adjacency matrix representation of the graph
    int graph[V][V] = {
        {0, 9, 0, 0, 0},
        {9, 0, 6, 0, 0},
        {0, 6, 0, 3, 0},
        {0, 0, 3, 0, 2},
        {0, 0, 0, 2, 0}
    };

    int start = 0;  // Starting vertex (0-indexed)

    // Call Dijkstra's algorithm to find the shortest paths
    dijkstra(graph, start);

    return 0;
}
