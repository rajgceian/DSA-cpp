//Boundary traversal in a binary tree.
#include<iostream>
#include<climits>
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

void leftsub(Node *root,vector<int>&ans){
    if(!root || (!root->left && !root->right))
    return;

    ans.push_back(root->data);
    if(root->left)
    leftsub(root->left,ans);
    else
    leftsub(root->right,ans);
}

void leaf(Node *root,vector<int>&ans){
    if(!root)
    return;

    if(!root->left && !root->right){
    ans.push_back(root->data);
    return;
}
    leaf(root->left,ans);
    leaf(root->right,ans);
}

void rightsub(Node *root,vector<int>&ans){
    if(!root || (!root->left && !root->right))
    return;

    if(root->right)
    rightsub(root->right,ans);
    else
    rightsub(root->left,ans);
    ans.push_back(root->data);
}

vector<int>boundary(Node *root){
    vector<int>ans;
    ans.push_back(root->data);
    if(root->left || root->right)
    leftsub(root->left,ans);
    leaf(root,ans);
    rightsub(root->right,ans);
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

    vector<int>ans=boundary(root);
    cout<<"Boundary traversal:";
    for(int data:ans){
        cout<<data<<" ";
    }
    return 0;
}