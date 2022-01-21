//Link of Eplanation : https://www.youtube.com/watch?v=XB4MIexjvY0

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

class node{
    public:
    vector<vector<int>> connected_vertices;
};
//DIJKSTRA ALGORITHM FOR THE WEIGHTED DIRECTED GRAPH.
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
    void getEdges(){
        int a,b,c;
        for(int i=0;i<this->edges;i++){
            cin>>a>>b>>c;
            pointer[a].connected_vertices.push_back({b,c});
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
    void dijkstra(int start){
        int **dp=new int*[this->vertices];
        for(int i=0;i<this->vertices-1;i++){
            dp[i]=new int[this->vertices];
        }
        //ARRAY FOR KEEPING THE TRACK WEATHER THE VERTEX IS ALREADY RELAXED OR NOT.
        bool *relaxed=new bool[this->vertices];
        for(int i=0;i<this->vertices;i++){
            relaxed[i]=false;
        }
        int row=0;
        relaxed[0]=true;
        relaxed[start]=true;
        for(int i=0;i<this->vertices;i++){
            dp[row][i]=INT_MAX;
        }
        for(int i=0;i<this->pointer[start].connected_vertices.size();i++){
            dp[row][this->pointer[start].connected_vertices[i][0]]=this->pointer[start].connected_vertices[i][1];
        }
        for(int i=0;i<this->vertices-3;i++){
            int temp,index=INT_MAX;
            for(int j=0;j<this->vertices;j++){
                if(dp[row][j]<index && relaxed[j]==false){
                    index=dp[row][j];
                    temp=j;
                }
            }
            relaxed[temp]=true;
            row++;
            cout<<"\n"<<temp;
            //ARRAY FOR KEEPING THE TRACK WEATHER THE VERTEX IS RELAXED DURING THIS ITERATION OR NOT.
            bool *visited=new bool[this->vertices];
            for(int j=0;j<this->vertices;j++){
                visited[j]=false;
            }
            for(int j=0;j<this->pointer[temp].connected_vertices.size();j++){
                dp[row][this->pointer[temp].connected_vertices[j][0]]=min(dp[row-1][this->pointer[temp].connected_vertices[j][0]],this->pointer[temp].connected_vertices[j][1]+dp[row-1][temp]);
                visited[this->pointer[temp].connected_vertices[j][0]]=true;
            }
            //THE VERTEX WHICH IS NOT RELAXED DURING THIS ITERATION IS ASSIGNED WITH THE VALUE OF ITS PREVIOUS ROW.
            for(int j=0;j<this->vertices;j++){
                if(visited[j]==false){
                    dp[row][j]=dp[row-1][j];
                }
            }
        }
        for(int i=0;i<this->vertices-2;i++){
            cout<<"\n";
            for(int j=0;j<this->vertices;j++){
                cout<<dp[i][j]<<"  ";
            }
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
    cout<<"\n The dijkstra Matrix:\n";
    g.dijkstra(1);
    return 0;
}