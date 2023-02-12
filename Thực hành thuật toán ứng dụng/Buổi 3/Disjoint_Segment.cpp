// Problem link: https://openerp.dailyopt.ai/programming-contest/student-view-contest-problem-detail/APPLIED_ALGORITHM_2022_2023_1/DISJOINT_SEGMENT
#include <bits/stdc++.h>

using namespace std;

#define N 100000
typedef pair<int, int> seg;
int n;
int last;
int ans = 1;
seg segments_set[N];

bool compare(seg A, seg B)
{
    if(A.second < B.second)
        return true;
    return false;
}

void input()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> segments_set[i].first >> segments_set[i].second;
    }
    sort(segments_set, segments_set + n, compare);
}

void solution()
{
    last = segments_set[0].second;
    for(int i = 1; i < n; i++)
    {
        if(segments_set[i].first > last)
        {
            last = segments_set[i].second;
            ans++;
        }       
    }
}
int main() {
    input();
    solution();
    cout << ans << endl;
    return 0;
}