#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next=NULL;
};
class stack{
    private:
    node *head=NULL;
    int stack_size=0;

    public:
    void push(int n){
        node *t=new node;
        if(t==NULL){
            cout<<"\n The heap is exhausted (stack overflow).";
        }
        else{
            t->data=n;
            if(head==NULL){
                head=t;
            }
            else{
                t->next=head;
                head=t;
            }
            stack_size++;
        }
    }
    void pop(){
        if(stack_size==0){
            cout<<"\n The heap is Empty (stack underflow).";
        }
        else{
            node *t=head;
            head=head->next;
            delete(t);
        }
    }
    void peek(){
        if(stack_size==0){
            cout<<"\n The stack is empty so no element to peek.";
        }
        else{
            cout<<"\n The Topmost element of the stack is "<<head->data;
        }
    }
};

int main(){
    stack s;
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