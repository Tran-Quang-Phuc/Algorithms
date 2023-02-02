#include <iostream>

using namespace std;

#define N 1000000

int SubSeqMax(int *arr, int n)
{
    int max_sum_i = arr[0];   // max sum of subsequence that end at ith element 
    int maxSubSeq = max_sum_i;   
    
    for(int i = 1; i < n; i++)
    {
        if(max_sum_i > 0)
            max_sum_i += arr[i];
        else
            max_sum_i = arr[i];
        
        maxSubSeq = max(maxSubSeq, max_sum_i);
    }

    return maxSubSeq;
}

int main() {
    int arr[N];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << SubSeqMax(arr, n) << endl;
    return 0;
}