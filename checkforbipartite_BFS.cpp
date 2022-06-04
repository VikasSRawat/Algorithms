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
        bool isbipartite(vector<int> &color,int source){
            queue<int> q;
            color[source]=1;//Setting the color of the 1st vertice
            q.push(source);
            while(!q.empty()){
                int u=q.front();
                q.pop();

                for(auto it: adj[u]){
                    if(color[it]==-1){
                        color[it]=1-color[u];
                        q.push(it);
                    }//if the adjacent vertice has not been assigned a color
                        //It will assign a color opposite to the parent 
                    else if(color[it]==color[u])//if it has been colored then it will check if color of adjacent vertice is equal to the current vertice and hence will return false
                        return false;
                }
            }
            return true;
        }
        bool check(){
            vector<int> color(V+1,-1);// Making a color vector to store the color of the vertice and initializing it as -1
            for(int i=1;i<=V;i++)
                if(color[i]==-1)//Checking for different components if they have been not assigned a color
                    if(!isbipartite(color,i))
                        return false;
            return true;
        }
};
int main(){
    graph g=graph(8);
    g.addedge(1,2);
    g.addedge(2,3);
    g.addedge(2,4);
    g.addedge(3,5);
    g.addedge(4,6);
    g.addedge(6,5);
    g.addedge(5,7);
    g.addedge(7,8);
    if(g.check())
        cout<<"Bipartite "<<endl;
    else
        cout<<"Not Bipartite "<<endl;
    return 0;
}