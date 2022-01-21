//This requires the level order Traversal

#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node *left=NULL;
    node *right=NULL;
};

class BinaryHeap{
    private:
    node *n1,*n2,*n3,*n4,*n5,*n6,*n7;
    int *array=new int[7];
    public:
    BinaryHeap(){
        n1=new node;
        n2=new node;
        n3=new node;
        n4=new node;
        n5=new node;
        n6=new node;
        n7=new node;
        n1->left=n2;
        n1->right=n3;
        n2->left=n4;
        n2->right=n5;
        n3->left=n6;
        n3->right=n7;
        n1->data=50;
        n2->data=30;
        n3->data=20;
        n4->data=15;
        n5->data=10;
        n6->data=8;
        n7->data=16;
    }
    int* ArrayForm(){
        queue<node*> q;
        q.push(n1);
        int k=0;
        while(q.size()!=0){
            if(q.front()->left!=NULL){
                q.push(q.front()->left);
            }
            if(q.front()->right!=NULL){
                q.push(q.front()->right);
            }
            array[k]=q.front()->data;
            k++;
            q.pop();
        }
        return array;
    }
};

int main(){
    BinaryHeap bh;
    int *array=bh.ArrayForm();
    cout<<"\n The Array Representation of the Binary Heap:";
    for(int i=0;i<7;i++){
        cout<<array[i]<<" ";
    }
    return 0;
}