#include <iostream>

using namespace std;

#define CONST (long long) (1e9 + 7)

unsigned long long addMod(unsigned long long a, unsigned long long b)
{
    unsigned long long d1 = a % CONST;
    unsigned long long d2 = b % CONST;
    d1 = (d1 + d2) % CONST;
    return d1;
}

int main() {
    unsigned long long a, b;
    cin >> a >> b;
    cout << addMod(a, b) << endl;
    return 0;
}