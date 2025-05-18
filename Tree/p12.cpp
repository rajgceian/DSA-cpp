//check for balance tree.
#include<iostream>
#include<climits>
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

int height(Node *root,bool &valid){
    if(!root)
    return 0;

    int l=height(root->left,valid);
    int r=height(root->right,valid);
    if(abs(l-r)>1)
    valid=0;
    return 1+max(l,r);
}

bool isBalanced(Node *root){
    bool valid=1;
    height(root,valid);
    return valid;
}

int main(){
    Node *root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);

    cout<<"For balanced=1 and Not balanced=0"<<endl;
    cout<<"Tree is balanced or not:"<<isBalanced(root)<<endl;
}