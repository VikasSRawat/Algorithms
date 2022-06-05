#include<bits/stdc++.h>
#include<vector>
#include<queue>
using namespace std;

int cost=0;// The total cost of the spanning tree

void primMST(int V,vector<pair<int,int>> adj[]){
    

    vector<bool> MST(V,false);// Will see if the vertice has been inserted into the spanning tee
    vector<int> parent(V,-1);// Parent will keep track of each vertices parent i.e., after removing some edges
    vector<int> distance(V,INT_MAX); //Distance will keep track of the index's distance(edge weight) from its parent


    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;// weight , vertice pairs will be inserted into the priority with the priority set given to the weights( in min heap order)
    
    distance[0]=0;// Distance of the source from itself will always be 0
    parent[0]=0;

    pq.push({0,0});

    while(!pq.empty()){

        int u=pq.top().first;
        pq.pop();
        MST[u]=true;

        for(auto it: adj[u]){

            int v=it.first;// getting the edge weight between the adjacent vertice and the parent
            int wt=it.second;// getting the adjacent vertice from the list

            if(MST[v]==false && wt<distance[v]){
                // If v is not part of the Minimum spanning tree and the edge weight from the parent is less 
                // than the mentioned in the distance vector then :
                parent[v]=u;// We update the parent vector for the adjacent vector
                distance[v]=wt;
                pq.push({v,wt});//we push the new edge weight and the vertice onto the queue and then check for its adjacent vertice
            }
        }
    }
    // The minimum priority queue makes it so that we will insert those vertices into the MST which will have the least edge weight
    // Hence the getting the minimal total cost of the tree

    // Printing the MST's parent  and its adjacent vertices along with its edge weight
    for(int i=1;i<V;i++){
        cout<<parent[i]<<" - "<<i<<"     edge weight = "<<distance[i]<<endl;
        if(distance[i]!=INT_MAX)
            cost+=distance[i];
    }
}
int main()
{
    int n,m;
    cout<<"Enter the the number of vertices and number of edges"<<endl;
    cin>>n>>m;// N= number of vertices , m=number of edges
    vector<pair<int,int>> adj[n];//adjacency list containing parents and its adjacent vertices with the edge weight of each adjacent vertice
    cout<<"Enter the starting vertice, ending vertice and edge weight"<<endl;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    primMST(n,adj);
    cout<<"The total cost is "<<cost<<endl;
    return 0;
}