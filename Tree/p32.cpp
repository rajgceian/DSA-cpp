//construct BST from postorder.
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

Node *BST(int post[],int &index,int lower,int upper){
     if(index<0 || post[index]<lower || post[index]>upper)
     return NULL;

     Node *root=new Node(post[index--]);
     root->right=BST(post,index,root->data,upper);
     root->left=BST(post,index,lower,root->data);
     return root;
}

Node *constructTree(int post[],int size){
    int index=size-1;
    return BST(post,index,INT16_MIN,INT16_MAX);
}

void inorder(Node *root){
    if(!root)
    return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}

int main(){
    int post[]={1,7,5,50,40,10};
    int size=6;
    Node *root=constructTree(post,size);
    cout<<"Inoreder traversal of constructed BST :";
    inorder(root);
    cout<<endl;
    return 0;

}