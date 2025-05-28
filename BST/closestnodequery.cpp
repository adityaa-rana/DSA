#include<bits/stdc++.h>
using namespace std;

typedef struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
}node;


// basically a vector of nodes is given, we have to find a pair of floor and ceil for each node
int ceil(TreeNode* root,int query){
        int ans=-1;
        while(root!=NULL){
            if(root->val==query){
                ans=root->val;
            }
            else if(root->val>query){
                ans=root->val;
                root=root->left;
            }
            else{
                root=root->right;
            }
        }
        return ans;
    }
    int floor(TreeNode* root,int query){
        int ans=-1;
        while(root!=NULL){
            if(root->val==query){
                ans=root->val;
            }
            else if(root->val<query){
                ans=root->val;
                root=root->right;
            }
            else{
                root=root->left;
            }
        }
        return ans;
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> external;
        for(int i=0;i<queries.size();i++){
            vector<int> internal;
            int f=floor(root,queries[i]);
            internal.push_back(f);
            int c=ceil(root,queries[i]);
            internal.push_back(c);
            external.push_back(internal);
        }
        return external;
    }


// a better solution to this question will be by converting the tree to a sorted array and then using binary search