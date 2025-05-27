#include<bits/stdc++.h>
using namespace std;

typedef struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
}node;

TreeNode* search(TreeNode* root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->val==key)
    {
        return root;
    }
    else if(root->val>key){
        return search(root->left,key);
    }
    else{
        return search(root->right,key);
    }
}