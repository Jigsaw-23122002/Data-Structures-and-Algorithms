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

class AVLTree{
    public:
    node *head=NULL;
    public:
    AVLTree(vector<string> &initialisation){
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
    int Height(node *head){
    if(head==NULL){
        return 0;
    }
    else{
        return 1+max(Height(head->left),Height(head->right));
    }
}
    int AVL(node *root,node *head,bool &status){
        if(head==NULL){
            return 0;
        }
        else{
            int heightLeft=AVL(root,head->left,status);
            int heightRight=AVL(root,head->right,status);
            node *newHead=head;
            if(abs(heightLeft-heightRight)>1){
                status=false;
            }
            if(heightLeft-heightRight>1){
                if(Height(head->left->left)>=Height(head->left->right)){
                    newHead=head->left;
                    cout<<"\n R : "<<head->data;
                    this->head=RightRotation(root,head);
                    AVL(root,newHead->left,status);
                    AVL(root,newHead->right,status);
                }
                else{
                    cout<<"\n LR : "<<head->data;
                    newHead=head->left->right;
                    this->head=LeftRightRotation(root,head);
                    AVL(root,newHead->left,status);
                    AVL(root,newHead->right,status);
                }
            }
            else if(heightLeft-heightRight<-1){
                if(Height(head->right->left)<=Height(head->right->right)){
                    newHead=head->right;
                    cout<<"\n L : "<<head->data;
                    this->head=LeftRotation(root,head);
                    AVL(root,newHead->left,status);
                    AVL(root,newHead->right,status);
                }
                else{
                    newHead=head->right->left;
                    cout<<"\n RL : "<<head->data;
                    this->head=RightLeftRotation(root,head);
                    AVL(root,newHead->left,status);
                    AVL(root,newHead->right,status);
                }
            }
            return 1+max(Height(newHead->left),Height(newHead->right));
        }
    }
    node* RightRotation(node *head,node *rotational_node){
        if(head==rotational_node){
            node *temp=head->left;
            head->left=temp->right;
            temp->right=head;
            return temp;
        }
        else{
            node *traverse=head;
            while(traverse->left!=rotational_node && traverse->right!=rotational_node){
                if(rotational_node->data<traverse->data){
                    traverse=traverse->left;
                }
                else{
                    traverse=traverse->right;
                }
            }
            node *temp=rotational_node->left;
            rotational_node->left=temp->right;
            temp->right=rotational_node;
            if(traverse->left==rotational_node){
                traverse->left=temp;
            }
            else{
                traverse->right=temp;
            }
            return head;
        }
    }
    node* LeftRotation(node *head,node *rotational_node){
        if(head==rotational_node){
            node *temp=head->right;
            head->right=temp->left;
            temp->left=head;
            return temp;
        }
        else{
            node *traverse=head;
            while(traverse->left!=rotational_node && traverse->right!=rotational_node){
                if(rotational_node->data<traverse->data){
                    traverse=traverse->left;
                }
                else{
                    traverse=traverse->right;
                }
            }
            node *temp=rotational_node->right;
            rotational_node->right=temp->left;
            temp->left=rotational_node;
            if(traverse->left==rotational_node){
                traverse->left=temp;
            }
            else{
                traverse->right=temp;
            }
            return head;
        }
    }
    node* RightLeftRotation(node *head,node *rotational_node){
        node *t1=rotational_node->right;
        node *t2=t1->left;
        t1->left=t2->right;
        t2->right=t1;
        rotational_node->right=t2;
        if(head==rotational_node){
            node *temp=head->right;
            head->right=temp->left;
            temp->left=head;
            return temp;
        }
        else{
            node *traverse=head;
            while(traverse->left!=rotational_node && traverse->right!=rotational_node){
                if(rotational_node->data<traverse->data){
                    traverse=traverse->left;
                }
                else{
                    traverse=traverse->right;
                }
            }
            node *temp=rotational_node->right;
            rotational_node->right=temp->left;
            temp->left=rotational_node;
            if(traverse->left==rotational_node){
                traverse->left=temp;
            }
            else{
                traverse->right=temp;
            }
            return head;
        }
    }
    node* LeftRightRotation(node *head,node *rotational_node){
        node *t1=rotational_node->left;
        node *t2=t1->right;
        t1->right=t2->left;
        t2->left=t1;
        rotational_node->left=t2;
        if(head==rotational_node){
            node *temp=head->left;
            head->left=temp->right;
            temp->right=head;
            return temp;
        }
        else{
            node *traverse=head;
            while(traverse->left!=rotational_node && traverse->right!=rotational_node){
                if(rotational_node->data<traverse->data){
                    traverse=traverse->left;
                }
                else{
                    traverse=traverse->right;
                }
            }
            node *temp=rotational_node->left;
            rotational_node->left=temp->right;
            temp->right=rotational_node;
            if(traverse->left==rotational_node){
                traverse->left=temp;
            }
            else{
                traverse->right=temp;
            }
            return head;
        }
    }
};

int main(){
    int n,search_element;
    cout<<"\n Enter the number of nodes present in the Binary Search Tree:";
    cin>>n;
    vector<string> initialisation(n);
    cout<<"\n Enter the node values of the Binary Search Tree:";
    for(int i=0;i<n;i++){
        cin>>initialisation[i];
    }
    AVLTree avl(initialisation);
    cout<<"\n The Status of the Binary Search Tree before any Rotations:";
    cout<<"\n The InOrder Traversal of the Binary Search Tree:";
    avl.InOrderTraversal();
    bool status=true;
    avl.AVL(avl.head,avl.head,status);
    if(status==true){
        cout<<"\n The given Binary Search Tree is an AVL Tree.";
    }
    else{
        cout<<"\n The given Binary Search Tree is not an AVL Tree.";
    }
    status=true;
    avl.AVL(avl.head,avl.head,status);
    cout<<"\n The Status of the Binary Search Tree after required Rotations:";
    cout<<"\n The InOrder Traversal of the Binaary Search Tree:";
    avl.InOrderTraversal();
    if(status==true){
        cout<<"\n The given Binary Search Tree is an AVL Tree.";
    }
    else{
        cout<<"\n The given Binary Search Tree is not an AVL Tree.";
    }
    return 0;
}