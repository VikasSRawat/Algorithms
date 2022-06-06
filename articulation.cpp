#include<iostream>
#include<vector>
#include<list>
using namespace std;
class graph{
    // vector<list<int>> adj;
    list<int> *adj;
    int V;
    public:
        graph(int v){
            this->V=v;
            // adj.resize(V+1);
            adj=new list<int>[V+1];
        }
        void addedge(int u,int v){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        void DFS(int source,int parent,vector<bool> &vis,vector<int> &tin,vector<int> &low,int &timer,vector<bool> &articulation){
            vis[source]=true;
            tin[source]=low[source]=timer++;//setting the current timer for both low and current time vectors
            int child=0;
            for(auto it: adj[source]){
                if(it==parent)// If the only adjacent vertice is the parent of the adjacent itself then skip
                    continue;
                if(!vis[it]){
                    DFS(it,source,vis,tin,low,timer,articulation);
                    low[source]=min(low[source],low[it]);// The low insertion of source will always be the minimum of its adjacent vertice
                    if(low[it]>=tin[source] && parent!=-1)
                        articulation[source]=true;// It will mark true for the articulation point if the condition is met
                    child++;// Evey adjacent vertice is a child of the source hence it will increment for those vertices which has not been visited
                }
                else
                    low[source]=min(low[source],low[it]);
                    // We update the low of this particular vertice as this vertice can have more than one adjacent vertice where that adjacent vertice might have lower least inserting time.
                if(parent==-1 && child>1)// Special case for the starting vertex 
                    articulation[source]=true;
            }
        }
        void DFS_traverse_nosou(){
            vector<bool> vis(V+1,false);
            vector<int> low(V+1,-1);// Lowest insertion time of vertice
            vector<int> tin(V+1,-1);// current insertion time of vertice
            vector<bool> articulation(V+1,false);// Will be marked true for all those vertices which are articulation points
            int timer=0;// The timer will keep track of the current time of insertion so initially 0
            for(int i=1;i<=V;i++){
                if(!vis[i])
                    DFS(i,-1,vis,tin,low,timer,articulation);// Calling DFS for different components of the graph with parent as 0
            }
            cout<<"The articulation points are : "<<endl;
            for(int i=0;i<articulation.size();i++)
                if(articulation[i])
                    cout<<i<<" ";
            cout<<endl;
        }
};
int main()
{
    graph g=graph(12);
    g.addedge(1,2);
    g.addedge(1,4);
    g.addedge(3,4);
    g.addedge(3,2);
    g.addedge(4,5);
    g.addedge(5,6);
    g.addedge(6,7);
    g.addedge(6,9);
    g.addedge(8,7);
    g.addedge(8,9);
    g.addedge(8,10);
    g.addedge(10,11);
    g.addedge(10,12);
    g.addedge(11,12);
    g.DFS_traverse_nosou();
    return 0;
}