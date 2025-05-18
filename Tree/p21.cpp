//Diagonal traversal of a binary tree.
#include<iostream>
#include<climits>
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

void find(Node *root,int pos,int &l){
    if(!root)
    return;

    l=max(pos,l);
    find(root->left,pos+1,l);
    find(root->right,pos,l);
}

void findDig(Node *root,int pos,vector<vector<int>>&ans){
    if(!root)
    return;

    ans[pos].push_back(root->data);
    findDig(root->left,pos,ans);
    findDig(root->right,pos,ans);
}

vector<int>diagonal(Node *root){
    int l=0;
    find(root,0,l); //left most diagonal.

    vector<vector<int>>ans(l+1);
    findDig(root,0,ans);
    vector<int>temp;
    for(int i=0;i<ans.size();i++)
    for(int j=0;j<ans[i].size();j++)
    temp.push_back(ans[i][j]);
    return temp;
}

int main(){
    Node *root=new Node(1);
    root->left=new Node(2);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right=new Node(3);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    root->right->left->left=new Node(9);
    root->right->right->right=new Node(10);
    root->left->left->left=new Node(8);
    root->left->left->left->right=new Node(11);            
    
    vector<vector<int>>ans;
    diagonal(root);
    cout<<"diagonal traversal:";
    for(auto& diagonal:ans){
        for(int data:diagonal){
            cout<<data<<" ";
        }
    }
    return 0;
}