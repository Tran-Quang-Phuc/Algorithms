/*
  Đề bài: Cho một dãy gồm n phần tử a1, a2, ..., an. Thực hiện cài đặt 2 thao tác Insert và Delete-max cho dãy số đã cho.
  Đầu vào nhận dấu '*' để kết thúc. Output in ra màn hình lần lượt kết quả của các lần delete-max.

  Ví dụ:
  Input:
    10
    10 9 10 1 8 8 7 10 10 6 
    insert 9
    delete-max
    delete-max
    delete-max
    delete-max
    insert 5
    delete-max
    delete-max
    delete-max
    insert 6
    *
  Output:
    10
    10
    10
    10
    9
    9
    8
*/
#include<bits/stdc++.h>

using namespace std;

const int N = 1e7;
int n, a[N];
vector<int> ans;

int delete_max()
{
    int i_max = 0, max;
    for(int i = 1; i < n; i++)
        if(a[i] > a[i_max])
            i_max = i;
    max = a[i_max];
    a[i_max] = INT_MIN;
    /*
    for(int i = i_max; i < n; i++)
        a[i] = a[i+1];
    n--;
    */

    return max;
}

void input()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    while(1) {
        string query;
        int value;

        cin >> query;
        if(query == "*")
            break;
        if(query == "insert")
        {
            cin >> value;
            a[n] = value;
            n++;
        }
        else
        {
            value = delete_max();
            ans.push_back(value);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    input();
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;

    return 0;
}