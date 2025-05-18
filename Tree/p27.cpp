//check BST.
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

Node *insert(Node *root,int target){
    if(root==NULL){
        Node *temp=new Node(target);
        return temp;
    }
    if(target<=root->data)
    root->left=insert(root->left,target);
    else
    root->right=insert(root->right,target);
    return root;
}

bool BST(Node *root,int &prev){
    if(root==NULL)
    return 1;

    bool l=BST(root->left,prev);
    if(l==0)
    return 0;
    if(root->data<=prev)
    return 0;
    prev=root->data;
    return BST(root->right,prev);
}

bool isBST(Node *root){
    int prev=INT16_MIN;
    return BST(root,prev);
}

int main(){
    int arr[]={6,17,3,5,11,18,2,1,20,14};
    Node *root=NULL;
    for(int i=0;i<10;i++)
    root=insert(root,arr[i]);
    cout<<isBST(root)<<endl;
}


