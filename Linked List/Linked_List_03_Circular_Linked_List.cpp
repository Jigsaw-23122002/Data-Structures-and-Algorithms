#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next=NULL;
};

class CircularLinkedList{
    private:
    int size=0;
    node *head=NULL;
    node *tail=NULL;

    public:
    void addLast(int n){
        size++;
        node *t=new node;
        t->data=n;
        if(tail==NULL){
            head={tail=t};
            head->next=head;
        }
        else{
            t->next=tail->next;
            tail->next=t;
            tail=t;
        }
    }
    void addFirst(int n){
        size++;
        node *t=new node;
        t->data=n;
        if(head==NULL){
            head={tail=t};
            head->next=head;
        }
        else{
            t->next=head;
            tail->next=t;
            head=t;
        }
    }
    void addAtPosition(int n,int position){
        if(position==1){
            addFirst(n);
        }
        else if(position==size+1){
            addLast(n);
        }
        else if(position<1 ||position>size+1){
            cout<<"\n Invalid Position for the insertion of the element in the linked list.";
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
            t->data=n;
            t->next=traverse->next;
            traverse->next=t;
        }
    }
    void deleteFirst(){
        if(head==NULL && tail==NULL){
            cout<<"\n The Linked list is currently empty, hence no element can be deleted.";
        }
        else if(head==tail){
            size--;
            node *t=head;
            head={tail=NULL};
            delete(t);
        }
        else{
            size--;
            node *t=head;
            tail->next=head->next;
            head=head->next;
            delete(t);
        }
    }
    void deleteLast(){
        if(head==NULL && tail==NULL){
            cout<<"\n The Linked list is currently empty, hence no element can be deleted.";
        }
        else if(head==tail){
            size--;
            node *t=head;
            head={tail=NULL};
            delete(t);
        }
        else{
            size--;
            node *t=tail;
            node *traverse=head;
            while(traverse->next!=tail){
                traverse=traverse->next;
            }
            delete(t);
            traverse->next=head;
            tail=traverse;
        }
    }
    void deleteAtPosition(int position){
        if(position==1){
            deleteFirst();
        }
        else if(position==size){
            deleteLast();
        }
        else if(position<1 ||position>size){
            cout<<"\n Invalid Position for the insertion of the element in the linked list.";
        }
        else{
            size--;
            int count=1;
            node *traverse=head;
            while(count<position-1){
                count++;
                traverse=traverse->next;
            }
            node *t=traverse->next;
            traverse->next=t->next;
            delete(t);
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
            node *traverse=head;
            int count=1;
            do{
                count++;
                traverse=traverse->next;
            }while(traverse!=NULL && traverse->data!=n);
            if(traverse->data==n){
                deleteAtPosition(count);
            }
            else{
                cout<<"\n No such element exists in the given Doubly Circular Linked List.";
            }
        }
    }
    void display(){
        if(head==NULL && tail==NULL){
            cout<<"\n The Circular Linked List is Empty.";
        }
        else{
            cout<<"\n The Circular Linked List : ";
            node *traverse=head;
            do{
                cout<<traverse->data<<" ";
                traverse=traverse->next;
            }while(traverse!=head);
        }
    }
};

int main(){
    CircularLinkedList cll;
    cout<<"\n Testing the CircularLinkedList class : ";
    cll.addLast(10);
    cll.display();
    cll.addLast(20);
    cll.addLast(30);
    cll.addLast(40);
    cll.addLast(50);
    cll.display();
    cll.addFirst(0);
    cll.addFirst(-10);
    cll.display();
    cll.addAtPosition(-20,1);
    cll.display();
    cll.addAtPosition(60,9);
    cll.display();
    cll.addAtPosition(5,4);
    cll.display();
    cll.addAtPosition(70,12);
    cll.deleteFirst();
    cll.display();
    cll.deleteFirst();
    cll.display();
    cll.deleteAtPosition(1);
    cll.display();
    cll.deleteAtPosition(4);
    cll.display();
    cll.deleteAtPosition(10);
    cll.deleteAtPosition(6);
    cll.display();
    cll.deleteAtPosition(5);
    cll.display();
    cll.deleteValue(20);
    cll.display();
    cll.deleteValue(40);
    cll.display();
    cll.deleteValue(5);
    cll.display();
    cll.deleteValue(10);
    cll.display();
    return 0;
}