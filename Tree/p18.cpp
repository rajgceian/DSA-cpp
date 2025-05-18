//Right view of binary tree.
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

void Rview(Node *root,int level,vector<int>&ans){
    if(!root)
    return;

    if(level==ans.size())
    ans.push_back(root->data);
    Rview(root->right,level+1,ans);
    Rview(root->left,level+1,ans);
}

vector<int>rightview(Node *root){
    vector<int>ans;
    if(!root)
    return ans;
    Rview(root,0,ans);
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
    
    vector<int>ans=rightview(root);
    cout<<"Right view of binary tree:";
    for(int data:ans){
        cout<<data<<" ";
    }
    return 0;
}