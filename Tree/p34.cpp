//lowest common ancestor in a BST.
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

Node *LCA(Node *root,Node *n1,Node *n2){
    if(!root)
    return NULL;

    if(root->data>n1->data && root->data>n2->data)
    return LCA(root->left,n1,n2);
    else if(root->data<n1->data  && root->data<n2->data)
    return LCA(root->right,n1,n2);
    else
    return root;
}

int main(){
    Node *root=new Node(6);
    root->left=new Node(2);
    root->right=new Node(8);
    root->left->left=new Node(0);
    root->left->right=new Node(4);
    root->right->left=new Node(7);
    root->right->right=new Node(9);

    Node *n1=root->left  ; //2
    Node *n2=root->right; //8
    
    Node *lowestcommonancestotrs=LCA(root,n1,n2);
    cout<<"LCA: "<<lowestcommonancestotrs->data<<" ";
    return 0;

}