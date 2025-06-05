#include<bits/stdc++.h>
using namespace std;
typedef struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
}node;
class Solution {
public:
    void inorder(TreeNode* root,vector<int>& r){
        if(root==NULL){
            return;
        }
        inorder(root->left,r);
        r.push_back(root->val);
        inorder(root->right,r);
        return;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>r1;
        vector<int>r2;
        inorder(root1,r1);
        inorder(root2,r2);

        vector<int>ans;
        int i=0,j=0;
        while(i<r1.size() && j<r2.size()){
            if(r1[i] <= r2[j]){
                ans.push_back(r1[i]);
                i++;
            }
            else{
                ans.push_back(r2[j++]);
            }
        }
        while(i<r1.size()){
            ans.push_back(r1[i]);
            i++;
        }
        while(j<r2.size()){
            ans.push_back(r2[j]);
            j++;
        }
        return ans;
    }
};