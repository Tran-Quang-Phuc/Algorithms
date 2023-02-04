#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 2, MOD = 1e9 + 7;
int n, k1, k2, f[N][2], res;

void process()
{
    f[0][0] = f[0][1] = 1;

    for(int i = 1; i <= n; i++)
    {
        for(int j = max(i - k2, 0); j <= i - k1; j++)
        {
            f[i][1] += f[j][0];
            f[i][1] %= MOD; 
        }
        f[i][0] = f[i-1][1];
    }

    res = f[n][0] + f[n][1];
    printf("%d\n", res);
}

int main() {
    scanf("%d %d %d", &n, &k1, &k2);
    process();
    return 0;
}