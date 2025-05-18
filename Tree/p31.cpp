//construct BST from preorder traversal.
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

Node *BST(vector<int>&preorder,int &index,int lower,int upper){
    if(index==preorder.size() || lower>preorder[index] || upper<preorder[index])
    return NULL;

    Node *root=new Node(preorder[index++]);
    root->left=BST(preorder,index,lower,root->data);
    root->right=BST(preorder,index,root->data,upper);
    return root;
}

Node *bstfrompreorder(vector<int>&preorder){
    int index=0;
    return BST(preorder,index,INT16_MIN,INT16_MAX);
}

void inorder(Node *root){
    if(!root)
    return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}

int main(){
    vector<int>preorder={8,5,1,7,10,12};
    Node *root=bstfrompreorder(preorder);
    cout<<"Inorder traversal of constructed BST:";
    inorder(root);
    cout<<endl;
    return 0;
    
}