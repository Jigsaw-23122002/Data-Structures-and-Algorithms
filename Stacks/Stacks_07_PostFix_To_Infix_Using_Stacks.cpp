#include<iostream>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;

bool operate(char c){
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='('||c==')'){
        return true;
    }
    else{
        return false;
    }
}

string postfixToInfix(string st){
    stack<string> s;
    for(int i=0;i<st.length();i++){
        if(operate(st[i])==true){
            string t=st[i]+s.top()+')';
            s.pop();
            t='('+s.top()+t;
            s.pop();
            s.push(t);
        }
        else{
            s.push(to_string(st[i]));
        }
    }
    return s.top();
}

int main(){
    string st;
    cout<<"\n Enter the expression to be evaluated in the postfix form:";
    cin>>st;
    string answer=postfixToInfix(st);
    cout<<"\n The PreFix of the above Expression:"<<answer;
    return 0;
}