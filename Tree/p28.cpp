//minimum distance between BST nodes.
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

void minDist(Node *root,int &prev,int &ans){
    if(!root)
    return ;

    minDist(root->left,prev,ans);
    if(prev!=INT16_MIN)
    ans=min(ans,root->data-prev);
    prev=root->data;
    minDist(root->right,prev,ans);
}

int minDiffInBST(Node *root){
    int prev=INT16_MIN;
    int ans=INT16_MAX;
    minDist(root,prev,ans);
    return ans;
}

int main(){
    int arr[]={20,10,2,14,30,25,35};
    Node *root=NULL;
    for(int i=0;i<7;i++)
    root=insert(root,arr[i]);
    cout<<minDiffInBST(root)<<endl;
}