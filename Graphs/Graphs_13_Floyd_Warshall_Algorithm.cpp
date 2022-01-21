//Warshall's algorithm is used to Find the shortest path between the any two pair of vertices.
//The link of the explanation : https://www.youtube.com/watch?v=oNI0rf2P9gE&t=215s


#include<iostream>
#include<limits.h>
using namespace std;

class graph{
    private:
    int vertices;
    int edges;
    int infinity=INT_MAX;
    long long int **first;
    long long int **second;
    
    public:
    graph(int vertices,int edges){
        this->vertices=vertices+1;
        this->edges=edges;
        first=new long long int*[this->vertices];
        second=new long long int*[this->vertices];
        for(int i=0;i<this->vertices;i++){
            first[i]=new long long int[this->vertices];
            second[i]=new long long int[this->vertices];
        }
        for(int i=0;i<this->vertices;i++){
            for(int j=0;j<this->vertices;j++){
                if(i==j){
                    first[i][j]=0;
                    second[i][j]=0;
                }
                else{
                    first[i][j]=infinity;
                    second[i][j]=infinity;
                }
            }
        }
    }
    void setEdges(){
        int a,b,c;
        for(int i=0;i<this->edges;i++){
            cin>>a>>b>>c;
            first[a][b]=c;
        }
    }
    friend void floydWarshall(graph &g);
};

// 0 is not considered as the vertex value in any of the input graph.
void floydWarshall(graph &g){
    int count=1;
    for(int i=1;i<g.vertices;i++){
        cout<<"\n Value of i:"<<i;
        if(i%2==1){
            count=1;
            for(int j=1;j<g.vertices;j++){
                g.second[i][j]=g.first[i][j];
                g.second[j][i]=g.first[j][i];
            }
            for(int j=1;j<g.vertices;j++){
                for(int k=1;k<g.vertices;k++){
                    if(j!=k && j!=i && k!=i){
                        g.second[j][k]=min(g.first[j][k],g.first[j][i]+g.first[i][k]);
                    }
                }
            }
        }
        else{
            count=2;
            for(int j=1;j<g.vertices;j++){
                g.first[i][j]=g.second[i][j];
                g.first[j][i]=g.second[j][i];
            }
            for(int j=1;j<g.vertices;j++){
                for(int k=1;k<g.vertices;k++){
                    if(j!=k && j!=i && k!=i){
                        g.first[j][k]=min(g.second[j][k],g.first[j][i]+g.first[i][k]);
                    }
                }
            }
        }
    }
    if(count==1){
        for(int i=0;i<g.vertices;i++){
            cout<<"\n";
            for(int j=0;j<g.vertices;j++){
                cout<<g.second[i][j]<<"  ";
            }
        }
    }
    else{
        for(int i=0;i<g.vertices;i++){
            cout<<"\n";
            for(int j=0;j<g.vertices;j++){
                cout<<g.first[i][j]<<"  ";
            }
        }
    }
}

int main(){
    int vertices,edges;
    cout<<"\n Enter the number of vertices in the graph:";
    cin>>vertices;
    cout<<"\n Enter the number of edges in the graph:";
    cin>>edges;
    graph g(vertices,edges);
    cout<<"\n Enter the details of the edges of the graph:\n";
    g.setEdges();
    floydWarshall(g);
    return 0;
}