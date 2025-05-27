#include<bits/stdc++.h>
using namespace std;

class treenode{
    public:
    int data;
    treenode* left;
    treenode* right;
    treenode(int data){
        this->data=data;
        left=nullptr;
        right=nullptr;
    }
};

// search in a binary tree
// recursive preorder
treenode* searchBST(treenode* root, int val) {
    if(root == NULL) {
        return NULL;
    }
    if(root->data == val) {
        return root;
    }
    else if(root->data > val) {
        return searchBST(root->left, val);  
    }
    else {
        return searchBST(root->right, val);  
    }
}

// iterative pre order
treenode* searchBST(treenode* root, int val) {
    while(root->data!=val || root!=NULL){
        if(root->data > val) {
            root=root->left;  
        }
        else {
            root=root->right;  
        }
        }
    return root;
}


//minimum difference between parent and child node class Solution {

int getMinimumDifference(treenode* root) {
    int diff=INT_MAX;
    mindiff(root,&diff);
    return diff;
}
void mindiff(treenode* root,int *diff){
    if(root==NULL){
        return;
    }
    if(root->left!=NULL){
        int left=abs(root->data-root->left->data);
        if(left<*diff){
            *diff=left;
        }
    }
    if(root->right!=NULL){
        int right=abs(root->data-root->right->data);
        if(right<*diff){
            *diff=right;
        }
    }
    
    mindiff(root->left,diff);
    mindiff(root->right,diff);
}

// inorder successor

//method 1 brute force

treenode* successor(treenode* root,treenode* key){
    vector<treenode*>inorder;
    treenode* ans=NULL;
    intrav(root,key,inorder);
    for(int i=0;i<inorder.size();i++){
        if(inorder[i]==key && i!=inorder.size()-1){
            ans=inorder[i+1];
            break;
        }
    }
    return ans;
}
void intrav(treenode* root,treenode* key,vector<treenode*>& inorder){
    if(root==NULL){
        return;
    }
    intrav(root->left,key,inorder);
    inorder.push_back(root);
    intrav(root->right,key,inorder);
}

treenode* successor(treenode* root,treenode* key){
    treenode* ans=NULL;
    while(root!=NULL){
        if(root->data<=key->data){
            root=root->right;
        }
        else{
            ans=root;
            root=root->left;
        }
    }
    return ans;
}