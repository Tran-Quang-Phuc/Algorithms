// Link tham khảo: https://vnoi.info/wiki/algo/graph-theory/Depth-First-Search-Tree.md#b%C3%A0i-to%C3%A1n-2
#include<bits/stdc++.h>

using namespace std;

const int maxN = 1e6; 
int N, M;   // N vertices and M edges
vector<int> g[maxN];    // g[u] is list of node v that (u, v) is an edge of graph
int num[maxN], low[maxN], tail[maxN], timeDfs = 0;
int bridge = 0, joint[maxN], articulation = 0;    // joint[u] = 1 mean that u is a articulation of graph

void input()
{
    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        int X, Y;
        cin >> X >> Y;
        g[X].push_back(Y);
        g[Y].push_back(X);
    }
}

void DFS(int u, int pre)
{
    int child = 0;    // number children of node u
    num[u] = low[u] = ++timeDfs;
    for(int v: g[u])
    {
        if(v == pre)    continue;
        if(num[v])
            low[u] = min(low[u], num[v]);
        else
        {
            DFS(v, u);
            low[u] = min(low[u], low[v]);
            child++;
            if(num[v] == low[v])
                bridge++;
            if(u == pre)
            {
                if(child > 1) joint[u] = 1;
            }
            else if(low[v] >= num[u])
                joint[u] = 1;
        }
    }
    // tail[u] = timeDfs;
}

int main() {
    input();
    for (int i = 1; i <= N; i++) 
        if (!num[i]) DFS(i, i);

    for(int i = 1; i <= N; i++)
        articulation += joint[i];
    cout << articulation << " " << bridge << endl;
    return 0;
}