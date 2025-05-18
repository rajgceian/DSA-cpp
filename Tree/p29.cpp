//sum of k smallest element in BST.
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

void ksum(Node *root,int &sum,int &k){
    if(!root)
    return;

    ksum(root->left,sum,k);
    k--;
    if(k>=0)
    sum+=root->data;
    if(k<=0)
    return;
    ksum(root->right,sum,k);
}

int sum(Node *root,int k){
    int sum=0;
    ksum(root,sum,k);
    return sum;
}

int main(){
    int arr[]={20,8,22,4,12,10,14};
    Node *root=NULL;
    for(int i=0;i<7;i++)
    root=insert(root,arr[i]);
    int k=3;
    cout<<sum(root,k)<<endl;
}