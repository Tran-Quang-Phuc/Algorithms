#include <bits/stdc++.h>

#define NIL -1
#define MAX 100

using namespace std;

unsigned long long fib[100];

int fibo(int n)
{
    fib[0] = 0;
    fib[1] = 1;

    for(int i = 2; i <= n; i++)
        fib[i] = (fib[i - 1] + fib[i - 2])%1000000007;

    return fib[n];
}

int main() {
    cout << fibo(200);
}