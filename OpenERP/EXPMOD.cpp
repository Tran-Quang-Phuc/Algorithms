#include<iostream>
 
using namespace std;
 
#define CONST (unsigned long long) (1e9 + 7)

unsigned long long expMod(unsigned long long a, unsigned long long b)
{
    if(a == 1)
        return 1;
    
    if(b == 1)
        return a;

    unsigned long long d = expMod(a, b/2);

    if(b%2 == 0)
        return (d * d) % CONST;
    else
    {
        d = (d * d) % CONST;
        return (d * a) % CONST;
    }    
         
}
 
int main() {
    unsigned long long a, b;
    cin >> a >> b;
    a = a % CONST;
    cout << expMod(a, b) << endl; 

    return 0;
}