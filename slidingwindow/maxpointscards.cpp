#include <bits/stdc++.h>
using namespace std;

// brute force try all possible combo
int maxScore(vector<int>& cardPoints, int k){
    int size = cardPoints.size();
    int ans = 0;
    
    for(int i = 0; i <= k; i++){
        int sum = 0;
        // Take i cards from the start
        for(int j = 0; j < i; j++){
            sum += cardPoints[j];
        }
        // Take (k - i) cards from the end
        for(int j = 0; j < k - i; j++){
            sum += cardPoints[size - 1 - j];
        }
        ans = max(ans, sum);
    }
    return ans;
}


// better 
int maxScore(vector<int>& cardPoints, int k){
    int summ=0;
    for(int i=0;i<k;i++){
        summ+=cardPoints[i];
    }
    int ans=summ;
    int size = cardPoints.size();
    for(int j=1;j<=k;j++){
        summ-=cardPoints[k-j];
        summ+=cardPoints[size-j];
        ans=max(summ,ans);
    }
    return ans;
}