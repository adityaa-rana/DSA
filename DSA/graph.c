#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int mindistance(int visited[],int distance[],int num){
    int min=INT_MAX;
    int minind=-1;
    for(int i=0;i<num;i++){
        if(!visited[i] && distance[i]<min){
            min=distance[i];
            minind=i;
        }
    }
    return minind;
}
void djikstra(int graph[][100],int source,int num){
    int distance[num];
    int visited[num];
    for(int i=0;i<num;i++){
        visited[i]=0;
        distance[i]=INT_MAX;
    }
    distance[source]=0;
    for(int i=0;i<num;i++){
        int u=mindistance(visited,distance,num);
        visited[u]=1;
        for(int j=0;j<num;j++){
            if(!visited[j] && graph[u][j]!=0 && distance[u]!=INT_MAX && distance[u]+graph[u][j]<distance[j]){
                distance[j]=distance[u]+graph[u][j];
            }
        }
    for(int i=0;i<num;i++){
        if(i!=source){
            if(distance[i]!=INT_MAX){
                printf("City %d: %d units\n",i,distance[i]);
            }
            else{
                printf("City %d: Not reachable\n",i);
            }
        }
    }
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int graph[100][100];
    for(int i=0;i<m;i++){
        
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        graph[u][v]=w;
        
    }
    int source;
    scanf("%d",&source);
    djikstra(graph,source,n);
}

int mindis(int visited[],int distance[],int num){
    int min=INT_MAX;
    int minind=-1;
    for(int i=0;i<num;i++){
        if(!visited[i] && distance[i]<min){
            min=distance[i];
            minind=i;
        }
    }
    return minind;
}

void djs(int graph[][100],int source,int des,int num){
    int visited[num];
    int distance[num];
    int prev[num];
    for(int i=0;i<num;i++){
        visited[i]=0;
        distance[i]=INT_MAX;
        prev[i]=-1;
    }
    distance[source]=0;
    for(int i=0;i<num-1;i++){
        int u=mindis(visited,distance,num);
        visited[u]=1;
        for(int j=0;j<num;j++){
            if(!visited[j] && graph[u][j]!=0 && distance[u]!=INT_MAX && distance[u]+graph[u][j]<distance[j]){
                 distance[j]=distance[u]+graph[u][j];
                prev[j]=u;
            }
        }
    }
    printf("Shortest path: %d\n",distance[des]);
    int path[num];
    int pathind=0;
    for(int i=des;i!=-1;i=prev[i]){
        path[pathind++]=i;
    }
    printf("Path: ");
    for(int i=pathind-1;i>=0;i--){
        printf("%d ",path[i]);
        if(i!=0){
            printf("-> ");
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int graph[100][100];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int edge;
            scanf("%d",&graph[i][j]);
        }
    }
    int s,d;
    scanf("%d %d",&s,&d);
    djs(graph,s,d,n);
}

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define max 100


typedef struct edge{
    int u,v,w;
}edge;

int parent[max];
int rank[max];

void init(int n){
    for(int i=0;i<n;i++){
        rank[i]=0;
        parent[i]=i;
    }
}

int find(int x){
    if(parent[x]!=x){
        parent[x]=find(parent[x]);
    }
    return parent[x];
}

void union_(int x,int y){
    int upx=find(x);
    int upy=find(y);
    if(upx!=upy){X
        if(rank[upx]>rank[upy]){
            parent[upy]=upx;
        }
        else if(rank[upy]>rank[upx]){
            parent[upx]=upy;
        }
        else{
            parent[upy]=upx;
            rank[upx]++;
        }
    }
}


int compare(const void *a,const void *b){
    edge *edgeA=(edge*)a;
    edge *edgeB=(edge*)b;
    return edgeA->w-edgeB->w;
}

void kruskal(edge edges[],int e ,int n,int budget){
    qsort(edges,e,sizeof(edge),compare);
    init(n);
    int mst=0;
    int mstedges=0;
    for(int i=0;i<e;i++){
        int u=edges[i].u;
        int v=edges[i].v;
        int w=edges[i].w;
        if(find(u)!=find(v)){
            union_(u,v);
            mst+=w;
            mstedges++;
        }
        if(mstedges==n-1){
            break;
        }
    }
    if(mstedges!=n-1){
        printf("A valid MST is not possible with given edges.");
    }
    else if(mst<=budget){
        printf("Minimum Cost Spanning Tree within the budget: %d",mst);
    }
    else{
        printf("A valid MST within the budget is not possible.");
    }
}


int main(){
    int n,e,b;
    scanf("%d %d %d",&n,&e,&b);
    edge edges[max];
    for(int i=0;i<e;i++){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        edges[i].u=u;
        edges[i].v=v;
        edges[i].w=w;
    }
    kruskal(edges,e,n,b);
    return 0;
}   


#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int mindis(int visited[],int distance[],int num){
    int min=INT_MAX;
    int minind=-1;
    for(int i=0;i<num;i++){
        if(!visited[i] && distance[i]<min){
            min=distance[i];
            minind=i;
        }
    }
    return minind;
}

void prims(int graph[][10],int num){
    int visited[num];
    int parent[num];
    int distance[num];
    for(int i=0;i<num;i++){
        visited[i]=0;
        distance[i]=INT_MAX;
    }
    distance[0]=0;
    parent[0]=-1;
    int edges=0;
    while(edges<num-1){
        int u=mindis(visited,distance,num);
        visited[u]=1;
        for(int i=0;i<num;i++){
            if(!visited[i] && graph[u][i]!=0 && graph[u][i]<distance[i]){
                distance[i]=graph[u][i];
                parent[i]=u;
            }
        }
        edges++;
    }
    int total=0;
    printf("Location\tDistance\n");
    for(int i=1;i<num;i++){
        printf("%d -> %d\t\t\t%d km\n",parent[i],i,graph[i][parent[i]]);
        total+=graph[i][parent[i]];
    }
    printf("Minimum total distance: %d km",total);
}

int main(){
    int n;
    scanf("%d",&n);
    int graph[10][10];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    prims(graph,n);
}


#include<stdio.h>
#include<stdlib.h>
#define max 100
typedef struct graph{
    int adjmat[max][max];
    int visited[max];
    int n,m;
}graph;

void init(graph* g,int n,int m){
    g->n=n;
    g->m=m;
    for(int i=0;i<n;i++){
        g->visited[i]=0;
        for(int j=0;j<n;j++){
            g->adjmat[i][j]=0;
        }
    }
}

void addedge(graph* g,int u,int v,int w){
    g->adjmat[u][v]=w;
}

void dfs(graph* g,int vertex){
    g->visited[vertex]=1;
    printf("%d ",vertex);
    for(int i=0;i<g->n;i++){
        if(g->adjmat[vertex][i]!=0 && vertex!=i && g->visited[i]==0){
            dfs(g,i);
        }
    }
}

int main(){
    int n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    graph g;
    init(&g,n,m);
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d",&u);
        scanf("%d",&v);
        addedge(&g,u,v,1);
    }
    int start;
    scanf("%d",&start);
    dfs(&g,start);
    return 0;
}





#include<stdio.h>
#include<stdlib.h>
#define max 101

typedef struct graph{
    int adjmat[max][max];
    int visited[max];
    int n,m;
}graph;

void init(graph* g,int n,int m){
    g->n=n;
    g->m=m;
    for(int i=0;i<n;i++){
        g->visited[i]=0;
        for(int j=0;j<n;j++){
            g->adjmat[i][j]=0;
        }
    }
}

void addedge(graph* g,int u,int v){
    g->adjmat[u][v]=1;
}

void bfs(graph* g,int vertex){
    int q[g->n];
    int front=0;
    int rear=0;
    q[rear++]=vertex;
    g->visited[vertex]=1;
    while(front<rear){
        int node=q[front];
        front++;
        printf("%d ",node);
        for(int i=0;i<g->n;i++){
            if(g->adjmat[node][i]==1 && node!=i && g->visited[i]==0){
                q[rear++]=i;
                g->visited[i]=1;
            }
        }
        
    }
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    graph g;
    init(&g,n,m);
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        addedge(&g,u,v);
    }
    int start;
    scanf("%d",&start);
    bfs(&g,start);
    return 0;
}



#include<stdio.h>
#include<stdlib.h>
#define max 10

typedef struct graph{
    int adjmat[max][max];
    int visited[max];
    int n,m;
}graph;

void init(graph* g,int n,int m){
    g->n=n;
    g->m=m;
    for(int i=0;i<n;i++){
        g->visited[i]=0;
        for(int j=0;j<n;j++){
            g->adjmat[i][j]=0;
        }
    }
}

void addedge(graph* g,int u,int v){
    g->adjmat[u][v]=1;
    g->adjmat[v][u]=1;
}

void dfs(graph* g,int vertex){
    g->visited[vertex]=1;
    printf("%d ",vertex);
    for(int i=0;i<g->n;i++){
        if(g->visited[i]!=1  && g->adjmat[vertex][i]==1 && i!=vertex){
            dfs(g,i);
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    graph* g;
    init(g,n,n-1);
    while(true){
        int u,v;
        scanf("%d %d",&u,&v);
        if(u==-1 && v==-1){
            break;
        }
        addedge(g,u,v);
    }
    printf("Following are connected components:\n");
    for(int i=0;i<n;i++){
        if(g->visited[i]==0){
            dfs(g,i);
            printf("\n");
        }
    }
    return 0;
    
}



#include<stdio.h>
#include<stdlib.h>
#define max 100

typedef struct graph{
    int adj[max][max];
    int visited[max];
    int level[max];
    int n,m;
}graph;

void init(graph* g,int n,int m){
    g->n=n;
    g->m=m;
    for(int i=0;i<n;i++){
        g->visited[i]=0;
        g->level[i]=0;
        for(int j=0;j<n;j++){
            g->adj[i][j]=0;
        }
    }
}

void addedge(graph* g,int u,int v){
    g->adj[u][v]=1;
}

int bfslevel(graph* g,int start,int target){
    int ans=-1;
    int count=1;
    int queue[max];
    int front=0,rear=0;
    queue[rear++]=start;
    g->visited[start]=1;
    g->level[start]=1;
    while(front<rear){
        int node=queue[front++];
        if(node==target){
            ans=g->level[target];
            break;
        }
        for(int i=0;i<g->n;i++){
            if(g->adj[node][i]==1 && node!=i && g->visited[i]==0){
                queue[rear++]=i;
                g->visited[i]=1;
                g->level[i]=g->level[node]+1;
                
            }
            
        }
        
    }
    return ans;
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    graph g;
    init(&g,n,m);
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        addedge(&g,u,v);
    }
    int target;
    scanf("%d",&target);
    int ans=bfslevel(&g,0,target);
    printf("%d",ans);
    return 0;
}


// detect cycle 
#include<stdio.h>
#include<stdlib.h>
#define max 100
typedef struct graph{
    int adj[max][max];
    int visited[max];
    int n,e;
}graph;

void init(graph* g,int n,int e){
    g->n=n;
    g->e=e;
    for(int i=0;i<n;i++){
        g->visited[i]=0;
        for(int j=0;j<n;j++){
            g->adj[i][j]=0;
        }
    }
}

void addedge(graph* g,int u,int v){
    g->adj[u][v]=1;
    g->adj[v][u]=1;
}

int cycle(graph* g,int source,int parent){
    g->visited[source]=1;
    for(int i=0;i<g->n;i++){
        if(g->adj[source][i]==1 && i!=source){
            if(g->visited[i]==0){
                cycle(g,i,source);
            }
            else if(i!=parent){
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    graph g;
    init(&g,n,m);
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        addedge(&g,u,v);
    }
    printf("%d",cycle(&g,0,-1));
}