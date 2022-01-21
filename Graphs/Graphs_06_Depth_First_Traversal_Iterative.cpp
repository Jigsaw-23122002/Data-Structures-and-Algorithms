#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class node{
    public:
    int vertex_value;
    vector<vector<int>> connected_vertices;
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
            cin>>pointer[i].vertex_value;
        }
    }
    void setDirectedUnweightedEdges(){
        int a,b;
        for(int i=0;i<this->edges;i++){
            cin>>a>>b;
            for(int j=0;j<this->vertices;j++){
                if(this->pointer[j].vertex_value==a){
                    this->pointer[j].connected_vertices.push_back({b,0});
                    break;
                }
            }
        }
    }
    void setUndirectedUnweightedEdges(){
        int a,b,count=0;
        for(int i=0;i<this->edges;i++){
            cin>>a>>b;
            for(int j=0;j<this->vertices;j++){
                if(this->pointer[j].vertex_value==a){
                    this->pointer[j].connected_vertices.push_back({b,0});
                    count++;
                }
                else if(this->pointer[j].vertex_value==b){
                    this->pointer[j].connected_vertices.push_back({a,0});
                    count++;
                }
                if(count==2){
                    break;
                }
            }
        }
    }
    void setDirectedWeightedEdges(){
        int a,b,c;
        for(int i=0;i<this->edges;i++){
            cin>>a>>b>>c;
            for(int j=0;j<this->vertices;j++){
                if(this->pointer[j].vertex_value==a){
                    this->pointer[j].connected_vertices.push_back({b,c});
                    break;
                }
            }
        }
    }
    void setUndirectedWeightedEdges(){
        int a,b,c,count=0;
        for(int i=0;i<this->edges;i++){
            cin>>a>>b>>c;
            for(int j=0;j<this->vertices;j++){
                if(this->pointer[j].vertex_value==a){
                    this->pointer[j].connected_vertices.push_back({b,c});
                    count++;
                }
                else if(this->pointer[j].vertex_value==b){
                    this->pointer[j].connected_vertices.push_back({a,c});
                    count++;
                }
                if(count==2){
                    break;
                }
            }
        }
    }
    void showGraph(){
        for(int i=0;i<this->vertices;i++){
            cout<<"\n "<<this->pointer[i].vertex_value<<" ==> ";
            for(int j=0;j<this->pointer[i].connected_vertices.size();j++){
                cout<<this->pointer[i].connected_vertices[j][0]<<"("<<this->pointer[i].connected_vertices[j][1]<<") - ";
            }
        }
    }
    friend void depthFirstTraversal(graph &g);
};

void depthFirstTraversal(graph &g){
    stack<node> s;
    bool *visited=new bool[g.vertices];
    for(int i=0;i<g.vertices;i++){
        visited[i]=false;
    }
    s.push(g.pointer[0]);
    visited[0]=true;
    while(s.size()!=0){
        node temp=s.top();
        s.pop();
        cout<<"  "<<temp.vertex_value;

        for(int i=0;i<temp.connected_vertices.size()!=0;i++){
            for(int j=0;j<g.vertices;j++){
                if(g.pointer[j].vertex_value==temp.connected_vertices[i][0] && visited[j]==false){
                    s.push(g.pointer[j]);
                    visited[j]=true;
                }
            }
        }
    }
}

int main(){
    int vertices,edges;
    cout<<"\n Enter the number of vertices in the graph:";
    cin>>vertices;
    cout<<"\n Enter the  number of edges in the graph:";
    cin>>edges;
    int choice;
    cout<<"\n Select 1 for Unweighted Directed Graph.\n Select 2 for Unweighted Undirected Graph.\n Select 3 for Weighted Directed Graph.\n Select 4 for Weighted Undirected Graph.\n Enter your Choice:";
    cin>>choice;
    graph g(vertices,edges);

    cout<<"\n Enter the values of the vertices of the graph:";
    g.setVertices();
    if(choice==1){
        cout<<"\n Enter the details of the edges:";
        g.setDirectedUnweightedEdges();
    }
    else if(choice==2){
        cout<<"\n Enter the details of the edges:";
        g.setUndirectedUnweightedEdges();
    }
    else if(choice==3){
        cout<<"\n Enter the details of the edges:";
        g.setDirectedWeightedEdges();
    }
    else{
        cout<<"\n Enter the details of the edges:";
        g.setUndirectedWeightedEdges();
    }
    cout<<"\n The adjacency list representation of the graph:\n";
    g.showGraph();
    depthFirstTraversal(g);
    return 0;
}