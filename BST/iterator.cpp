
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val),left(nullptr),right(nullptr){} //constructor
};

class BSTIterator {
    stack<TreeNode*> st;
public:
    void pushLeft(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    int next() {
        int ans=-1;
        TreeNode* node=NULL;
        if(!st.empty()){
            node=st.top();
            st.pop();
        }
        if(node){
            ans=node->val;
            if(node->right){
                pushLeft(node->right);
            }
        }   
        return ans;
    }
    
    bool hasNext() {
        if(st.empty()){
            return false;
        }
        else{
            return true;
        }
    }
};