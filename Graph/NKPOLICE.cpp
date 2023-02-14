// Bài toán 2: https://vnoi.info/wiki/algo/graph-theory/Depth-First-Search-Tree.md
#include <bits/stdc++.h>

using namespace std;

const int maxN = 100010;
int N, M;
vector<int> g[maxN];    // g[u] là danh sách các thành phố nối với thành phố u bởi 1 con đường
int p[maxN][20];    // SparseTable với p[i][j] là tổ tiên thứ 2^j của i
int depth[maxN];    // lưu chiều sâu của mỗi đỉnh trong cây 
int num[maxN], low[maxN], tail[maxN], timeDfs;
bool joint[maxN];    // joint[u] = true thì u là một đỉnh khớp của đồ thị
vector<string> output;

void DFS(int u, int pre)
{
    int child = 0;
    num[u] = low[u] = ++timeDfs;
    for(int v: g[u])
    {
        if(v == pre)  continue;
        if(!num[v])
        {
            p[v][0] = u;
            depth[v] = depth[u] + 1;
            DFS(v, u);
            low[u] = min(low[u], low[v]);
            child++;
            if(u == pre)
            {
                if(child > 1)  joint[u] = true;
            }
            else if(low[v] >= num[u])
                joint[u] = true;
        }
        else
            low[u] = min(low[u], num[v]);
    }
    tail[u] = timeDfs;
}

void calP()    // tính mảng p[][]
{
    p[1][0] = 1;
    for(int j = 1; j < 19; j++)
        for(int i = 1; i <= N; i++)
            p[i][j] = p[p[i][j - 1]][j - 1];
}

int findParent(int u, int par)
{
    // Tìm tổ tiên của đỉnh u là con trực tiếp của đỉnh par
    for(int i = 19; i >= 0; i--)
        if(depth[p[u][i]] > depth[par])
            u = p[u][i];
    return u;
}

bool checkInSubtree(int u, int root)
{
    return (num[root] <= num[u] && num[u] <= tail[root]);
}

bool solve1(int A, int B, int G1, int G2)
{
    if(num[G1] > num[G2])
        swap(G1, G2);

    if(num[G2] != low[G2])
        return true;
    else if((checkInSubtree(A, G2) && !checkInSubtree(B, G2)) || (checkInSubtree(B, G2) && !checkInSubtree(A, G2)))
        return false;

    return true;
}

bool solve2(int A, int B, int C)
{
    if(!joint[C])
        return true;
    else
    {
        int pa = 0, pb = 0;
        if(checkInSubtree(A, C))  pa = findParent(A, C);
        if(checkInSubtree(B, C))  pb = findParent(B, C);

        if(!pa && !pb)
            return true;
        if(pa == pb)
            return true;
        if(!pa && low[pb] < num[C])
            return true;
        if(!pb && low[pa] < num[C])
            return true;
        if(pa && pb && low[pa] < num[C] && low[pb] < num[C])
            return true;

        return false;
    }
}

int main() {
    cin >> N >> M;
    for(int i = 1; i <= M; i++)
    {
        int X, Y;
        cin >> X >> Y;
        g[X].push_back(Y);
        g[Y].push_back(X);
    }

    depth[1] = 1;
    DFS(1, 1);
    calP();

    int Q;
    cin >> Q;
    int T, A, B, C, G1, G2;
    for(int i = 0; i < Q; i++)
    {
        cin >> T;
        if(T == 1)
        {
            cin >> A >> B >> G1 >> G2;
            if(solve1(A, B, G1, G2))
                output.push_back("yes");
            else
                output.push_back("no");
        }
        else
        {
            cin >> A >> B >> C;
            if(solve2(A, B, C))
                output.push_back("yes");
            else
                output.push_back("no");
        }
    }

    for(string op: output)
        cout << op << endl;
}