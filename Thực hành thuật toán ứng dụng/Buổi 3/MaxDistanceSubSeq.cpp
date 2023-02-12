#include <bits/stdc++.h>

using namespace std;

int T, N[20], C[20];
int a[20][100000];
int d, ans[20];

void input()
{
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        cin >> N[i] >> C[i];
        for(int j = 0; j < N[i]; j++)
            cin >> a[i][j];
    }
}

void Solution()
{
    
}

int main() {
    input();
    Solution();
    for(int i = 0; i < T; i++)
        cout << ans[i] << endl;
    return 0;
}