// adjacency matrix representation of graphs
#include<bits/stdc++.h>
using namespace std;

// int main(){
//     int n,m;
//     //n= no. of nodes , m=no. of edges
//     cin>>n>>m;
//     int adj[n+1][m+1];
//     for(int i=0;i<m;i++){
//         int u,v;
//         cin>>u>>v;
//         adj[v][u]=1;   
//         adj[u][v]=1;    // not to be done for directed graphs
//     }
//     return 0;
// }

// TC= O(N)
// SC= O(N*N)

// USING ARRAY OF VECTORS (adjacency list)
// int main(){
//     int n,m;
//     cin>>n>>m;
//     vector<vector<int>>adj(n+1);
//     for(int i=0;i<m;i++){
//         int u,v;
//         cin>>u>>v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);   // not required for directed graphs
//     }
//     return 0;
// }


// instead pof vector  of data type int use pair data type vector for storing graph using adjacency list  
//for weighted matrix where the pair will store the inceident vertex and the weight of the edge
// int main(){
//     int n,m;
//     cin>>n>>m;
//     vector<vector<pair<int,int>>adj(n+1);
//     for(int i=0;i<m;i++){
//         int u,v;
//         cin>>u>>v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);   // not required for directed graphs
//     }
//     return 0;
// }

// SC= o(2*m)    // SC= O(m) for directed graph 
// TC=o(n)

// bfs traversal in graph

vector<int> bfs(int num,vector<int>adj[]){  // num is starting node
    vector<int>bfs;
    int visited[num]={0};
    visited[0]=1;
    queue<int>q;
    q.push(0);  // pushing first node
    while(!q.empty()){
        int node=q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it: adj[node]){
            if(!visited[it]){
                visited[it]=1;
                q.push(it);
            }
        }
    }
    return bfs;
}


//TC= O(n)
void dfs_recur(int node,vector<int>& ans, vector<int> adj[],int visited[]){
    visited[node]=1;
    ans.push_back(node);
    for(auto it: adj[node]){
        if(!visited[it]){
            dfs_recur(it,ans,adj,visited);
        }
    }
}

vector<int>dfs(int num,vector<int>adj[]){
    int visited[num]={0};
    int node; // starting node
    vector<int>ans;
    dfs_recur(node,ans,adj,visited);
    return ans;
}

// number of provinces 
void dfs(int node, vector<int> adjlist[],vector<int>& visited){
    visited[node]=1;
    for(auto it: adjlist[node]){
        if(!visited[it]){
            dfs(it,adjlist,visited);
        }
    }
}
int provinces(vector<vector<int>>& isConnected) {
    // converting adjacency matrix to list
    int n=isConnected.size();
    vector<int> adjlist[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(isConnected[i][j]==1 && i!=j){
                adjlist[i].push_back(j);
                adjlist[j].push_back(i);
            }
        }
    }

    vector<int> visited(n,0);
    int count=0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            count++;
            dfs(i,adjlist,visited);
        }
    }
    return count;
}

// detecting a cycle using bfs

// bool cyclebfs(int start,vector<int>adj[],int visited[]){
//     visited[start]=1;
//     queue<pair<int,int>> q;
//     q.push({start,-1});
//     while(!q.empty()){
//         int node=q.front().second;
//         int parent=q.front().first;
//         q.pop();

//         for(auto it:adj[node]){
//             if(!visited[it]){
//                 q.push({it,node});
//             }
//             else if(it!=parent){
//                 return true;   // the real point of checking
//             }
//         }
//     }
//     return false;
// }

// bool iscyclebfs(int num,vector<int>adj[]){
//     int visited[num]={0};
//     for(int  i=0;i<num;i++){
//         if(!visited[i]){
//             if(cyclebfs(i,adj,visited)==true){
//                 return true;
//             }
//         }
//     }
//     return false;
// }

// // detecting a cycle using dfs

// bool cycledfs(int node,int parent,vector<int>adj[],int visited[]){
//     visited[node]=1;
//     for(auto adjnode : adj[node]){
//         if(!visited[adjnode]){
//             if(cycledfs(adjnode,node,adj,visited)==true){
//                 return true;
//             }
//             else if(adjnode!=parent){
//                 return true;
//             }
//         }
//     }
//     return false;
// }

// bool iscycledfs(int num,vector<int>adj[]){
//     int visited[num]={0};
//     for(int i=0;i<num;i++){
//         if(!visited[i]){
//             if(cycledfs(i,-1,adj,visited)==true){
//                 return true;
//             }
//         }
//     }
//     return false;
// }

