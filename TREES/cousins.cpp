#include<bits/stdc++.h>
using namespace std;
typedef struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
}node;

int depth(TreeNode* root,int x,map<TreeNode*,TreeNode*>& parents,TreeNode*& node){
        if(root==NULL){
            return 0;
        }
        if(root->val==x){
            node=root;
            return 1;
        }
        parents[root->left]=root;
        parents[root->right]=root;
        int l=depth(root->left,x,parents,node);
        int r=depth(root->right,x,parents,node);
        if(l!=0){
            return 1+l;
        }
        else if(r!=0){
            return 1+r;
        }
        else{
            return 0;
        }
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        map<TreeNode*,TreeNode*>parents;
        TreeNode* xnode;
        TreeNode* ynode;
        int depthx=depth(root,x,parents,xnode);
        int depthy=depth(root,y,parents,ynode);
        return (depthx==depthy) && (parents[xnode]!=parents[ynode]);
    }