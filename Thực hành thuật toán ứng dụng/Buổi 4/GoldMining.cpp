#include<bits/stdc++.h>

using namespace std;

int n, a[1000000], L1, L2;
int F[1000000];

void input()
{
    scanf("%d %d %d", &n, &L1, &L2);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void solve()
{
    for(int i = 0; i < L1; i++)
        F[i] = a[i];

    for(int i = L1; i < n; i++)
    {
        for(int j = i - L2; j <= i - L1; j++)
        {
            if(j >= 0)
                F[i] = max(F[i], F[j] + a[i]);
        }
    }
}

int main() {
    input();
    solve();

    int ans = 0;
    for(int i = 0; i < n; i++)
        ans = max(ans, F[i]);

    printf("%d\n", ans);
    return 0;
}