#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;

class node{
    public:
    vector<vector<int>> connectedVertices;
    vector<bool> flags;
};

class graph{
    private:
    int vertices;
    int edges;
    node *pointer;

    public:
    graph(int vertices,int edges){
        this->vertices=vertices+1;
        this->edges=edges;
        pointer=new node[this->vertices];
    }
    void setEdges(){
        int a,b,c;
        for(int i=0;i<this->edges;i++){
            cin>>a>>b>>c;
            this->pointer[a].connectedVertices.push_back({b,c});
            this->pointer[b].connectedVertices.push_back({a,c});
        }
    }
    void adjacencyList(){
        for(int i=0;i<this->vertices;i++){
            cout<<"\n"<<i<<" ==> ";
            for(int j=0;j<this->pointer[i].connectedVertices.size();j++){
                cout<<this->pointer[i].connectedVertices[j][0]<<"("<<this->pointer[i].connectedVertices[j][1]<<")  ";
            }
        }
    }
    
};

int main(){
    int vertices;
    int edges;
    cout<<"\n Enter the number of vertices in the graph:";
    cin>>vertices;
    cout<<"\n Enter the number of edges in the graph:";
    cin>>edges;
    graph g(vertices,edges);
    cout<<"\n Enter the details of the edges of the graph:";
    g.setEdges();
    cout<<"\n The adjacency list of the graph:";
    g.adjacencyList();
    return 0;
}