//For the explanation of the detectrion of the cycle in the graph.....refer Jenny's lecture video.
//Link : https://www.youtube.com/watch?v=vXrv3kruvwE

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class node{
    public:
    int vertex_value;
    int flag=-1;
    vector<int> connected_vertices;
};

class graph{
    private:
    int vertices;
    int edges;
    node *pointer;
    public:
    graph(int vertices,int edges){
        this->vertices=vertices;
        this->edges=edges;
        pointer=new node[this->vertices];
    }
    void setVertices(){
        for(int i=0;i<this->vertices;i++){
            cin>>this->pointer[i].vertex_value;
        }
    }
    void setDirectedEdges(){
        int a,b;
        for(int i=0;i<this->edges;i++){
            cin>>a>>b;
            for(int j=0;j<this->vertices;j++){
                if(this->pointer[j].vertex_value==a){
                    this->pointer[j].connected_vertices.push_back(b);
                }
            }
        }
    }
    void setUndirectedEdges(){
        int a,b;
        for(int i=0;i<this->edges;i++){
            cin>>a>>b;
            for(int j=0;j<this->vertices;j++){
                if(this->pointer[j].vertex_value==a){
                    this->pointer[j].connected_vertices.push_back(b);
                }
                else if(this->pointer[j].vertex_value==b){
                    this->pointer[j].connected_vertices.push_back(a);
                }
            }
        }
    }
    void showGraph(){
        for(int i=0;i<this->vertices;i++){
            cout<<"\n"<<this->pointer[i].vertex_value<<" ==> ";
            for(int j=0;j<this->pointer[i].connected_vertices.size();j++){
                cout<<this->pointer[i].connected_vertices[j]<<" - ";
            }
        }
    }
    bool detectCycle(){
        queue<node> q;
        q.push(this->pointer[0]);
        this->pointer[0].flag=0;
        while(q.size()!=0){
            for(int i=0;i<q.front().connected_vertices.size();i++){
                for(int j=0;j<this->vertices;j++){
                    if(q.front().connected_vertices[i]==this->pointer[j].vertex_value && this->pointer[j].flag==-1){
                        q.push(this->pointer[j]);
                        this->pointer[j].flag=0;
                    }
                    else if(q.front().connected_vertices[i]==this->pointer[j].vertex_value && this->pointer[j].flag==1){
                        return true;
                    }
                }
            }
            for(int i=0;i<this->vertices;i++){
                if(this->pointer[i].vertex_value==q.front().vertex_value){
                    this->pointer[i].flag=1;
                }
            }
            q.pop();
        }
        return false;
    }
    void showFlags(){
        cout<<"\n";
        for(int i=0;i<this->vertices;i++){
            cout<<this->pointer[i].flag<<"  ";
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
    cout<<"\n Enter the vertices values of the graph:";
    g.setVertices();
    cout<<"\n Enter the Edges in the directed Graph:";
    g.setDirectedEdges();
    cout<<"\n The Adjacency list of the given directed Graph:";
    g.showGraph();
    g.showFlags();
    if(g.detectCycle()==true){
        cout<<"\n There is the cycle in the graph.";
    }
    else{
        cout<<"\n The cycle is not present in the graph.";
    }
    g.showFlags();
    return 0;
}
