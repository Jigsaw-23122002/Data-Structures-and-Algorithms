#include<iostream>
using namespace std;

class stack{
    private:
    int stack_size=5;
    int *stack_array=new int[stack_size];
    int stack_top=0;
    
    public:
    void push(int n){
        if(stack_top==stack_size){
            cout<<"\n The heap is exhausted (stack overflow).";
        }
        else{
            stack_array[stack_top]=n;
            stack_top++;
        }
    }
    void pop(){
        if(stack_top==0){
            cout<<"\n The heap is Empty (stack underflow).";
        }
        else{
            stack_top--;
        }
    }
    void peek(){
        if(stack_top==0){
            cout<<"\n The stack is empty so no element to peek.";
        }
        else{
            cout<<"\n The Topmost element of the stack is "<<stack_array[stack_top-1];
        }
    }
};

int main(){
    stack s;
    cout<<"\n Operations : ";
    s.peek();
    s.pop();
    s.push(10);
    s.push(23);
    s.push(7);
    s.push(98);
    s.push(67);
    s.push(11);
    s.peek();
    s.pop();
    s.peek();
    return 0;
}