#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

class graph{
    private:
    int vertices;
    int edges;
    vector<vector<int>> adj_list;
    
    public:
    graph(int vertices,int edges){
        this->vertices=vertices;
        this->edges=edges;
        for(int i=0;i<this->vertices;i++){
            vector<int> t;
            adj_list.push_back(t);
        }
    }
    void getEdges(){
        for(int i=0;i<this->edges;i++){
            int a,b;
            cin>>a>>b;
            adj_list[a].push_back(b);
            adj_list[b].push_back(a);
        }
    }
    void display(){
        for(int i=0;i<this->vertices;i++){
            cout<<"\n"<<i<<" -> ";
            for(int j=0;j<adj_list[i].size();j++){
                cout<<adj_list[i][j]<<"  ";
            }
        }
    }
    void Bridges(int i,int& count,int& answer,vector<int>& parent,vector<int>& discover,vector<int>&nearest){
        discover[i]=count;
        count++;
        
        for(int j=0;j<adj_list[i].size();j++){
            if(discover[adj_list[i][j]]==-1){
                
                parent[adj_list[i][j]]=i;
                Bridges(adj_list[i][j],count,answer,parent,discover,nearest);
                
            }
        }
        for(int j=0;j<adj_list[i].size();j++){
            if(adj_list[i][j]!=parent[i]){
                nearest[i]=min(nearest[i],min(discover[adj_list[i][j]],nearest[adj_list[i][j]]));
            }
        }
        if(parent[i]!=-1 && nearest[i]>discover[parent[i]]){
            cout<<"\n ("<<i<<","<<parent[i]<<")";
            answer++;
        }
    }
    int func(){
        int count=1,answer=0;
        vector<int> parent(this->vertices,-1);
        vector<int> discover(this->vertices,-1);
        vector<int> nearest(this->vertices,INT_MAX);
        Bridges(0,count,answer,parent,discover,nearest);
        return answer;
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
    cout<<"\n Enter the details of the edges of the graph:";
    g.getEdges();
    cout<<"\n The adjacency list of the graph:";
    g.display();
    cout<<"\n The number of bridges in the graph:"<<g.func();
    return 0;
}
/*
0 1
1 2
2 3
*/