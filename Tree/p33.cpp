//preorder and bst.
#include<iostream>
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

void BST(int arr[],int &index,int lower,int upper,int N){
    if(index==N || arr[index]<lower || arr[index]>upper)
    return;

    int value=arr[index++];
    BST(arr,index,lower,value,N);
    BST(arr,index,value,upper,N);

}

int canRepresentBST(int arr[],int N){
    int index=0;
    BST(arr,index,INT16_MIN,INT16_MAX);
    return index==N;
}

int main(){
    int arr[]={2,4,3};
    int N=3;
    Node *root=canRepresentBST(arr,N);
    

}