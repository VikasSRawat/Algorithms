#include<bits/stdc++.h>
#include<vector>
using namespace std;
// Note pls keep in mind in the order which we pass the arguements
class node{
    public:
    int wt,u,v;
    node(int wt,int u,int v){
        this->u=u;
        this->v=v;
        this->wt=wt;
    }
};
int findpar(int u,vector<int>& parent){
    if(u==parent[u])
        return u;// The parent of the set will have the same parent as itself i.e., parent[u]=u
    return parent[u]=findpar(parent[u],parent);// Keeps on going until we find the root i.e., the parent of the set
        
}
void Union(int u,int v,vector<int>& parent,vector<int>& rank){
    u=findpar(u,parent);
    v=findpar(v,parent);
    
    if(u!=v)
    {
        if(rank[u]<rank[v])
            parent[u]=v;
        else if(rank[v]<rank[u])
            parent[v]=u;
        else
        {
            parent[v]=u;
            rank[u]++;
        }
    }
}
bool comp(node a,node b){
    return a.wt<b.wt;
}
int main()
{
    int n,m;
    cout<<"Enter the number of edges and vertices : ";
    cin>>n>>m;
    vector<int> parent(m);
    vector<int> rank(m,0);

    vector<node> edges;
    cout<<"Enter the edge weight , the starting vertex of the edge and the ending vertex of the edge"<<endl;
    for(int i=0;i<n;i++){
        int wt,u,v;
        cin>>wt>>u>>v;
        edges.push_back(node(wt,u,v));// Will store the edge weight , u and v of the edge in a linear order 
    }
    sort(edges.begin(),edges.end(),comp);// Sorting the edges based on their weights

    for(int i=0;i<m;i++)
        parent[i]=i;

    int cost=0;
    vector<pair<int,pair<int,int>>> MST;
    for(auto it:edges){// Traverse the sorted edges vector untill all the vertices are part of the MST
        if(findpar(it.u,parent)!=findpar(it.v,parent)){// If there parents are not same hence they are not in the same set meaning that one is not part of the MST hence we will insert it into the MST and then unite
            MST.push_back({it.u,{it.v,it.wt}});
            //inserting starting of the edge , ending of the edge and the weight of the edge inside MST
            cost+=it.wt;// Adding the weight of that edge
            Union(it.u,it.v,parent,rank);
        }
    }
    // vector<pair<int,pair<int,int>>> :: iterator it;
    cout<<endl;
    for(auto it:MST){
        cout<<it.first<<" - "<<it.second.first<<"           "<<it.second.second<<endl;
    }
    cout<<"The total cost of the MST is "<<cost<<endl;

    return 0;
}