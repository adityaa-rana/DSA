#include<bits/stdc++.h>
using namespace std;

typedef struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
}node;

TreeNode* findMin(TreeNode* root) {
        while (root && root->left) {
            root = root->left;
        }
        return root;
    }

    TreeNode* parent(TreeNode* root, TreeNode* target) {
        if (root == NULL || root == target) return NULL;
        TreeNode* curr = root;
        while (curr) {
            if (curr->left == target || curr->right == target) return curr;
            if (target->val < curr->val) curr = curr->left;
            else curr = curr->right;
        }
        return NULL;
    }

    TreeNode* deleteGivenNode(TreeNode* root, TreeNode* node) {
        if (root == NULL || node == NULL) return root;

        if (node->left == NULL && node->right == NULL) {
            TreeNode* prnt = parent(root, node);
            if (prnt) {
                if (prnt->left == node) prnt->left = NULL;
                else prnt->right = NULL;
            }
            delete node;
            return prnt ? prnt : NULL;
        }

        if (node->left == NULL) {
            TreeNode* prnt = parent(root, node);
            if (prnt) {
                if (prnt->left == node) prnt->left = node->right;
                else prnt->right = node->right;
            }
            delete node;
            return prnt ? prnt : node->right;
        }

        if (node->right == NULL) {
            TreeNode* prnt = parent(root, node);
            if (prnt) {
                if (prnt->left == node) prnt->left = node->left;
                else prnt->right = node->left;
            }
            delete node;
            return prnt ? prnt : node->left;
        }

        // Both children exist
        TreeNode* temp = findMin(node->right);
        node->val = temp->val;
        node->right = deleteGivenNode(root, temp);
        return node;
    }

    TreeNode* trim(TreeNode* root, TreeNode* org, int low, int high) {
        if (root == NULL) return root;

        if (root->val < low || root->val > high) {
            root = deleteGivenNode(org, root);
            return trim(root, org, low, high);  // Re-check after deletion
        }

        root->left = trim(root->left, org, low, high);
        root->right = trim(root->right, org, low, high);
        return root;
    }

    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return trim(root, root, low, high);
    }