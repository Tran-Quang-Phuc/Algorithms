#include <bits/stdc++.h>

using namespace std;

struct DSU {
    int* parent;
    int* rank;

    DSU(int n) {
        this->parent = new int[n];
        this->rank = new int[n];

        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find(int i)
    {
        // find the subset contains element i
        if(this->parent[i] == i)
            return i;
        return find(this->parent[i]);
    }

    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);

        if(s1 != s2)
        {
            if(rank[s1] < rank[s2])
                parent[s1] = s2;
            else if(rank[s1] > rank[s2])
                parent[s2] = s1;
            else {
                parent[s2] = s1;
                rank[s1] += 1;
            }
        }
    }
};

struct Graph {
    vector<vector<int>> edgeList;
    int V;

    Graph(int V) {
        this->V = V;
    }

    void addEdge(int x, int y, int w)
    {
        edgeList.push_back({w, x, y});
    }

    void kruskals_mst()
    {
        // sort all edge by the weight
        sort(edgeList.begin(), edgeList.end());
        
        // initialize the DSU
        DSU s = DSU(V);
        
        int ans = 0;
        for(auto e: edgeList)
        {
            int w = e[0];
            int x = e[1];
            int y = e[2];

            if(s.find(x) != s.find(y))
            {
                s.unite(x, y);
                ans += w;
            }
        }
        
        cout << "The minimum value of spanning tree is: " << ans << endl;
        
    }

};


int main() {
    Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);
    g.addEdge(2, 0, 6);
    g.addEdge(0, 3, 5);
 
    // Function call
    g.kruskals_mst();
    return 0;
}