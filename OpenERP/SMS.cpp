#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

string remove_redundant_space(string sms)
{
    auto i = sms.end() - 1;
    while(*i == ' ')
    {
        sms.pop_back();
        i--;
    }

    i = sms.begin();
    while(*i == ' ')
    {
        sms.erase(0, 1);
        i = sms.begin();
    }
    return sms;
}

void sms_count(vector<string> messages, int T)
{
    map<char, int> char_to_num = {
        {'a', 1}, {'b', 2}, {'c', 3},
        {'d', 1}, {'e', 2}, {'f', 3},
        {'g', 1}, {'h', 2}, {'i', 3},
        {'j', 1}, {'k', 2}, {'l', 3},
        {'m', 1}, {'n', 2}, {'o', 3},
        {'p', 1}, {'q', 2}, {'r', 3}, {'s', 4},
        {'t', 1}, {'u', 2}, {'v', 3},
        {'w', 1}, {'x', 2}, {'y', 3}, {'z', 4},
        {' ', 1}
    };
    
    string sms;
    int count = 0;

    for(int i = 0; i < T; i++)
    {
        sms = remove_redundant_space(messages[i]);
        // cout << sms << endl;
        for(auto i = sms.begin(); i != sms.end(); i++)
        {
            count += char_to_num[*i];
        }
        cout << "Case #" << (i + 1) << ": " << count << endl;
        count = 0;
    }
}

int main() {
    int T;
    vector<string> messages;
    string sms;

    cin >> T;
    fflush(stdin);
    for(int i = 0; i < T; i++)
    {
        getline(cin, sms);
        messages.push_back(sms);
    }

    sms_count(messages, T);

    return 0;
}