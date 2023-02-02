#include <bits/stdc++.h>

using namespace std;

#define N 20

int n, k;      // number of passengers and max places on the bus
int c[N][N], c_min;     // c[i][j]: cost for moving from i to j
int isVisited[N];     
int x[2*N], x_best[2*N];      // to log the result moves
int cur_cost, estimated_cost;     // current cost and estimated cost 
int passenger_num;        // the number of passenger in the bus
int res;      // the answer of problem

void input()
{
    cin >> n >> k;
    c_min = 1000000;
    for(int i = 0; i <= 2*n; i++)
        for(int j = 0; j <= 2*n; j++)
        {
            cin >> c[i][j];
            c_min = min(c_min, c[i][j]);
        }
}

int check(int v)
{
    if(isVisited[v] == 1) return 0;
    if(v > n){
        if(!isVisited[v-n]) return 0;
    }else{
        if(passenger_num + 1 > k) return 0;
    }
    return 1;
}

void Solution()
{
    if(cur_cost + c[x[2*n]][0] < res)
    {
        res = cur_cost + c[x[2*n]][0];
    }
}

void Try(int m)
{
    for(int v = 1; v <= 2*n; v++)
    {
        if(check(v))     // if point has not visited yet
        {
            x[m] = v;
            cur_cost += c[x[m-1]][x[m]];
            if(v <= n) passenger_num += 1; else passenger_num -= 1;
            isVisited[v] = 1;
            if(m == 2*n)
                Solution();
            else
            {
                if(cur_cost + (2*n+1-m)*c_min < res)
                    Try(m + 1);
            }
            if(v <= n) passenger_num -= 1; else passenger_num += 1;
            isVisited[v] = 0;
            cur_cost -= c[x[m-1]][x[m]]; 
        }
    }
}

void solve()
{
    passenger_num = 0;
    cur_cost = 0;
    res = 1000000;
    for(int i = 1; i <= 2*n; i++)
        isVisited[i] = 0;
    x[0] = 0; 
    Try(1);
    cout << res << endl;  
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    solve();
    // cout << res << endl;
    return 0;
}
