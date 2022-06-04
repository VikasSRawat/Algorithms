#include<iostream>
#include<vector>
#include<list>
#include<stack>
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
        void topo_DFS(int source,vector<bool> &vis,stack<int> &st){
            vis[source]=true;

            for(auto it: adj[source])
                if(vis[it]==false)
                    topo_DFS(it,vis,st);
            
            st.push(source);
        }
        void toposort(){
            vector<bool> vis(V+1,0);
            stack<int> st;

            for(int i=1;i<=V;i++)
                if(vis[i]==false)
                    topo_DFS(i,vis,st);
            
            while(st.empty()==false){
                cout<<st.top()<<" ";
                st.pop();
            }
            cout<<endl;
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
    g.toposort();
    return 0;
}