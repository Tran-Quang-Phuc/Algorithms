// Problem link: https://www.geeksforgeeks.org/maximum-size-rectangle-binary-sub-matrix-1s/
#include <bits/stdc++.h>

using namespace std;


int maxHist(int row[], int n)
{
    // Create a stack to hold indexes of hist[] array. 
    // The bars stored in stack are always in increasing order of their heights
    stack<int> result;

    int top_val;    // top of stack
    int max_area = 0;    // max area in current row
    int area = 0;    // area with current top

    int i = 0;
    while(i < n)
    { 
        if(result.empty() || row[i] >= row[result.top()])
            result.push(i++);

        else {
            top_val = row[result.top()];
            result.pop();
            
            area = i * top_val;
            if(!result.empty())
                area =  top_val * (i - result.top() - 1);

            max_area = max(area, max_area);
        }
    }
    while(!result.empty())
    {
        top_val = row[result.top()];
        result.pop();
            
        area = i * top_val;
        if(!result.empty())
            area =  top_val * (i - result.top() - 1);

        max_area = max(area, max_area);
    }

    return max_area;
}

int largestRectangle(int A[1000][1000], int m, int n)
{
    int ans = maxHist(A[0], n);

    for(int i = 1; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(A[i][j])
                A[i][j] = A[i-1][j] + 1;
        }
        ans = max(ans, maxHist(A[i], n));
    }
    return ans;
}

int main() {
    int A[1000][1000], m, n;

    scanf("%d %d", &m, &n);
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);
 
    cout << largestRectangle(A, m , n);
    return 0;
}