#include<iostream>
#include<vector>
using namespace std;


int findpar(int x,int *parent){
    if (parent[x] != x) 
        parent[x] = findpar(parent[x],parent);// we will keep on recursively call findpar until we find the parent of the set and update the current nodes parent hence this is also called path compression
 
    return parent[x];// If the node is itself the parent then we have reached the parent of the vertice and returns that node
}

void union_set(int u,int v,int *parent,int *rank_set){
    u=findpar(u,parent);
    v=findpar(v,parent);
    // Getting the parent of each node/vertex and comparing the ranks of each vertice

    // Smaller rank sets gets absorbed by the bigger rank sets
    if(rank_set[u]>rank_set[v])
        parent[v]=u;
    else if(rank_set[u]<rank_set[v])
        parent[v]=u;
    //If the rank of both the sets are same then 
    else{
        parent[v]=u;
        rank_set[u]++;// Incrementing the rank of the parent of the new set
    }
}


int main()
{
    int *rank_set;
    int *parent;
    int n=6;

    parent=new int[n+1];
    rank_set=new int[n+1];

    for(int i=1;i<=n;i++){
        rank_set[i]=0;//setting the rank of every vertice as 0
        parent[i]=i;//initially every vertice is their own parent
    }
    union_set(1,2,parent,rank_set);
    union_set(3,2,parent,rank_set);
    union_set(4,5,parent,rank_set);
    union_set(5,6,parent,rank_set);

    for(int i=1;i<=n;i++)
        cout<<parent[i]<<" -> "<<i<<endl;

    if(findpar(3,parent)!=findpar(1,parent))
        cout<<"Not same components"<<endl;
    else
        cout<<"Same components"<<endl;
    
    return 0;
}