#include<bits/stdc++.h>
using namespace std;

// bfs traversal
typedef struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
}node;

class Solution {
public:
    bool check(TreeNode* root,int value){
        if(root==NULL){
            return true;
        }
        if(root->val!=value){
            return false;
        }
        bool l=check(root->left,value);
        bool r=check(root->right,value);
        if(!l || !r){
            return false;
        }
        return true;

    }
    bool isUnivalTree(TreeNode* root) {
        return check(root,root->val);
    }
};