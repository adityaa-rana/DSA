#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        //convert to adjacency list
        int src=1;
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        
        vector<int>parent(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
        
        // Min-heap priority queue: {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> dist(n+1, INT_MAX);
        dist[src] = 0;
        pq.push({0, src});
        
        while(!pq.empty()){
            int currdis=pq.top().first;
            int currnode=pq.top().second;
            pq.pop();
            
            for(auto it:adj[currnode]){
                int adjNode = it.first;
                int edgeWeight = it.second;

                if (currdis + edgeWeight < dist[adjNode]) {
                    dist[adjNode] = currdis + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                    parent[adjNode]=currnode;
                }
            }
        }
        
        if(parent[n]==n){
            return {-1};
        }
        
        vector<int>ans;
        int node=n;
        while(parent[node]!=node){
            ans.push_back(node);
            node=parent[node];
        }
        
        ans.push_back(node);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
