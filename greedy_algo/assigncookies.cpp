#include<bits/stdc++.h>
using namespace std;
int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int greed=0;
        int cookie=0;
        int count=0;
        while(greed<g.size() && cookie<s.size()){
            if(g[greed]<=s[cookie]){
                count++;
                greed++;
                cookie++;
            }
            else{
                cookie++;
            }
        }
        return count;
    }