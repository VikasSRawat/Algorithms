#include <bits/stdc++.h>
using namespace std;
#define V 4
void floyd_warshall_shortest_path(int adj[V][V]){
    for(int k=0;k<V;k++){// For trying all intermediate vertices
        for(int i=0;i<V;i++){ // For all possible starting positions(u)
            for(int j=0;j<V;j++){// For all possible ending position(v)
                if (adj[i][k]==INT_MAX || adj[k][j]==INT_MAX)
                    continue;
                else
                    adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
            }
        }
    }
}
void negative_cycle(int adj[V][V]){

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(adj[i][j]<=-1){
                cout<<"Negative edge cycle detected"<<endl;
                return;
            }
        }
    }
}
void print(int adj[V][V]){
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++)
            cout<<adj[i][j]<<" ";
        cout<<endl;
    }
}
int main()
{

    int adj[V][V]={
        {0,3,INT_MAX,5},
        {2,0,INT_MAX,8},
        {INT_MAX,1,0,INT_MAX},
        {INT_MAX,INT_MAX,2,0}
    };
    floyd_warshall_shortest_path(adj);
    negative_cycle(adj);
    print(adj);
    return 0;
}
