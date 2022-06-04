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
        void addedge(int u,int v){
            adj[u].push_back(v);
        }
        bool checkcycle(vector<bool>& vis,vector<bool>& dfsvis,int source){

                vis[source]=true;// Marking the source as true for the overall the vertices which we have visited 
                dfsvis[source]=true; // Marking the source as true for the dfs path which we are going to traverse

                for(auto it: adj[source]){
                    if(!vis[it] and checkcycle(vis,dfsvis,it))// Calls recursively for that adjacent vertice for checking a cycle
                        return true;

                    else if(dfsvis[it]==true) //If the adjacent vertice has been visited in the current dfs path then returns true
                        return true;
                }

            dfsvis[source]=false;// If the path reaches its end and no cycle was found then it will backtrack till starting vertice of the path
            return false;// returns false for the particular path
        }
        bool iscycle(){
            vector<bool> vis(V+1,false);
            vector<bool> dfsvis(V+1,false);

            for(int i=1;i<=V;i++)
                if(!vis[i] and checkcycle(vis,dfsvis,i))
                    return true;

            return false;
        }
};
int main()
{
    graph g=graph(4);
    g.addedge(1,2);
    g.addedge(2,3);
    g.addedge(3,2);
    // cout<<g.iscycle()<<endl;
    if(g.iscycle())
        cout<<"cycle detected";
    else
        cout<<"cycle not detected";
    
    return 0;
}
