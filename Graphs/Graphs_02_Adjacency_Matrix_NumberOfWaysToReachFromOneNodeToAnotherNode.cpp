/*
The concept :If n is the number of vertices in the graph and if we represent this graph with the Matrix A as the Adjacency  matrix then then if we calculate the A x A x A x ......n times ......then the matrix obtained is B=A^n and the B[i,j]
represent the number of ways in which we can reach the vertex j fron vertex i.
*/

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
                adjacency_matrix[i][j]=0;
            }
        }
    }
    void pushEdge(int start,int end,int weight_of_edge=1){
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
    void Connections(){
        int **matrix=new int*[this->highest_vertex_value];
        for(int i=0;i<this->highest_vertex_value;i++){
            matrix[i]=new int[this->highest_vertex_value];
            for(int j=0;j<this->highest_vertex_value;j++){
                matrix[i][j]=adjacency_matrix[i][j];
            }
        }
        for(int i=0;i<this->vertices-1;i++){
            int **answer=new int*[this->highest_vertex_value];
            for(int j=0;j<this->highest_vertex_value;j++){
                answer[j]=new int[this->highest_vertex_value];
            }
            for(int j=0;j<this->highest_vertex_value;j++){
                for(int k=0;k<this->highest_vertex_value;k++){
                    int sum=0;
                    for(int l=0;l<this->highest_vertex_value;l++){
                        sum=sum+matrix[j][l]*adjacency_matrix[l][k];
                    }
                    answer[j][k]=sum;
                }
            }
            matrix=answer;
        }
        cout<<"\n The connection matrix:\n";
        for(int i=0;i<this->highest_vertex_value;i++){
            cout<<"\n";
            for(int j=0;j<this->highest_vertex_value;j++){
                cout<<matrix[i][j]<<"  ";
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
        
    if(choice==1){
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
    g.Connections();
    return 0;
}

/*
Vertices=6
Edges=9
Highest Vertex=6
Choice=2
Edge Details:
1 2
1 6
1 3
2 3
2 4
3 6
3 4
6 5
5 4
*/