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
    void push_back(int n){
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
    void push_front(int n){
        node *t=new node;
        if(t==NULL){
            cout<<"\n The heap is exhauted (no elements can be popped).";
        }
        else{
            t->data=n;
            if(front==NULL){
                front={back=t};
            }
            else{
                t->next=front;
                front=t;
            }
        }
    }
    void pop_front(){
        node *t=front;
        if(front==NULL){
            cout<<"\n The queue is Empty (no elements can be popped from front).";
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
    void pop_back(){
        if(back==NULL){
            cout<<"\n The queue is empty (no elements can be popped from back).";
        }
        else if(front==back){
            node *t=back;
            front={back=NULL};
            delete(t);
        }
        else{
            node *traverse=front;
            node *t=back;
            while(traverse->next!=back){
                traverse=traverse->next;
            }
            traverse->next=NULL;
            back=traverse;
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
    q.pop_front();
    q.pop_back();
    q.push_back(10);
    q.push_back(20);
    q.push_back(30);
    q.push_back(40);
    q.push_back(50);
    q.display();
    q.pop_back();
    q.display();
    q.pop_front();
    q.display();
    
    q.pop_back();
    q.display();
    q.pop_front();
    q.display();
    q.pop_back();
    q.pop_front();
    q.display();
    q.push_front(10);
    q.push_front(5);
    q.push_back(20);
    q.display();
    return 0;
}