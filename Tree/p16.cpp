//In order traversal(iterative)
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
    vector<int>inOrder(Node *root){
        stack<Node*>s;
        stack<bool>visited;
        s.push(root);
        visited.push(0);
        vector<int>ans;

        while(!s.empty()){
            Node *temp=s.top();
            s.pop();
            bool flag=visited.top();
            visited.pop();

            if(flag==0){
                if(temp->right){
                    s.push(temp->right);
                    visited.push(0);
                }
                s.push(temp);
                visited.push(1);
                if(temp->left){
                    s.push(temp->left);
                    visited.push(0);
                }
            }
            else{
                ans.push_back(temp->data);
            }
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
    vector<int>In=sol.inOrder(root);
    cout<<"In order traversal:";
    for(int data:In){
        cout<<data<<" ";
    }
    return 0;

}