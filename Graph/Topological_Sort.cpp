// Link tham khảo: https://vnoi.info/wiki/algo/graph-theory/topological-sort.md
#include <bits/stdc++.h>

using namespace std;

const int maxN = 100;
int N, M;
vector<int> g[maxN], TopoList;
queue<int> sourceList;
int inDegree[maxN], ans[maxN];

void input()
{
    cin >> N >> M;
    int X, Y;
    for(int i = 1; i <= M; i++)
    {
        cin >> X >> Y;
        g[X].push_back(Y);
        inDegree[Y]++;
    }
}

void Topological_sort(queue<int> sourceList)
{
    while(!sourceList.empty())
    {
        int u = sourceList.front();
        sourceList.pop();
        TopoList.push_back(u);
        for(int v: g[u])
        {
            inDegree[v]--;
            if(inDegree[v] == 0)
                sourceList.push(v);
        }
    }
}

int main() {
    input();
    for(int i = 1; i <= N; i++)
        if(inDegree[i] == 0) sourceList.push(i);

    Topological_sort(sourceList);

    if (TopoList.size() < N) {
    	cout << "Error: graph contains a cycle";
    	return 0;
    }

    for(int i = 0; i < TopoList.size(); i++)
        ans[TopoList[i]] = i+1;

    for(int i = 1; i <= N; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}