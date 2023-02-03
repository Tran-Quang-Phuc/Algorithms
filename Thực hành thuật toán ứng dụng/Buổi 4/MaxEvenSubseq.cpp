#include <bits/stdc++.h>

using namespace std;

long long n, a[1000000];
long long ans = LLONG_MIN;

void input()
{
    scanf("%lld", &n);
    for(int i = 0; i < n; i++)
        scanf("%lld", &a[i]);
}

void solve()
{
    long long pre_mes = 0, pre_mos = 0, mes = 0, mos = 0;

    for(int i = 0; i < n; i++)
    {
        if(a[i] % 2 == 0)
        {
            if(pre_mes > 0)
                mes = pre_mes + a[i];
            else
                mes = a[i];

            if(pre_mos != 0)
                mos = pre_mos + a[i];

            pre_mes = mes;
            pre_mos = mos;         
        }
        else
        {
            if(pre_mos == 0)
                mes = 0;
            else
                mes = pre_mos + a[i];

            if(pre_mes > 0)
                mos = pre_mes + a[i];
            else
                mos = a[i];

            pre_mes = mes;
            pre_mos = mos;
        }
        ans = max(ans, mes);
        // cout << mes << " " <<  mos << " " <<  ans << endl;
    }
}

int main() {
    input();
    solve();
    printf("%lld\n", ans);
}