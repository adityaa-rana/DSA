
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val),left(nullptr),right(nullptr){} //constructor
};
class Solution {
public:
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
    TreeNode* prev;

    void inorder(TreeNode* root){
        if(root==NULL){
            return;
        }

        inorder(root->left);
        if(prev && root->val < prev->val){
            if(first==NULL){
                first=prev;
                middle=root;
            }
            else{
                last=root;
            }
        }

        prev=root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root){
        if(root==NULL){
            return;
        }
        first=middle=last=NULL;
        prev=new TreeNode(INT_MIN);
        inorder(root);
        if(!last){
            swap(first->val,middle->val);
        }
        else{
            swap(first->val,last->val);
        }
    }
};