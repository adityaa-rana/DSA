#include<bits/stdc++.h>
using namespace std;

typedef struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
}node;


//better  method

bool check(TreeNode* root, TreeNode* org, int& remain) {
    if (root == NULL) {
        return false;
    }

    bool ans = false;
    int remaining = remain - root->val;

    TreeNode* curr = org;
    while (curr) {
        if (curr->val == remaining && curr != root) {
            ans = true;
            break;
        }
        if (remaining > curr->val) {
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }

    bool checkleft = false;
    bool checkright = false;
    if (!ans) {
        checkleft = check(root->left, org, remain);
        checkright = check(root->right, org, remain);
    }

    return ans || checkleft || checkright;
}

bool findTarget(TreeNode* root, int k) {
    return check(root, root, k);
}
