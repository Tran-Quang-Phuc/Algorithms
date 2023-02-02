// Problem link: https://www.geeksforgeeks.org/activity-selection-problem-greedy-algo-1/
#include <bits/stdc++.h>

using namespace std;

void  SelectActivities(vector<int> s, vector<int> f)
{
    // vector to store  results
    vector<pair<int, int> > ans;

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > p;

    for(int i = 0; i < s.size(); i++)
    {
        p.push(make_pair(f[i], s[i]));
    }

    auto it = p.top();
    int start = it.second;
    int finish = it.first;
    p.pop();
    ans.push_back(make_pair(start, finish));
    while(!p.empty())
    {
        auto act = p.top();
        if(act.second >= finish)
        {
            start = act.second;
            finish = act.first;
            ans.push_back(make_pair(start, finish));
        }
        p.pop();
    }

    cout << "Following Activities should be selected. "
         << endl
         << endl;
 
    for (auto itr = ans.begin(); itr != ans.end(); itr++) 
    {
        cout << "Activity started at " << (*itr).first
             << " and ends at " << (*itr).second << endl;
    }
}

int main() {
    vector<int> s = { 1, 3, 0, 5, 8, 5 };
    vector<int> f = { 2, 4, 6, 7, 9, 9 };
 
    // Function call
    SelectActivities(s, f);

    return 0;
}