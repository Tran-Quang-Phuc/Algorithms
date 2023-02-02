#include <bits/stdc++.h>

using namespace std;

bool checkPhone(string num)
{
    if(num.length() != 10)
        return false;
    for(int i = 0; i < 10; i++)
        if(num[i] < '0' || num[i] > '9')
            return false;
    return true;
}

int countTime(string f, string e)
{
    int start_time = 3600 * ((f[0] = '0')*10 + f[1] - '0') + 60 * ((f[3] - '0')*10 + f[4] - '0') + (f[6] - '0')*10 + f[7]-'0';
    int end_time = 3600 * ((e[0] = '0')*10 + e[1] - '0') + 60 * ((e[3] - '0')*10 + e[4] - '0') + (e[6] - '0')*10 + e[7]-'0';
    return end_time - start_time;
}

map<string, int> numberCalls, timeCall;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    string type;
    int totalCalls = 0;
    int incorrectPhone = 0;

    while(1)
    {
        cin >> type;
        if(type == "#")
            break;
        ++totalCalls;
        string fnum, tnum, date, ftime, etime;
        cin >> fnum >> tnum >> date >> ftime >> etime;
        if(!checkPhone(fnum) || !checkPhone(tnum))
            ++incorrectPhone;
        numberCalls[fnum]++;
        timeCall[fnum] += countTime(ftime, etime);
    }

    while(1)
    {
        cin >> type;
        if(type == "#")
            break;
        if(type == "?check_phone_number")
            if(incorrectPhone == 0)
                cout << 1 << endl;
            else
                cout << 0 << endl;
        else if(type == "?number_calls_from")
        {
            string phone;
            cin >> phone;
            cout << numberCalls[phone] << endl;
        }
        else if(type == "?number_total_calls")
        {
            cout << totalCalls << endl;
        }
        else if(type == "?count_time_calls_from")
        {
            string phone;
            cin >> phone;
            cout << timeCall[phone] << endl;
        }
    }
    return 0;
}

/*
call 0912345678 0132465789 2022-07-12 10:30:23 10:32:00
call 0912345678 0945324545 2022-07-13 11:30:10 11:35:11
call 0132465789 0945324545 2022-07-13 11:30:23 11:32:23
call 0945324545 0912345678 2022-07-13 07:30:23 07:48:30
#
?check_phone_number
?number_calls_from 0912345678
?number_total_calls
?count_time_calls_from 0912345678
?count_time_calls_from 0132465789
#
*/