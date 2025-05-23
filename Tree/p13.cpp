//Check if 2 nodes are cousin or not.
#include<iostream>
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

bool Parent(Node *root,int a,int b){
    if(!root)
    return 0;

    if(root->left && root->right){
        if(root->left->data==a && root->right->data==b)
        return 1;
        if(root->left->data==b && root->right->data==a)
        return 1;
    }

    return Parent(root->left,a,b) || Parent(root->right,a,b);
}

bool isCousin(Node *root,int a,int b){
    queue<Node *>q;
    q.push(root);
    int l1=-1,l2=-1;
    int level=0;
    while(!q.empty()){
        int n=q.size();
        while(n--){
            Node *temp=q.front();
            q.pop();
            if(temp->data==a)
            l1=level;
            if(temp->data==b)
            l2=level;

            if(temp->left)
            q.push(temp->left);
            if(temp->right)
            q.push(temp->right);
        }
    
    level++;
    if(l1!=l2)
    return 0;
    if(l1!=-1)
    break;
 }

}

return !Parent(root,a,b);