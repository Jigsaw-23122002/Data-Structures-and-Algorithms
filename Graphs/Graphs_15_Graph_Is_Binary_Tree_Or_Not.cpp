#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class node{
    public:
    int data=0;
    vector<int> connected_vertices;
    int flag=-1;
};

class Graph{
    int vertices;
    int edges;
    node *pointer;

    public:
    Graph(int vertices,int edges){
        this->vertices=vertices;
        this->edges=edges;
        this->pointer=new node[this->vertices];
        for(int i=0;i<this->vertices;i++){
            this->pointer[i].data=i;
        }
    }
    void getEdges(){
        int a,b;
        for(int i=0;i<this->edges;i++){
            cin>>a>>b;
            this->pointer[a].connected_vertices.push_back(b);
            this->pointer[b].connected_vertices.push_back(a);
        }
    }
    bool detectCycle(){
        queue<node> q;
        q.push(pointer[0]);
        this->pointer[0].flag=0;
        while(q.size()!=0){
            for(int i=0;i<q.front().connected_vertices.size();i++){
                if(this->pointer[q.front().connected_vertices[i]].flag==-1){
                    q.push(this->pointer[q.front().connected_vertices[i]]);
                    this->pointer[q.front().connected_vertices[i]].flag=0;
                }
                else if(this->pointer[q.front().connected_vertices[i]].flag==1){
                    return true;
                }
            }
            this->pointer[q.front().data].flag=1;
            q.pop();
        }
        return false;
    }
    bool detectConnection(){
        for(int i=0;i<this->vertices;i++){
            if(this->pointer[i].connected_vertices.size()==0){
                cout<<"\n "<<i;
                return false;
            }
        }
        return true;
    }
    bool detect(){
        bool connection_status=detectConnection();
        if(connection_status==false){
            cout<<"\n Connection status false.";
            return false;
        }
        else{
            bool cycle_status=detectCycle();
            if(cycle_status==false){
                return true;
            }
            else{
                cout<<"\n Cycle status false.";
                return false;
            }
        }
    }
};

int main(){
    int vertices,edges;
    cout<<"\n Enter the number of vertices in the graph:";
    cin>>vertices;
    cout<<"\n Enter the number of edges in the graph:";
    cin>>edges;
    Graph g(vertices,edges);
    cout<<"\n Enter the edegs in the graph:";
    g.getEdges();
    if(g.detect()){
        cout<<"\n The Graph is Binary tree.";
    }
    else{
        cout<<"\n The Graph is not a Binary Tree.";
    }
    return 0;
}