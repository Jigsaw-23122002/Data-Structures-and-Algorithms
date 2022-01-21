//The Heaps are the complete binary tree.The complete binary tree is the tree which when converted to the array doen't leave any empty space in the Heap.
#include<iostream>
#include<cmath>
using namespace std;

class node{
    public:
    int data;
    node *left=NULL;
    node *right=NULL;
};

void PrepareHeap(node *head,int *array,int i,int n){
    if(2*i+1<n){
        node *left=new node;
        left->data=array[2*i+1];
        head->left=left;
        PrepareHeap(left,array,2*i+1,n);
    }
    if(2*i+2<n){
        node *right=new node;
        right->data=array[2*i+2];
        head->right=right;
        PrepareHeap(right,array,2*i+2,n);
    }
}

void HeapTraversal(node *head){
    if(head!=NULL){
        HeapTraversal(head->left);
        cout<<head->data<<" ";
        HeapTraversal(head->right);
    }
}

node* Heap(int *array,int n){
    node *head=new node;
    head->data=array[0];
    PrepareHeap(head,array,0,n);
    return head;
}

int main(){
    int n;
    int *array;
    cout<<"\n Enter the number of elements in the heap:";
    cin>>n;
    array=new int[n];
    cout<<"\n Enter the elements of the heap in the heapified form:";
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    node *HeapHead=Heap(array,n);
    cout<<"\n The InOrder Traversal of the Heap : ";
    HeapTraversal(HeapHead);
    return 0;
}