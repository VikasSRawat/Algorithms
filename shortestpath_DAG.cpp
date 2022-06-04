#include <iostream>
#include <list>
#include <vector>
#include <stack>
using namespace std;
// Every graph contains the edge and the destination hence creating a utility class to store the information of that pair
class vertice
{
    int V, wt;

public:
    vertice(int v, int w)
    {
        this->V = v;
        this->wt = w;
    }
    getV()
    {
        return V;
    }
    getwt()
    {
        return wt;
    }
};

class graph
{
    int V;
    list<vertice> *adj; // adj will be adjaceny list containing vertice objects
public:
    graph(int v)
    {
        this->V = v;
        adj = new list<vertice>[V + 1];
    }
    void addedge(int u, int v, int wt)
    {
        // Creating vertice object and inserting the values inside it using the constructor of the vertice
        // and pushing it into the adjacency list
        vertice Vert(v, wt);
        adj[u].push_back(Vert);
    }

    void topo_DFS(int source, vector<bool> &vis, stack<int> &st)
    {
        vis[source] = true;
        list<vertice>::iterator it; // Making an iterator for iterating the adjacent vertices of the source
        for (it = adj[source].begin(); it != adj[source].end(); it++)
        {
            vertice vert = *it;
            if (vis[vert.getV()] == false)
                topo_DFS(vert.getV(), vis, st);
        }

        st.push(source);
    }
    void shortest_path(int s)
    {
        stack<int> st;
        vector<bool> vis(V + 1, false);
        vector<int> dist(V + 1, INT_MAX);
        for (int i = 1; i <= V; i++)
            if (!vis[i])
                topo_DFS(i, vis, st);

        dist[s] = 0; // distance of source from itself is always 0

        while (st.empty() == false)
        {
            int u = st.top();
            st.pop();

            list<vertice>::iterator it;
            if (dist[u] != INT_MAX)
            {
                for (it = adj[u].begin(); it != adj[u].end(); it++)
                {                                                 // taking the adjacent vertices of the popped element
                    if (dist[it->getV()] > (dist[u] + it->getwt())) // If the distance of the current vertice is more than the distance of the parent vertce + the edge weigth between those 2 vertice then we update that distance vector.
                        dist[it->getV()] = dist[u] + it->getwt(); // it->getwt will get the edge weight between the parent and the current vertice using the utility function in vertice
                }
            }
        }

        for (int i = 1; i <= V; i++)
            (dist[i] == INT_MAX) ? cout << "INF " : cout << dist[i] << " ";
        cout << endl;
    }
};
int main()
{
    graph g = graph(6);
    g.addedge(1, 2, 2);
    g.addedge(1, 5, 1);
    g.addedge(2, 3, 3);
    g.addedge(5, 3, 2);
    g.addedge(5, 6, 4);
    g.addedge(6, 4, 1);
    g.addedge(3, 4, 6);
    g.shortest_path(1);
    return 0;
}