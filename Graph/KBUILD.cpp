// Bài toán 3: https://vnoi.info/wiki/algo/graph-theory/Depth-First-Search-Tree.md#b%C3%A0i-to%C3%A1n-3
#include <bits/stdc++.h>

using namespace std;

const int maxN = 2e6 + 10;
vector<int> g[maxN];
int num[maxN], low[maxN], timeDfs = 0;
int bridge = 0;

void DFS(int u, int pre)
{
    num[u] = low[u] = ++timeDfs;
    for(int v: g[u])
    {
        if(v == pre)  continue;
        if(!num[v])
        {
            DFS(v, u);
            low[u] = min(low[u], low[v]);
            if(num[v] == low[v])
                bridge++;
        }
        else
            low[u] = min(low[u], num[v]);
    }
}

int main() {
    int N, M;
    cin >> N;
    for(int i = 1; i < N; i++)
    {
        int X, Y;
        cin >> X >> Y;
        g[X].push_back(Y);
        g[Y].push_back(X);
    }
    cin >> M;
    for(int i = 0; i < M; i++)
    {
        int X, Y;
        cin >> X >> Y;
        g[X].push_back(Y);
        g[Y].push_back(X);
    }

    DFS(1, 1);
    cout << bridge << endl;
    return 0;
}