// Problem link: https://www.geeksforgeeks.org/introduction-to-disjoint-set-data-structure-or-union-find-algorithm/
#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int src, dest;
};

struct Graph {
    int V, E;
    Edge *edge;

    Graph(int V, int E)
    {
        this->V = V;
        this->E = E;
    }
};

Graph* createGraph(int V, int E)
{
    Graph* graph = new Graph(V, E);
    graph->edge = new Edge[graph->E];
    
    return graph;
}

// Function to find the subset of an element i
int find(int parent[], int i)
{
    if(parent[i] == i)
    {
        return i;
    }
    return find(parent, parent[i]);
}

void Union(int parent[], int x, int y)
{
    parent[x] = y;
}

int isCycle(Graph* graph)
{
    int* parent = new int[graph->V];

    for(int i = 0; i < graph->V; i++) 
        parent[i] = i;
    
    for(int i = 0; i < graph->E; i++)
    {
        int x = find(parent, graph->edge[i].src);
        int y = find(parent, graph->edge[i].dest);

        if(x == y)
            return 1;
        
        Union(parent, x, y);
    }
    return 0;
}

int main() {
    int V = 3, E = 3;
    Graph* graph = createGraph(V, E);

    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
 
    // add edge 1-2
    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
 
    // add edge 0-2
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
 
    if (isCycle(graph))
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";

    return 0;
}