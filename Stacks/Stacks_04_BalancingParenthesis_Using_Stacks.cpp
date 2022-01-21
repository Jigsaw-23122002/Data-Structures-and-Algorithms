#include<iostream>
#include<stack>
using namespace std;

bool BalancedParenthesis(string st){
    stack<char> s;
    for(int i=0;i<st.length();i++){
        if(st[i]=='('||st[i]=='['||st[i]=='{'){
            s.push(st[i]);
        }
        else{
            if(s.size()==0){
                return false;
            }
            else{
                if((st[i]==')' && s.top()!='(')||(st[i]==']' && s.top()!='[')||(st[i]=='}' && s.top()!='{')){
                    return false;
                }
                else{
                    s.pop();
                }
            }
        }
    }
    if(s.size()==0){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    string st;
    cout<<"\n Enter the string to be checked:";
    cin>>st;
    if(BalancedParenthesis(st)){
        cout<<"\n The Parenthesis in the given string is balanced.";
    }
    else{
        cout<<"\n The Parenthesis in the given string is not balanced.";
    }
    return 0;
}