// Problem link: https://openerp.dailyopt.ai/programming-contest/student-view-contest-problem-detail/APPLIED_ALGORITHM_2022_2023_1/BCA
#include <bits/stdc++.h>

using namespace std;

int m, n;
vector<int> courses[50];    // courses[i]: the list of teachers that can teach the course i
int conflict[50][50];    // conflict[i][j] = 1 mean that course i and j is scheduled in the same slot of timetable
int load[20], c[20];    // c[i] = j mean that course i is taught by teacher j
int ans = 50;

void input()
{
    scanf("%d %d", &m, &n);   
    int k, c;
    for(int i = 1; i <= m; i++)
    {
        scanf("%d", &k);
        for(int j = 1; j <= k; j++)
        {
            scanf("%d", &c);
            courses[c].push_back(i);
        }
    }
    scanf("%d", &k);
    int i , j;
    for(int v = 0; v < k; v++)
    {
        scanf("%d %d", &i, &j);
        conflict[i][j] = 1;
        conflict[j][i] = 1;
    }
}

bool notConflict(int t, int k)
{
    for(int i = 1; i < k; i++)
        if(c[i] == t && conflict[k][i] == 1)
            return false;

    return true;
}

int getMaxLoad(int load[], int m)
{
    int maxLoad = 0;
    for(int i = 1; i <= m; i++)
        maxLoad = max(maxLoad, load[i]);

    return maxLoad;
}

void Try(int k)
{
    for(int t: courses[k])
    {
        if(notConflict(t, k))
        {
            c[k] = t;
            load[t] += 1;          
            if(load[t] < ans)
            {
                if(k == n)
                    ans = min(ans, getMaxLoad(load, m));
                else
                    Try(k+1);
            }
            load[t] -= 1;
        }
    }
}

int main() {
    input();
    Try(1);
    if(ans != 50)
        printf("%d\n", ans);
    else
        printf("%d", -1);
    return 0;
}