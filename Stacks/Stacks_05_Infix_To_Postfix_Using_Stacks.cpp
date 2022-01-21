#include<iostream>
#include<stack>
using namespace std;

int prior(char c){
    if(c=='+'||c=='-'){
        return 1;
    }
    else if(c=='*'||c=='/'){
        return 2;
    }
    else{
        return 3;
    }
}

bool operate(char c){
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='('||c==')'){
        return true;
    }
    else{
        return false;
    }
}

string infixToPostfix(string st){
    stack<char> s;
    string ans="";
    for(int i=0;i<st.length();i++){
        if(operate(st[i])==false){
            ans=ans+st[i];
        }
        else{
            if(s.size()==0){
                s.push(st[i]);
            }
            else{
                if(st[i]==')'){
                    while(s.size()!=0 && s.top()!='('){
                        ans=ans+s.top();
                        s.pop();
                    }
                    s.pop();
                }
                else if(s.size()!=0 && s.top()=='('){
                    s.push(st[i]);
                }
                else if(prior(s.top())<prior(st[i])){
                    s.push(st[i]);
                }
                else{
                    while(s.size()!=0 && prior(s.top())>=prior(st[i])){
                        ans=ans+s.top();
                        s.pop();
                        if(s.size()!=0 && s.top()=='('){
                            break;
                        }
                    }
                    s.push(st[i]);
                }
            }
        }
    }
    while(s.size()!=0){
        ans=ans+s.top();
        s.pop();
    }
    return ans;
}

int main(){
    string st;
    cout<<"\n Enter the expression to be evaluated in the infix form:";
    cin>>st;
    string answer=infixToPostfix(st);
    cout<<"\n The PostFix of the above Expression:"<<answer;
    return 0;
}