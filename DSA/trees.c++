#include<bits/stdc++.h>
using namespace std;

class treenode{
    public:
    int data;
    treenode* left;
    treenode* right;
    treenode(int data){
        this->data=data;
        left=nullptr;
        right=nullptr;
    }
};

// iterative approach for preorder trasversal of tree
vector<int>preorder(treenode* root){
    vector<int>prearr;
    if(root==NULL){
        return prearr;
    }
    stack<treenode*>st;  // stack to store nodes temporarily
    st.push(root);    // pushing the head root
    while(!st.empty()){
        root=st.top();
        st.pop();
        prearr.push_back(root->data);
        if(root->right!=NULL){
            st.push(root->right);
        }
        if(root->left!=NULL){
            st.push(root->left);
        }
    }
    return prearr;
}

// iterative approach for inorder trasversal of tree

vector<int>preorder(treenode* root){
    treenode* node=root;
    vector<int>inarr;
    if(node==NULL){
        return inarr;
    }
    stack<treenode*>st;  // stack to store nodes temporarily
    while(true){
        if(node!=NULL){
            st.push(node);
            node=node->left;
        }
    
        else{
            if(st.empty()==true){
                break;
            }
            node=st.top();
            st.pop();
            inarr.push_back(node->data);
            node=node->right;
        }
    }
    return inarr;

}

// iterative approach for postorder trasversal of tree

vector<int>postorder(treenode* root){
    vector<int>postarr;
    if(root==NULL){
        return postarr;
    }
    stack<treenode*>st1;  // stack to store nodes temporarily
    stack<treenode*>st2;  // to store end result
    st1.push(root);
    while(!st1.empty()){
        root=st1.top();
        st1.pop();
        st2.push(root);
        if(root->left!=NULL){
            st1.push(root->left);
        }
        if(root->right!=NULL){
            st1.push(root->right);
    
        }
        while(!st2.empty()){
            postarr.push_back(st2.top()->data);
            st2.pop();
        }   
    }
    return postarr;

}

// recursive approach for trasveral

// pre order
vector<int>rpreorder(treenode* root){
    treenode* node=root;
    vector<int>ans;
    if(node==NULL){
        return ans;
    }
    ans.push_back(node->data);
    rpreorder(node->left);
    rpreorder(node->right);
    return ans;
}

// postorder
vector<int>rpostorder(treenode* root){
    treenode* node=root;
    vector<int>ans;
    if(node==NULL){
        return ans;
    } 
    rpostorder(node->left);
    rpostorder(node->right);
    ans.push_back(node->data);
    return ans;
}

// inorder
vector<int>rinorder(treenode* root){
    treenode* node=root;
    vector<int>ans;
    if(node==NULL){
        return ans;
    } 
    rinorder(node->left);
    ans.push_back(node->data);
    rinorder(node->right);
    return ans;
}

// LEVEL ORDER TRASVERSAL

vector<vector<int>>levelorder(treenode* root){
    vector<vector<int>>ans;
    if(root==NULL){
        return ans;
    }
    queue<treenode*> q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        vector<int>level;
        for(int i=0;i<size;i++){
            treenode* node=q.front();
            q.pop();
            if(node->left!=NULL){
                q.push(node->left);
            }
            if(node->right!=NULL){
                q.push(node->right);
            }
            level.push_back(node->data);
        }
        ans.push_back(level);
    }
    return ans;
}

class Solution {
public:
    int maxDepth(treenode* root) {
        treenode* node=root;
        if(node==NULL){
            return 0;        
        }
        int lheight=maxDepth(node->left);
        int rheight=maxDepth(node->right);
        return 1+max(lheight,rheight);

    }
};

// check if tree is balanced
int findh(treenode* root){
    if(root==NULL){
        return 0;
    }
    int lheight=findh(root->left);
    int rheight=findh(root->right);
    return 1+max(lheight,rheight);
}

bool check(treenode* root){
    if(root==NULL){
        return true;
    }
    int lh=findh(root->left);
    int rh=findh(root->right);
    if(abs(lh-rh)>1){
        return false;
    }

    bool l=check(root->left);
    bool r=check(root->right);
    if(!l || !r){
        return false;
    }
    return true;
}

// METHOD 2 INCORPORATING WITHIN THE CODE OF MAX DEPTH

int depth(treenode* root){
    if(root==NULL){
        return 0;
    }
    int lh=depth(root->left);
    int rh=depth(root->right);
    if((lh==-1) || (rh==1)) {
        return -1;
    } 
    if(abs(lh-rh)>1){
        return -1;
    }
    return 1+max(lh,rh);
}


// find diameter of a tree  tc: n^2

int diameter(treenode* root,int max=0){
    if(root==NULL){
        return 0;
    }

    int l=findh(root->left);
    int r=findh(root->right);
    if(l+r-1>max){
        max=l+r-1;
    }
    diameter(root->left);
    diameter(root->right);
    return max;
}

int diameter2(treenode* root){
    int diameter=0;
    findh(root,diameter);
    return diameter;
}

int findh(treenode* root,int& diameter){
    if(root==NULL){
        return 0;
    }
    int l=findh(root->left);
    int r=findh(root->right);
    diameter=max(diameter,l+r);  // as far as diameter is concerned, this function is being only used to change the value of diameter
    return 1+max(l,r);
}

class Solution {
public:
    int sum(treenode* root,int& maxi){
        if(root==NULL){
            return 0;
        }
        int l=max(0,sum(root->left,maxi));
        int r=max(0,sum(root->right,maxi));
        maxi=max(maxi,l+r+root->data);
        return max(l,r)+root->data;
    }

    int maxPathSum(treenode* root) {
        
        int maxi=INT_MIN;
        sum(root,maxi);
        return maxi;
        
    }
};

// identical trees or not

bool identical(treenode* root1,treenode* root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    if(root1==NULL || root2==NULL){
        return false;
    }
    if(root1->data!=root2->data){
        return false;
    }
    
    bool l=identical(root1->left,root2->left);
    bool r=identical(root1->right,root2->right);
    if(!l || !r){
        return false;
    }
    return true;
}

// zigzag transversal

vector<vector<int>> zigzag(treenode* root){
    vector<vector<int>>ans;
    if(root==NULL){
        return ans;
    }
    bool ltor=true;
    queue<treenode*>q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        vector<int>temp;
        for(int i=0;i<size;i++){
            treenode* node=q.front();
            q.pop();
            int index=ltor?i:size-i-1;
            temp[index]=node->data;
            if(node->left!=NULL){
                q.push(node->left);
            }
            if(node->right!=NULL){
                q.push(node->right);
            }
        }
        ltor=!ltor;
        ans.push_back(temp);
    }
    return ans;
}


// boundary traversal

void addleftbound(treenode* root,vector<int>& res){
    treenode* current=root->left;
    while(current!=NULL){
        if(!isleaf(current)){
            res.push_back(current->data);
        }
        if(current->left!=NULL){
            current=current->left;
        }
        else{   // using else because we don't have to add right until left exists
            current=current->right;
        }
    }
}

void addrightbound(treenode* root,vector<int>& res){
    stack<int> temp;
    treenode* current=root->right;
    while(current!=NULL){
        if(!isleaf(current)){
            temp.push(current->data);
        }
        if(current->right!=NULL){
            current=current->right;
        }
        else{
            current=current->left;
        }
    }
    while(!temp.empty()){
        res.push_back(temp.top());
        temp.pop();
    }
}

void addleaves(treenode* root,vector<int>& res){
    if(isleaf(root)){
        res.push_back(root->data);
    }
    if(root->left!=NULL){
        addleaves(root->left,res);
    }
    if(root->right!=NULL){
        addleaves(root->right,res);
    }
}

bool isleaf(treenode* root){
    return (!root->left && !root->right);
}
vector<int>boundary(treenode* root){
    vector<int>res;
    if(root==NULL){
        return res;
    }
    if(!isleaf(root)){
        res.push_back(root->data);
    }
    addleftbound(root,res);
    addleaves(root,res);
    addrightbound(root,res);
    return res;
}

// vertical traversal  : iterative method

vector<vector<int>> vertical(treenode* root){
    map<int,map<int,multiset<int>>>nodes;
    queue<pair<treenode*,pair<int,int>>> todo;
    todo.push({root,{0,0}});
    while(!todo.empty()){
        auto p=todo.front();
        todo.pop();
        treenode* node=p.first;
        int x=p.second.first;
        int y=p.second.second;
        nodes[x][y].insert(node->data);
        if(node->left){
            todo.push({node->left,{x-1,y+1}});
        }
        if(node->right){
            todo.push({node->right,{x+1,y+1}});
        }
    }
    vector<vector<int>>ans;
    for(auto p:nodes){
        vector<int> col;
        for(auto q:p.second){
            col.insert(col.end(),q.second.begin(),q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}

// top view of binary tree

vector<int> top(treenode* root){
    map<int,int>mpp;
    queue<pair<treenode*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        auto p=q.front();
        q.pop();
        treenode* node=p.first;
        int vertical=p.second;
        if(mpp.find(vertical)==mpp.end()){
            mpp.insert({vertical,node->data});
        }
        if(node->left){
            q.push({node->left,vertical-1});
        }
        if(node->right){
            q.push({node->right,vertical+1});
        }
    }
    vector<int>ans;
    for(auto it:mpp){
        ans.push_back(it.second);
    }
    return ans;
}

vector<int> bottom(treenode* root){
    map<int,int>mpp;
    queue<pair<treenode*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        auto p=q.front();
        int vertical=p.second;
        treenode* node=p.first;
        q.pop();
        mpp.insert(vertical,node->data);
        if(node->left){
            q.push({node->left,vertical-1});
        }
        if(node->right){
            q.push({node->right,vertical+1});
        }
    }
    vector<int>ans;
    for(auto it:mpp){
        ans.push_back(it.second);
    }
    return ans;
}

// right view : iterative approach
vector<int>right(treenode* root){
    map<int,int>mpp;
    queue<pair<treenode*,int>>q;
    vector<int>ans;
    q.push({root,0});
    while(!q.empty()){
        auto p=q.front();
        int level=p.second;
        treenode* node=p.first;
        q.pop();
        if(mpp.find(level)==mpp.end()){
            mpp.insert(level,node->data);
        }
        if(node->right){
            q.push({node->right,level+1});
        }
        if(node->left){
            q.push({node->left,level+1});
        }
    }
    for(auto it: mpp){
        ans.push_back(it.second);
    }
    return ans;
}

// left view : iterative approach

vector<int> left(treenode* root){
    map<int,int>mpp;
    queue<pair<treenode*,int>>q;
    q.push({root,0});
    vector<int>ans;
    while(!q.empty()){
        auto p=q.front();
        int level=p.second;
        treenode* node=p.first;
        mpp[level]=node->data;
        if(node->right){
            q.push({node->right,level+1});
        }
        if(node->left){
            q.push({node->left,level+1});
        }
    }
    for(auto it: mpp){
        ans.push_back(it.second);
    }
    return ans;
}

//  recursive approach

void rside(treenode* root,vector<int>& ans,int level){
    if(ans.size()==level){
        ans.push_back(root->data);
    }
    rside(root->right,ans,level+1);
    rside(root->left,ans,level+1);
}
vector<int> right(treenode* root){
    vector<int>ans;
    rside(root,ans,0);
    return ans;
}

void lside(treenode* root,vector<int>& ans,int level){
    if(ans.size()==level){
        ans.push_back(root->data);
    }
    lside(root->left,ans,level+1);
    lside(root->right,ans,level+1);
}
vector<int> left(treenode* root){
    vector<int>ans;
    lside(root,ans,0);
    return ans;
}

bool getpath(treenode* root,vector<int>& arr,int node){
    if(root==NULL){
        return false;
    }
    arr.push_back(root->data);
    if(root->data==node){
        return true;
    }
    if(getpath(root->left,arr,node)|| getpath(root->right,arr,node)){
        return true;
    }
    arr.pop_back();
    return false;

}

vector<int> nodepath(treenode* root,int node){
    vector<int>arr;
    getpath(root,arr,node);
    return arr;
}

// lowest common ancestor
treenode* lca(treenode* root,treenode* a,treenode* b){
    if(root==NULL || root==a || root==b){
        return root;
    }
    treenode* left=lca(root->left,a,b);
    treenode* right=lca(root->right,a,b);
    if(left==NULL && right==NULL){
        return NULL;
    }
    else if(left==NULL){
        return right;
    }
    else if(right==NULL){
        return left;
    }
    else{
        return root;
    }

}

// maximum width

int widthmax(treenode* root){
    if(root==NULL){
        return 0;
    }
    int ans=0;
    queue<pair<treenode*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        int size=q.size();
        int mmin=q.front().second;
        int first,last;
        for(int i=0;i<size;i++){
            int cur_id=q.front().second-mmin;
            q.pop();
            if(i==0){
                first=cur_id;
            }
            if(i==size-1){
                last=cur_id;
            }
            if(root->left){
                q.push({root->left,cur_id*2+1});
            }
            if(root->right){
                q.push({root->right,cur_id-2+2});
            }
        }
        ans=max(ans,last-first+1);
    }
    return ans;
}


// print all element k distance apart from parent node

void markparents(treenode* root,map<treenode*,treenode*>& parent,treenode* target){
    queue<treenode*>q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            treenode* node=q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
                parent.insert(node->left,node);
            }
            if(node->right){
                q.push(node->right);
                parent.insert(node->right,node);
            }
        }
    }
}

vector<int> ans(treenode* root,treenode* target,int k){
    int count=0;
    vector<int>arr;
    map<treenode*,treenode*>parent;
    markparents(root,parent,target);

    map<treenode*,bool>visited;
    queue<treenode*>q;
    q.push(target);
    visited[target]=true;
    while(!q.empty()){
        int size=q.size();
        if(count==k){
            break;
        }
        for(int i=0;i<size;i++){
            treenode* current=q.front();
            q.pop();
            if(current->left && !visited[current->left]){
                q.push(current->left);
                visited[current->left]=true;
            }
            if(current->right && !visited[current->right] ){
                q.push(current->right);
                visited[current->right]=true;
            }
            if(parent[current] && !visited[parent[current]]){
                q.push(parent[current]);
                visited[parent[current]]=true;
            }
        }
        count++;
    }
    while(!q.empty()){
        treenode* node=q.front();
        q.pop();
        arr.push_back(node->data);
    }
    return arr;
}

// lowest common ancestor
treenode* findlca(treenode* root,int x,int y){
    if(root->left==NULL && root->right==NULL){
        return NULL;
    }
    if(root->data==x|| root->data==y){
        return root;
    }
    root->left=findlca(root->left,x,y);
    root->right=findlca(root->right,x,y);
    if(root->left==NULL){
        return root->right;
    }
    else if(root->right==NULL){
        return root->left;
    }
    else{
        return root;
    }
}