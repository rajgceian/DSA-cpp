//vertical traversal in a binary tree.
#include<iostream>
#include<climits>
#include<vector>
#include<queue>
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

void find(Node *root,int pos,int &l,int &r){
    if(!root)
    return;

    l=min(pos,l);
    r=max(r,pos);
    find(root->left,pos+1,l,r);
    find(root->right,pos+1,l,r);
}

vector<int>verticalorder(Node *root){
    int l=0,r=0;
    find(root,0,l,r);

    vector<vector<int>>positive(r+1);
    vector<vector<int>>negative(abs(l)+1);

    queue<Node*>q;
    q.push(root);
    queue<int>index;
    index.push(0);

    while(!q.empty()){
        Node *temp=q.front();
        q.pop();
        int pos=index.front();
        index.pop();

        if(pos>=0)
        positive[pos].push_back(temp->data);
        else
        negative[abs(pos)].push_back(temp->data);
        
        if(temp->left){
            q.push(temp->left);
            index.push(pos-1);
        }

        if(temp->right){
            q.push(temp->right);
            index.push(pos+1);
        }

        vector<int>ans;
        for(int i=negative.size()-1;i>0;i--)
        for(int j=0;j<negative[i].size();j++)
        ans.push_back(negative[i][j]);

       for(int i=0;i<positive.size();i++)
       for(int j=0;j=positive[i].size();j++)
       ans.push_back(positive[i][j]);

       return ans;

    }
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
}