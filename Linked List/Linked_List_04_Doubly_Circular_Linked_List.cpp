#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next=NULL;
    node *previous=NULL;
};

class LinkedList{
    private:
    int size=0;
    node *head=NULL;
    node *tail=NULL;

    public:
    void addLast(int n){
        size++;
        node *t=new node;
        t->data=n;
        if(head==NULL && tail==NULL){
            t->next=t;
            t->previous=t;
            head={tail=t};
        }
        else{
            tail->next=t;
            t->previous=tail;
            t->next=head;
            head->previous=t;
            tail=t;            
        }
    }
    void addFirst(int n){
        size++;
        node *t=new node;
        t->data=n;
        if(head==NULL && tail==NULL){
            head={tail=t};
            t->next=t;
            t->previous=t;
        }
        else{
            tail->next=t;
            t->previous=tail;
            t->next=head;
            head->previous=t;
            head=t;
        }
    }
    void addAtPosition(int element,int position){
        if(position==1){
            addFirst(element);
        }
        else if(position==size+1){
            addLast(element);
        }
        else if(position<0 ||position>size+1){
            cout<<"\n Invalid position for the addition of the element.";
        }
        else{
            size++;
            int count=1;
            node *traverse=head;
            while(count<position-1){
                count++;
                traverse=traverse->next;
            }
            node *t=new node;
            t->data=element;
            t->next=traverse->next;
            t->previous=traverse;
            traverse->next->previous=t;
            traverse->next=t;
        }
    }
    void deleteLast(){
        if(head==NULL &&tail==NULL){
            cout<<"\n The Doubly Circular Linked list is Already Empty.";
        }
        else if(head==tail){
            node *t=head;
            delete(t);
            head={tail=NULL};
            size--;
        }
        else{
            node *t=tail->previous;
            delete(tail);
            t->next=head;
            head->previous=t;
            tail=t;
            size--;
        }
    }
    void deleteFirst(){
        if(head==NULL && tail==NULL){
            cout<<"\n The Doubly Circular Linked list is Already Empty.";
        }
        else if(head==tail){
            node *t=head;
            head={tail=NULL};
            delete(t);
            size--;
        }
        else{
            node *t=head->next;
            delete(head);
            t->previous=tail;
            tail->next=t;
            head=t;
            size--;
        }
    }
    void deleteAtPosition(int position){
        if(position==1){
            deleteFirst();
        }
        else if(position==size){
            deleteLast();
        }
        else if(position<1 || position>size){
            cout<<"\n Invalid position for the addition of the element.";
        }
        else{
            size--;
            int count=1;
            node *traverse=head;
            while(count<position-1){
                count++;
                traverse=traverse->next;
            }
            node *t=traverse->next->next;
            delete(traverse->next);
            traverse->next=t;
            t->previous=traverse;
        }
    }
    void deleteValue(int n){
        if(head->data==n){
            deleteFirst();
        }
        else if(tail->data==n){
            deleteLast();
        }
        else{
            int count=1;
            node *traverse=head;
            do{
                count++;
                traverse=traverse->next;
            }while(traverse!=head && traverse->data!=n);
            if(traverse->data==n){
                deleteAtPosition(count);
            }
            else{
                cout<<"\n No such element exists in the given Doubly Circular Linked List.";
            }
        }
    }
    void display(){
        if(head==NULL){
            cout<<"\n The Doubly Circular Linked List is Empty.";
        }
        else{
            node *traverse=head;
            cout<<"\n The elements of the Doubly Circular Linked List in the Right Direction : ";
            do{
                cout<<traverse->data<<" ";
                traverse=traverse->next;
            }while(traverse!=head);
            traverse=tail;
            cout<<"\n The elements of the Doubly Circular Linked List in the Left Direction : ";
            do{
                cout<<traverse->data<<" ";
                traverse=traverse->previous;
            }while(traverse!=tail);
        }
    }
};

int main(){
    LinkedList ll;
    cout<<"\n Testing the LinkedList Class : ";
    ll.addLast(10);
    ll.display();
    ll.addLast(20);
    ll.addLast(30);
    ll.addLast(40);
    ll.display();
    ll.addFirst(-10);
    ll.addFirst(-20);
    ll.display();
    ll.addAtPosition(-30,1);
    ll.addAtPosition(50,8);
    ll.display();
    ll.addAtPosition(0,4);
    ll.display();
    ll.deleteLast();
    ll.deleteLast();
    ll.deleteLast();
    ll.display();
    ll.deleteFirst();
    ll.display();
    ll.deleteAtPosition(3);
    ll.display();
    ll.deleteAtPosition(3);
    ll.display();
    ll.deleteValue(-30);
    ll.display();
    ll.deleteValue(-10);
    ll.display();
    ll.deleteValue(-20);
    ll.deleteValue(20);
    ll.display();
    ll.addFirst(-10);
    ll.display();
    return 0;
}