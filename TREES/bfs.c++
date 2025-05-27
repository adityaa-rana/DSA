#include<bits/stdc++.h>
using namespace std;

// bfs traversal
typedef struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
}node;

vector<vector<int>> levelorder(node* root){
    vector<vector<int>> bfs;
    if(root==NULL){
        return bfs;
    }
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        vector<int>level;
        for(int i=0;i<size;i++){
            node* curr=q.front();
            q.pop();
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
            level.push_back(curr->val);
        }
        bfs.push_back(level);
    }
    return bfs;
}

// zigzag traversal
vector<vector<int>> zigzag(node* root){
    vector<vector<int>>ans;
    if(root==NULL){
        return ans;
    }
    queue<node*>q;
    int count=1;
    q.push(root);
    while(!q.empty()){
        vector<int>level;
        int size=q.size();
        for(int i=0;i<q.size();i++){
            node* curr=q.front();
            q.pop();
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
            level.push_back(curr->val);
        }
        if(count%2==0){
            level.reverse();
        }
        ans.push_back(level);
        count++;
    }
}