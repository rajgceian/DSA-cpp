//Top view of binary tee.
#include<iostream>
#include<vector>
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

void Tview(Node *root,int pos,vector<int>&ans,vector<int>&level,int l){
    if(!root)
    return ;

    if(level[pos]>l){
        ans[pos]=root->data;
        level[pos]=l;
    }
    Tview(root->left,pos-1,ans,level,l+1);
    Tview(root->right,pos+1,ans,level,l+1);
}

vector<int>topview(Node *root){
    int l=0,r=0;
    find(root,0,l,r);
    vector<int>ans(r-l+1);
    vector<int>level(r-l+1,INT16_MAX);
    Tview(root,-1*l,ans,level,0);
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
    
    vector<int>ans=topview(root);
    cout<<"Top view of binary tree:";
    for(int data:ans){
        cout<<data<<" ";
    }
    return 0;
}