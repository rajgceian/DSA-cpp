//Mirror tree or not.
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

void Mirror(Node *root){
    if(!root)
    return ;

    Node *temp=root->left;
    root->right=root->left;
    root->left=temp;

    Mirror(root->left);
    Mirror(root->right);
}

int main(){
    Node *root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
}