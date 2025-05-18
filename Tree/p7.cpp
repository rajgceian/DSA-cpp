//count no of leaves node.
#include<iostream>
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

int countleaf(Node *root){
    if(!root)
    return 0;

    //leaf node
    if(!root->left && !root->right)
    return 1;
    //non leaf
    return(countleaf(root->left)+countleaf(root->right));
}

Node *BinaryTree(){
    int x;
    cin>>x;
    if(x==-1)
    return NULL;
    Node *temp=new Node(x);
    cout<<"enter the left child of "<<x<<" :";
    temp->left=BinaryTree();
    cout<<"enter the right child of "<<x<<" :";
    temp->right=BinaryTree();
    return temp;
}

int main(){
    cout<<"enter the root node:";
    Node *root;
    root=BinaryTree();
    cout<<"Number of leaves node is "<<countleaf(root)<<endl;
    return 0;
}