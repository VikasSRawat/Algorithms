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
        bool checkforcycle(int source,vector<int> &vis){
            queue<pair<int,int>> q;//making a queue which will contain the vertice and its parent
            vis[source]=1;//marking the source as visited
            q.push({source,-1});//initializing the vertice
            while(!q.empty()){
                int u=q.front().first;//for the vertice
                int par=q.front().second;//for the parent of the vertice
                q.pop();
                for(auto it:adj[u]){
                    if(!vis[it]){
                        vis[it]=1;
                        q.push({it,u});//pushing the adjacent vertices and its parent into the queue
                    }
                    else if(par!=it)//if the adjacent vertice has been visited and is not equal to its parent/previous hence it will return true
                        return true;
                }
            }
            return false;//default response if the queue becomes empty and no cycle was detected
        }
        bool iscycle(){//In this we will run a to get through all the for loops
            vector<int> vis(V+1,0);
            for(int i=1;i<=V;i++){
                if(!vis[i]){
                        bool var=checkforcycle(i,vis);
                        // cout<<var<<endl;
                        if(var)// We will check if there is a cycle present for 
                            return true;//this particular vertice by traversing from that vertice using BFS
                }
            }
            return false;
        }
};
int main(){
    
    graph g= graph(3);
    g.addedge(1,2);
    g.addedge(2,3);
    int var=g.iscycle();
    if(var!=0)
        cout<<"Cycle present"<<endl;
    else
        cout<<"Cycle not present"<<endl;
    return 0;
}