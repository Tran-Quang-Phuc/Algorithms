/*
  Đề bài: Cho một dãy số nguyên a1, a2, ..., an và các số nguyên k, A, B.
  Tìm số các dãy gồm k phần tử ai, a[i+1], ..., a[i+k-1] sao cho tổng các phần tử đó >= A và <= B

  Ví dụ:
  Input:
    6 3 4 10
    7 5 3 1 2 10
  Output:
    2
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;
int n, k, A, B;
int a[N], sum = 0, ans = 0;

void input() {
    cin >> n >> k >> A >> B;
    for(int i = 0; i < n; i++)
        cin >> a[i];
}

void solve()
{
    for(int i = 0; i < k; i++)
        sum += a[i];

    if(A <= sum && sum <= B)
        ans++;

    for(int i = 1; i <= n-k; i++)
    {
        sum = sum - a[i-1] + a[i + k - 1];
        if(A <= sum && sum <= B)
            ans++;
    }
}

int main() {
    input();
    solve();
    cout << ans;
}