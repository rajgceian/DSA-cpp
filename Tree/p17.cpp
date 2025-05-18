//left view of binary tree.
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

Node *BinaryTree(){
    Node *root=new Node(1);
    root->left=new Node(2);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->left->right->left=new Node(7);
    root->left->right->right=new Node(8);
    root->left->right->right->right=new Node(9);
    root->right=new Node(3);
    root->right->right=new Node(6);
    return root;
}

void Lview(Node *root,int level,vector<int>&ans){
    if(!root)
    return;

    if(level==ans.size())
    ans.push_back(root->data);
    Lview(root->left,level+1,ans);
    Lview(root->right,level+1,ans);
}

vector<int>leftview(Node *root){
    vector<int>ans;
    if(!root)
    return ans;
    Lview(root,0,ans);
    return ans;
}

int main(){
    Node *root;
    root=BinaryTree();
    vector<int>ans=leftview(root);
    cout<<"Left view of binary tree:";
    for(int data:ans){
        cout<<data<<" ";
    }
    return 0;
}