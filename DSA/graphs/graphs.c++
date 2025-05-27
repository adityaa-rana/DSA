#include<bits/stdc++.h>
using namespace std;
// bfs of graph
vector<int> bfs(vector<int>adj[],int num){
    vector<int >answer;
    int visited[num]={0};
    visited[0]=1;
    queue<int>q;
    q.push(0);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        answer.push_back(node);
        for(auto it: adj[node]){
            if(!visited[it]){
                q.push(it);
                visited[it]=1;
            }
        }
    }
    return answer;
}


void dfs_recur(vector<int> &ans,int visited[],int start,vector<int>adj[]){
    ans.push_back(start);
    visited[start]=1;
    for(auto it:adj[start]){
        if(!visited[it]){
            dfs_recur(ans,visited,it,adj);
        }
    }
}
vector<int> dfs(vector<int>adj[],int num){
    int start;
    int visited[num]={0};
    vector<int>answer;
    dfs_recur(answer,visited,start,adj);
    return answer;
}

// number of provinces

void dfs_recur(int visited[],vector<int>adj[],int node){
    visited[node]=1;
    for(auto it: adj[node]){
        dfs_recur(visited,adj,it);
    }
}

int provinces(vector<int> adj[],int num){
    int visited[num]={0};
    int count=0;
    for(int i=0;i<num;i++){
        if(visited[i]==0){
            count++;
            dfs_recur(visited,adj,i);
        }
    }
}

// number of islands using grid
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    void bfs(int crow, int ccol, vector<vector<char>>& grid, vector<vector<int>>& visited) {
        int n = grid.size();
        int m = grid[0].size();

        visited[crow][ccol] = 1;
        queue<pair<int, int>> q;
        q.push({crow, ccol});
        
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int r = row + i;
                    int c = col + j;

                    // Ensure we are within bounds and only explore land that hasn't been visited yet
                    if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == '1' && !visited[r][c]) {
                        visited[r][c] = 1;
                        q.push({r, c});
                    }
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        int count = 0;

        // Initialize visited vector with 0 (unvisited)
        vector<vector<int>> visited(rows, vector<int>(columns, 0));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                // If the cell is land and hasn't been visited
                if (!visited[i][j] && grid[i][j] == '1') {
                    bfs(i, j, grid, visited);
                    count++;  // Increment island count
                }
            }
        }
        return count;  // Return the number of islands
    }
};


// FLOOD FILL ALGO USING BFS
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initial = image[sr][sc];
        if (initial == color) return image; // No need to process if the initial color is the same as the target color
        
        queue<pair<int, int>> q;
        int n = image.size();
        int m = image[0].size();

        q.push({sr, sc});
        
        while (!q.empty()) {
            int currow = q.front().first;
            int curcol = q.front().second;
            image[currow][curcol] = color;
            q.pop();

            // Check the four cardinal directions (up, down, left, right)
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (abs(i) + abs(j) == 1) { // Only consider up, down, left, right
                        int r = currow + i;
                        int c = curcol + j;
                        if (r >= 0 && r < n && c >= 0 && c < m && image[r][c] == initial) {
                            q.push({r, c});
                        }
                    }
                }
            }
        }
        return image;
    }
};

// FLOOD FILL ALGO USING DFS
class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc,int delrow[],int delcol[],int color,int initial){
        int n = image.size();
        int m = image[0].size();
        image[sr][sc]=color;
        for(int i=0;i<4;i++){
            int r=sr+delrow[i];
            int c=sc+delcol[i];
            if(r>=0 && r<n && c>=0 && c<m && image[r][c]==initial){
                dfs(image,r,c,delrow,delcol,color,initial);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initial=image[sr][sc];
        if(image[sr][sc]==color){
            return image;
        }
        int delrow[4]={0,-1,0,1};
        int delcol[4]={-1,0,1,0};
        dfs(image,sr,sc,delrow,delcol,color,initial);
        return image;
    }
};



// detect a cycle in undirected graph using bfs
 // this question can also be done using queue<pair<int,int>> instead of map
bool iscycle(vector<int>adj[],int visited[],int src){
    map<int,int>parent;
    
    parent.insert({src,-1});
    visited[src]=1;
    while(!parent.empty()){
        int element=parent.begin()->first;
        int prnt=parent.begin()->second;
        parent.erase(parent.begin());
        for(auto it:adj[element]){
            if(visited[it]==1 && it!=prnt){
                return true;
            }
            else if(!visited[it] && it!=prnt){
                parent.insert({it,element});
            }
        }
    }
    return false;
}

// for disconneted componenets of graph
bool detectcycle(vector<int>adj[],int num,int src){
    int visited[num+1]={0};
    for(int i=0;i<num;i++){
        if(!visited[i]){
            bool res=iscycle(adj,visited,i);
            if(res==true){
                return true;
            }
        }
    }
    return false;
}

// detect a cycle in undirected graph using dfs

bool dfs(vector<int>adj[],int visited[],int src,int parent){
    visited[src]=1;
    for(auto it:adj[src]){
        if(!visited[it]){
            if(dfs(adj,visited,it,src)==true){
                return true;    
            }
        }
        else if(it!=parent){
            return true;
        }
    }
    return false;
}
bool iscycledfs(vector<int>adj[],int num,int src){
    int parent=-1;
    int visited[num]={0};
    for(int i=1;i<=num;i++){
        if(dfs(adj,visited,src,parent)==true){
            return true;
        }
    }
    return false;
    
}

