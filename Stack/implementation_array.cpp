//using array to create stack.
#include<iostream>
using namespace std;
class stack{
     int *arr;
     int size;
     int top;
     public:
     stack(int s){
         size=s;
         top=-1;
         arr=new int[s];
     }

     //push
     void push(int value){
        if(top==size-1){
            cout<<"stack overflow/n";
            return;
        }
        else{
            top++;
            arr[top]=value;
            cout<<"pushed "<<value<<" into the stack\n";
        }
     }

     //pop
     void pop(){
        if(top==-1){
            cout<<"stack underflow/n";
            return;
        }
        else{
            top--;
            cout<<"popped "<<arr[top+1]<<" from the stack\n";
        }
     }

     //peek
     int peek(){
        if(top==-1){
            cout<<"stack is empty/n";
            return -1;
        }
        else{
            return arr[top];
        }
     }

     //is empty
     bool isEmpty(){
        return top==-1;
     }

     //is full
     bool isFull(){
        if(top=size-1)
        return 1;
        else 
        return 0;
     }

     //is size
     int isSize(){
        return top+1;
     }
};

int main(){
    stack s(5);
    s.push(4);
    s.push(45);
    s.push(12);
    s.push(7);
    s.push(5);
    s.pop();
    s.pop();
    cout<<s.peek()<<endl;
    return 0;
}