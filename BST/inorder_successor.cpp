#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val),left(nullptr),right(nullptr){} //constructor
};

TreeNode* successor(TreeNode* root,TreeNode* key){
    if(root==NULL){
        return NULL;
    }
    TreeNode* ans=NULL;
    while(root!=NULL){
        if(root->val <= key->val){
            root=root->right;
        }
        else if(root->val > key->val){
            ans=root;
            root=root->left;
        }
    
    }
    return ans;
}