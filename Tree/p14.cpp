//pre order traversal(iterative)
#include<iostream>
#include<vector>
#include<stack>
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

class Solution{
    public:
    vector<int>preOrder(Node *root){
        stack<Node*>s;
        s.push(root);
        vector<int>ans;
        while(!s.empty()){
            Node *temp=s.top();
            s.pop();
            ans.push_back(temp->data);
            if(temp->right)
            s.push(temp->right);
            if(temp->left)
            s.push(temp->left);
        }
        return ans;
    }
};

int main(){
    Node *root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    root->left->left->left=new Node(8);

    Solution sol;
    vector<int>pre=sol.preOrder(root);
    cout<<"pre order traversal:";
    for(int data:pre){
        cout<<data<<" ";
    }
    return 0;

}