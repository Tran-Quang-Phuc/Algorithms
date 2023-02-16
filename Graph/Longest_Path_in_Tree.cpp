#include <bits/stdc++.h>

using namespace std;

const int maxN = 100000;

struct Edge{
    int node;
    int w;
    Edge(int _node, int _w) {
        node = _node;
        w = _w;
    }
};

int N;
vector<Edge> g[maxN];    // g[u] is list of Edge start with u
int d[maxN];    // d[u] is the distance from the source to u in BFS
int p[maxN];    // p[u] is the parent of u by BFS

void input()
{
    cin >> N;
    for(int i = 1; i <= N-1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[v].push_back(Edge(u, w));
        g[u].push_back(Edge(v, w));
    }
}

void init()
{
    for(int u = 1; u <= N; u++)
        d[u] = p[u] = -1;
}

void BFS(int u)
{
    queue<int> Q;
    d[u] = 0;
    Q.push(u);
    while(!Q.empty())
    {
        int v = Q.front();
        Q.pop();
        for(Edge e: g[v])
        {
            int x = e.node;
            if(x == p[v]) continue;
            int w = e.w;
            d[x] = d[v] + w;
            p[x] = v;
            Q.push(x);       
        }
    }
}

int findMax() {
    int u = 1;
    for(int v = 2; v <= N; v++)
        if(d[u] < d[v])
            u = v;

    return u;
}

void solve()
{
    init();
    BFS(1);
    int u = findMax();
    init();
    BFS(u);
    u = findMax();
    cout << d[u] << endl;
}

int main() {
    input();
    solve();

    return 0;
}