#include <bits/stdc++.h>

using namespace std;

int n, L1, L2;
int a[100001];
int cur_total_gold = 0, ans = 0, WH[100000];


void Try(int k)
{
    for(int i = WH[k-1] + 1; i <= n; i++)
    {
        if(WH[k-1] == 0)
        {
            if(i <= L1)
            {
                WH[k] = i;
                cur_total_gold = a[i];
                if(i + L1 > n)
                {
                    if(cur_total_gold > ans)
                        ans = cur_total_gold;
                }
                else
                    Try(k+1);
                cur_total_gold = 0;
            } 
            else
                return;
        }
        else if(L1 <= i - WH[k-1] && i - WH[k-1] <= L2)
        {
            WH[k] = i;
            cur_total_gold += a[i];
            if(i + L1 > n)
            {
                if(cur_total_gold > ans)
                    ans = cur_total_gold;
            }
            else
                Try(k+1);
            
            cur_total_gold -= a[i];
        }
    }
}

int main() {   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> L1 >> L2;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    
    Try(1);
    cout << ans << endl;
    return 0;
}
