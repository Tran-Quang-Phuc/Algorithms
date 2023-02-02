#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int cutRod(int n, vector<int> price)
{
    
    if(n == 1)
        return price[0];

    int Max = price[n - 1];
    for(int i = n - 2; i > 0; i--)
    { 
        int max_i = price[i] + cutRod(n -i -1, price);
        Max = max(Max, max_i);
    }

    return Max;
}

int main() {
    int n = 8;
    vector<int> price = {3,   5,   8,   9,  10,  17,  17,  20};
    cout << cutRod(n, price);
    return 0;
}