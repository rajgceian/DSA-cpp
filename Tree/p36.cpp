//check whether BST contains dead end or not.
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

bool dead(Node *root,int lower,int upper){
    if(!root)
    return 0;

    if(!root->left && !root->right){
        if(root->data-lower==1 && upper-root->data==1)
        return 1;
        else
        return 0;
    }

    return dead(root->left,lower,root->data)||dead(root->right,root->data,upper);
}

bool isdead(Node *root){
    return dead(root,0,INT16_MAX);
}

int main(){
    Node *root=new Node(6);
    root->left=new Node(2);
    root->right=new Node(8);
    root->left->left=new Node(0);
    root->left->right=new Node(4);
    root->right->left=new Node(7);
    root->right->right=new Node(9);

    cout<<isdead(root)<<endl;

}