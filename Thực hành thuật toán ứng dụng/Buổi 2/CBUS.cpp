#include <bits/stdc++.h>

using namespace std;

int n, k;
int c[30][30];
// trace[i] = j mean the point j is the ith point has moved 
// moved[i] = 1 mean that point i has been gone through
int trace[20], moved[20];   
int num_pass = 0, cur_dis = 0, min_dis = 0;

void input() 
{
    scanf("%d %d", &n, &k);
    for(int i = 0; i <= 2*n; i++)
        for(int j = 0; j <= 2*n; j++)
            scanf("%d", &c[i][j]);
}

bool check(int v, int k)
{
    return true;
}

void Try(int k)
{
    for(int v = 1; v <= 2*n; v++)
    {
        if(1 <= v && v <= n)
        {
            if(num_pass < k && moved[v] != 1)
            {
                num_pass++;
                trace[k] = v;
                moved[v] = 1;
                cur_dis += c[trace[k-1]][v];
                if(cur_dis < min_dis)
                    Try(k+1);
            }
            

        }
    }
}

int main() {
    return 0;
}