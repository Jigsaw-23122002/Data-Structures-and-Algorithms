//One way of avoiding the collision is using the vectors.The example is given in the Hashing_01_Basic_Implementation.cpp
//The another is using the linked list:

#include<iostream>
using namespace std;

class node{
    public:
    int data=0;
    node *next=NULL;
};

class Hashing{
    private:
    node *HashTable=new node[10];
    public:
    void HashData(int n){
        int index=n%10;
        if(HashTable[index].next==NULL){
            node *t=new node;
            t->data=n;
            HashTable[index].data++;
            HashTable[index].next=t;
        }
        else{
            node *traverse=HashTable[index].next;
            while(traverse->next!=NULL){
                traverse=traverse->next;
            }
            node *t=new node;
            t->data=n;
            HashTable[index].data++;
            traverse->next=t;
        }
    }
    bool findData(int n){
        int search_index=n%10;
        if(HashTable[search_index].data==0){
            return false;
        }
        else{
            node *traverse=HashTable[search_index].next;
            while(traverse!=NULL){
                if(traverse->data==n){
                    return true;
                }
                traverse=traverse->next;
            }
            return false;
        }
    }
    void hashedTable(){
        for(int i=0;i<10;i++){
            cout<<"\n "<<i<<" ==> ";
            node *traverse=HashTable[i].next;
            while(traverse!=NULL){
                cout<<traverse->data<<" , ";
                traverse=traverse->next;
            }
        }
    }
};

int main(){
    int n,temp,find;
    Hashing h;
    cout<<"\n Enter the number of elements present in the data:";
    cin>>n;
    cout<<"\n Enter the elements present in the data:";
    for(int i=0;i<n;i++){
        cin>>temp;
        h.HashData(temp);
    }
    cout<<"\n Enter the element to be searched in the earlier data:";
    cin>>find;
    if(h.findData(find)){
        cout<<"\n The element was present in the data entered earlier.";
    }
    else{
        cout<<"\n The element was not pressent in the data entered earlier.";
    }
    cout<<"\n The Hash table for the verificatiion:";
    h.hashedTable();
    return 0;
}