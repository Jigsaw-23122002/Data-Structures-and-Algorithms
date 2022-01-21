//Topological sort occurs only in directed acyclic graph.
//Explanation of topological Sorting : https://www.youtube.com/watch?v=qe_pQCh09yU


#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class node{
    public:
    vector<int> connected_vertices;
};

class graph{
    private:
    int vertices;
    int edges;
    stack<int> toposort;
    node *pointer;
    
    public:
    graph(int vertices,int edges){
        this->vertices=vertices;
        this->edges=edges;
        pointer=new node[this->vertices];
    }
    void setDirectedEdges(){
        int a,b;
        for(int i=0;i<this->edges;i++){
            cin>>a>>b;
            this->pointer[a].connected_vertices.push_back(b);
        }
    }
    void showGraph(){
        for(int i=0;i<this->vertices;i++){
            cout<<"\n"<<i<<" ==> ";
            for(int j=0;j<this->pointer[i].connected_vertices.size();j++){
                cout<<this->pointer[i].connected_vertices[j]<<" - ";
            }
        }
    }
    void recursion(bool *visited,int index){
        if(visited[index]==true){
            return;
        }
        else{
            //TRUE OCCURS INSIDE THE RECURSION AND NOT IN THE CALLING FUNCTION.
            visited[index]=true;
            for(int i=0;i<this->pointer[index].connected_vertices.size();i++){
                recursion(visited,this->pointer[index].connected_vertices[i]);
            }
            toposort.push(index);
        }
    }
    void topologicalSort(){
        bool *visited=new bool[this->vertices];
        for(int i=0;i<this->vertices;i++){
            visited[i]=false;
        }
        for(int i=0;i<this->vertices;i++){
            if(visited[i]==false){
                recursion(visited,i);
            }
        }
        cout<<"\n The Topological sort : "; 
        while(toposort.size()!=0){
            cout<<toposort.top()<<"  ";
            toposort.pop();
        }
    }
};

int main(){
    int vertices,edges;
    cout<<"\n Enter the number of vertices in the graph:";
    cin>>vertices;
    cout<<"\n Enter the number of edges in the graph:";
    cin>>edges;
    graph g(vertices,edges);
    cout<<"\n Enter the Edges in the directed Graph:";
    g.setDirectedEdges();
    cout<<"\n The Adjacency list of the given directed Graph:";
    g.showGraph();
    g.topologicalSort();
    return 0;
}

/*
Sample Input:
Vertices=6
Edges=7
Edge Details:
5 0
5 2
0 2
0 3
3 1
4 2
4 1

*/