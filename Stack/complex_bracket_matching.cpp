//bracket matching when there is multiple brackets (()){ }[ ()]
#include<iostream>
#include<stack>
using namespace std;

bool isvalid(string s){
    stack<char>st;
    for(int i=0;i<s.size();i++){
        //opening bracket
        if(s[i]=='('||s[i]=='{'||s[i]=='['){
            st.push(s[i]);
        }
        //closing bracket
        else{
            if(st.empty())
            return 0;

            else if(s[i]==')'){
                if(st.top()!='(')
                return 0;
                else
                st.pop();
            }

            else if(s[i]=='}'){
                if(st.top()!='{')
                return 0;
                else
                st.pop();
            }

            else if(s[i]==']'){
                if(st.top()!='[')
                return 0;
                else 
                st.pop();
            }
        }

    }
    return st.empty();
}
int main(){
    string s="(()){}[()]";
    cout<<isvalid(s)<<endl;
    return 0;
}