//sum of binary tree.
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

int sumBT(Node *root){
    if(!root)
    return 0;

    return(root->data+sumBT(root->left)+sumBT(root->right));   
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
    cout<<"sum of binary tree:"<<sumBT(root)<<endl;
    return 0;
}