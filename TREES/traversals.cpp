#include<bits/stdc++.h>
using namespace std;

// bfs traversal
typedef struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
}node;

// vertical order traversal 
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,int>>> q;
        map<int,map<int,multiset<int>>>nodes;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            TreeNode* currnode=curr.first;
            int currx=curr.second.first;
            int currlevel=curr.second.second;
            nodes[currx][currlevel].insert(currnode->val);
            if(currnode->left){
                q.push({currnode->left,{currx-1,currlevel+1}});
            }
            if(currnode->right){
                q.push({currnode->right,{currx+1,currlevel+1}});
            }
        }

        // step 2 :  transfer from map to vector
        vector<vector<int>>ans;

        // iterating over vertical columns one by one -2 -> -1 -> 0 -> 1 -> 2
        for(auto vertical_column:nodes){

            // to store vertical column 
            vector<int>vertical;

            // each level in a vertical column
            for(auto column_level: vertical_column.second){
                for (auto it = column_level.second.begin(); it != column_level.second.end(); ++it) {
                    int value = *it;          // get the value from multiset
                    vertical.push_back(value); // add the value to the vector
}
            }
            ans.push_back(vertical);
        }
        return ans;

    }
};

// construct a unqiue tree from given innorder and preorder
node* form(vector<int>& preorder,int prestart,vector<int>& inorder,int instart,int inend){
    if(instart>inend){
        return NULL;    
    }
    node* root;
    root->val=preorder[prestart];
    prestart;
    if(instart==inend){
        return root;
    }
    int j=instart;
    while(inorder[j]!=root->val){
        j++;
    }
    root->left=form(preorder,prestart,inorder,instart,j-1);
    root->right=form(preorder,prestart,inorder,j+1,inend);
    return root;
}

node* buildtree(vector<int>preorder,vector<int>inorder){
    if(preorder.size()==0){
        return NULL;
    }
    int prestart=0;
    node* tree=form(preorder,prestart,inorder,0,inorder.size()-1);
    return tree;
}


TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        TreeNode* root=construct(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mpp);
        return root;
    }
TreeNode* construct(vector<int>& preorder,int prestart,int prend,vector<int>& inorder,int instart, int inend,map<int,int>& mpp){
    if(prestart>prend || instart>inend){
        return NULL;
    }
    TreeNode* root=new TreeNode(preorder[prestart]);
    int inroot=mpp[root->val];
    int numsleft=inroot-instart;
    root->left=construct(preorder,prestart+1,prestart+numsleft,inorder,instart,inroot-1,mpp);
    root->right=construct(preorder,prestart+numsleft+1,prend,inorder,inroot+1,inend,mpp);
    return root;

}


// top view of binary tree
vector<int>topview(TreeNode* root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    map<int,int> coordinates;
    queue<pair<TreeNode*,int>>q;
    q.push({root,0});   
    while(!q.empty()){
        auto curr=q.front();
        q.pop();
        TreeNode* currnode=curr.first;
        int currx=curr.second;
        if(coordinates.count(currx)==0){
            coordinates[currx]=(currnode->val);
        }
        if(currnode->left){
            q.push({currnode->left,currx-1});
        }
        if(currnode->right){
            q.push({currnode->right,currx+1});
        }
    }
    
    for(auto node:coordinates){
        ans.push_back(node.second);
    }

    return ans;
}

// bottom view
vector<int>bottomview(TreeNode* root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    map<int,int>coordinates;
    queue<pair<TreeNode*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        auto curr=q.front();
        q.pop();
        TreeNode* currnode=curr.first;
        int currx=curr.second;
        coordinates[currx]=currnode->val;
        if(currnode->left){
            q.push({currnode->left,currx-1});
        }
        if(currnode->right){
            q.push({currnode->right,currx+1});
        }
    }
    
    for(auto node:coordinates){
        ans.push_back(node.second);
    }

    return ans;
}

// right side view 
vector<int>bottomview(TreeNode* root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    map<int,int>coordinates;
    queue<pair<TreeNode*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        auto curr=q.front();
        q.pop();
        TreeNode* currnode=curr.first;
        int currx=curr.second;
        coordinates[currx]=currnode->val;
        if(currnode->left){
            q.push({currnode->left,currx+1});
        }
        if(currnode->right){
            q.push({currnode->right,currx+1});
        }
    }
    
    for(auto node:coordinates){
        ans.push_back(node.second);
    }

    return ans;
}