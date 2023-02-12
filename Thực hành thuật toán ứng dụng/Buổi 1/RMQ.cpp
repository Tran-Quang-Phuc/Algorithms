// Problem link: https://vnoi.info/wiki/translate/topcoder/Range-Minimum-Query-and-Lowest-Common-Ancestor.md
#include <bits/stdc++.h>

using namespace std;

#define N 1000000

int A[N], n, ans;
int M[N][30];

void input()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &A[i]);
}

void process()
{
    for(int i = 0; i < n; i++)
        M[i][0] = i;
    
    for(int j = 1; 1 << j <= n; j++)
    {
        for(int i = 0; i + (1 << j) - 1 < n; i++)
        {
            if(A[M[i][j-1]] <= A[M[i + (1 << (j-1))][j-1]])
                M[i][j] = M[i][j-1];
            else
                M[i][j] = M[i + (1 << (j-1))][j-1];
        }
    }
}

int RMQ(int i, int j)
{
    int k = (int)log2(j-i+1);
    return min(A[M[i][k]], A[M[j - (1 << k) + 1][k]]);
}

int main() {
    input();
    process();
    int m, i, j;
    scanf("%d", &m);
    ans = 0;
    for(int k = 0; k < m; k++)
    {
        scanf("%d%d", &i, &j);
        // cout << RMQ(i, j) << endl;
        ans = ans + RMQ(i, j);
    }
    printf("%d", ans);
    return 0;
}