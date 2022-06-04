#include<iostream>
#include<vector>
#include<list>
using namespace std;
class graph{
    vector<list<int>> adj;
    int V;
    public:
        graph(int v){
            this->V=v;
            adj.resize(V+1);
        }
        void addedge_undirected(int u,int v){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        void addedge_directed(int u,int v){
            adj[u].push_back(v);
            // adj[v].push_back(u);
        }
        void DFS(int source,vector<int> &vis){
            cout<<source<<" ";
            vis[source]=1;
            for(auto it:adj[source])
                if(!vis[it])
                    DFS(it,vis);
        }
        void DFS_traverse_nosou(){//DFS traversal without any source
        //this will enable dfs to traverse to all the vertices of all the components
        // Hence for every new component it will take a new source and call dfs from it
            vector<int> vis(V+1,0);
            for(int i=1;i<=V;i++){
                if(!vis[i])
                    DFS(i,vis);
            }
        }
        void DFS_traverse_sou(int v){
            vector<int> vis(V+1,0);
            cout<<v<<" ";
            vis[v]=1;
            for(auto it: adj[v])
                if(!vis[it])
                    DFS(it,vis);
        }
};
int main()
{
    graph g=graph(4);
    // g.addedge(1,2);
    // g.addedge(2,4);
    // g.addedge(2,7);
    // g.addedge(4,2);
    // g.addedge(4,6);
    // g.addedge(6,4);
    // g.addedge(6,7);
    // g.addedge(7,6);
    // g.addedge(7,2);
    // g.addedge(3,5);
    // g.addedge(5,3);
    // g.DFS_traverse_nosou();
    g.addedge_undirected(0, 1);
    g.addedge_undirected(0, 2);
    g.addedge_undirected(1, 2);
    g.addedge_undirected(2, 0);
    g.addedge_undirected(2, 3);
    g.addedge_undirected(3, 3);
    g.DFS_traverse_sou(2);
    return 0;
}