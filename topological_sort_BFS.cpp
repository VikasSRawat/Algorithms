#include<iostream>
#include<vector>
#include<list>
#include<queue>

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
        void topo_BFS(){
            vector<int> topo(V+1,0),indeg(V+1,0);
            queue<int> q;
            for(int i=1;i<=V;i++)//for getting all the indegrees of the vertices
                for(auto  it: adj[i])// it is the adjacent vertice of i hence it has an indegree i.e., i
                    indeg[it]++;// Increase the frequency of that indegree
            for(int i=1;i<=V;i++)            
                if(indeg[i]==0)
                    q.push(i);// Pushing all those vertices which don't have any indegree

            while(!q.empty()){
                int a=q.front();
                q.pop();
                //Printing the frontmost element as it won't be dependent on any other vertice
                cout<<a<<" ";
                for(auto it:adj[a]){
                    indeg[it]--;//Decreasing all the indegrees of those vertices dependent of the printed vertice
                    if(indeg[it]==0)// Pushing all those vertices which don't have any indegree
                        q.push(it);
                }
            }
            // return topo;
        }
};
int main()
{
    graph g = graph(6);
    g.addedge(6,1);
    g.addedge(6,3);
    g.addedge(5,1);
    g.addedge(5,2);
    g.addedge(3,4);
    g.addedge(4,1);
    g.topo_BFS();
    // vector<int> v=g.topo_BFS();
    // for(int i=0;i<v.size()-1;i++)
    //     cout<<v[i]<<" ";
    // cout<<endl;
    return 0;
}
