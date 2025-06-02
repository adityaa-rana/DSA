#include<bits/stdc++.h>
using namespace std;

typedef struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val),left(nullptr),right(nullptr){}
}node;

// construct a bst from a given pre order traversal
TreeNode* construct(vector<int>& preorder, int& index, int ub) {
    if (index == preorder.size() || preorder[index] > ub)
        return NULL;

    TreeNode* root = new TreeNode(preorder[index++]);
    root->left = construct(preorder, index, root->val);
    root->right = construct(preorder, index, ub);
    return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    int index = 0;
    return construct(preorder, index, INT_MAX);
}
