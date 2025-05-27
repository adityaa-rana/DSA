// //djikstra
// #include<stdio.h>
// #include<stdlib.h>
// #include<limits.h>

// int mindis(int visited[],int distance[],int num){
//     int minind=-1;
//     int min=INT_MAX;
//     for(int i=0;i<num;i++){
//         if(!visited[i] && distance[i]<min){
//             min=distance[i];
//             minind=i;
//         }
//     }
//     return minind;
// }

// void djikstra(int graph[100][100],int source,int des,int num){
//     int visited[num];
//     int distance[num];
//     int prev[num];
//     for(int i=0;i<num;i++){
//         visited[i]=0;
//         distance[i]=INT_MAX;
//         prev[i]=-1;
//     }
//     distance[source]=0;
//     for(int i=0;i<num-1;i++){
//         int u=mindis(visited,distance,num);
//         visited[u]=1;
//         for(int j=0;j<num;j++){
//             if(!visited[j] && graph[u][j] && distance[u]!=INT_MAX && graph[u][j]+distance[u]<distance[j]){
//                 distance[j]=graph[u][j]+distance[u];
//                 prev[j]=u;
//             }
//         }
//     }
//     int path[num];
//     int pathind=0;
//     for(int i=des;i!=-1;i=prev[i]){
//         path[pathind++]=i;
//     }
    
//     for(int j=pathind-1;j>=0;j--){
//         printf("%d",path[j]);
//     }
// }

// prims algo
// #include<stdio.h>
// #include<stdlib.h>
// #include<limits.h>

// int mindis(int visited[],int distance[],int num){
//     int minind=-1;
//     int min=INT_MAX;
//     for(int i=0;i<num;i++){
//         if(!visited[i] && distance[i]<min){
//             min=distance[i];
//             minind=i;
//         }
//     }
//     return minind;
// }

// void prims(int graph[100][100],int num){
//     int visited[num];
//     int distance[num];
//     int parent[num];
//     for(int i=0;i<num;i++){
//         visited[i]=0;
//         distance[i]=INT_MAX;
//     }
//     distance[0]=0;
//     parent[0]=-1;
//     int edges=0;
//     while(edges<num-1){
//         int u=mindis(visited,distance,num);
//         visited[u]=1;
//         edges++;
//         for(int i=0;i<num;i++){
//             if(!visited[i] && graph[u][i] && distance[i]>graph[u][i]){
//                 distance[i]=graph[u][i];
//                 parent[i]=u;
//             }
//         }
//     }
//     int total=0;
//     for(int i=1;i<num;i++){
//         printf("%d -> %d",i,parent[i]);
//         total+=graph[i][parent[i]];
//     }
// }


// kruskal algo

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define max 10
typedef struct edge{
    int u,v,w;
}edge;

int parent[max];
int rank[max];

void init(int n){
    for(int i=0;i<n;i++){
        parent[i]=i;
        rank[i]=0;
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
    if(upx!=upy){
        if(rank[upx]>=rank[upy]){
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

int compare(const void* a,const void* b){
    edge *edgeA=(edge*)a;
    edge *edgeB=(edge*)b;
    return edgeA->w-edgeB->w;
}

void kruskal(edge edges[],int n,int e){
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
            printf("%d->%d : %d",u,v,w);
            mst+=w;
            mstedges++;
        }
        if(mstedges==n-1){
            break;
        }
    }
    if(mstedges==n-1){
        printf("MST: %d",mst);
    }
    else{
        printf("NOT POSSIBLE");
    }
}