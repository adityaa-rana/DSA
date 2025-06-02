#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val),left(nullptr),right(nullptr){} //constructor
};

// approach 1 , storing all elements inorder in a vector and doing linear search
void findinorder(TreeNode* root,vector<int>& inorder){
    if(root==NULL){
        return;
    }
    findinorder(root->left,inorder);
    inorder.push_back(root->val);
    findinorder(root->right,inorder);
    return;

}
int ksmallest(TreeNode* root,int k){
    vector<int>inorder;
    findinorder(root,inorder);
    return inorder[k-1];
}


// approach 2 : without using vector
void inorder(TreeNode* root,int& k,int *ans){
    if(root==NULL){
        return;
    }
    inorder(root->left,k,ans);
    k--;
    if(k==0){
        *ans=root->val;
    }
    inorder(root->right,k,ans);
    return ;
}

int kthSmallest(TreeNode* root,int k){
    int ans=-1;
    inorder(root,k,&ans);
    return ans;
}
