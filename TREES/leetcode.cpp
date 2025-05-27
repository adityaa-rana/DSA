#include<bits/stdc++.h>
using namespace std;
typedef struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
}node;

void addleaves(node* root,vector<int>&leaves){
    if(root->left==NULL && root->right==NULL){
        leaves.push_back(root->val);
        return;
    }
    addleaves(root->left,leaves);
    addleaves(root->right,leaves);
}
bool leafsimilar(node* root1,node* root2){
    vector<int>tree1;
    vector<int>tree2;
    addleaves(root1,tree1);
    addleaves(root2,tree2);
    int size=tree1.size();
    for(int k=0;k<size;k++){
        if(tree1[k]!=tree2[k]){
            return false;
        }
    }
    if(tree1.size()!=tree2.size()){
        return false;
    }
    return true;
}

// better solution

void addleaves(TreeNode* root, vector<int>& leaves) {
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL) {
        leaves.push_back(root->val);
        return;
    }
    addleaves(root->left, leaves);
    addleaves(root->right, leaves);
}

bool compare(const vector<int>& tree, TreeNode* root, int* ind) {
    if (root == NULL) return true;

    if (root->left == NULL && root->right == NULL) {
        // Check bounds
        if (*ind >= tree.size() || root->val != tree[*ind]) {
            return false;
        }
        (*ind)++;
        return true;
    }

    bool l = compare(tree, root->left, ind);
    bool r = compare(tree, root->right, ind);
    return l && r;
}

bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> tree1;
    addleaves(root1, tree1);
    int ind = 0;
    bool ans = compare(tree1, root2, &ind);
    return ans && ind == tree1.size();  // All leaves must be matched
}