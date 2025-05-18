//kth largest element in bst.
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

void klargest(Node *root,int &ans,int &k){
    if(!root)
    return;

    klargest(root->right,ans,k);
    k--;
    if(k==0)
    ans=root->data;
    if(k<=0)
    return;
    klargest(root->left,ans,k);
}

int kthlargest(Node *root,int k){
    int ans;
    klargest(root,ans,k);
    return ans;
}

int main(){
    int arr[]={30,20,40,6,24,36,50,45};
    Node *root=NULL;
    for(int i=0;i<8;i++)
    root=insert(root,arr[i]);
    int k=3;
    cout<<kthlargest(root,k)<<endl;
}