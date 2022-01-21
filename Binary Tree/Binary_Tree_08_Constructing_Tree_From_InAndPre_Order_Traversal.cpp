#include<iostream>
#include<unordered_map>
using namespace std;

class node{
    public:
    int data;
    node *left=NULL;
    node *right=NULL;
};

class BinaryTree{
    private:
    int n;
    int *preOrder;
    int *inOrder;
    node *root=NULL;
    unordered_map<int,int> ump;
    
    public:
    BinaryTree(int n){
        this->n=n;
        preOrder=new int[n];
        inOrder=new int[n];
    }
    void getPreOrder(){
        for(int i=0;i<n;i++){
            cin>>preOrder[i];
        }
    }
    void getInOrder(){
        for(int i=0;i<n;i++){
            cin>>inOrder[i];
        }
    }
    void postOrderTraversal(node* temp){
        if(temp!=NULL){
            postOrderTraversal(temp->left);
            postOrderTraversal(temp->right);
            cout<<temp->data<<" ";
        }
    }
    node* function(int index,int low,int high){
        if(low>high){
            return NULL;
        }
        else if(low==high){
            node *t=new node;
            t->data=preOrder[index];
            return t;
        }
        else{
            int element=preOrder[index];
            int division=ump[element];
            node *left=function(index+1,low,division-1);
            node *right=function(index+1+division-low,division+1,high);
            node *current=new node;
            current->data=element;
            current->left=left;
            current->right=right;
            return current;
        }
    }
    void BuildTree(){
        for(int i=0;i<n;i++){
            ump[inOrder[i]]=i;
        }
        this->root=function(0,0,n-1);
    }
    friend int main();
};

int main(){
    int n;
    cout<<"\n Enter the number of elements in the binary tree:";
    cin>>n;
    BinaryTree bt(n);
    cout<<"\n Enter the preOrder Traversal of the Binary tree : ";
    bt.getPreOrder();
    cout<<"\n Enter the inOrder Traversal of the Binary tree : ";
    bt.getInOrder();
    bt.BuildTree();
    cout<<"\n The Post Order Traversal of the Binary Tree : ";
    bt.postOrderTraversal(bt.root);
    return 0;
}

