#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

class graph{
    private:
    int vertices;
    int edges;
    vector<vector<vector<int>>> graph_list;
    
    public:
    graph(int vertices,int edges){
        this->vertices=vertices;
        this->edges=edges;
        for(int i=0;i<this->vertices;i++){
            vector<vector<int>> t;
            graph_list.push_back(t);
        }
    }
    void getEdges(){
        int a,b,c;
        for(int i=0;i<this->edges;i++){
            cin>>a>>b>>c;
            graph_list[a].push_back({b,c});
            graph_list[b].push_back({a,c});
        }
    }
    void display(){
        for(int i=0;i<this->vertices;i++){
            cout<<"\n "<<i<<" -> ";
            for(int j=0;j<graph_list[i].size();j++){
                cout<<" "<<graph_list[i][j][0]<<" ("<<graph_list[i][j][1]<<") ";
            }
        }
    }
    void PrimAlgorithm(int start){
        vector<int> visited(this->vertices);
        vector<int> minimum(this->vertices,INT_MAX);
        vector<int> parent(this->vertices);
        
        minimum[start]=0;
        int previous=-1;
        
        int count=0;
        while(count!=this->vertices){
            int Min=INT_MAX;
            int index;
            for(int i=0;i<this->vertices;i++){
                if(Min>minimum[i] && visited[i]==0){
                    Min=minimum[i];
                    index=i;
                }
            }
            parent[index]=previous;
            previous=index;
            count++;
            for(int i=0;i<graph_list[index].size();i++){
                if(visited[graph_list[index][i][0]]==0){
                    minimum[graph_list[index][i][0]]=min(minimum[graph_list[index][i][0]],graph_list[index][i][1]);
                }
            }
            visited[index]=1;
        }
        cout<<"\n Parent:";
        for(int i=0;i<this->vertices;i++){
            cout<<parent[i]<<" ";
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
    cout<<"\n The Adjacency list of the graph:";
    g.display();
    int start;
    cout<<"\n Enter the starting vertex for the prim's process:";
    cin>>start;
    g.PrimAlgorithm(start);
    return 0;
}
/*
0 5 10
5 4 25
3 4 22
2 3 12
1 2 16
0 1 28
1 6 14
4 6 24
3 6 18
*/