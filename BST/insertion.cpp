#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val),left(nullptr),right(nullptr){} //constructor
};

TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node=new TreeNode(val);
        TreeNode* org=root;
        if(root==NULL){
            return node;
        }
        while(root!=NULL){
            if(root->val>val){
                if(root->left==NULL){
                    root->left=node;
                    break;
                }
                else{
                    root=root->left;
                }
            }
            else if(root->val<val){
                if(root->right==NULL){
                    root->right=node;
                    break;
                }
                else{
                    root=root->right;
                }
            }
        }
        return org;
    }