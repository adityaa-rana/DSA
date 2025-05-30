#include<bits/stdc++.h>
using namespace std;
typedef struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
}node;
TreeNode* pruneTree(TreeNode* root) {
    if (root == NULL) return NULL;

    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);

    // If current node and both subtrees do not contain a 1, prune it
    if (root->val == 0 && root->left == NULL && root->right == NULL) {
        return NULL;
    }

    return root;
}