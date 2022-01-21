#include<iostream>
#include<stack>
using namespace std;

class node{
    public:
    int data=0;
    node *left=NULL;
    node *right=NULL;
    node(int n){
        this->data=n;
    }
};

class BinaryTree{
    private:
    node *n1=new node(1);
    node *n2=new node(2);
    node *n3=new node(3);
    node *n4=new node(4);
    node *n5=new node(5);
    node *n6=new node(6);
    node *n7=new node(7);
    node *n8=new node(8);
    node *n9=new node(10);
    node *n10=new node(12);
    public:
    BinaryTree(){
        n1->left=n2;
        n1->right=n3;
        n2->left=n4;
        n2->right=n5;
        n3->left=n6;
        n3->right=n7;
        n4->left=n8;
        n5->left=n9;
        n6->right=n10;
    }
    void PostOrderTraversal(node *root){
        if(root!=NULL){
            PostOrderTraversal(root->left);
            PostOrderTraversal(root->right);
            cout<<root->data<<" ";
        }
    }
    friend int main();
};

int main(){
    BinaryTree bt;
    cout<<"\n The Post-order Traversal of the tree : ";
    bt.PostOrderTraversal(bt.n1);
    return 0;
}