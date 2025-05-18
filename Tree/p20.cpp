//Bottom view of binary tree.
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Node{
    public:
    int data;
    Node *left,*right;
    Node(int value){
        data=value;
        left=right=NULL;
    }
};

void find(Node *root,int pos,int &l,int &r){
    if(!root)
    return;

    l=min(pos,l);
    r=max(pos,r);
    find(root->left,pos-1,l,r);
    find(root->right,pos+1,l,r);
}

void Bview(Node *root,int pos,vector<int>&ans,vector<int>&level,int l){
    if(!root)
    return;

    if(!ans[pos] || l>=level[pos]){
        ans[pos]=root->data;
        level[pos]=l;
    }
    Bview(root->left,pos-1,ans,level,l+1);
    Bview(root->right,pos+1,ans,level,l+1);
}

vector<int>bottomview(Node *root){
    int l=0,r=0;
    find(root,0,l,r);
    vector<int>ans(r-l+1);
    vector<int>level(r-l+1,0);
    Bview(root,-1*l,ans,level,0);
    return ans;
}
int main(){
    Node *root=new Node(1);
    root->left=new Node(2);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right=new Node(3);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    root->right->left->left=new Node(9);
    root->right->right->right=new Node(10);
    root->left->left->left=new Node(8);
    root->left->left->left->right=new Node(11);
     
    vector<int>ans=bottomview(root);
    cout<<"Bottom view of binary tree:";
    for(int data:ans){
        cout<<data<<" ";
    }
    return 0;
}