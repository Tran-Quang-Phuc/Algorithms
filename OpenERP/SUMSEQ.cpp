#include <iostream>

using namespace std;

#define N 1000000
#define CONST (long long)(1e9 + 7)

long long sumSeq(unsigned long long *seq, int n)
{
    unsigned long long sum = 0;
    for(int i = 0; i < n; i++)
        sum = sum + seq[i];

    return sum % CONST;
}

int main() {
    unsigned long long seq[N];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> seq[i];
    cout << sumSeq(seq, n) << endl;
    return 0;
}