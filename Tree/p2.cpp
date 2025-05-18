//creation of binary tree using recurssion.
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

Node *BinaryTree(){
    int x;
    cin>>x;
    if(x==-1)
    return NULL;
    Node *temp=new Node(x);
    cout<<"enter the left child of "<<temp->data<<" :";
    temp->left=BinaryTree();
    cout<<"enter the right child of "<<temp->data<<" :";
    temp->right=BinaryTree();
    return temp;
}

int main(){
    cout<<"enter the root node:";
    Node *root;
    root=BinaryTree();
}