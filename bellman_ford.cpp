#include <iostream>
#include <list>
#include <vector>
#include<queue>
using namespace std;
// Every graph contains the edge and the destination hence creating a utility class to store the information of that pair
class vertice
{
    public:
    int u,v,wt;
    vertice(int u,int v,int w){
        this->u=u;
        this->v=v;
        this->wt=w;
    }
};

class graph
{
    int V;
    vector<vertice> edge;
public:
    graph(int v)
    {
        this->V = v;
    }
    void addedge(int u, int v, int wt)
    {
        //Adding an edge to the vector using vertice constructor
        vertice obj = vertice(u,v,wt);
        edge.push_back(obj);
    }
    void shortest_distance(int source){

        vector<int> dist(V+1,INT_MAX);
        dist[source]=0;

        for(int i=1;i<=V;i++){
            for(auto it: edge)// Relaxing each edge
                if(dist[it.u]+it.wt<dist[it.v])
                    dist[it.v]=dist[it.u]+it.wt;
        }
        int flag=0;
        for(auto it:edge){//Relaxing 1 more time to see if there exists a negative cycle 
            if(dist[it.u]+it.wt<dist[it.v])// If any changes occur then we will
            {
                cout<<"Negative cycle"<<endl;
                flag=1;
                break;
            }
        }
        if(flag)
            return ;
        
        cout<<"The shortes distance for all the vertices from the source "<<source<<" is "<<endl;
        for(int i=1;i<=V;i++)
            cout<<i<<" "<<dist[i]<<endl;//Printing out the distance of each vertice from each source
    }
    
};
int main()
{
    graph g = graph(6);
    g.addedge(1,2,5);
    g.addedge(2,3,-2);
    g.addedge(2,6,-3);
    g.addedge(6,4,1);
    g.addedge(4,3,6);
    g.addedge(3,5,3);
    g.addedge(4,5,-2);
    g.shortest_distance(1);
    return 0;
}