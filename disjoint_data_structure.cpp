#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int> rank,parent;
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        for(int i = 0 ; i <= n ; i++)
            parent[i] = i;
    }

    int findpar(int node){
        if(node == parent[node])// Ultimate parent is itself hence returning that node
            return node;
        return parent[node] = findpar(parent[node]);// Here we are updating each parent node along the path to the ultimate parent to reduce time complexit
    }
    void unionByRank(int u,int v){
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
    
    return 0;
}
