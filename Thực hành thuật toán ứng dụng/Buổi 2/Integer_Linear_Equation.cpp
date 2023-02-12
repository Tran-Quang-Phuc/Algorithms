// Problem link: https://openerp.dailyopt.ai/programming-contest/student-view-contest-problem-detail/APPLIED_ALGORITHM_2022_2023_1/COUNT_INTEGER_LINEAR_EQUATION
#include <bits/stdc++.h>

using namespace std;

int n, M;
int a[1000];
int x[1000], cur_sum = 0, ans = 0;

void Try(int k)
{
    if(k >= n) 
        return;
    
    for(int i = 1; i <= (M - cur_sum)/a[k]; i++)
    {
        x[k] = i;
        cur_sum += a[k] * x[k];

        if(k == n-1 && cur_sum == M)
            ans += 1;
        else
            Try(k+1);
        cur_sum -= a[k] * x[k];
    }
}

int main() {
    scanf("%d %d", &n, &M);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    Try(0);
    printf("%d\n", ans);
}