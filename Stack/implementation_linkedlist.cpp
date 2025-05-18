//using linkedlist to create stack.
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int value){
        data=value;
        next=NULL;
    }
};
class stack{
    Node *top;
    int size;
    public:
    stack(){
        top=NULL;
        size=0;
    }

    //push
    void push(int value){
        Node *temp=new Node(value);
        if(temp==NULL){
            cout<<"stack overflow\n";
            return;
        }
        else{
            temp->next=top;
            top=temp;
            size++;
            cout<<"pushed "<<value<<" into the stack\n";
        }
    }

    //pop
    void pop(){
        if(top==NULL){
            cout<<"stack underflow\n";
            return;
        }
        else{
            Node *temp=top;
            cout<<"popped "<<top->data<<" from the stack\n";
            top=top->next;
            delete temp;
            size--;
        }
    }

    //peek
    int peek(){
        if(top==NULL){
            cout<<"stack is empty\n";
            return -1;
        }
        else{
            return top->data;
        }
    }

    //is empty
    bool isEmpty(){
        return top==NULL;
    }

    //is size
    int isSize(){
        return size;
    }
};

int main(){
    stack s;
    s.push(5);
    s.push(8);
    s.push(13);
    s.push(23);
    s.push(12);
    s.pop();
    s.pop();
    cout<<s.peek()<<endl;
    return 0;
}
