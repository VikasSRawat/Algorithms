// BFS for traversal
#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;
class graph{
    int V;//Number of vertices in the graph excluding 0
    vector<list<int>> adj;//adjacency list

    public:

        graph(int v){
            this->V=v;
            adj.resize(V+1);
        }
        void addedge(int u,int v)//u-starting vertice of the edge      v-ending vertice of the edge
        {
            adj[u].push_back(v);
            adj[v].push_back(u);//for undirected graph
        }
        void bfs_sou(int source)//BFS WITH SOURCE
        {
            vector<int>vis(V+1,0);
            queue<int> q;
            //we push the source into the queue and make that vertice as visited
            q.push(source);
            // vis[source]=1;
            while(!q.empty()){
                //this will keep on running until the queue becomes empty i.e., all the reachable vertices have been visited
                int u=q.front();//popping the frontmost element from the queue
                q.pop();
                cout<<u<<" "; //printing the popped element and marking that vertice as visited
                vis[u]=1;
                // Taking all the adjacent vertice from the adjacency list and checking if they are not visited then we push them onto the queue and mark them visited
                for(auto it: adj[u]){
                    if(!vis[it])
                    {
                        vis[it]=1;
                        q.push(it);
                    }
                }
            }
        }
        void bfs_nosou(){//BFS traversal with no source 
            vector<int> vis(V+1,0);
            queue<int> q;
            //By doing this we will be able to make a traversal to all the vertices of a graph even if they multiple components
            for(int i=1;i<=V;i++){//we instead traverse all the vertices of the graph
                if(!vis[i]){//if not visited
                    q.push(i);
                    vis[i]=1;
                    //pushing the vertice into the queue and marking that vertice as visited
                    while (!q.empty())//this will follow the same process as the above while loop
                    {
                        int u=q.front();
                        q.pop();
                        cout<<u<<" ";
                        for(auto v: adj[u]){
                            if(!vis[v]){
                                vis[v]=1;
                                q.push(v);
                            }
                        }
                    }
                }
            }
        }
};
int main(){
    graph g=graph(7);
    g.addedge(1,2);
    g.addedge(2,1);
    g.addedge(2,3);
    g.addedge(2,7);
    g.addedge(3,2);
    g.addedge(3,5);
    g.addedge(5,3);
    g.addedge(5,7);
    g.addedge(7,2);
    g.addedge(7,5);
    g.addedge(4,6);
    g.addedge(6,4);
    // g.bfs_sou(3);
    g.bfs_nosou();

    return 0;
}