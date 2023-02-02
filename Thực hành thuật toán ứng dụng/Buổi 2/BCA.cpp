#include <bits/stdc++.h>

using namespace std;

int m, n;
vector<int> course[31];     // course[i]: list of teacher can teach course i
bool conflict[31][31];
int x[31], load[11];
int res = 30;

void input()
{
    cin >> m >> n;
    int k, c;
    for(int i = 1; i <= m; i++)
    {
        cin >> k;
        for(int j = 0; j < k; j++)
        {
            cin >> c;
            course[c].push_back(i);
        }
    }   
    cin >> k;
    memset(conflict, false, sizeof(conflict));
    int c1, c2; 
    for(int i = 0; i < k; i++)
    {
        cin >> c1 >> c2;
        conflict[c1][c2] = true;
        conflict[c2][c1] = true;
    }
}

bool notConflict(int k, int t)
{
    for(int i = 1; i < k; i++)
    {
        if(x[i] == t && conflict[i][k] == true)
            return false;
    }
    return true;
}

int maxVal()
{
    int maxLoad = load[1];
    for(int t = 2; t <= m; t++)
        maxLoad = max(maxLoad, load[t]);

    if(maxLoad < res)
        return maxLoad;

    return res;
}

void Try(int k)
{
    // if(k > n)
    //     return;
    
    for(int i = 0; i < course[k].size(); i++)
    {
        int t = course[k][i];
        if(notConflict(k, t))
        {
            x[k] = t;
            load[t] += 1;
            
            if(load[t] < res)
            {
                if(k == n)
                    res = maxVal();
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
    cout << res << endl;
    return 0;
}