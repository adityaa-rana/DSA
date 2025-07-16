#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Build adjacency list: adj[node] = vector of {neighbor, weight}
        vector<vector<pair<int, int>>> adj(V);
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], wt = edge[2];
            adj[u].push_back({v, wt});
            // If undirected graph: also add reverse edge
            // adj[v].push_back({u, wt});
        }

        // Min-heap priority queue: {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            int currDis = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();

            for (auto &it : adj[currNode]) {
                int adjNode = it.first;
                int edgeWeight = it.second;

                if (currDis + edgeWeight < dist[adjNode]) {
                    dist[adjNode] = currDis + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
};