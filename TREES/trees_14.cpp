// max depth of binarty tree
#include<bits/stdc++.h>
using namespace std;

typedef struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
}node;

class Solution {
    public:
        void findmaxdep(int* currdep, int* maxdep, TreeNode* root) {
            if (root == NULL){
                return;
            }

            (*currdep)++; 
    
            if (root->left == NULL && root->right == NULL){
                if (*currdep > *maxdep)
                    *maxdep = *currdep;
            } 
            else {
                findmaxdep(currdep, maxdep, root->left);
                findmaxdep(currdep, maxdep, root->right);
            }
    
            (*currdep)--; // Backtrack after recursion
        }
    
        int maxDepth(TreeNode* root) {
            int maxdep=0;
            int currdep=0;
            if(root==NULL){
                return maxdep;
            }
            findmaxdep(&currdep,&maxdep,root);
            return maxdep;
        }
    };

// method 2 
int maxdepth(node* root){
    if(root==NULL){
        return 0;
    }
    int left=maxdepth(root->left)+1;
    int right=maxdepth(root->right)+1;
    return max(left,right);
}

// check for balanced binary tree
// method 1 : check at every node by finding height of left and right subtree at every node

bool checkbalaned1(node* root){
    // if there is no left or right subtree
    if(root==NULL){
        return true;
    }
    int lh=maxdepth(root->left);
    int rh=maxdepth(root->right);
    if(abs(lh-rh)>1){
        return false;
    }
    bool leftcheck=checkbalaned1(root->left);
    bool rightcheck=checkbalaned1(root->right);
    if(!leftcheck || !rightcheck){
        return false;
    }
    return true;
}

// method 2 : blend both the methods

int checkbalanced2(node* root){
    if(root==NULL){
        return 0;
    }
    int lh=checkbalanced2(root->left);
    int rh=checkbalanced2(root->right);
    if(abs(lh-rh)>1){
        return -1;
    }
    if(lh==-1 || rh==-1){
        return -1;
    }
    return 1+max(lh,rh);
}

// diameter of binary tree

void diameter1(node *root,int *maxx){
    if(root==NULL){
        return;
    }
    int lh=maxdepth(root->left);
    int rh=maxdepth(root->right);
    if(*maxx<lh+rh){
        *maxx=lh+rh;
    }
    diameter1(root->left,maxx);
    diameter1(root->right,maxx);
}

int finddmtr(node* root){
    int maxx=0;
    diameter1(root,&maxx);
    return maxx;
}

// method 2 : optimized : blend

int finddia(node* root,int* maxi){
    if(root==NULL){
        return 0;
    }
    int lh=finddia(root->left,maxi);
    int rh=finddia(root->right,maxi);
    *maxi=max(*maxi,lh+rh);
    return 1+max(lh,rh);
}
int diameter2(node* root){
    int maxx=0;
    maxx=finddia(root,&maxx);
    return maxx;
}


// max path sum of tree
int maxpathsum1(node* root,int* maxx){
    if(root==NULL){
        return 0;
    }
    int leftsum=maxpathsum1(root->left,maxx);
    int rightsum=maxpathsum1(root->right,maxx);
    int curr=leftsum+rightsum+root->val;
    if(curr>*maxx){
        *maxx=curr;
    }
    return root->val+max(leftsum,rightsum);

}

// leetcode solution with optimizations
class Solution {
    public:
        int pathsum(TreeNode* root,int& maxi){
            if(root==NULL){
                return 0;
            }
            int lsum=pathsum(root->left,maxi);
            int rsum=pathsum(root->right,maxi);
            int curr=root->val;
            if(lsum>=0 && rsum>=0){
                curr+=rsum+lsum;
            }
            else if(lsum>=0){
                curr+=lsum;
            }
            else if(rsum>0){
                curr+=rsum;
            }
            maxi=max(maxi,curr);
            int maxside=max(lsum,rsum);
            if(maxside>=0){
                return maxside+root->val;
            }
            else{
                return root->val;
            }
        }
    
        int maxPathSum(TreeNode* root) {
            
            int maxi=INT_MIN;
            pathsum(root,maxi);
            return maxi;
            
        }
    };

    // identical trees or not
bool identical(node* root1,node* root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    if(root1!=NULL || root2!=NULL){
        return false;
    }
    bool checkleft=identical(root1->left,root2->left);
    bool checkright=identical(root1->right,root2->right);

    if(checkleft==false || checkright==false){
        return false;
    }
    return true;
}

// root to leaf node path
void findpath(node* root,vector<int>&ans,int leaf){
    ans.push_back(root->val);
    if(root->left==NULL && root->right==NULL && root->val!=leaf){
        ans.pop_back();
        return;
    }
    
    if(root->val==leaf){
        return;
    }
   
    else{
        findpath(root->left,ans,leaf);
        findpath(root->right,ans,leaf);
    }
    return;
}
vector<int>roottoleaf(node* root,int leaf){
    vector<int>ans;
    findpath(root,ans,leaf);
    return ans;
}

// leetcode: sum root to leaf numbers
void findsum(node* root,int *sum,int curr){
    if(root==NULL){
        return;
    }
    curr=curr*10+root->val;
    if(root->left==NULL && root->right==NULL){
        *sum+=curr;
        curr=curr/10;
        return;
    }
    findsum(root->left,sum,curr);
    findsum(root->right,sum,curr);
    curr=curr/10;
    return;

}
int rootleaf(node* root){
    int sum=0;
    int curr=0;
    findsum(root,&sum,curr);
    return sum;
}

// leetcode : binary tree paths
void findpaths(node* root,vector<string>&paths,vector<int>curr){
    if(root==NULL){
        return;
    }
    curr.push_back(root->val);
    if(root->left==NULL && root->right==NULL){
        int size=curr.size();
        string s;
        int i=0;
        for(i=0;i<curr.size()-1;i++){
            s+=to_string(curr[i]);
            s+='->';
        }
        s+=to_string(curr[i]);

        paths.push_back(s);
        curr.pop_back();
        return;
    }

    findpaths(root->left,paths,curr);
    findpaths(root->right,paths,curr);
    curr.pop_back();
    return;
    
}
vector<string>roottoleafpaths(node* root){
    vector<string>paths;
    vector<int>curr;
    findpaths(root,paths,curr);
    return paths;
}

// lowest common ancestor
// brute force, store path to one node in an array and find the last common element by comparing the path for 
// the node with the path of the first element

bool findpath(node* root,node* target,vector<node*>&path){
    if(root==NULL){
        return false;
    }
    path.push_back(root);
    if(root==target){
        return true;
    }
    bool left=findpath(root->left,target,path);
    bool right=findpath(root->right,target,path);
    if(left || right){
        return true;
    }
    path.pop_back();
    return false;
}

node* lca(node* root,node* q,vector<node*> path1,int index){
    if(root==q && path1[index]==root){
        return q;
    }
    if(root==q){
        return path1[index-1];
    }
    if(root->val==path1[index]->val){
        index++;
    }
    if(root->left==NULL && root->right==NULL){
        return NULL;
    }
    node* left=lca(root->left,q,path1,index);
    node* right=lca(root->right,q,path1,index);
    if(left!=NULL){
        return left;
    }
    else if(right!=NULL){
        return right;
    }
    return NULL;
}
node* findlca(node* root,node* p,node* q){
    vector<node*>path1;
    findpath(root,p,path1);
    node* ans=lca(root,q,path1,0);
    return ans;

}

// maximum width of binary tree
int width(node* root){
    int maxwid=0;
    if(root==NULL){
        return maxwid;
    }
    queue<pair<node*,int>>mpp;
    mpp.push({root,1});
    maxwid++;
    while(!mpp.empty()){
        int levelwid=0;
        int size=mpp.size();
        for(int i=0;i<size;i++){
            pair<node*,int>curr=mpp.front();
            mpp.pop();
            if(curr.first->left){
                mpp.push({curr.first->left,(2*(i-1)+1)});
            }
            if(curr.first->right){
                mpp.push({curr.first->right,(2*(i-1)+1)});
            }
        }
        int currsize=mpp.back().second-mpp.front().second;
        if(currsize>maxwid){
            maxwid=currsize;
        }
    }
    return maxwid;
}

//children sum property

int childsum(node* root){
    if(root->left==NULL && root->right==NULL){
        return root->val;
    }
    int l;
    if(root->left){
        l=root->left->val;
    }
    else{
        l=0;
    }
    int r;
    if(root->right){
        r=root->right->val;
    }
    else{
        r=0;
    }
    if((root->val)>(l+r)){
        root->left->val=root->val;
        root->right->val=root->val;
    }
    else if((root->val)<(l+r)){
        root->val=root->left->val+root->right->val;
    }
    int left=childsum(root->left);
    int right=childsum(root->right);
    root->val=left+right;
    return root->val;
}

// nodes at a distance k from a given node in binary tree

//step 1: mark parents
void markparents(TreeNode* root,map<TreeNode*,TreeNode*>& parent){
        if(root==NULL){
            return;
        }
        if(root->left){
            parent.insert({root->left,root});
        }
        if(root->right){
            parent.insert({root->right,root});
        }
        markparents(root->left,parent);
        markparents(root->right,parent);
        return;
    }

    void getnodesk(TreeNode* root,map<TreeNode*,TreeNode*>parent,vector<int>& ans,int k,TreeNode* target,int origk,unordered_set<TreeNode*>& visited){
        if(visited.count(root)){
            return;
        }
        if(root==NULL){
            return;
        }
        if(root==target && k==0){
            return;
        }
        if(k==0){
            ans.push_back(root->val);
            k++;
            return;
        }
        visited.insert(root);
        getnodesk(root->left,parent,ans,k-1,target,origk,visited);
        getnodesk(root->right,parent,ans,k-1,target,origk,visited);
        
        if(parent[root]!=NULL){
            getnodesk(parent[root],parent,ans,k-1,target,origk,visited);
        }
        
        k=origk;
        return;
    }
    vector<int> distanceK(TreeNode* root,TreeNode* target,int k){
        map<TreeNode*,TreeNode*> parent;
        parent[root]=NULL;
        
        markparents(root,parent);
        vector<int>ans;
        unordered_set<TreeNode*> visited;
        getnodesk(target,parent,ans,k,target,k,visited);
        return ans;
    }

void markparents(TreeNode* root,map<TreeNode*,TreeNode*>& parent){
        if(root==NULL){
            return;
        }
        if(root->left){
            parent.insert({root->left,root});
        }
        if(root->right){
            parent.insert({root->right,root});
        }
        markparents(root->left,parent);
        markparents(root->right,parent);
        return;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
       vector<int>ans;
       map<TreeNode*,TreeNode*>parent;
       parent[root]=NULL;
       markparents(root,parent);
       queue<TreeNode*> q;
       q.push(target);
       map<TreeNode*,int>visited;
       visited[target]=1;
       while(!q.empty()){
            int size=q.size();
            int count=0;
            for(int i=0;i<size;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left && visited[temp->left]==0){
                    q.push(temp->left);
                    visited[temp->left]=1;
                }
                if(temp->right && visited[temp->right]==0){
                    q.push(temp->right);
                    visited[temp->right]=1;
                }
                if(parent[temp] && visited[parent[temp]]==0){
                    q.push(parent[temp]);
                    visited[parent[temp]]=1;
                }
            }
            count++;
            if(count==k){
                for(int i=0;i<q.size();i++){
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                break;
            }
       }
       return ans;
    }

// burn a tree : using bfs
class Solution {
public:
    node* findnode(node* root, int start) {
        if (root->val == start) {
            return root;
        }
        if (root == NULL) {
            return NULL;
        }
        node* l = findnode(root->left, start);
        node* r = findnode(root->right, start);
        if (l != NULL) {
            return l;
        }
        if (r != NULL) {
            return r;
        }
        return NULL;
    }

    void markparents(node* root, map<node*, node*>& parents) {
        if (root == NULL) {
            return;
        }
        if (root->left) {
            parents[root->left] = root;
        }
        if (root->right) {
            parents[root->right] = root;
        }
        markparents(root->left, parents);
        markparents(root->right, parents);
        return;
    }

    int amountOfTime(node* root, int start) {
        //using BFS
        map<node*, node*> parents;
        parents[root] = NULL;
        markparents(root, parents);

        node* target = findnode(root, start);
        set<node*> visited;
        visited.insert(target);

        queue<node*> q;
        q.push(target);
        int burnt = 0;
        int count = 0;
        while (!q.empty()) {
            int size = q.size();
            burnt = 0;
            for (int i = 0; i < size; i++) {

                node* curr = q.front();
                q.pop();
                if (curr->left && visited.count(curr->left) == 0) {
                    q.push(curr->left);
                    visited.insert(curr->left);
                    burnt++;
                }
                if (curr->right && visited.count(curr->right) == 0) {
                    q.push(curr->right);
                    visited.insert(curr->right);
                    burnt++;
                }
                if (parents[curr] && visited.count(parents[curr]) == 0) {
                    q.push(parents[curr]);
                    visited.insert(parents[curr]);
                    burnt++;
                }
            }
            if (burnt > 0) {
                count++;
            }
        }
        return count;
    }
};
