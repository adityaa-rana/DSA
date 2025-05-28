#include<bits/stdc++.h>
using namespace std;

typedef struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
}node;

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    if(root==NULL){
        return NULL;
    }
    while(root){
        if(root->val > p->val && root->val > q->val){
            root=root->left;
        }
        else if(root->val < p->val && root->val < q->val){
            root=root->right;
        }
        else{
            break;
        }
    }
    return root;
}