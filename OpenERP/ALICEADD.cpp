#include <iostream>
#include <string>

using namespace std;

string AliceAdd(string a, string b)
{
    string sum;
    int renum = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;
    int x, y;
    while(i > -1 || j > -1)
    {
        if (i == -1) 
        {
            x = b[j] - '0';
            renum = (x + renum) / 10;
            sum.insert(0, to_string((x + renum)% 10));
            j--;
            continue;
        }
        if (j == -1) 
        {
            x = a[i] - '0';
            renum = (x + renum) / 10;
            sum.insert(0, to_string((x + renum)% 10));
            i--;
            continue;
        }
        x = a[i] - '0';
        y = b[j] - '0';
        sum.insert(0, to_string((x + y + renum) %10));
        renum = (x + y + renum) /10;
        i--;
        j--;
    }
    if(renum != 0)
        sum.insert(0, to_string(renum));

    return sum;
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << AliceAdd(a, b) << endl;
    return 0;
}