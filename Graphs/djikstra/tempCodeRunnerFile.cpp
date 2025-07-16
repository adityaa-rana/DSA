#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {

        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));

        queue<pair<pair<int,int>,int>>q;
        q.push({{source.first,source.second},0});
        dist[source.first][source.second]=0;
        int ans=-1;
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int steps=q.front().second;
            if(row==destination.first && col==destination.second){
                ans=steps;
                break;
            }
            q.pop();
            int delrow[]={-1,0,1,0};
            int delcol[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int r=row+delrow[i];
                int c=col+delcol[i];
                if(r>=0 && r<n && c>=0 &&c<m && grid[r][c]==1 && dist[r][c]>steps+1){
                    dist[r][c]=steps+1;
                    q.push({{r,c},dist[r][c]});
                }
            }
            
        }
        return ans;
    }
};
