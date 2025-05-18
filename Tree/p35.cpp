//print BST element in given range.
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

void find(Node *root,int low,int high){
    if(!root)
    return ;

    if(root->data>low)
    find(root->left,low,high);
     if(root->data>=low && root->data<=high)
    cout<<root->data<<" ";
    if(root->data<high) 
    find(root->right,low,high);
}

int main(){
    Node *root=new Node(6);
    root->left=new Node(2);
    root->right=new Node(8);
    root->left->left=new Node(0);
    root->left->right=new Node(4);
    root->right->left=new Node(7);
    root->right->right=new Node(9);

    int low=3;
    int high=8;
    cout<<"Elements in range["<<low<<" ,"<<high<<"]:";
    find(root,low,high);
    cout<<endl;
    return 0;
}