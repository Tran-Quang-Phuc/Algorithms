/*
  Đề bài: Cho dãy số nguyên gồm n phần tử a1, a2, ..., an, số nguyên k, m.
  Tìm số tập con gồm k phần tử của a sao cho tổng các phần tử bằng m.

  Ví dụ:
  Input:
    6 2 10
    6 6 3 2 2 6
  Output:
    0
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 30;
int n, k, m;
int a[N];
int x[N], ans = 0, cur_sum = 0; 

void input() {
    cin >> n >> k >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
}

bool check(int i, int v)
{
    for(int j = 0; j < v; j++)
        if(x[j] >= i)
            return false;
    return true;
}

void Try(int v)
{
    if(v > k)
        return;

    for(int i = 1; i <= n; i++)
    {
        if(check(i, v))
        {
            x[v] = i;
            cur_sum += a[i];
            
            if(cur_sum == m && v == k)
                ans++;
            else if(cur_sum < m)
                Try(v+1);
            
            cur_sum -= a[i];
        }
    }
}

int main() {
    input();
    Try(1);
    cout << ans << endl;
    return 0;
}