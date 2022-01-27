#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

class graph{
    private:
    int vertices;
    int edges;
    vector<vector<int>> graph_list;
    
    public:
    graph(int vertices,int edges){
        this->vertices=vertices;
        this->edges=edges;
    }
    void getEdges(){
        for(int i=0;i<this->edges;i++){
            int a,b,c;
            cin>>a>>b>>c;
            graph_list.push_back({a,b,c});
        }
    }
    void edgesInGraph(){
        sort(graph_list.begin(),graph_list.end());
        for(int i=0;i<this->edges;i++){
            cout<<"\n ("<<graph_list[i][0]<<","<<graph_list[i][1]<<") = ("<<graph_list[i][2]<<")";
        }
    }
    void BellManFordAlgorithm(){
        vector<int> values(this->vertices,INT_MAX);
        values[0]=0;
        for(int i=0;i<this->vertices-1;i++){
            for(int j=0;j<this->edges;j++){
                if(values[graph_list[j][0]]!=INT_MAX && values[graph_list[j][0]]+graph_list[j][2]<values[graph_list[j][1]]){
                    values[graph_list[j][1]]=values[graph_list[j][0]]+graph_list[j][2];
                }
            }
        }
        cout<<"\n The BellMan Ford's Algorithm : ";
        for(int i=0;i<this->vertices;i++){
            cout<<values[i]<<"  ";
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
    cout<<"\n Enter the edges of the graph:";
    g.getEdges();
    cout<<"\n The sorted Edges in the graph:";
    g.edgesInGraph();
    g.BellManFordAlgorithm();
    return 0;
}
/*
0 1 6
0 3 5
1 4 -1
3 5 -1
4 6 3
5 6 3
0 2 5
2 1 -2
2 4 1
3 2 -2
*/