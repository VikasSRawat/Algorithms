#include<iostream>
#include<vector>
#include<list>
#include<queue>

using namespace std;
class graph{
    vector<list<int>> adj;
    int V;
    public:
        graph(int v){
            this->V=v;
            adj.resize(V+1);
        }
        void addedge(int u,int v){
            adj[u].push_back(v);
        }
        bool topo_BFS(){
            vector<int> topo(V+1,0),indeg(V+1,0);
            queue<int> q;
            for(int i=1;i<=V;i++)//for getting all the indegrees of the vertices
                for(auto  it: adj[i])// it is the adjacent vertice of i hence it has an indegree i.e., i
                    indeg[it]++;// Increase the frequency of that indegree
            for(int i=1;i<=V;i++)            
                if(indeg[i]==0)
                    q.push(i);// Pushing all those vertices which don't have any indegree
            int count=0;//Due to 1-based indexing of the graph's vertices
            while(!q.empty()){
                int a=q.front();
                q.pop();
                count++;// The only difference we are doing is that we are counting the number of elements in the topological sorted
                //Printing the frontmost element as it won't be dependent on any other vertice
                for(auto it:adj[a]){
                    indeg[it]--;//Decreasing all the indegrees of those vertices dependent of the printed vertice
                    if(indeg[it]==0)// Pushing all those vertices which don't have any indegree
                        q.push(it);
                }
            }
            if(count==V)//If the count is equal to the number of vertices then it will return a false as a topological sort was generated
                return false;
            else
                return true;

            // return topo;
        }
};
int main()
{
    graph g = graph(3);
    // g.addedge(6,1);
    // g.addedge(6,3);
    // g.addedge(5,1);
    // g.addedge(5,2);
    // g.addedge(3,4);
    // g.addedge(4,1);
    g.addedge(1,2);
    g.addedge(2,3);
    g.addedge(3,1);
    if(g.topo_BFS())
        cout<<"Cycle detected"<<endl;
    else
        cout<<"Cycle Not detected"<<endl;
    return 0;
}