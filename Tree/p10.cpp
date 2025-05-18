//two trees are identical.
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

bool isIdentical(Node *r1,Node *r2){
    if(!r1 && !r2)
    return 1;
    if((!r1 && r2) || (r1 && !r2))
    return 0;
    if(r1->data!=r2->data)
    return 0;
    return isIdentical(r1->left,r2->left) && isIdentical(r1->right,r2->right);
}

int main(){
    Node *r1=new Node(1);
    r1->left=new Node(2);
    r1->right=new Node(3);

    Node *r2=new Node(1);
    r2->left=new Node(2);
    r2->right=new Node(3);

    if(isIdentical(r1,r2)){
        cout<<"The trees are identical."<<endl;
    }
    else{
        cout<<"The trees are NOT identical."<<endl;
    }
    return 0;
}
