//ON HOLD FOR THE DETAILED STUDY.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class node{
    public:
    vector<vector<int>> connected_vertices;
};

class graph{
    private:
    int vertices;
    int edges;
    node *pointer;
    vector<vector<int>> nodes;
    public:
    graph(int vertices,int edges){
        this->vertices=vertices+1;
        this->edges=edges;
        pointer=new node[this->vertices];
    }
    void getEdges(){
        int a,b,c;
        for(int i=0;i<this->edges;i++){
            cin>>a>>b>>c;
            pointer[a].connected_vertices.push_back({b,c});
            pointer[b].connected_vertices.push_back({a,c});
            nodes.push_back({c,a,b});
        }
    }
    void adjacencyList(){
        for(int i=0;i<this->vertices;i++){
            cout<<"\n"<<i<<" ==>";
            for(int j=0;j<this->pointer[i].connected_vertices.size();j++){
                cout<<"  "<<this->pointer[i].connected_vertices[j][0]<<"("<<this->pointer[i].connected_vertices[j][1]<<")";
            }
        }
    }
    void getNodes(){
        sort(this->nodes.begin(),this->nodes.end());
        for(int i=0;i<this->nodes.size();i++){
            cout<<"\n"<<this->nodes[i][0]<<" == "<<this->nodes[i][1]<<" - "<<this->nodes[i][2];
        }
    }
    int UnionFind(int vertex,int *parent){
        if(parent[vertex]<0){
            return vertex;
        }
        else{
            return UnionFind(parent[vertex],parent);
        }
    }
    void kruskal(){
        vector<vector<int>> answer;
        int *parent=new int[this->vertices];
        for(int i=0;i<this->vertices;i++){
            parent[i]=-1;
        }
        sort(this->nodes.begin(),this->nodes.end());
        for(int i=0;i<this->edges;i++){
            int sourceParent=UnionFind(this->nodes[i][1],parent);
            int destinationParent=UnionFind(this->nodes[i][2],parent);
            if(sourceParent!=destinationParent){
                answer.push_back(this->nodes[i]);
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
        cout<<"\n The output of the Kruskal's Algorithm:";
        for(int i=0;i<answer.size();i++){
            cout<<"\n"<<answer[i][0]<<" == ( "<<answer[i][1]<<" , "<<answer[i][2]<<" )";
        }
    }
};

int main(){
    int vertices,edges;
    cout<<"\n Enter the number of vertices present in the graph:";
    cin>>vertices;
    cout<<"\n Enter the number of edges present in the graph:";
    cin>>edges;
    graph g(vertices,edges);
    cout<<"\n Enter the edges of the graph:";
    g.getEdges();
    cout<<"\n The Adjacency list form of the graph:";
    g.adjacencyList();
    cout<<"\n The graph representation in the nodes form:";
    g.getNodes();
    g.kruskal();
    return 0;
}