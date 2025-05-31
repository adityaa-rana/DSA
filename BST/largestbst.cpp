#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val),left(nullptr),right(nullptr){} //constructor
};

class NodeValue{
public:
    int maxsum;
    int maxnode;
    int minnode;
    NodeValue(int summ,int minn,int maxx){
        this->maxsum=summ;
        this->minnode=minn;
        this->maxnode=maxx;
    }
};
class Solution {

public:
    NodeValue find(TreeNode* root,int& maximum){
        if(root==NULL){
            return NodeValue(0,INT_MAX,INT_MIN);
        }
        auto l=find(root->left,maximum);
        auto r=find(root->right,maximum);

        if(l.maxnode < root->val && r.minnode > root->val){
            maximum=max(maximum,root->val+l.maxsum+r.maxsum);
            return NodeValue(root->val+l.maxsum+r.maxsum, min(root->val,l.minnode) , max(root->val,r.maxnode));
        }
        else{
            return NodeValue(max(r.maxsum,l.maxsum) , INT_MIN,INT_MAX);
        }
    }
    int maxSumBST(TreeNode* root) {
        int maximum=0;
        find(root,maximum);
        return maximum;
    }
};