#include<bits/stdc++.h>
using namespace std;

typedef struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
}node;

int ceil(TreeNode* root,int key){
    int ans=-1;
    while(!root){
        if(root->val==key){
            ans=root->val;
            break;
        }
        else if(root->val>key){
            ans=root->val;
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    return ans;
}
