//deletion in a binary search tree.
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
    if(!root){
        Node *temp=new Node(target);
        return temp;
    }
    if(target<root->data)
    root->left=insert(root->left,target);
    else
    root->right=insert(root->right,target);

    return root;
}

Node *deleteNode(Node *root,int target){
    if(!root)
    return NULL;

    if(root->data>target){
        root->left=deleteNode(root->left,target);
        return root;
    }

    else if(root->data<target){
        root->right=deleteNode(root->right,target);
        return root;
    }

    else{
        //leaf node.
        if(!root->left && !root->right){
            delete root;
            return NULL;
        }
        //1 child exist.
        else if(!root->right){           //left child exist.
            Node *temp=root->left;
            delete root;
            return temp;
        }
        else if(!root->left){           //right child exist
            Node *temp=root->right;
            delete root;
            return temp;
        }
        //2 child exist.
        else{
            //find the greatest element from left.
            Node *child=root->left;
            Node *parent=root;

            //reaching right most node.
            while(child->right){
                parent=child;
                child=child->right;
            }

            if(root!=parent){
                parent->right=child->left;
                child->left=root->left;
                child->right=root->right;
                delete root;
                return child;
            }
            else{                                  //when root and parent are equal.
                child->right=root->right;
                delete root;
                return child;
            }
        }
    }
}

void inOrder(Node *root){
    if(!root)
    return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

int main(){
    int arr[]={6,3,17,5,11,18,2,1,20,14};
    Node *root=NULL;
    for(int i=0;i<10;i++)
    root=insert(root,arr[i]);
    inOrder(root);
    cout<<endl;
    root=deleteNode(root,14);
    inOrder(root);

}