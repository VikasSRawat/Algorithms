#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    public:
    vector<int> rank,parent;
    DisjointSet(int n){
        rank.resize(n+1,0); // initially all the ranks will be the same due to the fact that all are componenets themselves
        parent.resize(n+1,0);
        for(int i = 0 ; i <= n ; i++)
            parent[i] = i;
    }

    int findpar(int node){
        if(node == parent[node])// Ultimate parent is itself hence returning that node
            return node;
        return parent[node] = findpar(parent[node]);// Here we are updating each parent node along the path to the ultimate parent to reduce time complexity
    }
    void unionByRank(int u,int v){
        // We find the ultimate parent of both the vertices and check if they belong to the same component i.e., same ultimate parent or not
        // If not then we just check the ranks 
        int ult_pu = findpar(u); 
        int ult_pv = findpar(v);
        if(ult_pu == ult_pv)//belonging to the same component;
            return;
        if(rank[ult_pu] > rank[ult_pv]){
            parent[ult_pv] = ult_pu;
        }
        else if(rank[ult_pv] > rank[ult_pu]){
            parent[ult_pu] = ult_pv;
        }
        else{
            // if both ultimate parents have the same rank then we just join one component to another(your choice) and increase the other componenet's ultimate parent rank
            parent[ult_pv] = ult_pu;
            rank[ult_pu]++;
        }
    }
};
int main(){
    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
    // checking if 3 and 7 are part of the same component or not 
    if(ds.findpar(3) == ds.findpar(7))
        cout<<"Same component"<<endl;
    else
        cout<<"Not Same component"<<endl;
    // To find the out the number of components we just need to check how many different types of ultimate parents exists
    int count = 0;
    for(int i = 0 ; i < ds.parent.size() ; i++)
        if(ds.parent[i] == i)
            count++;
    cout<<"Number of components are : "<<count<<endl;
    return 0;
}
