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
    int peek(){
        if(stack_size==0){
            cout<<"\n The stack is empty so no element to peek.";
            return -1;
        }
        else{
            cout<<"\n The Topmost element of the stack is "<<head->data;
            return head->data;
        }
    }
};

int main(){
    int n;
    cout<<"\n Enter the number of elements in the List:";
    cin>>n;
    int *array=new int[n];
    cout<<"\n Enter the elements in the List:";
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    stack s;
    for(int i=0;i<n;i++){
        s.push(array[i]);
    }
    for(int i=0;i<n;i++){
        array[i]=s.peek();
        s.pop();
    }
    cout<<"\n The List after reversing using the stack : ";
    for(int i=0;i<n;i++){
        cout<<array[i]<<"  ";
    }
    return 0;
}