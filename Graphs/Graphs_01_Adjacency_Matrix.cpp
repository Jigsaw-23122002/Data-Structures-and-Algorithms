#include<iostream>
using namespace std;

class graph{
    private:
    int vertices;
    int edges;
    int highest_vertex_value;
    int **adjacency_matrix;

    public:
    graph(int vertices,int edges,int highest_vertex_value){
        this->vertices=vertices;
        this->edges=edges;
        this->highest_vertex_value=highest_vertex_value+1;
        adjacency_matrix=new int*[this->highest_vertex_value];
        for(int i=0;i<this->highest_vertex_value;i++){
            adjacency_matrix[i]=new int[this->highest_vertex_value];
        }
        for(int i=0;i<this->highest_vertex_value;i++){
            for(int j=0;j<this->highest_vertex_value;j++){
                adjacency_matrix[i][j]=-1;
            }
        }
    }
    void pushEdge(int start,int end,int weight_of_edge=0){
        adjacency_matrix[start][end]=weight_of_edge;
    }
    void showGraph(){
        for(int i=0;i<this->highest_vertex_value;i++){
            cout<<"\n";
            for(int j=0;j<this->highest_vertex_value;j++){
                cout<<adjacency_matrix[i][j]<<"  ";
            }
        }
    }
};

int main(){
    int vertices,edges,highest_vertex_value;
    cout<<"\n Enter the number of vertices present in the graph:";
    cin>>vertices;
    cout<<"\n Enter the number of edges present in the graph:";
    cin>>edges;
    cout<<"\n Enter the vertex with the highest value present in the graph:";
    cin>>highest_vertex_value;

    int choice;
    cout<<"\n Select 1 for Unweighted Directed Graph.\n Select 2 for Unweighted Undirected Graph.\n Select 3 for Weighted Directed Graph.\n Select 4 for Weighted Undirected Graph.\n Enter your Choice:";
    cin>>choice;

    graph g(vertices,edges,highest_vertex_value);
        
    if(choice==1 || choice==2){
        cout<<"\n Enter the details of the edges of the graph:";
        for(int i=0;i<edges;i++){
            int a,b;
            cin>>a>>b;
            g.pushEdge(a,b);
        }
    }
    else if(choice==2){
        cout<<"\n Enter the details of the edges of the graph:";
        for(int i=0;i<edges;i++){
            int a,b;
            cin>>a>>b;
            g.pushEdge(a,b);
            g.pushEdge(b,a);
        }
    }
    else if(choice==3){
        cout<<"\n Enter the details of the edges of the graph:";
        for(int i=0;i<edges;i++){
            int a,b,c;
            cin>>a>>b>>c;
            g.pushEdge(a,b,c);
        }
    }
    else{
        cout<<"\n Enter the details of the edges of the graph:";
        for(int i=0;i<edges;i++){
            int a,b,c;
            cin>>a>>b>>c;
            g.pushEdge(a,b,c);
            g.pushEdge(b,a,c);
        }
    }

    cout<<"\n The Adjacency Matrix representation of the entered graph:";
    g.showGraph();
    
    return 0;
}