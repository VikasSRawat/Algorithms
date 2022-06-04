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
        void shortestpath_BFS(int source,int des)//BFS WITH SOURCE
        {
            vector<bool> vis(V+1,false);
            vector<int> pred(V+1,-1),dist(V+1,INT_MAX);
            dist[source]=0;// The distance of the source from itself will always be 0
            vis[source]=true;// Marking the source as visited
            bool flag=false;
            queue<int> q;
            q.push(source);// Pushing the source into the queue to perform BFS

            while(!q.empty()){
                int u=q.front(); // Removing the frontmost element from the queue
                q.pop();
                for(auto it: adj[u]){ // Checking the current element's adjacent vertices 
                    if(!vis[it]){// If not visited then it will mark it as visited and includes its pred. as u(the front element from the queue)
                        vis[it]=true;
                        pred[it]=u;
                        q.push(it);
                        dist[it]=dist[u]+1;// Setting its distance by incrementing its parent distance
                    } 
                    if(it==des)//If destination is reached then it will return true
                    {
                        flag= true;
                        break;
                    }
                }
                if(flag)
                    break;
            }
            // The shortest path is calculated when say for ex :
            // if 2 vertices point to the same vertice then the pointed vertice's parent will be the one which will have
            // the shortest path from the source i.e., as it is the shorter path of the two hence it will be visited first as
            // the second path would have taken more time to reach the pointed vertice as it would have to visit more vertices

            if(flag==false){
                cout<<"The source and the destination are not connected"<<endl;
                return;
            }
            cout<<"The shortest path length is "<<dist[des]<<endl;
            cout<<"The path is "<<endl;
            vector<int> :: iterator it;
            vector<int>  path;
            int crawl=des;
            // Backtracking throught predecessor to get the path
            while (pred[crawl]!=-1)
            {
                path.push_back(pred[crawl]);// Pushing the vertice onto the path
                crawl=pred[crawl];// Backtracking
            }

            for(int i=path.size()-1;i>=0;i--)
                cout<<path[i]<<" -> ";
            cout<<des<<endl;
        }
        
        
};
int main(){
    graph g=graph(10);
    g.addedge(1,2);
    g.addedge(1,4);
    g.addedge(2,3);
    g.addedge(4,5);
    g.addedge(5,6);
    g.addedge(6,7);
    g.addedge(3,7);
    g.addedge(7,8);
    g.addedge(7,9);
    g.addedge(8,9);
    g.addedge(10,0);
    g.shortestpath_BFS(1,10);

    return 0;
}