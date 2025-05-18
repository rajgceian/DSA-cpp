//count non leaves nodes in a tree.
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

int countNonleaf(Node *root){
    if(root==NULL)
    return 0;

    //leaf node
    if(root->left==NULL && root->right==NULL)
    return 0;
    //Non leaf node
    return (1+countNonleaf(root->left)+countNonleaf(root->right));
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
    cout<<"Number of non leaves node is:"<<countNonleaf(root)<<endl;
    return 0;
 }