#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next=NULL;
};

class queue{
    private:
    int queue_size();
    node *front=NULL;
    node *back=NULL;

    public:
    void push(int n){
        node *t=new node;
        if(t==NULL){
            cout<<"\n The heap is exhausted (no further elements can be added into the queue.";
        }
        else{
            t->data=n;
            if(front==NULL){
                front={back=t};
            }
            else{
                back->next=t;
                back=t;
            }
        }
    }
    void pop(){
        node *t=front;
        if(front==NULL){
            cout<<"\n The queue is Empty (no elements can be popped).";
        }
        else if(front==back){
            front={back=NULL};
            delete(t);
        }
        else{
            front=front->next;
            delete(t);
        }
    }
    void display(){
        node *traverse=front;
        if(traverse==NULL){
            cout<<"\n The Queue is Empty.";
        }
        else{
            cout<<"\n The queue : ";
            while(traverse!=NULL){
                cout<<traverse->data<<" ";
                traverse=traverse->next;
            }
        }
    }
};

int main(){
    queue q;
    cout<<"\n Testing the queue class : ";
    q.pop();
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.display();
    q.pop();
    q.display();
    q.pop();
    q.pop();
    q.pop();
    q.display();
    q.pop();
    q.push(10);
    q.display();
    return 0;
}