#include <iostream>
#include <list>
#include <vector>
#include<queue>
using namespace std;
// Every graph contains the edge and the destination hence creating a utility class to store the information of that pair
class vertice
{
    int V, wt;

public:
    vertice(int v, int w)
    {
        this->V = v;
        this->wt = w;
    }
    getV()
    {
        return V;
    }
    getwt()
    {
        return wt;
    }
};

class graph
{
    int V;
    list<vertice> *adj; // adj will be adjaceny list containing vertice objects
public:
    graph(int v)
    {
        this->V = v;
        adj = new list<vertice>[V + 1];
    }
    void addedge(int u, int v, int wt)
    {
        // Creating vertice object and inserting the values inside it using the constructor of the vertice
        // and pushing it into the adjacency list
        vertice Vert(v, wt);
        vertice Vert1(u,wt);
        adj[u].push_back(Vert);
        adj[v].push_back(Vert1);
    }
    void shortest_distance(int source){
        vector<int> dist(V+1,INT_MAX);
        dist[source]=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        // This priority queue will be used in a such way that the priority will be based on distance of vertice from the source 

        pq.push({0,source});

        while (!pq.empty())
        {
            int d=pq.top().first;
            int u=pq.top().second;
            pq.pop();
            list<vertice> :: iterator it;
            for(it=adj[u].begin();it!=adj[u].end();it++){
                int v=it->getV();// Getting the adjacent vertice of u(The topmost element of the priority queue)
                int w=it->getwt();// Getting the weight of the edge between the parent(u) and the adjacent vertices(v)

                // If the distance the adjacent vertice is more than the combined distance of the 
                // parent distance from source and the edge weight then we update that adjacent vertice weight in the dist vector
                if(dist[v]>dist[u]+w){
                    dist[v]=dist[u]+w;
                    pq.push({dist[v],v});// Pushing the updated vertice into the priority queue
                }

            }
        }
        cout<<"The shorted distances for all the vertices from the source are "<<endl;
        for(int i=1;i<=V;i++)
            cout<<dist[i]<<" ";
        cout<<endl;
    }
    
};
int main()
{
    graph g = graph(5);
    g.addedge(1,2,2);
    g.addedge(1,4,1);
    g.addedge(4,3,3);
    g.addedge(2,3,4);
    g.addedge(2,5,5);
    g.addedge(3,5,1);
    g.shortest_distance(1);
    return 0;
}