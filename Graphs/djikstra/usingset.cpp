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

        set<pair<int,int>>st;

        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        st.insert({0, src});

        while (!st.empty()) {
            auto curr=*(st.begin());
            int currDis = curr.first;
            int currNode = curr.second;
            st.erase(curr);

            for (auto &it : adj[currNode]) {
                int adjNode = it.first;
                int edgeWeight = it.second;

                if (currDis + edgeWeight < dist[adjNode]) {
                    dist[adjNode] = currDis + edgeWeight;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
};

