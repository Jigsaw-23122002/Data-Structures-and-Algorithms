#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node *left=NULL;
    node *right=NULL;
};

void Traversal(node *head){
    if(head!=NULL){
        Traversal(head->left);
        cout<<head->data<<" ";
        Traversal(head->right);
    }
}

class BinarySearchTree{
    public:
    node *head=NULL;
    public:
    BinarySearchTree(vector<string> &initialisation){
        queue<node*> q;
        node *root=new node;
        root->data=stoi(initialisation[0]);
        q.push(root);
        int k=1;
        this->head=root;
        while(q.size()!=0 && k+1<initialisation.size()){
            if(initialisation[k]=="N" && initialisation[k+1]=="N"){
                q.pop();
            }
            else if(initialisation[k]=="N" && initialisation[k+1]!="N"){
                node *temp=new node;
                temp->data=stoi(initialisation[k+1]);
                q.front()->right=temp;
                q.push(temp);
                q.pop();
            }
            else if(initialisation[k]!="N" && initialisation[k+1]=="N"){
                node *temp=new node;
                temp->data=stoi(initialisation[k]);
                q.front()->left=temp;
                q.push(temp);
                q.pop();
            }
            else{
                node *temp1=new node;
                node *temp2=new node;
                temp1->data=stoi(initialisation[k]);
                temp2->data=stoi(initialisation[k+1]);
                q.front()->left=temp1;
                q.front()->right=temp2;
                q.push(temp1);
                q.push(temp2);
                q.pop();
            }
            k=k+2;
        }
        if(k+1==initialisation.size() && q.size()!=0 && initialisation[k]!="N"){
            node *temp=new node;
            temp->data=stoi(initialisation[k]);
            q.front()->left=temp;
        }
    }
    void InOrderTraversal(){
        Traversal(head);
    }
};

void InsertReplaced(node *head,node *temp){
    if(head->data<temp->data){
        if(head->right==NULL){
            head->right=temp;
        }
        else{
            InsertReplaced(head->right,temp);
        }
    }
    else{
        if(head->left==NULL){
            head->left=temp;
        }
        else{
            InsertReplaced(head->left,temp);
        }
    }
}

node *DeleteHead(node *head){
    if(head->left==NULL){
        node *temp=head->right;
        delete(head);
        return temp;
    }
    else if(head->right==NULL){
        node *temp=head->left;
        delete(head);
        return temp;
    }
    else if(head->left==NULL && head->right==NULL){
        delete(head);
        return NULL;
    }
    else{
        node *temp=head->left->right;
        head->left->right=head->right;
        InsertReplaced(head->left,temp);
        return head->left;
    }
}

void DeleteIntermediate(node *head,int delete_element){
    if(delete_element<head->data){
        if(delete_element==head->left->data){
            head->left=DeleteHead(head->left);
        }
        else{
            DeleteIntermediate(head->left,delete_element);
        }
    }
    else{
        if(delete_element==head->right->data){
            head->right=DeleteHead(head->right);
        }
        else{
            DeleteIntermediate(head->right,delete_element);
        }
    }
}

node* Deletion(node *head,int delete_element){
    if(head->data==delete_element){
        head=DeleteHead(head);
    }
    else{
        DeleteIntermediate(head,delete_element);
    }
    return head;
}

int main(){
    int n,delete_element;
    cout<<"\n Enter the number of nodes present in the Binary Search Tree:";
    cin>>n;
    vector<string> initialisation(n);
    cout<<"\n Enter the node values of the Binary Search Tree:";
    for(int i=0;i<n;i++){
        cin>>initialisation[i];
    }
    BinarySearchTree bst(initialisation);
    cout<<"\n The InOrder Traversal before Deleting a node of the Binary Search Tree:";
    bst.InOrderTraversal();
    cout<<"\n Enter the node to be deleted from the Binary search Tree:";
    cin>>delete_element;

    bst.head=Deletion(bst.head,delete_element);

    cout<<"\n The InOrder Traversal after Deleting a node of the Binary Search Tree:";
    bst.InOrderTraversal();
    return 0;
}
/*
Sample Inputs:
nodes=11
node details=50 25 75 12 37 62 87 7 17 32 43
*/