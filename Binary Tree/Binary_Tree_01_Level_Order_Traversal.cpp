#include<iostream>
#include<queue>
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
    void LevelOrderTraversal(){
        queue<node*> q;
        q.push(n1);
        while(q.size()!=0){
            cout<<q.front()->data<<" ";
            if(q.front()->left!=NULL){
                q.push(q.front()->left);
            }
            if(q.front()->right!=NULL){
                q.push(q.front()->right);
            }
            q.pop();
        }
    }
};

int main(){
    BinaryTree bt;
    cout<<"\n The level order Traversal of the tree : ";
    bt.LevelOrderTraversal();
    return 0;
}