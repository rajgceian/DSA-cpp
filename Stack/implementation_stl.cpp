//create stack using STL.
#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int>s;
    s.push(3);
    s.push(9);
    s.push(12);
    s.push(23);
    cout<<s.size()<<endl;
    cout<<s.top()<<endl;
}