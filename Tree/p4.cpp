//pre-order post-order in-order
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
void preOrder(Node *root){
    if(root==NULL)
    return;

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node *root){
    if(root==NULL)
    return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(Node *root){
    if(root==NULL)
    return;

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
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
    cout<<"preOrder:";
    preOrder(root);
    cout<<"\ninOrder:";
    inOrder(root);
    cout<<"\npostOrder:";
    postOrder(root);
}