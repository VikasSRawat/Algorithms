#include<iostream>
#include<vector>
#include<list>
using namespace std;
class graph{    
    list<int> *adj;
    int V;
    public:
        graph(int v){
            this->V=v;
            adj=new list<int>[V+1];
        }
        void addedge_undirected(int u,int v){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        void addedge_directed(int u,int v){
            adj[u].push_back(v);
            // adj[v].push_back(u);
        }
        bool checkcycle(vector<int> vis,int source,int par){
            vis[source]=1;
            for(auto it:adj[source]){
                if(!vis[it]){
                    if(checkcycle(vis,it,source))
                        return true;
                }
                else if(it!=par)
                    return true;
            }
            return false;
        }
        bool iscycle(){
            vector <int> vis(V+1,0);
            for(int i=1;i<=V;i++)
                if(checkcycle(vis,i,-1))
                    return true;
            return false;
        }
};
int main()
{
    graph g=graph(3);
    g.addedge_undirected(1,2);
    g.addedge_undirected(2,3);
    if(g.iscycle())
        cout<<"cycle detected";
    else
        cout<<"cycle not detected";
    
    return 0;
}
