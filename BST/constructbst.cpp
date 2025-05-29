#include<bits/stdc++.h>
using namespace std;

typedef struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val),left(nullptr),right(nullptr){}
}node;

// construct a bst from a given pre order traversal
TreeNode* construct(vector<int>& preorder,int index,TreeNode* root,int ub){
    
    if(preorder[index]>ub){
        return NULL;
    }
    TreeNode* temp=new TreeNode(preorder[index]);
    index++;
    if(root->left==NULL){
        root->left=temp;
    }
    else if(root->right==NULL){
        root->right=temp;
    }
    if(index==preorder.size()){
        return root;
    }
    TreeNode* l=construct(preorder,index,root->left,root->val);
    TreeNode* r=construct(preorder,index,root->right,ub);
    if(!l){
        return r;
    }
    else{
        return r;
    }
}
    
TreeNode* bstFromPreorder(vector<int>& preorder){
    int index=0;
    int ub=INT_MAX;
    TreeNode* root=new TreeNode(preorder[index++]);
    root=construct(preorder,index,root,ub);
    return root;
    
}