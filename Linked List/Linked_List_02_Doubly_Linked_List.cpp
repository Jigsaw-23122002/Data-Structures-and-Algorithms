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
    node *head=NULL;
    node *tail=NULL;
    int size=0;

    public:
    void addLast(int n){
        size++;
        if(head==NULL){
            node *t=new node;
            t->data=n;
            head={tail=t};
        }
        else{
            node *t=new node;
            t->data=n;
            t->previous=tail;
            tail->next=t;
            tail=t;
        }
    }
    void deleteLast(){
        if(head==NULL){
            cout<<"\n Cannot perform the deletion as the linked list conatins 0 elements.";
        }
        else if(head==tail){
            node *t=tail;
            head={tail=NULL};
            delete(t);
            size--;
        }
        else{
            node *traverse=head;
            while(traverse->next!=tail){
                traverse=traverse->next;
            }
            traverse->next=NULL;
            tail=traverse;
            size--;
        }
    }
    void addFirst(int n){
        size++;
        if(head==NULL){
            node *t=new node;
            t->data=n;
            head={tail=t};
        }
        else{
            node *t=new node;
            t->data=n;
            t->next=head;
            head->previous=t;
            head=t;
        }
    }
    void deleteFirst(){
        if(head==NULL){
            cout<<"\n Cannot perform the deletion as the linked list conatins 0 elements.";
        }
        else if(head==tail){
            node *t=head;
            head={tail=NULL};
            delete(t);
            size--;
        }
        else{
            node *t=head;
            head=head->next;
            head->previous=NULL;
            delete(t);
            size--;
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
            while(traverse->next!=NULL && traverse->next->data!=n){
                traverse=traverse->next;
            }
            if(traverse->next==NULL){
                cout<<"\n No such element is present in the linked list to be deleted.";
            }
            else{
                node *t=traverse->next;
                traverse->next=t->next;
                t->next->previous=traverse;
                delete(t);
                size--;
            }
        }
    }
    void deleteAtPosition(int position){
        if(position==1){
            deleteFirst();
        }
        else if(position==size){
            deleteLast();
        }
        else if(position>size ||position<1){
            cout<<"\n Invalid position for the deletion of the element in the linked list.";
        }
        else{
            int count=1;
            node *traverse=head;
            while(count<position-1){
                count++;
                traverse=traverse->next;
            }
            node *t=traverse->next;
            traverse->next=t->next;
            t->next->previous=traverse;
            delete(t);
        }
    }
    void addAtPosition(int n,int position){
        if(position==1){
            addFirst(n);
        }
        else if(position==size+1){
            addLast(n);
        }
        else if(position>size+1 || position<1){
            cout<<"\n Invalid position for the insertion of the element in the linked list.";
        }
        else{
            int count=1;
            node *traverse=head;
            while(count<position-1){
                count++;
                traverse=traverse->next;
            }
            node *t=new node;
            t->data=n;
            t->next=traverse->next;
            t->next->previous=t;
            t->previous=traverse;
            traverse->next=t;
            size++;
        }
    }
    void display(){
        cout<<"\n The linked list in forward direction : ";
        node *traverse=head;
        while(traverse!=NULL){
            cout<<traverse->data<<" ";
            traverse=traverse->next;
        }
        cout<<"\n The linked list in backward direction : ";
        traverse=tail;
        while(traverse!=NULL){
            cout<<traverse->data<<" ";
            traverse=traverse->previous;
        }
        cout<<endl;
    }
};

int main(){
    LinkedList ll;
    cout<<"\n Testing the LinkedList class : ";
    ll.addLast(10);
    ll.addLast(20);
    ll.addLast(30);
    ll.addLast(40);
    ll.addLast(50);
    ll.display();
    ll.addFirst(0);
    ll.addFirst(-10);
    ll.display();
    ll.deleteLast();
    ll.deleteLast();
    ll.display();
    ll.deleteFirst();
    ll.deleteFirst();
    ll.display();
    ll.addAtPosition(40,4);
    ll.display();
    ll.addAtPosition(35,4);
    ll.display();
    ll.addAtPosition(0,1);
    ll.display();
    ll.addAtPosition(50,8);
    ll.display();
    ll.deleteAtPosition(1);
    ll.display();
    ll.deleteAtPosition(5);
    ll.display();
    ll.deleteAtPosition(5);
    ll.display();
    ll.deleteValue(10);
    ll.display();
    ll.deleteValue(30);
    ll.display();
    ll.deleteValue(35);
    ll.display();
    return 0;
}