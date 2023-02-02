#include <bits/stdc++.h>

using namespace std;

int CP[20][20];

void init()
{
    memset(CP, -1, sizeof CP);
}

int S(int n, int k)
{
    if(n == 1 || k == 1 || k == n)
        return 1;

    if(n == 0 || k == 0 || k > n)
        return 0;

    if(CP[n][k] == -1)
    {
        CP[n][k] = S(n - 1, k - 1) + k * S(n - 1, k);
    }

    return CP[n][k];
}

int Bell_number(int n)
{
    int ans = 0;
    for(int k = 1; k <= n; k++)
        ans += S(n, k);
    
    return ans;
}

int main() {
    init();
    cout << Bell_number(5);
    return 0;
}