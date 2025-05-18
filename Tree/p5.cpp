//size of binary tree
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

int getSize(Node *root){
    if(root==NULL)
    return 0;
    return(1+getSize(root->left)+getSize(root->right));
}

Node *BinaryTree(){
    Node *root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->right->left=new Node(5);
    root->right->right=new Node(6);
    return root;
}

int main(){
    Node *root=BinaryTree();
    cout<<"size of tree: "<<getSize(root)<<endl;
    return 0;
}
