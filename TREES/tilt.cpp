#include<bits/stdc++.h>
using namespace std;
typedef struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
}node;

int find(TreeNode* root,int *ans){
        if(root==NULL){
            return 0;
        }
        int l=find(root->left,ans);
        int r=find(root->right,ans);
        int curr=root->val;
        root->val=abs(r-l);
        *ans+=root->val;
        return l+r+curr;
    }
    int findTilt(TreeNode* root) {
        int ans=0;
        find(root,&ans);
        return ans;
    }