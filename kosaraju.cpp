#include<iostream>
#include<vector>
#include<list>
#include<stack>
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
        }
        void topo_DFS(int source,vector<bool> &vis,stack<int> &st){
            vis[source]=true;

            for(auto it: adj[source])
                if(vis[it]==false)
                    topo_DFS(it,vis,st);
            
            st.push(source);// Storing the topologically sorted elements inside the stack
        }

        // Normal traversal of a transposed adjacency list
        void DFS(int source,vector<bool> &vis,list<int> *tra){
            cout<<source<<" ";
            vis[source]=true; 
            for(auto it:tra[source])
                if(!vis[it])
                    DFS(it,vis,tra);
        }
        void kosaraju(){
            stack<int> st;
            vector<bool> vis(V+1,false);

            list<int> *tra;// For storing the transpose of the adjacent list
            tra=new list<int>[V+1];

            for(int i=1;i<=V;i++)
                if(!vis[i])
                    topo_DFS(i,vis,st);// Getting the topo logically sorted elements inside the stack
            
            // Adding elements into the transpose of the matrix
            for(int i=1;i<=V;i++){
        // Adding the adjacent vertices of i in adj as the parent/source in tra and pushing the parent in i as adjacent vertices of it in tra
                vis[i]=false;//Marking the vertices as false for dfs traversal later on
                for(auto it: adj[i])
                    tra[it].push_back(i);
            }

            // Now getting the strongly components of the graph
            while(!st.empty()){
                int i=st.top();
                st.pop();
                if(!vis[i]){
                    cout<<"Strongly Component graph : "<<endl;
                    DFS(i,vis,tra);//Performing DFS based on the order of the stack and printing each SCC in the function itself
                    cout<<endl;
                }
            }
        }
};
int main()
{
    graph g = graph(5);
    g.addedge(1,2);
    g.addedge(2,3);
    g.addedge(3,1);
    g.addedge(2,4);
    g.addedge(4,5);
    g.kosaraju();
    return 0;
}