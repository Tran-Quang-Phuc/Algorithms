// Given a number n, the task is to find n’th Ugly number.
#include <bits/stdc++.h>
#include <cmath>

using namespace std;


int nth_Ugly(int n)
{
    vector<int> ugly = {1};

    int i2 = 0, i3 = 0, i5 = 0;

    int next_multiple_of_2 = 2;
    int next_multiple_of_3 = 3;
    int next_multiple_of_5 = 5;

    for(int i = 1; i < n; i++)
    {
        int next_ugly_no = min(next_multiple_of_2, min(next_multiple_of_3, next_multiple_of_5));
        ugly.push_back(next_ugly_no);

        if(ugly[i] == next_multiple_of_2)
        {
            i2++;
            next_multiple_of_2 = ugly[i2] * 2;
        }

        if(ugly[i] == next_multiple_of_3)
        {
            i3++;
            next_multiple_of_3 = ugly[i3] * 3;
        }

        if(ugly[i] == next_multiple_of_5)
        {
            i5++;
            next_multiple_of_5 = ugly[i5] * 5;
        }
    }

    return ugly.back();
}


int main() {
    int n;
    cin >> n;
    cout << "nth Ugly number is: " << nth_Ugly(n);
}