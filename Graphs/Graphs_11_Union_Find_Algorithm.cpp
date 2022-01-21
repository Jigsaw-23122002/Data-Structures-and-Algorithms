// THIS ALGORITHM IS USED TO DETECT THE CYCLE IN THE GRAPH.
//Link of the Explanation of Algorithm : https://www.youtube.com/watch?v=wU6udHRIkcc

#include<iostream>
#include<vector>
using namespace std;

class graph{
    private:
    int vertices;
    int edges;
    vector<vector<int>> nodes;
    public:
    graph(int vertices,int edges){
        this->vertices=vertices+1;
        this->edges=edges;
    }
    void setEdges(){
        int a,b,c;
        for(int i=0;i<this->edges;i++){
            cin>>a>>b>>c;
            nodes.push_back({a,b,c});
        }
    }
    void getEdges(){
        for(int i=0;i<this->edges;i++){
            cout<<"\n"<<this->nodes[i][0]<<" == ( "<<this->nodes[i][1]<<" , "<<this->nodes[i][2]<<" )";
        }
    }
    int algorithm(int vertex,int *parent){
        if(parent[vertex]<0){
            return vertex;
        }
        else{
            return algorithm(parent[vertex],parent);
        }
    }
    void UnionFind(){
        int cycles=0;
        int *parent=new int[this->vertices];
        for(int i=0;i<this->vertices;i++){
            parent[i]=-1;
        }
        for(int i=0;i<this->edges;i++){
            int sourceParent=algorithm(this->nodes[i][1],parent);
            int destinationParent=algorithm(this->nodes[i][2],parent);
            if(sourceParent==destinationParent){
                cycles++;
            }
            else{
                if(parent[sourceParent]<=parent[destinationParent]){
                    parent[sourceParent]=parent[sourceParent]+parent[destinationParent];
                    parent[destinationParent]=sourceParent;
                }
                else{
                    parent[destinationParent]=parent[sourceParent]+parent[destinationParent];
                    parent[sourceParent]=destinationParent;
                }
            }
        }
        cout<<"\n"<<cycles<<"\n";
        for(int i=0;i<this->vertices;i++){
            cout<<parent[i]<<"  ";
        }
    }
};

int main(){
    int vertices,edges;
    cout<<"\n Enter the total number of vertices present in the graph:";
    cin>>vertices;
    cout<<"\n Enter the total number of edges present in the graph:";
    cin>>edges;
    graph g(vertices,edges);
    cout<<"\n Enter the edge details in the graph:";
    g.setEdges();
    cout<<"\n The edges of the graph:";
    g.getEdges();
    g.UnionFind();
    return 0;
}