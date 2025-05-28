#include<bits/stdc++.h>
using namespace std;

typedef struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
}node;

// approach 1 : store inorder in vector, check if sorted 

void findinorder(TreeNode* root,vector<int>& inorder){
    if(root==NULL){
        return;
    }
    findinorder(root->left,inorder);
    inorder.push_back(root->val);
    findinorder(root->right,inorder);
    return;

}

bool isValidBST(TreeNode* root){
    vector<int>inorder;
    bool ans=true;
    findinorder(root,inorder);
    for(int i=1;i<inorder.size();i++){
        if(inorder[i]<=inorder[i-1]){
            ans=false;
        }
    }
    return ans;
}


// approach 2 : no need to store, use left and right recursion

bool checkvalid(TreeNode* root,long minposs,long maxposs){
    if(root==NULL){
        return true;
    }
    if(root->val >= maxposs || root->val <= minposs){
        return false;
    }

    bool l=checkvalid(root->left,minposs,root->val);
    bool r=checkvalid(root->right,root->val,maxposs);
    if(!l || !r){
        return false;
    }
    return true;

}
bool isValidBST(TreeNode* root){
    return checkvalid(root,LONG_MIN,LONG_MAX);
}