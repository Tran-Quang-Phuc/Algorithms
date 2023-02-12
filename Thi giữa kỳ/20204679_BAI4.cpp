/*
  Đề bài: https://www.geeksforgeeks.org/maximum-subsequence-sum-such-that-no-three-are-consecutive/.
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 1000000;
int arr[N], n;
int max_sum[N], k;

int SubSeqMax(int *arr, int n)
{
    max_sum[1] = arr[1];
    k = 1;
    if(arr[1] > 0)
    {
        max_sum[2] = arr[1] + arr[2];
        k = 2;
    }
    else
        max_sum[2] = arr[2];

    int maxSubSeq = max(max_sum[1], max_sum[2]);
    
    for(int i = 3; i <= n; i++)
    {
        if(k < 2)
        {  
            if(max_sum[i-1] > 0)
            {       
                max_sum[i] = max_sum[i-1] + arr[i];
                k = 2;
            }
            else
            {
                max_sum[i] = arr[i];
                k = 1;
            }
        }
        else
        {
            if(arr[i-1] < arr[i-2])
            {
                if(max_sum[i-2] > 0)
                    max_sum[i] = max_sum[i-2] + arr[i];
                else
                    max_sum[i] = arr[i];
                k = 1;
            }
            else
                if(max_sum[i-3] > 0) 
                {          
                    max_sum[i] = max_sum[i-3] + arr[i-1] + arr[i];
                    k = 2;
                }
                else
                {
                    max_sum[i] = arr[i];
                    k = 1;
                }
        }
        
        maxSubSeq = max(maxSubSeq, max_sum[i]);
    }

    return maxSubSeq;
}

int main() {
    
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    cout << SubSeqMax(arr, n) << endl;
    return 0;
}