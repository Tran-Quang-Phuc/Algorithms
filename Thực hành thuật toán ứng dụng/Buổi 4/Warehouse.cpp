#include <bits/stdc++.h>

using namespace std;

const int N = 2000;
int n, T, D;
int a[N], t[N];
int f[N][N];
int res = 0;

void input()
{
    scanf("%d %d %d", &n, &T, &D);

    for(int i = 1 ; i <= n; i++)
        scanf("%d", &a[i]);
    
    for(int i = 1; i <= n; i++)
        scanf("%d", &t[i]);
}

void solve()
{  
    for(int i = 1; i <= n; i++)
    {
        for(int k = t[i]; k <= T; k++)
        {
            for(int j = max(i-D, 0); j <= i-1; j++)
            {
                f[i][k] = max(f[i][k], f[j][k - t[i]] + a[i]);
            }
            res = max(res, f[i][k]);
        }
    }
    printf("%d\n", res);          
}


int main() {
    input();
    solve();
    
    return 0;
}